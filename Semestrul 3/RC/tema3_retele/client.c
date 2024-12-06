#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main() {
	int c = socket(AF_INET, SOCK_DGRAM, 0);
	if (c < 0) {
		printf("socket err.");
		return 1;
	}

	struct sockaddr_in server;
	int x = sizeof(server);
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(1234);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	char sir[101];
	char chr;
	printf("c=");
	scanf(" %c", &chr);
	printf("sir=");
	scanf("%s", sir);
	char sendBuf[500];
	char recvBuf[500];
	sprintf(sendBuf, "%c %s", chr, sir);
	
	sendto(c, sendBuf, 500, 0, (struct sockaddr*) &server, x);
	recvfrom(c, recvBuf, 500, 0, (struct sockaddr*) &server, &x);
	printf("Sirul pozitiilor este: %s\n", recvBuf);

	close(c);
	return 0;
}	
