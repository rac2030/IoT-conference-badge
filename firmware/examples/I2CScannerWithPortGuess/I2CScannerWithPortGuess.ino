/**
 * This is an I2C scanner for the MakeZurich badge, customized for the NINA Breakout.
 * based on the original code
 * available on Arduino.cc and later improved by user Krodal and Nick Gammon (www.gammon.com.au/forum/?id=10896)
 * and probably others adjusted to serve as test code and example for the badge.
 * @author Michel Racic
 **/

#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Serial.println("\n\nI2C Scanner to scan for devices on each GPIO port pair");
}

// This is a list of all GPIOs, I excluded GPIs as they are not suitable for I2C AFAIK
// Those are the actual ESP32 pins
uint8_t portArray[] = {23, 32, 33, 21, 25, 26, 27, 22, 19, 1, 3, 4, 2, 0, 5, 18, 14, 15, 13, 12};
//This array is just needed to display the friendly name from the NINA-W102 pinout
String portMap[] = {"IO1", "IO5", "IO7", "IO8", "IO16", "IO17", "IO18", "IO20", "IO21", "IO22" "IO23", "IO24", "IO25", "IO27", "IO28", "IO29", "IO31", "IO32", "IO35", "IO36" };

// Disble ports if it hangs at certain ports with strange characters or rebooting...
//uint8_t portArray[] = {32, 33, 21, 25, 26, 27, 22, 4, 2, 0, 5, 18, 14, 15, 13, 12};
//String portMap[] = {"IO5", "IO7", "IO8", "IO16", "IO17", "IO18", "IO20", "IO24", "IO25", "IO27", "IO28", "IO29", "IO31", "IO32", "IO35", "IO36" };

//uint8_t portArray[] = {21, 22};
//String portMap[] = {"IO21", "IO22"};

void scanPorts() { 
  for (uint8_t i = 0; i < sizeof(portArray); i++) {
    for (uint8_t j = 0; j < sizeof(portArray); j++) {
      if (i != j){
        Serial.print("Scanning (SDA : SCL) - ");
        Serial.print(portMap[i]);
        Serial.print(" : ");
        Serial.println(portMap[j]);
        //TODO maybe add speed evaluation?
        Wire.begin(portArray[i], portArray[j], 100000 /** bus speed in Hz **/);
        delay(200);
        check_if_exist_I2C();
        Wire.reset();
      }
    }
  }
}

void check_if_exist_I2C() {
  byte error, address;
  int nDevices;
  nDevices = 0;
  for (address = 1; address < 127; address++ )  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0){
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknow error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  } //for loop
  if (nDevices == 0)
    Serial.println("No I2C devices found");
  else
    Serial.println("**********************************\n");
}

void loop() {
  scanPorts();
  delay(3000);  
}
