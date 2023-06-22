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
 * This Module interfaces the input and output of the Bus Hardware connector.
 * 
 * 
 * ## Dependencies 
 * 
 * This module requires the following modules:
 * - protocol.c
 * - protocol.h
 * 
 * 
 * ### Bus Hardware Signal routing
 *
 * |Signal|Direction|Source|Destination|Description|Internal name|uC Pin|
 * |:---|:---:|:---:|:---|:---:|:---|:---|
 * |hw_comp_ena|Out|PROTOCOL.Output.enable_compressor|Compressor Device|This is the Compression enable signal to Compressor device|uc_CMP_ENA|38|
 * |hw_cmp_on|In|Compressor Device | PROTOCOL.Status.compression_on|Compression On signal from the Compressor device|uc_CMP_ON|41|
 * |hw_rot_cw|In|Manual C-ARM rotation| PROTOCOL.Status.carm_rot_cw|Manual C-ARM rotation request CW direction|uc_ROT_CW|61|
 * |hw_rot_ccw|In|Manual C-ARM rotation|PROTOCOL.Status.carm_rot_ccw|Manual C-ARM rotation request CCW direction|uc_ROT_CCW|62|
 * |hw_carm_up|In|Manual UP/DOWN|PROTOCOL.Status.carm_up|Manual C-ARM UP request |uc_CARM_UP|63|
 * |hw_carm_dwn|In|Manual UP/DOWN|CAN_PROTOCOL.Status.carm_dwn|Manual C-ARM DWN request |uc_CARM_DWN|64|
 * |hw_slide_up|In|Manual SLIDE|CAN_PROTOCOL.Status.slide_up|Manual SLIDE UP request |uc_SLIDE_UP|42|
 * |hw_slide_dwn|In|Manual SLIDE|CAN_PROTOCOL.Status.slide_dwn|Manual SLIDE DWN request |uc_SLIDE_DWN|51|
 * |hw_calib_ena|Out|CAN_PROTOCOL.Output.enable_calibration|Compressor/collimator devices|Enables the Compressor/Collimator calibration|uc_CALIB_ENA|5|
 * |hw_spo2|Out|-|-|-|uc_HW_SPO2|6|
 * |hw_spi1|In|-|-|-|uc_HW_SPARE_IN|27|
 * 
 * The module read the Inputs coming from the bus hardware connector making 
 * a time filtering with 14.56ms;
 * 
 * The module writes the Output of the bus hardware connector every 7.28ms;
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