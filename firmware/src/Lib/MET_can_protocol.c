#define _MET_CAN_PROTOCOL_C

#include "MET_can_protocol.h"                // SYS function prototypes
#include "application.h"

// Harmony 3 library Data structure of the Can Module
uint8_t Can0MessageRAM[CAN0_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));
CAN_MSG_RX_FRAME_ATTRIBUTE msgFrameAttr0 = CAN_MSG_RX_DATA_FRAME;

void MET_DefaultError_Callback(uint8_t event); //!< Default Error callback in case of not assigned error handler 
void MET_Can_Protocol_Reception_Callback(uintptr_t context); 
void MET_ReadStatusRegister(MET_Read_Status_Command_t* cmdFrame);


static bool rxReceptionTrigger = false;
static bool rxErrorTrigger = false;
static MET_Can_Protocol_RxTx_t MET_Can_Protocol_RxTx_Struct; //!< This is the structure handling the data transmitted and received
static MET_Protocol_Data_t MET_Protocol_Data_Struct;


void MET_Can_Protocol_Reception_Trigger(void){

    // Reception Event callback registered on the FIFO0
    CAN0_RxCallbackRegister( MET_Can_Protocol_Reception_Callback, 0 , CAN_MSG_ATTR_RX_FIFO0 );
    
    // Activate the reception buffer on the FIFO-0
    if (CAN0_MessageReceive(&MET_Can_Protocol_RxTx_Struct.rx_messageID,
            &MET_Can_Protocol_RxTx_Struct.rx_messageLength,
            MET_Can_Protocol_RxTx_Struct.rx_message,
            &MET_Can_Protocol_RxTx_Struct.rx_timestamp,
            CAN_MSG_ATTR_RX_FIFO0, &msgFrameAttr0) == false)  MET_DefaultError_Callback(MET_CAN_PROTOCOL_ERROR_RECEPTION_ACTIVATION);
    
    return;
}

void MET_Can_Protocol_Init(MET_CAN_PROTOCOL_READ_STATUS_CALLBACK readStatusHandler){
    
    // Harmony 3 library call: Init memory of the CAN Bus module
    CAN0_MessageRAMConfigSet(Can0MessageRAM);
    
    // Revision Initialization        
    MET_Protocol_Data_Struct.revisionStatus[0] = (uint8_t) APP_MAJ_REV;
    MET_Protocol_Data_Struct.revisionStatus[1] = (uint8_t) APP_MIN_REV;
    MET_Protocol_Data_Struct.revisionStatus[2] = (uint8_t) APP_SUB_REV;
    MET_Protocol_Data_Struct.revisionStatus[3] = (uint8_t) 0;
    
    // Clear the defaul protocol registers
    memset(&MET_Protocol_Data_Struct.systemStatus[0],0,4);
    memset(&MET_Protocol_Data_Struct.errorsStatus[0],0,4);
    memset(&MET_Protocol_Data_Struct.commandStatus[0],0,4);
    
    // Add the external ReadStatus Handler routine
    MET_Protocol_Data_Struct.readStatusHandler = readStatusHandler;
    
    // Schedules the next reception interrupt
    MET_Can_Protocol_Reception_Trigger();      
    return ;
 }


/*
    Funzione da far girare nel main loop dell'applicazione
 */
