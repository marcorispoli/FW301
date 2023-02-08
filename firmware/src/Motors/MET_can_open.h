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

#ifndef _MET_CAN_OPEN_H    /* Guard against multiple inclusion */
#define _MET_CAN_OPEN_H


#include "definitions.h"                // SYS function prototypes


/// Can Open Error codes
typedef enum
{    
    MET_CAN_OPEN_ERROR_OK=0, //!< No error
            
} MET_CAN_OPEN_ERROR_DEFS;

// Callback eventi CanOpen
typedef void (*MET_CANOPEN_ERROR_CALLBACK) (uint8_t event);

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

} MET_Can_Open_RxTx_t;

/******************************************************************************/
/*                      API DI ISTALLAZIONE PROTOCOLLO                        */
/******************************************************************************/
void MET_Can_Open_Init(void);
void MET_Can_Open_Loop(void);  // Dichiarare nel loop principale dell'applicazione
void MET_Can_Open_Start(void);      // Inizio attività di rxtx con protocollo CanOpen


/////////////////////////////////////////////////////////////////////////
void MET_Can_Open_Send_ReadStatus(uint8_t index);


#endif /* _MET_CAN_OPEN_H */

/* *****************************************************************************
End of File
*/
