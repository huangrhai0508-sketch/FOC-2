/*
 * File: parameter.c
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.218
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue May 12 14:29:38 2026
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
#include "FOC_types.h"

/* Exported data definition */

/* ConstVolatile memory section */
/* Definition for custom storage class: ConstVolatile */
const volatile real32_T FFW_enable = 0.7F;
const volatile boolean_T PWMFrqSwitch_C = true;
const volatile real32_T SC_Ld_P = 0.0013591F;
const volatile real32_T SC_Lq_P = 0.0041944F;
const volatile real32_T SC_Psi_P = 0.034816F;
const volatile real32_T f32_P_AngleCompCur = -0.35F;
const volatile real32_T f32_P_AngleCompVol = 1.5F;
const volatile real32_T f32_P_Coef = 0.06F;
const volatile real32_T f32_P_Modulation = 1.065F;
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
const volatile boolean_T g_msgCore0to2_FFW_Gain = true;
const volatile boolean_T g_msgCore0to2_MTPA_Gain = true;
const volatile real32_T g_msgCore0to2_arc_dd_fi = 1.0F;
const volatile boolean_T g_msgCore0to2_clpwitch = false;
const volatile boolean_T g_msgCore0to2_linearKpEn = false;
const volatile real32_T g_msgCore0to2_maxCur = 30.0F;
const volatile real32_T g_msgCore0to2_maxFwcCurRatio = 0.8F;
const volatile boolean_T g_msgCore0to2_motorseq = true;
const volatile real32_T g_msgCore0to2_pwmFrqSet = 10000.0F;
const volatile real32_T u16_P_MotorPair = 5.0F;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
