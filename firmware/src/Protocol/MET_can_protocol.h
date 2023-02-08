/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _MET_CAN_PROTOCOL_H    /* Guard against multiple inclusion */
#define _MET_CAN_PROTOCOL_H


#include "definitions.h"                // SYS function prototypes


/// Can Protocol Error codes
typedef enum
{    
    MET_CAN_PROTOCOL_ERROR_OK=0, //!< No error
    MET_CAN_PROTOCOL_ERROR_RECEPTION_ACTIVATION, //!< Error in activating the reception
    MET_CAN_PROTOCOL_ERROR_TRANSMISSION, //!> Error during data transmission       
    MET_CAN_PROTOCOL_ERROR_INVALID_CRC, //!> Frame with invalid CRC received        
    MET_CAN_PROTOCOL_ERROR_INVALID_LENGHT, //!> Frame with invalid Lenght
            
            
} MET_CAN_PROTOCOL_ERROR_DEFS;



#define _CAN_ID_BASE_ADDRESS 0x200
#define _CAN_ID_BROADCAST_ADDRESS 0x100

typedef struct {

    // Struttura dati per la ricezione
    uint32_t rx_messageID;
    uint8_t rx_message[8];
    uint8_t rx_messageLength;
    uint16_t rx_timestamp;

    // Struttura dati per la trasmissione
    uint32_t tx_messageID;
    uint8_t tx_message[8];
    uint8_t tx_messageLength;
    uint16_t tx_timestamp;

} MET_Can_Protocol_RxTx_t;

typedef struct {

    
    uint8_t seq;
    uint8_t command;
    uint8_t d[5];
    
} MET_Can_Protocol_Command_t;

typedef struct {
    
    uint8_t seq;
    uint8_t command;
    uint8_t index;
    uint8_t s[4];
    
} MET_Read_Status_Command_t;


typedef enum{
    MET_CAN_PROTOCOL_READ_STATUS = 1,
    MET_CAN_PROTOCOL_WRITE_PARAM = 2,
    MET_CAN_PROTOCOL_WRITE_DATA = 3,
    MET_CAN_PROTOCOL_STORE_PARAMS = 4,    
    MET_CAN_PROTOCOL_COMMAND_EXEC = 5
} MET_CAN_PROTOCOL_COMMAND_ENUM;

typedef void (*MET_CAN_PROTOCOL_READ_STATUS_CALLBACK) (MET_Read_Status_Command_t* status);


typedef struct {
    uint8_t deviceID;
    
    uint8_t** pStatusArray;
    uint8_t   statusArrayLen;
    
} MET_Protocol_Data_t;





/******************************************************************************/
/*                      API DI ISTALLAZIONE PROTOCOLLO                        */
/******************************************************************************/
void MET_Can_Protocol_Init(uint8_t deviceID, uint8_t** pStatArray, uint8_t statusLen);
void MET_Can_Protocol_Loop(void);  // Dichiarare nel loop principale dell'applicazione
void MET_Can_Protocol_Reception_Trigger(void);     


#endif /* _MET_CAN_PROTOCOL_H */

/* *****************************************************************************
End of File
*/
