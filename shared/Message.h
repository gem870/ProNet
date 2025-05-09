#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "json.hpp"

using json = nlohmann::json;

class Message {
public:
    Message() = default;
    Message(const std::string& name, const std::string& profession, const std::string& msg)
        : name(name), profession(profession), message(msg) {}

    std::string toJSON() const {
        json j = {{"name", name}, {"profession", profession}, {"message", message}};
        return j.dump();
    }

    bool fromJSON(const std::string& str) {
        try {
            json j = json::parse(str);
            name = j.at("name").get<std::string>();
            profession = j.at("profession").get<std::string>();
            message = j.at("message").get<std::string>();
            return true;
        } catch (json::exception&) {
            return false;
        }
    }

    std::string getName() const { return name; }
    std::string getMessage() const { return message; }

private:
    std::string name;
    std::string profession;
    std::string message;
};

#endif
