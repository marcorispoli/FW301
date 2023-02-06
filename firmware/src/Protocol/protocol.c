#include "application.h"
#include "Lib/MET_can_protocol.h"

void protocolReadStatusHandler(MET_Read_Status_Command_t* status);

void ApplicationProtocolInit ( void )
{
    // Initialize the Met Can Library
    MET_Can_Protocol_Init(&protocolReadStatusHandler);
  
    
}

void protocolReadStatusHandler(MET_Read_Status_Command_t* status){
    
}
