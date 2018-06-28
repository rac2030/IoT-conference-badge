//Header that declares all shared objects between .cpp files
#include "taskheader.hpp"
#include <Arduino.h> //for Serial and delay
#include <esp_wifi.h>
#include <esp_bt.h>
#include "version.h"
#include "networkSettings.h"

Scheduler runner, runnerPriority;

// Tasks
// TODO: Should work if they are in their own file as it works in the simple example... for now they stay here as this works
Task tInitialize(&initBadge, &runnerPriority);
Task tQRView(&handleQRView, &runner);
Task tNameView(&handleNameView, &runner);
Task tSensorView(&handleSensorView, &runner);
Task tUpdateDisplay(&handleUpdateDisplay, &runner);
Task tSplashView(&handleSplashView, &runnerPriority);
Task tFetchRegistration(&handleFetchRegistration, &runner);
Task tTriggerAquireSensorView(&handleAquireSensorData, &runnerPriority);

// Run every 2 minutes once
Task tAquireSensorData(120000L, TASK_FOREVER, &handleAquireSensorData, &runner, true);
// Run every 30 minutes
Task tPushSensorData(1800000L, TASK_FOREVER, &handlePushSensorData, &runner, true);

// Refresh sensor view
Task tSensorViewRefresh(5000L, TASK_FOREVER, &handleSensorView, &runner, false);

// Button tasks
Task tBTN1(&handleBTN1, &runnerPriority);
Task tBTN2(&handleBTN2, &runnerPriority);
Task tBTN3(&handleBTN3, &runnerPriority);
Task tBTN4(&handleBTN4, &runnerPriority);

// PINS
// Buttons
const byte BTN1 = D19;
const uint64_t BTN1_mask = 1ULL << BTN1;
const byte BTN2 = D8;
const uint64_t BTN2_mask = 1ULL << BTN2;
const byte BTN3 = D21;
const uint64_t BTN3_mask = 1ULL << BTN3;
const byte BTN4 = D20;
const uint64_t BTN4_mask = 1ULL << BTN4;

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
void prepareButtonStatus();
void IRAM_ATTR handleInterruptBTN1();
void IRAM_ATTR handleInterruptBTN2();
void IRAM_ATTR handleInterruptBTN3();
void IRAM_ATTR handleInterruptBTN4();
void handleInterruptButtonDebounce(byte buttonPin, String text, StatusRequest *btn);

/*
Arduino serial-remote control.

commands
=========
separator ;

AT

*/
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

// Serial commands
void setFirstName(String newFirstName) {
    preferences.begin(PREF_TAG, false); // Read/write
        preferences.putString(PREF_FIRSTNAME, newFirstName);
        preferences.end();
        Serial.println("=> new first name saved in NVM");
}
void setLastName(String newLastName) {
    preferences.begin(PREF_TAG, false); // Read/write
        preferences.putString(PREF_LASTNAME, newLastName);
        preferences.end();
        Serial.println("=> new last name saved in NVM");
}

void command_listener()
{
  char buf[50];
  if (inputString=="AT\r\n") Serial.println("OK");
  if (inputString.substring(0,6)=="ATSNF+"){
    // get name
    setFirstName(inputString.substring(6));
    Serial.println("OK");
    }
    if (inputString.substring(0,6)=="ATSNL+"){
    // get name
    setLastName(inputString.substring(6));
    Serial.println("OK");
    }
  if (inputString=="AT+CCLK\r\n"){
    unsigned long tiempo = millis();
    sprintf(buf, "%lu", tiempo); 
    Serial.println( buf );
    Serial.println("OK");
    }
  if (inputString.substring(0,6)=="ATDOH+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),OUTPUT);
    digitalWrite(strPin.toInt(),HIGH);
    Serial.println("OK");
    }
  if (inputString.substring(0,6)=="ATDOL+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),OUTPUT);
    digitalWrite(strPin.toInt(),LOW);
    Serial.println("OK");
    }
  
  if (inputString.substring(0,6)=="ATDIN+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),INPUT);
    Serial.println(digitalRead(strPin.toInt()));
    Serial.println("OK");
    }
      
  if (inputString.substring(0,6)=="ATDIP+"){
    String strPin =  inputString.substring(6);
    pinMode(strPin.toInt(),INPUT_PULLUP);
    Serial.println(digitalRead(strPin.toInt()));
    Serial.println("OK");
    }
      
  if (inputString.substring(0,6)=="ATAI+"){
    String strPin =  inputString.substring(5);
    Serial.println(analogRead(strPin.toInt()));
    Serial.println("OK");
    } 
      
  if (inputString=="AT+RESET\r\n"){
    ESP.restart();
    Serial.println("OK");
    }   
 
}

