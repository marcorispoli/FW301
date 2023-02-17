#define _PROTOCOL_C

#include "application.h"
#include "protocol.h"


static void ApplicationProtocolCommandHandler(void);

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
void ApplicationProtocolInit ( void )
{

    // Initialize the Met Can Library
    MET_Can_Protocol_Init(ApplicationProtocolCommandHandler);
             
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

/**
 * This is the Application Command Execution Handler
 *  
 */
void ApplicationProtocolCommandHandler(void){
    
    switch(MET_Can_Protocol_getCommandCode()){
        default:
            MET_Can_Protocol_setReturnCommand(MET_CAN_COMMAND_ERROR,0,0,MET_CAN_COMMAND_NOT_AVAILABLE);
    }
    
    return;
}