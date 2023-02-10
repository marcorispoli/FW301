/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "application.h"
#include "Protocol/protocol.h"
#include "Motors/MET_can_open.h"
#include "BusHardware/bushw.h"


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static bool isToggleTime = false;

static void rtcEventHandler (RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{
    // Periodic Interval Handler: Freq = 1024 / 2 ^ (n+3)
    if (intCause & RTC_TIMER32_INT_MASK_PER0){
        // 7.82ms Interrupt
        
        BusHwRtcInterrupt(); // Handles the Signals filtering
        return;
    }
    
    if (intCause & RTC_TIMER32_INT_MASK_PER7)
    {   
        // 1.024s
        isToggleTime    = true;
        
    }
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

     // Registra la callback richiesta
    RTC_Timer32CallbackRegister(rtcEventHandler, 0);
    RTC_Timer32Start();
            
    // Start the TCo to start the Vitality LED
    TC0_CompareStart();
    
    MET_Can_Open_Init();
    MET_Can_Open_Start();
    
    // Application Protocol initialization
    ApplicationProtocolInit(APP_DEVICE_ID);
    
    // This call shall follows the ApplicationProtocolInit() function
    BusHwInit();
    
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        // Protocol management
        ApplicationProtocolLoop();
        
        // Bus Hardware Management
        BusHwLoop();
        
        
        if(isToggleTime){            
            isToggleTime = false;
            
            MET_Can_Open_Send_ReadStatus(1);
        }
        
        if(PROTOCOL_SYSTEM_SLIDE_UP) VITALITY_LED_Set();
        else VITALITY_LED_Clear();
    }

    
    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

