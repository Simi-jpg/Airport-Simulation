#include "RequestTakeOff.h"
#include "Simulation.h"
#include <iostream>

using namespace std;

//Constructors
RequestTakeOff::RequestTakeOff()
{
}

RequestTakeOff::RequestTakeOff(Plane * plane, int time) : Event(plane, time) {}

//Destructor
RequestTakeOff::~RequestTakeOff()
{
    // Event:: ~Event();

}

//Instance variable
void RequestTakeOff::processEvent(Simulation* sim)
{

     print(); //print ouput message


    //Check if there are runways. Retuns the runway if its status is free or nullptr if no available runway
    RunWay* availableRunway = sim->getAvailableRunway(); //should return false if it is available

    if(availableRunway) {

       this->getPlane()->setRunwayId(availableRunway->getId());//set the plane to use this runway

        //create a takeoff event immediately since a runway was available. 
        Event* newTakeOff = new TakeOff(this->getPlane(), this->getEventTime());


        //add the takeOff event to the priority queue
        sim->scheduleEvent(newTakeOff);

        //update the runway status to occupied (true)
        availableRunway->setStatus(true);

    } else {

        //add to waitlist. No runway available
        sim->joinWaitList(this->getPlane());
        // sim->updateTimeWasted(this->getEventTime());
        
    }
    
}

//Refinement by using event's print and adding to it
void RequestTakeOff::print()
{

       Event::print();
       printf(" ready for takeoff\n");
}
