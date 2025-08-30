/*
*CLASS: Simulation.h

*AUTHOR: Simi Adeniyi

*REMARKS: This is a simulation of the airport where the events take place. It handles the queues and
                    waitlist, checking for runways and reading the input file.
*/

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

#include "RunWay.h"
#include "WaitList.h"
#include "EventQueue.h"
#include "AirCraftNode.h"

#include "SmallPlane.h"
#include "LargePlane.h"
#include "SuperPlane.h"
#include "HeavyPlane.h"

#include "RequestLanding.h"
#include "RequestTakeOff.h"

class Plane;
class Event;

using namespace std;


class Simulation { 

    private:

        ifstream inputFile; //variable for reading file
        int numRunways; //from the command line
        RunWay** runways; //an array of runways
        LinkedList* waitList; //where planes wait in line for arunway
        LinkedList* queue; //the priority queue for events
        int numPlanes; //increments by one each time a plane is created
        int timeWasted;  //tracks the time wasted when planes are in the waiting list. Calculated as the time the event starts - the plane's request time

    public:
    
      //Constructors & destructor
        Simulation();
        Simulation(string, int); //filename, number of runways
        ~Simulation();

      //Returns a runway at an index whose status is free (false) or nullptr if no runway
        RunWay* getAvailableRunway();

        //Adds an event (the argument) to the priority queue
        void scheduleEvent(Event* );

        //adds a plane (the argument) to a waitlist
        void joinWaitList(Plane* );

        //updates the amount of time a plane spends in the waitlist. Takes in an int which is the wasted time
        void updateTimeWasted(int);

        //removes and returns the top plane in the waitlist
        AirCraftNode* getNextInLine();

        //takes in an int that represents the runway id and sets its occupancy to false
        void freeRunway(int);

        //takes in an int that represents the runway id and sets its occupancy to true
        void occupyRunway(int);

      //responsible for reading in the file line by line, creating a plane and event and adding the event to queue
      void readNextEvent();

      //runs the events in the queue and calls readNextEvent when we process a request
        void run();

};