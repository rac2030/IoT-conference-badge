#define SerialDebug true  // set to true to get Serial output for debugging

//This is the place to declare every single function
//and global variable that is going to be reused between cpp files.

#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r

#include <Preferences.h>

#include <WiFiType.h>
#include <WiFi.h>

//We are going to use the TaskScheduler, but only the declarations part.
//Remember to put customization macros before the #include:
#define _TASK_SLEEP_ON_IDLE_RUN
#define _TASK_STATUS_REQUEST
#define _TASK_PRIORITY
#include <TaskSchedulerDeclarations.h>

//Let the runner object be a global, single instance shared between object files.
extern Scheduler runner, runnerPriority;
// Global access to display, just use it to fill the buffer then signal that it will be drawn
extern GxEPD_Class display;

extern Preferences preferences;

// Status request objects
extern StatusRequest updateDisplay;
extern StatusRequest btn1Pressed;
extern StatusRequest btn2Pressed;
extern StatusRequest btn3Pressed;
extern StatusRequest btn4Pressed;
extern StatusRequest displaySplash;
extern StatusRequest displayNameView;
extern StatusRequest displaySensorView;
extern StatusRequest displayQRView;
extern StatusRequest fetchRegistration;
extern StatusRequest triggerAquireSensorData;

// Tasks for enable / disable created in main.cpp
extern Task tInitialize;
extern Task tUpdateDisplay;
extern Task tFetchRegistration;

// Show view tasks created in main.cpp
extern Task tQRView;
extern Task tNameView;
extern Task tSplashView;
extern Task tSensorView;
extern Task tAquireSensorData;
extern Task tPushSensorData;
extern Task tSensorViewRefresh;
extern Task tTriggerAquireSensorView;

// Button tasks
extern Task tBTN1;
extern Task tBTN2;
extern Task tBTN3;
extern Task tBTN4;

// Methods that can be globally called
//// taskDisplay.cpp
extern void prepareUpdateDisplayStatus();
extern void handleUpdateDisplay();
//// taskInit.cpp
extern void initBadge();
//// taskQRInit.cpp
extern void handleQRView();
//// taskNameView.cpp
extern void handleNameView();
extern char* string2char(String command);
//// taskSensorView.cpp
extern void handleSensorView();
extern void setSensorViewRefresh(boolean state);
//// taskSplash.cpp
extern void handleSplashView();
//// taskFetchRegistration.cpp
extern void handleFetchRegistration();
extern void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info);
//// taskButtons.cpp
extern void handleBTN1();
extern void handleBTN2();
extern void handleBTN3();
extern void handleBTN4();
//// taskFetchRegistration.cpp
extern void handleFetchRegistration();
//// taskAquireSensorData.cpp
extern void handleAquireSensorData();
//// taskPushSensorData.cpp
extern void handlePushSensorData();

// Global variables
//// taskInit.cpp
extern String firstName;
extern String lastName;
extern String efuseMac;
// taskAquireSensorData.cpp
extern float temp;
extern float rh;
extern float tvoc;

// Namespace of preferences
#define PREF_TAG "mz18badge" 

// Preference keys
#define PREF_FIRSTNAME "firstName"
#define PREF_LASTNAME "lastName"

