#include <Arduino.h>
#include "taskheader.hpp"

// GxEPD lib and display drivers
#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.cpp>  // 2.13" b/w/r

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>

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

// Status request objects
StatusRequest updateDisplay;

// Callback method prototypes
void handleUpdateDisplay();

// Task objects
//Task tUpdateDisplay(&handleUpdateDisplay, &runner);

// Handlers
void handleUpdateDisplay() {
  Serial.println("handleUpdateDisplay() called");
  display.update(); // Update the display to show the current buffer
  delay(3000); // Delay the return so the message stays a bit, only for this demo purpose
  PrepareUpdateDisplayStatus();
}

