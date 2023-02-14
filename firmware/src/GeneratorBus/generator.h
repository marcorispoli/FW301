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
 * ## Harmony 3 configurator setting
 * 
 * ### Pin Assignement
 * 
 * |Signal name|Pin|Direction|Driver|Description|
 * |:---|:---:|:---:|:---:|:---|
 * |uc_XRAY_ENA|20|Out|Strong|This is the Generator XRAY-ENA output|
 * |uc_HV_ON|14|In|Pull-Down|Generator HV-ON signal activation|
 * ||||||
 * 
 * ## Module Function Description
 * 
 * Most of the Generator Hardware signals enter the board through 
 * the Bus Hardware and exit the board to the generator after 
 * the opto insulator convert the levels from the Bus Hardware to the 
 * Generator Bus interfaces. Thos signals have no impact on the 
 * module because they don't interact with the micro controller.
 * 
 * Only the following signals are instead controlled for different
 * purpose:
 * + GENERATOR_XRAY_ENA signal (output) : Generator XRAY signal enable;
 * + GENERATOR_HV_ON signal (In): the Status of the Generator HV_ON signal
 * 
 * ### XRAY_ENA Signal handling
 * 
 * The uc_XRAY_ENA microcontroller output shall be set according with the status of the 
 * Protocol/Output.generator_xray_ena signal.
 * 
 * The effective status of the GENRATOR_XRAY_ENA hardware signals 
 * will depend by the status of all the following signals:
 * + Input XRAY-Push button;
 * + Input safety CLOSED_DOOR;
 * + The uc_XRAY_ENA signal from the micro controller.
 * 
 * 
 * ### GENERATOR_HV_ON signal
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