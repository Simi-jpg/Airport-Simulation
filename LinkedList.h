/*
*CLASS: LinkedList.h

*AUTHOR: Simi Adeniyi

*REMARKS: A generic linked list that defines the base behaviour for any type of linked list class
                    Subtypes are WaitList and EventQueue. Linked lists are only of these two types, hence, 
                    this is an abstract class
*/

#pragma once

#include "NodeClass.h"

class LinkedList
{
    private: 
        NodeClass* top;
    public:

    //Constructor & Destructor
    LinkedList();
    virtual ~LinkedList() = 0;

        //Methods
        NodeClass* getTop();
        void setTop( NodeClass*);

        NodeClass* removeTop();
        
        //checks if the list is empty (if top is null)
        bool isEmpty();
};