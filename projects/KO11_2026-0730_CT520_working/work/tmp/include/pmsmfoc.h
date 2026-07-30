/*
 * File: pmsmfoc.h
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

#ifndef RTW_HEADER_pmsmfoc_h_
#define RTW_HEADER_pmsmfoc_h_
#ifndef pmsmfoc_COMMON_INCLUDES_
#define pmsmfoc_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pmsmfoc_COMMON_INCLUDES_ */

#include "pmsmfoc_types.h"
#include "EGM.h"
#include "ECM.h"
#include "lookuptabletype.h"
#include "model_reference_types.h"
#include <stddef.h>

/* Includes for objects with custom storage classes */
#include "lookuptable.h"
#include "parameter.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define pmsmfoc_M                      (GRM)

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  Core2_ISP_Out ISP_Out;               /* '<Root>/CDD&ISP' */
  volatile Core2_ISP_Out RateTransition1_Buffer0;/* '<S1>/Rate Transition1' */
  volatile Sig10ms02ST RateTransition_Buffer[2];/* '<Root>/Rate Transition' */
  Sig10ms02ST RateTransition;          /* '<Root>/Rate Transition' */
  Sig10ms02ST UD1_DSTATE;              /* '<Root>/UD1' */
  Core2_PMC_Out BusCreator1;           /* '<S4>/Bus Creator1' */
  Sig1ms02ST UD2;                      /* '<Root>/UD2' */
  volatile Core2_PMC_Out RateTransition3_Buffer0;/* '<S1>/Rate Transition3' */
  Sig1ms02ST UD2_DSTATE;               /* '<Root>/UD2' */
  volatile real32_T RateTransition2_Buffer[2];/* '<S2>/Rate Transition2' */
  volatile real32_T RateTransition3_Buffer[2];/* '<S2>/Rate Transition3' */
  real32_T CDDISP_o2;                  /* '<Root>/CDD&ISP' */
  real32_T CDDISP_o3;                  /* '<Root>/CDD&ISP' */
  real32_T DCCurrent;                  /* '<S2>/Model' */
  real32_T UnitDelay_DSTATE;           /* '<S2>/Unit Delay' */
  volatile real32_T RateTransition4_Buffer0;/* '<S1>/Rate Transition4' */
  volatile real32_T RateTransition6_Buffer0;/* '<S1>/Rate Transition6' */
  volatile ECM RateTransition4_Buffer[2];/* '<S2>/Rate Transition4' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<S2>/Rate Transition2' */
  volatile int8_T RateTransition_ActiveBufIdx;/* '<Root>/Rate Transition' */
  volatile int8_T RateTransition3_ActiveBufIdx;/* '<S2>/Rate Transition3' */
  volatile int8_T RateTransition4_ActiveBufIdx;/* '<S2>/Rate Transition4' */
  volatile int8_T RateTransition1_semaphoreTaken;/* '<S1>/Rate Transition1' */
  volatile int8_T RateTransition3_semaphoreTaken;/* '<S1>/Rate Transition3' */
  volatile int8_T RateTransition4_semaphoreTaken;/* '<S1>/Rate Transition4' */
  volatile int8_T RateTransition6_semaphoreTaken;/* '<S1>/Rate Transition6' */
  volatile boolean_T RateTransition5_Buffer0;/* '<S4>/Rate Transition5' */
} pmsmfoc_D_Work;

