 // --------------------------------------
// i2c_scanner
// Based on https://playground.arduino.cc/Main/I2cScanner
//   Corrected Serial speed to NINA's defaults
//
// This sketch tests the standard 7-bit addresses
// Devices with higher bit address might not be seen properly.
//

#include <Wire.h>

// Internal I2C bus where the sensor module is connected to
#define SDA1 13  // GPIO35
#define SCL1 0   // GPIO27

// User I2C bus which is exposed in the 2 breakouts at the bottom of the badge
// Note that those have the pullups not populated, 
// depending on the module you connect you might need to populate them
#define SDA2 2   // GPIO25
#define SCL2 12  // GPIO36

void setup()
{
  Serial.begin(115200);
  delay(1000); // let serial console settle
  Serial.println("\nI2C Scanner");
}


void loop()
{
  scan("Internal I2C bus", SDA1, SCL1);
  scan("User I2C bus", SDA2, SCL2);
  delay(5000);           // wait 5 seconds for next scan
}

void scan(String busDescription, int sda, int scl)
{
  byte error, address;
  int nDevices;

  Wire.begin(sda, scl);
  Serial.print("Scanning ");
  Serial.print(busDescription);
  Serial.println("...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print(">> I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print(">> Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println(">> No I2C devices found\n");
  else
    Serial.println("done\n");
  delay(1000);
}