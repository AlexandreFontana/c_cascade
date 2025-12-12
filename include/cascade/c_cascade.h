#include <cascade/detail/visibility.hpp>

#ifdef __cplusplus

#include <cascade/sim.hpp>
extern "C" {

#endif 

CASCADE_DLL_PUBLIC void printSmile();

CASCADE_DLL_PUBLIC void* initSim();

CASCADE_DLL_PUBLIC void* initSimArgs(double state[], int state_length, float ct);

CASCADE_DLL_PUBLIC unsigned long getNParts(void* simPointer);

CASCADE_DLL_PUBLIC int getSimTime(void* simPointer);

CASCADE_DLL_PUBLIC void simStep(void* simPointer);

#ifdef __cplusplus
}
#endif