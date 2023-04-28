#define _MET_CAN_OPEN_C

#include "application.h"                // SYS function prototypes
#include "MET_can_open.h" 
#include "../Protocol/protocol.h"
#include "OD.h"

extern  void armInitialization(canOpen_workflowData_t* pData);
extern  void liftInitialization(canOpen_workflowData_t* pData);
extern  void bodyInitialization(canOpen_workflowData_t* pData);

#define DEVICE_DATA (&MET_CanOpen_Data_Struct.workflowData[MET_CanOpen_Data_Struct.currentDevice])
#define DEVICE_CONFIG (&MET_CanOpen_Data_Struct.workflowData[MET_CanOpen_Data_Struct.currentDevice])->config
#define DEVICE_POSITIONING (&MET_CanOpen_Data_Struct.workflowData[MET_CanOpen_Data_Struct.currentDevice])->positionRegisters

static uint8_t deviceInitialization(void);
static uint8_t deviceZeroSetting(void);
static uint8_t ciaGetStatus(void);
static uint8_t ciaNotReadyToSwitchOn(void);
static uint8_t ciaSwitchOnDisabled(void);
static uint8_t ciaReadyToSwitchOn(void);
static uint8_t ciaSwitchedOn(void);
static uint8_t positioningExecution(void);
static uint8_t ciaOperationEnabled(void);
static uint8_t ciaQuickStopActive(void);
static uint8_t ciaFaultReactionActive(void);
static uint8_t ciaFault(void);
static uint8_t ciaQuickStopActivation(void);

static void commandExecutionTerminated(uint8_t code);


MET_canOpenWorkflow MET_canOpen_ciaWorkflowVector[]={ \
    deviceInitialization,
    deviceZeroSetting,
    ciaGetStatus,
    ciaNotReadyToSwitchOn,
    ciaSwitchOnDisabled,
    ciaReadyToSwitchOn,
    ciaSwitchedOn,
    positioningExecution,
    ciaOperationEnabled,
    ciaQuickStopActive,
    ciaQuickStopActivation,
    ciaFaultReactionActive,
    ciaFault
};

/**
 * \defgroup metCanOpneImplementation Implementation module
 * 
 * \ingroup metCanOpenModule
 * 
 * This Module provides the implementation details
 * 
 *  @{ 
 */
        
        
        
    /**
     * \defgroup metCanOpenHarmony Harmony 3 necessary declarations
     * 
     * The declaration of this section are necessary for the usage of the CAN channel
     * based on the Harmony 3 configuration library.
     * 
     *  @{
     */ 
        /// Harmony 3 data declaration
        uint8_t Can1MessageRAM[CAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32))); 
        
        /// Attribute used into the CAN Rx/Tx functions
        CAN_MSG_RX_FRAME_ATTRIBUTE msgFrameAttr1 = CAN_MSG_RX_DATA_FRAME; 
        
       
    /** @}*/  // metCanOpenHarmony
    
     /**
     * \defgroup metCanOpenLocal Locale Module function declaration
     * 
     * 
     *  @{
     */        
    
        
        /// Interrupt routine
        static void MET_CanOpen_Protocol_Reception_Callback(uintptr_t context); 

        /// Reception activation routine
        static bool MET_CanOpen_Protocol_Reception_Trigger(uint8_t tmo);     

        
        
    /** @}*/  // metCanOpenLocal

bool MET_CanOpen_Protocol_Reception_Trigger(uint8_t tmo){

    MET_CanOpen_Data_Struct.rxReceptionTrigger = false;
    MET_CanOpen_Data_Struct.rxErrorTrigger = false;
    MET_CanOpen_Data_Struct.rx_tmo = tmo;
    
    // Reception Event callback registered on the FIFO0
    CAN1_RxCallbackRegister( MET_CanOpen_Protocol_Reception_Callback, 0 , CAN_MSG_ATTR_RX_FIFO0 );
    
    // Activate the reception buffer on the FIFO-0
    return CAN1_MessageReceive(&MET_CanOpen_Data_Struct.rx_messageID,
            &MET_CanOpen_Data_Struct.rx_messageLength,
            MET_CanOpen_Data_Struct.rx_message,
            &MET_CanOpen_Data_Struct.rx_timestamp,
            CAN_MSG_ATTR_RX_FIFO0, &msgFrameAttr1);
            
}


void initWorkflow(uint8_t device){
    MET_CanOpen_Data_Struct.workflowData[device].workflow = WORKFLOW_INITIALIZATION;
    MET_CanOpen_Data_Struct.workflowData[device].workflow_step = 0;
    MET_CanOpen_Data_Struct.workflowData[device].initialized = false;
    MET_CanOpen_Data_Struct.workflowData[device].wait_zero_setting = true;    
    MET_CanOpen_Data_Struct.workflowData[device].analog1 = 0;
    MET_CanOpen_Data_Struct.workflowData[device].position = 0;
    MET_CanOpen_Data_Struct.workflowData[device].error_class = 0;
    MET_CanOpen_Data_Struct.workflowData[device].error_code = 0;
    MET_CanOpen_Data_Struct.workflowData[device].execution_command = NO_EXECECUTION_COMMAND;
}

