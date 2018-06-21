/**
 * This is an example of using interrupts and the 4 buttons available on the MakeZurich badge
 * @author Michel Racic
 **/

#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.cpp>  // 2.13" b/w/r
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>
#include <Fonts/FreeSansBold24pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

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

#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#define DATA_PIN 27                // GPIO18
#define NUM_LEDS 2
CRGB leds[NUM_LEDS];

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
  if (interrupt_time - last_interrupt_time > 200) {
    // distinguish between pressed and released state
    if(digitalRead(buttonPin) == LOW) {
      Serial.print("\n\n\n                                          [pressed] ");
    } else {
      Serial.print("[released] ");
    }
    Serial.print(text);
    Serial.print("\n\n\n");
    last_interrupt_time = interrupt_time;
  }
  portEXIT_CRITICAL_ISR(&mux);
  // Configure wakeup from deep sleep on all 4 buttons
  // This should probably be better handled in a task that runs with a timedelay
  esp_sleep_enable_ext1_wakeup(BTN1_mask | BTN2_mask | BTN3_mask | BTN4_mask , ESP_EXT1_WAKEUP_ANY_HIGH);
  esp_deep_sleep_start();
}


void setup()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

    Serial.begin(115200);
    delay(1000); // let serial console settle
    print_wakeup_reason();
    
    // Initiate the display object
    display.init(115200); // enable diagnostic output on Serial

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

    ledOff(); // turn off leds just in case
    showName("Michel", "Racic");
    delay(2000);
    showName("Baxter", "");
    delay(2000);
    showName("Urs", "Marti");
    delay(2000);
    showName("Christina", "");
    delay(2000);
    showName("Marco", "");
    delay(2000);
    showName("Muriel", "");
    delay(2000);
    showName("Marcus", "Cathomen");
    delay(2000);
    showName("Reto", "Wick");
    delay(2000);
    showName("Gonzalo", "Casas");
}

void loop(){ /** Intentially empty to satisfy arduino **/}

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason)
  {
    case 1  : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case 2  : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case 3  : Serial.println("Wakeup caused by timer"); break;
    case 4  : Serial.println("Wakeup caused by touchpad"); break;
    case 5  : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.println("Wakeup was not caused by deep sleep"); break;
  }
}

void ledOff() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}

void showName(const char firstname[], const char lastname[])
{
  // Display size is 176x264
  //display.fillScreen(GxEPD_WHITE);
  display.eraseDisplay(true);
  display.setRotation(3);

  int firstnamex=((sizeof(firstname) / sizeof(char *))*30)/2; // Center the text 
  display.setCursor(firstnamex /** X **/, 50 /** Y **/);
  display.setFont(&FreeSansBold24pt7b);
  display.setTextColor(GxEPD_RED);
  display.print(firstname);

  display.setCursor(100 /** X **/, 80 /** Y **/);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.print(lastname);

  display.update();
}
