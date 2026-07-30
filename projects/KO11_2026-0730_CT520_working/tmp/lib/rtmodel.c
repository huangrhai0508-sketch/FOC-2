/*
 * File: rtmodel.c
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

#include "rtmodel.h"

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void pmsmfoc_step(int_T tid)
{
  switch (tid) {
   case 0 :
    pmsmfoc_step0();
    break;

   case 1 :
    pmsmfoc_step1();
    break;

   case 2 :
    pmsmfoc_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
