/*
*CLASS: RequestLanding.h

*AUTHOR: Simi Adeniyi

*REMARKS: Created if the request type read in from the file is landing. 
                    The class checks available runway and either creates a landing event or
                    adds the plane to the waitList. Landing takes higher priority in waiting.
*/

#pragma once
#include "Event.h"
#include "Landing.h"

class RequestLanding : public Event {

    public:

    //Constructors & Destructor
        RequestLanding();
        RequestLanding(Plane*, int);

        ~RequestLanding();

        /**
         * The purpose of this method is to check if there is an available runway to process this request immediately.
         * If there is an available runway, a landing event is immediately created.
         * If not, this method adds the plane to the waitlist. Note that landing requests have higher priority and the waitlist class
         *      takes care of that.
         * Once a request has been processed, the next line of the file is immediately read in and added to the queue
         * 
         * Takes in a simulation parameter to track status of the airport
         */
        void processEvent(Simulation*) override;

        void print();
};