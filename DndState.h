#include "UserState.h"
#include <iostream>

class DndState:public UserState{
    public:
    DndState();
    ~DndState();
    bool CanReceiveMessage();
    bool CanSendMessage();
};