void changeDevice(void){
    
    MET_CanOpen_Data_Struct.currentDevice++;
    if(MET_CanOpen_Data_Struct.currentDevice == MAX_CANOPEN_DEVICE)
        MET_CanOpen_Data_Struct.currentDevice = 0;
    
    MET_CanOpen_Data_Struct.isWaiting = false;
}

void MET_CanOpen_Protocol_Init(void){
        
    
    // Harmony 3 library call: Init memory of the CAN Bus module
    CAN1_MessageRAMConfigSet(Can1MessageRAM);
        
    MET_CanOpen_Data_Struct.currentDevice = 0;
    MET_CanOpen_Data_Struct.current_command = NO_COMMAND;
    MET_CanOpen_Data_Struct.command_result = COMMAND_COMPLETED;
    MET_CanOpen_Data_Struct.abort_request = false;
    
    // Reception data initialization
    MET_CanOpen_Data_Struct.rxReceptionTrigger = false;
    MET_CanOpen_Data_Struct.rxErrorTrigger = false;

    // Init of the device workflow
    for(int i=0; i<MAX_CANOPEN_DEVICE;i++) initWorkflow(i);
    
    armInitialization(&MET_CanOpen_Data_Struct.workflowData[ARM]);
    liftInitialization(&MET_CanOpen_Data_Struct.workflowData[LIFT]);
    bodyInitialization(&MET_CanOpen_Data_Struct.workflowData[BODY]);
        
    return ;
    
 }

void MET_CanOpen_Protocol_Register_Update(void){
    int16_t val =  (MET_CanOpen_Data_Struct.workflowData[ARM].analog1 / 100);
    PROTOCOL_ARMPOS_POTL((val&0xFF));
    PROTOCOL_ARMPOS_POTH((val>>8));
    val =  (MET_CanOpen_Data_Struct.workflowData[ARM].position / 100);
    PROTOCOL_ARMPOS_ENCODERL((val&0xFF));
    PROTOCOL_ARMPOS_ENCODERH((val>>8));
    
    // Set the IDLE condition of the Motor driver
    PROTOCOL_SYSTEM_MOTORS_IDLE(MET_CanOpen_Data_Struct.current_command == NO_COMMAND);
    
}

/**
 * 
 * The function checks the flags rxReceptionTrigger or rxErrorTrigger.
 * 
 * 
 */
void MET_CanOpen_Protocol_Loop(void){
    
    // Evaluates the timeout in reception
    if(MET_CanOpen_Data_Struct.isWaiting){
        
        // Test Index and SubIndex and error returned code
        if(MET_CanOpen_Data_Struct.rxReceptionTrigger){
            if((MET_CanOpen_Data_Struct.rx_message[0] == SDO_ACK_ERR) ||
               (MET_CanOpen_Data_Struct.rx_message[1] != MET_CanOpen_Data_Struct.tx_message[1])||
               (MET_CanOpen_Data_Struct.rx_message[2] != MET_CanOpen_Data_Struct.tx_message[2]) ||
               (MET_CanOpen_Data_Struct.rx_message[3] != MET_CanOpen_Data_Struct.tx_message[3])) 
                    MET_CanOpen_Data_Struct.rxErrorTrigger = true;            
        }else if(!MET_CanOpen_Data_Struct.rxErrorTrigger){
            // Verify the timeout reception
            if(!MET_CanOpen_Data_Struct.rx_tmo) MET_CanOpen_Data_Struct.rxErrorTrigger = true;
            else{
                MET_CanOpen_Data_Struct.rx_tmo--;
                return;
            }
        }
        
        // In case of error condition the current command will be repeated after the device poll
        if(MET_CanOpen_Data_Struct.rxErrorTrigger){
            MET_CanOpen_Data_Struct.isWaiting = false;
            changeDevice();
            return;
        }

    }
    
    // Calls the workflow routine related to the current device
    // After a reception completion, if the workflow return 0, the module change the current device ID
    if((!MET_canOpen_ciaWorkflowVector[DEVICE_DATA->workflow]()) && (!MET_CanOpen_Data_Struct.isWaiting)) changeDevice();

}   


/**
 * @brief CAN Reception Interrupt Handler
 * 
 * This function is assigned in the MET_Can_Protocol_Reception_Trigger() function
 * when the reception is activated. When the interrupt is executed it needs to be 
 * rescheduled in order to be executed again.
 * 
 * The function determines if the interrupt has been generated 
 * because of an error condition or because of a correct 
 * frame received. In both cases a given flag is set so it can be 
 * handled into the MET_Can_Protocol_Loop() function out of the Interrupt context.
 * 
 * 
 * @param context
 */
