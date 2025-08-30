/*
*CLASS: TakeOff.h

*AUTHOR: Simi Adeniyi

*REMARKS: Created to process a landing request. The time it takes for planes to land (irrespective of size)
                   is a constant of 3 seconds. 
*/

#pragma once
#include "Completed.h"
#include <iostream>

using namespace std;

class TakeOff : public Event { 

        private: 
            const int TAKE_OFF_TIME = 1;

        public:

        TakeOff();
        TakeOff(Plane*, int);
        ~TakeOff() override;
        
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