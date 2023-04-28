#define _MET_ARM_C
#include "application.h"              
#include "MET_can_open.h" 
#include "OD.h" 
#include "ARM.h" 

#define MOTOR_GEAR 80 // Gear * 10
#define ENCODER_ROUNDS 833 // Tourns * 100
#define ZERO_ENCODER 512
#define SPEED_DENOMINATOR       120
    
 const MET_canOpen_Config_t ARM_CONFIG_VECTOR[]={

   // Hardware configuration
    {OD_4013_01,1},    // 1 = EXTERNAL VCC LOGIC ON


    // NMT Behavior in case of fault
    {OD_1029_01,0},
    {OD_1029_02,1},
    {OD_2031_00,5000}, 	// Peak current
    {OD_2032_00,5000}, 	// Maximum Speed
    {OD_2033_00,0 },	// Plunger Block
    {OD_2034_00,51500 },// Upper Voltage Warning Level
    {OD_2035_00,20000 },// ****************************************Lower Voltage Warning Level
    {OD_2036_00,2000}, 	// Open Loop Current Reduction Idle Time
    {OD_2037_00,(uint) (-50) },	// Open Loop Current Reduction Value/factor

    // I2t Parameters
    {OD_203B_01,5000 },	// Nominal Current
    {OD_203B_02,1000 },	// Maximum Duration Of Peak Current
    {OD_203B_03,0 },	// Threshold
    {OD_203B_04,0 },	// CalcValue
    {OD_203B_05,5000}, 	// LimitedCurrent
    {OD_2056_00,500 },	// Limit Switch Tolerance Band

    // user unitS
    {OD_2061_00,1 },	// Velocity Numerator
    {OD_2062_00,SPEED_DENOMINATOR },  // Velocity Denominator        ***********************
    {OD_2063_00,1 },	// Acceleration Numerator
    {OD_2064_00,SPEED_DENOMINATOR}, 	// Acceleration Denominator    ***********************
    {OD_2065_00,1 },	// Jerk Numerator
    {OD_2066_00,60 },	// Jerk Denominator
    {OD_3202_00,9}, 	// Motor Drive Submode Select: 6:BLDC 3:CurRed 2:Brake 1:VoS 0:CLOOP/OLOOP

    // Motor Drive Sensor Display Closed Loop
    {OD_320B_01,0 	},  // Commutation
    {OD_320B_02,0 },	// Torque
    {OD_320B_03,1 },	// Velocity
    {OD_320B_04,1}, 	// Position

    // Motor Drive Parameter Set
    {OD_3210_01,50000 }, // Position Loop, Proportional Gain (closed Loop)
    {OD_3210_02,10 },	 // Position Loop, Integral Gain (closed Loop)

    // Analogue Inputs Control
    {OD_3221_00,0},     // 0 , Voltage, 1, Current


    // Digital Input Capture
    {OD_3241_01,0 },    // Control (0:off, 1:RE, 2:FE, 3:RE+FE)
    // 3241:02,0        // Capture Count
    //3241:03,0         // Encoder user units
    //3241:04,0         // Encoder Raw Value


    // Following Error Option Code
    {OD_3700_00,0xFFFF},
            // 0xFFFF No reaction
            // 0 Immediate stop
            // 1 Braking with "slow down ramp"
            // 2 Braking with "quick stop ramp"

    // Quick Stop Option Code
    {OD_605A_00,0 },
            // 0 Immediate stop
            // 1 Braking with "slow down ramp"
            // 2 Braking with "quick stop ramp"

    // Shutdown Option Code
    {OD_605B_00,0 },
            // 0 Immediate stop
            // 1 Braking with "slow down ramp"

    // Disable Option Code
    {OD_605C_00,0 },
            // 0 Immediate stop
            // 1 Braking with "slow down ramp"

    // Halt Option Code
    {OD_605D_00,0 },
            // 0 Immediate stop
            // 1 Braking with "slow down ramp"
            // 2 Braking with "quick stop ramp"

    // Fault Option Code
    {OD_605E_00,0 },
            // 0 Immediate stop
            // 1 Braking with "slow down ramp"
            // 2 Braking with "quick stop ramp"

    // Following Error Window and time
    {OD_6065_00,256}, 	// Window
    {OD_6066_00,100 },	// Time (ms)


    // Position Window + time
    {OD_6067_00,10 },	// Window
    {OD_6068_00,100 },	// Time


    // Position Range Limit
    {OD_607B_01,0}, 	// Min Position Range Limit
    {OD_607B_02,0 },	// Max Position Range Limit

    // Software Position Limit
    {OD_607D_01,(uint) (cGRAD_TO_ENCODER(-18000)) },	// Min Position Limit
    {OD_607D_02,cGRAD_TO_ENCODER(18000) },	// Max Position Limit

    // Polarity
    {OD_607E_00,0 },	// b7:1-> inverse rotaion


    // Position Encoder Resolution: EncInc/MotRev
    {OD_608F_01,2000 },	// Encoder Increments
    {OD_608F_02,1}, 	// Motor Revolutions

    {OD_60F2_00,0x0002}, // Absolute positionning

    // Gear Ratio
    {OD_6091_01,1}, 	// Motor Revolutions
    {OD_6091_02,1 },	// Shaft Revolutions

    // Max Absolute Acceleration and Deceleration
    {OD_60C5_00,5000 },// Max Acceleration
    {OD_60C6_00,5000 },// Max Deceleration

    // Homing registers
    {OD_6098_00,35},                                            // Homing method 21
    {OD_607C_00,0},                                             // Offset value

    END_ODVECTOR // Last element always present!!


};

MET_canOpen_Config_t ARM_POSITIONING[] = {
    {OD_607A_00,cGRAD_TO_ENCODER(-9000)},                        // Target First element always!!   
    {OD_6083_00,cGRADsec_TO_ROT_min(200)}, // Acceleration ratio
    {OD_6084_00,cGRADsec_TO_ROT_min(200)}, // Deceleration ratio
    {OD_6081_00,cGRADsec_TO_ROT_min(100)}, // Speed
    END_ODVECTOR // Last element always present!!
};
 
int32_t analogToPositionConversion(uint16_t analog){
    return (((int32_t) analog - ZERO_ENCODER) * 35156 / (ENCODER_ROUNDS));       
}

int32_t positionToEncoderConversion(int32_t position){           
    return cGRAD_TO_ENCODER(position);    
}

int32_t encoderToPositionConversion(int32_t encoder){           
    return ENCODER_TO_cGRAD(encoder);    
}

void armInitialization(canOpen_workflowData_t* pData){
    pData->deviceId = 0x3;    
    pData->config = ARM_CONFIG_VECTOR;
    pData->positionRegisters = ARM_POSITIONING;
    
    pData->getAnalogToPositionConversion  = analogToPositionConversion;
    pData->getPositionToEncoderConversion = positionToEncoderConversion;
    pData->getEncoderToPositionConversion = encoderToPositionConversion;
    
}
