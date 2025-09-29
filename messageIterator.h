#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H
#include "iterator.h"
#include "Users.h"
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