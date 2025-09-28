#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"

/**
 * @file Users.cpp
 * @brief Implementation of the Users class (Colleague in Mediator pattern, Invoker in Command pattern)
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

Users::Users(string name) : name(name) {
    chatRooms.reserve(10);
    commandQueue.reserve(100);
    cout << "User " << name << " created." << endl;
}

void Users::send(string message, ChatRoom* room) {
    if (room == nullptr) {
        cout << "Error: Cannot send message to null room" << endl;
        return;
    }
    cout << name << " is sending message to " << room->getRoomName() << endl;
    Command* sendCmd = new SendMessageCommand(room, this, message);
    Command* logCmd = new LogMessageCommand(room, this, message);
    addCommand(sendCmd);
    addCommand(logCmd);
    executeAll();
}

void Users::receive(string message, Users* fromUser, ChatRoom* room) {
    cout << "  [" << name << " received in " << room->getRoomName() << "]: " 
         << fromUser->getName() << " says: " << message << endl;
}

void Users::addCommand(Command* command) {
    if (command != nullptr) {
        commandQueue.push_back(command);
    }
}

void Users::executeAll() {
    for (Command* cmd : commandQueue) {
        if (cmd != nullptr) {
            cmd->execute();
        }
    }
    for (Command* cmd : commandQueue) {
        delete cmd;
    }
    commandQueue.clear();
}

Users::~Users() {
    for (Command* cmd : commandQueue) {
        delete cmd;
    }
    commandQueue.clear();
    cout << "User " << name << " destroyed." << endl;
}