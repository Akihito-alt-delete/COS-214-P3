#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H
#include "iterator.h"
#include "Users.h"

/**
 * @class messageIterator
 * @brief Iterator for traversing through users in a chat room
 * 
 * Implements the Iterator pattern to provide sequential access
 * to users in a chat room without exposing the underlying representation.
 */
class messageIterator: public Iterator{
    public:
        messageIterator(ChatRoom* room);
        ~messageIterator();
        void first();
        void next();
        bool hasNext();
        std::string curr();
    private:
        vector<Users*> ChatUsers;
        size_t currentIndex;
        Users* current;
};

#endif