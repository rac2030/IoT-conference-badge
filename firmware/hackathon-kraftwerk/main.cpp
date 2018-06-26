//Header that declares all shared objects between .cpp files
#include "taskheader.hpp"
#include <Arduino.h> //for Serial and delay
#include <esp_wifi.h>
#include <esp_bt.h>

Scheduler runner, runnerPriority; 

// Tasks
// TODO: Should work if they are in their own file as it works in the simple example... for now they stay here as this works
Task tInitialize(200, TASK_ONCE, &initBadge, &runnerPriority);
Task tQRView(100, TASK_ONCE, &handleQRView, &runner);
Task tNameView(100, TASK_ONCE, &handleNameView, &runner);
Task tUpdateDisplay(&handleUpdateDisplay, &runner);
Task tSplashView(100, TASK_ONCE, &handleSplashView, &runnerPriority);
Task tFetchRegistration(100, TASK_ONCE, &handleFetchRegistration, &runner);

void setup () {
    // Disable networking parts to save energy until we really need it
    esp_wifi_stop();
    esp_bt_controller_disable();

    Serial.begin(115200);
    // Initiate the display object
    display.init(115200); // enable diagnostic output on Serial
  
    Serial.println("MakeZurich Badge Firmware v0.0.2");

    runner.setHighPriorityScheduler(&runnerPriority);
    
    tInitialize.enable();
    runner.startNow();  // set point-in-time for scheduling start
}


void loop () {
  runner.execute();
}

void PrepareUpdateDisplayStatus() {
    Serial.println("Set display to wait for update signal");
  updateDisplay.setWaiting();         // set the status request object for waiting 
  tUpdateDisplay.waitFor(&updateDisplay); //request tasks tUpdateDisplay to wait on the object updateDisplay signal
}