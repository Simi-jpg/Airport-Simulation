/*
*CLASS: Plane.h

*AUTHOR: Simi Adeniyi

*REMARKS: A Plane can either be Small, Large, Heavy or Super. These four sizes determine how long the wake turbulence of each plane is.
                   This class is the parent for the four subtypes. It defines each plane's charecteristics, getters and setters and a print function.
                   It is an abstract class
*/

#pragma once

#include <iostream>
using namespace std;

class Plane
{
    private:
        string callSign; //the plane name
        string flightNumber; 
        int atcId; //id number for each plane. Allocated when a plane is created. 
        int reqTime; //time the plane requested for runway service
        string size; //the four size type of a plane. 
        string requestType; //either takeoff or landing
        int runwayId; //the runway the plane is using
        
    public:

        virtual int getWakeTurbulence() = 0; //pure virtual method that returns the wake turbulence

        //Constructors & Destructor

        Plane(); //null constructor
        Plane(string, string); //callSign and flightNum

        virtual ~Plane(); //destructor


        //Instance Methods
        
        //The plane's id num (increments by one each time a new plane is created)
        int getAtcId(); 
        void setAtcId(int);

        //the plane's name. 
        string getCallSign();
        string getSize();

        //The subtypes of planes. Either small, large, heavy or super
        void setSize(string);

        //flight num of each plane
        string getFlightNum();
        void setFlightNum (string );

        //the time a plane makes a request for a runway
        int getReqTime();
        void setReqTime(int);

        //the type of request a plane makes. Eithe takeoff or landing
        string getRequestType();
        void setRequestType(string);

        //the runway a plane uses
        int getRunwayId();
        void setRunwayId(int);

        /**Compares planes by atc Id. Lower atc Id comes first in the queue
         * 
         * Takes in a plane paramete and uses it's atcId to compare planes
        */
        int compare(Plane *);
        //print a plane's info:  callsign, flighNum, atcId
        void print();

};
