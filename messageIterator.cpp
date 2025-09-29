#include "messageIterator.h"
#include <stdexcept>

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

void messageIterator::first() {
    if (!ChatUsers.empty()) {
        currentIndex = 0;
        this->current = ChatUsers[currentIndex];
    } else {
        throw std::runtime_error("NO CHAT HISTORY FOUND");
    }
}

void messageIterator::next() {
    if (hasNext()) {
        this->current = ChatUsers[++currentIndex];
    }
}

bool messageIterator::hasNext() {
    return currentIndex < ChatUsers.size() - 1;
}

std::string messageIterator::curr() {
    if (current != NULL) {
        return current->getName();
    } else {
        return "";
    }
}
