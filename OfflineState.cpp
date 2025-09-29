#include "OfflineState.h"

OfflineState::OfflineState(){
    send = false;
    receive = false;
}

OfflineState::~OfflineState(){}

bool OfflineState::CanReceiveMessage(){
    return receive;
}

bool OfflineState::CanSendMessage(){
    return send;
}
