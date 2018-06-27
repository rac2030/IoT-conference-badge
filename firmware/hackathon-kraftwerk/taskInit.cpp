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

void initBadge()
{
    Serial.println("Initialize badge - Home");

    // Get the chip id, this is used all over the place
    getEfuseMac();

    // Get the name if already registered or display the QR code otherwise
    preferences.begin(PREF_TAG, true); // Read only
    // Check if name is already set, we only check if first name has a value here
    firstName = preferences.getString(PREF_FIRSTNAME, "Unknown");
    lastName = preferences.getString(PREF_LASTNAME, "Hacker");
    if (firstName == "Unknown")
    {
        // Name is not yet set, enable the display of the QR init screen until this has been set
        // Display MZ Logo as splash screen
        displaySplash.signal();
        delay(3000); // Wait for 3 seconds before continuing writing next display
        displayQRView.signal();
        Serial.println("Badge not yet registered, try to fetch registration");
        tFetchRegistration.enable();
    }
    else
    {
        // Name is set, display the Name Tag screen accordingly
        // Signal the name view to be shown
        displayNameView.signal();
        Serial.print("Name set is: ");
        Serial.print(firstName);
        Serial.print("");
        Serial.println(lastName);
    }
    preferences.end();
}

/**
 * Get the chip ID
 * TODO: Make it lean and less memory hungry
 */
void getEfuseMac()
{
    uint64_t id = ESP.getEfuseMac();
    char id_h[9];
    char id_l[9];

    sprintf(id_h, "%08X", (uint32_t)(id >> 32));
    sprintf(id_l, "%08X", (uint32_t)(id));

    efuseMac = String(id_h) + String(id_l);
}