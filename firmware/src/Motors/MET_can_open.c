#define _MET_CAN_OPEN_C

#include "application.h"                // SYS function prototypes
#include "MET_can_open.h" 
#include "OD.h"

extern MET_canOpenWorkflow armWorkflowVector[];
extern  MET_canOpen_Config_t ARM_CONFIG_VECTOR[];

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
    MET_CanOpen_Data_Struct.workflowData[device].cia_status = 0;
    
    MET_CanOpen_Data_Struct.workflowData[device].error_class = 0;
    MET_CanOpen_Data_Struct.workflowData[device].error_code = 0;
    
}

void changeDevice(void){
    MET_CanOpen_Data_Struct.currentDevice++;
    if(MET_CanOpen_Data_Struct.currentDevice == MAX_CANOPEN_DEVICE)
        MET_CanOpen_Data_Struct.currentDevice = 0;
    
    MET_CanOpen_Data_Struct.isWaiting = false;
    switch(MET_CanOpen_Data_Struct.currentDevice){
        default:
            MET_CanOpen_Data_Struct.pWorkflowFunc = armWorkflowVector; 
            MET_CanOpen_Data_Struct.pWorkflowData = &MET_CanOpen_Data_Struct.workflowData[ARM];
            
    }
        
}

void MET_CanOpen_Protocol_Init(void){
        
    
    // Harmony 3 library call: Init memory of the CAN Bus module
    CAN1_MessageRAMConfigSet(Can1MessageRAM);
        
    MET_CanOpen_Data_Struct.currentDevice = 0;
    MET_CanOpen_Data_Struct.pWorkflowData = &MET_CanOpen_Data_Struct.workflowData[MET_CanOpen_Data_Struct.currentDevice];
    MET_CanOpen_Data_Struct.pWorkflowFunc = armWorkflowVector;
    MET_CanOpen_Data_Struct.pDeviceConfig = ARM_CONFIG_VECTOR;
    
    // Reception data initialization
    MET_CanOpen_Data_Struct.rxReceptionTrigger = false;
    MET_CanOpen_Data_Struct.rxErrorTrigger = false;

    // Init of the device workflow
    for(int i=0; i<MAX_CANOPEN_DEVICE;i++) initWorkflow(i);
    
    return ;
    
 }



        
/**
 * 
 * The function checks the flags rxReceptionTrigger or rxErrorTrigger.
 * 
 * 
 */
void MET_CanOpen_Protocol_Loop(void){
    static uint8_t delay = 0;
    
    if(delay){
        delay--;
        return;
    }
    
    // Evaluates the timeout in reception
    if(MET_CanOpen_Data_Struct.isWaiting){
        
        // Test Index and SubIndex and error returned code
        if(MET_CanOpen_Data_Struct.rxReceptionTrigger){
            if((MET_CanOpen_Data_Struct.rx_message[0] == SDO_ACK_ERR) ||
               (MET_CanOpen_Data_Struct.rx_message[1] != MET_CanOpen_Data_Struct.tx_message[1])||
               (MET_CanOpen_Data_Struct.rx_message[2] != MET_CanOpen_Data_Struct.tx_message[2]) ||
               (MET_CanOpen_Data_Struct.rx_message[3] != MET_CanOpen_Data_Struct.tx_message[3])) MET_CanOpen_Data_Struct.rxErrorTrigger = true;            
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
            delay = 0;
            changeDevice();
            return;
        }

    }
    
    // Calls the workflow routine related to the current device
    delay = MET_CanOpen_Data_Struct.pWorkflowFunc[MET_CanOpen_Data_Struct.pWorkflowData->workflow]();
    if((!delay) && (!MET_CanOpen_Data_Struct.isWaiting)) changeDevice();

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



bool MET_canOpen_WriteSDO(uint8_t devId, uint16_t idx, uint8_t sub, uint8_t odt, uint32_t d, uint8_t tmo){
    
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
    CAN1_MessageTransmit((uint32_t) 0x600 + (uint32_t) devId, 8, MET_CanOpen_Data_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);      
    MET_CanOpen_Data_Struct.isWaiting = MET_CanOpen_Protocol_Reception_Trigger(tmo); // Reschedule the new data reception
    return  MET_CanOpen_Data_Struct.isWaiting;
    
}

bool MET_canOpen_ReadSDO(uint8_t devId, uint16_t idx, uint8_t sub, uint8_t odt, uint8_t tmo){
     
   
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
    CAN1_MessageTransmit((uint32_t) 0x600 + (uint32_t) devId, 8, MET_CanOpen_Data_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);      
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
/** @}*/  // metCanLocal
