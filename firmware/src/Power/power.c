#define _POWER_C

#include "application.h"
#include "power.h"
#include "Protocol/protocol.h"

static uint16_t timer100ms = 0;

static void managePowerOff(void);
static void managePowerOn(void);
static void initPowerOff(void);

static void presenceLED_200ms_blink(void);
static void presenceLED_400ms_blink(void);
static void presenceLED_5000ms_blink(void);

static bool power_status; //!< Board Power ON/OFF current status
static uint8_t power_off_workflow;//!< Power Off workflow current status
static bool power_lock; //!< Power lock current status

static bool request_soft_power_off; //!< Request to execute the soft power off
static uint8_t timer_request_soft_power_off;//! Timer to handle the soft power off

static uint8_t timer_hs_power_button; //!< Timer to handle the hard power off
static uint8_t timer_disable_button; //!< Timer to handle the disable Power On button
static uint8_t timer_poweron_button ;//!< Timer to handle the PowerOn button activation status
static bool poweron_button = false;//!< Current filtered power-on button status

// Powerdown event and keepalive timers
static uint16_t timer_keepalive; //!< Timer to handle the keepalive ; 
static uint8_t timer_powerdown; //< Timer to filter the powerdown input
static bool powerdown_condition; //!< Current Powerdown filtered status

static uint8_t batt1_level; //!< Battery 1 voltage level
static uint8_t batt2_level; //!< Battery 2 voltage level

#define FILTER_100ms_POWERON_BUTTON ((100000/POWER_RTC_us_TIME_UNIT)-1)
#define FILTER_100ms_POWERDWN ((100000/POWER_RTC_us_TIME_UNIT)-1)
#define TIMER_100MS ((100000/POWER_RTC_us_TIME_UNIT)-1)


#define HARD_POWER_BUTTON_TIME      50 //!< 5 seconds for the hard power button
#define SOFT_POWER_BUTTON_TIME      20 //!< 2 seconds for the soft power button
#define KEEPALIVE_PRESENCE_LED_TIME 100 //!< 10 seconds of the last blinking

void PowerInit(void){
    
    // Init of the 100ms timer
    timer100ms = 0;
            
    // The initial status of the module is Power Off with a disable time active 
    initPowerOff();
    ADC0_Enable();
    ADC1_Enable();
    ADC0_ConversionStart();
    ADC1_ConversionStart();
    
    powerdown_condition = false;
    poweron_button = false;
}


void Power_1564us_Loop(void){

    
    // Input Power Button time filtering section 
    if(!poweron_button){
        if(uc_BUTTON_PWRON_REQ_Get()) timer_poweron_button++;
        else timer_poweron_button = 0;
        if(timer_poweron_button >= FILTER_100ms_POWERON_BUTTON){ 
            poweron_button = true;
            timer_poweron_button = 0;
        }
    }else{
        if(!uc_BUTTON_PWRON_REQ_Get()) timer_poweron_button++;
        else timer_poweron_button = 0;
        if(timer_poweron_button >= FILTER_100ms_POWERON_BUTTON){ 
            poweron_button = false;
            timer_poweron_button = 0;
        }        
    }
    
    // Input powerdown_condition time filtering section 
    if(!powerdown_condition){
        if(!uc_POWER_DOWN_Get()) timer_powerdown++;
        else timer_powerdown = 0;
        if(timer_powerdown >= FILTER_100ms_POWERDWN){ 
            powerdown_condition = true;
            timer_powerdown = 0;
        }
    }else{
        if(uc_POWER_DOWN_Get()) timer_powerdown++;
        else timer_powerdown = 0;
        if(timer_powerdown >= FILTER_100ms_POWERDWN){ 
            powerdown_condition = false;
            timer_powerdown = 0;
        }
    }
    
    
    
    // --------------  Section 100ms ---------------
    if(!timer100ms){
        timer100ms = TIMER_100MS;
            
        
        if(!power_status) managePowerOff();
        else managePowerOn();
        
        // Update the status of the Battery Ena button
        SETBIT_PROTOCOL_SYSTEM_BATTENA(uc_BATT_ENA_Get());
        
        batt1_level = (ADC1_ConversionResultGet() * 100) / 124;        
        SETBYTE_PROTOCOL_BATTERY_VBATT1(batt1_level);
        
        batt2_level = (ADC0_ConversionResultGet() * 100) / 124;        
        SETBYTE_PROTOCOL_BATTERY_VBATT2(batt2_level);
        
        // Set the status of the system status bit 
        SETBIT_PROTOCOL_SYSTEM_BATT1_LOW(batt1_level < GETBYTE_PARAMETER_LOW_BATT1_LEVEL);
        SETBIT_PROTOCOL_SYSTEM_BATT2_LOW(batt2_level < GETBYTE_PARAMETER_LOW_BATT2_LEVEL);
        
    }else timer100ms--;
    
    
}

void presenceLED_200ms_blink(void){
    static uint8_t timer_presence_led =0;
    if(timer_presence_led == 1) {
        uc_GEMMA_ON_Toggle();
        timer_presence_led = 1;
    }else timer_presence_led++;
}

void presenceLED_400ms_blink(void){
    static uint8_t timer_presence_led =0;
    if(timer_presence_led == 2) {
        uc_GEMMA_ON_Toggle();
        timer_presence_led = 1;
    }else timer_presence_led++;
}

