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
#include "MetLib/MET_can_protocol.h"
#include "MetLib/MET_can_open.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
static bool isToggleTime = false;

static void rtcEventHandler (RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{
    if (intCause & RTC_TIMER32_INT_MASK_PER7)
    {   
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
    
    MET_Can_Protocol_Init();
    MET_Can_Open_Init();
          
    void MET_Can_Protocol_Start();
    void MET_Can_Open_Start();
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
         if(isToggleTime){ 
            MET_Can_Open_TestFrame();
            isToggleTime = false;
        }
        
        // Gestione del protocollo CAN
        //MET_Can_Protocol_Loop();
        MET_Can_Protocol_Loop();
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

