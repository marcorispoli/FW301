#define _GPIO_C

#include "application.h"
#include "gpio.h"
#include "../Power/power.h"
#include "Protocol/protocol.h"


static bool burning_jumper_status = false;
static bool burning_jumper_test = false;


void motorPowerManagement(bool run){
    
    // Motor Switch Relay
    SETBIT_PROTOCOL_SYSTEM_MOT_DCOK(uc_48V_DCOK_Get());
    
    if(!run){
        uc_48V_DISABLE_Set();
        uc_MOTOR_SAFE_ENA_Clear();          
        return;
    }

    // 48V Motor Enable 
    if(TESTBIT_PROTOCOL_MOT_ENA_OUT) uc_48V_DISABLE_Clear();
    else uc_48V_DISABLE_Set();

    // 48V Solid State Relay output
    if(TESTBIT_PROTOCOL_MOT_SWITCH_OUT) uc_MOTOR_SAFE_ENA_Set();
    else uc_MOTOR_SAFE_ENA_Clear();        
        
}
void xrayManagement(bool run){
    
    // Read the XRAY Push Button
    SETBIT_PROTOCOL_SYSTEM_XRAY_BUTTON(uc_XRAY_REQ_Get());
    
    if(!run){    
        uc_XRAY_ENA_Clear();
        uc_XRAY_LED_Clear();
        uc_XRAY_LAMP1_Clear();
        uc_XRAY_LAMP2_Clear();
        return;
    }
    
    // XRAY-ENA signal output
    if(TESTBIT_PROTOCOL_XRAY_ENA_OUT) uc_XRAY_ENA_Set();
    else uc_XRAY_ENA_Clear();

    // Xray LED Out
    if(TESTBIT_PROTOCOL_XRAY_LED_OUT) uc_XRAY_LED_Set();
    else uc_XRAY_LED_Clear();

    // Xray LAMP1 Out
    if(TESTBIT_PROTOCOL_XRAY_LAMP1_OUT) uc_XRAY_LAMP1_Set();
    else uc_XRAY_LAMP1_Clear();

     // Xray LAMP2 Out
    if(TESTBIT_PROTOCOL_XRAY_LAMP2_OUT) uc_XRAY_LAMP2_Set();
    else uc_XRAY_LAMP2_Clear();
       
}

void compressorManagement(bool run){
    
    // Compression bus hw input 
    SETBIT_PROTOCOL_SYSTEM_COMPRESSION_ON(uc_CMP_ON_Get());
    
    if(!run){        
        uc_CMP_ENA_Clear(); 
        uc_CALIB_ENA_Clear();
        return;
    }
    
    // Compressor Enable Output
    if(TESTBIT_PROTOCOL_COMPRESSOR_ENA_OUT) uc_CMP_ENA_Set();
    else uc_CMP_ENA_Clear();    

    // Compressor Calibration Ena output
    if(TESTBIT_PROTOCOL_CALIB_ENA_OUT) uc_CALIB_ENA_Set();
    else uc_CALIB_ENA_Clear();
}

void burningManagement(bool run){
    static int test_step = 0;
    
    // TEst on the Burning presence if requested
    if(burning_jumper_test){     
        
        // Test completed
        if(test_step == 255){
            test_step = 0;
            burning_jumper_test = false;
            
            // Assignes the current burning status
            if(uc_XRAY_REQ_Get()) burning_jumper_status = true;
            else burning_jumper_status = false;
            
            
            uc_BURNING_Clear();
            SETBIT_PROTOCOL_SYSTEM_BURNIN_JUMPER(burning_jumper_status);
            return;
        }
        
        // TEst initialization
        if(test_step == 0){
            uc_BURNING_Set();
            uc_XRAY_ENA_Clear();            
        }
        
        test_step++;        
        return;
    }
    
    // Read the burning jumper
    SETBIT_PROTOCOL_SYSTEM_BURNIN_JUMPER(burning_jumper_status);
    
    if(!run){
        uc_BURNING_Clear();
        return;
    }
    
    // Burning Out (software x-ray request)
    if(TESTBIT_PROTOCOL_BURNIN_OUT)  uc_BURNING_Set();
    else uc_BURNING_Clear();

}

void manualRotationActivation(bool run){
   
    SETBIT_PROTOCOL_SYSTEM_ROT_CW(uc_ROT_CW_Get());
    SETBIT_PROTOCOL_SYSTEM_ROT_CCW(uc_ROT_CCW_Get());
    
    SETBIT_PROTOCOL_SYSTEM_CARM_UP(uc_CARM_UP_Get());
    SETBIT_PROTOCOL_SYSTEM_CARM_DWN(uc_CARM_DWN_Get());
    
    SETBIT_PROTOCOL_SYSTEM_SLIDE_UP(uc_SLIDE_UP_Get());    
    SETBIT_PROTOCOL_SYSTEM_SLIDE_DWN(uc_SLIDE_DWN_Get());

    SETBIT_PROTOCOL_SYSTEM_BODY_CW(uc_BODY_CW_Get());
    SETBIT_PROTOCOL_SYSTEM_BODY_CCW(uc_BODY_CCW_Get());    
    
    if(TESTBIT_MANUAL_ROT_LED)   uc_HW_MAN_ENA_Set();
    else uc_HW_MAN_ENA_Clear();
    
}

void pedalboardActivation(bool run){
    
    SETBIT_PROTOCOL_SYSTEM_PEDAL_UP(uc_PEDAL_UP_Get());
    SETBIT_PROTOCOL_SYSTEM_PEDAL_DWN(uc_PEDAL_DWN_Get());    
    SETBIT_PROTOCOL_SYSTEM_PEDAL_CMP_UP(uc_PEDAL_CMP_UP_Get());
    SETBIT_PROTOCOL_SYSTEM_PEDAL_CMP_DWN(uc_PEDAL_CMP_UP_Get());
}

void GpioInit(void){
   burning_jumper_status = false;
   burning_jumper_test = true;
   
}

bool gpioTest(void){
    static int step = 0;
    
    switch(step){
        case 0:
            uc_BURNING_Set();
            uc_XRAY_ENA_Clear();
            step++;
            break;
        case 1:
            // Test the presence of the Burning jumper
            if(uc_XRAY_REQ_Get()) burning_jumper_status = true;
            else burning_jumper_status = false;
            step = 0;
            break;
    }
    
    if(step) return true;
    else return false;
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
void GpioLoop(void){
    bool run  = (isPowerOn() && !timeoutMasterCommunication());
       
    // Emergency detection
    SETBIT_PROTOCOL_SYSTEM_EMERGENCY(uc_EMERGENCY_Get());

    // Cabinet Input Switch
    SETBIT_PROTOCOL_SYSTEM_CABINET_SAFETY(uc_MOT_SW_Get());

    // Read the closed door input
    SETBIT_PROTOCOL_SYSTEM_CLOSED_DOOR(uc_CLOSED_DOOR_Get());
        
    
    motorPowerManagement(run);
    xrayManagement(run);
    compressorManagement(run);
    burningManagement(run);
    manualRotationActivation(run);
    pedalboardActivation(run);

    // Read back the current motor switch activation status
    if( (!uc_MOT_SW_Get()) && (!uc_CMP_ON_Get()) && (TESTBIT_PROTOCOL_MOT_SWITCH_OUT))       
        SETBIT_PROTOCOL_SYSTEM_MOT_SWICTH_ON(1);
    else SETBIT_PROTOCOL_SYSTEM_MOT_SWICTH_ON(0);

       
}

bool isRunningMode(void){
    return ((isPowerOn() && (!timeoutMasterCommunication()) ));
}