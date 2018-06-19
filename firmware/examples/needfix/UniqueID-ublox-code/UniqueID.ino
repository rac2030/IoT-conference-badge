

#include <stdlib.h>
#include <string.h>
#include "esp_system.h"
#include "otp_reader.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);
}

void loop()
{
  Serial.print("EfuseMac = ");
  Serial.println(UniqueID());
  
  char to_print[cbOTP_SIZE_SERIAL];
    uint8_t mac[6];
    uint8_t serial_number[cbOTP_SIZE_SERIAL];
    uint8_t mask[cbOTP_SIZE_FEATURE_MASK];
    esp_err_t err;

Serial.println("Reading efuse mac:");
    err = esp_efuse_mac_get_default(mac);
    if (err == ESP_OK) {
        dataToHex(mac, 6, to_print);
        Serial.printf("Espressif Base MAC address which is stored in BLK0 of EFUSE: %s\n", to_print);
    } else {
        Serial.printf("Failed to read Espressif base MAC\n");
    }

    Serial.println("Reading ublox serial");

    err = otp_read_serial_number(serial_number);
    Serial.println("Convert to hex");
    if (err == ESP_OK) {
        dataToHex(serial_number, cbOTP_SIZE_SERIAL, to_print);
        Serial.printf("u-blox unit Serial Number: 0x%s\n", to_print);
    } else {
        Serial.printf("Failed to read u-blox Serial Number\n");
    }

    Serial.println("Finished loop");
    delay(5000);
}

static void dataToHex(uint8_t* data, uint32_t len, char* result)
{
    uint32_t i;

    result[0] = 0;
    for (i = 0; i < len; i++) {
        sprintf(&(result[i * 2]), "%02X", data[i]);
    }
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