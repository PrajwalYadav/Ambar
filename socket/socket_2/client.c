//client.c
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int sock, valread, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[255];

	if(argc < 3){
		fprintf(stderr, "usage %s hostname port\n", argv[0]);
		exit(1);
	}
	portno = atoi(argv[2]);
	sock = socket(AF_INET,	SOCK_STREAM, 0);
	if(sock < 0)
		perror("\n Socket creation error \n");


	server = gethostbyname(argv[1]);
	if(server == NULL) {
		fprintf(stderr, "Error, no such host\n");
	}

	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sock, (struct sockaddr*)&serv_addr,	sizeof(serv_addr))< 0) {
		printf("\nConnection Failed \n");
		return -1;
	}

	while(1) {
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);
		n = write(sock, buffer, strlen(buffer));
		if(n < 0)
			perror("error on writing\n");

		bzero(buffer, 255);
		n = read(sock, buffer, 255);
		if(n < 0)
			perror("error on writing\n");
		printf("Server : %s\n", buffer);

		int i = strncmp("Bye", buffer, 3);
		if(i == 0)
		break;
	}

	close(sock);
	return 0;
}

/*
RUN COMMAND:
1. make all
2. ./client 127.0.0.1 <portno same as server>
*/
