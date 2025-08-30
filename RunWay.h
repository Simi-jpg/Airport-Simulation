/*
*CLASS: RunWay.h

*AUTHOR: Simi Adeniyi

*REMARKS: Creates a runway instance to represent where the events will take place
                    Runways have to be available before an event can occur
*/

#pragma once

class RunWay {

    private:
        bool isOccupied; //will be false anytime a runway is created
        int runWayId;  //position in the array + 1

    public:

    RunWay(); //null constructor

    ~RunWay(); //destructor

    //status represents whether a plane is free or occupied
    void setStatus(bool);
    bool getStatus();

    //Runway id is the position in the array + 1
    void setRunWayId(int);
    int getId();

    //prints the runway id
    void print();
};