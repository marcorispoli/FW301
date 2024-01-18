#ifndef _GPIO_H    
#define _GPIO_H

#include "definitions.h"  

#undef ext
#ifdef _GPIO_C
#define ext
#else
#define ext extern
#endif

/*!
 * \defgroup gpioModule Digital Input Output management module
 *
 * \ingroup applicationModule
 * 
 * 
 * This Module interfaces the input and output of the board.
 * 
 * 
 * ## Dependencies 
 * 
 * This module requires the following modules:
 * - protocol.c
 * - protocol.h
 * 
 * 
 * 
 * ## Module Implementation description
 * 
 * In order to implement the Module functions, the Module 
 * makes use of the following Methods:
 * +  GpioInit(): this is called in order to initialize the status of the IOs;
 * +  GpioLoop(): this function shall be called every 7.28ms to update the IO status;
 *
 *  @{
 * 
 */

    /**
    * \defgroup gpioModuleApi API Module
    *  @{
    */
        /**
         * @brief Module Initialization
         * 
         * This function initializes the Bus Hardware signals 
         * with the initial values
         * 
         * The function shall be called ***AFTER*** the use of the ApplicationProtocolInit() function
         * because it modifies the Status Registers!
         * 
         */
        ext void GpioInit(void);
    
        /**
         * @brief This function handles the IOs status
         * 
         * The function shall be called into the MAIN loop of the Application
         */
        ext void GpioLoop(void);
        
        
        
    /** @}*/ // gpioModuleApi
    
/** @}*/ // gpioModule


#endif 