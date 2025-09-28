#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>

class ChatRoom;
class Users;

using namespace std;

/**
 * @class Command
 * @brief Abstract base class for Command pattern
 *
 * Encapsulates a request as an object, allowing for queuing of operations.
 */
class Command
{
public:
    /**
     * @brief Constructor
     * @param room The chat room (receiver)
     * @param fromUser The user issuing the command
     * @param message The message content
     */
    Command(ChatRoom *room, Users *fromUser, string message);

    /**
     * @brief Executes the command
     */
    virtual void execute() = 0;

    /**
     * @brief Destructor
     */
    virtual ~Command();

protected:
    ChatRoom *room;
    Users *fromUser;
    string message;
};

#endif