void MET_CanOpen_Protocol_Reception_Callback(uintptr_t context)
{
 
    uint32_t  status = CAN1_ErrorGet();

    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || 
	((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
    {
        
       
       // SUCCESSO
        MET_CanOpen_Data_Struct.rxReceptionTrigger = true;
        
    }    else
    {
        // ERROR
        MET_CanOpen_Data_Struct.rxErrorTrigger = true;
        
    }
}



bool MET_canOpen_WriteSDO(uint16_t idx, uint8_t sub, uint8_t odt, uint32_t d, uint8_t tmo){
    
    // OD TYPE
    MET_CanOpen_Data_Struct.tx_message[0] = odt; 
    
    // Index
    MET_CanOpen_Data_Struct.tx_message[1] = idx & 0xFF; 
    MET_CanOpen_Data_Struct.tx_message[2] = (idx >> 8 ) & 0xFF;
    
    // Sub Index
    MET_CanOpen_Data_Struct.tx_message[3] = sub; 
    
    // Data
    MET_CanOpen_Data_Struct.tx_message[4] = d & 0xff; d = d >> 8;
    MET_CanOpen_Data_Struct.tx_message[5] = d & 0xff; d = d >> 8;
    MET_CanOpen_Data_Struct.tx_message[6] = d & 0xff; d = d >> 8;
    MET_CanOpen_Data_Struct.tx_message[7] = d & 0xff;
    
    
    // Sends the buffer to the caller
    CAN1_MessageTransmit((uint32_t) 0x600 + (uint32_t) DEVICE_DATA->deviceId, 8, MET_CanOpen_Data_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);      
    // MET_CanOpen_Data_Struct.isWaiting = MET_CanOpen_Protocol_Reception_Trigger(tmo); // Reschedule the new data reception
    MET_CanOpen_Protocol_Reception_Trigger(tmo);
    MET_CanOpen_Data_Struct.isWaiting = true;
    return  MET_CanOpen_Data_Struct.isWaiting;
    
}

bool MET_canOpen_ReadSDO(uint16_t idx, uint8_t sub, uint8_t odt, uint8_t tmo){
     
   
    MET_CanOpen_Data_Struct.tx_message[0] = RD_COMMAND; 
    
    // Index
    MET_CanOpen_Data_Struct.tx_message[1] = idx & 0xFF; 
    MET_CanOpen_Data_Struct.tx_message[2] = (idx >> 8 ) & 0xFF;
    
    // Sub Index
    MET_CanOpen_Data_Struct.tx_message[3] = sub; 
    
    // Data
    MET_CanOpen_Data_Struct.tx_message[4] = 0;
    MET_CanOpen_Data_Struct.tx_message[5] = 0;
    MET_CanOpen_Data_Struct.tx_message[6] = 0;
    MET_CanOpen_Data_Struct.tx_message[7] = 0;
    
    // Sends the buffer to the caller
    CAN1_MessageTransmit((uint32_t) 0x600 + (uint32_t)  DEVICE_DATA->deviceId, 8, MET_CanOpen_Data_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);      
    MET_CanOpen_Data_Struct.isWaiting = MET_CanOpen_Protocol_Reception_Trigger(tmo); // Reschedule the new data reception
    return MET_CanOpen_Data_Struct.isWaiting;
}


uint8_t MET_canOpen_getOdType(void){    
    return MET_CanOpen_Data_Struct.rx_message[0];
}

bool MET_canOpen_isOdOk(void){    
    if(MET_CanOpen_Data_Struct.rx_message[0] == SDO_ACK_ERR) return false;
    else return true;
}

uint16_t MET_canOpen_getOdId(void){    
    return MET_CanOpen_Data_Struct.rx_message[1] + 256 * MET_CanOpen_Data_Struct.rx_message[2];
}
uint8_t MET_canOpen_getOdSub(void){
    return MET_CanOpen_Data_Struct.rx_message[3];
}
uint32_t MET_canOpen_getOdVal(void){
    if(MET_CanOpen_Data_Struct.rx_message[0] == RD_1BYTE) return (uint32_t) MET_CanOpen_Data_Struct.rx_message[4];
    if(MET_CanOpen_Data_Struct.rx_message[0] == RD_2BYTE) return (uint32_t) MET_CanOpen_Data_Struct.rx_message[4] + 256 * (uint32_t) MET_CanOpen_Data_Struct.rx_message[5];
    if(MET_CanOpen_Data_Struct.rx_message[0] == RD_3BYTE) return (uint32_t) MET_CanOpen_Data_Struct.rx_message[4] + 256 * (uint32_t) MET_CanOpen_Data_Struct.rx_message[5] + 256 * 256 * (uint32_t) MET_CanOpen_Data_Struct.rx_message[6];
    if(MET_CanOpen_Data_Struct.rx_message[0] == RD_4BYTE) return (uint32_t) MET_CanOpen_Data_Struct.rx_message[4] + 256 * (uint32_t) MET_CanOpen_Data_Struct.rx_message[5] + 256 * 256 * (uint32_t) MET_CanOpen_Data_Struct.rx_message[6] + 256 * 256 * 256 * (uint32_t) MET_CanOpen_Data_Struct.rx_message[7];
    return 0;
}

uint8_t MET_canOpen_GetCiaStatus(void){
    uint8_t val = MET_CanOpen_Data_Struct.rx_message[4];
    
    if((val & 0x4F) == 0 ) return  WORKFLOW_CIA_NOT_READY_TO_SWITCH_ON;
    else if((val & 0x4F) == 0x40 ) return  WORKFLOW_CIA_SWITCH_ON_DISABLED;
    else if((val & 0x6F) == 0x21 ) return  WORKFLOW_CIA_READY_TO_SWITCH_ON;
    else if((val & 0x6F) == 0x23 ) return  WORKFLOW_CIA_SWITCHED_ON;
    else if((val & 0x6F) == 0x27 ) return  WORKFLOW_CIA_OPERATION_ENABLED;
    else if((val & 0x6F) == 0x7 ) return  WORKFLOW_CIA_QUICK_STOP_ACTIVE;
    else if((val & 0x4F) == 0xF ) return  WORKFLOW_CIA_FAULT_REACTION_ACTIVE;
    else if((val & 0x4F) == 0x8 ) return  WORKFLOW_CIA_FAULT;
    
    return WORKFLOW_CIA_NOT_READY_TO_SWITCH_ON;
    
    
}


uint8_t ciaNotReadyToSwitchOn(void){
    DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
    DEVICE_DATA->workflow_step = 0;
    return 0;
}

uint8_t ciaQuickStopActive(void){
    return ciaSwitchOnDisabled();
}


uint8_t ciaFaultReactionActive(void){
    DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
    DEVICE_DATA->workflow_step = 0;
    return 0;
}

uint8_t ciaQuickStopActivation(void){
     if(MET_CanOpen_Data_Struct.isWaiting){
        MET_CanOpen_Data_Struct.isWaiting = false;        
        
        if(MET_canOpen_getOdType() == WR_ACK_OK) {
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            return 0;
        }
        
       
        uint16_t ctrw = MET_canOpen_getOdVal();
        ctrw &=~ OD_MASK(OD_6040_00_QUICKSTOP);
        ctrw |= OD_VAL(OD_6040_00_QUICKSTOP);
        MET_canOpen_WriteSDO(OD_6040_00,ctrw,2); // Write the control word        
        return 0;
        
    }else{
        MET_canOpen_ReadSDO(OD_6040_00,2); // Read the Control Word
        return 0;
    }
    return 0;
}

uint8_t ciaGetStatus(void){
    
                
     // In case of initialization request, proceed with the Initialization procedure
     if(!DEVICE_DATA->initialized){
        DEVICE_DATA->workflow = WORKFLOW_INITIALIZATION;
        DEVICE_DATA->workflow_step = 0;
        return 0;
    }
    if(DEVICE_DATA->wait_zero_setting){
        DEVICE_DATA->workflow = WORKFLOW_ZERO_SETTING;
        DEVICE_DATA->workflow_step = 0;
        return 0;
    }
     
     switch(DEVICE_DATA->workflow_step){
        case 0:
                       
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
         
               // If the code is the RESET code then the device has been reset
               if(MET_canOpen_getOdVal() == RESET_CODE){                   
                   DEVICE_DATA->initialized = false;
                   return 0;
               }
               
               DEVICE_DATA->workflow_step++;
               break;
           }else{       
                
               MET_canOpen_ReadSDO(RESET_USER_PARAM, 2);
           }
        
        break;
        default: // Read and set the Status word
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;        

                DEVICE_DATA->workflow = MET_canOpen_GetCiaStatus();
                DEVICE_DATA->workflow_step = 0;
                return 0;

            }else{
                MET_canOpen_ReadSDO(OD_6041_00,2);
            }
     }
  
     return 0;
}


