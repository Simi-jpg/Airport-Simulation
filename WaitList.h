/*
*CLASS: WaitList.h

*AUTHOR: Simi Adeniyi

*REMARKS: This wailtist holds the planes who have made request but there are no available 
                    runways. The list adds in planes at the back of the queue
*/

#pragma once
#include "LinkedList.h"

class Plane;

class WaitList : public LinkedList
{

    private:
        NodeClass* tail;

    public:
        //Constructors & Destructor
        WaitList();
        ~WaitList() override;

        //Instance Methods

        /**
         * Adds planes into the a waiting list while they await a free runway. Since landing events
         * have higher priority, the planes are added with landing coming first, then takeoffs at the end
         * of the list
         * 
         * Parameter: Takes in a plane argument and creates a node with it, then adds it at the end of 
         * list
         */
        void addAtPos(Plane* );
};