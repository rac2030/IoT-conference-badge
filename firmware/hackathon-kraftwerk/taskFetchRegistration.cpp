#include <Arduino.h>
#include "taskheader.hpp"
#include <WiFi.h>
#include <WiFiType.h>
#include <esp_wifi.h>
#include <Preferences.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Wifi settings at Kraftwerk
const char *ssid = "impacthub";
const char *password = "coworking@ImpactHub";

HTTPClient http;
#define GETNAME_ENDPOINT "https://golgafrincham-mekeyasfsg.now.sh/?type=get-badge-name&id="

void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info);

const char* root_ca= \
"-----BEGIN CERTIFICATE-----\n" \
"MIIEkjCCA3qgAwIBAgIQCgFBQgAAAVOFc2oLheynCDANBgkqhkiG9w0BAQsFADA/\n" \
"MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n" \
"DkRTVCBSb290IENBIFgzMB4XDTE2MDMxNzE2NDA0NloXDTIxMDMxNzE2NDA0Nlow\n" \
"SjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxIzAhBgNVBAMT\n" \
"GkxldCdzIEVuY3J5cHQgQXV0aG9yaXR5IFgzMIIBIjANBgkqhkiG9w0BAQEFAAOC\n" \
"AQ8AMIIBCgKCAQEAnNMM8FrlLke3cl03g7NoYzDq1zUmGSXhvb418XCSL7e4S0EF\n" \
"q6meNQhY7LEqxGiHC6PjdeTm86dicbp5gWAf15Gan/PQeGdxyGkOlZHP/uaZ6WA8\n" \
"SMx+yk13EiSdRxta67nsHjcAHJyse6cF6s5K671B5TaYucv9bTyWaN8jKkKQDIZ0\n" \
"Z8h/pZq4UmEUEz9l6YKHy9v6Dlb2honzhT+Xhq+w3Brvaw2VFn3EK6BlspkENnWA\n" \
"a6xK8xuQSXgvopZPKiAlKQTGdMDQMc2PMTiVFrqoM7hD8bEfwzB/onkxEz0tNvjj\n" \
"/PIzark5McWvxI0NHWQWM6r6hCm21AvA2H3DkwIDAQABo4IBfTCCAXkwEgYDVR0T\n" \
"AQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwfwYIKwYBBQUHAQEEczBxMDIG\n" \
"CCsGAQUFBzABhiZodHRwOi8vaXNyZy50cnVzdGlkLm9jc3AuaWRlbnRydXN0LmNv\n" \
"bTA7BggrBgEFBQcwAoYvaHR0cDovL2FwcHMuaWRlbnRydXN0LmNvbS9yb290cy9k\n" \
"c3Ryb290Y2F4My5wN2MwHwYDVR0jBBgwFoAUxKexpHsscfrb4UuQdf/EFWCFiRAw\n" \
"VAYDVR0gBE0wSzAIBgZngQwBAgEwPwYLKwYBBAGC3xMBAQEwMDAuBggrBgEFBQcC\n" \
"ARYiaHR0cDovL2Nwcy5yb290LXgxLmxldHNlbmNyeXB0Lm9yZzA8BgNVHR8ENTAz\n" \
"MDGgL6AthitodHRwOi8vY3JsLmlkZW50cnVzdC5jb20vRFNUUk9PVENBWDNDUkwu\n" \
"Y3JsMB0GA1UdDgQWBBSoSmpjBH3duubRObemRWXv86jsoTANBgkqhkiG9w0BAQsF\n" \
"AAOCAQEA3TPXEfNjWDjdGBX7CVW+dla5cEilaUcne8IkCJLxWh9KEik3JHRRHGJo\n" \
"uM2VcGfl96S8TihRzZvoroed6ti6WqEBmtzw3Wodatg+VyOeph4EYpr/1wXKtx8/\n" \
"wApIvJSwtmVi4MFU5aMqrSDE6ea73Mj2tcMyo5jMd6jmeWUHK8so/joWUoHOUgwu\n" \
"X4Po1QYz+3dszkDqMp4fklxBwXRsW10KXzPMTZ+sOPAveyxindmjkW8lGy+QsRlG\n" \
"PfZ+G6Z6h7mjem0Y+iWlkYcV4PIWL1iwBi8saCbGS5jN2p8M+X+Q7UNKEkROb3N6\n" \
"KOqkqm57TH2H3eDJAkSnh6/DNFu0Qg==\n" \
"-----END CERTIFICATE-----\n";

