/* Testbench for TLC59711 Functions
 *
 *
 */

#include "TB.h"
#include  "PWM_TLC59711.h"

int tbTLC59711(int debug){
	signed char retInitSPI, retfullON, retsetAllChan, retClearAll;
	
	retInitSPI = initSPI();
	if(retInitSPI == -1){
		printf("ERROR SPI Init faild\n");
		ErrCNT++;
		return -1; }
	else if(debug)	printf("SPI Init succses!\n");
	if(printBuff) printSPIBuff();
	
	// Test clearAll()
	retClearAll = clearAll();
	if(retClearAll == -1){
		printf("ERROR clearAll faild\n");
		ErrCNT++;}
	else if(debug){ printf("clearAll succes!\n"); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	// Test fullON()
	retfullON = fullON();
	if(retfullON == -1){
		printf("ERROR fullON faild\n");;
		ErrCNT++;}
	else if(debug) printf("fullON succes!\n"); usleep(Sleep);
		if(printBuff) printSPIBuff();
		
	// Test setALLChan(int pwmVal)
		// Check for Vaild
	retsetAllChan = setAllChan(0);
	if(retsetAllChan == -1){
		printf("ERROR setAllChan(0) faild\n");
		ErrCNT++;}
	else if(debug){ printf("setAllChan(0) succes!\n"); usleep(Sleep);}
		if(printBuff) printSPIBuff();
		
	retsetAllChan = setAllChan(30000);
	if(retsetAllChan == -1){
		printf("ERROR setAllChan(30000) faild\n");
		ErrCNT++;}
	else	if(debug){ printf("setAllChan(30000) succes!\n"); usleep(Sleep);}
		if(printBuff) printSPIBuff();
		
	retsetAllChan = setAllChan(0xFFFF);
	if(retsetAllChan == -1){
		printf("ERROR setAllChan(0xFFFF) faild\n");
		ErrCNT++;}
	else	if(debug){ printf("setAllChan(0xFFFF) succes!\n"); usleep(Sleep);}
		if(printBuff) printSPIBuff();
			
	// Check for fail
	retsetAllChan = setAllChan(-10);
	if(retsetAllChan != -2){
		printf("ERROR setAllChan(-10) faild\n");
		ErrCNT++;}
	else	if(debug){ printf("setAllChan(-10) succes!\n"); usleep(Sleep);}
		if(printBuff) printSPIBuff();
			
	retsetAllChan = setAllChan(66666);
	if(retsetAllChan != -2){
		printf("ERROR setAllChan(66666) faild\n");
		ErrCNT++;}
	else	if(debug){ printf("setAllChan(66666) succes!\n"); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	
	if(ErrCNT == 0)
		printf("PWM_TLC59711 succes!\n");
	else{
		printf("ERROR PWM_TLC59711 faild");
		return -1;}
	return 0;
}
