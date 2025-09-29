#include "UserState.h"
#include <iostream>

/**
 * @class OnlineState
 * @brief Represents the online state of a user
 * 
 * In this state, users can both send and receive messages.
 */
class OnlineState:public UserState{
    public:
    OnlineState();
    ~OnlineState();
    bool CanReceiveMessage();
    bool CanSendMessage();
};