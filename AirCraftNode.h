/*
*CLASS: AirCraftNode.h

*AUTHOR: Simi Adeniyi

*REMARKS: This is a NodeClass type that specifically stores planes waiting for a runway.
                    All nodes in the WaitList are of this type (dynamic type)
*/

#pragma once

#include "NodeClass.h"

#include "Plane.h"

class AirCraftNode : public NodeClass
{

    private:
        Plane* airCraft;
        
    public:
        //constructors
        AirCraftNode();
        AirCraftNode(Plane*, NodeClass*); //plane it stores, next node in the list

        //Allocated memory to create the planes stored in the node. Delete
        ~AirCraftNode() override;

        //Instance Methods
        
        //Print uses the method from plane's class
        void print() override;

        //returns the plane stored
        Plane* getItem();

};