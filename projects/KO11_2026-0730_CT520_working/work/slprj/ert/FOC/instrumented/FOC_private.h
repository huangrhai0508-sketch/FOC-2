/*
 * File: FOC_private.h
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

#ifndef RTW_HEADER_FOC_private_h_
#define RTW_HEADER_FOC_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "ECM.h"
#include "FOC.h"
#include "FOC_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsSampleHit
#define rtmIsSampleHit(sti, tid)       (FOCpmsmfoc_rtTimingBridge->taskCounter[FOCpmsmfoc_rtGlobalTID[sti]] == 0)
#endif

#ifndef rtmIsSpecialSampleHit
#define rtmIsSpecialSampleHit(sti, prom_sti, tid) ( *((FOCpmsmfoc_rtTimingBridge->rateTransition)[FOCpmsmfoc_rtGlobalTID[sti] + FOCpmsmfoc_rtTimingBridge->nTasks*FOCpmsmfoc_rtGlobalTID[prom_sti]]) )
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetClockTick0
#define rtmGetClockTick0()             ( *((FOCpmsmfoc_rtTimingBridge->clockTick[FOCpmsmfoc_rtGlobalTID[0]])) )
#endif

#ifndef rtmGetClockTick1
#define rtmGetClockTick1()             ( *((FOCpmsmfoc_rtTimingBridge->clockTick[FOCpmsmfoc_rtGlobalTID[1]])) )
#endif

#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0()            ( *(FOCpmsmfoc_rtTimingBridge->clockTickH[FOCpmsmfoc_rtGlobalTID[0]]) )
#endif

#ifndef rtmGetClockTickH1
#define rtmGetClockTickH1()            ( *(FOCpmsmfoc_rtTimingBridge->clockTickH[FOCpmsmfoc_rtGlobalTID[1]]) )
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT()                      (*(FOCpmsmfoc_rtTimingBridge->taskTime[0]))
#endif

extern const uint32_T rtCP_pooled_cWV27uSCYrIW[2];
extern const uint32_T rtCP_pooled_5V6edGmokdkO[2];
extern const uint32_T rtCP_pooled_Ie8v1ZM5rKrP[2];

#define rtCP_cLdAdpt_maxIndex          rtCP_pooled_cWV27uSCYrIW  /* Computed Parameter: rtCP_cLdAdpt_maxIndex
                                                                  * Referenced by: '<S39>/cLdAdpt'
                                                                  */
#define rtCP_cLqAdpt_maxIndex          rtCP_pooled_cWV27uSCYrIW  /* Computed Parameter: rtCP_cLqAdpt_maxIndex
                                                                  * Referenced by: '<S39>/cLqAdpt'
                                                                  */
#define rtCP_MTPA_T_maxIndex           rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_MTPA_T_maxIndex
                                                                  * Referenced by: '<S33>/MTPA_T'
                                                                  */
#define rtCP_ExFeedBack_maxIndex       rtCP_pooled_Ie8v1ZM5rKrP  /* Computed Parameter: rtCP_ExFeedBack_maxIndex
                                                                  * Referenced by: '<S33>/ExFeedBack'
                                                                  */

extern int_T FOCpmsmfoc_rtGlobalTID[2];
extern const rtTimingBridge *FOCpmsmfoc_rtTimingBridge;

#endif                                 /* RTW_HEADER_FOC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
