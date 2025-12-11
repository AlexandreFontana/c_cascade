#include <cascade/c_cascade.h>
#include <cascade/sim.hpp>

extern "C" {
    
    void printSmile(){
        std::cout << "\n" << ":):):):):):):):):):):):):):):):):) yes" << "\n";
        std::cout << "THIS WAS WRITTEN IN C++";
        cascade::sim testSim;
        std::cout << testSim.get_time() << "\n";
    }
}