/*
 * File: FOC.h
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

#ifndef RTW_HEADER_FOC_h_
#define RTW_HEADER_FOC_h_
#ifndef FOC_COMMON_INCLUDES_
#define FOC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_COMMON_INCLUDES_ */

#include "ECM.h"
#include "FOC_types.h"
#include "currentloop.h"
#include "SVPWM.h"
#include "lookuptabletype.h"
#include "model_reference_types.h"

/* Includes for objects with custom storage classes */
#include "lookuptable.h"
#include "parameter.h"

/* Block signals and states (default storage) for model 'FOC' */
#ifndef FOC_MDLREF_HIDE_CHILD_

typedef struct {
  co1gakok1l_prot Model1_InstanceData; /* '<S1>/Model1' */
  kvcdvf5mir_prot Model2_InstanceData; /* '<S1>/Model2' */
  Duty Model2_o1;                      /* '<S1>/Model2' */
  real32_T Merge;                      /* '<S1>/Merge' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Model1_o3;                  /* '<S1>/Model1' */
  real32_T Model1_o5;                  /* '<S1>/Model1' */
  real32_T Sqrt;                       /* '<S36>/Sqrt' */
  real32_T UnitDelay5_DSTATE;          /* '<S1>/Unit Delay5' */
  real32_T UnitDelay1_DSTATE;          /* '<S11>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_i;        /* '<S14>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_i2;       /* '<S13>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S41>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_e;        /* '<S10>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S42>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S1>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_kc;       /* '<S1>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_j;        /* '<S23>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_c;        /* '<S12>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_eu;       /* '<S45>/Unit Delay1' */
  real32_T UnitDelay3_DSTATE;          /* '<S1>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S1>/Unit Delay4' */
  real32_T UnitDelay_DSTATE;           /* '<S18>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S19>/Unit Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S1>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_m;        /* '<S24>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_l;         /* '<S8>/Unit Delay' */
  real32_T RateTransition12_Buffer;    /* '<S9>/Rate Transition12' */
  real32_T RateTransition6_Buffer;     /* '<S9>/Rate Transition6' */
  real32_T RateTransition7_Buffer;     /* '<S9>/Rate Transition7' */
  real32_T RateTransition8_Buffer;     /* '<S9>/Rate Transition8' */
  uint32_T m_bpIndex[2];               /* '<S33>/ExFeedBack' */
  uint32_T m_bpIndex_j[2];             /* '<S33>/MTPA_T' */
  uint32_T m_bpIndex_h[2];             /* '<S39>/cLdAdpt' */
  uint32_T m_bpIndex_i[2];             /* '<S39>/cLqAdpt' */
  uint32_T m_bpIndex_c;                /* '<S39>/cPsiIsqAdptMot' */
  ECM Switch;                          /* '<S16>/Switch' */
  uint16_T UnitDelay_DSTATE_i;         /* '<S2>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE_o;        /* '<S2>/Unit Delay1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  boolean_T reset_not_empty;           /* '<S1>/MATLAB Function' */
  boolean_T Subsystem_MODE;            /* '<S1>/Subsystem' */
} FOCpmsmfoc_rtDW_a;

#endif                                 /*FOC_MDLREF_HIDE_CHILD_*/

#ifndef FOC_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct FOCpmsmfoc_tag_RTM {
  const char_T **errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID0_1;
      boolean_T b_TID0_1;
    } RateInteraction;
  } Timing;
};

#endif                                 /*FOC_MDLREF_HIDE_CHILD_*/

#ifndef FOC_MDLREF_HIDE_CHILD_

typedef struct {
  FOCpmsmfoc_RT_MODEL rtm;
} FOCpmsmfoc_rtMdlrefDWork_n;

#endif                                 /*FOC_MDLREF_HIDE_CHILD_*/



/* Declare global externs for instrumentation */
extern void profileStart_FOC(uint32_T);
extern void profileEnd_FOC(uint32_T);
/* Code_Instrumentation_Declarations_Placeholder */
extern void FOC_Init(real32_T *y_f32_Duty_f32_DutyUon, real32_T
                     *y_f32_Duty_f32_DutyVon, real32_T *y_f32_Duty_f32_DutyWon);
extern void FOC_Reset(void);
extern void FOC_Disable(real32_T *y_f32_Duty_f32_DutyUon, real32_T
  *y_f32_Duty_f32_DutyVon, real32_T *y_f32_Duty_f32_DutyWon);
