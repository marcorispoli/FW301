#define _MET_CAN_OPEN_C

#include "MET_can_open.h"     // SYS function prototypes
#include "Protocol/MET_can_protocol.h"

CAN_MSG_RX_FRAME_ATTRIBUTE msgFrameAttr = CAN_MSG_RX_DATA_FRAME;

void MET_CanOpen_Error_Callback(uint8_t event); //!< Default Error callback in case of not assigned error handler 
void MET_Can_Open_Reception_Callback(uintptr_t context); 

static bool rxReceptionTrigger = false;
static bool rxErrorTrigger = false;


static  MET_Can_Open_RxTx_t MET_Can_Open_RxTx_Struct; //!< This is the structure handling the data transmitted and received

// Harmony 3 library Data structure of the Can Module
uint8_t Can1MessageRAM[CAN1_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));


void MET_Can_Open_Init(void){
    
    // Harmony 3 library call: Init memory of the CAN Bus module
    CAN1_MessageRAMConfigSet(Can1MessageRAM);
    
    return ;
 }

void MET_Can_Open_Start(void){

    // Reception Event callback registered on the FIFO0
    CAN1_RxCallbackRegister( MET_Can_Open_Reception_Callback, 0 , CAN_MSG_ATTR_RX_FIFO0 );
    
    // Activate the reception buffer on the FIFO-0
    if (CAN1_MessageReceive(&MET_Can_Open_RxTx_Struct.rx_messageID,
            &MET_Can_Open_RxTx_Struct.rx_messageLength,
            MET_Can_Open_RxTx_Struct.rx_message,
            &MET_Can_Open_RxTx_Struct.rx_timestamp,
            CAN_MSG_ATTR_RX_FIFO0, &msgFrameAttr) == false)  MET_CanOpen_Error_Callback(0);
    
    return;
}


/*
    Funzione da far girare nel main loop dell'applicazione
 */
void MET_Can_Open_Loop(void){
    
    if(rxReceptionTrigger){
        rxReceptionTrigger = false;
        MET_Can_Open_Start();
        
        
    }else if(rxErrorTrigger){
        rxErrorTrigger = false;
        MET_Can_Open_Start();
        
    }
    
    return;
    
    if(rxReceptionTrigger){
        rxReceptionTrigger = false;
            
    
    }else if(rxErrorTrigger){
        rxErrorTrigger = false;
    }

    // Rescedule the reception for a next frame
    //MET_Can_Open_Start();
}   
/*
 ****************************************************************************
 *                      CALLBACKS MODULO CAN
 ****************************************************************************

 */

void MET_Can_Open_Reception_Callback(uintptr_t context)
{
 
    uint32_t  status = CAN1_ErrorGet();

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

void MET_CanOpen_Error_Callback(uint8_t errEvent)
{
    switch(errEvent){
        case 0:
            break;
        default:
            break;
    }
    
    return;
}

void MET_Can_Open_Send_ReadStatus(uint8_t index){
    
    
    MET_Can_Open_RxTx_Struct.tx_message[0] = 0x1; // Sequence
    MET_Can_Open_RxTx_Struct.tx_message[1] = 1;
    MET_Can_Open_RxTx_Struct.tx_message[2] = index;
    MET_Can_Open_RxTx_Struct.tx_message[3] = 0;
    MET_Can_Open_RxTx_Struct.tx_message[4] = 0;
    MET_Can_Open_RxTx_Struct.tx_message[5] = 0;
    MET_Can_Open_RxTx_Struct.tx_message[6] = 0;
    
    uint8_t i;
    uint8_t crc = 0;
    for(i=0; i<7; i++) crc ^=  MET_Can_Open_RxTx_Struct.tx_message[i];
    MET_Can_Open_RxTx_Struct.tx_message[7] = crc;
    
    CAN1_MessageTransmit(0x211, 8, MET_Can_Open_RxTx_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);  
    
}

void MET_Can_Open_Send_WriteData(uint8_t index, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3 ){
    MET_Can_Open_RxTx_Struct.tx_message[0] = 0x1; // Sequence
    MET_Can_Open_RxTx_Struct.tx_message[1] = 3;
    MET_Can_Open_RxTx_Struct.tx_message[2] = index;
    MET_Can_Open_RxTx_Struct.tx_message[3] = d0;
    MET_Can_Open_RxTx_Struct.tx_message[4] = d1;
    MET_Can_Open_RxTx_Struct.tx_message[5] = d2;
    MET_Can_Open_RxTx_Struct.tx_message[6] = d3;
    
    uint8_t i;
    uint8_t crc = 0;
    for(i=0; i<7; i++) crc ^=  MET_Can_Open_RxTx_Struct.tx_message[i];
    MET_Can_Open_RxTx_Struct.tx_message[7] = crc;
    
    CAN1_MessageTransmit(0x211, 8, MET_Can_Open_RxTx_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);  
    
}
