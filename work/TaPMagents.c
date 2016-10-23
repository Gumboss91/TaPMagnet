#include "TaPMagnets.h"

char invert = 0;
signed char magnetInit(int inv=0){
	
	if(inv > 1 || inv < 0)
		return -2;

	invert = inv;
	
	if(spiInit() != 0)
		return -1;


	return 0;
}

signed char magnetOFF(int magChan){
	if(magChan > 4 || magChan < 1)
		return -2;
	
	if(invert)
		pwmVal = 0xFFFF;
	else
		pwmVal = 0x0000;
	
	if(setChannel(i*3, pwmVal) != 0)
		return -1;
	
	if(setChannel(i*3+1, pwmVal) != 0)
		return -1;
	
	if(setChannel(i*3+2, pwmVal) != 0)
		return -1;

	return 0;
}

signed char setMagnetON(int magChan, char dutyCycle){
	int pwmVal;

	if(magChan > 4 || magChan < 1)
		return -2;
	
	if(dutyCycle > 100 || dutyCycle < 0)
		return -2
	
	if(invert)
		pwmVal = 100-dutyCycle;

	pwmVal = 0xFFFF/dutyCycle*100;
	

	if(invert)
		pwmVal = 0x0000;
	
	if(setChannel(i*3, pwmVal) != 0)
		return -1;
	
	if(setChannel(i*3+1, pwmVal) != 0)
		return -1;
	
	if(setChannel(i*3+2, pwmVal) != 0)
		return -1;


	return 0;
}

signed char magnetON(int magChan){
	if(magChan > 4 || magChan < 1)
		return -2;
	
	if(invert)
		pwmVal = 0x0000;
	else
		pwmVal = 0xFFFF;
	
	if(setChannel(i*3, pwmVal) != 0)
		return -1;
	
	if(setChannel(i*3+1, pwmVal) != 0)
		return -1;
	
	if(setChannel(i*3+2, pwmVal) != 0)
		return -1;

	return 0;
}
