
// Include the ESP32 Arduino Servo Library instead of the original Arduino Servo Library
#include <ESP32Servo.h>
#ifndef SERVOMETHODS
#define SERVOMETHODS
// Possible PWM GPIO pins on the ESP32: 0(used by on-board button),2,4,5(used by on-board LED),12-19,21-23,25-27,32-33
int servoPin = 18; // GPIO pin used to connect the servo control (digital out)
Servo myservo;     // create servo object to control a servo

int getMappedValue(int val)
{
    return map(
        val // the value that we want to 'map'
        ,
        0 // the low end of the current scale
        ,
        100 // the high end of the current scale
        ,
        0 // the low end of the scale we want to map our value to
        ,
        180 // the high end of the scale we want to map our value to
    );
}
void spinservo(int val)
{
    myservo.attach(18, 500, 2400); // attaches the servo on pin 18 to the servo object
                                   // using SG90 servo min/max of 500us and 2400us
                                   // for MG995 large servo, use 1000us and 2000us,
                                   // which are the defaults, so this line could be
                                   // "myservo.attach(servoPin);"
    Serial.println("mapped");
    Serial.println(getMappedValue(val));
    myservo.write(getMappedValue(val));
    delay(1000);
    myservo.detach(); // detach the servo once we have run it to the value. stops it humming.
}
void initservo()
{
    myservo.setPeriodHertz(50); // Standard 50hz servo
}
#endif