#include "Event.h"


//Constructors
Event:: Event() : plane(nullptr) {}
Event:: Event(Plane* p, int time) : plane(p), eventTime(time) {}

//Destructor
Event:: ~Event() {
    
    
}

//Instance methods

int Event::getEventTime()
{
    return eventTime;
}

void Event::setEventTime(int time)
{
    eventTime = time;
}

Plane* Event:: getPlane()
{
    return plane;

}


int Event::compareEvent(Event * otherEvent)
{
    int comp = 0;

    if(this->eventTime < otherEvent->eventTime) { //then the otherEvent is bigger

        comp = -1;

    } else if(this->eventTime > otherEvent->eventTime) { //otherEvent is smaller

        comp = 1;
    } else { //equal event time

        if(this->plane->compare(otherEvent->plane) > 0) { //other plane has lower atcId so it is higher priority

            comp = 1;

        } else { //other event has higer atcId so it is lower priority (should come after)

            comp = -1;
        }
    }

    return comp; // 1 for a bigger argument. -1 for a smaller argument
}

void Event::print()
{

    printf("TIME: %d -> %s %s (%d) %s  " , eventTime, plane->getCallSign().c_str(), plane->getFlightNum().c_str(), plane->getAtcId(),  plane->getSize().c_str());
}
