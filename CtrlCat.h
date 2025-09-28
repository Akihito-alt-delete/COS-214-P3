#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

/**
 * @class CtrlCat
 * @brief Concrete Mediator for cat and tech enthusiasts
 * 
 * A specific chat room implementation for cat lovers who also enjoy technology.
 */
class CtrlCat : public ChatRoom {
public:
    /**
     * @brief Constructor
     */
    CtrlCat();
    
    /**
     * @brief Registers a user to the CtrlCat room
     * @param user The user to register
     */
    void registerUser(Users* user) override;
    
    /**
     * @brief Removes a user from the CtrlCat room
     * @param user The user to remove
     */
    void removeUser(Users* user) override;
    
    /**
     * @brief Gets the room name
     * @return The room name "CtrlCat"
     */
    string getRoomName() const override { return "CtrlCat"; }
    
    /**
     * @brief Destructor
     */
    ~CtrlCat();
};

#endif