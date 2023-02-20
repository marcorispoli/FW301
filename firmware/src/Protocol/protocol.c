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
   
    Protocol_test_100ms_timer = false;
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
 * This function is called every 7.82ms from the main loop
 */
void Protocol_7280_us_callback(void){
    if(Protocol_test_100ms_timer){
        Protocol_test_100ms_timer--;
        if(!Protocol_test_100ms_timer){
            MET_Can_Protocol_returnCommandExecuted(MET_Can_Protocol_getCommandParam0(), MET_Can_Protocol_getCommandParam1());
        }
    }
}

/**
 * This is the Application Command Execution Handler
 *  
 */
void ApplicationProtocolCommandHandler(void){
    
    switch(MET_Can_Protocol_getCommandCode()){
        case MET_COMMAND_ABORT:
            
            MET_Can_Protocol_returnCommandAborted();
            break;
        case TEST_LOOPBACK:
            MET_Can_Protocol_returnCommandExecuted(MET_Can_Protocol_getCommandParam0(), MET_Can_Protocol_getCommandParam1());
            break;
        case TEST_100ms_LOOPBACK:
            MET_Can_Protocol_returnCommandExecuting();
            Protocol_test_100ms_timer = 13;            
            break;
        case TEST_INFINITE_CMD:
            MET_Can_Protocol_returnCommandExecuting();
            Protocol_test_100ms_timer = 0;            
            break;
        default:
            MET_Can_Protocol_returnCommandError(MET_CAN_COMMAND_NOT_AVAILABLE);
    }
    
    return;
}