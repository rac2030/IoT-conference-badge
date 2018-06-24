/**
 * Example to generate QR Code from chipID
 * (modified the code from https://github.com/anunpanya/ESP8266_QRcode/tree/master/src to fit our setup)
 * and display it with some text next to it
 **/

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

#include "qrcode.h"
QRcode qrcode (&display);

void setup()
{
  Serial.begin(115200);
  // Initiate the display object
  display.init(115200); // enable diagnostic output on Serial
  
  delay(1000); // let serial console settle

  Serial.println("\n\nGxEPD display test for MakeZurich 2018 badge");

  // enable debug qrcode
  qrcode.debug();
  // create qrcode
  qrcode.generate(UniqueID());
  showQRInitScreen();
}

void loop()
{
 // Serial.println("Start the loop with MakeZurich text");
//  showMZText();

  
  delay(5000);
}

void showQRInitScreen() {
  display.fillScreen(GxEPD_WHITE); // Make the screen empty
  display.setRotation(3); // Set the rotation for the badge display orientation

  qrcode.writeToDisplayBuffer(5 /** X **/, 5 /** Y **/); // Display chipID as QR Code into current buffer

  // Display some text next to it
  display.setFont(&FreeMonoBold12pt7b);
  // Print MakeZurich big using red for upper case letters
  display.println(""); // Add an empty line as otherwise text is cut at the top
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
  display.print(UniqueID());

  display.update(); // Update the display to show the current buffer
  delay(5000); // Delay the return so the message stays a bit, only for this demo purpose
}

String UniqueID()
{
  uint64_t id = ESP.getEfuseMac();
  char id_h[9];
  char id_l[9];

  sprintf(id_h, "%08X", (uint32_t)(id>>32));
  sprintf(id_l, "%08X", (uint32_t)(id));

  return String(id_h) + String(id_l);
}
