#include "SmallPlane.h"

#include <iostream>

SmallPlane:: SmallPlane() : Plane() {}

SmallPlane:: SmallPlane( string name, string flightNum): Plane(name, flightNum) {}

SmallPlane:: ~SmallPlane()
{

}

//Methods
int SmallPlane ::getWakeTurbulence() {

    return TURB;
}