uint8_t ciaSwitchOnDisabled(void){
    
     if(MET_CanOpen_Data_Struct.isWaiting){
        MET_CanOpen_Data_Struct.isWaiting = false;        
        
        if(MET_canOpen_getOdType() == WR_ACK_OK) {
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            return 0;
        }
        
        // Set the Shutdown code  To the Ready to SwitchOn Status
        uint16_t ctrw = MET_canOpen_getOdVal();
        ctrw &=~ 0x0087;
        ctrw |= 0x0006;
        MET_canOpen_WriteSDO(OD_6040_00,ctrw,2); // Write the control word        
        return 0;
        
    }else{
        if(!MET_canOpen_ReadSDO(OD_6040_00,2)) return 0; // Read the Control Word
        return 0;
    }
    return 0;
}

uint8_t ciaReadyToSwitchOn(void){
    
    if(MET_CanOpen_Data_Struct.isWaiting){
        MET_CanOpen_Data_Struct.isWaiting = false;        
        
        if(MET_canOpen_getOdType() == WR_ACK_OK) {
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            return 0;
        }
        
        // To Switched On Status
        uint16_t ctrw = MET_canOpen_getOdVal();
        ctrw &=~ 0x008F;
        ctrw |= 0x0007;
        MET_canOpen_WriteSDO(OD_6040_00,ctrw,2); // Write the control word        
        return 0;
        
    }else{
        if(!MET_canOpen_ReadSDO(OD_6040_00,2)) return 0; // Read the Control Word
        return 0;
    }
    return 0;
}

