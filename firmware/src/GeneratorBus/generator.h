#ifndef _GENERATOR_H    
#define _GENERATOR_H

#include "definitions.h"  

#undef ext
#ifdef _GENERATOR_C
#define ext
#else
#define ext extern
#endif

/*!
 * \defgroup generatorModule Generator Interface management module
 *
 * \ingroup applicationModule
 * 
 * 
 * This Module handles the Generator Bus signals, according with the Specifications.
 * 
 * 
 * ## Dependencies 
 * 
 * This module requires the following library modules:
 * - protocol.c
 * - protocol.h
 * 
 * ##  Generator interface Signal routing
 * 
 * |Signal|Direction|Source|Destination|Description|Internal name|uC Pin|
 * |:---|:---:|:---:|:---|:---:|:---|:---|
 * |gen_xray_ena|Out|Internal|Generator Device|This is the Generator XRAY-ENA output|uc_XRAY_ENA|20|
 * |gen_hv_on|In|Generator Device|Internal|Generator HV-ON signal activation|uc_HV_ON|14|
 * 
 * ## Module Function Description
 * 
 * Most of the Generator interface signals transit only into the Power Service board
 * without the uController interaction. However two of the Generator interface signals 
 * are handled for internal usage:
 * 
 * + gen_xray_ena signal (output) : Generator XRAY signal enable;
 * + gen_hv_on signal (In): the Status of the Generator HV_ON signal
 * 
 * ## GEN_HV_ON Signal handling
 * 
 * The module shall set the uc_XRAY_ENA according with the PROTOCOL.Output.generator_xray_ena
 * signal status. 
 * 
 * The Actual hardware output however depends by the status of other hardware signals:
 * + Input XRAY-Push button;
 * + Input safety CLOSED_DOOR;
 * 
 * 
 * ## GENERATOR_HV_ON signal
 * 
 * The GENERATOR_HV_ON signal is activated by the Generator device 
 * whenever the HV voltage is activated. 
 * 
 * This signal shall be read by the micro controller in order to properly activate
 * the Buzzer when the Buzzer is in Automatic mode.
 * In order to reduce possibles interferences this signal shall be filtered.
 * 
 * See @ref buzzerModule for details 
 *
 * ## Module Implementation description
 * 
 * In order to implement the Module functions, the Module 
 * makes use of the following Methods:
 * +  GeneratorInit(): this is called in order to initialize the status of the IOs;
 * +  GeneratorLoop(): this function shall be called every 7.28ms to filter the Input levels;
 * +  GeneratorGetHvOn(): this is a method available by the application to get the current HV_ON status;
 * 
 *  @{
 * 
 */

    /**
    * \defgroup generatorModuleApi API Module
    * 
    *  @{
    */
        /**
         * @brief Generator Module Initialization
         * 
         * This function initializes the Generator signals 
         * with the initial values
         * 
         * The function shall be called ***AFTER*** the use of the ApplicationProtocolInit() function
         * beacause it modifies the Status Registers!
         * 
         */
        ext void GeneratorInit(void);
    
        /**
         * @brief This function handles the Generator signal status
         * 
         * The function shall be called into the MAIN loop of the Application
         * but with a Time Period that determines the signal filtering time.
         * 
         * This function executes the following jobs:
         * + Get the GENERATOR_HV_ON inputs signal from the Generator Bus;
         * + Get the Protocol-Data Register outputs and set the XRAY_ENA signal;
         */
        ext void GeneratorLoop(void);
        
        /**
         * This function gets the current status of the HV-ON
         * 
         * @return the current status of the GENERATOR_HV_ON Signal 
         */
        ext bool GeneratorGetHvOn(void);
        
    /** @}*/ // generatorModuleApi
    
/** @}*/ // generatorModule


#endif 