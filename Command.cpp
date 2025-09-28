#include "Command.h"

/**
 * @file Command.cpp
 * @brief Implementation of the Command base class
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */

Command::Command(ChatRoom *room, Users *fromUser, string message)
    : room(room), fromUser(fromUser), message(message)
{
}

Command::~Command()
{
}