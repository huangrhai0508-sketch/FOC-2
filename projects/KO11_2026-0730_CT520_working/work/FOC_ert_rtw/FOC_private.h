/*
 * File: FOC_private.h
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

#ifndef RTW_HEADER_FOC_private_h_
#define RTW_HEADER_FOC_private_h_
#include "rtwtypes.h"
#include "FOC_types.h"
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

extern const uint32_T rtCP_pooled_cWV27uSCYrIW[2];
extern const uint32_T rtCP_pooled_5V6edGmokdkO[2];
extern const uint32_T rtCP_pooled_Ie8v1ZM5rKrP[2];

#define rtCP_cLdAdpt_maxIndex          rtCP_pooled_cWV27uSCYrIW  /* Computed Parameter: rtCP_cLdAdpt_maxIndex
                                                                  * Referenced by: '<S35>/cLdAdpt'
                                                                  */
#define rtCP_cLqAdpt_maxIndex          rtCP_pooled_cWV27uSCYrIW  /* Computed Parameter: rtCP_cLqAdpt_maxIndex
                                                                  * Referenced by: '<S35>/cLqAdpt'
                                                                  */
#define rtCP_MTPA_T_maxIndex           rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_MTPA_T_maxIndex
                                                                  * Referenced by: '<S29>/MTPA_T'
                                                                  */
#define rtCP_ExFeedBack_maxIndex       rtCP_pooled_Ie8v1ZM5rKrP  /* Computed Parameter: rtCP_ExFeedBack_maxIndex
                                                                  * Referenced by: '<S29>/ExFeedBack'
                                                                  */
#endif                                 /* RTW_HEADER_FOC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
