#include "TB.h"
#include "../TaPMagnets.h"
#define SIZEMOFFVAL2D 2
#define SIZESETMONVAL2D 3

int tbTaPMagnets(int debug){
	int i = 0;
	signed char retmagnetInit, retmagnetOFF, retsetMagnetON, retsetmagnetON;
	
	// Array[erwartungswert][funktVariablen 0]..[funktVariablen n]
	signed char mOFFVal[][SIZEMOFFVAL2D] =	{{0,1},
											{0,2},
											{0,3},
											{0,4},
											{-2,0},
											{-2,5},
											{-2,-1}, };
											
	signed char setmONVal[][SIZESETMONVAL2D] = 	{
											{0,1,50},
											{0,1,100},
											{0,2,100},
											{0,3,100},
											{0,4,100},
											{-2,0,100},
											{-2,-1,100},
											{-2,5,100},
											{-2,1,-100},
											{-2,1,101}, };
	
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
		retmagnetOFF = magnetOFF(mOFFVal[i][1]);
		if(retmagnetOFF != mOFFVal[i][0]){
			printf("ERROR  %d magnetOFF(%d) faild\n",retmagnetOFF,mOFFVal[i][1]);
			ErrCNT++; }
		else if(debug){ 
			printf("PASSED %d magnetOFF(%d)\n",retmagnetOFF,mOFFVal[i][1]);
			usleep(Sleep);}
		if(printBuff) printSPIBuff();
	}
	
	for(i=0;i<sizeof(setmONVal)/SIZESETMONVAL2D;i++){
		retsetmagnetON = setMagnetON(setmONVal[i][1],setmONVal[i][2]);
		if(retsetmagnetON != setmONVal[i][0]){
			printf("ERROR  %d magnetON(%d,%d) faild\n",retsetmagnetON,setmONVal[i][1],setmONVal[i][2]);
			ErrCNT++;}
		else if(debug){
				printf("PASSED %d magnetON(%d,%d)\n",retsetmagnetON,setmONVal[i][1],setmONVal[i][2]);
				usleep(Sleep);}
		if(printBuff) printSPIBuff();
	}
	
	return 0;
}
