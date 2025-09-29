#include "UserState.h"
#include <iostream>

/**
 * @class OfflineState
 * @brief Represents the offline state of a user
 * 
 * In this state, users cannot send or receive messages.
 */
class OfflineState:public UserState{
    public:
    OfflineState();
    ~OfflineState();
    bool CanReceiveMessage();
    bool CanSendMessage();
};