#ifndef _PROTOCOL_H    
#define _PROTOCOL_H

#include "definitions.h"  
#include "application.h"  
#include "Shared/CAN/MET_can_protocol.h"

#undef ext
#undef ext_static

#ifdef _PROTOCOL_C
    #define ext
    #define ext_static static 
#else
    #define ext extern
    #define ext_static extern
#endif



/*!
 * \defgroup protocolModule CAN Communication Protocol Module
 *
 * \ingroup applicationModule
 * 
 * 
 * This Module implements the functions of the PCB/22-301 Software Communication protocol specifications.
 * 
 * ## Dependencies
 * 
 * This module requires the following library modules:
 * - Shared/CAN/MET_Can_Protocol.c
 * - Shared/CAN/MET_Can_Protocol.h
 * 
 * 
 * ## Protocol Communication setting
 *  
 * The Application implements the communication protocol  
 * described in the PCB/22-301 Software Communication protocol specifications.
 * 
 *  @{
 * 
 */

    /**
     * \defgroup moduleConstants Constants module definition
     * 
     * This section describes the module constants
     * 
     *  @{
     */
        // Can Module Definitions
     #define   MET_CAN_APP_DEVICE_ID      0x10     //!< Application DEVICE CAN Id address
       
     /// @}   moduleConstants

    /**
     * \defgroup moduleApiInterface CAN Protocol API interface
     * 
     * This section describes the functions implementing the Protocol module.
     * 
     *  @{
     */
        /// This is the Protocol initialization function
        ext void ApplicationProtocolInit ( void);

        /// This is the Main Loop protocol function
        ext void  ApplicationProtocolLoop(void);

        /// This is the 7.280ms rtc function 
        ext void Protocol_7280_us_callback(void);
         
     /// @}   moduleApiInterface
    

    /** \defgroup StatusRegisterGroup STATUS REGISTERS Definition
     *  
     *  This section describes the implementation of the Application STATUS Registers 
     *  @{
     */
        
     /// This is the list of the implemented STATUS REGISTERS    
     typedef enum{
        PROTOCOL_STATUS_SYSTEM_IDX = 0,      //!< STATUS-SYSTEM Register Index definition
        PROTOCOL_STATUS_BATTERY_IDX = 1,     //!< STATUS-BATTERY Register Index definition  
        PROTOCOL_STATUS_LENGHT               //!< Total number of Status registers
     }PROTO_STATUS_t;
     
     /// @}   StatusRegisterGroup

     
    /** \defgroup DataRegisterGroup DATA REGISTERS Definition
     *  
     *  This section describes the implementation of the Protocol DATA Registers 
     *  @{
     */

         /// This is the list of the implemented DATA REGISTERS    
         typedef enum{
            PROTOCOL_DATA_OUTPUTS_IDX = 0, //!< DATA-OUTPUT Register Index definition
            PROTOCOL_DATA_LENGHT            //!< Total number of Data registers
         }PROTO_DATA_t;
        
    /// @}   DataRegisterGroup

    /** \defgroup ParamRegisterGroup PARAMETER Registers Definition
     *  
     *  This section describes the implementation of the Application PARAMETER Registers 
     *  @{
     */
        
        /// This is the list of the implemented PARAMETER REGISTERS        
        typedef enum{
            POWER_ON_OFF_DELAY = 0, //!< This is the parameter setting the delay between power On Off events
            HARDWARE_POWER_OFF_TIME = 1, //!< This is the parameter setting the button pression time to activate a Hard Power Off
            KEEP_ALIVE_POWER_OFF = 2,//!< This is the parameter setting the Keep Alive time during a Powerdown condition
            SOFT_POWER_OFF_DELAY = 3,//!< This is the parameter setting the delay waiting the soft power off
            LOW_BATT_LEVELS = 4,//!< This is the parameter setting the battery voltage level for low batt signaling
            BODY_ROTATION_LOCK_TIME = 5,//!< This is the parameter setting the lock/unlock time of the BODY ROTATION activation
            PEDALBOARD_LOCK_TIME = 6,//!< This is the parameter setting the lock/unlock time of the PEDALBOARD activation
            MANUAL_ROT_LOCK_TIME = 7,//!< This is the parameter setting the lock/unlock time of the MANUAL ROTATION activation
            XRAY_BUTTON_LOCK_TIME = 8,//!< This is the parameter setting the lock/unlock time of the XRAY BUTTON                     
            PROTOCOL_PARAMETER_LENGHT     //!< Total number of Parameter registers
        }PROTO_PARAMETERS_t;

    /// @}   ParamRegisterGroup
        
        
     /** \defgroup CommandGroup COMMAND Execution Definition
     *  
     *  This section describes the Application Command Execution codes
     *  @{
     */
        
        /// This is the list of the implemented COMMANDS
        typedef enum{
          RESERVED_COMMAND = 0,   
          ACTIVATE_SOFT_POWEROFF = 1 //!< Request for the Power Off Activation    
        }PROTO_COMMAND_ENUM_t;

        /// This is the list of the implemented ERRORS
        typedef enum{
            PROTO_COMMAND_FIRST_ERROR = MET_CAN_COMMAND_APPLICATION_ERRORS, 

        }PROTO_COMMAND_ERROR_ENUM_t;

     /// @}   CommandGroup

        
    /** \defgroup macroStatusRegister STATUS Register Access Macros
     *  
     *  This section describes the Macro to access the Status Registers content
     *  @{
     */
       
        #define SETBIT_PROTOCOL_SYSTEM_ERROR(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x1, val) //!< This is the error bit in the system register
        #define SETBIT_PROTOCOL_SYSTEM_EMERGENCY(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x2, val) //!< This is the emergency_button bit in the system register
        #define SETBIT_PROTOCOL_SYSTEM_POWERDOWN(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x4, val) //!< This is the powerdown_detected bit in the system register
        #define SETBIT_PROTOCOL_SYSTEM_MOTOR_SAFETY(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x8, val) //!< This is the motor_safety bit in the system register
        #define SETBIT_PROTOCOL_SYSTEM_SOFT_POWEROFF(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x10, val) //!< This is the  soft_poweroff bit in the system register
        #define SETBIT_PROTOCOL_SYSTEM_BATT1_LOW(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x20, val) //!< This is the  batt1_low bit in the system register
        #define SETBIT_PROTOCOL_SYSTEM_BATT2_LOW(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x40, val) //!< This is the  batt2_low bit in the system register
        #define SETBIT_PROTOCOL_SYSTEM_BATTENA(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 0, 0x80, val) //!< This is the  battery_enable_button bit in the system register
        
        #define SETBIT_PROTOCOL_SYSTEM_CARM_UP(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x1, val) //!< This is the c-arm up request flag
        #define SETBIT_PROTOCOL_SYSTEM_CARM_DWN(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x2, val) //!< This is the c-arm down request flag
        #define SETBIT_PROTOCOL_SYSTEM_SLIDE_UP(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x4, val) //!< This is the slide up request flag
        #define SETBIT_PROTOCOL_SYSTEM_SLIDE_DWN(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x8, val) //!< This is the slide down request flag
        #define SETBIT_PROTOCOL_SYSTEM_ROT_CW(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x10, val) //!< This is the c-arm rot cw request flag
        #define SETBIT_PROTOCOL_SYSTEM_ROT_CCW(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x20, val) //!< This is the c-arm rot ccw request flag
        #define SETBIT_PROTOCOL_SYSTEM_BODY_CW(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x40, val) //!< This is the body rot cw request flag
        #define SETBIT_PROTOCOL_SYSTEM_BODY_CCW(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 1, 0x80, val) //!< This is the body rot ccw request flag
        
        #define SETBIT_PROTOCOL_SYSTEM_MOT_DCOK(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 2, 0x1, val) //!< This is the motor DC-OK power DC flag
        #define SETBIT_PROTOCOL_SYSTEM_MOT_POWER_ON(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 2, 0x2, val) //!< This is the Motor power activatin status
        #define SETBIT_PROTOCOL_SYSTEM_COMPRESSION_ON(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 2, 0x4, val) //!< This is Compression On status
        #define SETBIT_PROTOCOL_SYSTEM_XRAY_BUTTON(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 2, 0x8, val) //!< This is the X-RAY button activation status
        #define SETBIT_PROTOCOL_SYSTEM_CLOSED_DOOR(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 2, 0x10, val) //!< This is the Closed-Door activation status
        #define SETBIT_PROTOCOL_SYSTEM_BURNIN_JUMPER(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 2, 0x20, val) //!< This is the burnin jumper presence
        #define SETBIT_PROTOCOL_SYSTEM_POWER_LOCK(val)  MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 2, 0x40, val) //!< This is the power lock activation feedback
        
        #define SETBIT_PROTOCOL_SYSTEM_PEDAL_UP(val)       MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 3, 0x1, val) //!< This is the Pedal Up input status
        #define SETBIT_PROTOCOL_SYSTEM_PEDAL_DWN(val)       MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 3, 0x2, val) //!< This is the Pedal Down input status
        #define SETBIT_PROTOCOL_SYSTEM_PEDAL_CMP_UP(val)    MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 3, 0x4, val) //!< This is the Pedal Compression Up input status
        #define SETBIT_PROTOCOL_SYSTEM_PEDAL_CMP_DWN(val)   MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 3, 0x8, val) //!< This is the Pedal Compression Down input status
        #define SETBIT_PROTOCOL_SYSTEM_MOTORS_IDLE(val)   MET_Can_Protocol_SetStatusBit(PROTOCOL_STATUS_SYSTEM_IDX, 3, 0x10, val) //!< This is the Motor IDLE condition

        #define SETBYTE_PROTOCOL_BATTERY_VBATT1(val)  MET_Can_Protocol_SetStatusReg(PROTOCOL_STATUS_BATTERY_IDX, 0, val )     //!< This is the voltage of the Battery 1
        #define SETBYTE_PROTOCOL_BATTERY_VBATT2(val)  MET_Can_Protocol_SetStatusReg(PROTOCOL_STATUS_BATTERY_IDX, 1, val ) //!< This is the voltage of the Battery 2
        /// @}   macroStatusRegister
        
     /** \defgroup macroDataRegister DATA Register Access Macros
     *  
     *  This section describes the Macro to access the DATA Registers content
     *  @{
     */
        #define TESTBIT_PROTOCOL_PROGRAMMING_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 0,0x1) //!< D0.0 - This flag activates the power auto sustain during a Loader firmware download
        #define TESTBIT_PROTOCOL_MOT_ENA_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 0,0x2) //!< D0.1 - This flag activates ALL the Motor power supply
        #define TESTBIT_PROTOCOL_MOT_SWITCH_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 0,0x4) //!< D0.2 - This flag enable the power supply external switch
        #define TESTBIT_PROTOCOL_COMPRESSOR_ENA_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 0,0x8) //!< D0.3 - This flag enables the compressor driver
        #define TESTBIT_PROTOCOL_CALIB_ENA_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 0,0x10) //!< D0.4 - This flag enables devices to operate calibrations
        #define TESTBIT_PROTOCOL_XRAY_ENA_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 0,0x20) //!< D0.5 - This flag activates the XRAY-ENA signal on the generator interface

        #define TESTBIT_PROTOCOL_BURNIN_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 1,0x1) //!< D1.0 - This flag activates the burnin output
        #define TESTBIT_PROTOCOL_MAN_BUZZER_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 1,0x2) //!< D1.1 - This flag manually activates the buzzer
        #define TESTBIT_PROTOCOL_BUZZER_MODE_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 1,0x4) //!< D1.2 - This flag set the buzzer activation mode
        #define TESTBIT_PROTOCOL_XRAY_LED_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 1,0x8) //!< D1.3 - This flag activate the XRAY-LED output
        #define TESTBIT_PROTOCOL_XRAY_LAMP1_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 1,0x10) //!< D1.4 - This flag activates the external Lamp 1 during Exposure
        #define TESTBIT_PROTOCOL_XRAY_LAMP2_OUT  MET_Can_Protocol_TestData(PROTOCOL_DATA_OUTPUTS_IDX, 1,0x20) //!< D1.5 - This flag activates the external Lamp 2 during Exposure

    /// @}   macroDataRegister
    
     /** \defgroup macroParamRegister PARAMETER Register Access Macros
     *  
     *  This section describes the Macro to access the DATA Registers content
     *  @{
     */
        #define GETBYTE_PARAMETER_POWER_ON_OFF_DELAY MET_Can_Protocol_GetParameter(POWER_ON_OFF_DELAY,0)            //!< Returns the Power On/Off delay time
        #define GETBYTE_PARAMETER_HARDWARE_POWER_OFF_TIME MET_Can_Protocol_GetParameter(HARDWARE_POWER_OFF_TIME,0)  //!< Returns the HArdware Power Off time
        #define GETBYTE_PARAMETER_KEEP_ALIVE_POWER_OFF MET_Can_Protocol_GetParameter(KEEP_ALIVE_POWER_OFF,0)        //!< Returns the Keepalive Power Off time
        #define GETBYTE_PARAMETER_SOFT_POWER_OFF_DELAY MET_Can_Protocol_GetParameter(SOFT_POWER_OFF_DELAY,0)        //!< Returns the Software Power On/Off delay time
        #define GETBYTE_PARAMETER_LOW_BATT1_LEVEL MET_Can_Protocol_GetParameter(LOW_BATT_LEVELS,0)                  //!< Returns the Battery 1 low level
        #define GETBYTE_PARAMETER_LOW_BATT2_LEVEL MET_Can_Protocol_GetParameter(LOW_BATT_LEVELS,1)                  //!< Returns the Battery 2 low level
        
     /// @}   macroParamRegister
        
        
/** @}*/ // protocolModule
#endif 

