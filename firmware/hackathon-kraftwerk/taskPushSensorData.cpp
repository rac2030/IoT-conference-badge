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
    "MIICiTCCAg+gAwIBAgIQH0evqmIAcFBUTAGem2OZKjAKBggqhkjOPQQDAzCBhTEL\n"
    "MAkGA1UEBhMCR0IxGzAZBgNVBAgTEkdyZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UE\n"
    "BxMHU2FsZm9yZDEaMBgGA1UEChMRQ09NT0RPIENBIExpbWl0ZWQxKzApBgNVBAMT\n"
    "IkNPTU9ETyBFQ0MgQ2VydGlmaWNhdGlvbiBBdXRob3JpdHkwHhcNMDgwMzA2MDAw\n"
    "MDAwWhcNMzgwMTE4MjM1OTU5WjCBhTELMAkGA1UEBhMCR0IxGzAZBgNVBAgTEkdy\n"
    "ZWF0ZXIgTWFuY2hlc3RlcjEQMA4GA1UEBxMHU2FsZm9yZDEaMBgGA1UEChMRQ09N\n"
    "T0RPIENBIExpbWl0ZWQxKzApBgNVBAMTIkNPTU9ETyBFQ0MgQ2VydGlmaWNhdGlv\n"
    "biBBdXRob3JpdHkwdjAQBgcqhkjOPQIBBgUrgQQAIgNiAAQDR3svdcmCFYX7deSR\n"
    "FtSrYpn1PlILBs5BAH+X4QokPB0BBO490o0JlwzgdeT6+3eKKvUDYEs2ixYjFq0J\n"
    "cfRK9ChQtP6IHG4/bC8vCVlbpVsLM5niwz2J+Wos77LTBumjQjBAMB0GA1UdDgQW\n"
    "BBR1cacZSBm8nZ3qQUfflMRId5nTeTAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0TAQH/\n"
    "BAUwAwEB/zAKBggqhkjOPQQDAwNoADBlAjEA7wNbeqy3eApyt4jf/7VGFAkK+qDm\n"
    "fQjGGoe9GKhzvSbKYAydzpmfz1wPMOG+FDHqAjAU9JM8SaczepBGR7NjfRObTrdv\n"
    "GDeAU/7dIOA1mjbRxwG55tzd8/8dLDoWV9mSOdY=\n"
    "-----END CERTIFICATE-----\n";