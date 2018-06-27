#include <Arduino.h>
#include "taskheader.hpp"

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeSansBold24pt7b.h>
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include "GxFont_GFX.h"

#include <sensirion_mzbadge.h>

StatusRequest displaySensorView;
bool initialized = false;

//  Create an instance of SensirionMZBADGE
SensirionMZBADGE sendorModule;

// Helper prototypes
void showSensorData(float temp, float rh, float tvoc);

// Handlers
void handleSensorView()
{
  // Check if already initialized, do so if not
  if (!initialized)
  {
    if (sendorModule.initSensors() != 0)
    {
      Serial.print("Error while initializing sensors: ");
      Serial.print(sendorModule.getError());
      Serial.print("\n");
      //TODO: Display error on EPD
      return; //we exit this method as we can't do anything
    }
  }

  float temp, rh, tvoc;
  // we'll start by triggering a measurement of the VOC/CO2 sensor;
  // it's important to do this first to make sure sleep timing is
  // correct. If the command succeeds, the local variables will
  // be set to the values we just read; if it fails, they'll be -1
  if (sendorModule.measureIAQ() != 0)
  {
    Serial.print("Error while measuring IAQ: ");
    Serial.print(sendorModule.getError());
    Serial.print("\n");
  }
  else
  {
    tvoc = sendorModule.getTVOC();
  }

  // next, we'll trigger the humidity and temperature measurement
  if (sendorModule.measureRHT() != 0)
  {
    Serial.print("Error while measuring RHT: ");
    Serial.print(sendorModule.getError());
    Serial.print("\n");
  }
  else
  {
    temp = sendorModule.getTemperature();
    rh = sendorModule.getHumidity();
  }

  // finally, let's print those to the serial console
  Serial.printf("%f°C with %f RH and a TVOC of %f\n", temp, rh, tvoc);

  showSensorData(temp, rh, tvoc);
  // Signal display to show the buffer
  updateDisplay.signalComplete();

  // and then, we'll use remainingWaitTimeMS() to ensure the correct
  // Measurement rate
  delay(sendorModule.remainingWaitTimeMS());

  displaySensorView.setWaiting();
  tSensorView.waitFor(&displaySensorView);
}

void showSensorData(float temp, float rh, float tvoc)
{
  display.fillScreen(GxEPD_WHITE);
  //display.eraseDisplay(true);
  display.setRotation(3);
  display.setCursor(0, 0);

  display.setFont(&FreeSans9pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.println("");
  display.print("Temperature: ");
  display.print(String(temp, 1));
  display.println(" °C");
  display.print("Relative Humidity: ");
  display.print(String(rh, 1));
  display.println("%");
  display.print("VOCs: ");
  display.print(String(tvoc, 6));
  display.println(" ppb");

  display.setFont();
  display.println("\nProvided by Sensirion SHTC3 & SGPC3");

}
