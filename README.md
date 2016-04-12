# SNx4HC595 C++ library
Simple C++ library for controlling a SNx4HC595 shift register via the wiringPi library
The code is written for usage on the RaspberryPi, but it should be easy to port it to the Arduino.

This library provides functionality to act with a SNx4HC595 chip (e.g. SN74HC595).
Any chip of the series should work.

## Requirements
* wiringPi library
* C++ compiler

## Tested chips
* SN74HC595

## Installation
Add the hc595 directory to your source files and include the hc595.h file.

## Usage example

```c++
#include "hc595.h"

hc595 = new HC595(PIN_SDI, PIN_RCLK, PIN_SRCLK);
hc595->Shift(1, 8, 1);
hc595->Clear();
```
See the example.cpp for a full example - the library is quite easy.

## Links
SNx4HC595 data sheet: https://www.sparkfun.com/datasheets/IC/SN74HC595.pdf

More information about wiringPi: http://wiringpi.com/
