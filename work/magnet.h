#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

// Wiring PI Includes
#include <wiringPi.h>
#include <wiringPiSPI.h>

// SPI Definitions
#define LEN 28
int spiChan = 1;
int spiSpeed = 1000000;

// Buffer for SPI communication
unsigned char spiBuff[LEN];
unsigned char lastspiBuff[LEN];

// function declaration
int initSPI();
signed char magnetON(int ledChan, char ONPower);
signed char magnetOFF(int ledChan);

// debug funvlion
void printSPIBuff();


int initSPI(){
//Zaehlervariablen	
	int i;

// Init SPI Connection
	wiringPiSetupPhys();
	if( wiringPiSPISetup(spiChan, spiSpeed) == -1){
		printf("Coud not initialise SPI\n");
		return -1;}

// Set Pin State
//	pinMode(12, PWM_OUTPUT);
//	pullUpDnControl(12, PUD_OFF);
//	pwmWrite(12, 

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

signed char magnetOFF(int ledChan){
	int i;
//Eingabepruefung
	if(ledChan > 4)
		return -1;
	
	for(i=0;i<LEN;i++)
		spiBuff[i] = lastspiBuff[i];

	switch(ledChan) {
		case 1:	spiBuff[27] = 255;
						spiBuff[26] = 255;
						spiBuff[25] = 255;
						spiBuff[24] = 255;
						spiBuff[23] = 255;
						spiBuff[22] = 255;
						break;
	
		case 2:	spiBuff[21] = 255;
						spiBuff[20] = 255;
						spiBuff[19] = 255;
						spiBuff[18] = 255;
						spiBuff[17] = 255;
						spiBuff[16] = 255;
						break;
		
		case 3:	spiBuff[15] = 255;
						spiBuff[14] = 255;
						spiBuff[13] = 255;
						spiBuff[12] = 255;
						spiBuff[11] = 255;
						spiBuff[10] = 255;
						break;
	
		case 4:	spiBuff[9] = 255;
						spiBuff[8] = 255;
						spiBuff[7] = 255;
						spiBuff[6] = 255;
						spiBuff[5] = 255;
						spiBuff[4] = 255;
						break;
		default:	return -1; break;
	}
	
	for(i=0;i<LEN;i++)
		lastspiBuff[i] = spiBuff[i];

// Send Buffer over SPI
	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		printf("Error while Sending\n");

	return 0;
}

signed char magnetON(int ledChan, char ONPower){
	int i;
//Eingabepruefung
	if(ledChan > 4)
		return -1;

	for(i=0;i<LEN;i++)
		spiBuff[i] = lastspiBuff[i];


	switch(ledChan) {
		case 1:	spiBuff[27] = ONPower;
						spiBuff[26] = ONPower;
						spiBuff[25] = ONPower;
						spiBuff[24] = ONPower;
						spiBuff[23] = ONPower;
						spiBuff[22] = ONPower;
						break;
	
		case 2:	spiBuff[21] = ONPower;
						spiBuff[20] = ONPower;
						spiBuff[19] = ONPower;
						spiBuff[18] = ONPower;
						spiBuff[17] = ONPower;
						spiBuff[16] = ONPower;
						break;
		
		case 3:	spiBuff[15] = ONPower;
						spiBuff[14] = ONPower;
						spiBuff[13] = ONPower;
						spiBuff[12] = ONPower;
						spiBuff[11] = ONPower;
						spiBuff[10] = ONPower;
						break;
	
		case 4:	spiBuff[9] = ONPower;
						spiBuff[8] = ONPower;
						spiBuff[7] = ONPower;
						spiBuff[6] = ONPower;
						spiBuff[5] = ONPower;
						spiBuff[4] = ONPower;
						break;
		default:	return -1; break;
	}
	
	for(i=0;i<LEN;i++)
		lastspiBuff[i] = spiBuff[i];


// Send Buffer over SPI
	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		printf("Error while Sending\n");

	return 0;
}


void printSPIBuff(){
	int i=0;
	printf("\nInit: %x%x\n",spiBuff[0],spiBuff[1]);
	for(i=2;i<LEN;i++)
		printf("Buffer:%i %x\n",i,spiBuff[i]);
	return;
}
