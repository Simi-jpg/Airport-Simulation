#include "AirCraftNode.h"
#include <iostream>

using namespace std;

//Constructor
AirCraftNode:: AirCraftNode() : airCraft(nullptr) {}
AirCraftNode::AirCraftNode(Plane* p, NodeClass* n) : airCraft(p), NodeClass(n) {}

AirCraftNode::~AirCraftNode()
{
    delete airCraft;
    airCraft = nullptr;
}

//Methods
Plane* AirCraftNode::getItem()
{

    return airCraft;
}

void AirCraftNode :: print() {

    airCraft->print(); 
}