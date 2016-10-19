/* Function File for TLC59711
 * 12-Channel 16-Bit PWM Driver Chip
 * communication over SPI using wiringPi
 * Adafruit LED Driver SPI Board
 */

#include <PWM_TLC59711.h>

signed char initSPI(){
//Zaehlervariablen	
	int i;

// Init SPI Connection
	wiringPiSetupPhys();
	if( wiringPiSPISetup(spiChan, spiSpeed) == -1){
		printf("Coud not initialise SPI\n");
		return -1;}

// definieren des Initialvectors
	// Erstes Byte des Buffers 
	spiBuff[0] = 0x96;
	spiBuff[1] = 0xdf;
	spiBuff[2] = 0xff;
	spiBuff[3] = 0xff;

	// Restlicher Buffer
	for(i=4;i<LEN;i++)
		spiBuff[i] = 0xff;

	for(i=0;i<LEN;i++)
		lastspiBuff[i] = spiBuff[i];

	return;
}

signed char setChannel(int channel, int pwmVal);
signed char clearAll();
signed char setAllChan(int pwmVal);
signed char fullON();
 
void printSPIBuff();

