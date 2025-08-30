#include "TakeOff.h"
#include "Simulation.h"

TakeOff::TakeOff() {}

TakeOff::TakeOff(Plane *p, int time) : Event(p, time) {
}

TakeOff::~TakeOff()
{
    //destroy plane
    // Event:: ~Event();

}

void TakeOff::processEvent(Simulation* sim)
{

    print(); //print the landing message

 /**change the event time before creating a completed event. Updated time accounts for wake 
        turbulence, current event time and the time it takes to complete landing (2 minutes)
    */ 
        this->setEventTime(this->getEventTime() + this->getPlane()->getWakeTurbulence() + TAKE_OFF_TIME); 

    //create a new completed event and add it to the queue
        Event* newEvent = new Completed(this->getPlane(), this->getEventTime());

        if(newEvent != nullptr)  {

            sim->scheduleEvent(newEvent); //add to queue
        }


}

//Refinement using event's print and adding to it
void TakeOff::print()
{
       Event::print();
        printf(" cleared for takeoff on runway %d. (time req. for takeoff: %d)\n",this->getPlane()->getRunwayId(), this->getPlane()->getWakeTurbulence() + TAKE_OFF_TIME ); //add run way id
}
