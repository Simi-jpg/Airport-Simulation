/*
*CLASS: EventQueue.h

*AUTHOR: Simi Adeniyi

*REMARKS: This priority queue is a subclass of the LinkedList class. It orders events based
                    on their event time, from lowest time to highest time.
*/

#pragma once

#include "Event.h"
#include "EventNode.h"
#include "LinkedList.h"

class EventQueue : public LinkedList
{
    public:
    
        //Constructor & Destructor
        EventQueue();
        ~EventQueue() override;

        //Methods

        /**
         * Sorts the events based on their event times, in ascending order.
         * 
         * Paremeter: Takes in an event argument and uses its compare method to find 
         *                     out where its position is in the queue
         */
        void addAtPos(Event* );

};