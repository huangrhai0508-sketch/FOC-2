/*
 * File: FOC.c
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

#include "FOC.h"
#include <math.h>
#include "rtwtypes.h"
#include "lookuptabletype.h"
#include "ECM.h"
#include "FOC_private.h"
#include "look2_iflf_pbinlca.h"
#include "look1_iflf_pbinlca.h"
#include "parameter.h"
#include "lookuptable.h"
#include "currentloop.h"
#include "SVPWM.h"

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
real32_T FOC_CurKp;                    /* '<S13>/Divide' */

/* curkp */
real32_T ISP_iDaFild;                  /* '<S37>/Sum1' */

/* d-axis filtered current,A */
real32_T ISP_iQaFild;                  /* '<S38>/Sum1' */

/* q-axis filtered current,A */
real32_T PMC_FFW_opt;                  /* '<S29>/Gain' */

/* TODO */
real32_T PMC_FWC_opt;                  /* '<S20>/MATLAB Function1' */

/* TODO */
real32_T PMC_IsMax;                    /* '<S21>/Ismax1' */

/* Caculated maximum phase current at current frequency */
real32_T PMC_IsdDes;                   /* '<S1>/Gain2' */

/* d-axis target current */
real32_T PMC_IsqDes;                   /* '<S1>/Gain1' */

/* q-axis target current */
real32_T PMC_Ld;                       /* '<S35>/Product4' */

/* d-axis inductance */
real32_T PMC_Lq;                       /* '<S35>/Product5' */

/* q-axis inductance */
real32_T PMC_LqSubLd;                  /* '<S35>/Add1' */

/* q-axis sub d-axis inductance */
real32_T PMC_MTPA_opt;                 /* '<S29>/Gain2' */

/* TODO */
real32_T PMC_PsiExc;                   /* '<S35>/Product1' */

/* flux */
real32_T PMC_PsiMax;                   /* '<S29>/Saturation' */

/* Calculated maximum flux for flux weakening control */
real32_T PMC_TrqOutEst;                /* '<S39>/Switch2' */

/* Estimated output torque */
real32_T PMC_UsdFlt;                   /* '<S14>/Plus' */

/* d axis output Nrm voltage */
real32_T PMC_UsdScal;                  /* '<S1>/Model1' */

/* d axis output Nrm voltage */
real32_T PMC_UsqFlt;                   /* '<S15>/Plus' */

/* q axis output Nrm voltage */
real32_T PMC_UsqScal;                  /* '<S1>/Model1' */

/* q axis output Nrm voltage */
real32_T PMC_isdFlt;                   /* '<S42>/Add' */

/* alphaBeta-dq current, A */
real32_T PMC_isqFlt;                   /* '<S42>/Subtract2' */

/* alphaBeta-dq current, A */
real32_T PMC_pwmfrq;                   /* '<S11>/Switch' */

/* cmprW */
real32_T ToSee_idAnti_windup;          /* '<S1>/MATLAB Function' */

/* TODO */
real32_T ToSee_iqAnti_windup;          /* '<S1>/MATLAB Function' */

/* TODO */
real32_T Trqdes_P1;                    /* '<Root>/TrqEmDes' */

/* TODO */
real32_T Uq_output_limit;              /* '<S1>/MATLAB Function' */

/* TODO */
real32_T cmprU;                        /* '<S1>/Model2' */

/* cmprU */
real32_T cmprV;                        /* '<S1>/Model2' */

/* cmprV */
real32_T cmprW;                        /* '<S1>/Model2' */

/* cmprW */
real32_T d_decouple;                   /* '<S1>/MATLAB Function' */

/* TODO */
real32_T d_integral;                   /* '<S1>/MATLAB Function' */

/* TODO */
real32_T q_decouple_Add_ffw;           /* '<S1>/MATLAB Function' */

/* TODO */
real32_T q_integral;                   /* '<S1>/MATLAB Function' */

/* TODO */
real32_T q_volt_lower;                 /* '<S1>/MATLAB Function' */

/* TODO */
real32_T q_volt_upper;                 /* '<S1>/MATLAB Function' */

/* TODO */
real32_T usage;                        /* '<S19>/Sum1' */

/* cmprW */
real32_T usd_output;                   /* '<S1>/MATLAB Function' */

/* TODO */
real32_T usq_output;                   /* '<S1>/MATLAB Function' */

/* TODO */

/* Block signals and states (default storage) */
pmsmfoc_D_Work pmsmfoc_rtDWork;

/* External inputs (root inport signals with default storage) */
pmsmfoc_ExternalInputs pmsmfoc_rtU;

/* External outputs (root outports fed by signals with default storage) */
pmsmfoc_ExternalOutputs pmsmfoc_rtY;

/* Real-time model */
static pmsmfoc_RT_MODEL pmsmfoc_rtM_;

/* Const memory section */
pmsmfoc_RT_MODEL *const pmsmfoc_rtM = &pmsmfoc_rtM_;

