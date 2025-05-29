#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int c, char *av[])
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        perror("socket creation failed!");
        exit(EXIT_FAILURE);
    }
    sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    connect(client_socket, (sockaddr *)&server_address, sizeof(server_address));
    
    // char buff[1024];
    // memset(&buff , 0 , sizeof(buff));
    const char *message = av[1];

    send(client_socket, message, strlen(message), 0);
    close (client_socket);
}
