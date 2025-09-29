#include "DndState.h"

/**
 * @brief Constructor for DndState
 * 
 * Initializes the state with send enabled and receive disabled.
 */
DndState::DndState(){
    send = true;
    receive = false;
}

DndState::~DndState(){}

/**
 * @brief Check if user can receive messages in DND state
 * @return false - Users cannot receive messages in DND state
 */
bool DndState::CanReceiveMessage(){
    return receive;
}

/**
 * @brief Check if user can send messages in DND state
 * @return true - Users can send messages in DND state
 */
bool DndState::CanSendMessage(){
    return send;
}