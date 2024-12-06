#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void deservire_client(int c) {
  // deservirea clientului
  char a;
  uint16_t lg, freq = 0;
  char* str;
  recv(c, &a, sizeof(a), MSG_WAITALL);
  recv(c, &lg, sizeof(lg), MSG_WAITALL);
  lg = ntohs(lg);
  str = malloc(sizeof(char) * lg);
  recv(c, str, lg * sizeof(char), MSG_WAITALL);
  str[lg] = '\0';
  for (int i = 0; i < lg; i++)
	  if (str[i] == a)
		  freq++;
  freq = htons(freq);
  send(c, &freq, sizeof(freq), 0);
  close(c);
  free(str);
  // sfarsitul deservirii clientului;
}
 
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
  server.sin_port = htons(1234);
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
    c = accept(s, (struct sockaddr *) &client, &l);
    printf("S-a conectat un client.\n");
    if (fork() == 0) { // fiu
      deservire_client(c);
      return 0;
    }
    // se executa doar in parinte pentru ca fiul se termina mai sus din cauza exit-ului    
  }
}
