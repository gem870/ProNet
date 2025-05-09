#include "Server.h"
#include <iostream>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

Server::Server(int port) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, SOMAXCONN);
    std::cout << "Server started on port " << port << std::endl;
}

Server::~Server() {
    closesocket(serverSocket);
    WSACleanup();
}

void Server::start() {
    while (true) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        std::cout << "Client connected." << std::endl;
        clientThreads.emplace_back(&Server::handleClient, this, clientSocket);
    }
}

void Server::handleClient(SOCKET clientSocket) {
    char buffer[1024];
    int bytesReceived;

    while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytesReceived] = '\0';
        std::cout << "Received: " << buffer << std::endl;
        send(clientSocket, buffer, bytesReceived, 0); // echo back
    }

    closesocket(clientSocket);
    std::cout << "Client disconnected." << std::endl;
}

void Server::cleanup() {
    for (auto& thread : clientThreads) {
        if (thread.joinable())
            thread.join();
    }
}
