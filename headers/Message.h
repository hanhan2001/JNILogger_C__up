#ifndef TERMINALCOLOR_MESSAGE_H
#define TERMINALCOLOR_MESSAGE_H

#include <iostream>

class Message {
private:
    std::string message;
    int color;
public:
    Message(const std::string& message, char color);
    std::string getMessage();
    int getColor() const;
    void send(bool line);
};

#endif