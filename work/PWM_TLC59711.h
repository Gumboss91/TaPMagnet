/* Header File for TLC59711
 * 12-Channel 16-Bit PWM Driver Chip
 * communication over SPI using wiringPi
 * Adafruit LED Driver SPI Board
 */

#include <stdio.h>
#include <stdlib.h>

// Wiring PI Includes
#include <wiringPi.h>
#include <wiringPiSPI.h>

// SPI Definitions
#define LEN 28
int spiChan = 1;
int spiSpeed = 1000000;

// Buffer for SPI communication
unsigned char spiBuff[LEN];
unsigned char lastSpiBuff[LEN];

// functions
signed char initSPI();
signed char setChannel(int channel, int pwmVal);
signed char clearAll();
signed char setAllChan(int pwmVal);
signed char fullON();

// debug functions 
void printSPIBuff();

/* According to the Datasheet
 * and the nummeration on the Adafruit board
 * the channel numbering is
 * 
 * Name = Channel
 * R0 = 0
 * G0 = 1
 * B0 = 2
 * R1 = 4
 * G0 = 5
 * ...
 * G3 = 10
 * B3 = 11
 * 
 * pwm Value can be 0 to 65536 (16 bit Integer)
 */