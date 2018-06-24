/**
 * Example to generate QR Code from chipID
 * (modified the code from https://github.com/anunpanya/ESP8266_QRcode/tree/master/src to fit our setup)
 * and display it with some text next to it
 **/

#define _TASK_SLEEP_ON_IDLE_RUN
#define _TASK_STATUS_REQUEST
#include <TaskScheduler.h>

// GxEPD lib and display drivers
#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.cpp>  // 2.13" b/w/r

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>

// Those are from the board definition and don't need to be defined as they are standard for NINA
//static const uint8_t SS    = 5;  //GPIO28
//static const uint8_t MOSI  = 23; //GPIO1
//static const uint8_t MISO  = 19; // not used for waveshare display
//static const uint8_t SCK   = 18; // GPIO29

// Specific pins used on the MakeZurich badge, adjust if you are using the Display and the NINA standalone
static const uint8_t DC = 22;      //GPIO20
static const uint8_t RST = 21;     //GPIO8
static const uint8_t BUSYN = 4;    //GPIO24

GxIO_Class io(SPI, SS, DC, RST); 
GxEPD_Class display(io, RST, BUSYN); 

#include "qrcode.h"
QRcode qrcode (&display);

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

// Status request objects
StatusRequest btn1Pressed;
StatusRequest btn2Pressed;
StatusRequest btn3Pressed;
StatusRequest btn4Pressed;
StatusRequest updateDisplay;

// Task scheduler
Scheduler ts;

// Callback method prototypes
void handleBTN1();
void handleBTN2();
void handleBTN3();
void handleBTN4();
void handleUpdateDisplay();

// Task
Task tBTN1(&handleBTN1, &ts);
Task tBTN2(&handleBTN2, &ts);
Task tBTN3(&handleBTN3, &ts);
Task tBTN4(&handleBTN4, &ts);
Task tUpdateDisplay(&handleUpdateDisplay, &ts);

// Task implementations
void handleBTN1() {
  handleInterrupButtonDebounce(BTN1, "Button 1 was pushed"); // Handle BTN1
  display.setCursor(0,0);
  display.fillScreen(GxEPD_WHITE); // Make the screen empty
  display.setRotation(3); // Set the rotation for the badge display orientation

  // Display some text next to it
  display.setFont(&FreeMonoBold12pt7b);
  // Print MakeZurich big using red for upper case letters
  display.println(""); // Add an empty line as otherwise text is cut at the top
  display.setCursor(10, display.getCursorY()); // Use offset to be next to QR code
  display.setTextColor(GxEPD_RED);
  display.print("Button 1");
  display.setTextColor(GxEPD_BLACK);
  display.print(" Pressed");
  updateDisplay.signalComplete();

  btn1Pressed.setWaiting();
  tBTN1.waitFor(&btn1Pressed);
}

void handleBTN2() {
  handleInterrupButtonDebounce(BTN2, "Button 2 was pushed"); // Handle BTN2
  btn2Pressed.setWaiting();
  tBTN2.waitFor(&btn2Pressed);
}

void handleBTN3() {
  handleInterrupButtonDebounce(BTN3, "Button 3 was pushed"); // Handle BTN3
  // create qrcode
  qrcode.generate(UniqueID());
  showQRInitScreen();
  updateDisplay.signalComplete();
  btn3Pressed.setWaiting();
  tBTN3.waitFor(&btn3Pressed);
}

void handleBTN4() {
  handleInterrupButtonDebounce(BTN4, "Button 4 was pushed"); // Handle BTN4
  btn4Pressed.setWaiting();
  tBTN4.waitFor(&btn4Pressed);
}

void handleUpdateDisplay() {
  Serial.println("handleUpdateDisplay() called");
  display.update(); // Update the display to show the current buffer
  delay(5000); // Delay the return so the message stays a bit, only for this demo purpose
  PrepareUpdateDisplayStatus();
}
void PrepareUpdateDisplayStatus() {
  updateDisplay.setWaiting();         // set the statusrequest object for waiting 
  tUpdateDisplay.waitFor(&updateDisplay); //request tasks tUpdateDisplay to wait on the object updateDisplay signal
}

