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

/// Can Protocol Address (range 1:32)
#define APP_CAN_ID    0x1 // 1 : 32

/// Can Protocol Error codes
typedef enum
{    
    MET_CAN_PROTOCOL_ERROR_OK=0, //!< No error
    MET_CAN_PROTOCOL_ERROR_RECEPTION_ACTIVATION, //!< Error in activating the reception
    MET_CAN_PROTOCOL_ERROR_TRANSMISSION, //!> Error during data transmission       
    MET_CAN_PROTOCOL_ERROR_INVALID_CRC, //!> Frame with invalid CRC received        
    MET_CAN_PROTOCOL_ERROR_INVALID_LENGHT, //!> Frame with invalid Lenght
            
            
} MET_CAN_PROTOCOL_ERROR_DEFS;

// Callback eventi CanOpen
//typedef void (*MET_CAN_PROTOCOL_OD_WRITE_CALLBACK) (uint8_t index, uint8_t subi);
typedef void (*MET_CANOPEN_ERROR_CALLBACK) (uint8_t event);

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

    // Struttura dati per la ricezione
    uint8_t seq;
    uint8_t command;
    uint8_t d[5];
    
} MET_Can_Protocol_Command_t;

typedef enum{
    MET_CAN_PROTOCOL_READ_STATUS = 1,
    MET_CAN_PROTOCOL_WRITE_PARAM = 2,
    MET_CAN_PROTOCOL_WRITE_DATA = 3,
    MET_CAN_PROTOCOL_STORE_PARAMS = 4,    
    MET_CAN_PROTOCOL_COMMAND_EXEC = 5
} MET_CAN_PROTOCOL_COMMAND_ENUM;
    

/******************************************************************************/
/*                      API DI ISTALLAZIONE PROTOCOLLO                        */
/******************************************************************************/
void MET_Can_Protocol_Init(void);
void MET_Can_Protocol_Loop(void);  // Dichiarare nel loop principale dell'applicazione
void MET_Can_Protocol_Start(void);      // Inizio attività di rxtx con protocollo CanOpen
void MET_Can_Protocol_TestFrame(void);



#endif /* _MET_CAN_PROTOCOL_H */

/* *****************************************************************************
End of File
*/
