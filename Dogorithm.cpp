#include "Dogorithm.h"
#include "Users.h"

/**
 * @file Dogorithm.cpp
 * @brief Implementation of the Dogorithm chat room (Concrete Mediator)
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

Dogorithm::Dogorithm() {
    cout << "Dogorithm chat room created - For algorithmic dog lovers!" << endl;
}

void Dogorithm::registerUser(Users* user) {
    if (user == nullptr) {
        cout << "Error: Cannot register null user" << endl;
        return;
    }
    bool userFound = false;
    for (Users* existingUser : users) {
        if (existingUser == user) {
            userFound = true;
            break;
        }
    }
    if (!userFound) {
        users.push_back(user);
        cout << user->getName() << " joined Dogorithm chat room." << endl;
        string joinMessage = user->getName() + " has joined the room!";
        for (Users* existingUser : users) {
            if (existingUser != user) {
                existingUser->receive(joinMessage, user, this);
            }
        }
    } else {
        cout << user->getName() << " is already in Dogorithm." << endl;
    }
}

void Dogorithm::removeUser(Users* user) {
    if (user == nullptr) {
        return;
    }
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            users.erase(users.begin() + i);
            cout << user->getName() << " left Dogorithm chat room." << endl;
            
            string leaveMessage = user->getName() + " has left the room.";
            for (Users* remainingUser : users) {
                remainingUser->receive(leaveMessage, user, this);
            }
            break;
        }
    }
}

Dogorithm::~Dogorithm() {
    cout << "Dogorithm chat room destroyed." << endl;
}