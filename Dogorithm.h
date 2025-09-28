#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

/**
 * @class Dogorithm
 * @brief Concrete Mediator for dog and algorithm enthusiasts
 * 
 * A specific chat room implementation for dog lovers who also enjoy algorithms and tech.
 */
class Dogorithm : public ChatRoom {
public:
    /**
     * @brief Constructor
     */
    Dogorithm();
    
    /**
     * @brief Registers a user to the Dogorithm room
     * @param user The user to register
     */
    void registerUser(Users* user) override;
    
    /**
     * @brief Removes a user from the Dogorithm room
     * @param user The user to remove
     */
    void removeUser(Users* user) override;
    
    /**
     * @brief Gets the room name
     * @return The room name "Dogorithm"
     */
    string getRoomName() const override { return "Dogorithm"; }
    
    /**
     * @brief Destructor
     */
    ~Dogorithm();
};

#endif