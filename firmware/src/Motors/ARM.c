#define _MET_ARM_C
#include "application.h"              
#include "MET_can_open.h" 
#include "OD.h" 
#include "ARM.h" 


#define DEVID   0x3
#define DEVICE_DATA MET_CanOpen_Data_Struct.pWorkflowData

static uint8_t deviceInitialization(void);
static uint8_t ciaGetStatus(void);
static uint8_t ciaNotReadyToSwitchOn(void);
static uint8_t ciaSwitchOnDisabled(void);
static uint8_t ciaReadyToSwitchOn(void);
static uint8_t ciaSwitchedOn(void);
static uint8_t ciaOperationEnabled(void);
static uint8_t ciaQuickStopActive(void);
static uint8_t ciaFaultReactionActive(void);
static uint8_t ciaFault(void);

MET_canOpenWorkflow armWorkflowVector[]={ \
    deviceInitialization,
    ciaGetStatus,
    ciaNotReadyToSwitchOn,
    ciaSwitchOnDisabled,
    ciaReadyToSwitchOn,
    ciaSwitchedOn,
    ciaOperationEnabled,
    ciaQuickStopActive,
    ciaFaultReactionActive,
    ciaFault
};


uint8_t ciaNotReadyToSwitchOn(void){
    DEVICE_DATA->workflow = MET_canOpen_GetCiaStatus();
    DEVICE_DATA->workflow_step = 0;
    return 0;
}

uint8_t ciaQuickStopActive(void){
    return ciaSwitchOnDisabled();
}
uint8_t ciaFaultReactionActive(void){
    DEVICE_DATA->workflow = MET_canOpen_GetCiaStatus();
    DEVICE_DATA->workflow_step = 0;
    return 0;
}


uint8_t ciaGetStatus(void){
    if(MET_CanOpen_Data_Struct.isWaiting){
        MET_CanOpen_Data_Struct.isWaiting = false;
        
        if(MET_CanOpen_Data_Struct.rxErrorTrigger) return 0;
        if(!MET_canOpen_isOdOk()) return 0;        
        if(MET_canOpen_getOdId() != 0x6041) return 0;
        
        
        DEVICE_DATA->workflow = MET_canOpen_GetCiaStatus();
        DEVICE_DATA->workflow_step = 0;
        return 0;
        
    }else{
        if(!MET_canOpen_ReadSDO(DEVID,OD_6041_00,2)) return 0;
        return 0;
    }
}


uint8_t ciaSwitchOnDisabled(void){
    if(MET_CanOpen_Data_Struct.isWaiting){
        MET_CanOpen_Data_Struct.isWaiting = false;
        
        if(MET_CanOpen_Data_Struct.rxErrorTrigger) return 0;
        if(!MET_canOpen_isOdOk()) return 0;        
        if(MET_canOpen_getOdId() != 0x6040) return 0;
        
        if(MET_canOpen_getOdType() == WR_ACK_OK) {
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            return 0;
        }
        
        // Set the Shutdown code  To the Ready to SwitchOn Status
        uint16_t ctrw = MET_canOpen_getOdVal();
        ctrw &=~ 0x0087;
        ctrw |= 0x0006;
        MET_canOpen_WriteSDO(DEVID,OD_6040_00,ctrw,2); // Write the control word        
        return 0;
        
    }else{
        if(!MET_canOpen_ReadSDO(DEVID,OD_6040_00,2)) return 0; // Read the Control Word
        return 0;
    }
    return 0;
}

uint8_t ciaReadyToSwitchOn(void){
    
    if(MET_CanOpen_Data_Struct.isWaiting){
        MET_CanOpen_Data_Struct.isWaiting = false;
        
        if(MET_CanOpen_Data_Struct.rxErrorTrigger) return 0;
        if(!MET_canOpen_isOdOk()) return 0;        
        if(MET_canOpen_getOdId() != 0x6040) return 0;
        
        if(MET_canOpen_getOdType() == WR_ACK_OK) {
            DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
            DEVICE_DATA->workflow_step = 0;
            return 0;
        }
        
        // To Switched On Status
        uint16_t ctrw = MET_canOpen_getOdVal();
        ctrw &=~ 0x008F;
        ctrw |= 0x0007;
        MET_canOpen_WriteSDO(DEVID,OD_6040_00,ctrw,2); // Write the control word        
        return 0;
        
    }else{
        if(!MET_canOpen_ReadSDO(DEVID,OD_6040_00,2)) return 0; // Read the Control Word
        return 0;
    }
    return 0;
}

uint8_t ciaSwitchedOn(void){
    
    return 0;
}




uint8_t ciaOperationEnabled(void){
    
    return 0;
}

uint8_t ciaFault(void){
    
    return 0;
}


uint8_t deviceInitialization(void){
    uint16_t index, chk;
    
    switch(DEVICE_DATA->workflow_step){
        case 0:
             // Calc the checksum of the vector to evaluate the reload in memory
            index = 0;
            chk = 0;
            while(1){
                if(MET_CanOpen_Data_Struct.pDeviceConfig[index++].type == 0) break;
                chk += (ushort) MET_CanOpen_Data_Struct.pDeviceConfig[index].val;
            }
            break;
            
    }
    return 0;
}

