#include <Arduino.h>
#include "taskheader.hpp"
#include "mzlogo.h"

// Task objects

// Handlers
void handleSplashView() {
    Serial.println("Show splash screen");
    //display.fillScreen(GxEPD_WHITE);
    //display.drawBitmap(0, 0, IMAGE_MZ_LOGO_FULLSCREEN, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
    // Signal display to show the buffer
    //updateDisplay.signalComplete();
    //display.drawExampleBitmap(IMAGE_MZ_LOGO_FULLSCREEN, sizeof(IMAGE_MZ_LOGO_FULLSCREEN));
    display.drawBitmap(IMAGE_MZ_LOGO_FULLSCREEN, sizeof(IMAGE_MZ_LOGO_FULLSCREEN), 1);
    delay(2000);
}
