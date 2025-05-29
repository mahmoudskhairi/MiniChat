#include <iostream>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        perror("Try with a valid input!");
        exit (EXIT_FAILURE);
    }
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

    if (connect(client_socket, (sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        perror("connection failed!");
        exit (EXIT_FAILURE);
    }
    const char *message = av[1];
    // if (send(client_socket, message, strlen(message), 0) == -1)
    // {
    //     perror("message doesen't sent!");
    //     exit (EXIT_FAILURE);
    // }
    if (write (client_socket, message, strlen(message)) == -1)
    {
        perror("message doesen't sent!");
        exit (EXIT_FAILURE);
    }
    close (client_socket);
}