void commandExecutionTerminated(uint8_t code){
    DEVICE_DATA->execution_command = NO_EXECECUTION_COMMAND; 
    MET_CanOpen_Data_Struct.current_command = NO_COMMAND;
    if(code == PROTO_COMMAND_NO_ERR){ 
        MET_CanOpen_Data_Struct.command_result = COMMAND_COMPLETED;
        MET_Can_Protocol_returnCommandExecuted(0,0);
    }else{ 
        MET_CanOpen_Data_Struct.command_result = COMMAND_ERROR;
        MET_Can_Protocol_returnCommandError(code);
    }
    
}
                    
uint8_t ciaSwitchedOn(void){
    
    switch(DEVICE_DATA->workflow_step){
        case 0: // Read the analog input
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;

                DEVICE_DATA->analog1 = DEVICE_DATA->getAnalogToPositionConversion(MET_canOpen_getOdVal());
                DEVICE_DATA->workflow_step++;
            }else{              
               
               MET_canOpen_ReadSDO(OD_3220_01, 2);
            }
        break;
        
        case 1: // Read the Encoder position
             if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

               DEVICE_DATA->position = DEVICE_DATA->getEncoderToPositionConversion(MET_canOpen_getOdVal());
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_ReadSDO(OD_6064_00, 2);
           }
        break;

        case 2: // Read the Status word           
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;        

                DEVICE_DATA->workflow = MET_canOpen_GetCiaStatus();   
                
                // If the status is not the SwitchOn status, an incoming command shall be terminated in error
                if(DEVICE_DATA->workflow != WORKFLOW_CIA_SWITCHED_ON){ 
                    if(DEVICE_DATA->execution_command != NO_EXECECUTION_COMMAND){                        
                        commandExecutionTerminated(PROTO_ERR_MOTORS_INVALID_STATUS);
                    }                        
                    DEVICE_DATA->workflow_step = 0;
                    return 0;
                }else{
                    
                    // A command execution is evaluated
                    switch(DEVICE_DATA->execution_command){
                        case EXEC_POSITIONING:
                            DEVICE_DATA->workflow = WORKFLOW_POSITIONING;
                            DEVICE_DATA->workflow_step = 0;
                            return 0;
                        default:
                            commandExecutionTerminated(PROTO_ERR_MOTORS_INVALID_CODE);
                   }
                }
                
                DEVICE_DATA->workflow_step++;
                return 0;

            }else{
                MET_canOpen_ReadSDO(OD_6041_00,2);
            }
            break;
            
        default: 
           DEVICE_DATA->workflow_step = 0;            
           return 0;
    }
   

    return 0;
}


    

