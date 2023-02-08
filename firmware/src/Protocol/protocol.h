#ifndef _PROTOCOL_H    
#define _PROTOCOL_H

#include "definitions.h"  

#ifdef _PROTOCOL_C
#define ext
#else
#define ext extern
#endif

/*!
 * \defgroup protocolModule CAN Communicaiton Protocol Module
 *
 * \ingroup applicationModule
 * 
 * # GENERAL OVERVIEW
 *
 * This protocol implements the functionalities 
 * of the PCB/22-301 Software Communication protocol specifications.
 * 
 * This module makes use of the application library module MET_Can_Protocol
 * that implements the communication based mechanisms.
 * 
 * 
 * # COMMUNICATION CHARACTERISTICS
 * 
 * The CAN communication is based on the following 
 * characteristics:
 * 
 * - Standard (not Flexible) communication;
 * - Standard frame (11 bit ID);
 * - Baude Rate: 1Mb/s;
 * - Can ID reception address: 0x201;
 * 
 * # PROTOCOL DESCRIPTION
 * 
 * The Application iplements the protocol Items 
 * described in the PCB/22-301 Software Communication protocol specifications.
 * 
 * In this chapter it will be briefly described the protocol Items.
 * For details refer to the document specification.
 * 
 * ## PROTOCOL STATUS REGISTERS
 * 
 * The available registers are:
 * 
 * - RESERVED   (IDX=0)
 * - REVISION   (IDX=1);
 * - SYSTEM     (IDX=2);
 * - ERRORS     (IDX=3);
 * - COMMAND    (IDX=4);
 * - BATTERY    (IDX=5);
 * 
 * ## PROTOCOL DATA REGISTERS
 * 
 * ## PROTOCOL PARAMETER REGISTERS
 * 
 * ## PROTOCOL COMMANDS
 * 
 *  @{
 * 
 */


/**
 * \defgroup moduleInterface Module API interface
 * 
 * This section describes the funtions implementing the Protocol module.
 * 
 *  @{
 */


/// This is the Protocol initialization function
ext void ApplicationProtocolInit ( uint8_t deviceID);

/// This is the Main Loop protocol function
ext void  ApplicationProtocolLoop(void);

/** @}*/  // moduleData

//_________________________ STATUS REGISTER DATA DEFINITION _______________________

