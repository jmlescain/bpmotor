# bpmotor
## __[Arduino Uno] Battery-powered Stepper Motor with Obstacle Detection and Capacitive Touch Controls__

### Summary

This Arduino Uno project is a stepper motor controller. It also features an obstacle detector using an infrared(IR) sensor. To control the speed of the motor, capacitive touch sensors are used.

Stepper motors are used in applications where precision is a priority (e.g. 3D printers, electronics assembly, etc). In this project, a 28BYJ-48 - 5V Stepper Motor is used. For convenience, motor control is provided by the Arduino Stepper Library. The motor is driven with a ULN2003 driver module board.

Capacitive touch sensors can provide advantage over mechanical buttons because of the lack of moving parts. Wear and tear can render the buttons damaged over time. Touch sensors do not have protruding parts, allowing the device to have a sleeker look. 

Obstacle detection is important especially in systems that contains moving parts or if the system itself, as a whole, moves. Obstacles can damage the sensors, actuators, the device itself, and/or the user themselves. The reflective and invinsible nature of infrared light is great for obstacle detection.

Due to the system being battery powered, it is also important to have a sensing mechanism for the battery level. Overtime as the battery discharges, its voltage output diminishes. With the Arduino Uno's ADC, we can make a battery level sensor.

The stepper motor's speed is controlled using the capacitive touch input, with the current _rpm_ and _motor steps_ displayed on the LCD. If any obstacle is present, the motor will stop and a message will be displayed on the LCD accordingly.


Inputs:
* Battery Level
  * To detect the on-board battery level
* Capacitive Sensor
  * To change speed of the motor
* IR Obstruction Sensor
  * To stop motor in case of obstruction

Outputs:
* Stepper Motor
  * Movement Output
* LCD
  * Shows if:
    * There is obstruction.
    * Motor speed in _rpm_.
    * Touch control feedback.
* (Optional) Buzzer
  * For audio feedback.