/*
*CLASS: Event.h

*AUTHOR: Simi Adeniyi

*REMARKS: An event is either a requestLanding, requestTakeOff, Landing, TakeOff or Completed.
                    This is an abstract class that defines common event type charecteristics shared by the subclasses. 
*/

#pragma once
#include "Plane.h"

class Simulation;

#include <iostream>

using namespace std;


class Event {

    private: 
        
        Plane* plane; 
        int eventTime; //time each event starts i.e when the plane hits the runway or when a request is made. 

    public:

        /**
         * The purpose of this class is to process the event types based on the status of the simulation.compareEvent
         * All events need to track simulation's data to know how to process their event type
         * 
         * Takes in a simulation parameter and uses its attibute to carry out a behaviour
         */
        virtual void processEvent(Simulation*) = 0; //inherited by the sub classes 

        //Constructors & Destructor
        Event();
        Event(Plane*, int); //takes in the plane we are pocessing, and the current time
        virtual ~Event();

        //Instance methods
        int getEventTime();
        void setEventTime(int);

        Plane* getPlane();

        /*Compares events based on their eventTime and adds them to the event prioity queue. 
        In the case that two events have the same event time, we pick the event whose plane has lower atcId using
        plane's compare function

        Takes an event parameter

        Returns an int. -1 if the argument is smaller. 1 if the argument is larger
        */
        int compareEvent(Event*);

        void print();
};