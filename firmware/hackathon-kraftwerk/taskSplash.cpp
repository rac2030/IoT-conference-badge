#include <Arduino.h>
#include "taskheader.hpp"
#include "mzlogo.h"

// Handlers
void handleSplashView()
{
  Serial.println("Show splash screen");
  display.drawBitmap(IMAGE_MZ_LOGO_FULLSCREEN, sizeof(IMAGE_MZ_LOGO_FULLSCREEN), 1);
  delay(2000); // give it some time to really display it
}
