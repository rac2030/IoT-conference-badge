// GxEPD lib and display drivers
#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.cpp>  // 2.13" b/w/r
#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>

#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>

//NINA
//static const uint8_t SS    = 5;  //GPIO28
//static const uint8_t MOSI  = 23; //GPIO1
//static const uint8_t MISO  = 19; // not used for waveshare display
//static const uint8_t SCK   = 18; // GPIO29

// NINA
static const uint8_t DC = 22;      //GPIO20
static const uint8_t RST = 21;     //GPIO8
static const uint8_t BUSYN = 4;    //GPIO24

GxIO_Class io(SPI, SS, DC, RST); 
GxEPD_Class display(io, RST, BUSYN); 

#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"
#define DATA_PIN 27                // GPIO18
#define NUM_LEDS 2
CRGB leds[NUM_LEDS];

void setup()
{
  Serial.begin(115200);
  delay(1000); // let serial console settle

  Serial.println();

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.println("setup");
  display.init(115200); // enable diagnostic output on Serial
  Serial.println("setup done");
}

void loop()
{
  // Turn off twice because the rgb leds on the proto board are giving me attitude
  ledOff();
  ledOff();

  Serial.println("Showing bitmap");
  showBitmapExample();
  Serial.println("Bitmap example done");
  delay(2000);

  Serial.println("drawing corners");
  drawCornerTest();
  showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
  showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);
  //showFont("FreeMonoBold18pt7b", &FreeMonoBold18pt7b);
  //showFont("FreeMonoBold24pt7b", &FreeMonoBold24pt7b);
  delay(10000);
}

void ledOff() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}

#if defined(_GxGDEW0213Z16_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
  display.drawPicture(BitmapWaveshare_black, BitmapWaveshare_red, sizeof(BitmapWaveshare_black), sizeof(BitmapWaveshare_red));
  delay(5000);
  display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  delay(5000);
#if !defined(__AVR)
  display.drawExamplePicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample3), sizeof(BitmapExample4));
  delay(5000);
#endif
  display.drawExampleBitmap(BitmapWaveshare_black, sizeof(BitmapWaveshare_black));
  delay(2000);
  // example bitmaps for b/w/r are normal on b/w, but inverted on red
  display.drawExampleBitmap(BitmapExample1, sizeof(BitmapExample1));
  delay(2000);
  display.drawExampleBitmap(BitmapExample2, sizeof(BitmapExample2), GxEPD::bm_invert);
  delay(2000);
  display.drawExampleBitmap(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
}
#endif

void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#if defined(HAS_RED_COLOR)
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
  display.update();
  delay(5000);
}

void showFontCallback()
{
  const char* name = "FreeMonoBold9pt7b";
  const GFXfont* f = &FreeMonoBold9pt7b;
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#if defined(HAS_RED_COLOR)
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
}

void drawCornerTest()
{
  display.drawCornerTest();
  delay(5000);
  uint8_t rotation = display.getRotation();
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillScreen(GxEPD_WHITE);
    display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
    display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
    display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
    display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
    display.update();
    delay(5000);
  }
  display.setRotation(rotation); // restore
}

