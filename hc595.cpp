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

#include "hc595.h"

/**
 * Constructor
 *
 * Pass corresponding GPIO pins to this function.
 *    pSdi:   SDI - serial data input
 *    pRclk:  STCP - memory clock input
 *    pSrclk: SHCP - shift register clock input
 */
HC595::HC595(int pSdi, int pRclk, int pSrclk) {
	this->_pinSDI = pSdi;
	this->_pinRCLK = pRclk;
	this->_pinSRCLK = pSrclk;

	// Initialize pins
	pinMode(this->_pinSDI, OUTPUT);
	pinMode(this->_pinRCLK, OUTPUT);
	pinMode(this->_pinSRCLK, OUTPUT);

	// Set pins to low
	digitalWrite(this->_pinSDI, 0);
	digitalWrite(this->_pinRCLK, 0);
	digitalWrite(this->_pinSRCLK, 0);

	// Clear on init
	this->Clear();
}


/**
 * Fetch given number of bits and optionally store them (which you normally would do)
 *
 * Parameters:
 *   dat: The data to insert
 *   size: Determines how many bits to insert
 *   write: Optional, determines if inserted bits should be written to the chip.
 *          If omitted the method Write() has to be called manually.
 */
void HC595::Shift(unsigned char dat, unsigned char size, unsigned char write) {
  int i = 0;

  if( size > 0 ) {
    for(i=0; i<size; i++) {
      digitalWrite(this->_pinSDI, 0x80 & (dat << i));
      this->_step();
    }

    if( write == 1 ) {
      this->Write();
    }
  }
}


/**
 * Clear the 74HC595
 *
 * Parameter size determines how many bits to clear. Default is 8, if no size is given.
 */
void HC595::Clear(unsigned char size) {
  int i = 0;

  if( size > 0 ) {
    for(i=0; i<size; i++) {
      digitalWrite(this->_pinSDI, 0x80 & (0 << i));
      this->_step();
    }

    this->Write();
  }
}


/**
 * Write stored bits to chip
 */
void HC595::Write() {
  digitalWrite(this->_pinRCLK, 1);
  delay(1);
  digitalWrite(this->_pinRCLK, 0);
}


/*
 * ---- PRIVATE -----
 */


/**
 * Go to next bit.
 * This function has to be called, after bit set in the 74HC595 via Shift() method
 */
void HC595::_step() {
  digitalWrite(this->_pinSRCLK, 1);
  delay(1);
  digitalWrite(this->_pinSRCLK, 0);
}
