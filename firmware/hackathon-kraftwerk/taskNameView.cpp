#include <Arduino.h>
#include "taskheader.hpp"

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeSansBold24pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

StatusRequest displayNameView;

// Helper prototypes
void showName(String firstname, String lastname);

// Handlers
void handleNameView()
{
  showName(firstName, lastName);
  // Signal display to show the buffer
  updateDisplay.signalComplete();
  displayNameView.setWaiting();
  tNameView.waitFor(&displayNameView);
}

void showName(String firstname, String lastname)
{
  // Display size is 176x264
  display.fillScreen(GxEPD_WHITE);
  //display.eraseDisplay(true);
  display.setRotation(3);

  int firstnamex = ((sizeof(firstname) / sizeof(char *)) * 30) / 2; // Center the text
  display.setCursor(firstnamex /** X **/, 50 /** Y **/);
  display.setFont(&FreeSansBold24pt7b);
  display.setTextColor(GxEPD_RED);
  display.print(firstname);

  display.setCursor(100 /** X **/, 80 /** Y **/);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.print(lastname);
}