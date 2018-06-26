//Header that declares all shared objects between .cpp files
#include "taskheader.hpp"
#include <Arduino.h> //for Serial and delay

Scheduler runner, runnerPriority; 

//Pretend, that the t2 task is a special task,
//that needs to live in file2 object file.
void t2Callback() {
    Serial.print("Only task that starts... :-/ why? ");
    Serial.println(millis());
}
Task t2(100, TASK_ONCE, &t2Callback, &runner, true);

// Tasks
// TODO: Should work iof they are in their own file as it works in the simple example...
Task tInitialize(200, TASK_ONCE, &initBadge, &runnerPriority);
Task tQRView(100, TASK_ONCE, &handleQRView, &runner);
Task tNameView(100, TASK_ONCE, &handleNameView, &runner);
Task tUpdateDisplay(&handleUpdateDisplay, &runner);
Task tSplashView(100, TASK_ONCE, &handleSplashView, &runnerPriority);

void setup () {
    Serial.begin(115200);
    // Initiate the display object
    display.init(115200); // enable diagnostic output on Serial
  
    Serial.println("MakeZurich Badge Firmware v0.0.1");

    delay(1000);
    
    runner.setHighPriorityScheduler(&runnerPriority);
    
    // Enable the display signal
    //PrepareUpdateDisplayStatus();
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