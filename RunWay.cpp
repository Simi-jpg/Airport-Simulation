#include "RunWay.h"

#include <iostream>

using namespace std;

RunWay:: RunWay()   {

    isOccupied = false;
}

//Destructor
RunWay:: ~RunWay() {

}


//Instance methods
void RunWay:: setStatus(bool currStatus) {

    isOccupied = currStatus;
}

bool RunWay:: getStatus() {

    return isOccupied;
}


void RunWay::setRunWayId(int id)
{
    runWayId = id;
}

int RunWay::getId()
{
    return runWayId;
}

void RunWay::print()
{
    printf(" on runway %d" , runWayId);
}
