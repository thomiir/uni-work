#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
int main() {
	int c;
	struct sockaddr_in server;

	c = socket(AF_INET, SOCK_STREAM, 0);
	if (c < 0) {
		printf("Eroare la crearea socketului client\n");
		return 1;
	}

	memset(&server, 0, sizeof(server));
	server.sin_port = htons(1236);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
		printf("Eroare la conectarea la server\n");
		return 1;
	}
	
	char chr;
	uint16_t lg, nrAparitii;
	char* str;
	printf("Introduceti caracterul: ");
	scanf("%c", &chr);
	printf("Introduceti lungimea sirului: ");
	scanf("%hd", &lg);
	str = (char*)malloc(lg * sizeof(char));
	printf("Introduceti sirul de caractere: ");
	scanf("%s", str);
	lg = htons(lg);
	send(c, &chr, sizeof(chr), 0);
	send(c, &lg, sizeof(lg), 0);
	send(c, str, sizeof(char) * lg, 0);
	recv(c, &nrAparitii, sizeof(nrAparitii), 0);
	nrAparitii = ntohs(nrAparitii);
	printf("Caracterul apare de %d ori", nrAparitii);
	close(c);
	free(str);
}
