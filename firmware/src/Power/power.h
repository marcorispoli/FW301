#ifndef _POWER_H    
#define _POWER_H

#include "definitions.h"  

#undef ext
#ifdef _POWER_C
#define ext
#else
#define ext extern
#endif

/*!
 * \defgroup powerModule System Power management module
 *
 * \ingroup applicationModule
 * 
 * 
 * This Module handles the System power control
 * 
 * 
 * # Dependencies 
 * 
 * This module requires the following library modules:
 * - protocol.c
 * - protocol.h
 * 
 * ## Harmony 3 configurator setting
 * 
 * ## RTC module
 * 
 * + Add the RTC peripheral module;
 * + Set the RTC module as follows:
 *  + Hardware Setting/RTC Operation Mode/RTC Mode 0 configuration
 *      + Periodic Interval 1 Interrupt enabled = ON
 * 
 *  This setting should provide a interrupt every 15.62 ms.
 *  In case it should not possible and the timer should change 
 *  the POWER_RTC_us_TIME_UNIT should be changed accordingly
 *   
 * ## Pin Assignement
 * 
 * |Signal name|Pin|Direction|Driver|Description|
 * |:---|:---:|:---:|:---:|:---|
 * |uc_BUTTON_PWRON_REQ|32|In|Pull-Down|-|
 * |uC_POWER_DOWN|13|In|Pull-Down|-|
 * |uC_DEVICE_ON|3|Out|Strong|-|
 * |uC_GEMMA_ON|31|Out|Strong|-|
 * |uC_AUTORITENUTA|50|Out|Strong|-|
 * ||||||
 * 
 * # Module Function Description
 * 
 * This module implements the following specifications:
 * + Hardware Power On/Off;
 * + Software Power On/Off;
 * + Power presence LED control;
 * + Power Down detection and management;
 * + Power Lock for programming purpose;
 * 
 * ## Power On activities
 * 
 * The module reads the Power-On button (uc_BUTTON_PWRON_REQ) and makes a time
 * filtering on the current status. If the filtered status is ON then the module
 * checks if the Delay time from a previous Power Off is expired.
 * 
 * When the previous conditions are meet the module activates the Power On sequence: 
 * + the output (uC_DEVICE_ON) is Set, closing the Power relay that provides the 24V Device ouput.
 * 
 * The presence LED  (uC_GEMMA_ON) is switched OFF.
 *  
 * ## Soft Power Off activities
 * 
 * The module implements the Soft Power Off command of the Communication PROTOCOL Command.
 * 
 * When the *ACTIVATE_SOFT_POWEROFF* command is received:
 * 
 * + The module activates a countdown timer set to the PARAMETER[SOFT_POWER_OFF_DELAY]:
 * when the timer expires the Power will be switched off;
 * 
 * + The module sets the STATUS_SYSTEM.power_off bit to acknowledge the MASTER. 
 * 
 * + During the countdown, the presence LED will toggle the light with a 500ms period (50%duty cycle);
 * 
 * + During the countdown, if the PROTOCOL ABORT Command should be received,
 * the power off sequence shall immediatelly be aborted.
 * 
 * When the Power Off is switched off the presence LED will continue to 
 * blinking for a time of PARAMETER[POWER_ON_OFF_DELAY].
 * 
 * During this time the Power-On button is disabled.
 * 
 * ## Hard Power Off activities
 * 
 * The module measure the time the Power-On button (uc_BUTTON_PWRON_REQ) is 
 * pressed. If the time exceeds the PARAMETER[HARDWARE_POWER_OFF_TIME] 
 * then the module switch off the Power
 * 
 * When the Power Off is switched off the presence LED will continue to 
 * blinking for a time of PARAMETER[POWER_ON_OFF_DELAY].
 * 
 * During this time the Power-On button is disabled.
 * 
 * ## Power Down activities
 * 
 * The module detects a Powerdown condition, monitoring the input (uC_POWER_DOWN).
 * When the Power down is detected:
 * 
 * + The module sets the PROTOCOL STATUS_SYSTEM.power_down bit to feedback the Master;
 * 
 * + The module activates a keepalive timer set to PARAMETER[KEEP_ALIVE_POWER_OFF]:
 *   + If the keep alive timer should expire, the module activates the Hard Power-Off procedure;
 * 
 * + During the keep alive timer, the presence LED: 
 *      + toggles with a period of 1s (50% duty-cycle) for the most of the time;
 *      + toggles with a period of 500ms (50% duty-cycle) for the last 10 seconds;
 * 
 * If the Power down condition should reset before the keep alive timer expires 
 * then the normal power on condition shall be restored:
 *  + The module clears the PROTOCOL STATUS_SYSTEM.power_down bit to feedback the Master; 
 * 
 * When the Power Off is switched off the presence LED will continue to 
 * blinking for a time of PARAMETER[POWER_ON_OFF_DELAY].
 * 
 * During this time the Power-On button is disabled.
 * 
 * ## Power Lock activities
 * 
 * The module activates the power lock output (uC_AUTORITENUTA) 
 * whenever the PROTOCOL DATA_OUTPUTS.programming is detected ON.
 * 
 * The module feedbacks it setting the STATUS_SYSTEM.power_lock to the MASTER.
 *  
 * Because the power lock cannot be reset until the board is switched off, the 
 * STATUS_SYSTEM.power_lock will never be reset.
 *  
 * 
 *  @{
 * 
 */
    

    /**
    * \defgroup powerModuleApi API Module
    * 
    *  @{
    */
        /**
         * @brief Power Module Initialization
         *        
         * The function shall be called ***AFTER*** the use of the ApplicationProtocolInit() function
         * beacause it modifies the Status Registers!
         * 
         */
        ext void PowerInit(void);
    
        /**
         * @brief This function handles the module activities        
         */
        ext void Power_1564us_Loop(void);
        #define POWER_RTC_us_TIME_UNIT 15640 //!< microseconds of the loop routine
        
        ext bool PowerModule_requestSoftPowerOff(void);
        ext void PowerModule_abortSoftPowerOff(void);
        
    /** @}*/ // powerModuleApi
    
/** @}*/ // powerModule


#endif 