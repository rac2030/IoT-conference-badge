#include <Arduino.h>
#include "taskheader.hpp"

// Status request objects
StatusRequest btn1Pressed;
StatusRequest btn2Pressed;
StatusRequest btn3Pressed;
StatusRequest btn4Pressed;

// Handlers
void handleBTN1()
{
    Serial.println("BTN1: Undefined");
    //TODO: handle
    btn1Pressed.setWaiting();
    tBTN1.waitFor(&btn1Pressed);
}

void handleBTN2()
{
    // Should always go to home screen
    // As a quick hack implementation, just redo the init
    Serial.println("BTN2: Go to home screen, display name view");
    displayNameView.signal();
    btn2Pressed.setWaiting();
    tBTN2.waitFor(&btn2Pressed);
}

void handleBTN3()
{
    Serial.println("BTN3: Show MakeZurich Logo");
    // Display MZ Logo as splash screen
    displaySplash.signal();
    
    btn3Pressed.setWaiting();
    tBTN3.waitFor(&btn3Pressed);
}

void handleBTN4()
{
    Serial.println("BTN4: Show sensor data");
    displaySensorView.signal();
    
    btn4Pressed.setWaiting();
    tBTN4.waitFor(&btn4Pressed);
}
