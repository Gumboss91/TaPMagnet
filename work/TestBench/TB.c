#include <stdio.h>
#include "TB.h"

int main(int argc,char* argv[]){
	int debug = 0;
	printBuff = atoi(argv[2]);
	debug = 1;
	Sleep = atoi(argv[1]);
	init = 0;
	
	printf("----Testing TLC59711----\n");	
	tbTLC59711(debug);
	
	printf("---Testing TaPMagnets---\n");
	printf("return: %d\n",tbTaPMagnets(debug));						
	
	printf("test end\n");
	return 0;
}
