#include <vector>
#include <cascade/c_cascade.h>
#include <cascade/sim.hpp>

extern "C" {

    /**
     * @brief initialize a sim object without parameters
     * 
     * @return a pointer to the sim object
     */
    void* initSim() {
        cascade::sim *newSim = new cascade::sim();

        return newSim;
    }
   
    /**
     * @brief initialize a sim object with parameters
     * 
     * @param state particles in state in format
     *              {p1.x, p1.y, p1.z, p1.vx, p1.vy, p1.vz, p1.size,
     *               p2.x, p2.y, p2.z ... }
     * 
     * @param state_length length of state array. Must be multiple of 7
     * 
     * @return pointer to the sim object
     */
    void* initSimArgs(double state[], int state_length, float ct) {
        
        std::vector<double> stateV(state, state + state_length);
        
        cascade::sim *newSim = new cascade::sim(stateV, ct);

        return newSim;
    }

    unsigned long getNParts(void* simPointer) {
        cascade::sim* temp = static_cast<cascade::sim*>(simPointer);
        return temp->get_nparts();
    } 

    int getSimTime(void* simPointer) {
        cascade::sim* temp = static_cast<cascade::sim*>(simPointer);
        return temp->get_time();
    }

    void simStep(void* simPointer) {
        cascade::sim* temp = static_cast<cascade::sim*>(simPointer);
        temp->step();
    }
    
    
    void printSmile(){
        std::cout << "\n" << ":):):):):):):):):):):):):):):):):) yes" << "\n";
        std::cout << "THIS WAS WRITTEN IN C++";
        cascade::sim testSim;
        std::cout << testSim.get_time() << "\n";
    }
}