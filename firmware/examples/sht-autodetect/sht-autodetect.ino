#include <Wire.h>

#include "SHTSensor.h"

// Internal I2C bus where the sensor module is connected to
#define SDA1 13  // GPIO35
#define SCL1 0   // GPIO27

// SHTSensor sht; // Use this if you want to use Autodetect
// To use a specific sensor instead of probing the bus use this command:
SHTSensor sht(SHTSensor::SHTC1); // We have an SHTC3 on the badge but the communication to it is the same

void setup() {
  Wire.begin(SDA1, SCL1);
  Serial.begin(115200);
  delay(1000); // let serial console settle

  if (sht.init()) {
      Serial.print("init(): success\n");
  } else {
      Serial.print("init(): failed\n");
  }

}

void loop() {
  if (sht.readSample()) {
      Serial.print("SHTC3:\n");
      Serial.print("  RH: ");
      Serial.print(sht.getHumidity(), 2);
      Serial.print("\n");
      Serial.print("  T:  ");
      Serial.print(sht.getTemperature(), 2);
      Serial.print("\n");
  } else {
      Serial.print("Error in readSample()\n");
  }

  delay(1000);
}
