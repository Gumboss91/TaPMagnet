all: magnetServer.o

magnetServer.o: magnetServer.c
	gcc magnetServer.c -o MS -lwiringPi
