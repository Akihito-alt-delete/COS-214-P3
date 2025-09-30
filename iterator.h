#ifndef ITERATOR_H
#define ITERATOR_H

#include "ChatRoom.h"
class Iterator{
    public:
    Iterator(ChatRoom* room);
    virtual ~Iterator();
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual std::string curr() = 0;

    protected:
    ChatRoom* room;
    
};
#endif