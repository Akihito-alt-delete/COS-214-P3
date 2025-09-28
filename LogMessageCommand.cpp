#include "LogMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

/**
 * @file LogMessageCommand.cpp
 * @brief Implementation of the LogMessageCommand class
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

LogMessageCommand::LogMessageCommand(ChatRoom* room, Users* fromUser, string message)
    : Command(room, fromUser, message) {
}

void LogMessageCommand::execute() {
    if (room != nullptr && fromUser != nullptr) {
        cout << "  [Executing LogMessageCommand]" << endl;
        room->saveMessage(message, fromUser);
    }
}

LogMessageCommand::~LogMessageCommand() {
}