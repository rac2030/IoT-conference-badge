//This is the place to declare every single function
//and global variable that is going to be reused between cpp files.

#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>  // 2.13" b/w/r

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

// Status request objects
extern StatusRequest updateDisplay;

// Tasks for enable / disable created in main.cpp
extern Task tInitialize;
extern Task tUpdateDisplay;

// Show view tasks created in main.cpp
extern Task tQRView;
extern Task tNameView;
extern Task tSplashView;

// Methods that can be globally called
//// taskDisplay.cpp
extern void PrepareUpdateDisplayStatus();
extern void handleUpdateDisplay();
//// taskInit.cpp
extern void initBadge();
//// taskQRInit.cpp
extern void handleQRView();
//// taskNameView.cpp
extern void handleNameView();
//// taskSplash.cpp
extern void handleSplashView();

// Global variables
//// taskInit.cpp
extern String firstName;
extern String lastName;
extern String efuseMac;

// Namespace of preferences
#define PREF_TAG "mz18badge" 

// Preference keys
#define PREF_FIRSTNAME "firstName"
#define PREF_LASTNAME "lastName"

