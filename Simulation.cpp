#include "Simulation.h"

Simulation::Simulation() {}

Simulation::Simulation(string fileName, int num) : numRunways(num)
{

    inputFile.open(fileName); //open file

    if(inputFile) { //if it is not nullptr

        runways = new RunWay*[numRunways]; //initialize the runways arrar and use loop to create runways at each index

        for (int i = 0; i < numRunways; i++) {

            RunWay* newRunway = new RunWay();
            runways[i] = newRunway;
            runways[i]->setRunWayId(i + 1);  //array index + 1 = runway id


        }

        waitList = new WaitList();

        queue = new EventQueue();

        numPlanes = 0; //initially no planes at the start of simulation

        timeWasted = 0; //track time spent in waiting list

    } else {

        cout << "Error opening the file: " << fileName << endl;
        
    }

}

Simulation::~Simulation()
{
    //loop through the array and delete each runway using runway's destructor

    inputFile.close();
    delete waitList;
    delete queue;

    for (int i = 0; i < numRunways; i ++) {

        delete runways[i];
    }

    delete runways;
}


RunWay *Simulation::getAvailableRunway()
{

    for (int i = 0; i < numRunways; i++) {

        if(!runways[i]->getStatus()) { //if the status is false, return the runway

            return runways[i];


        }
    } 
    return nullptr; //else return nullptr
}

void Simulation::scheduleEvent(Event * newEvent)
{
    //add the event to the queue

    EventQueue* castQueue = dynamic_cast <EventQueue*> (queue); //cast the queue to use addAtPos

    if(castQueue != nullptr) {

        castQueue->addAtPos(newEvent);
    }


}

void Simulation:: joinWaitList(Plane* newPlane) {

    WaitList* castQueue = dynamic_cast <WaitList*> (waitList); //cast the waitlist to use addAtPos

    if(castQueue != nullptr) {

        castQueue->addAtPos(newPlane);
    }
}

void Simulation::updateTimeWasted(int time)
{
    timeWasted += time;
}

AirCraftNode *Simulation::getNextInLine()
{
    AirCraftNode* next = dynamic_cast <AirCraftNode*> (waitList->getTop());

    if(next!= nullptr) { //not an empty list

        waitList->removeTop();

        return next;
    }

    return nullptr;
}

void Simulation::freeRunway(int id)
{
    runways[id-1]->setStatus(false);
}

void Simulation::occupyRunway(int id)
{
    runways[id-1]->setStatus(true);
}

void Simulation::readNextEvent()
{

        string line;
        
        if(getline(inputFile, line))  //gets the next line from the file and saves it in 'line', if there is one
        {

            stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
            string token;
            int time = 0;
            string callSign = "";
            string flightNum = "";
            string size = "";
            string requestType = "";
            
            sst >> token;  //grabbing the next token (reading time)
            time = stoi(token); //converting time (string format) to an int
            sst >> callSign;  //grabbing the next token (reading call sign)
            sst >> flightNum;  //grabbing the next token (reading flight number)
            sst >> size;  //grabbing the next token (reading plane size)
            sst >> requestType;  //grabbing the next token (reading request type, either landing or takeoff)


                //create the plane

                Plane* newPlane = nullptr;

                if (size == "super") {
                            
                    newPlane = new SuperPlane(callSign, flightNum);
                    
                } else if (size == "heavy") {

                    newPlane = new HeavyPlane(callSign, flightNum);
  
                } else if (size == "large") {

                    newPlane = new LargePlane(callSign, flightNum);

                } else if (size == "small") {

                    newPlane = new SmallPlane(callSign, flightNum);

                }

                //plane was successfully created
                if(newPlane != nullptr) {

                    //setting plane's attributes
                    newPlane->setSize(size);
                    newPlane->setReqTime(time);
                    newPlane->setAtcId(++numPlanes);
                    newPlane->setRequestType(requestType);

                }

            //create event
                Event* newEvent = nullptr;

                 if (requestType == "landing") {

                    newEvent = new RequestLanding(newPlane, time);


                } else if (requestType == "takeoff") {

                    newEvent = new RequestTakeOff(newPlane, time);
                    
                }


                //event was successfully created
                if(newEvent != nullptr) {

                    EventQueue* pQueue = dynamic_cast <EventQueue*> (queue);

                    if(pQueue != nullptr) {


                        pQueue->addAtPos(newEvent);
                    
                    }
                }

            }
 } 

void Simulation::run()
{

     cout << "Simulation begins...\n\n";

    readNextEvent(); //read in the first line

    while(!queue->isEmpty()) { //we will keep proccessing events until the queue is empty

        EventNode* toProcess = dynamic_cast <EventNode*> (queue->removeTop()); //will be an event since queue is not empty

   
        if(toProcess != nullptr) { //cast was successfule

            Event* nextEvent = toProcess->getItem(); //get the event to be processed

            if(nextEvent != nullptr) { //there was an actual event

                 nextEvent->processEvent(this);
            }
        
            //the next line of the file should be read ONLY when a request event has been processed
            if(dynamic_cast<RequestLanding*> (nextEvent) || dynamic_cast <RequestTakeOff*> (nextEvent)) {

                readNextEvent();
            }


        }
      
    }

    cout <<" \n\n\n#############################\n";

    cout << "The simulation has ended." << endl;
    cout << "The number of runways was " << numRunways << endl;

    //printing minutes in plural or singular form
    if(timeWasted >1) {

        cout << "The total amount of time wasted because runways were not available was " << timeWasted<<" minutes." << endl;
    } else {

        cout << "The total amount of time wasted because runways were not available was " << timeWasted<<" minute." << endl;

    }
    cout << "#############################\n";

}