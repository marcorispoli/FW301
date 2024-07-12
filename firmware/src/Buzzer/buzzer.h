#ifndef _BUZZER_H    
#define _BUZZER_H

#include "definitions.h"  

#undef ext
#ifdef _BUZZER_C
#define ext
#else
#define ext extern
#endif

/*!
 * \defgroup buzzerModule Buzzer Management Module
 *
 * \ingroup applicationModule
 * 
 * 
 * This Module controls the Buzzer activation.
 * 
 * 
 * ## Dependencies 
 * 
 * This module requires the following modules:
 * - protocol.c
 * - protocol.h
 * - gpio.c
 * - gpio.h
 * 
 * 
 * ## Module Implementation description
 * 
 * In order to implement the Module functions, the Module 
 * makes use of the following Methods:
 * +  BuzzerInit(): this is called in order to initialize module;
 * +  Buzzer728msLoop(): this function shall be called every 7.28ms ;
 *
 * ## Module API
 * 
 * The Application can call the following special functions:
 * + activateTomoDemo(): starts the Tomo Demo mode 
 * 
 *  @{
 * 
 */

    /**
    * \defgroup buzzerModuleApi API Module
    *  @{
    */
        /**
         * @brief Module Initialization
         * 
         * This function initializes the Buzzer lines and status
         * 
         * The function shall be called ***AFTER*** the use of the ApplicationProtocolInit() function
         * because it modifies the Status Registers!
         * 
         */
        ext void BuzzerInit(void);
        
        /**
         * @brief This function handles the buzzer workflow status
         * 
         * The function shall be called into the MAIN loop of the Application
         * into the 7.28 ms time schedule
         */
        ext void Buzzer728msLoop(void);
        
        /**
         * @brief This function activates the Demo mode for Tomo pulse generation
         * 
         * The Demo mode provides the execution of a given number of pulses 
         * with a given rate. 
         * 
         * This function shall be called only when the buzzer should set in manual mode.
         *  
         * NOTE: the pulse duration is fixed to 200ms, to let the buzzer properly work.
         * A lower buzzer pulse duration may cause an unexpected buzzer sound.
         * 
         * @param samples: is the number of pulses will be generated
         * @param fps: this is the pulse rate (pulse for seconds)
         */
        ext void activateTomoDemo(int samples, int fps);

    /** @}*/ // buzzerModuleApi
    
/** @}*/ // buzzerModule


#endif 