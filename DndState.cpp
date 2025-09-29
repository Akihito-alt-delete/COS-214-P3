#include "DndState.h"

DndState::DndState(){
    send = true;
    receive = false;
}

DndState::~DndState(){}

bool DndState::CanReceiveMessage(){
    return receive;
}

bool DndState::CanSendMessage(){
    return send;
}