uint8_t ciaOperationEnabled(void){
    
  uint16_t ctrw;
    
    switch(DEVICE_DATA->workflow_step){
        
        case 0: // Read/Write the control word
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                
                ctrw = MET_canOpen_getOdVal();         
                ctrw &=~ OD_MASK(OD_6040_00_RESET_OMS);
                ctrw |= OD_VAL(OD_6040_00_RESET_OMS);
                        
                MET_canOpen_WriteSDO(OD_6040_00,ctrw ,2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
        
        case 1: // Read/Write the control word to set the disable
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                
                ctrw = MET_canOpen_getOdVal();        
                ctrw &=~ OD_MASK(OD_6040_00_DISABLEOP);
                ctrw |= OD_VAL(OD_6040_00_DISABLEOP);                        
                MET_canOpen_WriteSDO(OD_6040_00,ctrw ,2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
        default:
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            return 0;
        
    }
    
    return 0;
}

uint8_t ciaFault(void){
   
    switch(DEVICE_DATA->workflow_step){
        
        case 0: // Read the Error Class register
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                DEVICE_DATA->error_class = MET_canOpen_getOdVal();                  
                
                // Moves to the reset fault step if no errors are alive
                if(DEVICE_DATA->error_class == 0){                    
                    DEVICE_DATA->workflow_step = 10;
                    return 0;
                }
                
                DEVICE_DATA->workflow_step++;
                break;
            }else{
                MET_canOpen_ReadSDO(OD_1001_00,2);
            }            
        break;
        
        case 1: // Read the error specific register
            // Be careful, the 1003_01 to 07 are readable ONLY if the 10003_00 
            // should be different than 0
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdVal()) DEVICE_DATA->workflow_step++;
                else DEVICE_DATA->workflow_step =0;                
                break;
            }else{
                MET_canOpen_ReadSDO(OD_1003_00,2);
            }
        break;
        
        case 2: // Read the error specific register
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                DEVICE_DATA->error_code = MET_canOpen_getOdVal();  
                DEVICE_DATA->workflow_step = 0;                
                break;
            }else{
                // If an error occurr it can be due to the communication lost. 
                // When the device should reconnnect it could happen that the 
                // register 1003_01 may no more be available.
                if(MET_CanOpen_Data_Struct.rxErrorTrigger) DEVICE_DATA->workflow_step = 0;
                else MET_canOpen_ReadSDO(OD_1003_01,2);
            }
        break;
        
        case 10:
           if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                
                MET_canOpen_WriteSDO(OD_6040_00,(MET_canOpen_getOdVal() | 0x80),2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
        
        case 11:
           if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                
                MET_canOpen_WriteSDO(OD_6040_00,(MET_canOpen_getOdVal() & (~0x80)),2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
        
        default:
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            return 0;
   
    }
    
    return 0;
}


uint8_t deviceInitialization(void){
   
    switch(DEVICE_DATA->workflow_step){
        case 0:
             // Calc the checksum of the vector to evaluate the reload in memory            
            DEVICE_DATA->chk = 0;
            while(1){
                if(DEVICE_CONFIG[DEVICE_DATA->index++].type == 0) break;
                DEVICE_DATA->chk += (ushort) DEVICE_CONFIG[DEVICE_DATA->index].val;
            }
            DEVICE_DATA->workflow_step++;
            break;
            
        case 1:
             if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                // The User config is equal to the expected checksum. End of procedure
                if(MET_canOpen_getOdVal() == DEVICE_DATA->chk){
                    DEVICE_DATA->workflow_step = 100;
                    return 1;
                }
                
                // The device needs to be uploaded with the configuration parameters
                DEVICE_DATA->index = 0;
                DEVICE_DATA->workflow_step++;
                break;
            }else{
                MET_canOpen_ReadSDO(CONFIG_USER_PARAM,2);
            }
            break;
            
        case 2: // Writes the data
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
               
               DEVICE_DATA->index++;          
               break;
           }else{
               // End of vector
               if(DEVICE_CONFIG[DEVICE_DATA->index].type == 0){
                 DEVICE_DATA->workflow_step++;                 
                 return 0;
               }
               MET_canOpen_WriteSDO(DEVICE_CONFIG[DEVICE_DATA->index].idx, DEVICE_CONFIG[DEVICE_DATA->index].sub,DEVICE_CONFIG[DEVICE_DATA->index].type,DEVICE_CONFIG[DEVICE_DATA->index].val, 2);
           }
        break;

        case 3: // Writes the checksum on the User parameter space
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(CONFIG_USER_PARAM,DEVICE_DATA->chk, 2);
           }
        break;
       
        case 4: // Reset the USER-RESET flag
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(RESET_USER_PARAM,RESET_CODE, 2);
           }
        break;
        
        case 5: // Store the Object Dictionary parameter
            MET_canOpen_WriteSDO(OD_1010_01,OD_SAVE_CODE, 2);
            MET_CanOpen_Data_Struct.isWaiting = false;
            DEVICE_DATA->workflow_step++;
            return 200;               
        break;
        
        case 6: // Read the Store register 
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               if(MET_canOpen_getOdVal() == 1){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
               
               break;
           }else{              
               MET_canOpen_ReadSDO(OD_1010_01, 2);
           }
        break;
        
        case 7: // Store user parameters
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(SAVE_USER_PARAM, 1,2);               
           }
        break;

        case 8: // Read back the storing user param register
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               if(MET_canOpen_getOdVal() == 0){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }               
               break;
           }else{              
               MET_canOpen_ReadSDO(SAVE_USER_PARAM, 2);
           }
        break;
        
        default : // Set the Reset User param to 1
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
                // End procedure
                DEVICE_DATA->wait_zero_setting = true;
                DEVICE_DATA->initialized = true;
                DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
                DEVICE_DATA->workflow_step = 0;
                return 0;
               break;
           }else{              
               MET_canOpen_WriteSDO(RESET_USER_PARAM, 1,2);               
           }
    }
    return 0;
}

