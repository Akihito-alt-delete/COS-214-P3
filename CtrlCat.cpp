#include "CtrlCat.h"
#include "Users.h"

/**
 * @file CtrlCat.cpp
 * @brief Implementation of the CtrlCat chat room (Concrete Mediator)
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

CtrlCat::CtrlCat()
{
    cout << "CtrlCat chat room created - For cat-loving techies!" << endl;
}

void CtrlCat::registerUser(Users *user)
{
    if (user == nullptr)
    {
        cout << "Error: Cannot register null user" << endl;
        return;
    }
    bool userFound = false;
    for (Users *existingUser : users)
    {
        if (existingUser == user)
        {
            userFound = true;
            break;
        }
    }
    if (!userFound)
    {
        users.push_back(user);
        cout << user->getName() << " joined CtrlCat chat room." << endl;

        string joinMessage = user->getName() + " has joined the room!";
        for (Users *existingUser : users)
        {
            if (existingUser != user)
            {
                existingUser->receive(joinMessage, user, this);
            }
        }
    }
    else
    {
        cout << user->getName() << " is already in CtrlCat." << endl;
    }
}

void CtrlCat::removeUser(Users *user)
{
    if (user == nullptr)
    {
        return;
    }
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i] == user)
        {
            users.erase(users.begin() + i);
            cout << user->getName() << " left CtrlCat chat room." << endl;

            string leaveMessage = user->getName() + " has left the room.";
            for (Users *remainingUser : users)
            {
                remainingUser->receive(leaveMessage, user, this);
            }
            break;
        }
    }
}

CtrlCat::~CtrlCat()
{
    cout << "CtrlCat chat room destroyed." << endl;
}