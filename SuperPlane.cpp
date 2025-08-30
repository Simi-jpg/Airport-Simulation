#include "SuperPlane.h"

#include <iostream>

SuperPlane:: SuperPlane() : Plane() {}

SuperPlane:: SuperPlane( string name, string flightNum): Plane(name, flightNum) {
}

SuperPlane:: ~SuperPlane()
{

}

//Methods
int SuperPlane::getWakeTurbulence() {

    return TURB;
}



