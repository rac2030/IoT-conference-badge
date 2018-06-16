/* 
* LED siren example for MakeZurich badge 2018
*/
#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"

#define NUM_LEDS 2
#define DATA_PIN 27 // GPIO18

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  Serial.println("\n\nTurn LEDs off");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  ledOff();
  delay(5000);
}

void ledOff() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}
