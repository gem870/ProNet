#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include <string>
#include "Message.h"

class Client {
public:
    Client(const std::string& ip, int port);
    ~Client();

    bool connectToServer();
    void sendMessage(const Message& msg);

private:
    SOCKET clientSocket;
    std::string serverIP;
    int serverPort;
};

#endif
