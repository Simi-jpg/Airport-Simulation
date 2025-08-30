#include "RequestLanding.h"
#include "Simulation.h"
#include <iostream>

using namespace std;

//Constructors
RequestLanding::RequestLanding() {}


RequestLanding:: RequestLanding(Plane * plane, int time): Event(plane, time) {}

//Destructor
RequestLanding::~RequestLanding()
{
    // Event:: ~Event();

}


//Instance methods
void RequestLanding::processEvent(Simulation* sim)
{

    print(); // print output message


    //Check if there are runways. Retuns the runway if its status is free or nullptr if no available runway
    RunWay* availableRunway = sim->getAvailableRunway();

    if(availableRunway) {

       this->getPlane()->setRunwayId(availableRunway->getId()); //set the plane to use this runway
      
        //create a landing event immediately since a runway was available. 
        Event* newLanding = new Landing(this->getPlane(), this->getEventTime());  

        //add to queue
        sim->scheduleEvent(newLanding);

        //update the runway status to occupied (true)
        availableRunway->setStatus(true);

        
    } else {

        //Add to the waitlist since runway was not available
        sim->joinWaitList(this->getPlane());
        // sim->updateTimeWasted(this->getEventTime());
        
    }

}

//Refinement using event's print and adding to it
void RequestLanding::print()
{
       Event::print();
        printf(" inbound for landing\n");
}
