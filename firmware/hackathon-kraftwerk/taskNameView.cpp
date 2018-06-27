#include <Arduino.h>
#include "taskheader.hpp"

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeSansBold24pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include "GxFont_GFX.h"


StatusRequest displayNameView;

// Helper prototypes
void showName(String firstname, String lastname);
char* string2char(String command);

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

  display.setFont(&FreeSansBold24pt7b);
  display.setTextColor(GxEPD_RED);
  // Get size of rendered text
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds( string2char(firstname), 0, 0, &x1, &y1, &w, &h );
  if((display.width() - 10 - w) <= 0) {
    // Text is too big, choose a smaller font and recalculate centering text again
    display.setFont(&FreeSansBold18pt7b);
    display.getTextBounds( string2char(firstname), 0, 0, &x1, &y1, &w, &h );
  }
  if((display.width() - 10 - w) <= 0) {
    // Text is still too big, choose a smaller font and recalculate centering text again
    display.setFont(&FreeSansBold12pt7b);
    display.getTextBounds( string2char(firstname), 0, 0, &x1, &y1, &w, &h );
  }
  if((display.width() - 10 - w) <= 0) {
    // Text is still too big, choose a smaller font and recalculate centering text again
    // last try, we just choose the one we use for last name
    display.setFont(&FreeSans9pt7b);
    display.getTextBounds( string2char(firstname), 0, 0, &x1, &y1, &w, &h );
  }
  int firstnamex = ( display.width() - w ) / 2; // Center the text
  display.setCursor(firstnamex /** X **/, 50 /** Y **/);
  display.print(firstname);

  display.setTextColor(GxEPD_BLACK);
  display.setFont(&FreeSans9pt7b);
  display.getTextBounds( string2char(lastName), 0, 0, &x1, &y1, &w, &h );
  int lastnamex = ( display.width() - w - 10); // Right align the text
  display.setCursor(lastnamex /** X **/, 80 /** Y **/);
  display.print(lastname);
}

char* string2char(String command){
    if(command.length()!=0){
        char *p = const_cast<char*>(command.c_str());
        return p;
    }
}