/* External inputs (root inport signals with default storage) */
typedef struct {
  Sig10ms02ST msgCore0to2_10ms_In;     /* '<Root>/msgCore0to2_10ms' */
  Sig1ms02ST msgCore0to2_1ms_In;       /* '<Root>/msgCore0to2_1ms' */
  Core2_CDDIN2 cddin;                  /* '<Root>/cddin' */
  int16_T Angleoffset_Init;            /* '<Root>/Angleoffset_Init' */
  real32_T f32_Iddes_A;                /* '<Root>/f32_Iddes_A' */
  boolean_T Drive;                     /* '<Root>/Drive' */
  real32_T f32_Iqdes_A;                /* '<Root>/f32_Iqdes_A' */
  real32_T TrqEmDes;                   /* '<Root>/TrqEmDes' */
  real32_T Uoffset;                    /* '<Root>/Uoffset' */
  real32_T Voffset;                    /* '<Root>/Voffset' */
  real32_T Woffset;                    /* '<Root>/Woffset' */
  real32_T PWMFrqSet;                  /* '<Root>/PWMFrqSet' */
  real32_T UdHCIF;                     /* '<Root>/UdHCIF' */
  real32_T UqHCIF;                     /* '<Root>/UqHCIF' */
  real32_T speed_ref;                  /* '<Root>/speed_ref' */
} pmsmfoc_ExternalInputs;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Sig10ms20ST msgCore2to0_10ms;        /* '<Root>/msgCore2to0_10ms' */
  EGM stGateDrv;                       /* '<Root>/stGateDrv' */
  real32_T SVM_tiGate;                 /* '<Root>/SVM_tiGate' */
  Core2_FOC_Out Core2_FOC_Out_b;       /* '<Root>/Core2_FOC_Out' */
  real32_T ISP_id;                     /* '<Root>/ISP_id' */
  real32_T ISP_iq;                     /* '<Root>/ISP_iq' */
  real32_T KpCoef;                     /* '<Root>/KpCoef' */
  real32_T IFAngle;                    /* '<Root>/IFAngle' */
  real32_T isdSet_last;                /* '<Root>/isdSet_last' */
  real32_T Ts;                         /* '<Root>/Ts' */
  real32_T Id;                         /* '<Root>/Id' */
  real32_T Iq;                         /* '<Root>/Iq' */
  int16_T ISP_agRtrElecAtan2_i;        /* '<Root>/ISP_agRtrElecAtan2_i' */
  real32_T ISP_n111;                   /* '<Root>/ISP_n111' */
  real32_T ISP_n000;                   /* '<Root>/ISP_n000' */
  real32_T ISP_n222;                   /* '<Root>/ISP_n222' */
} pmsmfoc_ExternalOutputs;

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct pmsmfoc_tag_RTM {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[3];
      uint32_T cLimit[3];
    } TaskCounters;

    struct {
      uint32_T TID0_1;
      boolean_T b_TID0_1;
      uint32_T TID0_2;
      boolean_T b_TID0_2;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern pmsmfoc_D_Work GRDWork;

/* External inputs (root inport signals with default storage) */
extern pmsmfoc_ExternalInputs GRU;

/* External outputs (root outports fed by signals with default storage) */
extern pmsmfoc_ExternalOutputs GRY;

/* Model entry point functions */
extern void pmsmfoc_initialize(void);
extern void pmsmfoc_step0(void);
extern void pmsmfoc_step1(void);
extern void pmsmfoc_step2(void);
extern void pmsmfoc_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern int16_T ISP_agRtrElecAtan2;     /* '<Root>/CDD&ISP' */

/* Electric angle of rotor calculated by atan2 */
extern real32_T ISP_n;                 /* '<Root>/CDD&ISP' */

/* mechanical speed */
extern real32_T ISP_speedref_final;    /* '<Root>/Rate Transition12' */

/* TODO */
extern real32_T PMC_IsdDes;            /* '<S2>/Model' */

/* d-axis target current */
extern real32_T PMC_IsqDes;            /* '<S2>/Model' */

/* q-axis target current */
extern real32_T PMC_TrqOutEst;         /* '<S2>/Model' */

/* Estimated output torque */
extern real32_T PMC_UsMax;             /* '<S4>/facVdc2Vsmax' */

/* SVPWM maximum phase voltage */
extern real32_T PMC_UsdFlt;            /* '<S2>/Model' */

/* d axis output Nrm voltage */
extern real32_T PMC_UsqFlt;            /* '<S2>/Model' */

/* q axis output Nrm voltage */
extern boolean_T PMC_flgReqSafeSt;     /* '<S4>/Rate Transition5' */

/* Safe state flag */
extern EGM PMC_stGateDrv;              /* '<S4>/Constant4' */

/* gate drive mode from the statemachine */
extern real32_T PMC_tiPerd;            /* '<S4>/Constant3' */

/* Period time output from MCT considering variable freuqency and random frequency */
extern real32_T Trqdes_P1;             /* '<Root>/Rate Transition8' */

/* TODO */
extern real32_T usage;                 /* '<S2>/Model' */

/* cmprW */

/* Real-time Model object */

/* Const memory section */
extern pmsmfoc_RT_MODEL *const GRM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Data Type Conversion' : Unused code path elimination
 * Block '<S1>/Data Type Conversion1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion2' : Unused code path elimination
 * Block '<S1>/Rate Transition2' : Unused code path elimination
 * Block '<S4>/Constant2' : Unused code path elimination
 * Block '<S1>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S4>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition9' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'pmsmfoc'
 * '<S1>'   : 'pmsmfoc/CoreMsgIf'
 * '<S2>'   : 'pmsmfoc/PMC&SVM'
 * '<S3>'   : 'pmsmfoc/SAQ'
 * '<S4>'   : 'pmsmfoc/PMC&SVM/PMC'
 * '<S5>'   : 'pmsmfoc/SAQ/cddRt'
 */
#endif                                 /* RTW_HEADER_pmsmfoc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
