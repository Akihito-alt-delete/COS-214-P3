#include "SendMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

/**
 * @file SendMessageCommand.cpp
 * @brief Implementation of the SendMessageCommand class
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

SendMessageCommand::SendMessageCommand(ChatRoom* room, Users* fromUser, string message)
    : Command(room, fromUser, message) {
}

void SendMessageCommand::execute() {
    if (room != nullptr && fromUser != nullptr) {
        cout << "  [Executing SendMessageCommand]" << endl;
        room->sendMessage(message, fromUser);
    }
}

SendMessageCommand::~SendMessageCommand() {
}