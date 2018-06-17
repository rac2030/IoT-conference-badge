/*
 *  This sketch shows the WiFi event usage
 *
*/

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

#define SerialDebug true  // set to true to get Serial output for debugging

#include <WiFi.h>

// LED includes and definitions
#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"

#define NUM_LEDS 2
#define DATA_PIN 27 // GPIO18
// Define the array of leds
CRGB leds[NUM_LEDS];


//EPD includes and definitions
// GxEPD lib and display drivers
#include <GxEPD.h>
#include <GxIO/GxIO.cpp>
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxGDEW0213Z16/GxGDEW0213Z16.cpp>  // 2.13" b/w/r
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>

// Those are from the board definition and don't need to be defined as they are standard for NINA
//static const uint8_t SS    = 5;  //GPIO28
//static const uint8_t MOSI  = 23; //GPIO1
//static const uint8_t MISO  = 19; // not used for waveshare display
//static const uint8_t SCK   = 18; // GPIO29

// Specific pins used on the MakeZurich badge, adjust if you are using the Display and the NINA standalone
static const uint8_t DC = 22;      //GPIO20
static const uint8_t RST = 21;     //GPIO8
static const uint8_t BUSYN = 4;    //GPIO24

// Runtime object instances for EPD
GxIO_Class io(SPI, SS, DC, RST); 
GxEPD_Class display(io, RST, BUSYN); 

// Create a holder for the texts to be displayed
// [0] Searching... or Network SSID if connected
// [1] Blank or RSSI if connected
// [2] Blank or IP if connected
// [3] Blank if connected or the reason if it gots disconected
String displayText[4];

// Wifi settings at Kraftwerk
const char* ssid     = "impacthub";
const char* password = "coworking@ImpactHub";


void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info)
{
    Serial.printf("[WiFi-event] event: %d\n", event);
    Serial.printf("Current RSSI=%d\n", WiFi.RSSI());
    switch (event)
    {
    case SYSTEM_EVENT_STA_GOT_IP:
        ledConnected();
        Serial.print("WiFi connected and got ");
        Serial.print("IP address: ");
        Serial.println(IPAddress(info.got_ip.ip_info.ip.addr));
        displayText[0] = ssid;
        // Set RSSI
        displayText[1] = WiFi.RSSI();
        // Set IP
        displayText[2] = WiFi.localIP().toString();
        showText();
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        ledError();
        Serial.print("WiFi lost connection. Reason: ");
        // Reasons found on https://www.esp32.com/viewtopic.php?t=349
        String disconnectReason;
        switch (info.disconnected.reason) {
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
        displayText[0] = "Disconnected";
        // Reset RSSI
        displayText[1] = "nc";
        // Reset IP
        displayText[2] = "0.0.0.0";
        // Set reason
        displayText[3] = disconnectReason;
        showText();
        break;
    }
}

void setup()
{
    Serial.begin(115200);
    // Initiate the display object
    display.init(115200); // enable diagnostic output on Serial
    
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

    // delete old config
    WiFi.disconnect(true);

    delay(1000); // let serial console settle
    Serial.println("\n\nKraftwerk wifi tester for MakeZurich 2018 badge");

    WiFi.onEvent(WiFiEvent);
    
    ledOff();
}

void loop()
{
    Serial.printf("Current RSSI=%d\n", WiFi.RSSI());
    displayText[1] = WiFi.RSSI();
    showText();
    if( WiFi.status() != WL_CONNECTED ) {
        // we are currently not connected, try connecting
        wifiStart();
    }
    delay(10000);
}

void wifiStart()
{
  unsigned long timer1 = millis();
  WiFi.begin(ssid, password);
    displayText[0] = "Searching...";
    // Reset RSSI
    displayText[1] = "nc";
    // Reset IP
    displayText[2] = "0.0.0.0";
    showText();
  while (WiFi.status() != WL_CONNECTED && millis() - timer1 < 5000UL) {
    ledSearching();
    Serial.print(".");
    ledSearching();
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(F(" CONNECTED"));
  }
  else {
    Serial.println(F("Could not connect!"));
  }
}

void ledOff() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  FastLED.show();
}

void ledConnected() {
  leds[0] = CRGB::Green;
  FastLED.show();
}

void ledError() {
  leds[0] = CRGB::Red;
  FastLED.show();
}

void ledSearching() {
  leds[1] = CRGB::Blue;
  FastLED.show();
  delay(200);
  leds[1] = CRGB::Black;
  FastLED.show();
  delay(200);
}

void showText() {
    // [0] Searching... or Network SSID if connected
    // [1] Blank or RSSI if connected
    // [2] Blank or IP if connected
    // [3] Blank if connected or the reason if it gots disconected
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&FreeMonoBold9pt7b);
  display.setRotation(3);
  display.setCursor(0, 0);
  display.println();
  display.print("SSID: ");
  display.println(displayText[0]);
  // IP
  display.print(displayText[2]);
  display.print(" RSSI: ");
  display.println(displayText[1]);
  // disconnect reason
  display.print("> ");
  display.println(displayText[3]);


  display.update();
  display.setRotation(0);
}