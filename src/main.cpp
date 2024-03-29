/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald

 modified for the ESP32 on March 2017
 by John Bennett

 see  http://www.arduino.cc/en/Tutorial/Knob for a description of the original code

 * Different servos require different pulse widths to vary servo angle, but the range is
 * an approximately 500-2500 microsecond pulse every 20ms (50Hz). In general, hobbyist servos
 * sweep 180 degrees, so the lowest number in the published range for a particular servo
 * represents an angle of 0 degrees, the middle of the range represents 90 degrees, and the top
 * of the range represents 180 degrees. So for example, if the range is 1000us to 2000us,
 * 1000us would equal an angle of 0, 1500us would equal 90 degrees, and 2000us would equal 1800
 * degrees.
 *
 * Circuit: (using an ESP32 Thing from Sparkfun)
 * Servo motors have three wires: power, ground, and signal. The power wire is typically red,
 * the ground wire is typically black or brown, and the signal wire is typically yellow,
 * orange or white. Since the ESP32 can supply limited current at only 3.3V, and servos draw
 * considerable power, we will connect servo power to the VBat pin of the ESP32 (located
 * near the USB connector). THIS IS ONLY APPROPRIATE FOR SMALL SERVOS.
 *
 * We could also connect servo power to a separate external
 * power source (as long as we connect all of the grounds (ESP32, servo, and external power).
 * In this example, we just connect ESP32 ground to servo ground. The servo signal pins
 * connect to any available GPIO pins on the ESP32 (in this example, we use pin 18.
 *
 * In this example, we assume a Tower Pro SG90 small servo connected to VBat.
 * The published min and max for this servo are 500 and 2400, respectively.
 * These values actually drive the servos a little past 0 and 180, so
 * if you are particular, adjust the min and max values to match your needs.
 */

// Include the ESP32 Arduino Servo Library instead of the original Arduino Servo Library
#include <ESP32Servo.h>
#include <setup.h>



void setup()
{
 initialise();
}

int getMappedValue(){
  return map(val, 0, 2000, 0, 180);
}

void loop()
{

  int val = readInputVal();
  //val = analogRead(potPin);       // reads the value of the potentiometer (value between 0 and 1023)
  //mappedval = map(val, 0, 1023, 0, 80); // scale it to use it with the servo (value between 0 and 180)
    Serial.println("val");

  Serial.println(val);
    Serial.println("mapped");
  Serial.println(getMappedValue());

  myservo.write(getMappedValue());
  

  //Serial.println(val); // sets the servo position according to the scaled value
  delay(1000);         // waits for the servo to get there
}







