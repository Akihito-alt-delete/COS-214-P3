#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class SendMessageCommand
 * @brief Concrete command for sending messages
 * 
 * Encapsulates the action of sending a message to all users in a chat room.
 */
class SendMessageCommand : public Command {
public:
    /**
     * @brief Constructor
     * @param room The chat room (receiver)
     * @param fromUser The user sending the message
     * @param message The message content
     */
    SendMessageCommand(ChatRoom* room, Users* fromUser, string message);
    
    /**
     * @brief Executes the send message command
     */
    void execute() override;
    
    /**
     * @brief Destructor
     */
    ~SendMessageCommand();
};

#endif