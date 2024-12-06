#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int s;
	struct sockaddr_in server, client;
	int c, l;

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		printf("Eroare la crearea socketului server\n");
		return 1;
	}

	memset(&server, 0, sizeof(server));
	server.sin_port = htons(1236);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
		printf("Eroare la bind\n");
		return 1;
	}

	listen(s, 5);

	l = sizeof(client);
	memset(&client, 0, sizeof(client));

	while (1) {
		char chr;
		uint16_t lg, nrAparitii = 0;
		char* str;
		c = accept(s, (struct sockaddr *) &client, &l);
		printf("S-a conectat un client.\n");
		// deservirea clientului
		recv(c, &chr, sizeof(chr), MSG_WAITALL);
		recv(c, &lg, sizeof(lg), MSG_WAITALL);
		lg = ntohs(lg);
		str = (char*)malloc(lg * sizeof(char));
		str[lg] = '\0';
		recv(c, str, sizeof(char) * lg, MSG_WAITALL);	
		for (int i = 0; i < lg; i++)
			if (str[i] == chr) nrAparitii++;

		nrAparitii = htons(nrAparitii);
		send(c, &nrAparitii, sizeof(nrAparitii), 0);
		close(c);
		free(str);
		// sfarsitul deservirii clientului;
	}
}