uint8_t deviceZeroSetting(void){
 
    switch(DEVICE_DATA->workflow_step){
        case 0: // Read the analog1 sensor            
             if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

               DEVICE_DATA->analog1 = DEVICE_DATA->getAnalogToPositionConversion(MET_canOpen_getOdVal());
               DEVICE_DATA->analog1 = DEVICE_DATA->getPositionToEncoderConversion(DEVICE_DATA->analog1);
               DEVICE_DATA->workflow_step++;
               break;
           }else{        
               VITALITY_LED_Set();
               MET_canOpen_ReadSDO(OD_3220_01, 2);
           }
        break;
        case 1: // Set the Offset register to the actual analog value
             if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(OD_607C_00, DEVICE_DATA->analog1, 2);
           }
        break;
        
        case 2: // Set the Homing method to 35
             if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(OD_6098_00, 35, 2);
           }
        break;
        
        case 3: // Activate the zero setting method
             if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(OD_6060_00, OD_6060_00_PROFILE_HOMING, 2);
           }
        break;
        
        case 4: // Read/Write the control word ctrw |=10
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                               
                MET_canOpen_WriteSDO(OD_6040_00,(MET_canOpen_getOdVal()| (0x10)) ,2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
        
        case 5:// Read/Write the control word ctrw &=~10
             if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }                
              
                MET_canOpen_WriteSDO(OD_6040_00,(MET_canOpen_getOdVal()& (~0x10)) ,2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
               
        
        case 6: // Remove the zero setting method
             if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(OD_6060_00, OD_6060_00_NO_PROFILE, 2);
           }
        break;
        
        case 7: // Read the encoder value
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

                DEVICE_DATA->position = MET_canOpen_getOdVal();

                if(DEVICE_DATA->position > DEVICE_DATA->analog1 + 2)  DEVICE_DATA->workflow_step = 0;
                else if(DEVICE_DATA->position < DEVICE_DATA->analog1 - 2)  DEVICE_DATA->workflow_step = 0;
                else DEVICE_DATA->workflow_step++;

                // Verify if the zero setting has been completed successfully: repeat the zero setting if false
                DEVICE_DATA->position = DEVICE_DATA->getEncoderToPositionConversion(MET_canOpen_getOdVal());       
                DEVICE_DATA->analog1 = DEVICE_DATA->getEncoderToPositionConversion(DEVICE_DATA->analog1);
                return 10;
           }else{              
               MET_canOpen_ReadSDO(OD_6064_00, 2);
           }
        break;
        
        default:
            VITALITY_LED_Clear();
            DEVICE_DATA->wait_zero_setting = false;
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            break;
        
    }
    
    return 0;
}

