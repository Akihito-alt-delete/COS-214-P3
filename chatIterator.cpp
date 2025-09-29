#include "chatIterator.h"
#include <vector>
chatIterator::chatIterator(ChatRoom *room):Iterator(room){
    if(room != NULL){
        chatHistory = room->getChatHistory();
        currentIndex = 0;
        this->current = chatHistory[currentIndex];
    }else{
        throw std::runtime_error("NULL PASSED TO ITERATOR");
    }
    
    
}

chatIterator::~chatIterator(){

}

void chatIterator::first(){
    if(!chatHistory.empty()){
        currentIndex = 0;
        this->current = chatHistory[currentIndex];
    }else{
        throw std::runtime_error("NO CHAT HISTORY FOUND");
    }
}



void chatIterator::next(){
    if(hasNext()){
        this->current = chatHistory[++currentIndex];
    }
}

bool chatIterator::hasNext(){
    return (currentIndex < chatHistory.size() - 1) && currentIndex >= 0;
}

std::string chatIterator::curr(){
    if(currentIndex >= 0 && currentIndex < chatHistory.size()){
        return chatHistory[currentIndex];
    }else{
        return "";
    }
}
