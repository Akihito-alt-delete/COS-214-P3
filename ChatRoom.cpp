#include "ChatRoom.h"
#include "Users.h"

/**
 * @file ChatRoom.cpp
 * @brief Implementation of the ChatRoom class (Mediator pattern)
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

ChatRoom::ChatRoom()
{
    users.reserve(50);
    chatHistory.reserve(1000);
}

void ChatRoom::sendMessage(string message, Users *fromUser)
{
    cout << "[" << getRoomName() << "] " << fromUser->getName() << ": " << message << endl;
    for (Users *user : users)
    {
        if (user != fromUser)
        {
            user->receive(message, fromUser, this);
        }
    }
}

void ChatRoom::saveMessage(string message, Users *fromUser)
{
    string formattedMessage = "[" + fromUser->getName() + "]: " + message;
    chatHistory.push_back(formattedMessage);
    cout << "[" << getRoomName() << "] Message saved to history: " << formattedMessage << endl;
}

ChatRoom::~ChatRoom()
{
    cout << "ChatRoom destroyed" << endl;
}