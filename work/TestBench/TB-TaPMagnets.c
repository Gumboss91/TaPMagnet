#include "TB.h"
#include "../TaPMagnets.h"
#define SIZEMOFFVAL2D 2

int tbTaPMagnets(int debug){
	int i = 0;
	signed char retmagnetInit, retmagnetOFF, retsetMagnetON, retmagnetON;
	
	signed char mOFFVal[][SIZEMOFFVAL2D] = {{1,0},
											{2,0},
											{3,0},
											{4,0},
											{0,-2},
											{5,-2},
											{-1,-2}, };
	
	printf("---Testing TaPMagnets---,\n");
	
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
	
	for(i=0;i<sizeof(mOFFVal)/SIZEMOFFVAL2D;i++){
		retmagnetOFF = magnetOFF(mOFFVal[i][0]);
		if(retmagnetOFF != mOFFVal[i][1]){
			printf("ERROR  %d magnetOFF(%d) faild\n",retmagnetOFF,mOFFVal[i][0]);
			ErrCNT++;
			return -1; }
		else if(debug){ 
			printf("PASSED %d magnetOFF(%d)\n",retmagnetOFF,mOFFVal[i][0]);
			usleep(Sleep);}
		if(printBuff) printSPIBuff();
	}
	
	
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
