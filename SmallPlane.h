/*
*CLASS: SmallPlane.h

*AUTHOR: Simi Adeniyi

*REMARKS:  Small plane is a subclass (type) of plane. It's wake turbulence is a constant 0 minute
*/

#pragma once

#include "Plane.h"
using namespace std;

class SmallPlane: public Plane {

    private:
        const int TURB = 0;
    public:

        //Contructor
        SmallPlane(); //null constructor
        SmallPlane( string, string); //name and flight number

        //Destructor
        ~SmallPlane();

        //Instance Methods
        int getWakeTurbulence() override;
};