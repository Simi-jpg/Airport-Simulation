#include "Plane.h"

//Constructor
Plane:: Plane()  {}

Plane:: Plane(string name, string flightNum) : callSign(name), flightNumber(flightNum) {}

Plane::~Plane()
{
}

//Instance Methods
int Plane::getAtcId() {

    return atcId;
}

void Plane:: setAtcId(int iDNum) {

    atcId = iDNum;
}

string Plane::getCallSign()
{
    return callSign;
}

string Plane::getSize()
{
    return size;
}

void Plane::setSize(string size)
{
    this->size = size;
}

string Plane:: getFlightNum() {

    return flightNumber;
}

void Plane:: setFlightNum(string flightNum) {

    flightNumber = flightNum;
}

int Plane::getReqTime()
{
    return reqTime;
}

void Plane::setReqTime(int time)
{
    reqTime = time;
}

string Plane::getRequestType()
{
    return requestType;
}

void Plane::setRequestType(string request)
{
    requestType = request;
}

int Plane::getRunwayId()
{
    return runwayId;
}

void Plane::setRunwayId(int id)
{
    runwayId = id;
}

//returns 1 if the argument has a higher atcId and -1 if otherwise
int Plane:: compare(Plane* other) {

 int comp = 0;

    if((this->atcId) < (other->atcId)) { //argument has higher atcId so it comes after

        comp = -1;

    } else if((this->atcId > other->atcId)) { //argument has lower atcId so it comes before

        comp = 1;
    }

    return comp;
}


void Plane:: print() {

    cout<< "CallSign: " << callSign << ". Flight Number: " << flightNumber <<  ". ATCID: " << atcId << "\n";
}
