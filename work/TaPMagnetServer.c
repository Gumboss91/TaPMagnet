#include "TaPMagnetServer.h"

int main(int argc, char *argv[]){
	int opt;
	int port;
	int debug;
	
	while ((opt = getopt(argc, argv, "pd")) != -1) {
		switch (opt) {
		case 'p':
            port = atoi(optarg);
			if(port == NULL)
				port = DEFAULTPORT;
            break;
        case 'd':
            debug = 1;
            break;
        default: /* '?' */
            printf("Usage: %s [-t nsecs] [-n] name\n", argv[0]);
            return -2;
        }
    }
	printf("port: %d\n",port);
	printf("debug: %d\n",debug);
	
	return 0;
}