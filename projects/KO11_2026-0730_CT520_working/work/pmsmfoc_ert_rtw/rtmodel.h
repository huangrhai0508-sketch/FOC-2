/*
 * File: rtmodel.h
 *
 * Code generated for Simulink model 'pmsmfoc'.
 *
 * Model version                  : 11.145
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 28 23:06:30 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rtmodel_h_
#define RTW_HEADER_rtmodel_h_
#include "pmsmfoc.h"

/* Macros generated for backwards compatibility  */
#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((void*) 0)
#endif

/* Model wrapper function */
/* Use this function only if you need to maintain compatibility with an existing static main program. */
extern void pmsmfoc_step(int_T tid);

#endif                                 /* RTW_HEADER_rtmodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