extern void FOCTID0(const real32_T *u_f32_CurrentU_A, const real32_T
                    *u_f32_CurrentV_A, const real32_T *u_f32_CurrentW_A, const
                    real32_T *u_f32_SpeedAct_rpm, const real32_T
                    *u_f32_Speedref_rpm, const real32_T *u_f32_Iddes_A, const
                    real32_T *u_f32_Iqdes_A, const real32_T *u_Udc, const
                    real32_T *u_f32_ModulationReq, const ECM *u_ControlMode,
                    const uint16_T *u_Angle, const uint8_T *u_ROLState, const
                    real32_T *u_iddes, const boolean_T *u_Drive, const real32_T *
                    u_PWMFrqSet, const real32_T *u_UdHCIF, const real32_T
                    *u_UqHCIF, real32_T *y_f32_Duty_f32_DutyUon, real32_T
                    *y_f32_Duty_f32_DutyVon, real32_T *y_f32_Duty_f32_DutyWon,
                    real32_T *y_KpCoef, real32_T *y_isdSet_last, real32_T *y_Ts,
                    real32_T *y_Id, real32_T *y_Iq);
extern void FOCTID1(void);

/* Model reference registration function */
extern void FOC_initialize(const char_T **rt_errorStatus, const rtTimingBridge
  *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T FOC_AcrKpCalOpt;       /* '<S17>/AsrPI1' */

/* TODO */
extern real32_T FOC_CurKp;             /* '<S17>/Divide' */

/* curkp */
extern real32_T ISP_iDaFild;           /* '<S41>/Sum1' */

/* d-axis filtered current,A */
extern real32_T ISP_iQaFild;           /* '<S42>/Sum1' */

/* q-axis filtered current,A */
extern real32_T PMC_FFW_opt;           /* '<S33>/Gain' */

/* TODO */
extern real32_T PMC_FWC_opt;           /* '<S24>/MATLAB Function1' */

/* TODO */
extern real32_T PMC_IsMax;             /* '<S25>/Ismax1' */

/* Caculated maximum phase current at current frequency */
extern real32_T PMC_IsdDes;            /* '<S1>/Gain2' */

/* d-axis target current */
extern real32_T PMC_IsqDes;            /* '<S1>/Gain1' */

/* q-axis target current */
extern real32_T PMC_Ld;                /* '<S39>/Product4' */

/* d-axis inductance */
extern real32_T PMC_LpfOpt;            /* '<S1>/MATLAB Function1' */

/* TODO */
extern real32_T PMC_LpfSpdAct;         /* '<S14>/Sum1' */

/* TODO */
extern real32_T PMC_Lq;                /* '<S39>/Product5' */

/* q-axis inductance */
extern real32_T PMC_LqSubLd;           /* '<S39>/Add1' */

/* q-axis sub d-axis inductance */
extern real32_T PMC_MTPA_opt;          /* '<S33>/Gain2' */

/* TODO */
extern real32_T PMC_PsiExc;            /* '<S39>/Product1' */

/* flux */
extern real32_T PMC_PsiMax;            /* '<S33>/Saturation' */

/* Calculated maximum flux for flux weakening control */
extern real32_T PMC_TrqOutEst;         /* '<S43>/Switch2' */

/* Estimated output torque */
extern real32_T PMC_UsdFlt;            /* '<S18>/Plus' */

/* d axis output Nrm voltage */
extern real32_T PMC_UsdScal;           /* '<S1>/Model1' */

/* d axis output Nrm voltage */
extern real32_T PMC_UsqFlt;            /* '<S19>/Plus' */

/* q axis output Nrm voltage */
extern real32_T PMC_UsqScal;           /* '<S1>/Model1' */

/* q axis output Nrm voltage */
extern real32_T PMC_isdFlt;            /* '<S13>/Sum1' */

/* alphaBeta-dq current, A */
extern real32_T PMC_isqFlt;            /* '<S10>/Sum1' */

/* alphaBeta-dq current, A */
extern real32_T PMC_pwmfrq;            /* '<S15>/Switch' */

/* cmprW */
extern real32_T ToSee_idAnti_windup;   /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T ToSee_iqAnti_windup;   /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T Trqdes_P1;

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
extern real32_T usage;                 /* '<S23>/Sum1' */

/* cmprW */
extern real32_T usd_output;            /* '<S1>/MATLAB Function' */

/* TODO */
extern real32_T usq_output;            /* '<S1>/MATLAB Function' */

/* TODO */
#ifndef FOC_MDLREF_HIDE_CHILD_

extern FOCpmsmfoc_rtMdlrefDWork_n FOCpmsmfoc_rtMdlrefDWork;

#endif                                 /*FOC_MDLREF_HIDE_CHILD_*/

#ifndef FOC_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern FOCpmsmfoc_rtDW_a FOCpmsmfoc_rtDWork;

#endif                                 /*FOC_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant3' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S25>/Abs' : Unused code path elimination
 * Block '<S25>/Freq vs MaxI' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S32>/Product1' : Unused code path elimination
 * Block '<S32>/Product3' : Unused code path elimination
 * Block '<S32>/Subtract' : Unused code path elimination
 * Block '<S32>/Sum1' : Unused code path elimination
 * Block '<S32>/Unit Delay1' : Unused code path elimination
 * Block '<S25>/tauPT1IsMax' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Gain' : Unused code path elimination
 * Block '<S16>/Constant2' : Unused code path elimination
 * Block '<S16>/Constant4' : Unused code path elimination
 * Block '<S16>/Constant5' : Unused code path elimination
 * Block '<S16>/Constant6' : Unused code path elimination
 * Block '<S16>/Constant7' : Unused code path elimination
 * Block '<S16>/Equal2' : Unused code path elimination
 * Block '<S16>/Equal3' : Unused code path elimination
 * Block '<S16>/Equal4' : Unused code path elimination
 * Block '<S16>/Equal5' : Unused code path elimination
 * Block '<S16>/Equal6' : Unused code path elimination
 * Block '<S16>/OR' : Unused code path elimination
 * Block '<S17>/Add' : Unused code path elimination
 * Block '<S17>/Constant2' : Unused code path elimination
 * Block '<S17>/Gain' : Unused code path elimination
 * Block '<S17>/Product' : Unused code path elimination
 * Block '<S17>/Product3' : Unused code path elimination
 * Block '<S17>/Sqrt' : Unused code path elimination
 * Block '<S9>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S9>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S7>'   : 'FOC/bldc/MATLAB Function1'
 * '<S8>'   : 'FOC/bldc/PMC_IsDesCalc'
 * '<S9>'   : 'FOC/bldc/PMC_PsmMdl1'
 * '<S10>'  : 'FOC/bldc/PT1'
 * '<S11>'  : 'FOC/bldc/PT1_1'
 * '<S12>'  : 'FOC/bldc/PT1_2'
 * '<S13>'  : 'FOC/bldc/PT2'
 * '<S14>'  : 'FOC/bldc/PT3'
 * '<S15>'  : 'FOC/bldc/PWMfreq'
 * '<S16>'  : 'FOC/bldc/Subsystem'
 * '<S17>'  : 'FOC/bldc/Subsystem1'
 * '<S18>'  : 'FOC/bldc/Subsystem3'
 * '<S19>'  : 'FOC/bldc/Subsystem4'
 * '<S20>'  : 'FOC/bldc/Switch Case Action Subsystem'
 * '<S21>'  : 'FOC/bldc/Switch Case Action Subsystem1'
 * '<S22>'  : 'FOC/bldc/abc2dq'
 * '<S23>'  : 'FOC/bldc/FwcFdbCalc/PT1_1'
 * '<S24>'  : 'FOC/bldc/PMC_IsDesCalc/FWC'
 * '<S25>'  : 'FOC/bldc/PMC_IsDesCalc/MaxI vs Freq'
 * '<S26>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_GenSigCalcn'
 * '<S27>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsdDesCalc'
 * '<S28>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc'
 * '<S29>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_PwmModCalcn'
 * '<S30>'  : 'FOC/bldc/PMC_IsDesCalc/FWC/MATLAB Function1'
 * '<S31>'  : 'FOC/bldc/PMC_IsDesCalc/FWC/PI'
 * '<S32>'  : 'FOC/bldc/PMC_IsDesCalc/MaxI vs Freq/PT1_2'
 * '<S33>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsdDesCalc/iDaDesTblLimd'
 * '<S34>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqDesLim_Calc'
 * '<S35>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqTrqDes_Calc'
 * '<S36>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqDesLim_Calc/SQRT'
 * '<S37>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqTrqDes_Calc/MCT_PsmPsiTrqCalc'
 * '<S38>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_GenSigCalcn'
 * '<S39>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_PsmParCalc'
 * '<S40>'  : 'FOC/bldc/PMC_PsmMdl1/PMC_TrqCal'
 * '<S41>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_GenSigCalcn/PT1'
 * '<S42>'  : 'FOC/bldc/PMC_PsmMdl1/MCT_GenSigCalcn/PT2'
 * '<S43>'  : 'FOC/bldc/PMC_PsmMdl1/PMC_TrqCal/Saturation Dynamic1'
 * '<S44>'  : 'FOC/bldc/Subsystem1/AsrPI1'
 * '<S45>'  : 'FOC/bldc/abc2dq/PT1'
 * '<S46>'  : 'FOC/bldc/abc2dq/Transform'
 * '<S47>'  : 'FOC/bldc/abc2dq/Transform/Subsystem'
 */
#endif                                 /* RTW_HEADER_FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
