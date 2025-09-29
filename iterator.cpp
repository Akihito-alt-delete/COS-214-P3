#include "iterator.h"

Iterator::Iterator(ChatRoom *room):room(room){
    current = "";
}

Iterator::~Iterator(){
};