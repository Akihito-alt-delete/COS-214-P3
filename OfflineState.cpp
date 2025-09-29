#include "OfflineState.h"

/**
 * @brief Constructor for OfflineState
 * 
 * Initializes the state with both send and receive disabled.
 */
OfflineState::OfflineState(){
    send = false;
    receive = false;
}

OfflineState::~OfflineState(){}

/**
 * @brief Check if user can receive messages in offline state
 * @return false - Users cannot receive messages while offline
 */
bool OfflineState::CanReceiveMessage(){
    return receive;
}

/**
 * @brief Check if user can send messages in offline state
 * @return false - Users cannot send messages while offline
 */
bool OfflineState::CanSendMessage(){
    return send;
}