// Handlers
void handleFetchRegistration()
{
    // This handler should only be called with a timeout set, otherwise it might run indefinitely
    Serial.println("TODO: fetch registration from server over Kraftwerk wifi");
    esp_wifi_start();
    delay(3000);
    Serial.println("Connecting to WiFi network: " + String(ssid));
    WiFi.onEvent(WiFiEvent);
    WiFi.begin(ssid, password);

    unsigned long timeout = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - timeout < 5000UL)
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

    String firstName = "";
    String lastName = "";

    // Fetch details from server, parse them and update properties if name is returned
    String target = String(GETNAME_ENDPOINT) + efuseMac;
    Serial.print("Hitting ");
    Serial.print(target);
    http.begin(target, root_ca); //Specify the URL
    int httpCode = http.GET();                       //Make the request

    if (httpCode > 0)
    { //Check for the returning code
        String payload = http.getString();
        Serial.print("HTTP response code: ");
        Serial.println(httpCode);
        Serial.println("----- Payload start -----");
        Serial.println(payload);
        Serial.println("----- Payload end -----");
        
        // Parse the response
        const size_t bufferSize = 2*JSON_OBJECT_SIZE(2) + 140;
        StaticJsonDocument<bufferSize> doc;

        // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, string2char(payload));

  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
  }

  // Get the root object in the document
  JsonObject& root = doc.as<JsonObject>();

        const char* newfirstName = root["payload"]["first"];
        firstName = String(newfirstName);
        const char* newlastName = root["payload"]["second"];
        lastName = String(newlastName);

    }

    else
    {
        Serial.print("Error on HTTP request: HTTP response code is ");
        Serial.println(httpCode);
    }

    http.end(); //Free the resources

    // Properly disconnect before we disable wifi
    WiFi.disconnect(true);
    // Stop wifi again before we finish this task
    esp_wifi_stop();
    // If successful, save in preferences and run initialize again
    if (firstName != "")
    {
        preferences.begin(PREF_TAG, false); // Read/write
        firstName = preferences.putString(PREF_FIRSTNAME, firstName);
        lastName = preferences.getString(PREF_LASTNAME, lastName);
        preferences.end();
    }

    //tInitialize.enable(); or ESP.restart(); to reinit the initialization
}

