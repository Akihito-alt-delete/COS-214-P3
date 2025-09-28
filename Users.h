#ifndef USERS_H
#define USERS_H

#include <string>
#include <vector>
#include <iostream>

class ChatRoom;
class Command;

using namespace std;

/**
 * @class Users
 * @brief Represents a user in the PetSpace chat system
 * 
 * Users can participate in multiple chat rooms and send/receive messages.
 * They act as the Invoker in the Command pattern.
 */
class Users {
public:
    /**
     * @brief Constructor
     * @param name The name of the user
     */
    Users(string name);
    
    /**
     * @brief Sends a message to a chat room
     * @param message The message content
     * @param room The target chat room
     */
    void send(string message, ChatRoom* room);
    
    /**
     * @brief Receives a message from another user
     * @param message The message content
     * @param fromUser The sender
     * @param room The chat room where message was sent
     */
    void receive(string message, Users* fromUser, ChatRoom* room);
    
    /**
     * @brief Adds a command to the command queue
     * @param command The command to add
     */
    void addCommand(Command* command);
    
    /**
     * @brief Executes all commands in the queue
     */
    void executeAll();
    
    /**
     * @brief Gets the user's name
     * @return The user's name
     */
    string getName() const { return name; }
    
    /**
     * @brief Destructor
     */
    ~Users();
    
protected:
    vector<ChatRoom*> chatRooms;
    string name;
    vector<Command*> commandQueue;
};

#endif