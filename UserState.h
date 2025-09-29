#include "Users.h"
#include <iostream>

/**
 * @class UserState
 * @brief Abstract base class representing a user's state in the State pattern
 * 
 * Defines the interface for different user states (Online, Offline, DND).
 * Each state determines whether a user can send or receive messages.
 */
class UserState{
    protected:
        bool send;      ///< Flag indicating if user can send messages in this state
        bool receive;   ///< Flag indicating if user can receive messages in this state
    public:
        UserState();
        ~UserState();
        virtual bool CanReceiveMessage() = 0;
        virtual bool CanSendMessage() = 0;
};