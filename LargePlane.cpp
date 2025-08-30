#include "LargePlane.h"

#include <iostream>

LargePlane:: LargePlane() : Plane() {}

LargePlane:: LargePlane( string name, string flightNum): Plane(name, flightNum) {}

LargePlane:: ~LargePlane()
{

}

//Methods
int LargePlane ::getWakeTurbulence() {

    return TURB;
}



