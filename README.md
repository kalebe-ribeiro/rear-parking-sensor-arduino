My first time publishing a project. This is a rear parking sensor made with an arduino. I'll be covering mostly the software side of the project.
It was made using an Arduino Uno R3, on TinkerCad
The components are:
- Ultrasonic Distance Sensor (4 pins)
- Piezo (Buzzer)
- 3 LEDs (Red, Yellow and Green)
- 3 Resistors
- Breadboard
- Arduino Uno R3

The software will work by processing the data captured by the distance sensor (microseconds),
and calculating the distance using the following formula: d = (t/s)/2.

After that, the LEDs and the buzzer will be set up to activate when determined conditions come true.
For example, set the red LED to turn on when the distance is to close, as well as set the buzzer to quickly turn on and off.
