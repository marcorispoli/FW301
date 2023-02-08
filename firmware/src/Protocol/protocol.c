#define _PROTOCOL_C

#include "application.h"
#include "protocol.h"
#include "MET_can_protocol.h"



/**
 * This function initiate the CAN Protocol communication.
 * 
 * - The function assignes the application revision code to REVISION status register;
 * - The function assignes the pointers to theProtocol registers to the 
 * Library protocol initilization procedure.
 * 
 * After this initialization, the reception is Automatically activated.
 * 
 * \param[in] deviceID the device can specific address
 * 
 */
void ApplicationProtocolInit ( uint8_t deviceID )
{
    // Assignes the Application revision code to the REVISION STATUS REGISTER
    PROTOCOL_MAJ_REVISION = APP_MAJ_REV;
    PROTOCOL_MIN_REVISION = APP_MIN_REV;
    PROTOCOL_SUB_REVISION = APP_SUB_REV;
    
    // Initialize the Met Can Library
    MET_Can_Protocol_Init(deviceID, (uint8_t**) statusRegisterArray,PROTOCOL_NUMBER_OF_STATUS_REGISTERS);
             
}

/**
 * This function shall be called by the MAIN loop application 
 * in order to manage the reception/transmission protocol activities.
 * 
 * The function merely call the library function  MET_Can_Protocol_Loop().
 */
void inline ApplicationProtocolLoop(void){
    MET_Can_Protocol_Loop();
}
