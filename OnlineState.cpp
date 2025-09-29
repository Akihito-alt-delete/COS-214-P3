#include "OnlineState.h"

OnlineState::OnlineState(){
    send = true;
    receive = true;
}

OnlineState::~OnlineState(){}

bool OnlineState::CanReceiveMessage(){
    return receive;
}

bool OnlineState::CanSendMessage(){
    return send;
}
