#include "LinkedList.h"

LinkedList::LinkedList() : top(nullptr){}

LinkedList::~LinkedList()
{
}

NodeClass *LinkedList::getTop()
{
    return top;
}

void LinkedList::setTop(NodeClass * newTop)
{
    top = newTop;
}

NodeClass *LinkedList::removeTop()
{

     if(top != nullptr) { //there is still a node in the list

       NodeClass* nextInLine = top;

        top = top->getNext();

    return nextInLine;

    }
    return nullptr;
}

bool LinkedList::isEmpty()
{
    return top == nullptr;
}
