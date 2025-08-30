/*
*CLASS: Landing.h

*AUTHOR: Simi Adeniyi

*REMARKS: Created to process a landing request. The time it takes for planes to land (irrespective of size)
                   is a constant of 3 minutes. 
*/

#pragma once
#include "Event.h"
#include "Completed.h"
#include <iostream>

class Landing : public Event {

    private:
            const int LAND_TIME = 3;  //every plane needs 3 seconds to land

    public:

        Landing();
        Landing(Plane*, int);

        ~Landing() override;
        
        /**
         * The purpose of this method is to create a landing event with the updated event time.
         * The updated time depends on how much time has passed while the plane was in the waitlist (if there was
         * no available runway)
         * Once a request has been processed, the next line of the file is immediately read in and added to the queue
         * 
         * Takes in a simulation parameter to track status of the airport
         */
        void processEvent(Simulation*) override;

        void print();
};