// interrupts
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR handleInterruptBTN1() { 
  btn1Pressed.signalComplete();
}

void IRAM_ATTR handleInterruptBTN2() {
  btn2Pressed.signalComplete();
}
void IRAM_ATTR handleInterruptBTN3() {
  btn3Pressed.signalComplete();
}

void IRAM_ATTR handleInterruptBTN4() {
  btn4Pressed.signalComplete();
}

/**
 *  This is the handler actually doing the work, locking the mutex (one interrupt at a time) and
 * debouncing it so it counts only if the time beetween both interrupts is greater than 100ms.
 * */
void handleInterrupButtonDebounce(byte buttonPin, String text) {
  portENTER_CRITICAL_ISR(&mux);
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 100ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 100) {
    // distinguish between pressed and released state
    if(digitalRead(buttonPin) == LOW) {
      Serial.print("[pressed] ");
    } else {
      Serial.print("[released] ");
    }
    Serial.println(text);
    last_interrupt_time = interrupt_time;
  }
  portEXIT_CRITICAL_ISR(&mux);
}

void setup()
{
  Serial.begin(115200);
  // Initiate the display object
  display.init(115200); // enable diagnostic output on Serial
  
  delay(1000); // let serial console settle

  Serial.println("\n\nIntegration test for MakeZurich 2018 badge");

  // Setup tasks
  btn1Pressed.setWaiting();
  tBTN1.waitFor(&btn1Pressed);
  btn2Pressed.setWaiting();
  tBTN2.waitFor(&btn2Pressed);
  btn3Pressed.setWaiting();
  tBTN3.waitFor(&btn3Pressed);
  btn4Pressed.setWaiting();
  tBTN4.waitFor(&btn4Pressed);
  updateDisplay.setWaiting();
  tUpdateDisplay.waitFor(&updateDisplay);
  Serial.println("Initialized Tasks");

  // Setup interrupts for Buttons
  pinMode(BTN1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN1), handleInterruptBTN1, FALLING);
  pinMode(BTN2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN2), handleInterruptBTN2, FALLING);
  pinMode(BTN3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN3), handleInterruptBTN3, FALLING);
  pinMode(BTN4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN4), handleInterruptBTN4, FALLING);
  Serial.println("Initialized interrupts");

  // enable debug qrcode
  qrcode.debug();
}

void loop()
{
  ts.execute();
}

void showQRInitScreen() {
  display.setCursor(0,0);
  display.fillScreen(GxEPD_WHITE); // Make the screen empty
  display.setRotation(3); // Set the rotation for the badge display orientation

  qrcode.writeToDisplayBuffer(5 /** X **/, 5 /** Y **/); // Display chipID as QR Code into current buffer

  // Display some text next to it
  display.setFont(&FreeMonoBold12pt7b);
  // Print MakeZurich big using red for upper case letters
  display.println(""); // Add an empty line as otherwise text is cut at the top
  display.setCursor(110, display.getCursorY()); // Use offset to be next to QR code
  display.setTextColor(GxEPD_RED);
  display.print("M");
  display.setTextColor(GxEPD_BLACK);
  display.print("ake");

  // Go to next line
  display.println("");
  // on each new line we have to set the X offset again
  display.setCursor(110, display.getCursorY()); // Use offset to be next to QR code

  display.setTextColor(GxEPD_RED);
  display.print("Z");
  display.setTextColor(GxEPD_BLACK);
  display.print("urich");
  
  // Display init text
  // Make 1 line as space between
  display.print("\n\n");
  // on each new line we have to set the X offset again
  display.setCursor(105, display.getCursorY()); // Use offset to be next to QR code
  display.setFont();
  display.setTextColor(GxEPD_BLACK);
  display.print(UniqueID());
}

String UniqueID()
{
  uint64_t id = ESP.getEfuseMac();
  char id_h[9];
  char id_l[9];

  sprintf(id_h, "%08X", (uint32_t)(id>>32));
  sprintf(id_l, "%08X", (uint32_t)(id));

  return String(id_h) + String(id_l);
}
