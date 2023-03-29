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
    
     // In case of initialization request, proceed with the Initialization procedure
     if(!DEVICE_DATA->initialized){
        DEVICE_DATA->workflow = WORKFLOW_INITIALIZATION;
        DEVICE_DATA->workflow_step = 0;
        return 0;
    }
    
     switch(DEVICE_DATA->workflow_step){
        case 0:
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
         
               // If the code is the RESET code then the device has been reset
               if(MET_canOpen_getOdVal() == RESET_CODE){                   
                   DEVICE_DATA->initialized = false;
                   return 0;
               }
               
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_ReadSDO(DEVID,RESET_USER_PARAM, 2);
           }
        
        break;
        default: // Read and set the Status word
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;        

                DEVICE_DATA->workflow = MET_canOpen_GetCiaStatus();
                DEVICE_DATA->workflow_step = 0;
                return 0;

            }else{
                MET_canOpen_ReadSDO(DEVID,OD_6041_00,2);
            }
     }
  
     return 0;
}


uint8_t ciaSwitchOnDisabled(void){
     if(MET_CanOpen_Data_Struct.isWaiting){
        MET_CanOpen_Data_Struct.isWaiting = false;        
        
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
   
    DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
    DEVICE_DATA->workflow_step = 0;
    return 0;
}


uint8_t ciaOperationEnabled(void){
    DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
    DEVICE_DATA->workflow_step = 0;
    return 0;
}

uint8_t ciaFault(void){
    static uint16_t ctrlw;
    switch(DEVICE_DATA->workflow_step){
        case 0:
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                DEVICE_DATA->error_class = MET_canOpen_getOdVal();                
                DEVICE_DATA->workflow_step++;
                break;
            }else{
                MET_canOpen_ReadSDO(DEVID,OD_1001_00,2);
            }
        break;
        
        case 1:
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                DEVICE_DATA->error_code = MET_canOpen_getOdVal();  
                
                if(DEVICE_DATA->error_class == 0){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
                DEVICE_DATA->workflow_step--;
                break;
            }else{
                MET_canOpen_ReadSDO(DEVID,OD_1003_01,2);
            }
        break;
        
        case 2:
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                ctrlw = MET_canOpen_getOdVal() | 0x80; 
                
                DEVICE_DATA->workflow_step++;
                break;
            }else{
                MET_canOpen_ReadSDO(DEVID,OD_6040_00,2);
            }
        break;
        
        case 3:
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                ctrlw &=~ 0x80;                
                DEVICE_DATA->workflow_step++;
                break;
            }else{
                MET_canOpen_WriteSDO(DEVID,OD_6040_00,ctrlw,2);
            }
        break;
        
        case 4:
            if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
                DEVICE_DATA->workflow_step = 0;
                return 0;
            }else{
                MET_canOpen_WriteSDO(DEVID,OD_6040_00,ctrlw,2);
            }
        break;

        
    }
    
    return 0;
}


uint8_t deviceInitialization(void){
    static uint16_t index = 0; 
    static uint16_t chk;
    
                
    switch(DEVICE_DATA->workflow_step){
        case 0:
             // Calc the checksum of the vector to evaluate the reload in memory            
            chk = 0;
            while(1){
                if(MET_CanOpen_Data_Struct.pDeviceConfig[index++].type == 0) break;
                chk += (ushort) MET_CanOpen_Data_Struct.pDeviceConfig[index].val;
            }
            DEVICE_DATA->workflow_step++;
            break;
            
        case 1:
             if(MET_CanOpen_Data_Struct.isWaiting){
                MET_CanOpen_Data_Struct.isWaiting = false;
                
                // The User config is equal to the expected checksum. End of procedure
                if(MET_canOpen_getOdVal() == chk){
                    DEVICE_DATA->workflow_step = 100;
                    return 1;
                }
                
                // The device needs to be uploaded with the configuration parameters
                index = 0;
                DEVICE_DATA->workflow_step++;
                break;
            }else{
                MET_canOpen_ReadSDO(DEVID,CONFIG_USER_PARAM,2);
            }
            break;
            
        case 2: // Writes the data
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
               
               // Write successfully completed
               index++;          
               
               // Go to read back to be sure the write is ok
               DEVICE_DATA->workflow_step++;
               break;
           }else{
               // End of vector
               if(MET_CanOpen_Data_Struct.pDeviceConfig[index].type == 0){
                 DEVICE_DATA->workflow_step++;                 
                 return 0;
               }
               MET_canOpen_WriteSDO(DEVID,MET_CanOpen_Data_Struct.pDeviceConfig[index].idx, MET_CanOpen_Data_Struct.pDeviceConfig[index].sub,MET_CanOpen_Data_Struct.pDeviceConfig[index].type,MET_CanOpen_Data_Struct.pDeviceConfig[index].val, 2);
           }
        break;

        case 3: // Writes the checksum on the User parameter space
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(DEVID,CONFIG_USER_PARAM,chk, 2);
           }
        break;
       
        case 4: // Reset the USER-RESET flag
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(DEVID,RESET_USER_PARAM,RESET_CODE, 2);
           }
        break;
        
        case 5: // Store the Object Dictionary parameter
            MET_canOpen_WriteSDO(DEVID,OD_1010_01,OD_SAVE_CODE, 2);
            MET_CanOpen_Data_Struct.isWaiting = false;
            DEVICE_DATA->workflow_step++;
            return 200;               
        break;
        
        case 6: // Read the Store register 
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               if(MET_canOpen_getOdVal() == 1){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }
               
               break;
           }else{              
               MET_canOpen_ReadSDO(DEVID,OD_1010_01, 2);
           }
        break;
        
        case 7: // Store user parameters
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               DEVICE_DATA->workflow_step++;
               break;
           }else{              
               MET_canOpen_WriteSDO(DEVID,SAVE_USER_PARAM, 1,2);               
           }
        break;

        case 8: // Read back the storing user param register
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
               if(MET_canOpen_getOdVal() == 0){
                    DEVICE_DATA->workflow_step++;
                    return 0;
                }               
               break;
           }else{              
               MET_canOpen_ReadSDO(DEVID,SAVE_USER_PARAM, 2);
           }
        break;
        
        default : // Set the Reset User param to 1
            if(MET_CanOpen_Data_Struct.isWaiting){
               MET_CanOpen_Data_Struct.isWaiting = false;
                              
                // End procedure
                DEVICE_DATA->wait_zero_setting = true;
                DEVICE_DATA->initialized = true;
                DEVICE_DATA->workflow = WORKFLOW_GET_CIA_STATUS;
                DEVICE_DATA->workflow_step = 0;
                return 0;
               break;
           }else{              
               MET_canOpen_WriteSDO(DEVID,RESET_USER_PARAM, 1,2);               
           }
    }
    return 0;
}

