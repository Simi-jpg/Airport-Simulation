/**
 * NAME: SIMI ADENIYI
 * 
 */

#include "Simulation.h"
using namespace std;

int main(int argc, char* argv[]) {

    if(argc != 3) {

        cout << "Incorrect format";

        
    } else {

        string fileName = argv[1];

        int numRunWays = stoi(argv[2]);

        Simulation *sim = new Simulation(fileName, numRunWays);


        sim->run();

        cout << "\n\nPROGRAM ENDED SUCCESSFULLY\n" << endl;


        delete sim;
    }

return 0;

}

