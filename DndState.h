#include "UserState.h"
#include <iostream>

/**
 * @class DndState
 * @brief Represents the "Do Not Disturb" state of a user
 * 
 * In this state, users can send messages but cannot receive messages.
 */
class DndState:public UserState{
    public:
    DndState();
    ~DndState();
    bool CanReceiveMessage();
    bool CanSendMessage();
};