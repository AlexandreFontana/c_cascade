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

CASCADE_DLL_PUBLIC void remove_particles(void* simPointer, size_t indices[], int indices_length);

CASCADE_DLL_PUBLIC void reset_conjunctions(void* simPointer);

CASCADE_DLL_PUBLIC void set_new_state_pars(void* simPointer, double newState[], int newState_length, 
                                            double new_pars, int new_pars_length);

CASCADE_DLL_PUBLIC void step(void* simPointer);

CASCADE_DLL_PUBLIC int get_size_coll_whitelist(void* simPointer);

CASCADE_DLL_PUBLIC void get_coll_whitelist(void* simPointer, size_t *list);

CASCADE_DLL_PUBLIC unsigned long get_nparts(void* simPointer);

CASCADE_DLL_PUBLIC double getSimTime(void* simPointer);



#ifdef __cplusplus
    }
#endif