#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
char server_resp[256]="From Server!!!";
int server_socket=socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(9002);
server_address.sin_addr.s_addr=INADDR_ANY;

bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
listen(server_socket, 5);
char client_resp[256];
int client_socket;
client_socket=accept(server_socket, NULL, NULL);
send(client_socket, server_resp, sizeof(server_resp), 0);
recv(client_socket, &client_resp, sizeof(client_resp), 0);
printf("Message:%s",client_resp);
close(server_socket);
return 0;
}


