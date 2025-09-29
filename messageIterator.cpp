#include "messageIterator.h"
#include <stdexcept>

/**
 * @brief Constructor for messageIterator
 * @param room Pointer to the ChatRoom to iterate over
 * @throws std::runtime_error if room is NULL or has no users
 */
messageIterator::messageIterator(ChatRoom *room) : Iterator(room) {
    if (room != NULL) {//
        ChatUsers = room->getUsers();
        if (!ChatUsers.empty()) {
            currentIndex = 0;
            this->current = ChatUsers[currentIndex];
        } else {
            throw std::runtime_error("NO CHAT USERS FOUND");
        }
    } else {
        throw std::runtime_error("NULL PASSED TO ITERATOR");
    }
}

messageIterator::~messageIterator() {}

/**
 * @brief Reset iterator to the first user
 * @throws std::runtime_error if no users are available
 */
void messageIterator::first() {
    if (!ChatUsers.empty()) {
        currentIndex = 0;
        this->current = ChatUsers[currentIndex];
    } else {
        throw std::runtime_error("NO CHAT HISTORY FOUND");
    }
}

/**
 * @brief Move iterator to the next user
 * 
 * Only advances if hasNext() returns true
 */
void messageIterator::next() {
    if (hasNext()) {
        this->current = ChatUsers[++currentIndex];
    }
}

/**
 * @brief Check if there are more users to iterate over
 * @return true if there are more users, false otherwise
 */
bool messageIterator::hasNext() {
    return currentIndex < ChatUsers.size() - 1;
}

/**
 * @brief Get the name of the current user
 * @return Name of the current user, or empty string if current is NULL
 */
std::string messageIterator::curr() {
    if (current != NULL) {
        return current->getName();
    } else {
        return "";
    }
}