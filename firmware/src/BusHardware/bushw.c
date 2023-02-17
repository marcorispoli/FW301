#define _BUSHW_C

#include "application.h"
#include "bushw.h"
#include "Protocol/protocol.h"


static bool uc_CMP_ON_back = false;
static bool uc_ROT_CW_back = false;
static bool uc_ROT_CCW_back = false;
static bool uc_CARM_UP_back = false;
static bool uc_CARM_DWN_back = false;

static bool uc_SLIDE_UP_back = false;
static bool uc_SLIDE_DWN_back = false;



void BusHwInit(void){
    
    // Clears the Inputs
    PROTOCOL_SYSTEM_COMPRESSION_ON(0);
    PROTOCOL_SYSTEM_ROT_CW(0);
    PROTOCOL_SYSTEM_ROT_CCW(0);
    PROTOCOL_SYSTEM_CARM_UP(0);
    PROTOCOL_SYSTEM_CARM_DWN(0);
    PROTOCOL_SYSTEM_SLIDE_UP(0);
    PROTOCOL_SYSTEM_SLIDE_DWN(0);
    
    // Clear the outputs
    uc_CMP_ENA_Clear();    
    uc_HW_SPO2_Clear();
    uc_CALIB_ENA_Clear();
    
        
}

/**
 * @brief Hardware Bus Loop module
 * 
 * This function shall be launched every T milli seconds in order 
 * to make a signal filtering of period T.
 * 
 * This function executes the following jobs:
 * + Get the Bus Hardware inputs assigning the status to the Protocol-Status registers;
 * + Get the Protocol-Data Register outputs and set the related Output signal on the Bus Hardware;
 * 
 * ***Input Handling***
 * 
 * This function reads the BUS-HARDWARE inputs and converts the filtered status 
 * into the CAN Protocol Status register.
 * 
 * 
 * ***Output Handling***
 * 
 * This section set the Bus hardware outputs that are directly 
 * under the control of the Microcontroller:
 * 
 * - COMPRESSOR_ENA output;
 * - CALIBRATION_ENA Output (SPO1 Output);
 * - SPO2 Output;
 * 
 */
void BusHwLoop(void){

    // Direct BusHw to PROTOCOL STATUS REGISTER Input handling
    if(uc_CMP_ON_back != uc_CMP_ON_Get()){
        uc_CMP_ON_back = uc_CMP_ON_Get();
    }else{
        PROTOCOL_SYSTEM_COMPRESSION_ON(uc_CMP_ON_back);
    }
    
    if(uc_ROT_CW_back != uc_ROT_CW_Get()){
        uc_ROT_CW_back = uc_ROT_CW_Get();
    }else{
        PROTOCOL_SYSTEM_ROT_CW(uc_ROT_CW_back);
    }
    
    if(uc_ROT_CCW_back != uc_ROT_CCW_Get()){
        uc_ROT_CCW_back = uc_ROT_CCW_Get();
    }else{
        PROTOCOL_SYSTEM_ROT_CCW(uc_ROT_CCW_back);
    }
    
    
    if(uc_CARM_UP_back != uc_CARM_UP_Get()){
        uc_CARM_UP_back = uc_CARM_UP_Get();
    }else{
        PROTOCOL_SYSTEM_CARM_UP(uc_CARM_UP_back);
    }
    
    if(uc_CARM_DWN_back != uc_CARM_DWN_Get()){
        uc_CARM_DWN_back = uc_CARM_DWN_Get();
    }else{
        PROTOCOL_SYSTEM_CARM_DWN(uc_CARM_DWN_back);
    }
    
    if(uc_SLIDE_UP_back != uc_SLIDE_UP_Get()){
        uc_SLIDE_UP_back = uc_SLIDE_UP_Get();
    }else{
        PROTOCOL_SYSTEM_SLIDE_UP(uc_SLIDE_UP_back);
    }
    
    if(uc_SLIDE_DWN_back != uc_SLIDE_DWN_Get()){
        uc_SLIDE_DWN_back = uc_SLIDE_DWN_Get();
    }else{
        PROTOCOL_SYSTEM_SLIDE_DWN(uc_SLIDE_DWN_back);
    }

    // Direct PROTOCOL OUTPUT REGISTER to BusHw Outputs
    if(PROTOCOL_COMPRESSOR_ENA_OUT) uc_CMP_ENA_Set();
    else uc_CMP_ENA_Clear();    
    
    if(PROTOCOL_CALIB_ENA_OUT) uc_CALIB_ENA_Set();
    else uc_CALIB_ENA_Clear();
    
    
}
