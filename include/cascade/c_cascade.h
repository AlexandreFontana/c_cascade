#include <cascade/detail/visibility.hpp>

#ifdef __cplusplus
    #include <cascade/sim.hpp>
    extern "C" {
#endif

#ifndef __cplusplus
   enum outcome { success, time_limit, collision, reentry, exit, err_nf_state }; 
#endif

CASCADE_DLL_PUBLIC void printSmile();

CASCADE_DLL_PUBLIC void* initSim();

CASCADE_DLL_PUBLIC void* initSimArgs(double state[], int state_length, float ct);

CASCADE_DLL_PUBLIC enum outcome propogate_until(void* simPointer, float t);

CASCADE_DLL_PUBLIC unsigned long get_nparts(void* simPointer);

CASCADE_DLL_PUBLIC double getSimTime(void* simPointer);

CASCADE_DLL_PUBLIC void simStep(void* simPointer);

#ifdef __cplusplus
    }
#endif