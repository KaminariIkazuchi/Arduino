# Mini Proximity Sensor

That's my first project on Arduino, a mini proximity sensor that turns a led on when an object is close to ten centimeters from the ultrasonic sensor.

This project will have some improvements in the future.

## Getting Started

This shows you what you need to make this little project. 

### Prerequisites

* [Arduino Software](https://www.arduino.cc/en/Main/Software)
* Arduino MEGA 2560 (it's recommanded to begin with Arduino)
* USB cable Type-A to Type-B (often called printer cable)
* 1 mini breadboard
* 6 wires
* 1 green LED
* 1 resistance
* 1 ultrasonic sensor HC-SR04

### Installing

You just need to install the Arduino Software

### How to use the Arduino

Take a look to the [Arduino Getting Started](https://www.arduino.cc/en/Guide/ArduinoMega2560), if you don't want to, the steps are written below.

First, you have to launch the Arduino software and connect the Arduino to the computer using the USB A/B cable and atfer that you have to make sure that you selected the right board.
```
Tools ---> Board: Arduino/Genuino Mega or Mega 2560
```
Then, you need to know if it's recoginzed by the computer.
```
Tools ---> Port ---> COMx Arduino/Genuino Mega or Mega 2560
```
You may want to test the Arduino. We'll test it by blinking the built-in **L** LED (pin 13). Open the blink example.
```
Example ---> 01.Basics ---> Blink
```
Finally, you have to upload the data to the Arduino, by clicking the arrow button.

<img src="upload_arduino.PNG" />

The uploading is done when you see "Done uploading".
If the LED start blinking in orange you are ready to test other programs.

To stop the program just create a program which only contains the functions **setup()** and **loop()** and upload it to the Arduino.

## Mini Proximity Sensor

Open mini_proximity_sensor.ino.

### Setup the Arduino

Just Follow the branchings below.

<img src="mini_proximity_sensor_sketch.png" align="left" />

### Enjoy!

Upload the program to the Arduino and test it by approaching an object near the sensor.
If you want to modify the distance to light up the LED go to
```C++
void led(float distance)
{
  if (distance <= 10)
    digitalWrite(led_green, HIGH);
  else
    digitalWrite(led_green, LOW);
}
```
and modify the **10** by any value you want.

Thank for reading this readme.
