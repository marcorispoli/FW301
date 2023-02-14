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
 * |uc_ROT_CW|61|In|Pull-Down|Manual C-ARM rotation request CW direction|
 * |uc_ROT_CCW|62|In|Pull-Down|Manual C-ARM rotation request CCW direction|
 * |uc_CARM_UP|63|In|Pull-Down|Manual C-ARM UP request |
 * |uc_CARM_DWN|64|In|Pull-Down|Manual C-ARM DWN request |
 * |uc_SLIDE_UP|42|In|Pull-Down|Manual SLIDE UP request |
 * |uc_SLIDE_DWN|51|In|Pull-Down|Manual SLIDE DWN request |
 * |uc_CALIB_ENA|5|Out|Strong|Enables the Compressor calibration|
 * |uc_HW_SPO2|6|Out|Strong|-|
 * |uc_HW_SPARE_IN|27|In|Pull-Down|-|
 * 
 * ## Module Function Description
 * 
 * Most of the Bus Hardware signals are directly controlled by the 
 * microcontroller that set or read the related status.
 * 
 * This module provides the following Signal controlling path:
 * 
 * |Signal|Direction|Source|Description|
 * |:---|:---:|:---:|:---|
 * |hw_comp_ena|Out|CAN_PROTOCOL.Output.enable_compressor|This is the Compression enable signal to Compressor device|
 * |hw_cmp_on|In|CAN_PROTOCOL.Status.compression_on|Compression On signal from the Compressor device|
 * |hw_rot_cw|In|CAN_PROTOCOL.Status.carm_rot_cw|Manual C-ARM rotation request CW direction|
 * |hw_rot_ccw|In|CAN_PROTOCOL.Status.carm_rot_ccw|Manual C-ARM rotation request CCW direction|
 * |hw_carm_up|In|CAN_PROTOCOL.Status.carm_up|Manual C-ARM UP request |
 * |hw_carm_dwn|In|CAN_PROTOCOL.Status.carm_dwn|Manual C-ARM DWN request |
 * |hw_tilt_up|In|CAN_PROTOCOL.Status.slide_up|Manual SLIDE UP request |
 * |hw_tilt_dwn|In|CAN_PROTOCOL.Status.slide_dwn|Manual SLIDE DWN request |
 * |hw_spo1|Out|CAN_PROTOCOL.Output.enable_calibration|Enables the Compressor calibration|
 * |hw_spo2|Out|-|-|
 * |hw_spi1|In|-|-|
 * 
 * The Input signals shall be read and filtered at a rate of about 7.28ms;
 * 
 * The Output shall set every 7.28ms;
 * 
 * ## Module Implementation description
 * 
 * In order to implement the Module functions, the Module 
 * makes use of the following Methods:
 * +  BusHwInit(): this is called in order to initialize the status of the IOs;
 * +  BusHwLoop(): this function shall be called every 7.28ms to filter the Input levels;
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
        
        
        
    /** @}*/ // busHwModuleApi
    
/** @}*/ // busHwModule


#endif 