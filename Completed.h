/*
*CLASS: Completed.h

*AUTHOR: Simi Adeniyi

*REMARKS: This class represents an event that is completed. An instance is created in a takeoff 
                    or landing class which updates the time it needs to complete an event depending on 
                    the request type and plane size. 
*/

#pragma once
#include "Event.h"
#include "TakeOff.h"
#include "Landing.h"
#include "AirCraftNode.h"

#include <iostream>

using namespace std;

class Completed : public Event {

    public:

    //Constructors & Destructor
        Completed();
        Completed(Plane*, int);
        ~Completed() override;

        //Instance Method

        /**
         * Processes a completed event when it comes up first in the priority queue
         * Takes in a simulation to access its behaviour and perform behaviors to change 
         * runway status and get the next event from the waiting list
         */
        void processEvent(Simulation*) override;

        //Print out the appropriate message by refining event's orint and adding unto it
        void print();
};