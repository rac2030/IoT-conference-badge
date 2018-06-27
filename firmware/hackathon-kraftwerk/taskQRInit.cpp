#include <Arduino.h>
#include "taskheader.hpp"

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold12pt7b.h>

#include "qrcode.h"
QRcode qrcode(&display);

StatusRequest displayQRView;

// Callback method prototypes
void handleQRView();

// Helper prototypes
void writeQRInitScreen();

// Handlers
void handleQRView()
{
    // Generate the QR Code given the chipID
    qrcode.generate(efuseMac);
    // Fill display buffer
    writeQRInitScreen();
    // Signal display to show the buffer
    updateDisplay.signalComplete();

    displayQRView.setWaiting();
    tQRView.waitFor(&displayQRView);
}

/**
 * Fill the display buffer with the QR code generated
 */
void writeQRInitScreen()
{
    display.setCursor(0, 0);
    display.fillScreen(GxEPD_WHITE); // Make the screen empty
    display.setRotation(3);          // Set the rotation for the badge display orientation

    qrcode.writeToDisplayBuffer(5 /** X **/, 5 /** Y **/); // Display chipID as QR Code into current buffer

    // Display some text next to it
    display.setFont(&FreeMonoBold12pt7b);
    // Print MakeZurich big using red for upper case letters
    display.println("");                          // Add an empty line as otherwise text is cut at the top
    display.setCursor(110, display.getCursorY()); // Use offset to be next to QR code
    display.setTextColor(GxEPD_RED);
    display.print("M");
    display.setTextColor(GxEPD_BLACK);
    display.print("ake");

    // Go to next line
    display.println("");
    // on each new line we have to set the X offset again
    display.setCursor(110, display.getCursorY()); // Use offset to be next to QR code

    display.setTextColor(GxEPD_RED);
    display.print("Z");
    display.setTextColor(GxEPD_BLACK);
    display.print("urich");

    // Display init text
    // Make 1 line as space between
    display.print("\n\n");
    // on each new line we have to set the X offset again
    display.setCursor(105, display.getCursorY()); // Use offset to be next to QR code
    display.setFont();
    display.setTextColor(GxEPD_BLACK);
    display.print(efuseMac);
}