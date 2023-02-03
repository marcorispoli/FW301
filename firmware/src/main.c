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
#include "MetLib/MET_Bootloader_table.h"


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
        VITALITY_LED_Toggle();
    }
}

int main ( void )
{
   
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    if(ramBootloaderTable[0] == 0x1){
        asm("nop");
    }
            
    // Registra la callback richiesta
    RTC_Timer32CallbackRegister(rtcEventHandler, 0);
    
    // Start RTC module
    RTC_Timer32Start ( );
    
    // Initialization of the TC0 Timer for the Vitality LED
    TC0_CompareStart();
    
    MET_Can_Protocol_Init(0);
    MET_Can_Open_Init();
    MET_Can_Protocol_Start(); 
    MET_Can_Open_Start(); 
    //VITALITY_LED_Set();
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );

        if(isToggleTime){ 
            MET_Can_Protocol_TestFrame();
            isToggleTime = false;
        }
        
        // Gestione del protocollo CAN
        //MET_Can_Protocol_Loop();
        MET_Can_Open_Loop();

    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

/*******************************************************************************
 End of File
*/

