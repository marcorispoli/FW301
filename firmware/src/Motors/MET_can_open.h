#ifndef _MET_CAN_OPEN_H    /* Guard against multiple inclusion */
#define _MET_CAN_OPEN_H


#include "definitions.h"                // SYS function prototypes



#undef ext
#undef ext_static

#ifdef _MET_CAN_OPEN_C
    #define ext
    #define ext_static static 
#else
    #define ext extern
    #define ext_static extern
#endif

/*!
 * \defgroup metCanOpenModule  CAN OPEN Communication Engine Module
 *
 * \ingroup libraryModules
 * 
 * # Overview
 *
 * This module implements the CAN OPEN communication protocol to 
 * control the Nanotec motors.
 * 
 * # Communication settings
 * 
 * The CAN communication is based on the following 
 * characteristics:
 * 
 * - Standard (not Flexible) communication;
 * - Standard frame (11 bit ID);
 * - Baude Rate: 1Mb/s;
 * - Can ID reception address: 0x200 + deviceID;
 * 
 * The deviceID is a decimal value from 1 to 255.
 * 
 * # Harmony 3 Configurator Settings
 * 
 * This Module makes use of the following Processor modules:
 * - CAN0 peripheral module;
 * - Peripheral Can0 clock;
 * - PIN Assignement;
 * - SYSTEM Memory;
 * 
 * ## SYSTEM Peripheral module setup
 * 
 * This Module makes use of the Smart EEPROM feature of the microcontroller.
 * The module shall provides 256 32-bit word to be assigned to parameters.
 * According with this requisite the SYSTEM peripheral module shall be set as follow:
 * + SYSTEM/Device & Project Configuration/ATSAME51J20A Device Configuration/Fuse settings:
 *  + Number Of Phisical NVM Blocks Composing a SmartEEPROM Sector = 1;
 *  + Size Of SmartEEPROM Page = 1;
 * 
 * ## Pin Assignement
 * 
 * + The CAN TX Input shall be configured with CAN0-TX 
 * + The CAN RX Input shall be configured with CAN0-TX 
 * 
 * ## Peripheral Clock Settings
 * 
 *+ Activate the GLK4 Clock:
 *   + Set the DFLL (48MHz) as the Input clock;
 *   + Set the divisor to 2 to obtain a final 24MHz of GLK4 Clock;
 *   + The CAN0 Peripheral clock shall be configured with the GLK4 clock at 24 MHz.
 * 
 * ## CAN0 peripheral module
 * 
 * Follows only those settings that shall be activated.
 * What is not reported is disabled or not modified.
 * 
 * + CAN Operational Mode = NORMAL;
 * + Interrupt Mode: Yes;
 * + Bit Timing Calculation
 *  + Nominal Bit Timing
 *      + Automatic Nominal Bit Timing: Yes;
 *      + BIt Rate: 1000
 * 
 * + Use RX FIFO 0: Yes
 *   + RX FIFO 0 Setting
 *      + Number of element: 1
 * 
 * + Use TX FIFO: Yes
 *   + TX FIFO Setting
 *      + Number of element: 1
 *
 * + EnableTX Pause: YES
 * + Standard Filters 
 *  + Number Of STandard Filters: 1
 *  + Standard Filter 1
 *      + Type: Range;
 *      + ID1: 0x200 + Device ID
 *      + ID12: 0x200 + Device ID
 *      + Element Configuration: Store in RX FIFO 0
 *  + Standard message No-Match disposion: Reject
 *  + Reject Standard Remote Frames: YES
 *  + Timestamp Enable: YES 
 * 
 *  # Application Usage
 * 
 *    @{
 * 
 */
        #define cGRADsec_TO_ROT_min(x)     ((int32_t) x *  (int32_t)MOTOR_GEAR * (int32_t)SPEED_DENOMINATOR/(int32_t) 3600) 
        #define cGRAD_TO_ENCODER(x)        ((int32_t) x * (int32_t) MOTOR_GEAR / (int32_t) 180)
        #define ENCODER_TO_cGRAD(x)        ((int32_t) x * (int32_t) 180 / (int32_t) MOTOR_GEAR)
        #define END_ODVECTOR {0,0,0,0}

        


        typedef enum{
            WORKFLOW_INITIALIZATION=0,
            WORKFLOW_ZERO_SETTING,
            WORKFLOW_GET_CIA_STATUS,
            WORKFLOW_CIA_NOT_READY_TO_SWITCH_ON,
            WORKFLOW_CIA_SWITCH_ON_DISABLED,
            WORKFLOW_CIA_READY_TO_SWITCH_ON,
            WORKFLOW_CIA_SWITCHED_ON,
            WORKFLOW_POSITIONING,
            WORKFLOW_CIA_OPERATION_ENABLED,
            WORKFLOW_CIA_QUICK_STOP_ACTIVE,
            WORKFLOW_CIA_QUICK_STOP_ACTIVATION,
            WORKFLOW_CIA_FAULT_REACTION_ACTIVE,
            WORKFLOW_CIA_FAULT,
        }MET_CANOPEN_WORKFLOW_e;
        
        
        /** 
         * @brief CanOpen Protocol Error codes
         * 
         * Those errors are generated into the module in case
         * of some function should fail. When a error is detected, 
         * the error is provided to an internal error handler: MET_CanOpen_Error_Callback()
         * 
         */ 
        typedef enum
        {    
            MET_CANOPEN_PROTOCOL_ERROR_OK=0, //!< No error
            MET_CANOPEN_PROTOCOL_ERROR_RECEPTION_ACTIVATION, //!< Error in activating the reception
            MET_CANOPEN_PROTOCOL_ERROR_TRANSMISSION, //!> Error during data transmission       
            MET_CANOPEN_PROTOCOL_ERROR_INVALID_CRC, //!> Frame with invalid CRC received        
            MET_CANOPEN_PROTOCOL_ERROR_INVALID_LENGHT, //!> Frame with invalid Lenght
                        
        } MET_CANOPEN_PROTOCOL_ERROR_DEFS;
        
    /** 
     * \defgroup metCanOpenData  Module data structures
     * 
     * This section implements the data structures of the module
     *  @{
     */
        #define _CAN_ID_BASE_ADDRESS 0x200 //!< This is the base address for the communication point to point
        #define _CAN_ID_LOADER_ADDRESS 0x100 //!< This is the base address for the Loader frames


        /**
         * This is the Protocol frame data content
         */
        typedef struct {
            uint8_t seq;        //!< Frame sequence number
            uint8_t frame_cmd;  //!< Frame command code  
            uint8_t idx;        //!< This is the IDX field
            uint8_t d[4];       //!< Frame data content
            uint8_t crc;        //!< Frame CRC
        }MET_CanOpen_Frame_t;
        
        typedef uint8_t (*MET_canOpenWorkflow)(void);
        
        typedef struct {
            uint16_t idx;
            uint8_t  sub;
            uint8_t  type;
            uint32_t val;
        }MET_canOpen_Config_t;
        
        
        typedef struct {
            const MET_canOpen_Config_t*   config;
            MET_canOpen_Config_t*   positionRegisters;
            int32_t (*getAnalogToPositionConversion)(uint16_t);
            int32_t (*getPositionToEncoderConversion)(int32_t);
            int32_t (*getEncoderToPositionConversion)(int32_t);
            
            
            uint8_t execution_command;
            int32_t target_position;
            
            uint8_t deviceId;
            uint8_t workflow;
            uint8_t workflow_step;
            bool    initialized;        //!< The configuration file has been uploaded and stored
            bool    wait_zero_setting;  //!< The device needs the zero setting procedure
            int32_t analog1;           //!< This is the last Analog 1 read value
            int32_t position;          //!< This is the last position value
            
            uint16_t index;             //!< Register index 
            uint16_t chk;               //!< Configuration Checksum
            uint8_t error_class;        //!< Fault error class
            uint32_t error_code;        //!< Fault error code
        }canOpen_workflowData_t;
        
        typedef enum{
            ARM = 0,
            LIFT,
            BODY,
            MAX_CANOPEN_DEVICE        
        }MET_DEVICE_e;
        
        typedef enum{
            NO_COMMAND = 0,
            ACTIVATE_ARM,
            ACTIVATE_BODY,
            ACTIVATE_LIFT,
            ACTIVATE_ARM_LIFT        
        }MET_CanOpen_Commands_e;
        
        typedef enum{
            COMMAND_COMPLETED = 0,
            COMMAND_EXECUTING,        
            COMMAND_ERROR,
        }MET_CanOpen_Commands_Completed_e;
        
      
        
        typedef struct {
            // Reception packets
            uint32_t rx_messageID; //!< Received ID frame (11bit)
            uint8_t rx_message[8]; //!< Received data byte
            uint8_t rx_messageLength;//!< Received data lenght
            uint16_t rx_timestamp; //!< Received Time stamp
            bool rxReceptionTrigger; //!< RX received frame flag
            bool rxErrorTrigger ;//!< TX received frame flag
            bool isWaiting; //!< Is waiting a reception
            uint8_t rx_tmo; //!< Timeout reception time
            
            uint8_t tx_message[8]; //!< transmitted data byte
            
            // Workflow management
            uint8_t currentDevice;
            canOpen_workflowData_t workflowData[MAX_CANOPEN_DEVICE];
            
            // Command management
            MET_CanOpen_Commands_e current_command;
            MET_CanOpen_Commands_Completed_e command_result;
            bool abort_request;
            
        } MET_CanOpen_Data_t;
        
       
        
        #define NO_EXECECUTION_COMMAND             0
        #define EXEC_POSITIONING    1

        
    /** @}*/  // metCanOpenData

