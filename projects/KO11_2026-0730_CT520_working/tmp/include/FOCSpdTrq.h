/*
 * File: FOCSpdTrq.h
 *
 * Code generated for Simulink model 'FOCSpdTrq'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  3 16:26:26 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FOCSpdTrq_h_
#define RTW_HEADER_FOCSpdTrq_h_
#ifndef FOCSpdTrq_COMMON_INCLUDES_
#define FOCSpdTrq_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOCSpdTrq_COMMON_INCLUDES_ */

#include "FOCSpdTrq_types.h"
#include "ECM.h"

/* Includes for objects with custom storage classes */
#include "parameter0.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define FOCSpdTrq_M                    (GRSM)

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Switch2;                    /* '<S15>/Switch2' */
  real32_T out;                        /* '<S2>/MATLAB Function' */
  real32_T UnitDelay1_DSTATE;          /* '<S14>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S17>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a;         /* '<S16>/Unit Delay' */
  real32_T DelayInput2_DSTATE;         /* '<S10>/Delay Input2' */
  real32_T UnitDelay1_DSTATE_f;        /* '<S12>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_k;         /* '<S9>/Unit Delay' */
  real32_T UnitDelay_DSTATE_am;        /* '<S8>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ao;        /* '<S2>/Unit Delay' */
  boolean_T TorqueControl_MODE;        /* '<S1>/Torque Control' */
  boolean_T SpeedControl_MODE;         /* '<S1>/Speed Control' */
} pmsmfocS_D_Work;

/* External inputs (root inport signals with default storage) */
typedef struct {
  ECM ControlMode;                     /* '<Root>/ControlMode' */
  real32_T TrqMax;                     /* '<Root>/TrqMax' */
  real32_T TrqMin;                     /* '<Root>/TrqMin' */
  boolean_T Drive;                     /* '<Root>/Drive' */
  real32_T SpeedPiMaxRatio;            /* '<Root>/SpeedPiMaxRatio' */
  real32_T SpeedPiMinRatio;            /* '<Root>/SpeedPiMinRatio' */
  real32_T f32_TorqueCmd_Nm;           /* '<Root>/f32_TorqueCmd_Nm' */
  real32_T f32_Speedref_rpm;           /* '<Root>/f32_Speedref_rpm' */
  real32_T f32_SpdLimitPos;            /* '<Root>/f32_SpdLimitPos' */
  real32_T f32_SpdLimitNeg;            /* '<Root>/f32_SpdLimitNeg' */
  real32_T SpdDes;                     /* '<Root>/SpdDes' */
  real32_T f32_SpeedAct_rpm;           /* '<Root>/f32_SpeedAct_rpm' */
  real32_T isdSet_last;                /* '<Root>/isdSet_last' */
  real32_T Ts;                         /* '<Root>/Ts' */
} pmsmfocS_ExternalInputs;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T TrqEmDes;                   /* '<Root>/TrqEmDes' */
} pmsmfocS_ExternalOutputs;

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct pmsmfocS_tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern pmsmfocS_D_Work GRSDWork;

/* External inputs (root inport signals with default storage) */
extern pmsmfocS_ExternalInputs GRSU;

/* External outputs (root outports fed by signals with default storage) */
extern pmsmfocS_ExternalOutputs GRSY;

/* Model entry point functions */
extern void FOCSpdTrq_initialize(void);
extern void FOCSpdTrq_step(void);
extern void FOCSpdTrq_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T FOC_Ki;                /* '<S3>/AsrPI' */

/* speedki */
extern real32_T FOC_Kp;                /* '<S3>/AsrPI' */

/* speedkp */

/* Real-time Model object */

/* Const memory section */
extern pmsmfocS_RT_MODEL *const GRSM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOCSpdTrq'
 * '<S1>'   : 'FOCSpdTrq/Subsystem'
 * '<S2>'   : 'FOCSpdTrq/Subsystem/Speed Control'
 * '<S3>'   : 'FOCSpdTrq/Subsystem/Subsystem1'
 * '<S4>'   : 'FOCSpdTrq/Subsystem/Torque Control'
 * '<S5>'   : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function'
 * '<S6>'   : 'FOCSpdTrq/Subsystem/Speed Control/Ratelimit'
 * '<S7>'   : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem'
 * '<S8>'   : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem1'
 * '<S9>'   : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem4'
 * '<S10>'  : 'FOCSpdTrq/Subsystem/Speed Control/Ratelimit/Rate Limiter Dynamic'
 * '<S11>'  : 'FOCSpdTrq/Subsystem/Speed Control/Ratelimit/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S12>'  : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem/PT1_1'
 * '<S13>'  : 'FOCSpdTrq/Subsystem/Subsystem1/AsrPI'
 * '<S14>'  : 'FOCSpdTrq/Subsystem/Subsystem1/PT1_1'
 * '<S15>'  : 'FOCSpdTrq/Subsystem/Torque Control/Saturation Dynamic'
 * '<S16>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdNegLimit'
 * '<S17>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdPosLimit'
 * '<S18>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdNegLimit/MATLAB Function'
 * '<S19>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdPosLimit/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_FOCSpdTrq_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
