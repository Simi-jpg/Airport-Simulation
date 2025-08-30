#include "NodeClass.h"

NodeClass::NodeClass() {}

NodeClass::NodeClass(NodeClass * n) : next(n)
{
}

NodeClass::~NodeClass()
{
}

NodeClass *NodeClass::getNext()
{
    return next;
}

void NodeClass::setNext(NodeClass * newNext)
{
    next = newNext;   
}
