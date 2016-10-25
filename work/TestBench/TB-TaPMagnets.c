#include "TB.h"
#include "../TaPMagnets.h"

int tbTaPMagnets(int debug){
	int i = 0;
	signed char retmagnetInit, retmagnetOFF, retsetMagnetON, retmagnetON;
	
	printf("---Testing TaPMagnets---\n");
	
	if(init == 0){
		init = 1;
		retmagnetInit = magnetInit(0);
		if(retmagnetInit != 0){
			printf("ERROR  %d magnetInit(0) faild\n",retmagnetInit);
			ErrCNT++;
			return -1; }
		else if(debug){	printf("PASSED %d magnetInit(0)\n",retmagnetInit); usleep(Sleep);}
		if(printBuff) printSPIBuff();
	}
	printf("Init Complete\n");
	
	retmagnetOFF = magnetOFF(1);
	printf("1\n");
	if(retmagnetOFF != 0){
		printf("2\n");
		printf("ERROR  %d magnetOFF(1) faild\n",retmagnetOFF);
		ErrCNT++;
		return -1; }
	else if(debug){ printf("3\n"); printf("PASSED %d magnetOFF(1)\n",retmagnetOFF);usleep(Sleep);}
	printf("4\n");
	if(printBuff) printSPIBuff();
	printf("first test  Complete\n");
	
	retmagnetON = magnetON(1);
	if(retmagnetON != 0){
		printf("ERROR  %d magnetON(1) faild\n",retmagnetON);
		ErrCNT++;
		return -1; }
	else if(debug){	printf("PASSED %d magnetON(1)\n",retmagnetON);usleep(Sleep);}
	if(printBuff) printSPIBuff();
	printf("second test Complete\n");
	
	retmagnetON = magnetON(2);
	if(retmagnetON != 0){
		printf("ERROR  %d magnetON(2) faild\n",retmagnetON);
		ErrCNT++;
		return -1; }
	else if(debug){	printf("PASSED %d magnetON(2)\n",retmagnetON);usleep(Sleep);}
	if(printBuff) printSPIBuff();
	
	retmagnetON = magnetON(3);
	if(retmagnetON != 0){
		printf("ERROR  %d magnetON(3) faild\n",retmagnetON);
		ErrCNT++;
		return -1; }
	else if(debug){	printf("PASSED %d magnetON(3)\n",retmagnetON);usleep(Sleep);}
	if(printBuff) printSPIBuff();
	
	retmagnetON = magnetON(4);
	if(retmagnetON != 0){
		printf("ERROR  %d magnetON(4) faild\n",retmagnetON);
		ErrCNT++;
		return -1; }
	else if(debug){	printf("PASSED %d magnetON(4)\n",retmagnetON);usleep(Sleep);}
	if(printBuff) printSPIBuff();
	
	// Check wrong function calls
	retmagnetON = magnetON(5);
	if(retmagnetON != -2){
		printf("ERROR  %d magnetON(5) faild\n",retmagnetON);
		ErrCNT++;
		return -1; }
	else if(debug){	printf("PASSED %d magnetON(5)\n",retmagnetON);usleep(Sleep);}
	if(printBuff) printSPIBuff();
	
	retmagnetON = magnetON(0);
	if(retmagnetON != -2){
		printf("ERROR  %d magnetON(0) faild\n",retmagnetON);
		ErrCNT++;
		return -1; }
	else if(debug){	printf("PASSED %d magnetON(0)\n",retmagnetON);usleep(Sleep);}
	if(printBuff) printSPIBuff();
	
	return 0;
}
