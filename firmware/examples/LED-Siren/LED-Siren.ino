/* 
* LED siren example for MakeZurich badge 2018
*/
#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"

#define NUM_LEDS 2
#define DATA_PIN 27 // GPIO18

// Delays used inside siren algorithm
#define SHORT_DELAY 100
#define LONG_DELAY  500

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  Serial.println("\n\nSiren example");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  siren();
  Serial.println("Siren off");
  ledOff();
  delay(5000);
}

void siren() {
  // This will flash the leds 5 times from red to blue slowly (each on its side and the other off)
  Serial.println("Long flash");
  for(int i = 0; i <= 5; i++) {
    Serial.print("RED---");
    showRedBlack(LONG_DELAY);
    Serial.print("BLUE---\n");
    showBlackBlue(LONG_DELAY);
  }
  
  // This will flash each side multiple times fast but switch between the two with the same pace
  for(int i = 0; i <= 5; i++) {
    for(int j = 0; j <= 5; j++) {
      Serial.print("RED-");
      showRedBlack(SHORT_DELAY);
      ledOff();
      delay(50);
    }
    for(int j = 0; j <= 5; j++) {
      Serial.print("BLUE-");
      showBlackBlue(SHORT_DELAY);
      ledOff();
      delay(50);
    }
    Serial.print("\n");
  }

  // This will flash quickly between both LEDs
  Serial.println("Quick flash");
  for(int i = 0; i <= 30; i++) {
    Serial.print("RED-");
    showRedBlack(SHORT_DELAY);
    Serial.print("BLUE-\n");
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
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Blue;
  FastLED.show();
  delay(delayTime);
}