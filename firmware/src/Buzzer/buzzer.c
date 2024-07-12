#define _BUZZER_C

#include "application.h"
#include "GPIO/gpio.h"
#include "buzzer.h"
#include "Protocol/protocol.h"



#define BUZ_DEMO_PULSE_ON (10000/728)
static int buz_demo_seq = 0;
static int buz_demo_samples = 0;
static int buz_demo_fps = 0;

static unsigned char buz_demo_current_pulse = 0;
static unsigned char buz_demo_pulse_count = 0;

bool BuzzerDemoInit(int samples, int fps){
    
    // The Buzzer is not in Manual Mode
    if(!TESTBIT_PROTOCOL_BUZZER_MANUAL_MODE) return false;
    
    // The Xray Push Button is not detected active
    if(!uc_XRAY_REQ_Get()) return false;
    
    buz_demo_samples = samples; 
    buz_demo_fps = fps;     
    buz_demo_seq = 1;
    
    return true;
}


void buzzer_demo_sequence(void){
    
    // Xray Push Button released or the Manual mode is cleared
    if((!uc_XRAY_REQ_Get()) || (!TESTBIT_PROTOCOL_BUZZER_MANUAL_MODE)){
        uc_BUZZER_Clear();
        MET_Can_Protocol_returnCommandExecuted(buz_demo_current_pulse, 0);
        buz_demo_seq = 0;        
        return;
    }
    
    switch(buz_demo_seq){
        case 1:
            buz_demo_current_pulse = 1;              
            uc_BUZZER_Set();
            buz_demo_pulse_count = BUZ_DEMO_PULSE_ON;          
            buz_demo_seq++;
            break;
            
        case 2: // Buzzer ON
            buz_demo_pulse_count--;
            if(buz_demo_pulse_count) break;
            
            uc_BUZZER_Clear();
            buz_demo_pulse_count = (10000 / (73 * buz_demo_fps)) - BUZ_DEMO_PULSE_ON;
            if(buz_demo_pulse_count <= 0) buz_demo_pulse_count = 1;
            buz_demo_seq++;
            break;
            
        case 3: // Buzzer OFF
            buz_demo_pulse_count--;
            if(buz_demo_pulse_count) break;
            
            // End command
            if(buz_demo_current_pulse == buz_demo_samples){
                MET_Can_Protocol_returnCommandExecuted(buz_demo_current_pulse, 0);
                buz_demo_seq = 0;
                break;
            }
            
            buz_demo_current_pulse++;            
            uc_BUZZER_Set();
            buz_demo_pulse_count = BUZ_DEMO_PULSE_ON;      
            buz_demo_seq = 2;
            break;
    }
    
    return;
}


void Buzzer728msLoop(void){
    
    // The Board is not ion running Mode
    if(!isRunningMode()){
        uc_BUZZER_Clear();
        buz_demo_seq = 0;
        return;
    }
    
    
    if(buz_demo_seq) buzzer_demo_sequence();
    else if(TESTBIT_PROTOCOL_BUZZER_MANUAL_MODE){
        // Manual Mode
        if(TESTBIT_PROTOCOL_MAN_BUZZER_OUT) uc_BUZZER_Set();
        else uc_BUZZER_Clear();           
    }else{
        // Detector Mode
         uc_BUZZER_Clear();
    }
    
    
}