/* 
* WiFi Events

SYSTEM_EVENT_WIFI_READY               < ESP32 WiFi ready
SYSTEM_EVENT_SCAN_DONE                < ESP32 finish scanning AP
SYSTEM_EVENT_STA_START                < ESP32 station start
SYSTEM_EVENT_STA_STOP                 < ESP32 station stop
SYSTEM_EVENT_STA_CONNECTED            < ESP32 station connected to AP
SYSTEM_EVENT_STA_DISCONNECTED         < ESP32 station disconnected from AP
SYSTEM_EVENT_STA_AUTHMODE_CHANGE      < the auth mode of AP connected by ESP32 station changed
SYSTEM_EVENT_STA_GOT_IP               < ESP32 station got IP from connected AP
SYSTEM_EVENT_STA_LOST_IP              < ESP32 station lost IP and the IP is reset to 0
SYSTEM_EVENT_STA_WPS_ER_SUCCESS       < ESP32 station wps succeeds in enrollee mode
SYSTEM_EVENT_STA_WPS_ER_FAILED        < ESP32 station wps fails in enrollee mode
SYSTEM_EVENT_STA_WPS_ER_TIMEOUT       < ESP32 station wps timeout in enrollee mode
SYSTEM_EVENT_STA_WPS_ER_PIN           < ESP32 station wps pin code in enrollee mode
SYSTEM_EVENT_AP_START                 < ESP32 soft-AP start
SYSTEM_EVENT_AP_STOP                  < ESP32 soft-AP stop
SYSTEM_EVENT_AP_STACONNECTED          < a station connected to ESP32 soft-AP
SYSTEM_EVENT_AP_STADISCONNECTED       < a station disconnected from ESP32 soft-AP
SYSTEM_EVENT_AP_PROBEREQRECVED        < Receive probe request packet in soft-AP interface
SYSTEM_EVENT_GOT_IP6                  < ESP32 station or ap or ethernet interface v6IP addr is preferred
SYSTEM_EVENT_ETH_START                < ESP32 ethernet start
SYSTEM_EVENT_ETH_STOP                 < ESP32 ethernet stop
SYSTEM_EVENT_ETH_CONNECTED            < ESP32 ethernet phy link up
SYSTEM_EVENT_ETH_DISCONNECTED         < ESP32 ethernet phy link down
SYSTEM_EVENT_ETH_GOT_IP               < ESP32 ethernet got IP from connected AP
SYSTEM_EVENT_MAX
*/
void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info)
{
    Serial.printf("[WiFi-event] event: %d\n", event);
    Serial.printf("Current RSSI=%d\n", WiFi.RSSI());
    switch (event)
    {
    case SYSTEM_EVENT_STA_GOT_IP:
        Serial.print("WiFi connected and got ");
        Serial.print("IP address: ");
        Serial.println(IPAddress(info.got_ip.ip_info.ip.addr));
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        Serial.print("WiFi lost connection. Reason: ");
        // Reasons found on https://www.esp32.com/viewtopic.php?t=349
        String disconnectReason;
        switch (info.disconnected.reason)
        {
        case 1:
            disconnectReason = "WIFI_REASON_UNSPECIFIED";
            break;
        case 2:
            disconnectReason = "WIFI_REASON_AUTH_EXPIRE";
            break;
        case 3:
            disconnectReason = "WIFI_REASON_AUTH_LEAVE";
            break;
        case 4:
            disconnectReason = "WIFI_REASON_ASSOC_EXPIRE";
            break;
        case 5:
            disconnectReason = "WIFI_REASON_ASSOC_TOOMANY";
            break;
        case 6:
            disconnectReason = "WIFI_REASON_NOT_AUTHED";
            break;
        case 7:
            disconnectReason = "WIFI_REASON_NOT_ASSOCED";
            break;
        case 8:
            disconnectReason = "WIFI_REASON_ASSOC_LEAVE";
            break;
        case 9:
            disconnectReason = "WIFI_REASON_ASSOC_NOT_AUTHED";
            break;
        case 10:
            disconnectReason = "WIFI_REASON_DISASSOC_PWRCAP_BAD";
            break;
        case 11:
            disconnectReason = "WIFI_REASON_DISASSOC_SUPCHAN_BAD";
            break;
        case 13:
            disconnectReason = "WIFI_REASON_IE_INVALID";
            break;
        case 14:
            disconnectReason = "WIFI_REASON_MIC_FAILURE";
            break;
        case 15:
            disconnectReason = "WIFI_REASON_4WAY_HANDSHAKE_TIMEOUT";
            break;
        case 16:
            disconnectReason = "WIFI_REASON_GROUP_KEY_UPDATE_TIMEOUT";
            break;
        case 17:
            disconnectReason = "WIFI_REASON_IE_IN_4WAY_DIFFERS";
            break;
        case 18:
            disconnectReason = "WIFI_REASON_GROUP_CIPHER_INVALID";
            break;
        case 19:
            disconnectReason = "WIFI_REASON_PAIRWISE_CIPHER_INVALID";
            break;
        case 20:
            disconnectReason = "WIFI_REASON_AKMP_INVALID";
            break;
        case 21:
            disconnectReason = "WIFI_REASON_UNSUPP_RSN_IE_VERSION";
            break;
        case 22:
            disconnectReason = "WIFI_REASON_INVALID_RSN_IE_CAP";
            break;
        case 23:
            disconnectReason = "WIFI_REASON_802_1X_AUTH_FAILED";
            break;
        case 24:
            disconnectReason = "WIFI_REASON_CIPHER_SUITE_REJECTED";
            break;
        case 200:
            disconnectReason = "WIFI_REASON_BEACON_TIMEOUT";
            break;
        case 201:
            disconnectReason = "WIFI_REASON_NO_AP_FOUND";
            break;
        case 202:
            disconnectReason = "WIFI_REASON_AUTH_FAIL";
            break;
        case 203:
            disconnectReason = "WIFI_REASON_ASSOC_FAIL";
            break;
        case 204:
            disconnectReason = "WIFI_REASON_HANDSHAKE_TIMEOUT";
            break;
        }
        Serial.println(disconnectReason);
        break;
    }
}
