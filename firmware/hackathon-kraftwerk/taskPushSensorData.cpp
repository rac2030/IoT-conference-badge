#include <Arduino.h>
#include "taskheader.hpp"
#include <esp_wifi.h>
#include <Preferences.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "networkSettings.h"

HTTPClient httpsensor;

// Handlers
void handlePushSensorData()
{
    // This handler should only be called with a timeout set, otherwise it might run indefinitely
    Serial.println("Post sensor data");
    esp_wifi_start();
    delay(5000);
    Serial.println("Connecting to WiFi network: " + String(WIFI_SSID));
    WiFi.onEvent(WiFiEvent);
    WiFi.begin(WIFI_SSID, WIFI_PW);

    unsigned long timeout = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - timeout < 10000UL)
    {
        Serial.print(".");
        delay(500);
    }
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WiFi connected!");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
    else
    {
        Serial.println(F("Could not connect!"));
    }

    String target = String(SERVER_BASEPATH);
    Serial.print("Hitting ");
    Serial.println(target);

    const size_t bufferSize = 2 * JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(6);
    StaticJsonDocument<bufferSize> doc;
    JsonObject &root = doc.to<JsonObject>();
    JsonObject &meta = root.createNestedObject("meta");
    meta["id"] = efuseMac;
    meta["type"] = "post-data";

    JsonObject &payload = root.createNestedObject("payload");
    payload["temp"] = String(temp, 6);
    payload["rh"] = String(rh, 6);
    payload["tvoc"] = String(tvoc, 6);
    String output;
    serializeJson(root, output);
    Serial.println("----- post Payload start -----");
    Serial.println(output);
    Serial.println("----- post Payload end -----");

    httpsensor.begin(target, root_ca); //Specify the URL
    httpsensor.addHeader("Content-Type", "application/json"); //Specify content-type header
    int httpCode = httpsensor.POST(output); //Send the actual POST request

    if (httpCode > 0)
    { //Check for the returning code
        String payload = httpsensor.getString();
        Serial.print("HTTP response code: ");
        Serial.println(httpCode);
        Serial.println("----- Payload start -----");
        Serial.println(payload);
        Serial.println("----- Payload end -----");
    }
    else
    {
        Serial.print("Error on HTTP Post request: HTTP response code is ");
        Serial.println(httpCode);
    }

    httpsensor.end(); //Free the resources

    // Properly disconnect before we disable wifi
    WiFi.disconnect(true);
    // Stop wifi again before we finish this task
    esp_wifi_stop();
}

const char *WIFI_SSID = "impacthub";
const char *WIFI_PW = "coworking@ImpactHub";

const char *root_ca =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIEkjCCA3qgAwIBAgIQCgFBQgAAAVOFc2oLheynCDANBgkqhkiG9w0BAQsFADA/\n"
    "MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n"
    "DkRTVCBSb290IENBIFgzMB4XDTE2MDMxNzE2NDA0NloXDTIxMDMxNzE2NDA0Nlow\n"
    "SjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxIzAhBgNVBAMT\n"
    "GkxldCdzIEVuY3J5cHQgQXV0aG9yaXR5IFgzMIIBIjANBgkqhkiG9w0BAQEFAAOC\n"
    "AQ8AMIIBCgKCAQEAnNMM8FrlLke3cl03g7NoYzDq1zUmGSXhvb418XCSL7e4S0EF\n"
    "q6meNQhY7LEqxGiHC6PjdeTm86dicbp5gWAf15Gan/PQeGdxyGkOlZHP/uaZ6WA8\n"
    "SMx+yk13EiSdRxta67nsHjcAHJyse6cF6s5K671B5TaYucv9bTyWaN8jKkKQDIZ0\n"
    "Z8h/pZq4UmEUEz9l6YKHy9v6Dlb2honzhT+Xhq+w3Brvaw2VFn3EK6BlspkENnWA\n"
    "a6xK8xuQSXgvopZPKiAlKQTGdMDQMc2PMTiVFrqoM7hD8bEfwzB/onkxEz0tNvjj\n"
    "/PIzark5McWvxI0NHWQWM6r6hCm21AvA2H3DkwIDAQABo4IBfTCCAXkwEgYDVR0T\n"
    "AQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwfwYIKwYBBQUHAQEEczBxMDIG\n"
    "CCsGAQUFBzABhiZodHRwOi8vaXNyZy50cnVzdGlkLm9jc3AuaWRlbnRydXN0LmNv\n"
    "bTA7BggrBgEFBQcwAoYvaHR0cDovL2FwcHMuaWRlbnRydXN0LmNvbS9yb290cy9k\n"
    "c3Ryb290Y2F4My5wN2MwHwYDVR0jBBgwFoAUxKexpHsscfrb4UuQdf/EFWCFiRAw\n"
    "VAYDVR0gBE0wSzAIBgZngQwBAgEwPwYLKwYBBAGC3xMBAQEwMDAuBggrBgEFBQcC\n"
    "ARYiaHR0cDovL2Nwcy5yb290LXgxLmxldHNlbmNyeXB0Lm9yZzA8BgNVHR8ENTAz\n"
    "MDGgL6AthitodHRwOi8vY3JsLmlkZW50cnVzdC5jb20vRFNUUk9PVENBWDNDUkwu\n"
    "Y3JsMB0GA1UdDgQWBBSoSmpjBH3duubRObemRWXv86jsoTANBgkqhkiG9w0BAQsF\n"
    "AAOCAQEA3TPXEfNjWDjdGBX7CVW+dla5cEilaUcne8IkCJLxWh9KEik3JHRRHGJo\n"
    "uM2VcGfl96S8TihRzZvoroed6ti6WqEBmtzw3Wodatg+VyOeph4EYpr/1wXKtx8/\n"
    "wApIvJSwtmVi4MFU5aMqrSDE6ea73Mj2tcMyo5jMd6jmeWUHK8so/joWUoHOUgwu\n"
    "X4Po1QYz+3dszkDqMp4fklxBwXRsW10KXzPMTZ+sOPAveyxindmjkW8lGy+QsRlG\n"
    "PfZ+G6Z6h7mjem0Y+iWlkYcV4PIWL1iwBi8saCbGS5jN2p8M+X+Q7UNKEkROb3N6\n"
    "KOqkqm57TH2H3eDJAkSnh6/DNFu0Qg==\n"
    "-----END CERTIFICATE-----\n";