/** @}*/  // metCanOpenModule
        


/******************************************************************************/
/*                      API DI ISTALLAZIONE PROTOCOLLO                        */
/******************************************************************************/
        

        
     /** 
     * \defgroup metCanOpenApi  Module Installation API
     * 
     * \ingroup metCanOpenModule
     * This section providides the API for the canOPEN protocol integration.
     * 
     *  @{
     */
        
        /// Can protocol initialization
        ext void MET_CanOpen_Protocol_Init(void);
        
        /// Application Main Loop function handler
        ext void MET_CanOpen_Protocol_Loop(void);  
        
        ext uint8_t  motorDeviceActivate(uint8_t command, int32_t val);
        ext void motorDeviceAbort(void);
        
     /** @}*/  // metCanOpenApi
        
        
        ext MET_CanOpen_Data_t MET_CanOpen_Data_Struct; //!< This is the internal protocol data structure
        
        ext void changeDevice(void);
        ext bool MET_canOpen_WriteSDO(uint16_t idx, uint8_t sub, uint8_t odt, uint32_t d, uint8_t tmo);
        ext bool MET_canOpen_ReadSDO(uint16_t idx, uint8_t sub, uint8_t odt, uint8_t tmo);
        ext void MET_CanOpen_Protocol_Register_Update(void);
        
        ext bool        MET_canOpen_isOdOk(void);
        ext uint8_t     MET_canOpen_getOdType(void);
        ext uint16_t    MET_canOpen_getOdId(void);
        ext uint8_t     MET_canOpen_getOdSub(void);
        ext uint32_t    MET_canOpen_getOdVal(void);
        ext uint8_t     MET_canOpen_GetCiaStatus(void);


#endif /* _MET_CAN_OPEN_H */

/* *****************************************************************************
End of File
*/
