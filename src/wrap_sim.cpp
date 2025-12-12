#include <vector>
#include <array>
#include <list>
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

    outcome propogate_until(void* simPointer, float t) {
        cascade::sim* temp = static_cast<cascade::sim*>(simPointer);
        return temp->propagate_until(t);
    }

    void remove_particles(void* simPointer, size_t indices[], int indices_length) {
        cascade::sim* temp = static_cast<cascade::sim*>(simPointer);
        std::vector<size_t> indicesVec(indices, indices + indices_length);
        
        temp->remove_particles(indicesVec);
    }

    unsigned long get_nparts(void* simPointer) {
        cascade::sim* temp = static_cast<cascade::sim*>(simPointer);
        return temp->get_nparts();
    } 

    double getSimTime(void* simPointer) {
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