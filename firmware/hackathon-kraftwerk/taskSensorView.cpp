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

void showSensorData();

boolean sensorViewRefresh = false;

// Handlers
void handleSensorView()
{
  triggerAquireSensorData.signal();
  showSensorData();
  // Signal display to show the buffer
  updateDisplay.signalComplete();
  // Check if refresh true sensorViewRefresh
  if(sensorViewRefresh) {
    tSensorViewRefresh.enable();
  } else {
    tSensorViewRefresh.disable();
  }

  displaySensorView.setWaiting();
  tSensorView.waitFor(&displaySensorView);
}

void setSensorViewRefresh(boolean state) {
  sensorViewRefresh = state;
} 

void showSensorData()
{
  display.fillScreen(GxEPD_WHITE);
  //display.eraseDisplay(true); // does not flush the buffer
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
