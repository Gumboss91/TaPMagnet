# Makefie for Testbench

all: TB.o

TB.o: TB.c TB-PWM_TLC59711.c TB-TaPMagnets.c ../PWM_TLC59711.c ../TaPMagnets.c
	gcc TB.c TB-PWM_TLC59711.c TB-TaPMagnets.c ../PWM_TLC59711.c ../TaPMagnets.c -o TB -lwiringPi 



