#include <Arduino.h>
#include "taskheader.hpp"

#include <Preferences.h>

Preferences preferences;

// Global variables exposed in taskheader
String firstName;
String lastName;
String efuseMac;

// Callback method prototypes
void initBadge();

// helper prototypes
void getEfuseMac();

#define DUMMY
void initBadge() {
    PrepareUpdateDisplayStatus();
    Serial.println("Initialize badge");
    // Display MZ Logo as splash screen
    tSplashView.enable();
    delay(5000); // Wait for 5 seconds before continuing writing next display

    // Get the chip id, this is used all over the place
    getEfuseMac();
    
    #ifdef DUMMY
        firstName = "Ding";
        lastName = "Dong";
        tNameView.enable();
        Serial.println("Dummy name is set");
    #else
        // Get the name if already registered or display the QR code otherwise
        preferences.begin(PREF_TAG, true); // Read only
        // Check if name is already set, we only check if first name has a value here
        if(preferences.getString(PREF_FIRSTNAME, "") == "") {
            // Name is not yet set, enable the display of the QR init screen until this has been set
            tQRView.enable();
            Serial.println("Badge not yet registered");
        } else {
            // Name is set, get it and display the Name Tag screen accordingly
            firstName = preferences.getString(PREF_FIRSTNAME, "");
            lastName = preferences.getString(PREF_LASTNAME, "");
            // Signal the name view to be shown
            tNameView.enable();
            Serial.print("Name set is: ");
            Serial.print(firstName);
            Serial.print("");
            Serial.println(lastName);
        }
        preferences.end();
    #endif
}

/**
 * Get the chip ID
 * TODO: Make it lean and less memory hungry
 */
void getEfuseMac() {
  uint64_t id = ESP.getEfuseMac();
  char id_h[9];
  char id_l[9];

  sprintf(id_h, "%08X", (uint32_t)(id>>32));
  sprintf(id_l, "%08X", (uint32_t)(id));

  efuseMac = String(id_h) + String(id_l);
}