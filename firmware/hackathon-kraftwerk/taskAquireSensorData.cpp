#include <Arduino.h>
#include "taskheader.hpp"
#include <sensirion_mzbadge.h>

bool initialized = false;

float temp, rh, tvoc;

//  Create an instance of SensirionMZBADGE
SensirionMZBADGE sendorModule;

StatusRequest triggerAquireSensorData;

// Handlers
void handleAquireSensorData()
{
  // Check if already initialized, do so if not
  if (!initialized)
  {
    if (sendorModule.initSensors() != 0)
    {
      Serial.print("Error while initializing sensors: ");
      Serial.print(sendorModule.getError());
      Serial.print("\n");
      return; //we exit this method as we can't do anything
    }
    initialized = true;
  }

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

  // and then, we'll use remainingWaitTimeMS() to ensure the correct
  // Measurement rate
  delay(sendorModule.remainingWaitTimeMS());
  triggerAquireSensorData.setWaiting();
  tTriggerAquireSensorView.waitFor(&triggerAquireSensorData);
}
