/**
 * Simple test of the task scheduler library using status request objects
 * Based on examples of https://github.com/arkhipenko/TaskScheduler
 */

//#define _TASK_SLEEP_ON_IDLE_RUN // Seems to not work on ESP32 according to the compile warning
#define _TASK_STATUS_REQUEST
#include <TaskScheduler.h>

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
}

void loop(){ 
  ts.execute();
}
