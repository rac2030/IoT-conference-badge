/**
 * This is an example of using interrupts and the 4 buttons available on the MakeZurich badge
 * @author Michel Racic
 **/

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

// interrupts
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR handleInterruptBTN1() { 
  handleInterrupButtonDebounce(BTN1, "Button 1 was pushed"); // Handle BTN1
}

void IRAM_ATTR handleInterruptBTN2() {
  handleInterrupButtonDebounce(BTN2, "Button 2 was pushed"); // Handle BTN2
}
void IRAM_ATTR handleInterruptBTN3() {
  handleInterrupButtonDebounce(BTN3, "Button 3 was pushed"); // Handle BTN3
}

void IRAM_ATTR handleInterruptBTN4() {
  handleInterrupButtonDebounce(BTN4, "Button 4 was pushed"); // Handle BTN4
}

/**
 *  This is the handler actually doing the work, locking the mutex (one interrupt at a time) and
 * debouncing it so it counts only if the time beetween both interrupts is greater than 100ms.
 * */
void handleInterrupButtonDebounce(byte buttonPin, String text) {
  portENTER_CRITICAL_ISR(&mux);
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
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
  // Configure wakeup from deep sleep on all 4 buttons
}

void setup()
{
    Serial.begin(115200);
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

void loop(){ /** Not used but needs to be declared for arduino **/}
