/* 
* LED siren example for MakeZurich badge 2018
*/

#include "FastLED.h"

#define NUM_LEDS 2
#define DATA_PIN 27 // GPIO18

// Delays used inside siren algorithm
#define SHORT_DELAY 200
#define LONG_DELAY  1000

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  Serial.println("\n\nSiren example");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  siren();
  ledOff();
  delay(1000);
}

void siren() {
  // This will flash the leds 10 times from red to blue slowly (each on its side and the other off)
  for(int i = 0; i <= 10; i++) {
    showRedBlack(LONG_DELAY);
    showBlackBlue(LONG_DELAY);
  }
  
  // This will flash each side multiple times fast but switch between the two with the same pace
  for(int i = 0; i <= 10; i++) {
    for(int j = 0; j <= 5; j++) {
      showRedBlack(SHORT_DELAY);
    }
    for(int j = 0; j <= 5; j++) {
      showBlackBlue(SHORT_DELAY);
    }
  }

  // This will flash quickly between both LEDs
  for(int i = 0; i <= 30; i++) {
    showRedBlack(SHORT_DELAY);
    showBlackBlue(SHORT_DELAY);
  }
  
}

void ledOff() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}


void showRedBlack(int delayTime) {
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Black;
  FastLED.show();
  delay(delayTime);
}

void showBlackBlue(int delayTime) {
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Black;
  FastLED.show();
  delay(delayTime);
}