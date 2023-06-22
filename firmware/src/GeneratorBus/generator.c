#define _GENERATOR_C

#include "application.h"
#include "generator.h"
#include "Protocol/protocol.h"


static bool uc_HV_ON_back = false; //!< This is used to detect the signal status change
static bool Generator_HV_ON_status = false; //!< This is the current gen_hv_on status 


/**
 *  This function initializes the module
 */
void GeneratorInit(void){
    
    // Clear the outputs
    uc_XRAY_ENA_Clear();    
         
}

/**
 * This function shall be called into the Application main loop 
 * to handle the module activities.
 */
void GeneratorLoop(void){

    // Direct BusHw to PROTOCOL STATUS REGISTER Input handling
    if(uc_HV_ON_back != uc_HV_ON_Get()){
        uc_HV_ON_back = uc_HV_ON_Get();
    }else{
        Generator_HV_ON_status = uc_HV_ON_back;
    }
    
    
    // XRAY Ena status from the Master
    if(TESTBIT_PROTOCOL_XRAY_ENA_OUT) uc_XRAY_ENA_Set();
    else uc_XRAY_ENA_Clear();    
 
}

/**
 * This function returns the current GEN_HV_ON signal status
 * @return status of the gen_hv_on input signal
 */
bool inline GeneratorGetHvOn(void){
    return Generator_HV_ON_status;
}