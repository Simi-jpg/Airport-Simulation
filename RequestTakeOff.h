/*
*CLASS: RequestakeOff.h

*AUTHOR: Simi Adeniyi

*REMARKS: Created if the request type read in from the file is takeOff. 
                    The class checks available runway and either creates a takeOff event or
                    adds the plane to the waitList. takeOff takes lower priority in waiting.
*/

#pragma once
#include "TakeOff.h"

class RequestTakeOff : public Event {
    
    public:

    //Constructor
        RequestTakeOff();
        RequestTakeOff(Plane*, int);

        //Destrusctor
        ~RequestTakeOff() override;

        //Instance method

        /**
         * The purpose of this method is to check if there is an available runway to process this request immediately.
         * If there is an available runway, a takeOff event is immediately created.
         * If not, this method adds the plane to the waitlist. Note that takeOff requests have lower priority and the waitlist class
         *      takes care of that.
         * Once a request has been processed, the next line of the file is immediately read in and added to the queue
         * 
         * Takes in a simulation parameter to track status of the airport
         */
        void processEvent(Simulation*) override;

        void print();
};