uint8_t positioningExecution(void){
    uint16_t ctrw;
    
    switch(DEVICE_DATA->workflow_step){
        case 0:
            // The device needs to be uploaded with the configuration parameters
            DEVICE_POSITIONING[0].val = DEVICE_DATA->getPositionToEncoderConversion(DEVICE_DATA->target_position);
            DEVICE_DATA->index = 0;
            DEVICE_DATA->workflow_step++;
            return 1;
            
        case 1: // Upload the position registers: speed, acc, dec, target       
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;               
               DEVICE_DATA->index++;                                                    
               return 1;
           }else{
               // End of vector
               if(DEVICE_POSITIONING[DEVICE_DATA->index].type == 0){ 
                   DEVICE_DATA->workflow_step++;                 
                   return 1;
               }
               
               MET_canOpen_WriteSDO(DEVICE_POSITIONING[DEVICE_DATA->index].idx, DEVICE_POSITIONING[DEVICE_DATA->index].sub,DEVICE_POSITIONING[DEVICE_DATA->index].type,DEVICE_POSITIONING[DEVICE_DATA->index].val, 2);
               return 0;
           }
        break;

        case 2: // Upload the activation profile mode
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;               
               DEVICE_DATA->workflow_step++;                          
               return 0;
           }else{               
               MET_canOpen_WriteSDO(OD_6060_00,OD_6060_00_PROFILE_POSITIONING,2);
               return 0;
           }            
        break;
        
        case 3: // Read/Write the control word and change to Cia Enable Operation Mode
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                
                ctrw = MET_canOpen_getOdVal();                
                ctrw &=~ OD_MASK(POSITION_SETTING_CTRL_INIT);
                ctrw |= OD_VAL(POSITION_SETTING_CTRL_INIT);
                MET_canOpen_WriteSDO(OD_6040_00,ctrw ,2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
            return 0;
        break;
        

        case 4: // Read/Write the control word and change to Cia Enable Operation Mode
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 1;
                }
                
                ctrw = MET_canOpen_getOdVal();                
                ctrw &=~ OD_MASK(OD_6040_00_ENABLEOP);
                ctrw |= OD_VAL(OD_6040_00_ENABLEOP);

                ctrw &=~ OD_MASK(POSITION_SETTING_CTRL_INIT);
                ctrw |= OD_VAL(POSITION_SETTING_CTRL_INIT);
                MET_canOpen_WriteSDO(OD_6040_00,ctrw ,2);
                return 1;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
        
        case 5: // Read the status word and check for the correct status mode
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;        

                // Error in changing the Operation Enabled Status
                if(MET_canOpen_GetCiaStatus() != WORKFLOW_CIA_OPERATION_ENABLED){                    
                    commandExecutionTerminated(PROTO_ERR_MOTORS_INVALID_STATUS);
                    DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
                    DEVICE_DATA->workflow_step = 0;
                    return 0;
                }
                
                DEVICE_DATA->workflow_step++;
                return 1;

            }else{
                MET_canOpen_ReadSDO(OD_6041_00,2); 
            }
        break;
        
        case 6: // Read/Write the control word to activate the motor rotation
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                if(MET_canOpen_getOdType() == WR_ACK_OK){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                
                ctrw = MET_canOpen_getOdVal();                
                ctrw &=~ OD_MASK(POSITION_SETTING_START);
                ctrw |= OD_VAL(POSITION_SETTING_START);
                MET_canOpen_WriteSDO(OD_6040_00,ctrw ,2);
                break;
            }else{
                MET_canOpen_ReadSDO(OD_6040_00,2);
            }
        break;
        
        case 7: // Read the Encoder position
             if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;

               DEVICE_DATA->position = DEVICE_DATA->getEncoderToPositionConversion(MET_canOpen_getOdVal());
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_ReadSDO(OD_6064_00, 2);
           }
        break;
        
        case 8: // Read the status word and check for command completion
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;        

                // If an abort request is detected, the activation shall be aborted
                if(MET_CanOpen_Data_Struct.abort_request){
                    MET_CanOpen_Data_Struct.abort_request = false;
                    commandExecutionTerminated(MET_CAN_COMMAND_ABORT_CODE);
                    DEVICE_DATA->workflow = WORKFLOW_CIA_QUICK_STOP_ACTIVATION;
                    DEVICE_DATA->workflow_step = 0;
                    return 0;
                }
                
                // Error in changing the Operation Enabled Status
                if(MET_canOpen_GetCiaStatus() != WORKFLOW_CIA_OPERATION_ENABLED){                    
                    commandExecutionTerminated(PROTO_ERR_MOTORS_INVALID_STATUS);
                    DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
                    DEVICE_DATA->workflow_step = 0;
                    return 0;
                }
                
                // Command completed
                //if( ((MET_canOpen_getOdVal() & 0x1400) == 0x1400) || ((DEVICE_DATA->position < DEVICE_DATA->target_position+5)&&(DEVICE_DATA->position > DEVICE_DATA->target_position-5) )){
                    if( ((MET_canOpen_getOdVal() & 0x1400) == 0x1400) || ((DEVICE_DATA->position == DEVICE_DATA->target_position) )){
                    commandExecutionTerminated(PROTO_COMMAND_NO_ERR);
                    DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
                    DEVICE_DATA->workflow_step = 0;
                }else DEVICE_DATA->workflow_step--;
                return 0;

            }else{
                MET_canOpen_ReadSDO(OD_6041_00,2); 
            }
        break;
    }
    
    return 0;
}

uint8_t  motorDeviceActivate(uint8_t command, int32_t val){
    if(MET_CanOpen_Data_Struct.current_command != NO_COMMAND) return 1; // Busy condition    

    switch(command){
        case ACTIVATE_ARM:
            if(MET_CanOpen_Data_Struct.workflowData[ARM].workflow != WORKFLOW_CIA_SWITCHED_ON) return 1; // busy
            
            // Init of the command variables
            MET_CanOpen_Data_Struct.current_command = command;
            MET_CanOpen_Data_Struct.command_result = COMMAND_EXECUTING;
            MET_CanOpen_Data_Struct.abort_request = false;
 
            // Device command variables
            MET_CanOpen_Data_Struct.workflowData[ARM].target_position = val;
            MET_CanOpen_Data_Struct.workflowData[ARM].execution_command = EXEC_POSITIONING;
            break;
            
        default: return 2;
    }
    return 0;
}

void motorDeviceAbort(void){
    if(MET_CanOpen_Data_Struct.current_command != NO_EXECECUTION_COMMAND) MET_CanOpen_Data_Struct.abort_request = true;
}
/** @}*/  // metCanLocal
