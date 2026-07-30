/*
 * File: CDD_ISP_private.h
 *
 * Code generated for Simulink model 'CDD_ISP'.
 *
 * Model version                  : 1.238
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 20 08:50:47 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CDD_ISP_private_h_
#define RTW_HEADER_CDD_ISP_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "ECM.h"
#include "CDD_ISP.h"
#include "CDD_ISP_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsSampleHit
#define rtmIsSampleHit(sti, tid)       (CDD_ISPpmsmfoc_rtTimingBridge->taskCounter[CDD_ISPpmsmfoc_rtGlobalTID[sti]] == 0)
#endif

#ifndef rtmIsSpecialSampleHit
#define rtmIsSpecialSampleHit(sti, prom_sti, tid) ( *((CDD_ISPpmsmfoc_rtTimingBridge->rateTransition)[CDD_ISPpmsmfoc_rtGlobalTID[sti] + CDD_ISPpmsmfoc_rtTimingBridge->nTasks*CDD_ISPpmsmfoc_rtGlobalTID[prom_sti]]) )
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
#define rtmGetClockTick0()             ( *((CDD_ISPpmsmfoc_rtTimingBridge->clockTick[CDD_ISPpmsmfoc_rtGlobalTID[0]])) )
#endif

#ifndef rtmGetClockTick1
#define rtmGetClockTick1()             ( *((CDD_ISPpmsmfoc_rtTimingBridge->clockTick[CDD_ISPpmsmfoc_rtGlobalTID[1]])) )
#endif

#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0()            ( *(CDD_ISPpmsmfoc_rtTimingBridge->clockTickH[CDD_ISPpmsmfoc_rtGlobalTID[0]]) )
#endif

#ifndef rtmGetClockTickH1
#define rtmGetClockTickH1()            ( *(CDD_ISPpmsmfoc_rtTimingBridge->clockTickH[CDD_ISPpmsmfoc_rtGlobalTID[1]]) )
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
#define rtmGetT()                      (*(CDD_ISPpmsmfoc_rtTimingBridge->taskTime[0]))
#endif

extern int_T CDD_ISPpmsmfoc_rtGlobalTID[2];
extern const rtTimingBridge *CDD_ISPpmsmfoc_rtTimingBridge;

#endif                                 /* RTW_HEADER_CDD_ISP_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
