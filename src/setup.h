#include <ESP32Servo.h>
// #include "WiFi.h"
//#include <servoFunctions.h>
#include <endpoints.h>
#include <wifisetupmanager.h>



// Possible PWM GPIO pins on the ESP32: 0(used by on-board button),2,4,5(used by on-board LED),12-19,21-23,25-27,32-33
int servoPin = 18; // GPIO pin used to connect the servo control (digital out)
// Possible ADC pins on the ESP32: 0,2,4,12-15,32-39; 34-39 are recommended for analog input
int potPin = 34;    // GPIO pin used to connect the potentiometer (analog in)
int ADC_Max = 4096; // This is the default ADC max value on the ESP32 (12 bit ADC width);
                    // this width can be set (in low-level oode) from 9-12 bits, for a
                    // a range of max values of 512-4096




void initialise()
{

    Serial.begin(115200);

    initWIFI();

    Serial.println("");
 

    initEndpoints();

    // Allow allocation of all timers
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    myservo.setPeriodHertz(50);           // Standard 50hz servo
    myservo.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object
                                          // using SG90 servo min/max of 500us and 2400us
                                          // for MG995 large servo, use 1000us and 2000us,
                                          // which are the defaults, so this line could be
                                          // "myservo.attach(servoPin);"
    

}