/* Model step function for TID0 */
void FOC_step0(void)                   /* Sample time: [0.0001s, 0.0s] */
{
  real32_T UdNeglimt;
  real32_T UdPoslimt;
  real32_T act_Ki;
  real32_T pi_d_AxleOutput;
  real32_T rtb_Add1_l;
  real32_T rtb_Divide3;
  real32_T rtb_Divide_m;
  real32_T rtb_Gain2_d;
  real32_T rtb_Gain3_f;
  real32_T rtb_Sin;
  real32_T rtb_Sqrt;
  real32_T rtb_Sqrt_l;
  real32_T rtb_Subtract_a;
  real32_T rtb_Sum1;
  real32_T temp2;
  int16_T rtb_CastToSingle1;
  uint16_T rtb_Add3;
  uint16_T rtb_Add5;
  uint16_T rtb_Gain8_h;
  uint16_T rtb_angleElec;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0001s, 0.0s] to Sample time: [0.001s, 0.0s]  */
  pmsmfoc_rtM->Timing.RateInteraction.b_TID0_1 =
    (pmsmfoc_rtM->Timing.RateInteraction.TID0_1 == 0);
  (pmsmfoc_rtM->Timing.RateInteraction.TID0_1)++;
  if ((pmsmfoc_rtM->Timing.RateInteraction.TID0_1) > 9) {
    pmsmfoc_rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* Inport: '<Root>/Drive' */
  if (pmsmfoc_rtU.Drive) {
    pmsmfoc_rtDWork.Subsystem_MODE = true;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     *  Inport: '<Root>/ControlMode'
     *  Inport: '<Root>/ROLState'
     *  Logic: '<S12>/AND'
     *  Logic: '<S12>/NOT'
     *  RelationalOperator: '<S12>/Equal'
     *  RelationalOperator: '<S12>/Equal1'
     */
    if ((pmsmfoc_rtU.ControlMode != alOfsCal) || (pmsmfoc_rtU.ROLState == 1)) {
      /* Switch: '<S12>/Switch' */
      pmsmfoc_rtDWork.Switch = pmsmfoc_rtU.ControlMode;
    } else {
      /* Switch: '<S12>/Switch' incorporates:
       *  Constant: '<S12>/Constant3'
       */
      pmsmfoc_rtDWork.Switch = IsCtrl;
    }

    /* End of Switch: '<S12>/Switch' */
  } else if (pmsmfoc_rtDWork.Subsystem_MODE) {
    /* Disable for Switch: '<S12>/Switch' incorporates:
     *  Outport: '<S12>/Out1'
     */
    pmsmfoc_rtDWork.Switch = Init;
    pmsmfoc_rtDWork.Subsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Sum: '<S9>/Sum1' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Inport: '<Root>/Udc '
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product3'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  rtb_Sum1 = (pmsmfoc_rtU.Udc * 0.001F) + (pmsmfoc_rtDWork.UnitDelay1_DSTATE *
    0.999F);

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S43>/Constant'
   *  Inport: '<Root>/f32_CurrentV_A'
   *  Inport: '<Root>/f32_CurrentW_A'
   *  Switch: '<S43>/Switch'
   */
  if (g_msgCore0to2_motorseq) {
    rtb_Sin = pmsmfoc_rtU.f32_CurrentV_A;
    rtb_Gain3_f = pmsmfoc_rtU.f32_CurrentW_A;
  } else {
    rtb_Sin = pmsmfoc_rtU.f32_CurrentW_A;
    rtb_Gain3_f = pmsmfoc_rtU.f32_CurrentV_A;
  }

  /* End of Switch: '<S43>/Switch1' */

  /* Gain: '<S42>/Gain2' incorporates:
   *  Gain: '<S42>/Gain'
   *  Gain: '<S42>/Gain1'
   *  Inport: '<Root>/f32_CurrentU_A'
   *  Sum: '<S42>/Subtract'
   */
  rtb_Sqrt = ((pmsmfoc_rtU.f32_CurrentU_A - (0.5F * rtb_Sin)) - (0.5F *
    rtb_Gain3_f)) * 0.666666687F;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  if (PWMFrqSwitch_C) {
    /* Switch: '<S11>/Switch' incorporates:
     *  Inport: '<Root>/PWMFrqSet'
     */
    PMC_pwmfrq = pmsmfoc_rtU.PWMFrqSet;
  } else {
    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant'
     */
    PMC_pwmfrq = g_msgCore0to2_pwmFrqSet;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1>/AngleComp' */
  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S2>/Constant8'
   *  Gain: '<S2>/Gain6'
   *  Inport: '<Root>/f32_Speedref_rpm'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Add2'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Add3 = (uint16_T)(((uint32_T)((uint16_T)(((65536.0F *
    pmsmfoc_rtU.f32_Speedref_rpm) / PMC_pwmfrq) + 0.5F))) +
                        pmsmfoc_rtDWork.UnitDelay_DSTATE_i);

  /* Switch: '<S2>/Switch2' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Inport: '<Root>/Angle'
   *  Inport: '<Root>/ControlMode'
   *  RelationalOperator: '<S2>/Equal'
   */
  if (pmsmfoc_rtU.ControlMode != IFCtrl) {
    rtb_angleElec = pmsmfoc_rtU.Angle;
  } else {
    rtb_angleElec = rtb_Add3;
  }

  /* End of Switch: '<S2>/Switch2' */

  /* Gain: '<S2>/Gain8' */
  rtb_Gain8_h = rtb_angleElec;

  /* DataTypeConversion: '<S2>/Cast To Single1' incorporates:
   *  Gain: '<S2>/Gain8'
   *  Sum: '<S2>/Add4'
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  rtb_CastToSingle1 = (int16_T)(((int16_T)rtb_angleElec) - ((int16_T)
    pmsmfoc_rtDWork.UnitDelay1_DSTATE_o));

  /* Sum: '<S2>/Add5' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Product: '<S2>/Product1'
   */
  profileStart_FOC(1U); /* original_line:331 */rtb_Add5 = (uint16_T)(((int16_T)floorf(f32_P_AngleCompCur * ((real32_T)
    rtb_CastToSingle1))) + rtb_angleElec);profileEnd_FOC(1U); /* original_line:332 */

  /* Sum: '<S2>/Add6' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Product: '<S2>/Product3'
   */
  profileStart_FOC(2U); /* original_line:338 */rtb_angleElec = (uint16_T)(((uint32_T)((uint16_T)((int16_T)floorf(((real32_T)
    rtb_CastToSingle1) * f32_P_AngleCompVol)))) + rtb_Add5);profileEnd_FOC(2U); /* original_line:339 */

  /* Gain: '<S2>/Gain2' */
  rtb_Gain2_d = 9.58740711E-5F * ((real32_T)rtb_Add5);

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  Gain: '<S2>/Gain7'
   */
  pmsmfoc_rtDWork.UnitDelay_DSTATE_i = rtb_Add3;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  pmsmfoc_rtDWork.UnitDelay1_DSTATE_o = rtb_Gain8_h;

  /* End of Outputs for SubSystem: '<S1>/AngleComp' */

  /* Trigonometry: '<S42>/Cos' */
  profileStart_FOC(3U); /* original_line:355 */rtb_Sqrt_l = cosf(rtb_Gain2_d);profileEnd_FOC(3U); /* original_line:355 */

  /* Gain: '<S42>/Gain3' incorporates:
   *  Sum: '<S42>/Subtract1'
   */
  rtb_Gain3_f = (rtb_Sin - rtb_Gain3_f) * 0.577350259F;

  /* Trigonometry: '<S42>/Sin' */
  profileStart_FOC(4U); /* original_line:363 */rtb_Sin = sinf(rtb_Gain2_d);profileEnd_FOC(4U); /* original_line:363 */

  /* Sum: '<S42>/Add' incorporates:
   *  Product: '<S42>/Product'
   *  Product: '<S42>/Product1'
   */
  PMC_isdFlt = (rtb_Sqrt * rtb_Sqrt_l) + (rtb_Gain3_f * rtb_Sin);

  /* Sum: '<S37>/Sum1' incorporates:
   *  Constant: '<S34>/tauPT1Isd'
   *  Gain: '<S8>/Gain'
   *  Product: '<S37>/Product1'
   *  Product: '<S37>/Product3'
   *  UnitDelay: '<S37>/Unit Delay1'
   */
  ISP_iDaFild = ((0.707106769F * PMC_isdFlt) * 0.1F) +
    (pmsmfoc_rtDWork.UnitDelay1_DSTATE_k * 0.9F);

  /* Sum: '<S42>/Subtract2' incorporates:
   *  Product: '<S42>/Product2'
   *  Product: '<S42>/Product3'
   */
  PMC_isqFlt = (rtb_Gain3_f * rtb_Sqrt_l) - (rtb_Sqrt * rtb_Sin);

  /* Sum: '<S38>/Sum1' incorporates:
   *  Constant: '<S34>/tauPT1Isd'
   *  Gain: '<S8>/Gain1'
   *  Product: '<S38>/Product1'
   *  Product: '<S38>/Product3'
   *  UnitDelay: '<S38>/Unit Delay1'
   */
  ISP_iQaFild = ((0.707106769F * PMC_isqFlt) * 0.1F) +
    (pmsmfoc_rtDWork.UnitDelay1_DSTATE_a * 0.9F);

  /* Outputs for Atomic SubSystem: '<S8>/MCT_PsmParCalc' */
  /* Abs: '<S35>/Abs' */
  profileStart_FOC(5U); /* original_line:399 */rtb_Sqrt_l = fabsf(ISP_iDaFild);profileEnd_FOC(5U); /* original_line:399 */

  /* Lookup_n-D: '<S35>/cLdAdpt' incorporates:
   *  Sqrt: '<S18>/Sqrt'
   *  Sum: '<S38>/Sum1'
   */
  profileStart_FOC(6U); /* original_line:405 */rtb_Sqrt = look2_iflf_pbinlca(ISP_iQaFild, rtb_Sqrt_l, (const real32_T *)
    &cLdAdptMon_T.bp1[0], (const real32_T *)&cLdAdptMon_T.bp2[0], (const
    real32_T *)&cLdAdptMon_T.tab[0], pmsmfoc_rtDWork.m_bpIndex_h,
    rtCP_cLdAdpt_maxIndex, 61U);profileEnd_FOC(6U); /* original_line:408 */

  /* Product: '<S35>/Product4' incorporates:
   *  Constant: '<S35>/LdBas'
   */
  PMC_Ld = SC_Ld_P * rtb_Sqrt;

  /* Lookup_n-D: '<S35>/cLqAdpt' incorporates:
   *  Sqrt: '<S18>/Sqrt'
   *  Sum: '<S38>/Sum1'
   */
  profileStart_FOC(7U); /* original_line:419 */rtb_Sqrt_l = look2_iflf_pbinlca(ISP_iQaFild, rtb_Sqrt_l, (const real32_T *)
    &cLqAdptMon_T.bp1[0], (const real32_T *)&cLqAdptMon_T.bp2[0], (const
    real32_T *)&cLqAdptMon_T.tab[0], pmsmfoc_rtDWork.m_bpIndex_i,
    rtCP_cLqAdpt_maxIndex, 61U);profileEnd_FOC(7U); /* original_line:422 */

  /* Product: '<S35>/Product5' incorporates:
   *  Constant: '<S35>/LqBas'
   */
  PMC_Lq = rtb_Sqrt_l * SC_Lq_P;

  /* Sum: '<S35>/Add1' */
  PMC_LqSubLd = PMC_Lq - PMC_Ld;

  /* Lookup_n-D: '<S35>/cPsiIsqAdptMot' incorporates:
   *  Sum: '<S38>/Sum1'
   */
  profileStart_FOC(8U); /* original_line:435 */rtb_Sqrt_l = look1_iflf_pbinlca(ISP_iQaFild, (const real32_T *)
    &cPsiIsqAdptMot_TT.bp1[0], (const real32_T *)&cPsiIsqAdptMot_TT.tab[0],
    &pmsmfoc_rtDWork.m_bpIndex_c, 120U);profileEnd_FOC(8U); /* original_line:437 */

  /* Product: '<S35>/Product1' incorporates:
   *  Constant: '<S8>/psiExc_25degC'
   */
  PMC_PsiExc = SC_Psi_P * rtb_Sqrt_l;

  /* End of Outputs for SubSystem: '<S8>/MCT_PsmParCalc' */

  /* Product: '<S11>/Divide' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  rtb_Sin = 1.0F / PMC_pwmfrq;

  /* Product: '<S4>/Product2' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_Sqrt = rtb_Sin * 500.0F;

  /* Sum: '<S19>/Sum1' incorporates:
   *  Constant: '<S19>/Constant'
   *  Product: '<S19>/Product1'
   *  Product: '<S19>/Product3'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Sqrt: '<S4>/Sqrt'
   *  Sum: '<S19>/Subtract'
   *  Sum: '<S4>/Add'
   *  UnitDelay: '<S19>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  profileStart_FOC(9U); /* original_line:469 */usage = (sqrtf((pmsmfoc_rtDWork.UnitDelay2_DSTATE *
                  pmsmfoc_rtDWork.UnitDelay2_DSTATE) +
                 (pmsmfoc_rtDWork.UnitDelay1_DSTATE_kc *
                  pmsmfoc_rtDWork.UnitDelay1_DSTATE_kc)) * rtb_Sqrt) + ((1.0F -
    rtb_Sqrt) * pmsmfoc_rtDWork.UnitDelay1_DSTATE_j);profileEnd_FOC(9U); /* original_line:473 */

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Constant: '<S21>/Ismax1'
   *  Constant: '<S30>/IsResDes'
   *  Math: '<S30>/Math Function2'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  Sum: '<S30>/Sum2'
   */
  rtPrevAction = pmsmfoc_rtDWork.SwitchCase_ActiveSubsystem;
  switch (pmsmfoc_rtDWork.Switch) {
   case nCtrl:
   case TrqCtrl:
    rtAction = 0;
    break;

   case IFCtrl:
    rtAction = 1;
    break;

   case IsCtrl:
   case alOfsCal:
    rtAction = 2;
    break;

   case Discharge:
    rtAction = 3;
    break;

   default:
    rtAction = 4;
    break;
  }

  pmsmfoc_rtDWork.SwitchCase_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/PMC_IsDesCalc' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S20>/Unit Delay1'
       *  UnitDelay: '<S7>/Unit Delay'
       */
      pmsmfoc_rtDWork.UnitDelay1_DSTATE_m = 0.0F;
      pmsmfoc_rtDWork.UnitDelay_DSTATE_l = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S1>/PMC_IsDesCalc' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/PMC_IsDesCalc' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S7>/PMC_IsdDesCalc' */
    /* Abs: '<S29>/Abs' incorporates:
     *  Inport: '<Root>/TrqEmDes'
     */
    profileStart_FOC(10U); /* original_line:531 */rtb_Sqrt = fabsf(Trqdes_P1);profileEnd_FOC(10U); /* original_line:531 */

    /* End of Outputs for SubSystem: '<S7>/PMC_IsdDesCalc' */

    /* Outputs for Atomic SubSystem: '<S7>/PMC_PwmModCalcn' */
    /* Outputs for Atomic SubSystem: '<S7>/PMC_GenSigCalcn' */
    /* Product: '<S25>/Product' incorporates:
     *  Abs: '<S22>/Abs'
     *  Constant: '<S22>/unit'
     *  Constant: '<S22>/w10Hz'
     *  Gain: '<S7>/Gain'
     *  Gain: '<S7>/Gain2'
     *  Gain: '<S7>/Gain3'
     *  Gain: '<S7>/facMaxMI'
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  MinMax: '<S22>/MinMax'
     *  Product: '<S22>/Divide'
     */
    profileStart_FOC(11U); /* original_line:549 */rtb_Add1_l = (1.0F / fmaxf(62.831852F, fabsf(((u16_P_MotorPair / 60.0F) *
      pmsmfoc_rtU.f32_SpeedAct_rpm) * 6.28318548F))) * ((0.408248305F * rtb_Sum1)
      * f32_P_Modulation);profileEnd_FOC(11U); /* original_line:551 */

    /* End of Outputs for SubSystem: '<S7>/PMC_GenSigCalcn' */
    /* End of Outputs for SubSystem: '<S7>/PMC_PwmModCalcn' */

    /* Outputs for Atomic SubSystem: '<S7>/PMC_IsdDesCalc' */
    /* Saturate: '<S29>/Saturation' */
    if (rtb_Add1_l > 0.18F) {
      /* Saturate: '<S29>/Saturation' */
      PMC_PsiMax = 0.18F;
    } else if (rtb_Add1_l < 0.006F) {
      /* Saturate: '<S29>/Saturation' */
      PMC_PsiMax = 0.006F;
    } else {
      /* Saturate: '<S29>/Saturation' */
      PMC_PsiMax = rtb_Add1_l;
    }

    /* End of Saturate: '<S29>/Saturation' */

    /* Lookup_n-D: '<S29>/ExFeedBack' incorporates:
     *  Abs: '<S29>/Abs'
     *  Saturate: '<S29>/Saturation'
     */
    profileStart_FOC(12U); /* original_line:575 */rtb_Sqrt_l = look2_iflf_pbinlca(rtb_Sqrt, PMC_PsiMax, (const real32_T *)
      &ExFeedBack_T.bp1[0], (const real32_T *)&ExFeedBack_T.bp2[0], (const
      real32_T *)&ExFeedBack_T.tab[0], pmsmfoc_rtDWork.m_bpIndex,
      rtCP_ExFeedBack_maxIndex, 21U);profileEnd_FOC(12U); /* original_line:578 */

    /* Gain: '<S29>/Gain' incorporates:
     *  Sum: '<S29>/Add'
     */
    PMC_FFW_opt = ((real32_T)g_msgCore0to2_FFW_Gain) * rtb_Sqrt_l;

    /* Gain: '<S29>/Gain1' incorporates:
     *  Abs: '<S29>/Abs1'
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S29>/Constant2'
     *  Constant: '<S29>/Constant3'
     *  MinMax: '<S29>/Min1'
     *  Product: '<S29>/Divide'
     */
    profileStart_FOC(13U); /* original_line:593 */rtb_Sqrt_l = -fabsf(g_msgCore0to2_maxCur * fminf
                        (g_msgCore0to2_maxFwcCurRatio, 1.0F));profileEnd_FOC(13U); /* original_line:594 */

    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant'
     *  Constant: '<S29>/Constant5'
     */
    if (g_msgCore0to2_CalibEn) {
      rtb_Sqrt = 0.0F;
    } else {
      /* Lookup_n-D: '<S29>/MTPA_T' incorporates:
       *  Abs: '<S29>/Abs'
       */
      profileStart_FOC(14U); /* original_line:606 */rtb_Sqrt = look2_iflf_pbinlca(rtb_Sqrt, 0.0F, (const real32_T *)
        &MTPA_T.bp1[0], (const real32_T *)&MTPA_T.bp2[0], (const real32_T *)
        &MTPA_T.tab[0], pmsmfoc_rtDWork.m_bpIndex_j, rtCP_MTPA_T_maxIndex, 21U);profileEnd_FOC(14U); /* original_line:608 */
    }

    /* End of Switch: '<S29>/Switch' */

    /* Gain: '<S29>/Gain2' */
    PMC_MTPA_opt = ((real32_T)g_msgCore0to2_MTPA_Gain) * rtb_Sqrt;

    /* MinMax: '<S29>/MinMax' incorporates:
     *  MinMax: '<S29>/MinMax1'
     */
    profileStart_FOC(15U); /* original_line:619 */rtb_Gain3_f = fmaxf(rtb_Sqrt_l, fminf(PMC_FFW_opt, PMC_MTPA_opt));profileEnd_FOC(15U); /* original_line:619 */

    /* End of Outputs for SubSystem: '<S7>/PMC_IsdDesCalc' */

    /* Sum: '<S20>/Add' incorporates:
     *  MinMax: '<S20>/Min2'
     */
    profileStart_FOC(16U); /* original_line:626 */rtb_Gain2_d = fmaxf(PMC_MTPA_opt, rtb_Sqrt_l) - rtb_Gain3_f;profileEnd_FOC(16U); /* original_line:626 */

    /* Sum: '<S20>/Add1' */
    rtb_Add1_l = rtb_Sqrt_l - rtb_Gain3_f;

    /* Sum: '<S20>/Subtract' incorporates:
     *  Constant: '<S1>/Constant4'
     *  Inport: '<Root>/f32_ModulationReq'
     *  MinMax: '<S1>/Min'
     */
    profileStart_FOC(17U); /* original_line:636 */rtb_Subtract_a = fminf(f32_P_Modulation, pmsmfoc_rtU.f32_ModulationReq) -
      usage;profileEnd_FOC(17U); /* original_line:637 */

    /* Product: '<S27>/Divide' incorporates:
     *  Constant: '<S27>/Constant1'
     *  Constant: '<S27>/Constant4'
     */
    rtb_Divide_m = g_msgCore0to2_AfrKp * g_msgCore0to2_maxCur;

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S27>/Constant2'
     */
    if (rtb_Subtract_a > 0.0F) {
      rtb_Sqrt_l = 0.25F;
    } else {
      rtb_Sqrt_l = 1.0F;
    }

    /* End of Switch: '<S27>/Switch' */

    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S27>/Constant5'
     *  Constant: '<S27>/Constant6'
     *  Product: '<S27>/Divide1'
     */
    if (g_msgCore0to2_AfrTi != 0.0F) {
      rtb_Sqrt = (rtb_Divide_m * rtb_Sin) / g_msgCore0to2_AfrTi;
    } else {
      rtb_Sqrt = 0.0F;
    }

    /* End of Switch: '<S27>/Switch2' */

    /* Product: '<S27>/Divide3' */
    rtb_Divide3 = rtb_Sqrt * rtb_Sqrt_l;

    /* MATLAB Function: '<S20>/MATLAB Function1' incorporates:
     *  Product: '<S27>/Divide2'
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    rtb_Sqrt = pmsmfoc_rtDWork.UnitDelay1_DSTATE_m;

    /* MATLAB Function 'bldc/PMC_IsDesCalc/FWC/MATLAB Function1': '<S26>:1' */
    /* '<S26>:1:2' temp = err*kp; */
    /* '<S26>:1:3' out = temp + intg; */
    rtb_Sqrt_l = ((rtb_Divide_m * rtb_Sqrt_l) * rtb_Subtract_a) +
      pmsmfoc_rtDWork.UnitDelay1_DSTATE_m;

    /* '<S26>:1:4' if(out>MAX) */
    if (rtb_Sqrt_l > rtb_Gain2_d) {
      /* '<S26>:1:5' out = MAX; */
      rtb_Sqrt_l = rtb_Gain2_d;

      /* '<S26>:1:6' if(err<0) */
      if (rtb_Subtract_a < 0.0F) {
        /* '<S26>:1:7' intg = intg + ki*err; */
        rtb_Sqrt = (rtb_Divide3 * rtb_Subtract_a) +
          pmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
      }
    } else if (rtb_Sqrt_l < rtb_Add1_l) {
      /* '<S26>:1:9' elseif(out < MIN) */
      /* '<S26>:1:10' out = MIN; */
      rtb_Sqrt_l = rtb_Add1_l;

      /* '<S26>:1:11' if(err>0) */
      if (rtb_Subtract_a > 0.0F) {
        /* '<S26>:1:12' intg = intg + ki*err; */
        rtb_Sqrt = (rtb_Divide3 * rtb_Subtract_a) +
          pmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
      }
    } else {
      /* '<S26>:1:14' else */
      /* '<S26>:1:15' intg = intg + ki*err; */
      rtb_Sqrt = (rtb_Divide3 * rtb_Subtract_a) +
        pmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
    }

    /* '<S26>:1:17' max(intg,MIN); */
    /* '<S26>:1:18' min(intg,MAX); */
    PMC_FWC_opt = rtb_Sqrt_l;

    /* Sum: '<S20>/Add2' */
    rtb_Gain3_f += PMC_FWC_opt;
    PMC_IsMax = g_msgCore0to2_maxCur;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S21>/Ismax1'
     *  SignalConversion generated from: '<S7>/PMC_IdDes'
     */
    pmsmfoc_rtDWork.Merge1 = rtb_Gain3_f;

    /* Outputs for Atomic SubSystem: '<S7>/PMC_IsqDesCalc' */
    /* Outputs for Atomic SubSystem: '<S24>/IsqTrqDes_Calc' */
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Constant10'
     *  Constant: '<S33>/3p'
     *  Gain: '<S33>/unitNeg'
     *  Inport: '<Root>/TrqEmDes'
     *  Product: '<S31>/Product'
     *  Product: '<S33>/Product1'
     *  Product: '<S33>/Product2'
     *  SignalConversion generated from: '<S31>/MCT_PsiExc'
     *  Sum: '<S33>/Sum1'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    if (g_msgCore0to2_CalibEn) {
      rtb_Gain2_d = Trqdes_P1;
    } else {
      rtb_Gain2_d = Trqdes_P1 / (((PMC_LqSubLd *
        (-pmsmfoc_rtDWork.UnitDelay_DSTATE_l)) + PMC_PsiExc) * (u16_P_MotorPair *
        3.0F));
    }

    /* End of Switch: '<S31>/Switch' */
    /* End of Outputs for SubSystem: '<S24>/IsqTrqDes_Calc' */

    /* Outputs for Atomic SubSystem: '<S24>/IsqDesLim_Calc' */
    /* Sum: '<S30>/Sum1' incorporates:
     *  Math: '<S30>/Math Function'
     *  Math: '<S30>/Math Function1'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    rtb_Sqrt_l = (PMC_IsMax * PMC_IsMax) - (pmsmfoc_rtDWork.UnitDelay_DSTATE_l *
      pmsmfoc_rtDWork.UnitDelay_DSTATE_l);

    /* Outputs for Enabled SubSystem: '<S30>/SQRT' incorporates:
     *  EnablePort: '<S32>/Enable'
     */
    if ((rtb_Sqrt_l - (rtb_Gain2_d * rtb_Gain2_d)) <= 0.0F) {
      /* Sqrt: '<S32>/Sqrt' incorporates:
       *  Abs: '<S32>/Abs'
       */
      profileStart_FOC(18U); /* original_line:769 */pmsmfoc_rtDWork.Sqrt = sqrtf(fabsf(rtb_Sqrt_l));profileEnd_FOC(18U); /* original_line:769 */

      /* Signum: '<S7>/Sign' incorporates:
       *  Inport: '<Root>/TrqEmDes'
       */
      if (Trqdes_P1 < 0.0F) {
        act_Ki = -1.0F;
      } else {
        act_Ki = (real32_T)(Trqdes_P1 > 0.0F);
      }

      /* Merge: '<S1>/Merge' incorporates:
       *  MultiPortSwitch: '<S24>/Index Vector'
       *  Product: '<S30>/Product'
       *  Signum: '<S7>/Sign'
       */
      pmsmfoc_rtDWork.Merge = pmsmfoc_rtDWork.Sqrt * act_Ki;
    } else {
      /* Merge: '<S1>/Merge' incorporates:
       *  MultiPortSwitch: '<S24>/Index Vector'
       */
      pmsmfoc_rtDWork.Merge = rtb_Gain2_d;
    }

    /* End of Outputs for SubSystem: '<S30>/SQRT' */
    /* End of Outputs for SubSystem: '<S24>/IsqDesLim_Calc' */
    /* End of Outputs for SubSystem: '<S7>/PMC_IsqDesCalc' */

    /* Update for UnitDelay: '<S20>/Unit Delay1' incorporates:
     *  Constant: '<S30>/IsResDes'
     *  MATLAB Function: '<S20>/MATLAB Function1'
     *  Math: '<S30>/Math Function2'
     *  RelationalOperator: '<S30>/Relational Operator'
     *  Sum: '<S30>/Sum2'
     */
    pmsmfoc_rtDWork.UnitDelay1_DSTATE_m = rtb_Sqrt;

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    pmsmfoc_rtDWork.UnitDelay_DSTATE_l = rtb_Gain3_f;

    /* End of Outputs for SubSystem: '<S1>/PMC_IsDesCalc' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/IF Control' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S1>/Merge1' incorporates:
     *  Inport: '<Root>/f32_Iddes_A'
     *  SignalConversion generated from: '<S5>/Input'
     */
    pmsmfoc_rtDWork.Merge1 = pmsmfoc_rtU.f32_Iddes_A;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S5>/Constant1'
     *  SignalConversion generated from: '<S5>/Iqref'
     */
    pmsmfoc_rtDWork.Merge = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/IF Control' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant'
     *  Inport: '<Root>/ControlMode'
     *  RelationalOperator: '<S16>/Equal'
     *  Switch: '<S16>/Switch1'
     */
    if (pmsmfoc_rtU.ControlMode == alOfsCal) {
      /* Merge: '<S1>/Merge1' incorporates:
       *  Inport: '<Root>/iddes'
       */
      pmsmfoc_rtDWork.Merge1 = pmsmfoc_rtU.iddes;

      /* Merge: '<S1>/Merge' incorporates:
       *  Constant: '<S16>/Constant1'
       */
      pmsmfoc_rtDWork.Merge = 0.0F;
    } else {
      /* Merge: '<S1>/Merge1' incorporates:
       *  Inport: '<Root>/f32_Iddes_A'
       */
      pmsmfoc_rtDWork.Merge1 = pmsmfoc_rtU.f32_Iddes_A;

      /* Merge: '<S1>/Merge' incorporates:
       *  Inport: '<Root>/f32_Iqdes_A'
       */
      pmsmfoc_rtDWork.Merge = pmsmfoc_rtU.f32_Iqdes_A;
    }

    /* End of Switch: '<S16>/Switch' */
    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Merge: '<S1>/Merge1' incorporates:
     *  Inport: '<Root>/f32_Iddes_A'
     *  SignalConversion generated from: '<S17>/Iddes'
     */
    pmsmfoc_rtDWork.Merge1 = pmsmfoc_rtU.f32_Iddes_A;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S17>/Iqdes'
     *  SignalConversion generated from: '<S17>/Iqref'
     */
    pmsmfoc_rtDWork.Merge = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem1' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Default' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S3>/Constant'
     *  SignalConversion generated from: '<S3>/Idref '
     */
    pmsmfoc_rtDWork.Merge1 = 0.0F;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S3>/Constant1'
     *  SignalConversion generated from: '<S3>/Iqref'
     */
    pmsmfoc_rtDWork.Merge = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/Default' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Gain: '<S1>/Gain1' */
  PMC_IsqDes = 1.41421354F * pmsmfoc_rtDWork.Merge;

  /* Gain: '<S1>/Gain2' */
  PMC_IsdDes = 1.41421354F * pmsmfoc_rtDWork.Merge1;

  /* Sum: '<S10>/Sum1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Gain: '<S1>/Gain5'
   *  Inport: '<Root>/f32_SpeedAct_rpm'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product3'
   *  Sum: '<S10>/Subtract'
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  rtb_Sqrt = (((((u16_P_MotorPair * 2.0F) * 3.14159274F) / 60.0F) *
               pmsmfoc_rtU.f32_SpeedAct_rpm) * g_msgCore0to2_arc_dd_fi) + ((1.0F
    - g_msgCore0to2_arc_dd_fi) * pmsmfoc_rtDWork.UnitDelay1_DSTATE_c);

  /* Gain: '<S13>/Gain' incorporates:
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product3'
   *  Sqrt: '<S13>/Sqrt'
   *  Sum: '<S13>/Add'
   */
  profileStart_FOC(19U); /* original_line:934 */rtb_Gain2_d = sqrtf((PMC_IsqDes * PMC_IsqDes) + (PMC_IsdDes * PMC_IsdDes)) *
    0.707106769F;profileEnd_FOC(19U); /* original_line:935 */

  /* Product: '<S13>/Product1' incorporates:
   *  Constant: '<S13>/Constant16'
   *  Constant: '<S13>/Constant2'
   */
  rtb_Divide_m = g_msgCore0to2_AcrSwtLoRpm * g_msgCore0to2_maxCur;

  /* Product: '<S13>/Product2' incorporates:
   *  Constant: '<S13>/Constant17'
   *  Constant: '<S13>/Constant2'
   */
  rtb_Sqrt_l = g_msgCore0to2_AcrSwtHiRpm * g_msgCore0to2_maxCur;

  /* MATLAB Function: '<S13>/AsrPI1' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant10'
   *  Constant: '<S13>/Constant13'
   *  Constant: '<S13>/Constant7'
   */
  /*  */
  /* MATLAB Function 'bldc/Subsystem1/AsrPI1': '<S40>:1' */
  /* '<S40>:1:3' if KiHi == single(0) */
  if (g_msgCore0to2_AcrKiStb == 0.0F) {
    /* '<S40>:1:4' asrKiHi = single(0); */
    rtb_Add1_l = 0.0F;
  } else {
    /* '<S40>:1:5' else */
    /* '<S40>:1:6' asrKiHi = KiHi; */
    rtb_Add1_l = g_msgCore0to2_AcrKiStb;
  }

  /* '<S40>:1:9' if KiLo == single(0) */
  if (g_msgCore0to2_AcrKi == 0.0F) {
    /* '<S40>:1:10' asrKiLo = single(0); */
    rtb_Gain3_f = 0.0F;
  } else {
    /* '<S40>:1:11' else */
    /* '<S40>:1:12' asrKiLo = KiLo; */
    rtb_Gain3_f = g_msgCore0to2_AcrKi;
  }

  /* '<S40>:1:15' if rpm_Hi >= rpm_Lo */
  if (rtb_Sqrt_l >= rtb_Divide_m) {
    /* '<S40>:1:16' asr_rpm_Hi = rpm_Hi; */
    rtb_Subtract_a = rtb_Sqrt_l;

    /* '<S40>:1:17' asr_rpm_Lo = rpm_Lo; */
    rtb_Sqrt_l = rtb_Divide_m;
  } else {
    /* '<S40>:1:18' else */
    /* '<S40>:1:19' asr_rpm_Hi = rpm_Lo; */
    rtb_Subtract_a = rtb_Divide_m;

    /* '<S40>:1:20' asr_rpm_Lo = rpm_Hi; */
  }

  /* '<S40>:1:23' if fdb >= asr_rpm_Hi */
  if (rtb_Gain2_d >= rtb_Subtract_a) {
    /* '<S40>:1:24' Kp = KpHi; */
    rtb_Divide_m = g_msgCore0to2_AcrKpStb;

    /* '<S40>:1:25' Ki = asrKiHi; */
    rtb_Gain3_f = rtb_Add1_l;
  } else if (rtb_Gain2_d <= rtb_Sqrt_l) {
    /* '<S40>:1:26' elseif fdb <= asr_rpm_Lo */
    /* '<S40>:1:27' Kp = KpLo; */
    rtb_Divide_m = g_msgCore0to2_AcrKp;

    /* '<S40>:1:28' Ki = asrKiLo; */
  } else {
    /* '<S40>:1:29' else */
    /* '<S40>:1:30' Kp = (KpHi - KpLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + KpLo; */
    rtb_Gain2_d -= rtb_Sqrt_l;
    rtb_Sqrt_l = rtb_Subtract_a - rtb_Sqrt_l;
    rtb_Divide_m = (((g_msgCore0to2_AcrKpStb - g_msgCore0to2_AcrKp) *
                     rtb_Gain2_d) / rtb_Sqrt_l) + g_msgCore0to2_AcrKp;

    /* '<S40>:1:31' Ki = (asrKiHi - asrKiLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + asrKiLo; */
    rtb_Gain3_f += ((rtb_Add1_l - rtb_Gain3_f) * rtb_Gain2_d) / rtb_Sqrt_l;
  }

  /* End of MATLAB Function: '<S13>/AsrPI1' */

  /* Saturate: '<S13>/Saturation1' */
  if (PMC_pwmfrq > g_msgCore0to2_pwmFrqSet) {
    act_Ki = g_msgCore0to2_pwmFrqSet;
  } else if (PMC_pwmfrq < 2000.0F) {
    act_Ki = 2000.0F;
  } else {
    act_Ki = PMC_pwmfrq;
  }

  /* Product: '<S13>/Divide' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Saturate: '<S13>/Saturation1'
   */
  FOC_CurKp = (act_Ki * rtb_Divide_m) / g_msgCore0to2_pwmFrqSet;

  /* Sum: '<S41>/Sum1' incorporates:
   *  Constant: '<S18>/Constant'
   *  Product: '<S18>/Product4'
   *  Product: '<S18>/Product5'
   *  Product: '<S41>/Product1'
   *  Product: '<S41>/Product3'
   *  Saturate: '<S18>/Saturation'
   *  Sqrt: '<S18>/Sqrt'
   *  Sum: '<S18>/Sum1'
   *  UnitDelay: '<S41>/Unit Delay1'
   */
  profileStart_FOC(20U); /* original_line:1045 */rtb_Gain2_d = (sqrtf(fmaxf((PMC_isqFlt * PMC_isqFlt) + (PMC_isdFlt *
    PMC_isdFlt), 0.0F)) * 0.05F) + (pmsmfoc_rtDWork.UnitDelay1_DSTATE_e * 0.95F);profileEnd_FOC(20U); /* original_line:1046 */

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant12'
   *  Product: '<S13>/Product4'
   *  Saturate: '<S13>/Saturation'
   */
  if (g_msgCore0to2_linearKpEn) {
    rtb_Sqrt_l = FOC_CurKp;
  } else {
    /* Product: '<S13>/Divide2' incorporates:
     *  Constant: '<S13>/Constant11'
     *  Gain: '<S13>/Gain6'
     *  Gain: '<S13>/Gain7'
     *  Gain: '<S13>/Gain8'
     *  Sum: '<S13>/Minus1'
     */
    rtb_Add1_l = ((0.6F * g_msgCore0to2_maxCur) - (0.35360679F * rtb_Gain2_d)) /
      (0.4F * g_msgCore0to2_maxCur);

    /* Saturate: '<S13>/Saturation' */
    if (rtb_Add1_l > 1.0F) {
      rtb_Add1_l = 1.0F;
    } else if (rtb_Add1_l < 0.5F) {
      rtb_Add1_l = 0.5F;
    }

    rtb_Sqrt_l = FOC_CurKp * rtb_Add1_l;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   *  Inport: '<Root>/Drive'
   *  UnitDelay: '<S1>/Unit Delay3'
   *  UnitDelay: '<S1>/Unit Delay4'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  d_integral = pmsmfoc_rtDWork.UnitDelay3_DSTATE;
  q_integral = pmsmfoc_rtDWork.UnitDelay4_DSTATE;
  rtb_Add1_l = d_integral;
  rtb_Subtract_a = q_integral;

  /* persistent temp_d_integral; */
  /* MATLAB Function 'bldc/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:7' if isempty(reset) */
  if (!pmsmfoc_rtDWork.reset_not_empty) {
    /* '<S6>:1:8' reset = boolean(1); */
    pmsmfoc_rtDWork.reset_not_empty = true;

    /* modulation_state = single(0); */
    /* '<S6>:1:10' q_integral = single(0); */
    rtb_Subtract_a = 0.0F;

    /* '<S6>:1:11' d_integral = single(0); */
    rtb_Add1_l = 0.0F;

    /* modulation_state_new = single(0); */
  }

  /* '<S6>:1:16' if(Drive==1) */
  if (pmsmfoc_rtU.Drive) {
    real32_T anti_sat_term;
    real32_T id_error;
    real32_T iq_error;
    real32_T pi_q_AxleOutput;
    real32_T pi_q_AxleOutput_tmp;

    /* '<S6>:1:17' act_Kp= single((sqrt(3)* acr_kp)/Vdc); */
    rtb_Divide3 = (1.73205078F * rtb_Sqrt_l) / rtb_Sum1;

    /* '<S6>:1:18' act_Ki= single((sqrt(3)* acr_ki*sample_time)/Vdc); */
    act_Ki = ((1.73205078F * rtb_Gain3_f) * rtb_Sin) / rtb_Sum1;

    /* '<S6>:1:19' anti_sat_term = (act_Kp * kc * omega) *sample_time; */
    anti_sat_term = ((rtb_Divide3 * f32_P_Coef) * rtb_Sqrt) * rtb_Sin;

    /* '<S6>:1:21' id_error = single(idref - idact); */
    id_error = PMC_IsdDes - PMC_isdFlt;

    /* '<S6>:1:22' iq_error = single(iqref - iqact); */
    iq_error = PMC_IsqDes - PMC_isqFlt;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%d_axle%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* '<S6>:1:26' d_decouple = (-(omega *Lq*iqref*decouple_gain)*sqrt(3))/Vdc; */
    rtb_Divide_m = ((-(((rtb_Sqrt * PMC_Lq) * PMC_IsqDes) *
                       g_msgCore0to2_DecoupleEn)) * 1.73205078F) / rtb_Sum1;

    /* '<S6>:1:30' UdPoslimt = f32_P_Modulation -d_decouple; */
    UdPoslimt = f32_P_Modulation - rtb_Divide_m;

    /* 上限 */
    /* '<S6>:1:31' UdNeglimt = -f32_P_Modulation -d_decouple; */
    UdNeglimt = (-f32_P_Modulation) - rtb_Divide_m;

    /* 下限 */
    /* '<S6>:1:33' integral_delta = act_Ki * id_error; */
    /* 求当前拍积分 */
    /* '<S6>:1:34' d_integral = d_integral + integral_delta; */
    temp2 = act_Ki * id_error;
    rtb_Add1_l += temp2;

    /* 累加 */
    /* '<S6>:1:35' pi_d_AxleOutput=act_Kp*id_error +d_integral; */
    pi_d_AxleOutput = (rtb_Divide3 * id_error) + rtb_Add1_l;

    /* 求d轴PI总输出 */
    /* '<S6>:1:37' if(pi_d_AxleOutput >UdPoslimt) */
    if (pi_d_AxleOutput > UdPoslimt) {
      /* 总输出超过上限 */
      /* '<S6>:1:38' pi_d_AxleOutput = UdPoslimt; */
      pi_d_AxleOutput = UdPoslimt;

      /* 限幅 */
      /* '<S6>:1:39' if(id_error<0) */
      if (id_error < 0.0F) {
        /* 上限饱和 */
        /* '<S6>:1:40' temp_idAnti_windup = (-(anti_sat_term * iq_error)) + (id_error * act_Ki); */
        UdPoslimt = (-(anti_sat_term * iq_error)) + temp2;

        /* 饱和计算 */
        /* '<S6>:1:41' if(temp_idAnti_windup >0) */
        if (UdPoslimt > 0.0F) {
          /* 针对上限饱和的 Anti_windup项必须为正，否则发散 */
          /* '<S6>:1:42' temp_idAnti_windup = single(0); */
          UdPoslimt = 0.0F;
        }

        /* '<S6>:1:44' d_integral= d_integral +temp_idAnti_windup ; */
        rtb_Add1_l += UdPoslimt;
      }

      /* '<S6>:1:46' temp_idAnti_windup = single(0); */
      ToSee_idAnti_windup = 0.0F;
    } else if (pi_d_AxleOutput < UdNeglimt) {
      /* '<S6>:1:48' elseif(pi_d_AxleOutput < UdNeglimt) */
      /* '<S6>:1:49' pi_d_AxleOutput = UdNeglimt; */
      pi_d_AxleOutput = UdNeglimt;

      /* '<S6>:1:51' if(id_error >0 ) */
      if (id_error > 0.0F) {
        /* '<S6>:1:52' temp_idAnti_windup = (-(anti_sat_term * iq_error)) + (id_error * act_Ki); */
        UdPoslimt = (-(anti_sat_term * iq_error)) + temp2;

        /* '<S6>:1:53' if(temp_idAnti_windup <0) */
        if (UdPoslimt < 0.0F) {
          /* '<S6>:1:54' temp_idAnti_windup = single(0); */
          UdPoslimt = 0.0F;
        }

        /* '<S6>:1:56' d_integral= d_integral +temp_idAnti_windup ; */
        rtb_Add1_l += UdPoslimt;
      }

      /* '<S6>:1:58' temp_idAnti_windup = single(0); */
      ToSee_idAnti_windup = 0.0F;
    } else {
      /* '<S6>:1:60' else */
      /* '<S6>:1:61' temp_idAnti_windup = single(0); */
      ToSee_idAnti_windup = 0.0F;
    }

    /* '<S6>:1:64' ToSee_idAnti_windup = temp_idAnti_windup; */
    /* '<S6>:1:67' usd_output = pi_d_AxleOutput+d_decouple; */
    pi_d_AxleOutput += rtb_Divide_m;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%限幅值%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* '<S6>:1:70' temp1 =  single(1.177225) - usd_output*usd_output; */
    /* '<S6>:1:71' temp1 = sqrt(temp1); */
    /* '<S6>:1:72' if(temp1 <0) */
    /* '<S6>:1:75' temp2 = single(0.1)*single(temp1)+single(0.9)*uqlimit_1; */
    profileStart_FOC(21U); /* original_line:1221 */temp2 = (sqrtf(1.17722499F - (pi_d_AxleOutput * pi_d_AxleOutput)) * 0.1F) +
      (0.9F * pmsmfoc_rtDWork.UnitDelay5_DSTATE);profileEnd_FOC(21U); /* original_line:1222 */

    /* '<S6>:1:77' if(temp2 >f32_P_Modulation) */
    if (temp2 > f32_P_Modulation) {
      /* '<S6>:1:78' temp2 = f32_P_Modulation; */
      temp2 = f32_P_Modulation;
    }

    /* '<S6>:1:80' uqlimit = temp2 ; */
    Uq_output_limit = temp2;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%q_axle%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* '<S6>:1:83' q_decouple = ((omega *Ld*idref*decouple_gain)*sqrt(3)); */
    /* '<S6>:1:84' q_ffw= omega *psi *ffw_gain*sqrt(2); */
    /* '<S6>:1:86' q_decouple_Add_ffw= (q_decouple+q_ffw)/Vdc; */
    UdPoslimt = (((((rtb_Sqrt * PMC_Ld) * PMC_IsdDes) * g_msgCore0to2_DecoupleEn)
                  * 1.73205078F) + (((rtb_Sqrt * PMC_PsiExc) * FFW_enable) *
      1.41421354F)) / rtb_Sum1;

    /* '<S6>:1:88' UqPoslimt = uqlimit - q_decouple_Add_ffw; */
    UdNeglimt = temp2 - UdPoslimt;

    /* '<S6>:1:89' UqNeglimt = -uqlimit - q_decouple_Add_ffw ; */
    temp2 = (-temp2) - UdPoslimt;

    /* integral_delta_q = act_Ki * iq_error; */
    /* q_integral = q_integral + integral_delta_q; */
    /* '<S6>:1:95' pi_q_AxleOutput=act_Kp*iq_error +q_integral; */
    pi_q_AxleOutput_tmp = rtb_Divide3 * iq_error;
    pi_q_AxleOutput = pi_q_AxleOutput_tmp + rtb_Subtract_a;

    /* 求q轴PI总输出 */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%q_axle积分器限幅值%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* '<S6>:1:99' if(pi_q_AxleOutput >UqPoslimt) */
    if (pi_q_AxleOutput > UdNeglimt) {
      /* 总输出超过上限 */
      /* '<S6>:1:100' integral_delta_q = single(0); */
      pi_q_AxleOutput = 0.0F;

      /* 限幅 */
      /* '<S6>:1:101' if(iq_error<0) */
      if (iq_error < 0.0F) {
        /* 上限饱和 */
        /* '<S6>:1:102' temp_iqAnti_windup = (-(anti_sat_term * id_error)) + (iq_error * act_Ki); */
        anti_sat_term = (-(anti_sat_term * id_error)) + (iq_error * act_Ki);

        /* 饱和计算 */
        /* '<S6>:1:103' if(temp_iqAnti_windup >0) */
        if (anti_sat_term > 0.0F) {
          /* 针对上限饱和的 Anti_windup项必须为正，否则发散 */
          /* '<S6>:1:104' temp_iqAnti_windup = single(0); */
          anti_sat_term = 0.0F;
        }
      } else {
        /* '<S6>:1:106' else */
        /* '<S6>:1:107' temp_iqAnti_windup= single(0); */
        anti_sat_term = 0.0F;
      }
    } else if (pi_q_AxleOutput < temp2) {
      /* '<S6>:1:110' elseif(pi_q_AxleOutput < UqNeglimt) */
      /* '<S6>:1:111' integral_delta_q = single(0); */
      pi_q_AxleOutput = 0.0F;

      /* '<S6>:1:113' if(iq_error >0 ) */
      if (iq_error > 0.0F) {
        /* '<S6>:1:114' temp_iqAnti_windup = (-(anti_sat_term * id_error)) + (iq_error * act_Ki); */
        anti_sat_term = (-(anti_sat_term * id_error)) + (iq_error * act_Ki);

        /* '<S6>:1:115' if(temp_iqAnti_windup <0) */
        if (anti_sat_term < 0.0F) {
          /* '<S6>:1:116' temp_iqAnti_windup = single(0); */
          anti_sat_term = 0.0F;
        }
      } else {
        /* '<S6>:1:118' else */
        /* '<S6>:1:119' temp_iqAnti_windup= single(0); */
        anti_sat_term = 0.0F;
      }
    } else {
      /* '<S6>:1:123' else */
      /* '<S6>:1:124' temp_iqAnti_windup = single(0); */
      anti_sat_term = 0.0F;

      /* '<S6>:1:125' integral_delta_q = act_Ki * iq_error; */
      pi_q_AxleOutput = act_Ki * iq_error;
    }

    /* '<S6>:1:128' q_integral = q_integral +integral_delta_q+temp_iqAnti_windup; */
    rtb_Subtract_a = (rtb_Subtract_a + pi_q_AxleOutput) + anti_sat_term;

    /* '<S6>:1:129' ToSee_iqAnti_windup = temp_iqAnti_windup; */
    ToSee_iqAnti_windup = anti_sat_term;

    /* '<S6>:1:131' if(q_integral >UqPoslimt) */
    if (rtb_Subtract_a > UdNeglimt) {
      /* 总输出超过上限 */
      /* '<S6>:1:132' q_integral = UqPoslimt; */
      rtb_Subtract_a = UdNeglimt;
    } else if (rtb_Subtract_a < temp2) {
      /* '<S6>:1:133' elseif(q_integral <UqNeglimt) */
      /* '<S6>:1:134' q_integral = UqNeglimt; */
      rtb_Subtract_a = temp2;
    } else {
      /* '<S6>:1:135' else */
    }

    /* '<S6>:1:139' if(act_Kp*iq_error+q_integral>UqPoslimt) */
    act_Ki = pi_q_AxleOutput_tmp + rtb_Subtract_a;
    if (act_Ki > UdNeglimt) {
      /* '<S6>:1:140' Q_Axle_final = UqPoslimt; */
      rtb_Divide3 = UdNeglimt;
    } else if (act_Ki < temp2) {
      /* '<S6>:1:141' elseif(act_Kp*iq_error+q_integral<UqNeglimt) */
      /* '<S6>:1:142' Q_Axle_final = UqNeglimt; */
      rtb_Divide3 = temp2;
    } else {
      /* '<S6>:1:143' else */
      /* '<S6>:1:144' Q_Axle_final =act_Kp*iq_error+q_integral; */
      rtb_Divide3 = (rtb_Divide3 * iq_error) + rtb_Subtract_a;
    }

    /* '<S6>:1:147' usq_output = Q_Axle_final +q_decouple_Add_ffw; */
    usq_output = rtb_Divide3 + UdPoslimt;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else {
    /* '<S6>:1:149' else */
    /* '<S6>:1:150' q_integral = single(0); */
    rtb_Subtract_a = 0.0F;

    /* '<S6>:1:151' d_integral = single(0); */
    rtb_Add1_l = 0.0F;

    /* '<S6>:1:152' usd_output = single(0); */
    pi_d_AxleOutput = 0.0F;

    /* '<S6>:1:153' usq_output = single(0); */
    usq_output = 0.0F;

    /* '<S6>:1:154' q_decouple_Add_ffw = single(0); */
    UdPoslimt = 0.0F;

    /* '<S6>:1:155' d_decouple = single(0); */
    rtb_Divide_m = 0.0F;

    /* '<S6>:1:156' uqlimit = single(0); */
    Uq_output_limit = 0.0F;

    /* '<S6>:1:157' UqPoslimt = single(0); */
    UdNeglimt = 0.0F;

    /* '<S6>:1:158' UqNeglimt = single(0); */
    temp2 = 0.0F;

    /* '<S6>:1:159' ToSee_idAnti_windup =single(0); */
    ToSee_idAnti_windup = 0.0F;

    /* '<S6>:1:160' ToSee_iqAnti_windup =single(0); */
    ToSee_iqAnti_windup = 0.0F;
  }

  q_volt_upper = UdNeglimt;
  q_volt_lower = temp2;
  usd_output = pi_d_AxleOutput;
  d_integral = rtb_Add1_l;
  q_integral = rtb_Subtract_a;
  q_decouple_Add_ffw = UdPoslimt;
  d_decouple = rtb_Divide_m;

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* ModelReference: '<S1>/Model1' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/Constant16'
   *  Constant: '<S1>/Constant6'
   *  Inport: '<Root>/Drive'
   *  Outport: '<Root>/KpCoef'
   */
  profileStart_FOC(22U); /* original_line:1401 */currentloop(&pmsmfoc_rtU.Drive, &PMC_IsdDes, &PMC_isdFlt, &PMC_IsqDes,
              &PMC_isqFlt, &rtb_Sin, &rtb_Sum1, &rtb_Sqrt, &PMC_Ld, &PMC_Lq,
              &rtb_Sqrt_l, &rtb_Gain3_f, (const real32_T *)&f32_P_Coef, (const
    real32_T *)&f32_P_Modulation, &PMC_PsiExc, (const real32_T *)
              &g_msgCore0to2_DecoupleEn, (const real32_T *)&FFW_enable,
              &PMC_UsdScal, &PMC_UsqScal, &pmsmfoc_rtDWork.Model1_o3,
              &pmsmfoc_rtY.KpCoef, &pmsmfoc_rtDWork.Model1_o5,
              &(pmsmfoc_rtDWork.Model1_InstanceData.rtdw));profileEnd_FOC(22U); /* original_line:1408 */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/UdHCIF'
   *  Inport: '<Root>/UqHCIF'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   *  Switch: '<S1>/Switch1'
   */
  if (g_msgCore0to2_clpwitch) {
    rtb_Gain3_f = usd_output;
    rtb_Sqrt_l = usq_output;
  } else {
    rtb_Gain3_f = PMC_UsdScal + pmsmfoc_rtU.UdHCIF;
    rtb_Sqrt_l = PMC_UsqScal + pmsmfoc_rtU.UqHCIF;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Constant: '<S1>/Constant3' */
  rtb_Add3 = g_msgCore0to2_motorseq;

  /* ModelReference: '<S1>/Model2' incorporates:
   *  Inport: '<Root>/Drive'
   *  Outport: '<Root>/f32_Duty'
   */
  profileStart_FOC(23U); /* original_line:1435 */SVPWM(&pmsmfoc_rtU.Drive, &rtb_Gain3_f, &rtb_Sqrt_l, &rtb_angleElec, &rtb_Add3,
        &pmsmfoc_rtY.f32_Duty, &cmprU, &cmprV, &cmprW,
        &(pmsmfoc_rtDWork.Model2_InstanceData.rtdw));profileEnd_FOC(23U); /* original_line:1437 */

  /* Sum: '<S14>/Plus' incorporates:
   *  Constant: '<S14>/Constant'
   *  Gain: '<S1>/Gain'
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   *  Product: '<S1>/Product'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  PMC_UsdFlt = (((rtb_Sum1 * PMC_UsdScal) * 0.408248305F) * 0.1F) +
    (pmsmfoc_rtDWork.UnitDelay_DSTATE * 0.9F);

  /* Sum: '<S15>/Plus' incorporates:
   *  Constant: '<S15>/Constant'
   *  Gain: '<S1>/Gain3'
   *  Product: '<S15>/Product'
   *  Product: '<S15>/Product1'
   *  Product: '<S1>/Product1'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  PMC_UsqFlt = (((PMC_UsqScal * rtb_Sum1) * 0.408248305F) * 0.1F) +
    (pmsmfoc_rtDWork.UnitDelay_DSTATE_k * 0.9F);

  /* Outport: '<Root>/isdSet_last' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  pmsmfoc_rtY.isdSet_last = pmsmfoc_rtDWork.UnitDelay_DSTATE_b;

  /* Outport: '<Root>/Ts' */
  pmsmfoc_rtY.Ts = rtb_Sin;

  /* RateTransition: '<S8>/Rate Transition12' */
  if (pmsmfoc_rtM->Timing.RateInteraction.TID0_1 == 1) {
    pmsmfoc_rtDWork.RateTransition12_Buffer = PMC_LqSubLd;

    /* RateTransition: '<S8>/Rate Transition6' */
    pmsmfoc_rtDWork.RateTransition6_Buffer = PMC_PsiExc;

    /* RateTransition: '<S8>/Rate Transition7' */
    pmsmfoc_rtDWork.RateTransition7_Buffer = ISP_iDaFild;

    /* RateTransition: '<S8>/Rate Transition8' */
    pmsmfoc_rtDWork.RateTransition8_Buffer = ISP_iQaFild;
  }

  /* End of RateTransition: '<S8>/Rate Transition12' */

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  pmsmfoc_rtDWork.UnitDelay5_DSTATE = Uq_output_limit;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  pmsmfoc_rtDWork.UnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S37>/Unit Delay1' */
  pmsmfoc_rtDWork.UnitDelay1_DSTATE_k = ISP_iDaFild;

  /* Update for UnitDelay: '<S38>/Unit Delay1' */
  pmsmfoc_rtDWork.UnitDelay1_DSTATE_a = ISP_iQaFild;

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Switch: '<S1>/Switch3'
   */
  if (g_msgCore0to2_clpwitch) {
    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    pmsmfoc_rtDWork.UnitDelay2_DSTATE = usd_output;

    /* Update for UnitDelay: '<S1>/Unit Delay1' */
    pmsmfoc_rtDWork.UnitDelay1_DSTATE_kc = usq_output;
  } else {
    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    pmsmfoc_rtDWork.UnitDelay2_DSTATE = PMC_UsdScal;

    /* Update for UnitDelay: '<S1>/Unit Delay1' */
    pmsmfoc_rtDWork.UnitDelay1_DSTATE_kc = PMC_UsqScal;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Update for UnitDelay: '<S19>/Unit Delay1' */
  pmsmfoc_rtDWork.UnitDelay1_DSTATE_j = usage;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  pmsmfoc_rtDWork.UnitDelay1_DSTATE_c = rtb_Sqrt;

  /* Update for UnitDelay: '<S41>/Unit Delay1' */
  pmsmfoc_rtDWork.UnitDelay1_DSTATE_e = rtb_Gain2_d;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  pmsmfoc_rtDWork.UnitDelay3_DSTATE = d_integral;

  /* Update for UnitDelay: '<S1>/Unit Delay4' */
  pmsmfoc_rtDWork.UnitDelay4_DSTATE = q_integral;

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  pmsmfoc_rtDWork.UnitDelay_DSTATE = PMC_UsdFlt;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  pmsmfoc_rtDWork.UnitDelay_DSTATE_k = PMC_UsqFlt;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  pmsmfoc_rtDWork.UnitDelay_DSTATE_b = pmsmfoc_rtDWork.Model1_o3;
}

/* Model step function for TID1 */
void FOC_step1(void)                   /* Sample time: [0.001s, 0.0s] */
{
  real32_T rtb_Gain1_me;

  /* Gain: '<S36>/Gain1' incorporates:
   *  Product: '<S36>/Product'
   *  Product: '<S36>/Product1'
   *  Product: '<S36>/Product2'
   *  RateTransition: '<S8>/Rate Transition12'
   *  RateTransition: '<S8>/Rate Transition6'
   *  RateTransition: '<S8>/Rate Transition7'
   *  RateTransition: '<S8>/Rate Transition8'
   *  Sum: '<S36>/Sum'
   */
  rtb_Gain1_me = ((pmsmfoc_rtDWork.RateTransition6_Buffer *
                   pmsmfoc_rtDWork.RateTransition8_Buffer) -
                  ((pmsmfoc_rtDWork.RateTransition7_Buffer *
                    pmsmfoc_rtDWork.RateTransition12_Buffer) *
                   pmsmfoc_rtDWork.RateTransition8_Buffer)) * (3.0F *
    u16_P_MotorPair);

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S39>/LowerRelop1'
   *  RelationalOperator: '<S39>/UpperRelop'
   *  Switch: '<S39>/Switch'
   */
  if (rtb_Gain1_me > 500.0F) {
    /* Switch: '<S39>/Switch2' */
    PMC_TrqOutEst = 500.0F;
  } else if (rtb_Gain1_me < -500.0F) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Switch: '<S39>/Switch2'
     */
    PMC_TrqOutEst = -500.0F;
  } else {
    /* Switch: '<S39>/Switch2' incorporates:
     *  Switch: '<S39>/Switch'
     */
    PMC_TrqOutEst = rtb_Gain1_me;
  }

  /* End of Switch: '<S39>/Switch2' */
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (pmsmfoc_rtM)->Timing.TaskCounters.cLimit[0] = 1;
  (pmsmfoc_rtM)->Timing.TaskCounters.cLimit[1] = 10;

  /* Model Initialize function for ModelReference Block: '<S1>/Model1' */
  nxhg2dhc0l_prot(rtmGetErrorStatusPointer(pmsmfoc_rtM),
                  &(pmsmfoc_rtDWork.Model1_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/Model2' */
  bcegzfkptw_prot(rtmGetErrorStatusPointer(pmsmfoc_rtM),
                  &(pmsmfoc_rtDWork.Model2_InstanceData.rtm));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  pmsmfoc_rtDWork.SwitchCase_ActiveSubsystem = -1;

  /* SystemInitialize for ModelReference: '<S1>/Model1' */
  profileStart_FOC(24U); /* original_line:1609 */idkqe0cpzy_prot(&(pmsmfoc_rtDWork.Model1_InstanceData.rtdw));profileEnd_FOC(24U); /* original_line:1609 */
}

/* Model terminate function */
void FOC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
