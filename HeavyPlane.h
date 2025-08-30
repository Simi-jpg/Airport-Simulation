/*
*CLASS: HeavyPlane.h

*AUTHOR: Simi Adeniyi

*REMARKS: Heavy plane is a subclass (type) of plane. It's wake turbulence is a constant 2 minutes
*/

#pragma once

#include "Plane.h"
using namespace std;
class HeavyPlane: public Plane {

    private:
        const int TURB = 2;
    public:

        //Contructor
        HeavyPlane(); //null constructor
        HeavyPlane( string, string); //name and flight number

        //Destructor
        ~HeavyPlane();

        //Instance Methods
        int getWakeTurbulence() override;
};