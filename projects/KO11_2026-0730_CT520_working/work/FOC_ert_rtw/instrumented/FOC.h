/*
 * File: FOC.h
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

#ifndef RTW_HEADER_FOC_h_
#define RTW_HEADER_FOC_h_
#ifndef FOC_COMMON_INCLUDES_
#define FOC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_COMMON_INCLUDES_ */

#include "FOC_types.h"
#include "ECM.h"
#include "currentloop.h"
#include "SVPWM.h"
#include "lookuptabletype.h"

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

#define FOC_M                          (pmsmfoc_rtM)

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  co1gakok1l_prot Model1_InstanceData; /* '<S1>/Model1' */
  kvcdvf5mir_prot Model2_InstanceData; /* '<S1>/Model2' */
  real32_T Merge;                      /* '<S1>/Merge' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Model1_o3;                  /* '<S1>/Model1' */
  real32_T Model1_o5;                  /* '<S1>/Model1' */
  real32_T Sqrt;                       /* '<S32>/Sqrt' */
  real32_T UnitDelay5_DSTATE;          /* '<S1>/Unit Delay5' */
  real32_T UnitDelay1_DSTATE;          /* '<S9>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S37>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S38>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S1>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_kc;       /* '<S1>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_j;        /* '<S19>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_c;        /* '<S10>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_e;        /* '<S41>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S1>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S1>/Unit Delay4' */
  real32_T UnitDelay_DSTATE;           /* '<S14>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S15>/Unit Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S1>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_m;        /* '<S20>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_l;         /* '<S7>/Unit Delay' */
  real32_T RateTransition12_Buffer;    /* '<S8>/Rate Transition12' */
  real32_T RateTransition6_Buffer;     /* '<S8>/Rate Transition6' */
  real32_T RateTransition7_Buffer;     /* '<S8>/Rate Transition7' */
  real32_T RateTransition8_Buffer;     /* '<S8>/Rate Transition8' */
  uint32_T m_bpIndex[2];               /* '<S29>/ExFeedBack' */
  uint32_T m_bpIndex_j[2];             /* '<S29>/MTPA_T' */
  uint32_T m_bpIndex_h[2];             /* '<S35>/cLdAdpt' */
  uint32_T m_bpIndex_i[2];             /* '<S35>/cLqAdpt' */
  uint32_T m_bpIndex_c;                /* '<S35>/cPsiIsqAdptMot' */
  ECM Switch;                          /* '<S12>/Switch' */
  uint16_T UnitDelay_DSTATE_i;         /* '<S2>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE_o;        /* '<S2>/Unit Delay1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  boolean_T reset_not_empty;           /* '<S1>/MATLAB Function' */
  boolean_T Subsystem_MODE;            /* '<S1>/Subsystem' */
} pmsmfoc_D_Work;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T f32_CurrentU_A;             /* '<Root>/f32_CurrentU_A' */
  real32_T f32_CurrentV_A;             /* '<Root>/f32_CurrentV_A' */
  real32_T f32_CurrentW_A;             /* '<Root>/f32_CurrentW_A' */
  real32_T f32_SpeedAct_rpm;           /* '<Root>/f32_SpeedAct_rpm' */
  real32_T f32_Speedref_rpm;           /* '<Root>/f32_Speedref_rpm' */
  real32_T f32_Iddes_A;                /* '<Root>/f32_Iddes_A' */
  real32_T f32_Iqdes_A;                /* '<Root>/f32_Iqdes_A' */
  real32_T Udc;                        /* '<Root>/Udc ' */
  real32_T f32_ModulationReq;          /* '<Root>/f32_ModulationReq' */
  ECM ControlMode;                     /* '<Root>/ControlMode' */
  uint16_T Angle;                      /* '<Root>/Angle' */
  uint8_T ROLState;                    /* '<Root>/ROLState' */
  real32_T iddes;                      /* '<Root>/iddes' */
  boolean_T Drive;                     /* '<Root>/Drive' */
  real32_T PWMFrqSet;                  /* '<Root>/PWMFrqSet' */
  real32_T UdHCIF;                     /* '<Root>/UdHCIF' */
  real32_T UqHCIF;                     /* '<Root>/UqHCIF' */
} pmsmfoc_ExternalInputs;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Duty f32_Duty;                       /* '<Root>/f32_Duty' */
  real32_T DCCurrent;                  /* '<Root>/DCCurrent' */
  real32_T KpCoef;                     /* '<Root>/KpCoef' */
  real32_T isdSet_last;                /* '<Root>/isdSet_last' */
  real32_T Ts;                         /* '<Root>/Ts' */
} pmsmfoc_ExternalOutputs;



