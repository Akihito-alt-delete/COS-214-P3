#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>
#include <iostream>

class Users;

using namespace std;

/**
 * @class ChatRoom
 * @brief Abstract Mediator class for managing chat room interactions
 *
 * Acts as the Mediator in the Mediator pattern, handling all communication
 * between users in a chat room.
 */
class ChatRoom
{
public:
    /**
     * @brief Constructor
     */
    ChatRoom();

    /**
     * @brief Registers a user to the chat room
     * @param user The user to register
     */
    virtual void registerUser(Users *user) = 0;

    /**
     * @brief Sends a message to all users in the room
     * @param message The message content
     * @param fromUser The sender
     */
    void sendMessage(string message, Users *fromUser);

    /**
     * @brief Saves a message to chat history
     * @param message The message content
     * @param fromUser The sender
     */
    void saveMessage(string message, Users *fromUser);

    /**
     * @brief Removes a user from the chat room
     * @param user The user to remove
     */
    virtual void removeUser(Users *user) = 0;

    /**
     * @brief Gets the chat room name
     * @return The room name
     */
    virtual string getRoomName() const = 0;

    /**
     * @brief Gets the chat history
     * @return Vector of chat messages
     */
    vector<string> getChatHistory() const { return chatHistory; }

    /**
     * @brief Gets the list of users
     * @return Vector of users
     */
    vector<Users *> getUsers() const { return users; }

    /**
     * @brief Destructor
     */
    virtual ~ChatRoom();

protected:
    vector<Users *> users;
    vector<string> chatHistory;
};

#endif