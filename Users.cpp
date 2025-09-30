#include "Users.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include <iostream>

using namespace std;

/**
 * @file Users.cpp
 * @brief Implementation of the Users class (Colleague in Mediator pattern, Invoker in Command pattern)
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

Users::Users(string name) : name(name) {
    chatRooms.reserve(10);
    commandQueue.reserve(100);
    cout << "User " << name << " created." << endl;
    state = new OnlineState();
}

void Users::send(string message, ChatRoom* room) {
    if (room == nullptr) {
        cout << "Error: Cannot send message to null room" << endl;
        return;
    }
    if(state->CanSendMessage()){
        cout << name << " is sending message to " << room->getRoomName() << endl;
        Command* sendCmd = new SendMessageCommand(room, this, message);
        Command* logCmd = new LogMessageCommand(room, this, message);
        addCommand(sendCmd);
        addCommand(logCmd);
        executeAll();
    }else{
        cout<< name << " cannot Send Messages while offile.\n";
    }
 
}

void Users::receive(string message, Users* fromUser, ChatRoom* room) {
    if(state->CanReceiveMessage()){
        cout << "  [" << name << " received in " << room->getRoomName() << "]: " 
         << fromUser->getName() << " says: " << message << endl;
    }else{
        cout<<name<< " cannot recieve messages at this time.\n";
    }
    
}

void Users::addCommand(Command* command) {
    if (command != nullptr) {
        commandQueue.push_back(command);
    }
}

void Users::executeAll() {
    for (Command* cmd : commandQueue) {
        if (cmd != nullptr) {
            cmd->execute();
        }
    }
    for (Command* cmd : commandQueue) {
        delete cmd;
    }
    commandQueue.clear();
}

Users::~Users() {
    for (Command* cmd : commandQueue) {
        delete cmd;
    }
    commandQueue.clear();
    cout << "User " << name << " destroyed." << endl;
    if(state != NULL){
        delete state;
        state = NULL;
    }
}

void Users::logout(){
    if(state->CanReceiveMessage() && state->CanSendMessage()){
        // Online state
        delete this->state;
        this->state = new OfflineState();
        cout<< name <<" has successfully been logged out.\n";

    }else if(state->CanSendMessage() && !state->CanReceiveMessage()){
        // DND state
        delete state;
        state = new OfflineState();
        cout<< name <<" has successfully been logged out.\n";
    }else{
        // Already Offline
        cout<< name << " is already offline.\n";
    }
}

void Users::login(){
    if(state->CanReceiveMessage() && state->CanSendMessage()){
        // Already online
        cout<< name  << " is already online.\n";
    }else if(state->CanSendMessage() && !state->CanReceiveMessage()){
        // In DND
        delete state;
        state = new OnlineState();
        cout<< name <<" has successfully come out of DND.\n";
    }else{
        // Offline
        delete state;
        state = new OnlineState();
        cout<< name <<" has successfully logged in.\n";
    }
}

void Users::GoDND(){
    if(state->CanReceiveMessage() && state->CanSendMessage()){
        // Online
        delete state;
        state = new DndState();
        cout<< name <<" has successfully gone into DND.\n";
    }else if(state->CanSendMessage() && !state->CanReceiveMessage()){
        // Already in DND
        cout<< name << " is already in DND.\n";
    }else{
        // Offline - login first, then go to DND
        delete state;
        state = new DndState();
        cout<< name <<" has successfully logged in and gone into DND.\n";
    }
}

bool Users::ChangeState(UserState *NewState){
    if(NewState != nullptr){
        delete state;
        state = NewState;
        return true;
    }
    return false;
}
