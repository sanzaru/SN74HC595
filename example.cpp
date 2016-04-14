/**
 * Example for the SNx4HC595 C++ library
 */
#include <iostream>
#include <math.h>
#include <wiringPi.h>
#include "hc595.h"

/*
 * Some example pin definition
 * You should edit this according to the pins you use
 * NOTE: Don't use BCM notation!! This is in wiringPi notation.
 * 		 wPI #0 -> BCM #17
 *		 wPi #1 -> BCM #18
 *       ...
 */
#define PIN_SDI   1
#define PIN_RCLK  2
#define PIN_SRCLK 3

using namespace std;

int main(int argc, char **argv) {
	HC595 *hc595;
	int i;

	cout << "Starting SNx4HC595 example..." << endl;

	// Initialize 74HC595 shift register class
	hc595 = new HC595(PIN_SDI, PIN_RCLK, PIN_SRCLK);

	// Clear the register
	hc595->Clear();

	// Set all 8 bits one by one every second.
	// Connect your output pins of the shift register to see the result
	// (e.g. connect a led to each pin)
	for(i=1; i<=8; i++) {
		cout << "Setting bit #" << i << endl;
		hc595->Shift(pow(2, i), 8, 1);
		delay(1000);
	}

	cout << "All done!" << endl;
}
