#include "UserState.h"
#include <iostream>

class OfflineState:public UserState{
    public:
    OfflineState();
    ~OfflineState();
    bool CanReceiveMessage();
    bool CanSendMessage();
};