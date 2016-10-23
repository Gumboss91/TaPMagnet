/* Function File for TLC59711
 * 12-Channel 16-Bit PWM Driver Chip
 * communication over SPI using wiringPi
 * Adafruit LED Driver SPI Board
 */

#include "PWM_TLC59711.h"

int spiChan = 1;
int spiSpeed = 1000000;



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
		spiBuff[i] = 0x00;

	for(i=0;i<LEN;i++)
		lastSpiBuff[i] = spiBuff[i];

	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		return -1;

	return 0;
}

signed char setChannel(int channel, int pwmVal){
	int i = 0;

	if(channel >= 12 || channel > 0)
		return -2;
	
	if(pwmVal > 65536 || pwmVal < 0)
		return -2;

	for(i=0;i<LEN;i++)
		spiBuff[i] = lastSpiBuff[i];

	spiBuff[channel*2 + 5] = pwmVal>>8;
	spiBuff[channel*2 + 4] = pwmVal;
	
	for(i=0;i<LEN;i++)
		lastSpiBuff[i] = spiBuff[i];

	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		return -1;

	return 0;

}

signed char clearAll(){
	int i = 0;
	
	for(i=0;i<LEN;i++)
		spiBuff[i] = lastSpiBuff[i];
	
	for(i=4;i<LEN;i++)
		spiBuff[i]=0x0;
	
	for(i=0;i<LEN;i++)
		lastSpiBuff[i] = spiBuff[i];

	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		return -1;

	return 0;
}

signed char setAllChan(int pwmVal){
	int i = 0;
	
	if(pwmVal > 0xFFFF || pwmVal < 0)
		return -2;
	
	for(i=0;i<LEN;i++)
		spiBuff[i] = lastSpiBuff[i];

	for(i=0;i<12;i++){
		spiBuff[i*2+5]=pwmVal>>8;
		spiBuff[i*2+4]=(char)pwmVal;
	}

	for(i=0;i<LEN;i++)
			lastSpiBuff[i] = spiBuff[i];

	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		return -1;

	return 0;
}

signed char fullON(){
 	int i = 0;
	
	for(i=0;i<LEN;i++)
			spiBuff[i] = lastSpiBuff[i];

	for(i=4;i<LEN;i++)
		spiBuff[i]=0xFF;
	
	for(i=0;i<LEN;i++)
			lastSpiBuff[i] = spiBuff[i];

	if(wiringPiSPIDataRW(spiChan, spiBuff, LEN) == -1)
		return -1;

	return 0;
}
void printSPIBuff(){
	int i=0;
	printf("\nInit: %x%x\n",lastSpiBuff[0],lastSpiBuff[1]);
	for(i=2;i<LEN;i++)
		printf("Buffer Send/Recive:%i %x/%x\n",i,spiBuff[i],lastSpiBuff[i]);
	return;
}

