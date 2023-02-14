#define _GENERATOR_C

#include "application.h"
#include "generator.h"
#include "Protocol/protocol.h"


static bool uc_HV_ON_back = false;
static bool Generator_HV_ON_status = false;


void GeneratorInit(void){
    
    // Clear the outputs
    uc_XRAY_ENA_Clear();    
         
}


void GeneratorLoop(void){

    // Direct BusHw to PROTOCOL STATUS REGISTER Input handling
    if(uc_HV_ON_back != uc_HV_ON_Get()){
        uc_HV_ON_back = uc_HV_ON_Get();
    }else{
        Generator_HV_ON_status = uc_HV_ON_back;
    }
    
    
    // XRAY Ena status from the Master
    if(PROTOCOL_XRAY_ENA_OUT) uc_XRAY_ENA_Set();
    else uc_XRAY_ENA_Clear();    
  
    
}

bool inline GeneratorGetHvOn(void){
    return Generator_HV_ON_status;
}