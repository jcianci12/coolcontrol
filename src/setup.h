#include <ESP32Servo.h>
// #include "WiFi.h"
//#include <servoFunctions.h>
//#include <endpoints.h>
#include <endpoints.h>
#include <servomethods.h>


void initialise()
{

    Serial.begin(115200);
    
    //initEndpoints();

    initWIFI();

    Serial.println("");

    initservo();
    // Allow allocation of all timers
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
}
