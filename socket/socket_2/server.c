// server.c
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Port NO not provided. Program terminated.\n");
		exit(1);
	}

	int server_fd, new_socket, valread, n, portno;
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[255];
	socklen_t clilen;

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	bzero((char *)&serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	clilen = sizeof(cli_addr);

	new_socket = accept(server_fd, (struct sockaddr *)&cli_addr, &clilen);

	if(new_socket < 0) {
		perror("error");
		exit(EXIT_FAILURE);
	}

	while (1) {
		bzero(buffer, 255);
		n = read(new_socket, buffer, 255);
		if(n < 0)
			perror("error on writing\n");

		printf("Client : %s\n", buffer );
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);
		n = write(new_socket, buffer, strlen(buffer));
		if(n < 0)
			perror("error on writing\n");

		int i = strncmp("Bye", buffer, 3);
		if(i == 0)
		break;
	}
	close(new_socket);
	close(server_fd);
	return 0;
}

/*
RUN COMMAND:
1. make all
2. ./server <portno eg.5001>
*/
