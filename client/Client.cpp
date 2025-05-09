#include "Client.h"
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

Client::Client(const std::string& ip, int port)
    : serverIP(ip), serverPort(port), clientSocket(INVALID_SOCKET) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

Client::~Client() {
    closesocket(clientSocket);
    WSACleanup();
}

bool Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());

    return connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) != SOCKET_ERROR;
}

void Client::sendMessage(const Message& msg) {
    std::string jsonData = msg.toJSON();
    send(clientSocket, jsonData.c_str(), jsonData.size(), 0);
}
