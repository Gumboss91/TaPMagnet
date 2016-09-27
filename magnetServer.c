/*erver.c - A simple UDP echo server 
 usage: udpserver <port>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "magnet.h"

#define BUFSIZE 1024

/*
 * error - wrapper for perror
 */
void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
	int i = 0;
  int sockfd; /* socket */
  int portno; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  struct hostent *hostp; /* client host info */
  char buf[BUFSIZE]; /* message buf *a*/
	char copybuf[BUFSIZE];
  char *hostaddrp; /* dotted decimal host addr string */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */
	char *ptrSplitBuf;
	char *tapMagnet = "tap";
	char *magnetMode = "ON";
	char magnetChan = 5;
	char DC = 50; // DutyCycle

  /* 
   * check command line arguments 
  
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);
	*/
	portno = 5555;

	// SPI Init for PWM Chip
	if(initSPI() == -1)
		printf("SPI Error\n");
	else
		printf("SPI Init succsess!\n");
 
 	// Turn all Magnets ON
	if(magnetON(1, DC) == -1)
		printf("error turn Magnet 1 ON");
	else
		printf("Magnet 1 ON\n");
  
	if(magnetON(2, DC) == -1)
		printf("error turn Magnet 2 ON");
	else
		printf("Magnet 2 ON\n");
  
	if(magnetON(3, DC) == -1)
		printf("error turn Magnet 3 ON");
	else
		printf("Magnet 3 ON\n");

	if(magnetON(4, DC) == -1)
		printf("error turn Magnet 4 ON");
	else
		printf("Magnet 4 ON\n");
 		   
	/* 
   * socket: create the parent socket 
   */
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) 
    error("ERROR opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "ERROR on binding: Address already in use" error. 
   */
  optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
	     (const void *)&optval , sizeof(int));

  /*
   * build the server's Internet address
   */
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons((unsigned short)portno);

  /* 
   * bind: associate the parent socket with a port 
   */
  if (bind(sockfd, (struct sockaddr *) &serveraddr, 
	   sizeof(serveraddr)) < 0) 
    error("ERROR on binding");

  /* 
   * main loop: wait for a datagram, then echo it
   */
  clientlen = sizeof(clientaddr);
  while (1) {

    /*
     * recvfrom: receive a UDP datagram from a client
     */
    bzero(buf, BUFSIZE);
    n = recvfrom(sockfd, buf, BUFSIZE, 0,
		 (struct sockaddr *) &clientaddr, &clientlen);
    if (n < 0)
      error("ERROR in recvfrom");
	
		/* 
     * gethostbyaddr: determine who sent the datagram
     */
		hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, 
			  sizeof(clientaddr.sin_addr.s_addr), AF_INET);
    if (hostp == NULL)
      error("ERROR on gethostbyaddr");
    hostaddrp = inet_ntoa(clientaddr.sin_addr);
    if (hostaddrp == NULL)
      error("ERROR on inet_ntoa\n");
    printf("server received datagram from %s (%s)\n", 
	   hostp->h_name, hostaddrp);
  	for(i=0;i<BUFSIZE;i++)
			copybuf[i] = '\0';
		for(i=0;i<strlen(buf);i++)
			copybuf[i] = buf[i];  
		
		printf("Buf: %s\nCopyBuf: %s\n",buf,copybuf);
		printf("\n\n***********************\n");
		
		ptrSplitBuf = strtok(copybuf,";");
		tapMagnet = ptrSplitBuf;	
	 	printf("TapMagnet: %s\n",tapMagnet);
		
		ptrSplitBuf = strtok(NULL, ";");
		printf("conversion Start of: %s\n",ptrSplitBuf);
		magnetChan = atoi(ptrSplitBuf);
		printf("LedChan: %d\n",magnetChan);

		ptrSplitBuf = strtok(NULL, ";");
		magnetMode = ptrSplitBuf;
		printf("MagnetMode:_%s_\n", magnetMode);

		if(strcmp(magnetMode,"ON") == 0){
			printf("LEN: %s\n",ptrSplitBuf);	
			ptrSplitBuf = strtok(NULL, ";");
			DC = atoi(ptrSplitBuf);
			printf("DutyCyle: %d\n", DC);}

		switch(magnetChan){
			case 1:	printf("MagnetChan 1\n");
							if(strcmp(magnetMode,"ON")== 0)
								magnetON(magnetChan,DC);
							if(strcmp(magnetMode,"OFF")== 0)
								magnetOFF(magnetChan);
							break;
 			case 2: printf("MagnetChan 2\n");
							if(strcmp(magnetMode,"ON")== 0)
								magnetON(magnetChan,DC);
							if(strcmp(magnetMode,"OFF")== 0)
								magnetOFF(magnetChan);
							break;
 			case 3: printf("MagnetChan 3\n");
							if(strcmp(magnetMode,"ON")== 0)
								magnetON(magnetChan,DC);
							if(strcmp(magnetMode,"OFF")== 0)
								magnetOFF(magnetChan);
							break;
 			case 4: printf("MagnetChan 4\n");
							if(strcmp(magnetMode,"ON")== 0)
								magnetON(magnetChan,DC);
							if(strcmp(magnetMode,"OFF")== 0)
								magnetOFF(magnetChan);
							break;
     	default: magnetON(1,DC); magnetON(2,DC); magnetON(3,DC); magnetON(4,DC);
							break;
		}
		

		printf("\n");
    /*
	   *sendto: echo the input back to the client 
     */
    n = sendto(sockfd, buf, strlen(buf), 0, 
	       (struct sockaddr *) &clientaddr, clientlen);
    if (n < 0) 
      error("ERROR in sendto");
  	printf("\n\n\n");
	
	}
}
