/*
*CLASS: NodeClass.h

*AUTHOR: Simi Adeniyi

*REMARKS: The NodeClass serves as the parent class for the two node types stored in the linked lists.
                    AirCraftNode and EventNode are node types. They both store different items but have some common functionality as defined below.
                    This class is an abstract class.
*/

#pragma once
#include <iostream>

using namespace std;

class NodeClass
{

    private: 
        NodeClass* next;

    public:

        //Constructors & Destructor
        NodeClass();
        NodeClass(NodeClass*);
        
       virtual ~NodeClass() = 0;

        //Instance methods

        //Prints the information of each item in the node by calling the item's print function.
        virtual void print() = 0;

        NodeClass* getNext();

        void setNext(NodeClass*);
};