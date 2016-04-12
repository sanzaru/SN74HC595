/**
 * Library for controlling a SNx4HC595 shift register via the wiringPi library
 *
 * Author: Martin Albrecht <martin.albrecht@javacoffee.de>
 *
 * The code is written for usage on the RaspberryPi, but it should
 * be easy to port it to the Arduino.
 *
 * This class provides functionality to act with a SNx4HC595 chip
 * Every chip of the series should work.
 *
 * Tested chips:
 *     SN74HC595
 *
 * SNx4HC595 data sheet:
 *   https://www.sparkfun.com/datasheets/IC/SN74HC595.pdf
 *
 * More information about wiringPi:
 *   http://wiringpi.com/
 *
 * ------------------------------------------------------------------------------
 * License:
 * --------
 *
 * The MIT License (MIT)
 * Copyright (c) 2016 Martin Albrecht <martin.albrecht@javacoffee.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * ------------------------------------------------------------------------------
 */

#ifndef __HC595_H__
#define __HC595_H__

#include <wiringPi.h>

class HC595 {
	private:
		int _pinSDI,	// serial data input (SDI)
			_pinRCLK,	// memory clock input (STCP)
			_pinSRCLK;  // shift register clock input (SHCP)

		void _step();


	public:
		HC595(int, int, int);
		void Shift(unsigned char dat, unsigned char size, unsigned char write);
		void Clear(unsigned char size = 8);
		void Write();
};

#endif
