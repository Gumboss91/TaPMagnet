#include "TB.h"
#include "../TaPMagnets.h"

int tbTaPMagnets(int debug){
	int i = 0;
	signed char retmagnetInit, retmagnetOFF, retsetMagnetON, retmagnetON;

	retmagnetInit = magnetInit(0);
	if(retmagnetInit != 0){
		printf("ERROR  %d magnetInit(0) faild\n",retmagnetInit);
		ErrCNT++;
		return -1; }
	else if(debug)	printf("PASSED %d magnetInit(0)\n",retmagnetInit);
	
	retmagnetOFF = magnetOFF(1);
	if(retmagnetOFF != 0){
		printf("ERROR  %d magnetOFF(1) faild\n",retmagnetOFF);
		ErrCNT++;
		return -1; }
	else if(debug)	printf("PASSED %d magnetOFF(1)\n",retmagnetOFF);
	
	retmagnetON = magnetON(1);
	if(retmagnetOFF != 0){
		printf("ERROR  %d magnetON(1) faild\n",retmagnetOFF);
		ErrCNT++;
		return -1; }
	else if(debug)	printf("PASSED %d magnetON(1)\n",retmagnetOFF);
	
	return 0;
}