void MET_Can_Protocol_Loop(void){
    MET_Can_Protocol_Command_t cmdFrame;

    uint8_t crc = 0;
    uint8_t i;
    
    if(rxReceptionTrigger){
        rxReceptionTrigger = false;                          
        
        // Verify the Lenght: it shall be 8 byte
        if(MET_Can_Protocol_RxTx_Struct.rx_messageLength != 8) {
            MET_DefaultError_Callback(MET_CAN_PROTOCOL_ERROR_INVALID_LENGHT);
            MET_Can_Protocol_Reception_Trigger(); // Reschedule the new data reception
            return;
        }
        
        // Verify the CRC code
        for(i=0; i<7; i++) crc ^=  MET_Can_Protocol_RxTx_Struct.rx_message[i];
        if(crc){
            MET_DefaultError_Callback(MET_CAN_PROTOCOL_ERROR_INVALID_CRC);
            MET_Can_Protocol_Reception_Trigger(); // Reschedule the new data reception
            return;
        }
        
        cmdFrame.seq = MET_Can_Protocol_RxTx_Struct.rx_message[0];
        cmdFrame.command = MET_Can_Protocol_RxTx_Struct.rx_message[1];
        for(i=3;i<7;i++) cmdFrame.d[i-3] = MET_Can_Protocol_RxTx_Struct.rx_message[i];
        
        VITALITY_LED_Toggle();
        
        // Identifies the Protocol command
        switch(cmdFrame.command){
            case MET_CAN_PROTOCOL_READ_STATUS:
                MET_ReadStatusRegister((MET_Read_Status_Command_t*) &cmdFrame);
                break;
            case MET_CAN_PROTOCOL_WRITE_PARAM:
                break;
            case MET_CAN_PROTOCOL_WRITE_DATA:
                break;
            case MET_CAN_PROTOCOL_STORE_PARAMS:
                break;
            case MET_CAN_PROTOCOL_COMMAND_EXEC:
                break;
            
        }
        
        // The cmdFrame shall be properly modified by the Protocl command callbacks
        MET_Can_Protocol_RxTx_Struct.tx_message[0] = cmdFrame.seq;
        MET_Can_Protocol_RxTx_Struct.tx_message[1] = cmdFrame.command;
        MET_Can_Protocol_RxTx_Struct.tx_message[2] = cmdFrame.d[0];
        MET_Can_Protocol_RxTx_Struct.tx_message[3] = cmdFrame.d[1];
        MET_Can_Protocol_RxTx_Struct.tx_message[4] = cmdFrame.d[2];
        MET_Can_Protocol_RxTx_Struct.tx_message[5] = cmdFrame.d[3];
        MET_Can_Protocol_RxTx_Struct.tx_message[6] = cmdFrame.d[4];
        
        // Calcs the CRC of the buffer to be sent 
        crc = 0;
        for(i=0; i<7; i++) crc ^=  MET_Can_Protocol_RxTx_Struct.tx_message[i];
        MET_Can_Protocol_RxTx_Struct.tx_message[7] = crc;

        // Sends the buffer to the caller
        CAN0_MessageTransmit(_CAN_ID_BASE_ADDRESS + APP_CAN_ID, 8, MET_Can_Protocol_RxTx_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);  
        MET_Can_Protocol_Reception_Trigger(); // Reschedule the new data reception
        
    }else if(rxErrorTrigger){
        rxErrorTrigger = false;
        MET_Can_Protocol_Reception_Trigger();
    }

    // Rescedule the reception for a next frame
    
}   

void MET_ReadStatusRegister(MET_Read_Status_Command_t* statusFrame){
    
    switch(statusFrame->index){
        case _STAT_REVISION_IDX:
            memcpy(&statusFrame->s[0], &MET_Protocol_Data_Struct.revisionStatus[0], 4);
        break;
        case _STAT_SYSTEM_IDX:
            memcpy(&statusFrame->s[0], &MET_Protocol_Data_Struct.systemStatus[0], 4);
        break;
        case _STAT_ERRORS_IDX:
            memcpy(&statusFrame->s[0], &MET_Protocol_Data_Struct.errorsStatus[0], 4);
        break;
        case _STAT_COMMAND_IDX:
            memcpy(&statusFrame->s[0], &MET_Protocol_Data_Struct.commandStatus[0], 4);
        break;
        default:
            MET_Protocol_Data_Struct.readStatusHandler(statusFrame);
    }
    
    return;
}


/*
 ****************************************************************************
 *                      CALLBACKS MODULO CAN
 ****************************************************************************

 */

void MET_Can_Protocol_Reception_Callback(uintptr_t context)
{
 
    uint32_t  status = CAN0_ErrorGet();

    if (((status & CAN_PSR_LEC_Msk) == CAN_ERROR_NONE) || 
	((status & CAN_PSR_LEC_Msk) == CAN_ERROR_LEC_NC))
    {
       // SUCCESSO
        rxReceptionTrigger = true;
        
    }    else
    {
        // ERROR
        rxErrorTrigger = true;
    }
}

void MET_DefaultError_Callback(uint8_t errEvent)
{
    switch(errEvent){
        case 0:
            break;
        default:
            break;
    }
    
    return;
}

