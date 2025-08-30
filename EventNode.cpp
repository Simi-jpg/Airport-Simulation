#include "EventNode.h"
#include <iostream>

using namespace std;

//Constructor
EventNode::EventNode() : event(nullptr) {}

EventNode::EventNode(Event* e, EventNode* n) : event(e),  NodeClass(n) {}

//Destructor
EventNode:: ~EventNode() {

    delete event;
    event = nullptr;
}

//Methods
Event* EventNode::getItem()
{

    return event;
}


void EventNode :: print() {

    event->print(); 
}