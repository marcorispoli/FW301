#define _BUSHW_C

#include "application.h"
#include "bushw.h"
#include "Protocol/protocol.h"

static bool is_rtc_event = false;
static bool uc_CMP_ON_back = false;
static bool uc_ROT_CW_back = false;
static bool uc_ROT_CCW_back = false;
static bool uc_CARM_UP_back = false;
static bool uc_CARM_DWN_back = false;

static bool uc_SLIDE_UP_back = false;
static bool uc_SLIDE_DWN_back = false;



void BusHwInit(void){
    
    // Clear as default the outputs
    uc_CMP_ENA_Clear();    
    uc_HW_SPARE_OUT_Clear();
        
}

/**
 * @brief Hardware Bus Loop module
 * 
 * This function executes the following jobs:
 * + Get the Bus Hardware inputs assigning the status to the Protocol-Status registers;
 * + Get the Protocol-Data Register outputs and set the related Output signal on the Bus Hardware;
 * 
 * ***Input Handling***
 * 
 * This function reads the BUS-HARDWARE inputs, 
 * and makes a time filter on the signal levels before to assign
 * the steady status to the Protocol/Status register fields.
 * 
 * The Function operate every 7.28ms and every signals needs to be stable
 * almost for two consecutive time slots:
 * + ***A signal is assigned if it remains steady for 7.28ms ***
 * 
 * *** Output Handling***
 * 
 * 
 */
void BusHwLoop(void){
    if(!is_rtc_event) return;
    
    if(uc_CMP_ON_back != uc_CMP_ON_Get()){
        uc_CMP_ON_back = uc_CMP_ON_Get();
    }else{
        PROTOCOL_SYSTEM_COMPRESSION_ON = uc_CMP_ON_back;
    }
    
    if(uc_ROT_CW_back != uc_ROT_CW_Get()){
        uc_ROT_CW_back = uc_ROT_CW_Get();
    }else{
        PROTOCOL_SYSTEM_ROT_CW = uc_ROT_CW_back;
    }
    
    if(uc_ROT_CCW_back != uc_ROT_CCW_Get()){
        uc_ROT_CCW_back = uc_ROT_CCW_Get();
    }else{
        PROTOCOL_SYSTEM_ROT_CCW = uc_ROT_CCW_back;
    }
    
    
    if(uc_CARM_UP_back != uc_CARM_UP_Get()){
        uc_CARM_UP_back = uc_CARM_UP_Get();
    }else{
        PROTOCOL_SYSTEM_CARM_UP = uc_CARM_UP_back;
    }
    
    if(uc_CARM_DWN_back != uc_CARM_DWN_Get()){
        uc_CARM_DWN_back = uc_CARM_DWN_Get();
    }else{
        PROTOCOL_SYSTEM_CARM_DWN = uc_CARM_DWN_back;
    }
    
    if(uc_SLIDE_UP_back != uc_SLIDE_UP_Get()){
        uc_SLIDE_UP_back = uc_SLIDE_UP_Get();
    }else{
        PROTOCOL_SYSTEM_SLIDE_UP = uc_SLIDE_UP_back;
    }
    
    if(uc_SLIDE_DWN_back != uc_SLIDE_DWN_Get()){
        uc_SLIDE_DWN_back = uc_SLIDE_DWN_Get();
    }else{
        PROTOCOL_SYSTEM_SLIDE_DWN = uc_SLIDE_DWN_back;
    }

    

}

void BusHwRtcInterrupt(void){
    is_rtc_event = true;
}

