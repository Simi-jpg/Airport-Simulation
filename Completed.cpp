#include "Completed.h"
#include "Simulation.h"

Completed::Completed()
{
}

Completed::Completed(Plane *p, int time) : Event(p, time) {}

Completed::~Completed()
{
    // Event:: ~Event();
}

void Completed:: processEvent(Simulation* sim) {

    //free the runway this event tookplace as it is complete now
    sim->freeRunway(this->getPlane() -> getRunwayId()); 

    //get the next event in the waitlist. Returns null if waitlist is empty
    AirCraftNode* next = sim->getNextInLine();

    if(next != nullptr) {
        //get the plane in the next node in wait list
        Plane* nextPlane = next->getItem();

        //this next plane will use the same runway as the completed event. 
        nextPlane->setRunwayId(this->getPlane()->getRunwayId());

        //calculated time wasted based on the difference from when the plane requested a runway to when it got a runway

        int wastedTime = this->getEventTime() - nextPlane->getReqTime();
        //add it to the total wasted time
        sim->updateTimeWasted(wastedTime);
        
        //Make a new event based on the request type and add to the queue
        //The starting event time will be the same as the completed event time
        Event* newEvent = nullptr;

        if(nextPlane->getRequestType() == "takeoff") {

            newEvent =  new TakeOff(nextPlane, this->getEventTime());

        } else if(nextPlane->getRequestType() == "landing") { 

            newEvent = new Landing(nextPlane, this->getEventTime());
        }

        //ensure a new event was created and add to the queue
        //Also ensure to change the runway status to occupied.
        if(newEvent != nullptr) {

            sim->scheduleEvent(newEvent);
            sim->occupyRunway(newEvent->getPlane()->getRunwayId());

        }
    }

    print(); //print the completed message
}
//Refinement using event's print and adding to it
void Completed:: print() {

    Event::print();
    printf("has cleared runway %d\n", this->getPlane()->getRunwayId());


}
