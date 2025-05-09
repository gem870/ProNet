#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include <vector>
#include <thread>
#include <iostream>

class Server {
public:
    Server(int port);
    ~Server();

    void start();

private:
    SOCKET serverSocket;
    std::vector<std::thread> clientThreads;

    void handleClient(SOCKET clientSocket);
    void cleanup();
};

#endif
