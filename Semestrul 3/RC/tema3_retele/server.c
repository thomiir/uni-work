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

        struct sockaddr_in server, client;
        int x = sizeof(client);
	memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(1234);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

 	if (bind(c, (struct sockaddr*) &server, sizeof(server)) < 0) {
		printf("bind err.");
		return 1;
	}

	char recvBuf[500];
	char sir[101];
	char chr;

	recvfrom(c, recvBuf, 500, 0, (struct sockaddr*) &client, &x);
	sscanf(recvBuf, "%c %s", &chr, sir);
        
	char sendBuf[500];
	memset(sendBuf, 0, sizeof(sendBuf));
	for (int i = 0; i < strlen(sir); i++)
		if (sir[i] == chr) {
			char tmp[3];
			sprintf(tmp, "%d ", i);
			strcat(sendBuf, tmp);
		}

	sendto(c, sendBuf, 500, 0, (struct sockaddr*) &client, x);

        close(c);
        return 0;
}
