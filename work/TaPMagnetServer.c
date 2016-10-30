#include <unistd.h>
#include "TaPMagnetServer.h"


extern char *optarg;
main(int argc, char *argv[]){
	int i;
	int opt;
	int port = DEFAULTPORT;
	int debug = 0;
	int invert = 0;
	char recvmsg[BUFSIZE] = "TaPMagnetServer;ON;100;";
	
	while ((opt = getopt(argc, argv, "p:dih")) != -1) {
		switch (opt) {
		case 'p':
			if(optarg != NULL)
				port = atoi(optarg);
			break;
		case 'd':
			debug = 1;
			break;		
		case 'i':
			invert = 1;
			break;
		case 'h':
			printf("Help for TaPMagnetServer\n");
			printf("Usage: %s [-p port number] [-d] debug mode [-h] show Help\n", argv[0]);
			return 0;
			break;
		default: /* '?' */
			printf("Usage: %s [-p portnumber] [-d] debug mode [-i] invert pwm output [-h] show Help\n", argv[0]);
			return -2;
    }
  }
	printf("port: %d\n",port);
	printf("debug: %d\n",debug);
	
	if(initUDPServer(port) != 0){
		printf("ERROR whil init UDP-Server\n");
		return -1;
	}
	
	if(magnetInit(invert) != 0){
		printf("ERROR whil init Magnets\n");
		return -1;
	}
	
	while(strcmp(recvmsg,"TaPMagnet;exit") != 0){
		waitForClient(recvmsg);
		printf("msg: %s\n",recvmsg);
		
		if(parseCommand(recvmsg) != 0){
			printf("ERROR wrong Syntax\n");
			continue;
		}
		
		if(strcmp(MagnetMode, "ON") == 0){
			if(setMagnetON(MagnetChan, DC) !=0){
				printf("ERROR setMagnetON(%d,%d)\n",MagnetChan,DC);
				continue;
			}
			if(debug) printf("setMagnetON(%d,%d)\n",MagnetChan,DC);}
		else if(strcmp(MagnetMode, "OFF") == 0){
			if(magnetOFF(MagnetChan) !=0){
				printf("ERROR magnetOFF(%d)\n",MagnetChan);
				continue;
			}
			if(debug) printf("magnetOFF(%d)\n",MagnetChan");
		}
	}
		
	}
	
	return 0;
}

signed char parseCommand(char *command){
	
	return 0;
}