#include <setupheader.h>

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
    myservo.setPeriodHertz(50); // Standard 50hz servo
}