/** \defgroup statusRegister Status Registers Data definition
 *  
 *  This section describes the implementation of the Status Registers.
 * 
 *  The section is dived in:
 * - @ref  moduleData: this section describes the data structure handling the registers;
 * - @ref  typeDef: this section provides the typedef and structures handling the registers content;
 * - @ref  applicationMacro: this section provides the helper macro to be used along the application to get and set the Status registers content.
 * 
 * 
 *  @{
 */
        //_________________________ MODULE DATA DEFINITION _______________________
        /**
         * \defgroup moduleData Data structure declaration
         * 
         *  @{
         */

        #define PROTOCOL_NUMBER_OF_STATUS_REGISTERS 6 //!< Defines the total number of implemented status registers 
        ext uint8_t statusRegisterArray[PROTOCOL_NUMBER_OF_STATUS_REGISTERS][4]; //!< This is the Status data Array: 6 frames of 4 bytes         
        #define PROTOCOL_RESERVED_REGISTER_PTR  (&(statusRegisterArray[0][0])) //!< This is the pointer to the reserved register
        #define PROTOCOL_REVISION_REGISTER_PTR  ((_Revision_Status_t*)&(statusRegisterArray[1][0])) //!< This is the pointer to the REVISION status register
        #define PROTOCOL_SYSTEM_REGISTER_PTR    ((_System_Status_t*)&(statusRegisterArray[2][0])) //!< This is the pointer to the SYSTEM status register
        #define PROTOCOL_ERRORS_REGISTER_PTR    ((_Errors_Status_t*)&(statusRegisterArray[3][0])) //!< This is the pointer to the ERRORS status register
        #define PROTOCOL_COMMAND_REGISTER_PTR   ((_Command_Status_t*)&(statusRegisterArray[4][0])) //!< This is the pointer to the COMMAND status register
        #define PROTOCOL_BATTERY_REGISTER_PTR   ((_Battery_Status_t*)&(statusRegisterArray[5][0])) //!< This is the pointer to the BATTERY status register
        /** @}*/  // moduleData
    
        //_________________________ MODULE TYPEDEF DEFINITION _______________________

        /**
        * \defgroup typeDef Registers type definition
        * 
        * This section describes the typedf and struct defining the  
        * status register structures
        * 
        *  @{
        */
    
            /** 
             * ***REVISION STATUS REGISTER***
             * 
             * This is the structure of the Revision register content
             * 
             * The register data content is:
             * 
             * |BYTE|DESCRIPTION|
             * |:---:|:---|
             * |D0|Revision Major number|
             * |D1|Revision Minor number|
             * |D2|Revision Sub number|
             * |D3|-|
             * 
             * 
             */  
            typedef struct {
              uint8_t maj;  //!< D0 - This is the Major revision number
              uint8_t min;  //!< D1 - This is the minor revision number
              uint8_t sub;  //!< D2 - This is the Sub-minor revision number
              uint8_t d3;   //!< D3 - NA
            }_Revision_Status_t;

            /** 
            * ***SYSTEM  STATUS REGISTER***
            * 
            * This is the structure of the System status register content
            * 
            * The register data content is:
            * |BYTE|BIT|DESCRIPTION|
            * |:---:|:---:|:---|
            * |D0|0|The board is in error condition|
            * |D0|1|The Emergency button is pressed|
            * |D0|2|The Powerdown status is detected|
            * |D0|3|The Motor safety input is active|
            * |D0|4|The soft power off sequence has been requested|
            * |D0|5|The Battery 1 level is Low|
            * |D0|6|The Battery 2 level is Low|
            * |D0|7|The Battery Enable button is activated|
            * ||||
            * |D1|0|C-ARM UP activation request|
            * |D1|1|C-ARM DOWN activation request|
            * |D1|2|Slide Up request|
            * |D1|3|Slide Down request|
            * |D1|4|C-ARM rotation CW request|
            * |D1|5|C-ARM rotation CCW request|
            * |D1|6|Body rotation CW request|
            * |D1|7|Body rotation CCW request|
            * ||||
            * |D2|0|External Motor Power supply DC-OK flag|
            * |D2|1|Motor Power Supply activation status|
            * |D2|2|Compression-ON signal status|
            * |D2|3|X-RAY push button Status|
            * |D2|4|Closed Door Status|
            * |D2|5|Burnin Jumper presence detection|
            * |D2|6|-|
            * |D2|7|-|
            * ||||
            * |D3|0|PEDAL_CARM_UP input detection|
            * |D3|1|PEDAL_CARM_DWN input detection|
            * |D3|2|PEDAL_CMP_UP input detection|
            * |D3|3|PEDAL_CMP_DWN input detection|
            * |D3|4|-|
            * |D3|5|-|
            * |D3|6|-|
            * |D3|7|-|
            * 
            * For details about the iimplementation see the 
            * + Gantry Software Detailed Documentation
            *  + Power Service Protocol Specification
            */  
            typedef struct {

                struct{
                    uint8_t error:1; //!< D0.0 - This flag shall be set when an error is detected
                    uint8_t emergency_button:1; //!< D0.1 - This flag is set when the emergency button is detected activated
                    uint8_t powerdown_detected:1; //!< D0.2 - This flag shall be set when the Powerdown condiion is detected
                    uint8_t motor_safety:1; //!< D0.3 - This flag shall be set when the motor safety input is ON (safer condition)
                    uint8_t soft_poweroff_request:1;//!< D0.4 - This flag shall be set when a soft power off is requested to the Master
                    uint8_t batt1_low:1;//!< D0.5 - This flag shall be set when the battery1 level is detected low
                    uint8_t batt2_low:1;//!< D0.6 - This flag shall be set when the battery2 level is detected low
                    uint8_t battery_enable_button:1;//!< D0.7 - This flag shall be set when the battery enable button is detected ON
                }D0;

                struct{
                    uint8_t carm_up:1; //!< D1.0 - This flag shall be set to request the C-ARM UP manual activation
                    uint8_t carm_dwn:1; //!< D1.1 - This flag shall be set to request the C-ARM DWN manual activation
                    uint8_t slide_up:1; //!< D1.2 - This flag shall be set to request the SLIDE UP manual activation
                    uint8_t slide_dwn:1; //!< D1.3 - This flag shall be set to request the SLIDE DWN manual activation
                    uint8_t carm_rot_cw:1; //!< D1.4 - This flag shall be set to request the C-ARM Rotation CW manual activation
                    uint8_t carm_rot_ccw:1; //!< D1.5 - This flag shall be set to request the C-ARM Rotation CCW manual activation
                    uint8_t body_rot_cw:1; //!< D1.6 - This flag shall be set to request the Body Rotation CW manual activation
                    uint8_t body_rot_ccw:1; //!< D1.7 - This flag shall be set to request the Body Rotation CCW manual activation
                }D1;

               struct{
                    uint8_t motor_dc_ok:1; //!< D2.0 - This flag shall be set according with the External Motor Power supply DC-OK status
                    uint8_t motor_power_activate:1; //!< D2.1 - This flag shall be set when the motor power supply is activated (external power switch)
                    uint8_t compression_on:1; //!< D2.2 - This flag shall be set accordiing with the status of the COMPRESSION-ON external signal (see Bus Hardware)
                    uint8_t xray_button:1; //!< D2.3 - This flag shall be set according with the xray button activation status
                    uint8_t closed_door:1; //!< D2.4 - This flag shall be set to according with the status of the external CLOSED_DOOR signal
                    uint8_t burnin_jumper:1; //!< D2.5 - This flag shall be set according with the burnin jumper presence detection
                    uint8_t spare_26:1; //!< D2.6 - NA
                    uint8_t spare_27:1; //!< D2.7 - NA
                }D2;

                struct{
                    uint8_t pedal_carm_up:1; //!< D3.0 - This flag shall be set according with the External Pedal C-ARM Up input
                    uint8_t pedal_carm_dwn:1; //!< D3.1 - This flag shall be set according with the External Pedal C-ARM Down input
                    uint8_t pedal_compression_up:1; //!< D3.2 - This flag shall be set according with the External Pedal Compression Up input
                    uint8_t pedal_compression_dwn:1; //!< D3.3 - This flag shall be set according with the External Pedal Compression Down input
                    uint8_t spare_34:1; //!< D3.4 - NA
                    uint8_t spare_35:1; //!< D3.5 - NA
                    uint8_t spare_36:1; //!< D3.6 - NA
                    uint8_t spare_37:1; //!< D3.7 - NA
                }D3;

            }_System_Status_t;

            /** 
             * ***ERRORS  STATUS REGISTER***
             * 
            * This is the structure of the Errors status register content
            * 
            * The register data content is:
            * 
            * |BYTE|BIT|DESCRIPTION|
            * |:---:|:---:|:---|
            * |D0|0|Manual C-Arm-Up Lock|
            * |D0|1|Manual C-Arm-Down Lock|
            * |D0|2|Manual Rot-CW Lock|
            * |D0|3|Manual Rot-CCW Lock|
            * |D0|4|Manual Slide-Up Lock|
            * |D0|5|Manual Slid-Down Lock|
            * |D0|6|Manual Gantry Body CW Lock|
            * |D0|7|Manual Gantry Body CCW Lock|
            * ||||
            * |D1|0|Pedal Rot-Up Lock|
            * |D1|1|Pedal Rot-Down Lock|
            * |D1|2|Compressor-Up Lock|
            * |D1|3|Compressor-Down Lock|
            * |D1|4|-|
            * |D1|5|-|
            * |D1|6|-|
            * |D1|7|-|
            * ||||
            * |D2|0|X-Ray button Lock|
            * |D2|1|-|
            * |D2|2|-|
            * |D2|3|-|
            * |D2|4|-|
            * |D2|5|-|
            * |D2|6|-|
            * |D2|7|-|
            * ||||
            * |D3|0|-|
            * |D3|1|-|
            * |D3|2|-|
            * |D3|3|-|
            * |D3|4|-|
            * |D3|5|-|
            * |D3|6|-|
            * |D3|7|-|
            * 
            * For details about the iimplementation see the 
            * + Gantry Software Detailed Documentation
            *  + Power Service Protocol Specification
            */  
            typedef struct {

                struct{
                    uint8_t manual_carm_up_lock:1; //!< D0.0 - This flag shall be set when the manual c-arm up activation is detected in locking status
                    uint8_t manual_carm_dwn_lock:1; //!< D0.1 - This flag shall be set when the manual c-arm dwn activation is detected in locking status
                    uint8_t manual_rot_cw_lock:1; //!< D0.2 - This flag shall be set when the manual rot-cw activation is detected in locking status
                    uint8_t manual_rot_ccw_lock:1; //!< D0.3 - This flag shall be set when the manual rot-ccw activation is detected in locking status
                    uint8_t manual_slide_up_lock:1;//!< D0.4 - This flag shall be set when the manual slide-up activation is detected in locking status
                    uint8_t manual_slide_dwn_lock:1;//!< D0.5 - This flag shall be set when the manual slide-dwn activation is detected in locking status
                    uint8_t manual_body_cw_lock:1;//!< D0.6 - This flag shall be set when the manual body cw activation is detected in locking status
                    uint8_t manual_body_ccw_lock:1;//!< D0.7 - This flag shall be set when the manual body ccw activation is detected in locking status
                }D0;

                struct{
                    uint8_t pedal_up_lock:1; //!< D1.0 - This flag shall be set when the PEDAL UP input is in locking status
                    uint8_t pedal_dwn_lock:1; //!< D1.1 - This flag shall be set when the PEDAL DOWN input is in locking status
                    uint8_t pedal_cmp_up_lock:1; //!< D1.2 - This flag shall be set when the PEDAL COMPRESSION UP input is in locking status
                    uint8_t pedal_cmp_dwn_lock:1; //!< D1.3 - This flag shall be set when the PEDAL COMPRESSION DOWN input is in locking status
                    uint8_t spare_14:1; //!< D1.4 - NA
                    uint8_t spare_15:1; //!< D1.5 - NA
                    uint8_t spare_16:1; //!< D1.6 - NA
                    uint8_t spare_17:1; //!< D1.7 - NA
                }D1;

               struct{
                    uint8_t xray_button_lock:1; //!< D2.0 - This flag shall be set when the XRAY Button input is in locking status
                    uint8_t spare_21:1; //!< D2.1 - NA
                    uint8_t spare_22:1; //!< D2.2 - NA
                    uint8_t spare_23:1; //!< D2.3 - NA
                    uint8_t spare_24:1; //!< D2.4 - NA
                    uint8_t spare_25:1; //!< D2.5 - NA
                    uint8_t spare_26:1; //!< D2.6 - NA
                    uint8_t spare_27:1; //!< D2.7 - NA
                }D2;

                struct{
                    uint8_t spare_30:1; //!< D3.0 - NA
                    uint8_t spare_31:1; //!< D3.1 - NA
                    uint8_t spare_32:1; //!< D3.2 - NA
                    uint8_t spare_33:1; //!< D3.3 - NA
                    uint8_t spare_34:1; //!< D3.4 - NA
                    uint8_t spare_35:1; //!< D3.5 - NA
                    uint8_t spare_36:1; //!< D3.6 - NA
                    uint8_t spare_37:1; //!< D3.7 - NA
                }D3;

            }_Errors_Status_t;
        
            /** 
             * ***COMMAND STATUS REGISTER***
             * 
             * This is the structure of the Command register content
             * 
             * The register data content is:
             * 
             * |BYTE|DESCRIPTION|
             * |:---:|:---|
             * |D0|-|
             * |D1|-|
             * |D2|-|
             * |D3|-|
             * 
             * 
             */  
            typedef struct {
              uint8_t d0;  //!< D0 - This is the measured voltage on the battery 1
              uint8_t d1;  //!< D1 - This is the measured voltage on the battery 2
              uint8_t d2;       //!< D2 - NA
              uint8_t d3;       //!< D3 - NA
            }_Command_Status_t;
        
            /** 
             * ***BATTERY STATUS REGISTER***
             * 
             * This is the structure of the Battery register content
             * 
             * The register data content is:
             * 
             * |BYTE|DESCRIPTION|
             * |:---:|:---|
             * |D0|Battery 1 measured voltage|
             * |D1|Battery 2 measured voltage|
             * |D2|-|
             * |D3|-|
             * 
             * 
             */  
            typedef struct{
              uint8_t voltageBat1;  //!< D0 - This is the measured voltage on the battery 1
              uint8_t voltageBat2;  //!< D1 - This is the measured voltage on the battery 2
              uint8_t d2;           //!< D2 - NA
              uint8_t d3;           //!< D3 - NA
            }_Battery_Status_t;
        
        /** @}*/  // typeDef
        
         //_________________________ MODULE MACRO DEFINITION _______________________
        /**
         * \defgroup applicationMacro  Registers application Macro
         * 
         * This section describes the macros to be used in the Application to point to the 
         * registers and data bit
         * 
         *  @{
         */

            /**
             * \defgroup revisionMacro  REVISION Registers application Macro
             *  @{
             */
                #define PROTOCOL_MAJ_REVISION  PROTOCOL_REVISION_REGISTER_PTR->maj //!< This is the Major revision number field
                #define PROTOCOL_MIN_REVISION  PROTOCOL_REVISION_REGISTER_PTR->min //!< This is the Minor revision number field
                #define PROTOCOL_SUB_REVISION  PROTOCOL_REVISION_REGISTER_PTR->sub //!< This is the Sub revision number field
            /** @}*/  // revisionMacro
        
            /**
             * \defgroup systemMacro  SYSTEM Registers application Macro
             *  @{
             */
                #define PROTOCOL_SYSTEM_ERROR  PROTOCOL_SYSTEM_REGISTER_PTR->D0.error //!< This is the error bit in the system register
                #define PROTOCOL_SYSTEM_EMERGENCY  PROTOCOL_SYSTEM_REGISTER_PTR->D0.emergency_button //!< This is the emergency_button bit in the system register
                #define PROTOCOL_SYSTEM_POWERDOWN  PROTOCOL_SYSTEM_REGISTER_PTR->D0.powerdown_detected //!< This is the powerdown_detected bit in the system register
                #define PROTOCOL_SYSTEM_MOTOR_SAFETY  PROTOCOL_SYSTEM_REGISTER_PTR->D0.motor_safety //!< This is the motor_safety bit in the system register
                #define PROTOCOL_SYSTEM_SOFT_POWEROFF  PROTOCOL_SYSTEM_REGISTER_PTR->D0.soft_poweroff //!< This is the  soft_poweroff bit in the system register
                #define PROTOCOL_SYSTEM_BATT1_LOW  PROTOCOL_SYSTEM_REGISTER_PTR->D0.batt1_low //!< This is the  batt1_low bit in the system register
                #define PROTOCOL_SYSTEM_BATT2_LOW  PROTOCOL_SYSTEM_REGISTER_PTR->D0.batt2_low //!< This is the  batt2_low bit in the system register
                #define PROTOCOL_SYSTEM_BATTENA  PROTOCOL_SYSTEM_REGISTER_PTR->D0.battery_enable_button //!< This is the  battery_enable_button bit in the system register
                #define PROTOCOL_SYSTEM_CARM_UP  PROTOCOL_SYSTEM_REGISTER_PTR->D1.carm_up //!< This is the c-arm up request flag
                #define PROTOCOL_SYSTEM_CARM_DWN  PROTOCOL_SYSTEM_REGISTER_PTR->D1.carm_dwn //!< This is the c-arm down request flag
                #define PROTOCOL_SYSTEM_SLIDE_UP  PROTOCOL_SYSTEM_REGISTER_PTR->D1.slide_up //!< This is the slide up request flag
                #define PROTOCOL_SYSTEM_SLIDE_DWN  PROTOCOL_SYSTEM_REGISTER_PTR->D1.slide_dwn //!< This is the slide down request flag
                #define PROTOCOL_SYSTEM_ROT_CW  PROTOCOL_SYSTEM_REGISTER_PTR->D1.carm_rot_cw //!< This is the c-arm rot cw request flag
                #define PROTOCOL_SYSTEM_ROT_CCW  PROTOCOL_SYSTEM_REGISTER_PTR->D1.carm_rot_ccw //!< This is the c-arm rot ccw request flag
                #define PROTOCOL_SYSTEM_BODY_CW  PROTOCOL_SYSTEM_REGISTER_PTR->D1.body_rot_cw //!< This is the body rot cw request flag
                #define PROTOCOL_SYSTEM_BODY_CCW  PROTOCOL_SYSTEM_REGISTER_PTR->D1.body_rot_ccw //!< This is the body rot ccw request flag
                #define PROTOCOL_SYSTEM_MOT_DCOK  PROTOCOL_SYSTEM_REGISTER_PTR->D2.motor_dc_ok //!< This is the motor DC-OK power DC flag
                #define PROTOCOL_SYSTEM_MOT_POWER_ON  PROTOCOL_SYSTEM_REGISTER_PTR->D2.motor_power_activate //!< This is the Motor power activatin status
                #define PROTOCOL_SYSTEM_COMPRESSION_ON  PROTOCOL_SYSTEM_REGISTER_PTR->D2.compression_on //!< This is Compression On status
                #define PROTOCOL_SYSTEM_XRAY_BUTTON  PROTOCOL_SYSTEM_REGISTER_PTR->D2.xray_button //!< This is the X-RAY button activation status
                #define PROTOCOL_SYSTEM_CLOSED_DOOR  PROTOCOL_SYSTEM_REGISTER_PTR->D2.closed_door //!< This is the Closed-Door activation status
                #define PROTOCOL_SYSTEM_BURNIN_JUMPER  PROTOCOL_SYSTEM_REGISTER_PTR->D2.burnin_jumper //!< This is the burnin jumper presence
                #define PROTOCOL_SYSTEM_PEDAL_UP        PROTOCOL_SYSTEM_REGISTER_PTR->D3.pedal_carm_up //!< This is the Pedal Up input status
                #define PROTOCOL_SYSTEM_PEDAL_DWN       PROTOCOL_SYSTEM_REGISTER_PTR->D3.pedal_carm_dwn //!< This is the Pedal Down input status
                #define PROTOCOL_SYSTEM_PEDAL_CMP_UP    PROTOCOL_SYSTEM_REGISTER_PTR->D3.pedal_compression_up //!< This is the Pedal Compression Up input status
                #define PROTOCOL_SYSTEM_PEDAL_CMP_DWN   PROTOCOL_SYSTEM_REGISTER_PTR->D3.pedal_compression_dwn //!< This is the Pedal Compression Down input status
            /** @}*/  // systemMacro

            /**
             * \defgroup errorsMacro  ERRORS Registers application Macro
             *  @{
             */
                #define PROTOCOL_ERRORS_MAN_CARM_UP_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_carm_up_lock      //!< This is the Manual C-Arm Up locking error
                #define PROTOCOL_ERRORS_MAN_CARM_DWN_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_carm_dwn_lock    //!< This is the Manual C-Arm Down locking error
                #define PROTOCOL_ERRORS_MAN_ROT_CW_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_rot_cw_lock        //!< This is the Manual C-Arm Rot CW locking error
                #define PROTOCOL_ERRORS_MAN_ROT_CCW_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_rot_ccw_lock      //!< This is the Manual C-Arm Rot CCW locking error  
                #define PROTOCOL_ERRORS_MAN_SLIDE_UP_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_slide_up_lock    //!< This is the Manual Slide-Up locking error
                #define PROTOCOL_ERRORS_MAN_SLIDE_DWN_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_slide_dwn_lock  //!< This is the Manual Slide-Down locking error
                #define PROTOCOL_ERRORS_MAN_BODY_CW_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_body_cw_lock      //!< This is the Manual Body Rot CW locking error
                #define PROTOCOL_ERRORS_MAN_BODY_CCW_LOCK  PROTOCOL_ERRORS_REGISTER_PTR->D0.manual_body_ccw_lock    //!< This is the Manual Body Rot CCW locking error    
            /** @}*/  // errorsMacro
        
            /**
                * \defgroup batteryMacro  BATTERY Registers application Macro
                *  @{
                */
                   #define PROTOCOL_BATTERY_VBATT1  PROTOCOL_BATTERY_REGISTER_PTR->voltageBat1      //!< This is the voltage of the Battery 1
                   #define PROTOCOL_BATTERY_VBATT2  PROTOCOL_BATTERY_REGISTER_PTR->voltageBat2      //!< This is the voltage of the Battery 2
            /** @}*/  // batteryMacro

        
        /** @}*/  // applicationMacro
        
        

/** @}*/  // Status register group defintion
         
/** @}*/ // protocolModule
#endif 