# SNx4HC595 C++ library
Simple C++ library for controlling a SNx4HC595 shift register via the wiringPi library
The code is written for usage on the RaspberryPi, but it should be easy to port it to the Arduino.

This library provides functionality to act with a SNx4HC595 chip (e.g. SN74HC595).
Any chip of the series should work.

SNx4HC595 data sheet: <a href="https://www.sparkfun.com/datasheets/IC/SN74HC595.pdf" target="_blank">https://www.sparkfun.com/datasheets/IC/SN74HC595.pdf</a>

## Requirements
* wiringPi library (<a href="http://wiringpi.com/" target="_blank">http://wiringpi.com/</a>)
* C++ compiler

## Tested chips
* SN74HC595

## Installation
Copy the hc595.h and hc595.cpp to your desired destination (most likely your header/source file folder) and include them.

## Usage example

```c++
#include "hc595/hc595.h"

int main(int argc, char **argv) {
  HC595 *hc595 = new HC595(PIN_SDI, PIN_RCLK, PIN_SRCLK);
  hc595->Shift(1, 8, 1);
  hc595->Clear();
  
  return 0;
}
```
See the example.cpp for a full example - the library is quite easy to use.

