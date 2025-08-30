#include "EventQueue.h"
#include "EventNode.h"

#include <iostream>
using namespace std;

//Constructor
EventQueue::EventQueue() : LinkedList() {}

//Destructor
EventQueue::~EventQueue()
{

    NodeClass* curr = this->getTop();

    while (curr != nullptr) {

        NodeClass* next = curr->getNext();

        delete curr;
        curr = next;
    }

    this->setTop(nullptr);
}

//Methods

void EventQueue::addAtPos(Event* newEvent) {

    //create a new node with the event 
    NodeClass* newEventNode = new EventNode(newEvent, nullptr);

        //if the list is empty, we just add at the top
        if(this->getTop() == nullptr) {

            this->setTop(newEventNode);

        } else {
            //cast the top item in the list and use prev to keep track of the previous node.
            EventNode* currEvent = dynamic_cast<EventNode*> (this->getTop());
            EventNode* prev = nullptr; //prev does not need casting because it is assigned currEvent which has been cast already


            //the new event's time is higher so we keep moving to the next node
            while(currEvent != nullptr && newEvent->compareEvent(currEvent->getItem()) > 0) {

                prev = currEvent;
                currEvent = dynamic_cast <EventNode*> (currEvent->getNext());
            }


           
            if(prev == nullptr) {  //Inserting at the beginning. Update top

                newEventNode->setNext(this->getTop());
                this->setTop(newEventNode);

            } else if (currEvent == nullptr) { //inserting at the end

                prev->setNext(newEventNode);

            } else { //inserting in the middle

                newEventNode->setNext(currEvent);
                prev->setNext(newEventNode);

            }
        }
        
    
}
