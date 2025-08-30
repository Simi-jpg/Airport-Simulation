/*
*CLASS: EventNode.h

*AUTHOR: Simi Adeniyi

*REMARKS: A subclass of NodeClass that holds event types as its data. 
                    The nodes are for events in the EventQueue. All nodes in the queue are of the EventNode type (dynamic type)

*/

#pragma once

#include "NodeClass.h"

#include "Event.h"

class EventNode : public NodeClass
{

    private:
        Event* event;
        
    public:
        //constructors
        EventNode();
        EventNode(Event*, EventNode*); //plane type

        ~EventNode() override;

        //Instance Methods
        void print() override;
 
        Event* getItem();

};