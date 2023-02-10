#ifndef _BUSHW_H    
#define _BUSHW_H

#include "definitions.h"  

#undef ext
#ifdef _BUSHW_C
#define ext
#else
#define ext extern
#endif

/*!
 * \defgroup busHwModule BUS Hardware management module
 *
 * \ingroup applicationModule
 * 
 * 
 * This Module interfaces the input and output of the Bus Hardware
 * signals according with the Specifications.
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
 * |uc_CMP_ENA|38|Out|Strong|This is the Compression enable signal to Compressor device|
 * |uc_CMP_ON|41|In|Pull-Down|Compression On signal from the Compressor device|
 * |uC_ROT_CW|61|In|Pull-Down|Manual C-ARM rotation request CW direction|
 * |uC_ROT_CCW|62|In|Pull-Down|Manual C-ARM rotation request CCW direction|
 * |uC_CARM_UP|63|In|Pull-Down|Manual C-ARM UP request |
 * |uC_CARM_DWN|64|In|Pull-Down|Manual C-ARM DWN request |
 * |uC_SLIDE_UP|42|In|Pull-Down|Manual SLIDE UP request |
 * |uC_SLIDE_DWN|51|In|Pull-Down|Manual SLIDE DWN request |
 * |uC_CMP_CALIB_ENA|5|Out|Strong|Enables the Compressor calibration|
 * |uC_HW_SPARE_OUT|6|Out|Strong|-|
 * |uC_HW_SPARE_IN|27|In|Pull-Down|-|
 * 
 * 
 * 
 * 
 *  @{
 * 
 */

    /**
    * \defgroup busHwModuleApi API Module
    *  @{
    */
        /**
         * @brief Bus Hardware Module Initialization
         * 
         * This function initializes the Bus Hardware signals 
         * with the initial values
         * 
         * The function shall be called ***AFTER*** the use of the ApplicationProtocolInit() function
         * beacause it modifies the Status Registers!
         * 
         */
        ext void BusHwInit(void);
    
        /**
         * @brief This function handles the Bus Hardware status
         * 
         * The function shall be called into the MAIN loop of the Application
         */
        ext void BusHwLoop(void);
        
        /**
         * @brief Bus hardware rtc interrupt 
         *  
         * This function shall be used with the RTC Interrupt
         * with 7.82ms .
         * 
         * The function is used to filter the input signals
         * 
         */
        ext void BusHwRtcInterrupt(void);
        
    /** @}*/ // busHwModuleApi
    
/** @}*/ // busHwModule


#endif 