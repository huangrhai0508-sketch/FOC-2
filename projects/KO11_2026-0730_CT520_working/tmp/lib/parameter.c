/*
 * File: parameter.c
 *
 * Code generated for Simulink model 'pmsmfoc'.
 *
 * Model version                  : 11.92
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  3 16:25:55 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "parameter.h"
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "pmsmfoc_types.h"

/* Exported data definition */
#define SWC_IR_START_SEC_CALIB_UNSPECIFIED
#include "MemMap.h" 

/* ConstVolatile memory section */
/* Definition for custom storage class: ConstVolatile */
const volatile real32_T FFW_enable = 0.7F;
const volatile real32_T IdROL_C = 8.0F;
const volatile boolean_T PWMFrqSwitch_C = true;
const volatile real32_T SC_Ld_P = 0.0013591F;
const volatile real32_T SC_Lq_P = 0.0041944F;
const volatile real32_T SC_Psi_P = 0.036816F;
const volatile real32_T SC_pRsv_P = 1.0F;
const volatile real32_T SC_p_P = 5.0F;
const volatile int16_T agNegTrans_C = 1;
const volatile real32_T f32_P_AngleCompCur = -0.35F;
const volatile real32_T f32_P_AngleCompVol = 1.5F;
const volatile real32_T f32_P_Coef = 0.06F;
const volatile real32_T f32_P_Modulation = 1.065F;
const volatile real32_T f32_SpeedFltCoef = 0.0005F;
const volatile real32_T facAdc2iPh_C = 0.048828F;
const volatile real32_T facAdc2uDclnk_C = 0.31551F;
const volatile real32_T g_msgCore0to2_AcrKi = 2000.0F;
const volatile real32_T g_msgCore0to2_AcrKiStb = 2000.0F;
const volatile real32_T g_msgCore0to2_AcrKp = 4.0F;
const volatile real32_T g_msgCore0to2_AcrKpStb = 4.0F;
const volatile real32_T g_msgCore0to2_AcrSwtHiRpm = 0.8F;
const volatile real32_T g_msgCore0to2_AcrSwtLoRpm = 0.5F;
const volatile real32_T g_msgCore0to2_AfrKp = 0.5F;
const volatile real32_T g_msgCore0to2_AfrTi = 0.03F;
const volatile boolean_T g_msgCore0to2_CalibEn = false;
const volatile real32_T g_msgCore0to2_DecoupleEn = 0.7F;
const volatile boolean_T g_msgCore0to2_linearKpEn = false;
const volatile real32_T g_msgCore0to2_maxCur = 30.0F;
const volatile real32_T g_msgCore0to2_maxFwcCurRatio = 0.8F;
const volatile real32_T g_msgCore0to2_pwmFrqSet = 10000.0F;
const volatile real32_T iPhaMax_C = 900.0F;
const volatile real32_T iPhaMin_C = -900.0F;
const volatile int16_T offsAgRtrElec_C = 0;
const volatile uint16_T rotatedirection_C = 1U;
const volatile real32_T tauUdcPT1_C = 0.01F;
const volatile real32_T u16_P_MotorPair = 5.0F;
const volatile real32_T uDcMax_C = 1000.0F;
const volatile real32_T uDcMin_C = -1.0F;
const volatile int16_T wNegTrans_C = 1;


#define SWC_IR_STOP_SEC_CALIB_UNSPECIFIED
#include "MemMap.h" 
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
