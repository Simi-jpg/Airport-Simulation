#include "HeavyPlane.h"

#include <iostream>

HeavyPlane:: HeavyPlane() : Plane() {}

HeavyPlane:: HeavyPlane( string name, string flightNum): Plane(name, flightNum) {
}

HeavyPlane:: ~HeavyPlane()
{
}

//Methods
int HeavyPlane::getWakeTurbulence() {

    return TURB;
}

