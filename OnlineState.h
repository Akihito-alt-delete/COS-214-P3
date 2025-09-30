#ifndef ONLINESTATE_H
#define ONLINESTATE_H
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
    virtual ~OnlineState();
    bool CanReceiveMessage();
    bool CanSendMessage();
};
#endif