#include <unistd.h>
#include "TaPMagnetServer.h"


extern char *optarg;
main(int argc, char *argv[]){
	int opt;
	int port;
	int debug;
	port = DEFAULTPORT;
	debug = 1;

	while ((opt = getopt(argc, argv, "p:dh")) != -1) {
		switch (opt) {
		case 'p':
			if(optarg != NULL)
				port = atoi(optarg);
			break;
		case 'd':
			debug = 1;
			break;
		case 'h':
			printf("Help for TaPMagnetServer\n");
			printf("Usage: %s [-p port number] [-d] debug mode [-h] show Help\n", argv[0]);
			return 0;
			break;
		default: /* '?' */
			printf("Usage: %s [-p portnumber] [-d] debug mode [-h] show Help\n", argv[0]);
			return -2;
    }
  }
	printf("port: %d\n",port);
	printf("debug: %d\n",debug);
	
	


	return 0;
}
