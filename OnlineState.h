#include "UserState.h"
#include <iostream>

class OnlineState:public UserState{
    public:
    OnlineState();
    ~OnlineState();
    bool CanReceiveMessage();
    bool CanSendMessage();
};