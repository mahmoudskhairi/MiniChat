#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);//protocol: IPPROTO_TCP
    if (server_socket == -1)
    {
        perror("socket creation failed!");
        exit (EXIT_FAILURE);
    }
    std::cout << "fd: " << server_socket << std::endl;
    sockaddr_in SocketAdd;
    memset(&SocketAdd, 0 , sizeof(SocketAdd));
    SocketAdd.sin_family = AF_INET;
    SocketAdd.sin_port = htons(8080);
    SocketAdd.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (sockaddr *)&SocketAdd, sizeof(SocketAdd)) == -1)
    {
        perror("binding failed!");
        exit (EXIT_FAILURE);
    }
    if (listen(server_socket, 10) == -1)
    {
        perror("listening failed!");
        exit (EXIT_FAILURE);
    }
    while(1)
    {    
        int client_socket = accept(server_socket, nullptr, nullptr);
        if (client_socket == -1)
        {
            perror("accepting client was failed!");
            exit (EXIT_FAILURE);
        }
        char buff[1024];
        memset(&buff, 0 , sizeof(buff));
        if (recv(client_socket, buff, sizeof(buff), 0) == -1)
        {
            perror("recv are failed!");
            exit (EXIT_FAILURE);
        }
        std::cout << "client message: " << buff << std::endl;}
    // close(server_socket);
}