void presenceLED_5000ms_blink(void){
    static uint8_t timer_presence_led =0;
    if(timer_presence_led == 25) {
        uc_GEMMA_ON_Toggle();
        timer_presence_led = 1;
    }else timer_presence_led++;
}


bool PowerModule_requestSoftPowerOff(void){
    if(power_lock) return false;
    if(!power_status) return false;
    if(request_soft_power_off) return true;
    
    // Initits the timer
    timer_request_soft_power_off = GETBYTE_PARAMETER_SOFT_POWER_OFF_DELAY ;
    request_soft_power_off = true;
    SETBIT_PROTOCOL_SYSTEM_SOFT_POWEROFF(true);
    return true;
}

void PowerModule_abortSoftPowerOff(void){
    if(power_lock) return ;
    if(!power_status) return ;
    if(!request_soft_power_off) return ;
    
    request_soft_power_off = false;  
    SETBIT_PROTOCOL_SYSTEM_SOFT_POWEROFF(false);
    uc_GEMMA_ON_Clear();
    return ;
}

void initPowerOff(void){
    
    power_status = false;
    power_off_workflow = 0;
    
    timer_disable_button = GETBYTE_PARAMETER_POWER_ON_OFF_DELAY;
    
    // DeActivates the power relay
    uc_DEVICE_ON_Clear();
            
    // Init of the power lock 
    power_lock = false;
    SETBIT_PROTOCOL_SYSTEM_POWER_LOCK(false);
    uc_AUTORITENUTA_Clear();
    
    // Soft power Off
    SETBIT_PROTOCOL_SYSTEM_SOFT_POWEROFF(false);
    request_soft_power_off = false;
  
    // Powerdown
    timer_keepalive = GETBYTE_PARAMETER_KEEP_ALIVE_POWER_OFF * 10;
    SETBIT_PROTOCOL_SYSTEM_POWERDOWN(false);
    
    // Reset timer Hard and soft power On
    timer_hs_power_button = 0;
    
}

void managePowerOff(void){
    
    switch(power_off_workflow){
        case 0: 
           
            // During the disable time the presence LED blinks 500ms
            // When the delay time expires the LED shall be Set (Presemce Led = ON))
            if(timer_disable_button){
               timer_disable_button--;
               presenceLED_200ms_blink();
               // No other activities are allowed during this time
               return;
            }
            
            // The button shall be OFF to continue
            if(poweron_button){ 
                presenceLED_200ms_blink();
                return;
            }
           
            // Sets the presence LED 
            uc_GEMMA_ON_Set();
            
            power_off_workflow++;
            return;
        
        case 1:
            
            // Waits the push button
            if(!poweron_button) return;
            
            // Activates the power relay
            uc_DEVICE_ON_Set();

            power_off_workflow++;
            return;
            
            
        case 2:
            
            // The button shall be OFF to continue
            if(poweron_button){ 
                presenceLED_200ms_blink();
                return;
            }
           
            // Sets the presence LED 
            uc_GEMMA_ON_Clear();

            
            // Waits for the button release            
            power_off_workflow = 0;
            power_status = true;            
            
            return;
     }
    
}


void managePowerOn(void){
    
    // Power Lock status: the status is self retaining
    if(!power_lock){
        if(TESTBIT_PROTOCOL_PROGRAMMING_OUT){
            power_lock = true;
            SETBIT_PROTOCOL_SYSTEM_POWER_LOCK(true);
        
            // No Power Off possible
            uc_GEMMA_ON_Clear();
            request_soft_power_off = false;
            SETBIT_PROTOCOL_SYSTEM_SOFT_POWEROFF(false);
            
            // Self retained output activated 
            uc_AUTORITENUTA_Set();
        }
    }else return;// IN power locking, no Power Off activities can be initiated
    
    // Hard and Soft Power Off handling
    if(poweron_button) timer_hs_power_button++;
    else timer_hs_power_button = 0;
    
    // Hard Power Off event
    if(timer_hs_power_button > HARD_POWER_BUTTON_TIME){
        initPowerOff();
        return;
    }

    // Button soft power off request
    if((!request_soft_power_off) && (timer_hs_power_button > SOFT_POWER_BUTTON_TIME)){ 
        request_soft_power_off = true;     
        timer_request_soft_power_off = GETBYTE_PARAMETER_SOFT_POWER_OFF_DELAY ;
        SETBIT_PROTOCOL_SYSTEM_SOFT_POWEROFF(true);
    }
        
    // Soft power off management
    if(request_soft_power_off){        
        presenceLED_400ms_blink(); // Led blinks with 600ms period
        if(!timer_request_soft_power_off) initPowerOff();
        else timer_request_soft_power_off--;
        return;
    }
    
    // Powerdown management
    SETBIT_PROTOCOL_SYSTEM_POWERDOWN(powerdown_condition);
    
   
    
    if(powerdown_condition){
        
        // Keepalive timer: when expires the system gets power off
        if(!timer_keepalive){
            initPowerOff();
            return;
        }else timer_keepalive--;
        
        // presence LED blinking
        if(timer_keepalive < KEEPALIVE_PRESENCE_LED_TIME ) presenceLED_400ms_blink();
        else presenceLED_5000ms_blink();
        
    }else{ 
        timer_keepalive = GETBYTE_PARAMETER_KEEP_ALIVE_POWER_OFF * 10;
        uc_GEMMA_ON_Clear();
    }
    
    return;
}



