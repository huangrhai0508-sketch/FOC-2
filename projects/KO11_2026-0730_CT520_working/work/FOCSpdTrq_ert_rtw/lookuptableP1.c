/*
 * File: lookuptableP1.c
 *
 * Code generated for Simulink model 'FOCSpdTrq'.
 *
 * Model version                  : 1.197
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 28 23:07:39 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "lookuptableP1.h"
#include "rtwtypes.h"
#include "FOCSpdTrq_types.h"

/* Exported data definition */

/* ConstVolatile memory section */
/* Definition for custom storage class: ConstVolatile */
const volatile cphaseST_P1 cphase_T_P1 = {
  { -7000.0F, -6000.0F, -5000.0F, -4500.0F, -4000.0F, -3500.0F, -3000.0F,
    -2500.0F, -2000.0F, -1500.0F, -1000.0F, -750.0F, -500.0F, -490.0F, -200.0F,
    -1.0F, 0.0F, 400.0F, 490.0F, 500.0F, 1000.0F, 1500.0F, 2000.0F, 2500.0F,
    2600.0F, 3000.0F, 3500.0F, 4000.0F, 4500.0F, 5000.0F, 5500.0F, 6000.0F,
    7000.0F },

  { -1.4F, -1.4F, -1.4F, -1.4F, -1.4F, -1.4F, -1.4F, -1.4F, -1.4F, -1.4F, -1.4F,
    -1.4F, -1.4F, -1.4F, -1.4F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
} ;

const volatile crippleST_P1 cripple_T_P1 = {
  { 400.0F, 490.0F, 500.0F, 1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 3500.0F,
    4000.0F, 4500.0F, 5000.0F, 5500.0F, 5700.0F, 6000.0F },

  { 0.0F, 0.001F, 0.1F, 0.2F, 0.2F, 0.4F, 0.6F, 0.8F, 0.9F, 0.9F, 0.9F, 0.9F,
    0.9F, 0.9F, 0.9F }
} ;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
