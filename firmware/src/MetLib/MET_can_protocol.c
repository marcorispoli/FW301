#define _MET_CAN_PROTOCOL_C

#include "MET_can_protocol.h"                // SYS function prototypes
#include "MET_Bootloader_table.h"   

/* Set the Can ID into the Bootloader space */
const   uint32_t  _BOOTLOADER_CAN_ID __attribute__((keep, space(prog), address(_MET_BOOTLOADER_CAN_ID_OFFSET))) = APP_CAN_ID;  

CAN_MSG_RX_FRAME_ATTRIBUTE msgFrameAttr0 = CAN_MSG_RX_DATA_FRAME;

void MET_DefaultError_Callback(uint8_t event); //!< Default Error callback in case of not assigned error handler 
void MET_Can_Protocol_Reception_Callback(uintptr_t context); 
static bool rxReceptionTrigger = false;
static bool rxErrorTrigger = false;


static  MET_Can_Protocol_RxTx_t MET_Can_Protocol_RxTx_Struct; //!< This is the structure handling the data transmitted and received
static  MET_Can_Protocol_t MET_Can_Protocol_Struct;


// Harmony 3 library Data structure of the Can Module
uint8_t Can0MessageRAM[CAN0_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned (32)));


void MET_Can_Protocol_Init(MET_CANOPEN_ERROR_CALLBACK appErrHandler){
    
    // Harmony 3 library call: Init memory of the CAN Bus module
    CAN0_MessageRAMConfigSet(Can0MessageRAM);
    
    // Assignes the Error callback or the default if the application pass a null pointer
    if(appErrHandler == 0)  MET_Can_Protocol_Struct.errorHandler = MET_DefaultError_Callback;
    else MET_Can_Protocol_Struct.errorHandler = appErrHandler;
    
    return ;
 }

void MET_Can_Protocol_Start(void){

    // Reception Event callback registered on the FIFO0
    CAN0_RxCallbackRegister( MET_Can_Protocol_Reception_Callback, 0 , CAN_MSG_ATTR_RX_FIFO0 );
    
    // Activate the reception buffer on the FIFO-0
    if (CAN0_MessageReceive(&MET_Can_Protocol_RxTx_Struct.rx_messageID,
            &MET_Can_Protocol_RxTx_Struct.rx_messageLength,
            MET_Can_Protocol_RxTx_Struct.rx_message,
            &MET_Can_Protocol_RxTx_Struct.rx_timestamp,
            CAN_MSG_ATTR_RX_FIFO0, &msgFrameAttr0) == false)  MET_Can_Protocol_Struct.errorHandler(MET_CAN_PROTOCOL_ERROR_RECEPTION_ACTIVATION);
    
    return;
}


