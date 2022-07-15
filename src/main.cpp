

// Include the ESP32 Arduino Servo Library instead of the original Arduino Servo Library
#include <setup.h>
#include <servomethods.h>

void setup()
{
  initialise();
}

void loop()
{
  int newval = readInputVal();

  if (newval != oldval)
  {
    spinservo(newval);
    oldval = newval;
  }
  delay(50);
  if (resetWiFiManager)
  {
    resetWiFiManager = false;
    //server.reset();
    //server.end();
    wifiManager.resetSettings();
    ESP.restart();
  }
}
