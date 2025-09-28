#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"

/**
 * @class LogMessageCommand
 * @brief Concrete command for logging/saving messages
 * 
 * Encapsulates the action of saving a message to the chat history.
 */
class LogMessageCommand : public Command {
public:
    /**
     * @brief Constructor
     * @param room The chat room (receiver)
     * @param fromUser The user sending the message
     * @param message The message content
     */
    LogMessageCommand(ChatRoom* room, Users* fromUser, string message);
    
    /**
     * @brief Executes the log message command
     */
    void execute() override;
    
    /**
     * @brief Destructor
     */
    ~LogMessageCommand();
};

#endif