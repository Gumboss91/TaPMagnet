#include <stdio.h>
#include "TB.h"

int main(int argc,char* argv[]){
	int debug = 0;
	printBuff = atoi(argv[2]);
	debug = 1;
	Sleep = atoi(argv[1]);
	init = 0;
	
	
	tbTLC59711(debug);
	
	
	tbTaPMagnets(debug);						
	return 0;
}
