/*
 * File: FOC.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 1.117
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  3 16:25:38 2025
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
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Merge;                      /* '<S1>/Merge' */
  real32_T Model1_o1;                  /* '<S1>/Model1' */
  real32_T Model1_o2;                  /* '<S1>/Model1' */
  real32_T Model1_o3;                  /* '<S1>/Model1' */
  real32_T Model1_o5;                  /* '<S1>/Model1' */
  real32_T Sqrt;                       /* '<S31>/Sqrt' */
  real32_T UnitDelay1_DSTATE;          /* '<S8>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S37>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S38>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S1>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_kc;       /* '<S1>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_j;        /* '<S17>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_c;        /* '<S9>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_e;        /* '<S41>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S13>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S14>/Unit Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S1>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_m;        /* '<S18>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_o;        /* '<S26>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_l;         /* '<S6>/Unit Delay' */
  real32_T DelayInput2_DSTATE;         /* '<S30>/Delay Input2' */
  real32_T RateTransition12_Buffer;    /* '<S7>/Rate Transition12' */
  real32_T RateTransition6_Buffer;     /* '<S7>/Rate Transition6' */
  real32_T RateTransition7_Buffer;     /* '<S7>/Rate Transition7' */
  real32_T RateTransition8_Buffer;     /* '<S7>/Rate Transition8' */
  uint32_T m_bpIndex_a[2];             /* '<S27>/ExFeedBack' */
  uint32_T m_bpIndex_j[2];             /* '<S27>/MTPA_T' */
  uint32_T m_bpIndex_h[2];             /* '<S35>/cLdAdpt' */
  uint32_T m_bpIndex_i[2];             /* '<S35>/cLqAdpt' */
  uint32_T m_bpIndex;                  /* '<S19>/Freq vs MaxI' */
  uint32_T m_bpIndex_c;                /* '<S35>/cPsiIsqAdptMot' */
  ECM Switch;                          /* '<S11>/Switch' */
  uint16_T UnitDelay_DSTATE_i;         /* '<S2>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE_oc;       /* '<S2>/Unit Delay1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
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
                    u_PWMFrqSet, const real32_T *u_TrqEmDes, real32_T
                    *y_f32_Duty_f32_DutyUon, real32_T *y_f32_Duty_f32_DutyVon,
                    real32_T *y_f32_Duty_f32_DutyWon, real32_T *y_Iqref,
                    real32_T *y_Idref, real32_T *y_Udref, real32_T *y_Uqref,
                    real32_T *y_Usage, real32_T *y_KpCoef, real32_T
                    *y_isdSet_last, real32_T *y_Ts, real32_T *y_Id, real32_T
                    *y_Iq);
extern void FOCTID1(void);

/* Model reference registration function */
extern void FOC_initialize(const char_T **rt_errorStatus, const rtTimingBridge
  *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T FOC_CurKp;             /* '<S12>/Divide' */

/* curkp */
extern real32_T ISP_iDaFild;           /* '<S37>/Sum1' */

/* d-axis filtered current,A */
extern real32_T ISP_iQaFild;           /* '<S38>/Sum1' */

/* q-axis filtered current,A */
extern real32_T PMC_IsMax;             /* '<S19>/Product' */

/* Caculated maximum phase current at current frequency */
extern real32_T PMC_Ld;                /* '<S35>/Product4' */

/* d-axis inductance */
extern real32_T PMC_Lq;                /* '<S35>/Product5' */

/* q-axis inductance */
extern real32_T PMC_LqSubLd;           /* '<S35>/Add1' */

/* q-axis sub d-axis inductance */
extern real32_T PMC_PsiExc;            /* '<S35>/Product1' */

/* flux */
extern real32_T PMC_PsiMax;            /* '<S27>/Saturation' */

/* Calculated maximum flux for flux weakening control */
extern real32_T PMC_TrqOutEst;         /* '<S39>/Switch2' */

/* Estimated output torque */
extern real32_T cmprU;                 /* '<S1>/Model2' */

/* cmprU */
extern real32_T cmprV;                 /* '<S1>/Model2' */

/* cmprV */
extern real32_T cmprW;                 /* '<S1>/Model2' */

/* cmprW */
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
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Constant2' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S30>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Propagation' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Gain' : Unused code path elimination
 * Block '<S11>/Constant2' : Unused code path elimination
 * Block '<S11>/Constant4' : Unused code path elimination
 * Block '<S11>/Constant5' : Unused code path elimination
 * Block '<S11>/Constant6' : Unused code path elimination
 * Block '<S11>/Equal2' : Unused code path elimination
 * Block '<S11>/Equal3' : Unused code path elimination
 * Block '<S11>/Equal4' : Unused code path elimination
 * Block '<S11>/Equal5' : Unused code path elimination
 * Block '<S11>/OR' : Unused code path elimination
 * Block '<S7>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S7>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S43>/Constant' : Unused code path elimination
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
 * '<S6>'   : 'FOC/bldc/PMC_IsDesCalc'
 * '<S7>'   : 'FOC/bldc/PMC_PsmMdl1'
 * '<S8>'   : 'FOC/bldc/PT1_1'
 * '<S9>'   : 'FOC/bldc/PT1_2'
 * '<S10>'  : 'FOC/bldc/PWMfreq'
 * '<S11>'  : 'FOC/bldc/Subsystem'
 * '<S12>'  : 'FOC/bldc/Subsystem1'
 * '<S13>'  : 'FOC/bldc/Subsystem3'
 * '<S14>'  : 'FOC/bldc/Subsystem4'
 * '<S15>'  : 'FOC/bldc/Switch Case Action Subsystem'
 * '<S16>'  : 'FOC/bldc/abc2dq'
 * '<S17>'  : 'FOC/bldc/FwcFdbCalc/PT1_1'
 * '<S18>'  : 'FOC/bldc/PMC_IsDesCalc/FWC'
 * '<S19>'  : 'FOC/bldc/PMC_IsDesCalc/MaxI vs Freq'
 * '<S20>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_GenSigCalcn'
 * '<S21>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsdDesCalc'
 * '<S22>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc'
 * '<S23>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_PwmModCalcn'
 * '<S24>'  : 'FOC/bldc/PMC_IsDesCalc/FWC/MATLAB Function1'
 * '<S25>'  : 'FOC/bldc/PMC_IsDesCalc/FWC/PI'
 * '<S26>'  : 'FOC/bldc/PMC_IsDesCalc/MaxI vs Freq/PT1_2'
 * '<S27>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsdDesCalc/iDaDesTblLimd'
 * '<S28>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqDesLim_Calc'
 * '<S29>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqTrqDes_Calc'
 * '<S30>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/Rate Limiter Dynamic'
 * '<S31>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqDesLim_Calc/SQRT'
 * '<S32>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/IsqTrqDes_Calc/MCT_PsmPsiTrqCalc'
 * '<S33>'  : 'FOC/bldc/PMC_IsDesCalc/PMC_IsqDesCalc/Rate Limiter Dynamic/Saturation Dynamic'
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
