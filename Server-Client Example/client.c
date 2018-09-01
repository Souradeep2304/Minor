#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main()
{
char client_message[256]="From Client!!!";
int network_socket= socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in server_address;
server_address.sin_family= AF_INET;
server_address.sin_port=htons(9002);
server_address.sin_addr.s_addr=INADDR_ANY;

int conn_status= connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
if(conn_status != 0)
{
printf("Error in Connection!!!");
}
char server_response[256];
send(network_socket, client_message, sizeof(client_message), 0);
recv(network_socket, &server_response, sizeof(server_response), 0);
printf("Message:%s",server_response);


return 0;

}