/* Declare global externs for instrumentation */
extern void profileStart_FOC(uint32_T);
extern void profileEnd_FOC(uint32_T);
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
      uint32_T TID[2];
      uint32_T cLimit[2];
    } TaskCounters;

    struct {
      uint32_T TID0_1;
      boolean_T b_TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern pmsmfoc_D_Work pmsmfoc_rtDWork;

/* External inputs (root inport signals with default storage) */
extern pmsmfoc_ExternalInputs pmsmfoc_rtU;

/* External outputs (root outports fed by signals with default storage) */
extern pmsmfoc_ExternalOutputs pmsmfoc_rtY;

/* Model entry point functions */
extern void FOC_initialize(void);
extern void FOC_step0(void);
extern void FOC_step1(void);
extern void FOC_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T FOC_CurKp;             /* '<S13>/Divide' */

/* curkp */
extern real32_T ISP_iDaFild;           /* '<S37>/Sum1' */

/* d-axis filtered current,A */
extern real32_T ISP_iQaFild;           /* '<S38>/Sum1' */

/* q-axis filtered current,A */
extern real32_T PMC_FFW_opt;           /* '<S29>/Gain' */

/* TODO */
extern real32_T PMC_FWC_opt;           /* '<S20>/MATLAB Function1' */

/* TODO */
extern real32_T PMC_IsMax;             /* '<S21>/Ismax1' */

/* Caculated maximum phase current at current frequency */
extern real32_T PMC_IsdDes;            /* '<S1>/Gain2' */

/* d-axis target current */
extern real32_T PMC_IsqDes;            /* '<S1>/Gain1' */

/* q-axis target current */
extern real32_T PMC_Ld;                /* '<S35>/Product4' */

/* d-axis inductance */
extern real32_T PMC_Lq;                /* '<S35>/Product5' */

/* q-axis inductance */
extern real32_T PMC_LqSubLd;           /* '<S35>/Add1' */

/* q-axis sub d-axis inductance */
extern real32_T PMC_MTPA_opt;          /* '<S29>/Gain2' */

/* TODO */
extern real32_T PMC_PsiExc;            /* '<S35>/Product1' */

/* flux */
extern real32_T PMC_PsiMax;            /* '<S29>/Saturation' */

/* Calculated maximum flux for flux weakening control */
extern real32_T PMC_TrqOutEst;         /* '<S39>/Switch2' */

/* Estimated output torque */
extern real32_T PMC_UsdFlt;            /* '<S14>/Plus' */

/* d axis output Nrm voltage */
extern real32_T PMC_UsdScal;           /* '<S1>/Model1' */

/* d axis output Nrm voltage */
extern real32_T PMC_UsqFlt;            /* '<S15>/Plus' */

/* q axis output Nrm voltage */
extern real32_T PMC_UsqScal;           /* '<S1>/Model1' */

/* q axis output Nrm voltage */
extern real32_T PMC_isdFlt;            /* '<S42>/Add' */

/* alphaBeta-dq current, A */
extern real32_T PMC_isqFlt;            /* '<S42>/Subtract2' */

/* alphaBeta-dq current, A */
extern real32_T PMC_pwmfrq;            /* '<S11>/Switch' */

/* cmprW */
extern real32_T ToSee_idAnti_windup;   /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T ToSee_iqAnti_windup;   /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T Trqdes_P1;             /* '<Root>/TrqEmDes' */

/* TODO */
extern real32_T Uq_output_limit;       /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T cmprU;                 /* '<S1>/Model2' */

/* cmprU */
extern real32_T cmprV;                 /* '<S1>/Model2' */

/* cmprV */
extern real32_T cmprW;                 /* '<S1>/Model2' */

/* cmprW */
extern real32_T d_decouple;            /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T d_integral;            /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T q_decouple_Add_ffw;    /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T q_integral;            /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T q_volt_lower;          /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T q_volt_upper;          /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T usage;                 /* '<S19>/Sum1' */

/* cmprW */
extern real32_T usd_output;            /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T usq_output;            /* '<S1>/MATLAB Function' */

/* TODO */

/* Real-time Model object */

/* Const memory section */
extern pmsmfoc_RT_MODEL *const pmsmfoc_rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant3' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S21>/Abs' : Unused code path elimination
 * Block '<S21>/Freq vs MaxI' : Unused code path elimination
 * Block '<S28>/Constant' : Unused code path elimination
 * Block '<S28>/Product1' : Unused code path elimination
 * Block '<S28>/Product3' : Unused code path elimination
 * Block '<S28>/Subtract' : Unused code path elimination
 * Block '<S28>/Sum1' : Unused code path elimination
 * Block '<S28>/Unit Delay1' : Unused code path elimination
 * Block '<S21>/tauPT1IsMax' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/Gain' : Unused code path elimination
 * Block '<S12>/Constant2' : Unused code path elimination
 * Block '<S12>/Constant4' : Unused code path elimination
 * Block '<S12>/Constant5' : Unused code path elimination
 * Block '<S12>/Constant6' : Unused code path elimination
 * Block '<S12>/Constant7' : Unused code path elimination
 * Block '<S12>/Equal2' : Unused code path elimination
 * Block '<S12>/Equal3' : Unused code path elimination
 * Block '<S12>/Equal4' : Unused code path elimination
 * Block '<S12>/Equal5' : Unused code path elimination
 * Block '<S12>/Equal6' : Unused code path elimination
 * Block '<S12>/OR' : Unused code path elimination
 * Block '<S8>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S8>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'FOC'
 * '<S1>'   : 'FOC/bldc'
 * '<S2>'   : 'FOC/bldc/AngleComp'
 * '<S3>'   : 'FOC/bldc/Default'
 * '<S4>'   : 'FOC/bldc/FwcFdbCalc'
 * '<S5>'   : 'FOC/bldc/IF Control'
 * '<S6>'   : 'FOC/bldc/MATLAB Function'
 * '<S7>'   : 'FOC/bldc/PMC_IsDesCalc'
 * '<S8>'   : 'FOC/bldc/PMC_PsmMdl1'
 * '<S9>'   : 'FOC/bldc/PT1_1'
 * '<S10>'  : 'FOC/bldc/PT1_2'
 * '<S11>'  : 'FOC/bldc/PWMfreq'
 * '<S12>'  : 'FOC/bldc/Subsystem'
 * '<S13>'  : 'FOC/bldc/Subsystem1'
 * '<S14>'  : 'FOC/bldc/Subsystem3'
 * '<S15>'  : 'FOC/bldc/Subsystem4'
 * '<S16>'  : 'FOC/bldc/Switch Case Action Subsystem'
 * '<S17>'  : 'FOC/bldc/Switch Case Action Subsystem1'
 * '<S18>'  : 'FOC/bldc/abc2dq'
 * '<S19>'  : 'FOC/bldc/FwcFdbCalc/PT1_1'
 * '<S20>'  : 'FOC/bldc/PMC_IsDesCalc/FWC'
 * '<S21>'  : 'FOC/bldc/PMC_IsDesCalc/MaxI vs Freq'
 * '<S22>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_GenSigCalcn'
 * '<S23>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsdDesCalc'
 * '<S24>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc'
 * '<S25>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_PwmModCalcn'
 * '<S26>'  : 'FOC/bldc/PMC_IsDesCalc/FWC/MATLAB Function1'
 * '<S27>'  : 'FOC/bldc/PMC_IsDesCalc/FWC/PI'
 * '<S28>'  : 'FOC/bldc/PMC_IsDesCalc/MaxI vs Freq/PT1_2'
 * '<S29>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsdDesCalc/iDaDesTblLimd'
 * '<S30>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqDesLim_Calc'
 * '<S31>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqTrqDes_Calc'
 * '<S32>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqDesLim_Calc/SQRT'
 * '<S33>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqTrqDes_Calc/MCT_PsmPsiTrqCalc'
 * '<S34>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_GenSigCalcn'
 * '<S35>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_PsmParCalc'
 * '<S36>'  : 'FOC/bldc/PMC_PsmMdl1/PMC_TrqCal'
 * '<S37>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_GenSigCalcn/PT1'
 * '<S38>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_GenSigCalcn/PT2'
 * '<S39>'  : 'FOC/bldc/PMC_PsmMdl1/PMC_TrqCal/Saturation Dynamic1'
 * '<S40>'  : 'FOC/bldc/Subsystem1/AsrPI1'
 * '<S41>'  : 'FOC/bldc/abc2dq/PT1'
 * '<S42>'  : 'FOC/bldc/abc2dq/Transform'
 * '<S43>'  : 'FOC/bldc/abc2dq/Transform/Subsystem'
 */
#endif                                 /* RTW_HEADER_FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
