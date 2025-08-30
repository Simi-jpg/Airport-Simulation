#include "WaitList.h"
#include "AirCraftNode.h"

#include <iostream>
using namespace std;

//Constructor
WaitList::WaitList() : LinkedList() {
}

WaitList::~WaitList()
{

    NodeClass* curr = this->getTop();

    while (curr != nullptr) {

        NodeClass* next = curr->getNext();

        delete curr;
        curr = next;
    }

    this->setTop(nullptr);
    tail = nullptr;
}


void WaitList:: addAtPos(Plane* newCraft) {
      NodeClass* newPlaneNode = new AirCraftNode(newCraft, nullptr);

        if(this->getTop() == nullptr) {

            this->setTop(newPlaneNode);
            tail = newPlaneNode;

        } else {
                bool found = false;
               NodeClass* curr = this->getTop();
                AirCraftNode* prev = nullptr;

                while(!found) {

                    // if the new plane has a takeoff request, add staright at the end
                    if(newCraft ->getRequestType() == "takeoff") {

                                    tail->setNext(newPlaneNode);
                                    
                                    tail = newPlaneNode;
                                    found = true;
                    } else {
                        //find the postion
                        bool posFound = false;
                        while(curr != nullptr && !posFound) { // either we reach the end or we have found the correct pos for loop to end

                            AirCraftNode* currPlane = dynamic_cast <AirCraftNode*> (curr); //cast the current node

                            if(currPlane != nullptr) { //cast was successful

                                //we have reached the first takeoff request and need to insert between prev and curr
                                if(currPlane->getItem() -> getRequestType() == "takeoff") {

                                    posFound = true;

                                } else { //pass all landing events

                                      prev = currPlane;
                                      curr = curr->getNext();
                                }
                            }
                            
                        }

                        newPlaneNode->setNext(curr); //new node will point at the curr position

                        if(prev == nullptr) { //inserting at the first spot. Update top

                            this->setTop(newPlaneNode);

                        } else { //inserting in the middle of the list. Update prev's next

                            prev->setNext(newPlaneNode);
                        }

                        if(curr == nullptr) { //inserting at  the end. Need to update the tail pointer

                            tail = newPlaneNode;
                        }

                        found = true; //end outer while loop
                    }

                }

        }
}