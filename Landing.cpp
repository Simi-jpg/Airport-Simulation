#include "Landing.h"
#include "Simulation.h"

Landing::Landing()
{
    // print();
}

Landing::Landing(Plane *plane, int time) : Event(plane, time)
{
}

Landing::~Landing()
{
    // Event:: ~Event();

}

void Landing::processEvent(Simulation *sim)
{
    print(); //print the landing message


    /**change the event time before creating a completed event. Updated time accounts for wake 
        turbulence, current event time and the time it takes to complete landing (2 minutes)
    */ 
     this->setEventTime(this->getEventTime() + this->getPlane()->getWakeTurbulence() + LAND_TIME);

    //create a new completed event and add it to the queue
    Event* newEvent = new Completed(this->getPlane(), this->getEventTime());

    if(newEvent != nullptr) {

         sim->scheduleEvent(newEvent); //add to queue
    }

}

//Refinement using event's print and adding to it
void Landing::print()
{
 Event::print();
    printf(" cleared for landing on runway %d. (time req for landing: %d)\n", this->getPlane()->getRunwayId() , this->getPlane()->getWakeTurbulence() + LAND_TIME);
}
