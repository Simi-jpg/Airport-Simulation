/*
*CLASS: LargePlane.h

*AUTHOR: Simi Adeniyi

*REMARKS: Large plane is a subclass (type) of plane. It's wake turbulence is a constant 1 minute
*/

#pragma once

#include "Plane.h"
using namespace std;

class LargePlane: public Plane {

    private: 
    const int TURB = 1;

    public:

        //Contructor
        LargePlane(); //null constructor
        LargePlane( string, string); //name and flight number

        //Destructor
        ~LargePlane();

        //Instance Methods
        int getWakeTurbulence() override;
};