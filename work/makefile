#all: magnetServer.o

#magnetServer.o: magnetServer.c
#	gcc magnetServer.c -o MS -lwiringPia

all: TaPMagnetServer.o
	
TaPMagnetServer.o: TaPMagnetServer.c UDPServer.c TaPMagnets.c PWM_TLC59711.c
	gcc TaPMagnetServer.c UDPServer.c TaPMagnets.c PWM_TLC59711.c -o TaPMagnetServer -lwiringPi
