# SHT-Autodetect

Very simple sensor test using Sensirion SHT sensors (tested with SHT31 and the MakeZurich 2018 badge) based on the examples of [Sensirion's Arduino SHT lib](https://github.com/Sensirion/arduino-sht).

## Wiring

The sensor module on the badge contains a SHTC3 sensor and is on the internal I2C bus.

    // Internal I2C bus where the sensor module is connected to
    #define SDA1 13  // GPIO35
    #define SCL1 0   // GPIO27

## Libraries

Install the following libraries using Arduino IDE (`Sketch` -> `Include Library` -> `Manage Libraries...`):

* [Sensirion's Arduino SHT](https://github.com/Sensirion/arduino-sht)
