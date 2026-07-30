/*
 * File: FOC_types.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.230
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun May 17 16:05:39 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FOC_types_h_
#define RTW_HEADER_FOC_types_h_
#include "ECM.h"
#include "rtwtypes.h"
#include "lookuptabletype.h"
#ifndef DEFINED_TYPEDEF_FOR_Duty_
#define DEFINED_TYPEDEF_FOR_Duty_

typedef struct {
  real32_T f32_DutyUon;
  real32_T f32_DutyVon;
  real32_T f32_DutyWon;
} Duty;

#endif

/* Forward declaration for rtModel */
typedef struct FOCpmsmfoc_tag_RTM FOCpmsmfoc_RT_MODEL;

#endif                                 /* RTW_HEADER_FOC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
