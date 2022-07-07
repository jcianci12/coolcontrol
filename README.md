# coolcontrol

The goal of this project is to allow the user to retrofit a standard circular hvac vent with an ESP32 powered servo and control the vent.

This project makes use of WiFi.h to allow easy wifi connection using the ESPTouch app.

1. Flash the board using PlatformIO
Connect the board to the servo using 

5v => servo red wire
gnd => servo brown wire
pin 18 => servo orange wire

2. Connect the board to wifi using the ESPTouch app.
Navigate to the IP address of the board on your wifi.

Drag the slider around to monitor the output.
