/*
*CLASS: SuperPlane.h

*AUTHOR: Simi Adeniyi

*REMARKS:  Super plane is a subclass (type) of plane. It's wake turbulence is a constant 3 minutes
*/

#pragma once

#include "Plane.h"
using namespace std;

class SuperPlane: public Plane {

    private:
        const int TURB = 3;
        
    public:

        //Contructor
        SuperPlane(); //null constructor
        SuperPlane( string, string); //name and flight number

        //Destructor
        ~SuperPlane();

        //Instance Methods
        int getWakeTurbulence() override;
};