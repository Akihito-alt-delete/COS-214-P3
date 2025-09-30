#ifndef CHATITERATOR_H
#define CHATITERATOR_H
#include "iterator.h"
class chatIterator: public Iterator{
    public:
        chatIterator(ChatRoom* room);
        virtual ~chatIterator();
        void first();
        void next();
        bool hasNext();
        std::string curr();
    private:
        vector<string> chatHistory;
        size_t currentIndex;
        std::string current;
};

#endif