void setup()
{
    inputString.reserve(200);

    // Disable networking parts to save energy until we really need it
    esp_wifi_stop();
    esp_bt_controller_disable();

    Serial.begin(115200);

    // Initiate the display object
    display.init(115200); // enable diagnostic output on Serial

    Serial.println("MakeZurich Badge Firmware " + String(VERSION));

    runner.setHighPriorityScheduler(&runnerPriority);

    prepareUpdateDisplayStatus();
    prepareButtonStatus();
    displaySplash.setWaiting();
    tSplashView.waitFor(&displaySplash);
    displayNameView.setWaiting();
    tNameView.waitFor(&displayNameView);
    displaySensorView.setWaiting();
    tSensorView.waitFor(&displaySensorView);
    displayQRView.setWaiting();
    tQRView.waitFor(&displayQRView);
    fetchRegistration.setWaiting();
    tFetchRegistration.waitFor(&fetchRegistration);
    triggerAquireSensorData.setWaiting();
    tTriggerAquireSensorView.waitFor(&triggerAquireSensorData);

    tInitialize.enable();
    runner.startNow(); // set point-in-time for scheduling start
}

void loop()
{
    // print the string when a newline arrives:
  if (stringComplete) {
    command_listener();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
    while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }

    runner.execute();
}

void prepareUpdateDisplayStatus()
{
    Serial.println("Set display to wait for update signal");
    updateDisplay.setWaiting();             // set the status request object for waiting
    tUpdateDisplay.waitFor(&updateDisplay); //request tasks tUpdateDisplay to wait on the object updateDisplay signal
}

/**
 *  This is the handler actually doing the work, locking the mutex (one interrupt at a time) and
 * debouncing it so it counts only if the time beetween both interrupts is greater than 100ms.
 * */
void handleInterruptButtonDebounce(byte buttonPin, String text, StatusRequest *btn)
{
    portENTER_CRITICAL_ISR(&mux);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 100ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > 100)
    {
        // distinguish between pressed and released state
        if (digitalRead(buttonPin) == LOW)
        {
            Serial.print("Interrupt: [pressed] ");
            btn->signalComplete();
        }
        else
        {
            Serial.print("Interrupt: [released] ");
        }
        Serial.println(text);
        last_interrupt_time = interrupt_time;
    }
    portEXIT_CRITICAL_ISR(&mux);
}

void prepareButtonStatus()
{
    btn1Pressed.setWaiting();
    tBTN1.waitFor(&btn1Pressed);
    btn2Pressed.setWaiting();
    tBTN2.waitFor(&btn2Pressed);
    btn3Pressed.setWaiting();
    tBTN3.waitFor(&btn3Pressed);
    btn4Pressed.setWaiting();
    tBTN4.waitFor(&btn4Pressed);
    // Setup interrupts for Buttons
    pinMode(BTN1, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BTN1), handleInterruptBTN1, FALLING);
    pinMode(BTN2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BTN2), handleInterruptBTN2, FALLING);
    pinMode(BTN3, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BTN3), handleInterruptBTN3, FALLING);
    pinMode(BTN4, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BTN4), handleInterruptBTN4, FALLING);
}

// interrupts
void IRAM_ATTR handleInterruptBTN1()
{
    setSensorViewRefresh(false);
    handleInterruptButtonDebounce(BTN1, "Button 1", &btn1Pressed);
}

void IRAM_ATTR handleInterruptBTN2()
{
    setSensorViewRefresh(false);
    handleInterruptButtonDebounce(BTN2, "Button 2", &btn2Pressed);
}
void IRAM_ATTR handleInterruptBTN3()
{
    setSensorViewRefresh(false);
    handleInterruptButtonDebounce(BTN3, "Button 3", &btn3Pressed);
}

void IRAM_ATTR handleInterruptBTN4()
{
    handleInterruptButtonDebounce(BTN4, "Button 4", &btn4Pressed);
}
