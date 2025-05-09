#include "Client.h"
#include <iostream>
#include <string>

int main() {
    Client client("127.0.0.1", 5400);
    if (!client.connectToServer()) {
        std::cerr << "Connection failed!" << std::endl;
        return 1;
    }

    std::string name, profession;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your profession: ";
    std::getline(std::cin, profession);

    std::string input;
    while (true) {
        std::cout << "Message (type 'exit' to quit): ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        Message msg{name, profession, input};
        client.sendMessage(msg);
    }

    return 0;
}
