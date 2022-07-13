

// Include the ESP32 Arduino Servo Library instead of the original Arduino Servo Library
#include <ESP32Servo.h>
#include <setup.h>
Endpoints endpoints(0,0);
void setup()
{
  initialise(endpoints);
  
}

int getMappedValue(int newval)
{
  return map(
    newval  //the value that we want to 'map'
  , 0       //the low end of the current scale
  , 100     //the high end of the current scale
  , 0       //the low end of the scale we want to map our value to
  , 180     //the high end of the scale we want to map our value to
  );
}
void spinservo()
{
  myservo.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object
                                          // using SG90 servo min/max of 500us and 2400us
                                          // for MG995 large servo, use 1000us and 2000us,
                                          // which are the defaults, so this line could be
                                          // "myservo.attach(servoPin);"
  Serial.println("mapped");
  int val = endpoints.getNewVal();
  Serial.println(getMappedValue(val));
  myservo.write(getMappedValue(val));
  delay(1000);
  myservo.detach();//detach the servo once we have run it to the value. stops it humming.
}

void loop()
{
  int newval = endpoints.getNewVal();


  //Serial.println("newval ");Serial.print(newval);
  

  //Serial.println("oldval ");Serial.print(oldval);
  

  if (newval != endpoints.getOldVal())
  {
    //Serial.println("Value changed, rotating servo.");
    spinservo();
    endpoints.setOldVal(newval);
  }
  delay(50);
  // Serial.println(val); // sets the servo position according to the scaled value
}