void MET_Can_Protocol_TestFrame(void){
    
    
    MET_Can_Protocol_RxTx_Struct.tx_message[0] = 0x1;
    MET_Can_Protocol_RxTx_Struct.tx_message[1] = 0x2;
    MET_Can_Protocol_RxTx_Struct.tx_message[2] = 0x3;
    MET_Can_Protocol_RxTx_Struct.tx_message[3] = 0x4;
    MET_Can_Protocol_RxTx_Struct.tx_message[4] = 0x5;
    MET_Can_Protocol_RxTx_Struct.tx_message[5] = 0x6;
    MET_Can_Protocol_RxTx_Struct.tx_message[6] = 0x7;
    MET_Can_Protocol_RxTx_Struct.tx_message[7] = 0x8;
    
    if(!CAN0_MessageTransmit(0x601, 8, MET_Can_Protocol_RxTx_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME)){
        
    }  
    
}
bool MET_Can_Protocol_SendAnswer(uint8_t code, uint16_t address, uint8_t sub, uint8_t d0,  uint8_t d1, uint8_t d2, uint8_t d3){
    
    MET_Can_Protocol_RxTx_Struct.tx_message[0] = code;
    MET_Can_Protocol_RxTx_Struct.tx_message[1] = address & 0xFF;
    MET_Can_Protocol_RxTx_Struct.tx_message[2] = (address >> 8) & 0xFF;
    MET_Can_Protocol_RxTx_Struct.tx_message[3] = sub;
    MET_Can_Protocol_RxTx_Struct.tx_message[4] = d0;
    MET_Can_Protocol_RxTx_Struct.tx_message[5] = d1;
    MET_Can_Protocol_RxTx_Struct.tx_message[6] = d2;
    MET_Can_Protocol_RxTx_Struct.tx_message[7] = d3;
    
    return CAN0_MessageTransmit(_CAN_ID_BASE_ADDRESS + APP_CAN_ID, 8, MET_Can_Protocol_RxTx_Struct.tx_message, CAN_MODE_NORMAL, CAN_MSG_ATTR_TX_FIFO_DATA_FRAME);  
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
   
    
    }
    MET_Can_Protocol_Start();
    return;
    
    if(rxReceptionTrigger){
        rxReceptionTrigger = false;
        
        // Verify the Lenght: it shall be 8 byte
        if(MET_Can_Protocol_RxTx_Struct.rx_messageLength != 8) {
            MET_Can_Protocol_Struct.errorHandler(MET_CAN_PROTOCOL_ERROR_INVALID_LENGHT);
            MET_Can_Protocol_Start();
            return;
        }
        
        // Verify the CRC code
        for(i=0; i<7; i++) crc +=  MET_Can_Protocol_RxTx_Struct.rx_message[i];
        if(crc){
            MET_Can_Protocol_Struct.errorHandler(MET_CAN_PROTOCOL_ERROR_INVALID_CRC);
            MET_Can_Protocol_Start();
            return;
        }
        
        cmdFrame.seq = MET_Can_Protocol_RxTx_Struct.rx_message[0];
        cmdFrame.command = MET_Can_Protocol_RxTx_Struct.rx_message[1];
        for(i=3;i<7;i++) cmdFrame.d[i-3] = MET_Can_Protocol_RxTx_Struct.rx_message[i];
        
        // Identifies the Protocol command
        switch(cmdFrame.command){
            case MET_CAN_PROTOCOL_READ_STATUS:
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
        
    
    }else if(rxErrorTrigger){
        rxErrorTrigger = false;
    }

    // Rescedule the reception for a next frame
    MET_Can_Protocol_Start();
}   
/*
    if(odTrigger){
        odTrigger = false;
        
        // Discrimina il comando ricevuto
        address = MET_CanOpen_RxTx_OD_Struct.rx_message[1] + 256 * MET_CanOpen_RxTx_OD_Struct.rx_message[2];        
        sub = MET_CanOpen_RxTx_OD_Struct.rx_message[3];
        odIndex = MET_CanOpen_Get_OD(address);
         
        // Controllo su Index 
        if(odIndex == -1){
            if(!MET_CanOpen_SendError(address, sub, MET_CANOPEN_ERROR_OD_INVALID_ADDRESS)) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
            if(!MET_StartOdReception()) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_RECEPTION_ACTIVATION);
            return;
        }
        
        // Verifica se è busy
        if((MET_CanOpen_Protocol_Struct.odItems[odIndex].busy) || (MET_CanOpen_Protocol_Struct.odItems[odIndex].app_busy)){
           if(!MET_CanOpen_SendError(address, sub, MET_CANOPEN_ERROR_OD_BUSY)) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
           if(!MET_StartOdReception()) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_RECEPTION_ACTIVATION);
           return;             
        }        
        
        // Controllo su Sub Index
        if(sub >= APP_OBJECT_DICTIONARY_SUBINDEX_NUMBER_DEF){
            if(!MET_CanOpen_SendError(address, sub, MET_CANOPEN_ERROR_OD_INVALID_SUBINDEX)) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
            if(!MET_StartOdReception()) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_RECEPTION_ACTIVATION);
            return;
        }
        
        // Imposta il flag Busy di gestione
        MET_CanOpen_Protocol_Struct.odItems[odIndex].busy = true;
        
        item = &MET_CanOpen_Protocol_Struct.odItems[odIndex].item[sub];
        framecmd = 0;
        d0 = (uint32_t) MET_CanOpen_RxTx_OD_Struct.rx_message[4];
        d1 = d0 + (((uint32_t) MET_CanOpen_RxTx_OD_Struct.rx_message[5]) >> 8);
        d2 = d1 + (((uint32_t) MET_CanOpen_RxTx_OD_Struct.rx_message[6]) >> 16);
        d3 = d2 + (((uint32_t) MET_CanOpen_RxTx_OD_Struct.rx_message[7]) >> 24);
       
        switch(MET_CanOpen_RxTx_OD_Struct.rx_message[0]){
            case 0x2F: // Write of 8 bit data
                if(item->itemType != MET_CANOPEN_OD_TYPE_8){
                    if(!MET_CanOpen_SendError(address, sub, MET_CANOPEN_ERROR_OD_INVALID_SUBINDEX)) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_INVALID_WRITE_TYPE);
                    break;
                }                
                item->write_val = d0;
                if(MET_CanOpen_Protocol_Struct.odItems[odIndex].enable_interrupt) MET_CanOpen_Protocol_Struct.odItems[odIndex].handler(odIndex, sub);
                if(!MET_CanOpen_SendAnswer(0x60, address, sub, MET_CanOpen_RxTx_OD_Struct.rx_message[4],MET_CanOpen_RxTx_OD_Struct.rx_message[5],MET_CanOpen_RxTx_OD_Struct.rx_message[6],MET_CanOpen_RxTx_OD_Struct.rx_message[7])){
                    MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
                }
                break;
            case 0x2B: // Write of 16 bit data
                if(item->itemType != MET_CANOPEN_OD_TYPE_16){
                    if(!MET_CanOpen_SendError(address, sub, MET_CANOPEN_ERROR_OD_INVALID_SUBINDEX)) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_INVALID_WRITE_TYPE);
                    break;
                }
                item->write_val = d1;
                if(MET_CanOpen_Protocol_Struct.odItems[odIndex].enable_interrupt) MET_CanOpen_Protocol_Struct.odItems[odIndex].handler(odIndex, sub);
                if(!MET_CanOpen_SendAnswer(0x60, address, sub, MET_CanOpen_RxTx_OD_Struct.rx_message[4],MET_CanOpen_RxTx_OD_Struct.rx_message[5],MET_CanOpen_RxTx_OD_Struct.rx_message[6],MET_CanOpen_RxTx_OD_Struct.rx_message[7])){
                    MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
                }
                break;  
            case 0x27: // Write of 24 bit data
                if(item->itemType != MET_CANOPEN_OD_TYPE_24){
                    if(!MET_CanOpen_SendError(address, sub, MET_CANOPEN_ERROR_OD_INVALID_SUBINDEX)) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_INVALID_WRITE_TYPE);
                    break;
                }
                item->write_val = d2;
                if(MET_CanOpen_Protocol_Struct.odItems[odIndex].enable_interrupt) MET_CanOpen_Protocol_Struct.odItems[odIndex].handler(odIndex, sub);
                if(!MET_CanOpen_SendAnswer(0x60, address, sub, MET_CanOpen_RxTx_OD_Struct.rx_message[4],MET_CanOpen_RxTx_OD_Struct.rx_message[5],MET_CanOpen_RxTx_OD_Struct.rx_message[6],MET_CanOpen_RxTx_OD_Struct.rx_message[7])){
                    MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
                }
                break;  
            case 0x23: // Write of 32 bit data
                if(item->itemType != MET_CANOPEN_OD_TYPE_32){
                    if(!MET_CanOpen_SendError(address, sub, MET_CANOPEN_ERROR_OD_INVALID_SUBINDEX)) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_INVALID_WRITE_TYPE);
                    break;
                }
                item->write_val = d3;
                if(MET_CanOpen_Protocol_Struct.odItems[odIndex].enable_interrupt) MET_CanOpen_Protocol_Struct.odItems[odIndex].handler(odIndex, sub);
                if(!MET_CanOpen_SendAnswer(0x60, address, sub, MET_CanOpen_RxTx_OD_Struct.rx_message[4],MET_CanOpen_RxTx_OD_Struct.rx_message[5],MET_CanOpen_RxTx_OD_Struct.rx_message[6],MET_CanOpen_RxTx_OD_Struct.rx_message[7])){
                    MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
                }
               break;  
            case 0x40: // Read OD
                d0 = item->read_val & 0xFF;
                d1 = (item->read_val >> 8) & 0xFF;
                d2 = (item->read_val >> 16) & 0xFF;
                d3 = (item->read_val >> 24) & 0xFF;
                
                if(item->itemType == MET_CANOPEN_OD_TYPE_8) framecmd = 0x4F;
                else if(item->itemType == MET_CANOPEN_OD_TYPE_16) framecmd = 0x4B;
                else if(item->itemType == MET_CANOPEN_OD_TYPE_24) framecmd = 0x47;
                else  framecmd = 0x43;
                  
                if(!MET_CanOpen_SendAnswer(framecmd, address, sub, d0, d1, d2, d3)){
                    MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_TRANSMISSION);
                }
                break;  
        }
        
        MET_CanOpen_Protocol_Struct.odItems[odIndex].busy = false;
        if(!MET_StartOdReception()) MET_CanOpen_Protocol_Struct.errorHandler(MET_CANOPEN_ERROR_OD_RECEPTION_ACTIVATION);
    }
  */

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

