#include "Users.h"
#include <iostream>


class UserState{
    protected:
        bool send;
        bool receive;
    public:
        UserState();
        ~UserState();
        virtual bool CanReceiveMessage() = 0;
        virtual bool CanSendMessage() = 0;



};