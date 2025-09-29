#include "OnlineState.h"

/**
 * @brief Constructor for OnlineState
 * 
 * Initializes the state with both send and receive enabled.
 */
OnlineState::OnlineState(){
    send = true;
    receive = true;
}

OnlineState::~OnlineState(){}

/**
 * @brief Check if user can receive messages in online state
 * @return true - Users can receive messages while online
 */
bool OnlineState::CanReceiveMessage(){
    return receive;
}

/**
 * @brief Check if user can send messages in online state
 * @return true - Users can send messages while online
 */
bool OnlineState::CanSendMessage(){
    return send;
}