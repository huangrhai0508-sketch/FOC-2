/*
 * File: FOC.c
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

#include "FOC.h"
#include "rtwtypes.h"
#include "ECM.h"
#include <math.h>
#include "lookuptabletype.h"
#include "FOC_private.h"
#include "look2_iflf_pbinlca.h"
#include "look1_iflf_pbinlca.h"
#include "parameter.h"
#include "lookuptable.h"
#include "currentloop.h"
#include "SVPWM.h"

int_T FOCpmsmfoc_rtGlobalTID[2];
const rtTimingBridge *FOCpmsmfoc_rtTimingBridge;

/* Exported data definition */
#define FOC_P1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h" 

/* Definition for custom storage class: ExportToFile */
real32_T FOC_CurKp;                    /* '<S12>/Divide' */

/* curkp */
real32_T ISP_iDaFild;                  /* '<S37>/Sum1' */

/* d-axis filtered current,A */
real32_T ISP_iQaFild;                  /* '<S38>/Sum1' */

/* q-axis filtered current,A */
real32_T PMC_IsMax;                    /* '<S19>/Product' */

/* Caculated maximum phase current at current frequency */
real32_T PMC_Ld;                       /* '<S35>/Product4' */

/* d-axis inductance */
real32_T PMC_Lq;                       /* '<S35>/Product5' */

/* q-axis inductance */
real32_T PMC_LqSubLd;                  /* '<S35>/Add1' */

/* q-axis sub d-axis inductance */
real32_T PMC_PsiExc;                   /* '<S35>/Product1' */

/* flux */
real32_T PMC_PsiMax;                   /* '<S27>/Saturation' */

/* Calculated maximum flux for flux weakening control */
real32_T cmprU;                        /* '<S1>/Model2' */

/* cmprU */
real32_T cmprV;                        /* '<S1>/Model2' */

/* cmprV */
real32_T cmprW;                        /* '<S1>/Model2' */

/* cmprW */
FOCpmsmfoc_rtMdlrefDWork_n FOCpmsmfoc_rtMdlrefDWork;

/* Block states (default storage) */
FOCpmsmfoc_rtDW_a FOCpmsmfoc_rtDWork;

/* System initialize for referenced model: 'FOC' */

#define FOC_P1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h" 
void FOC_Init(real32_T *y_f32_Duty_f32_DutyUon, real32_T *y_f32_Duty_f32_DutyVon,
              real32_T *y_f32_Duty_f32_DutyWon)
{
  /* Start for SwitchCase: '<S1>/Switch Case' */
  FOCpmsmfoc_rtDWork.SwitchCase_ActiveSubsystem = -1;

  /* SystemInitialize for SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyUon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyUon;

  /* SystemInitialize for SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyVon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyVon;

  /* SystemInitialize for SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyWon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyWon;

  /* SystemInitialize for ModelReference: '<S1>/Model1' */
  idkqe0cpzy_prot(&(FOCpmsmfoc_rtDWork.Model1_InstanceData.rtdw));
}

/* System reset for referenced model: 'FOC' */
void FOC_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S37>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_k = 0.0F;

  /* InitializeConditions for UnitDelay: '<S38>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_a = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
  FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_j = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_c = 0.0F;

  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_e = 0.0F;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_k = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_b = 0.0F;

  /* SystemReset for Atomic SubSystem: '<S1>/AngleComp' */
  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_i = 0U;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_oc = 0U;

  /* End of SystemReset for SubSystem: '<S1>/AngleComp' */
}

/* Disable for referenced model: 'FOC' */
void FOC_Disable(real32_T *y_f32_Duty_f32_DutyUon, real32_T
                 *y_f32_Duty_f32_DutyVon, real32_T *y_f32_Duty_f32_DutyWon)
{
  /* Disable for Enabled SubSystem: '<S1>/Subsystem' */
  if (FOCpmsmfoc_rtDWork.Subsystem_MODE) {
    /* Disable for Switch: '<S11>/Switch' incorporates:
     *  Outport: '<S11>/Out1'
     */
    FOCpmsmfoc_rtDWork.Switch = Init;
    FOCpmsmfoc_rtDWork.Subsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/Subsystem' */

  /* Disable for SwitchCase: '<S1>/Switch Case' */
  FOCpmsmfoc_rtDWork.SwitchCase_ActiveSubsystem = -1;

  /* Disable for ModelReference: '<S1>/Model1' */
  hfht11bpny_prot(&FOCpmsmfoc_rtDWork.Model1_o1, &FOCpmsmfoc_rtDWork.Model1_o2,
                  &FOCpmsmfoc_rtDWork.Model1_o3,
                  &(FOCpmsmfoc_rtDWork.Model1_InstanceData.rtdw));

  /* Disable for ModelReference: '<S1>/Model2' */
  kxj4bmtjtf_prot(&FOCpmsmfoc_rtDWork.Model2_o1,
                  &(FOCpmsmfoc_rtDWork.Model2_InstanceData.rtdw));

  /* Disable for SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyUon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyUon;

  /* Disable for SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyVon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyVon;

  /* Disable for SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyWon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyWon;
}

/* Output and update for referenced model: 'FOC' */
void FOCTID0(const real32_T *u_f32_CurrentU_A, const real32_T *u_f32_CurrentV_A,
             const real32_T *u_f32_CurrentW_A, const real32_T
             *u_f32_SpeedAct_rpm, const real32_T *u_f32_Speedref_rpm, const
             real32_T *u_f32_Iddes_A, const real32_T *u_f32_Iqdes_A, const
             real32_T *u_Udc, const real32_T *u_f32_ModulationReq, const ECM
             *u_ControlMode, const uint16_T *u_Angle, const uint8_T *u_ROLState,
             const real32_T *u_iddes, const boolean_T *u_Drive, const real32_T
             *u_PWMFrqSet, const real32_T *u_TrqEmDes, real32_T
             *y_f32_Duty_f32_DutyUon, real32_T *y_f32_Duty_f32_DutyVon, real32_T
             *y_f32_Duty_f32_DutyWon, real32_T *y_Iqref, real32_T *y_Idref,
             real32_T *y_Udref, real32_T *y_Uqref, real32_T *y_Usage, real32_T
             *y_KpCoef, real32_T *y_isdSet_last, real32_T *y_Ts, real32_T *y_Id,
             real32_T *y_Iq)
{
  int_T tid = 0;
  real32_T rtb_Gain1_c;
  real32_T rtb_Gain2_b;
  real32_T rtb_Gain2_h;
  real32_T rtb_Gain3_f;
  real32_T rtb_Gain6_m;
  real32_T rtb_Product1;
  real32_T rtb_Sin;
  real32_T rtb_Subtract;
  real32_T rtb_Subtract_a;
  int16_T rtb_CastToSingle1;
  uint16_T rtb_Add3;
  uint16_T rtb_Add6;
  uint16_T rtb_Gain8_h;
  uint16_T rtb_angleElec;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (*u_Drive) {
    FOCpmsmfoc_rtDWork.Subsystem_MODE = true;

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Logic: '<S11>/AND'
     *  Logic: '<S11>/NOT'
     *  RelationalOperator: '<S11>/Equal'
     *  RelationalOperator: '<S11>/Equal1'
     */
    if (((*u_ControlMode) != alOfsCal) || ((*u_ROLState) == 1)) {
      /* Switch: '<S11>/Switch' */
      FOCpmsmfoc_rtDWork.Switch = *u_ControlMode;
    } else {
      /* Switch: '<S11>/Switch' incorporates:
       *  Constant: '<S11>/Constant3'
       */
      FOCpmsmfoc_rtDWork.Switch = IsCtrl;
    }

    /* End of Switch: '<S11>/Switch' */
  } else if (FOCpmsmfoc_rtDWork.Subsystem_MODE) {
    /* Disable for Switch: '<S11>/Switch' incorporates:
     *  Outport: '<S11>/Out1'
     */
    FOCpmsmfoc_rtDWork.Switch = Init;
    FOCpmsmfoc_rtDWork.Subsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  rtb_Product1 = (*u_Udc) * 0.001F;

  /* Sum: '<S8>/Sum1' incorporates:
   *  Product: '<S8>/Product3'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  rtb_Product1 += FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE * 0.999F;

  /* Switch: '<S43>/Switch1' */
  rtb_Sin = *u_f32_CurrentV_A;

  /* Switch: '<S43>/Switch' */
  rtb_Gain3_f = *u_f32_CurrentW_A;

  /* Sum: '<S42>/Subtract' incorporates:
   *  Gain: '<S42>/Gain'
   *  Gain: '<S42>/Gain1'
   */
  rtb_Subtract = ((*u_f32_CurrentU_A) - (0.5F * rtb_Sin)) - (0.5F * rtb_Gain3_f);

  /* Gain: '<S42>/Gain2' */
  rtb_Gain2_h = 0.666666687F * rtb_Subtract;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant2'
   */
  if (PWMFrqSwitch_C) {
    rtb_Subtract = *u_PWMFrqSet;
  } else {
    rtb_Subtract = g_msgCore0to2_pwmFrqSet;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1>/AngleComp' */
  /* Gain: '<S2>/Gain6' */
  rtb_Gain6_m = 65536.0F * (*u_f32_Speedref_rpm);

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S2>/Constant8'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Add2'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Add3 = (uint16_T)(((uint32_T)((uint16_T)((rtb_Gain6_m / rtb_Subtract) +
    0.5F))) + FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_i);

  /* Switch: '<S2>/Switch2' incorporates:
   *  Constant: '<S2>/Constant2'
   *  RelationalOperator: '<S2>/Equal'
   */
  if ((*u_ControlMode) != IFCtrl) {
    rtb_angleElec = *u_Angle;
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
    FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_oc));

  /* Sum: '<S2>/Add5' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Product: '<S2>/Product1'
   */
  rtb_angleElec += (int16_T)floorf(f32_P_AngleCompCur * ((real32_T)
    rtb_CastToSingle1));

  /* Sum: '<S2>/Add6' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Product: '<S2>/Product3'
   */
  rtb_Add6 = (uint16_T)(((uint32_T)((uint16_T)((int16_T)floorf(((real32_T)
    rtb_CastToSingle1) * f32_P_AngleCompVol)))) + rtb_angleElec);

  /* Gain: '<S2>/Gain2' */
  rtb_Gain2_b = 9.58740711E-5F * ((real32_T)rtb_angleElec);

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  Gain: '<S2>/Gain7'
   */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_i = rtb_Add3;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_oc = rtb_Gain8_h;

  /* End of Outputs for SubSystem: '<S1>/AngleComp' */

  /* Trigonometry: '<S42>/Cos' */
  rtb_Gain6_m = cosf(rtb_Gain2_b);

  /* Gain: '<S42>/Gain3' incorporates:
   *  Sum: '<S42>/Subtract1'
   */
  rtb_Gain3_f = (rtb_Sin - rtb_Gain3_f) * 0.577350259F;

  /* Trigonometry: '<S42>/Sin' */
  rtb_Sin = sinf(rtb_Gain2_b);

  /* Sum: '<S42>/Add' incorporates:
   *  Product: '<S42>/Product'
   *  Product: '<S42>/Product1'
   */
  *y_Id = (rtb_Gain2_h * rtb_Gain6_m) + (rtb_Gain3_f * rtb_Sin);

  /* Sum: '<S37>/Sum1' incorporates:
   *  Constant: '<S34>/tauPT1Isd'
   *  Gain: '<S7>/Gain'
   *  Product: '<S37>/Product1'
   *  Product: '<S37>/Product3'
   *  UnitDelay: '<S37>/Unit Delay1'
   */
  ISP_iDaFild = ((0.707106769F * (*y_Id)) * 0.1F) +
    (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_k * 0.9F);

  /* Sum: '<S42>/Subtract2' incorporates:
   *  Product: '<S42>/Product2'
   *  Product: '<S42>/Product3'
   */
  *y_Iq = (rtb_Gain3_f * rtb_Gain6_m) - (rtb_Gain2_h * rtb_Sin);

  /* Sum: '<S38>/Sum1' incorporates:
   *  Constant: '<S34>/tauPT1Isd'
   *  Gain: '<S7>/Gain1'
   *  Product: '<S38>/Product1'
   *  Product: '<S38>/Product3'
   *  UnitDelay: '<S38>/Unit Delay1'
   */
  ISP_iQaFild = ((0.707106769F * (*y_Iq)) * 0.1F) +
    (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_a * 0.9F);

  /* Outputs for Atomic SubSystem: '<S7>/MCT_PsmParCalc' */
  /* Abs: '<S35>/Abs' */
  rtb_Sin = fabsf(ISP_iDaFild);

  /* Lookup_n-D: '<S35>/cLdAdpt' incorporates:
   *  Sum: '<S38>/Sum1'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  rtb_Gain6_m = look2_iflf_pbinlca(ISP_iQaFild, rtb_Sin, (const real32_T *)
    &cLdAdpt_T.bp1[0], (const real32_T *)&cLdAdpt_T.bp2[0], (const real32_T *)
    &cLdAdpt_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex_h, rtCP_cLdAdpt_maxIndex,
    41U);

  /* Product: '<S35>/Product4' incorporates:
   *  Constant: '<S35>/LdBas'
   */
  PMC_Ld = SC_Ld_P * rtb_Gain6_m;

  /* Lookup_n-D: '<S35>/cLqAdpt' incorporates:
   *  Sum: '<S38>/Sum1'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  rtb_Sin = look2_iflf_pbinlca(ISP_iQaFild, rtb_Sin, (const real32_T *)
    &cLqNewAdpt_T.bp1[0], (const real32_T *)&cLqNewAdpt_T.bp2[0], (const
    real32_T *)&cLqNewAdpt_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex_i,
    rtCP_cLqAdpt_maxIndex, 41U);

  /* Product: '<S35>/Product5' incorporates:
   *  Constant: '<S35>/LqBas'
   */
  PMC_Lq = rtb_Sin * SC_Lq_P;

  /* Sum: '<S35>/Add1' */
  PMC_LqSubLd = PMC_Lq - PMC_Ld;

  /* Lookup_n-D: '<S35>/cPsiIsqAdptMot' incorporates:
   *  Sum: '<S38>/Sum1'
   */
  rtb_Sin = look1_iflf_pbinlca(ISP_iQaFild, (const real32_T *)
    &cPsiIsqAdptMot_T.bp1[0], (const real32_T *)&cPsiIsqAdptMot_T.tab[0],
    &FOCpmsmfoc_rtDWork.m_bpIndex_c, 40U);

  /* Product: '<S35>/Product1' incorporates:
   *  Constant: '<S7>/psiExc_25degC'
   */
  PMC_PsiExc = SC_Psi_P * rtb_Sin;

  /* End of Outputs for SubSystem: '<S7>/MCT_PsmParCalc' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Constant: '<S1>/Constant4'
   */
  rtb_Sin = fminf(f32_P_Modulation, *u_f32_ModulationReq);

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  *y_Ts = 1.0F / rtb_Subtract;

  /* Product: '<S4>/Product2' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_Gain6_m = (*y_Ts) * 500.0F;

  /* Sum: '<S17>/Sum1' incorporates:
   *  Constant: '<S17>/Constant'
   *  Product: '<S17>/Product1'
   *  Product: '<S17>/Product3'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Sqrt: '<S4>/Sqrt'
   *  Sum: '<S17>/Subtract'
   *  Sum: '<S4>/Add'
   *  UnitDelay: '<S17>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  *y_Usage = (sqrtf((FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE *
                     FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE) +
                    (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc *
                     FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc)) * rtb_Gain6_m) +
    ((1.0F - rtb_Gain6_m) * FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_j);

  /* SwitchCase: '<S1>/Switch Case' */
  rtPrevAction = FOCpmsmfoc_rtDWork.SwitchCase_ActiveSubsystem;
  switch (FOCpmsmfoc_rtDWork.Switch) {
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

   default:
    rtAction = 3;
    break;
  }

  FOCpmsmfoc_rtDWork.SwitchCase_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    {
      real32_T rtb_Divide_m;
      real32_T rtb_Yk1;
      boolean_T rtb_RelationalOperator;
      if (rtAction != rtPrevAction) {
        /* InitializeConditions for IfAction SubSystem: '<S1>/PMC_IsDesCalc' incorporates:
         *  ActionPort: '<S6>/Action Port'
         */
        /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
         *  UnitDelay: '<S18>/Unit Delay1'
         *  UnitDelay: '<S26>/Unit Delay1'
         *  UnitDelay: '<S6>/Unit Delay'
         */
        FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m = 0.0F;
        FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_o = 0.0F;
        FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l = 0.0F;

        /* End of InitializeConditions for SubSystem: '<S1>/PMC_IsDesCalc' */

        /* SystemReset for IfAction SubSystem: '<S1>/PMC_IsDesCalc' incorporates:
         *  ActionPort: '<S6>/Action Port'
         */
        /* SystemReset for Atomic SubSystem: '<S6>/PMC_IsqDesCalc' */
        /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
         *  UnitDelay: '<S30>/Delay Input2'
         *
         * Block description for '<S30>/Delay Input2':
         *
         *  Store in Global RAM
         */
        FOCpmsmfoc_rtDWork.DelayInput2_DSTATE = 0.0F;

        /* End of SystemReset for SubSystem: '<S6>/PMC_IsqDesCalc' */
        /* End of SystemReset for SubSystem: '<S1>/PMC_IsDesCalc' */
      }

      /* Outputs for IfAction SubSystem: '<S1>/PMC_IsDesCalc' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* Gain: '<S6>/Gain' */
      rtb_Gain3_f = (u16_P_MotorPair / 60.0F) * (*u_f32_SpeedAct_rpm);

      /* Outputs for Atomic SubSystem: '<S6>/PMC_IsdDesCalc' */
      /* Abs: '<S27>/Abs' */
      rtb_Gain2_h = fabsf(*u_TrqEmDes);

      /* End of Outputs for SubSystem: '<S6>/PMC_IsdDesCalc' */

      /* Outputs for Atomic SubSystem: '<S6>/PMC_PwmModCalcn' */
      /* Outputs for Atomic SubSystem: '<S6>/PMC_GenSigCalcn' */
      /* Product: '<S23>/Product' incorporates:
       *  Abs: '<S20>/Abs'
       *  Constant: '<S20>/unit'
       *  Constant: '<S20>/w10Hz'
       *  Gain: '<S6>/Gain2'
       *  Gain: '<S6>/Gain3'
       *  Gain: '<S6>/facMaxMI'
       *  MinMax: '<S20>/MinMax'
       *  Product: '<S20>/Divide'
       */
      rtb_Gain2_b = ((0.408248305F * rtb_Product1) * f32_P_Modulation) * (1.0F /
        fmaxf(62.831852F, fabsf(6.28318548F * rtb_Gain3_f)));

      /* End of Outputs for SubSystem: '<S6>/PMC_GenSigCalcn' */
      /* End of Outputs for SubSystem: '<S6>/PMC_PwmModCalcn' */

      /* Outputs for Atomic SubSystem: '<S6>/PMC_IsdDesCalc' */
      /* Saturate: '<S27>/Saturation' */
      if (rtb_Gain2_b > 0.18F) {
        /* Saturate: '<S27>/Saturation' */
        PMC_PsiMax = 0.18F;
      } else if (rtb_Gain2_b < 0.006F) {
        /* Saturate: '<S27>/Saturation' */
        PMC_PsiMax = 0.006F;
      } else {
        /* Saturate: '<S27>/Saturation' */
        PMC_PsiMax = rtb_Gain2_b;
      }

      /* End of Saturate: '<S27>/Saturation' */

      /* Lookup_n-D: '<S27>/ExFeedBack' incorporates:
       *  Abs: '<S27>/Abs'
       *  Saturate: '<S27>/Saturation'
       */
      look2_iflf_pbinlca(rtb_Gain2_h, PMC_PsiMax, (const real32_T *)
                         &ExFeedBack_T.bp1[0], (const real32_T *)
                         &ExFeedBack_T.bp2[0], (const real32_T *)
                         &ExFeedBack_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex_a,
                         rtCP_ExFeedBack_maxIndex, 8U);

      /* Gain: '<S27>/Gain1' incorporates:
       *  Abs: '<S27>/Abs1'
       *  Constant: '<S27>/Constant1'
       *  Constant: '<S27>/Constant2'
       *  Constant: '<S27>/Constant3'
       *  MinMax: '<S27>/Min1'
       *  Product: '<S27>/Divide'
       */
      rtb_Gain1_c = -fabsf(g_msgCore0to2_maxCur * fminf
                           (g_msgCore0to2_maxFwcCurRatio, 1.0F));

      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S27>/Constant'
       *  Constant: '<S27>/Constant5'
       */
      if (g_msgCore0to2_CalibEn) {
        rtb_Gain2_b = 0.0F;
      } else {
        /* Lookup_n-D: '<S27>/MTPA_T' incorporates:
         *  Abs: '<S27>/Abs'
         */
        rtb_Gain2_b = look2_iflf_pbinlca(rtb_Gain2_h, 0.0F, (const real32_T *)
          &MTPA_T.bp1[0], (const real32_T *)&MTPA_T.bp2[0], (const real32_T *)
          &MTPA_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex_j, rtCP_MTPA_T_maxIndex,
          21U);
      }

      /* End of Switch: '<S27>/Switch' */

      /* MinMax: '<S27>/MinMax' incorporates:
       *  MinMax: '<S27>/MinMax1'
       */
      rtb_Gain2_h = fmaxf(rtb_Gain1_c, fminf(0.0F, rtb_Gain2_b));

      /* End of Outputs for SubSystem: '<S6>/PMC_IsdDesCalc' */

      /* Sum: '<S18>/Add' incorporates:
       *  MinMax: '<S18>/Min2'
       */
      rtb_Gain2_b = fmaxf(rtb_Gain2_b, rtb_Gain1_c) - rtb_Gain2_h;

      /* Sum: '<S18>/Add1' */
      rtb_Gain1_c -= rtb_Gain2_h;

      /* Sum: '<S18>/Subtract' incorporates:
       *  MinMax: '<S1>/Min'
       */
      rtb_Subtract_a = rtb_Sin - (*y_Usage);

      /* Product: '<S25>/Divide' incorporates:
       *  Constant: '<S25>/Constant1'
       *  Constant: '<S25>/Constant4'
       */
      rtb_Divide_m = g_msgCore0to2_AfrKp * g_msgCore0to2_maxCur;

      /* Switch: '<S25>/Switch' incorporates:
       *  Constant: '<S25>/Constant'
       *  Constant: '<S25>/Constant2'
       */
      if (rtb_Subtract_a > 0.0F) {
        rtb_Gain6_m = 0.25F;
      } else {
        rtb_Gain6_m = 1.0F;
      }

      /* End of Switch: '<S25>/Switch' */

      /* Switch: '<S25>/Switch2' incorporates:
       *  Constant: '<S25>/Constant5'
       *  Constant: '<S25>/Constant6'
       *  Product: '<S25>/Divide1'
       */
      if (g_msgCore0to2_AfrTi != 0.0F) {
        rtb_Yk1 = (rtb_Divide_m * (*y_Ts)) / g_msgCore0to2_AfrTi;
      } else {
        rtb_Yk1 = 0.0F;
      }

      /* End of Switch: '<S25>/Switch2' */

      /* Product: '<S25>/Divide3' */
      rtb_Yk1 *= rtb_Gain6_m;

      /* MATLAB Function: '<S18>/MATLAB Function1' incorporates:
       *  Product: '<S25>/Divide2'
       *  UnitDelay: '<S18>/Unit Delay1'
       */
      rtb_Sin = FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;

      /* MATLAB Function 'bldc/PMC_IsDesCalc/FWC/MATLAB Function1': '<S24>:1' */
      /* '<S24>:1:2' temp = err*kp; */
      /* '<S24>:1:3' out = temp + intg; */
      rtb_Gain6_m = ((rtb_Divide_m * rtb_Gain6_m) * rtb_Subtract_a) +
        FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;

      /* '<S24>:1:4' if(out>MAX) */
      if (rtb_Gain6_m > rtb_Gain2_b) {
        /* '<S24>:1:5' out = MAX; */
        rtb_Gain6_m = rtb_Gain2_b;

        /* '<S24>:1:6' if(err<0) */
        if (rtb_Subtract_a < 0.0F) {
          /* '<S24>:1:7' intg = intg + ki*err; */
          rtb_Sin = (rtb_Yk1 * rtb_Subtract_a) +
            FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
        }
      } else if (rtb_Gain6_m < rtb_Gain1_c) {
        /* '<S24>:1:9' elseif(out < MIN) */
        /* '<S24>:1:10' out = MIN; */
        rtb_Gain6_m = rtb_Gain1_c;

        /* '<S24>:1:11' if(err>0) */
        if (rtb_Subtract_a > 0.0F) {
          /* '<S24>:1:12' intg = intg + ki*err; */
          rtb_Sin = (rtb_Yk1 * rtb_Subtract_a) +
            FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
        }
      } else {
        /* '<S24>:1:14' else */
        /* '<S24>:1:15' intg = intg + ki*err; */
        rtb_Sin = (rtb_Yk1 * rtb_Subtract_a) +
          FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
      }

      /* Sum: '<S18>/Add2' incorporates:
       *  MATLAB Function: '<S18>/MATLAB Function1'
       */
      /* '<S24>:1:17' max(intg,MIN); */
      /* '<S24>:1:18' min(intg,MAX); */
      rtb_Gain2_h += rtb_Gain6_m;

      /* Sum: '<S26>/Sum1' incorporates:
       *  Abs: '<S19>/Abs'
       *  Constant: '<S19>/tauPT1IsMax'
       *  Product: '<S26>/Product1'
       *  Product: '<S26>/Product3'
       *  UnitDelay: '<S26>/Unit Delay1'
       */
      rtb_Gain3_f = (fabsf(rtb_Gain3_f) * 0.1F) +
        (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_o * 0.9F);

      /* Lookup_n-D: '<S19>/Freq vs MaxI' incorporates:
       *  Sum: '<S26>/Sum1'
       */
      rtb_Yk1 = look1_iflf_pbinlca(rtb_Gain3_f, (const real32_T *)
        &facIphaMaxFreq_T.bp1[0], (const real32_T *)&facIphaMaxFreq_T.tab[0],
        &FOCpmsmfoc_rtDWork.m_bpIndex, 8U);

      /* Product: '<S19>/Product' incorporates:
       *  Constant: '<S19>/Ismax1'
       */
      PMC_IsMax = g_msgCore0to2_maxCur * rtb_Yk1;

      /* Merge: '<S1>/Merge1' incorporates:
       *  SignalConversion generated from: '<S6>/PMC_IdDes'
       */
      FOCpmsmfoc_rtDWork.Merge1 = rtb_Gain2_h;

      /* Signum: '<S6>/Sign' */
      rtb_Gain6_m = *u_TrqEmDes;

      /* Outputs for Atomic SubSystem: '<S6>/PMC_IsqDesCalc' */
      /* Outputs for Atomic SubSystem: '<S22>/IsqTrqDes_Calc' */
      /* Sum: '<S29>/Sum3' */
      rtb_Gain2_b = *u_TrqEmDes;

      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S29>/Constant10'
       *  Constant: '<S32>/3p'
       *  Gain: '<S32>/unitNeg'
       *  Product: '<S29>/Product'
       *  Product: '<S32>/Product1'
       *  Product: '<S32>/Product2'
       *  SignalConversion generated from: '<S29>/MCT_PsiExc'
       *  Sum: '<S32>/Sum1'
       *  UnitDelay: '<S6>/Unit Delay'
       */
      if (!g_msgCore0to2_CalibEn) {
        rtb_Gain2_b /= ((PMC_LqSubLd * (-FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l))
                        + PMC_PsiExc) * (u16_P_MotorPair * 3.0F);
      }

      /* End of Switch: '<S29>/Switch' */
      /* End of Outputs for SubSystem: '<S22>/IsqTrqDes_Calc' */

      /* Outputs for Atomic SubSystem: '<S22>/IsqDesLim_Calc' */
      /* Sum: '<S28>/Sum1' incorporates:
       *  Math: '<S28>/Math Function'
       *  Math: '<S28>/Math Function1'
       *  UnitDelay: '<S6>/Unit Delay'
       */
      rtb_Gain1_c = (PMC_IsMax * PMC_IsMax) -
        (FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l *
         FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l);

      /* RelationalOperator: '<S28>/Relational Operator' incorporates:
       *  Constant: '<S28>/IsResDes'
       *  Math: '<S28>/Math Function2'
       *  Sum: '<S28>/Sum2'
       */
      rtb_RelationalOperator = ((rtb_Gain1_c - (rtb_Gain2_b * rtb_Gain2_b)) <=
        0.0F);

      /* Outputs for Enabled SubSystem: '<S28>/SQRT' incorporates:
       *  EnablePort: '<S31>/Enable'
       */
      if (rtb_RelationalOperator) {
        /* Sqrt: '<S31>/Sqrt' incorporates:
         *  Abs: '<S31>/Abs'
         */
        FOCpmsmfoc_rtDWork.Sqrt = sqrtf(fabsf(rtb_Gain1_c));
      }

      /* End of Outputs for SubSystem: '<S28>/SQRT' */
      /* End of Outputs for SubSystem: '<S22>/IsqDesLim_Calc' */

      /* MultiPortSwitch: '<S22>/Index Vector' incorporates:
       *  Product: '<S28>/Product'
       *  Signum: '<S6>/Sign'
       */
      if (rtb_RelationalOperator != 0) {
        /* Signum: '<S6>/Sign' */
        if (rtb_Gain6_m < 0.0F) {
          rtb_Gain6_m = -1.0F;
        } else {
          rtb_Gain6_m = (real32_T)(rtb_Gain6_m > 0.0F);
        }

        /* Outputs for Atomic SubSystem: '<S22>/IsqDesLim_Calc' */
        rtb_Gain2_b = FOCpmsmfoc_rtDWork.Sqrt * rtb_Gain6_m;

        /* End of Outputs for SubSystem: '<S22>/IsqDesLim_Calc' */
      }

      /* End of MultiPortSwitch: '<S22>/Index Vector' */

      /* Sum: '<S30>/Difference Inputs1' incorporates:
       *  UnitDelay: '<S30>/Delay Input2'
       *
       * Block description for '<S30>/Difference Inputs1':
       *
       *  Add in CPU
       *
       * Block description for '<S30>/Delay Input2':
       *
       *  Store in Global RAM
       */
      rtb_Gain1_c = rtb_Gain2_b - FOCpmsmfoc_rtDWork.DelayInput2_DSTATE;

      /* Product: '<S30>/delta rise limit' incorporates:
       *  Constant: '<S22>/Constant'
       *  SampleTimeMath: '<S30>/sample time'
       *
       * About '<S30>/sample time':
       *  y = K where K = ( w * Ts )
       */
      rtb_Gain6_m = 0.25F;

      /* Switch: '<S33>/Switch2' incorporates:
       *  RelationalOperator: '<S33>/LowerRelop1'
       */
      if (rtb_Gain1_c <= 0.25F) {
        /* Switch: '<S33>/Switch' incorporates:
         *  RelationalOperator: '<S33>/UpperRelop'
         */
        if (rtb_Gain1_c < -0.25F) {
          rtb_Gain6_m = -0.25F;
        } else {
          rtb_Gain6_m = rtb_Gain1_c;
        }

        /* End of Switch: '<S33>/Switch' */
      }

      /* End of Switch: '<S33>/Switch2' */

      /* Sum: '<S30>/Difference Inputs2' incorporates:
       *  UnitDelay: '<S30>/Delay Input2'
       *
       * Block description for '<S30>/Difference Inputs2':
       *
       *  Add in CPU
       *
       * Block description for '<S30>/Delay Input2':
       *
       *  Store in Global RAM
       */
      rtb_Gain6_m += FOCpmsmfoc_rtDWork.DelayInput2_DSTATE;

      /* Switch: '<S22>/Switch' incorporates:
       *  Constant: '<S22>/Constant1'
       *  RelationalOperator: '<S22>/Equal'
       */
      if ((*u_ControlMode) == TrqCtrl) {
        /* Merge: '<S1>/Merge' */
        FOCpmsmfoc_rtDWork.Merge = rtb_Gain6_m;
      } else {
        /* Merge: '<S1>/Merge' */
        FOCpmsmfoc_rtDWork.Merge = rtb_Gain2_b;
      }

      /* End of Switch: '<S22>/Switch' */

      /* Update for UnitDelay: '<S30>/Delay Input2'
       *
       * Block description for '<S30>/Delay Input2':
       *
       *  Store in Global RAM
       */
      FOCpmsmfoc_rtDWork.DelayInput2_DSTATE = rtb_Gain6_m;

      /* End of Outputs for SubSystem: '<S6>/PMC_IsqDesCalc' */

      /* Update for UnitDelay: '<S18>/Unit Delay1' incorporates:
       *  MATLAB Function: '<S18>/MATLAB Function1'
       */
      FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m = rtb_Sin;

      /* Update for UnitDelay: '<S26>/Unit Delay1' */
      FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_o = rtb_Gain3_f;

      /* Update for UnitDelay: '<S6>/Unit Delay' */
      FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l = rtb_Gain2_h;

      /* End of Outputs for SubSystem: '<S1>/PMC_IsDesCalc' */
    }
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/IF Control' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S1>/Merge1' incorporates:
     *  SignalConversion generated from: '<S5>/Input'
     */
    FOCpmsmfoc_rtDWork.Merge1 = *u_f32_Iddes_A;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S5>/Constant1'
     *  SignalConversion generated from: '<S5>/Iqref'
     */
    FOCpmsmfoc_rtDWork.Merge = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/IF Control' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  RelationalOperator: '<S15>/Equal'
     *  Switch: '<S15>/Switch1'
     */
    if ((*u_ControlMode) == alOfsCal) {
      /* Merge: '<S1>/Merge1' */
      FOCpmsmfoc_rtDWork.Merge1 = *u_iddes;

      /* Merge: '<S1>/Merge' incorporates:
       *  Constant: '<S15>/Constant1'
       */
      FOCpmsmfoc_rtDWork.Merge = 0.0F;
    } else {
      /* Merge: '<S1>/Merge1' */
      FOCpmsmfoc_rtDWork.Merge1 = *u_f32_Iddes_A;

      /* Merge: '<S1>/Merge' */
      FOCpmsmfoc_rtDWork.Merge = *u_f32_Iqdes_A;
    }

    /* End of Switch: '<S15>/Switch' */
    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Default' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S3>/Constant'
     *  SignalConversion generated from: '<S3>/Idref '
     */
    FOCpmsmfoc_rtDWork.Merge1 = 0.0F;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S3>/Constant1'
     *  SignalConversion generated from: '<S3>/Iqref'
     */
    FOCpmsmfoc_rtDWork.Merge = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/Default' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Gain: '<S1>/Gain2' */
  *y_Idref = 1.41421354F * FOCpmsmfoc_rtDWork.Merge1;

  /* Gain: '<S1>/Gain1' */
  *y_Iqref = 1.41421354F * FOCpmsmfoc_rtDWork.Merge;

  /* Gain: '<S1>/Gain5' */
  rtb_Sin = (((u16_P_MotorPair * 2.0F) * 3.14159274F) / 60.0F) *
    (*u_f32_SpeedAct_rpm);

  /* Sum: '<S9>/Sum1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product3'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  rtb_Sin = (rtb_Sin * 0.001F) + (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_c *
    0.999F);

  /* Gain: '<S12>/Gain' incorporates:
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product3'
   *  Sqrt: '<S12>/Sqrt'
   *  Sum: '<S12>/Add'
   */
  rtb_Gain3_f = sqrtf(((*y_Iqref) * (*y_Iqref)) + ((*y_Idref) * (*y_Idref))) *
    0.707106769F;

  /* Product: '<S12>/Product1' incorporates:
   *  Constant: '<S12>/Constant16'
   *  Constant: '<S12>/Constant2'
   */
  rtb_Subtract_a = g_msgCore0to2_AcrSwtLoRpm * g_msgCore0to2_maxCur;

  /* Product: '<S12>/Product2' incorporates:
   *  Constant: '<S12>/Constant17'
   *  Constant: '<S12>/Constant2'
   */
  rtb_Gain2_h = g_msgCore0to2_AcrSwtHiRpm * g_msgCore0to2_maxCur;

  /* MATLAB Function: '<S12>/AsrPI1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant10'
   *  Constant: '<S12>/Constant13'
   *  Constant: '<S12>/Constant7'
   */
  /*  */
  /* MATLAB Function 'bldc/Subsystem1/AsrPI1': '<S40>:1' */
  /* '<S40>:1:3' if KiHi == single(0) */
  if (g_msgCore0to2_AcrKiStb == 0.0F) {
    /* '<S40>:1:4' asrKiHi = single(0); */
    rtb_Gain2_b = 0.0F;
  } else {
    /* '<S40>:1:5' else */
    /* '<S40>:1:6' asrKiHi = KiHi; */
    rtb_Gain2_b = g_msgCore0to2_AcrKiStb;
  }

  /* '<S40>:1:9' if KiLo == single(0) */
  if (g_msgCore0to2_AcrKi == 0.0F) {
    /* '<S40>:1:10' asrKiLo = single(0); */
    rtb_Gain6_m = 0.0F;
  } else {
    /* '<S40>:1:11' else */
    /* '<S40>:1:12' asrKiLo = KiLo; */
    rtb_Gain6_m = g_msgCore0to2_AcrKi;
  }

  /* '<S40>:1:15' if rpm_Hi >= rpm_Lo */
  if (rtb_Gain2_h >= rtb_Subtract_a) {
    /* '<S40>:1:16' asr_rpm_Hi = rpm_Hi; */
    rtb_Gain1_c = rtb_Gain2_h;

    /* '<S40>:1:17' asr_rpm_Lo = rpm_Lo; */
    rtb_Gain2_h = rtb_Subtract_a;
  } else {
    /* '<S40>:1:18' else */
    /* '<S40>:1:19' asr_rpm_Hi = rpm_Lo; */
    rtb_Gain1_c = rtb_Subtract_a;

    /* '<S40>:1:20' asr_rpm_Lo = rpm_Hi; */
  }

  /* '<S40>:1:23' if fdb >= asr_rpm_Hi */
  if (rtb_Gain3_f >= rtb_Gain1_c) {
    /* '<S40>:1:24' Kp = KpHi; */
    rtb_Subtract_a = g_msgCore0to2_AcrKpStb;

    /* '<S40>:1:25' Ki = asrKiHi; */
    rtb_Gain6_m = rtb_Gain2_b;
  } else if (rtb_Gain3_f <= rtb_Gain2_h) {
    /* '<S40>:1:26' elseif fdb <= asr_rpm_Lo */
    /* '<S40>:1:27' Kp = KpLo; */
    rtb_Subtract_a = g_msgCore0to2_AcrKp;

    /* '<S40>:1:28' Ki = asrKiLo; */
  } else {
    /* '<S40>:1:29' else */
    /* '<S40>:1:30' Kp = (KpHi - KpLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + KpLo; */
    rtb_Gain3_f -= rtb_Gain2_h;
    rtb_Gain2_h = rtb_Gain1_c - rtb_Gain2_h;
    rtb_Subtract_a = (((g_msgCore0to2_AcrKpStb - g_msgCore0to2_AcrKp) *
                       rtb_Gain3_f) / rtb_Gain2_h) + g_msgCore0to2_AcrKp;

    /* '<S40>:1:31' Ki = (asrKiHi - asrKiLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + asrKiLo; */
    rtb_Gain6_m += ((rtb_Gain2_b - rtb_Gain6_m) * rtb_Gain3_f) / rtb_Gain2_h;
  }

  /* End of MATLAB Function: '<S12>/AsrPI1' */

  /* Saturate: '<S12>/Saturation1' */
  if (rtb_Subtract > g_msgCore0to2_pwmFrqSet) {
    rtb_Subtract = g_msgCore0to2_pwmFrqSet;
  } else if (rtb_Subtract < 2000.0F) {
    rtb_Subtract = 2000.0F;
  }

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<S12>/Constant3'
   *  Saturate: '<S12>/Saturation1'
   */
  FOC_CurKp = (rtb_Subtract * rtb_Subtract_a) / g_msgCore0to2_pwmFrqSet;

  /* Sum: '<S41>/Sum1' incorporates:
   *  Constant: '<S16>/Constant'
   *  Product: '<S16>/Product4'
   *  Product: '<S16>/Product5'
   *  Product: '<S41>/Product1'
   *  Product: '<S41>/Product3'
   *  Saturate: '<S16>/Saturation'
   *  Sqrt: '<S16>/Sqrt'
   *  Sum: '<S16>/Sum1'
   *  UnitDelay: '<S41>/Unit Delay1'
   */
  rtb_Subtract = (sqrtf(fmaxf(((*y_Iq) * (*y_Iq)) + ((*y_Id) * (*y_Id)), 0.0F)) *
                  0.05F) + (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_e * 0.95F);

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant12'
   *  Product: '<S12>/Product4'
   *  Saturate: '<S12>/Saturation'
   */
  if (g_msgCore0to2_linearKpEn) {
    rtb_Gain3_f = FOC_CurKp;
  } else {
    /* Product: '<S12>/Divide2' incorporates:
     *  Constant: '<S12>/Constant11'
     *  Gain: '<S12>/Gain6'
     *  Gain: '<S12>/Gain7'
     *  Gain: '<S12>/Gain8'
     *  Sum: '<S12>/Minus1'
     */
    rtb_Gain2_b = ((0.6F * g_msgCore0to2_maxCur) - (0.35360679F * rtb_Subtract))
      / (0.4F * g_msgCore0to2_maxCur);

    /* Saturate: '<S12>/Saturation' */
    if (rtb_Gain2_b > 1.0F) {
      rtb_Gain2_b = 1.0F;
    } else if (rtb_Gain2_b < 0.5F) {
      rtb_Gain2_b = 0.5F;
    }

    rtb_Gain3_f = FOC_CurKp * rtb_Gain2_b;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* ModelReference: '<S1>/Model1' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/Constant16'
   *  Constant: '<S1>/Constant6'
   */
  currentloop(u_Drive, y_Idref, y_Id, y_Iqref, y_Iq, y_Ts, &rtb_Product1,
              &rtb_Sin, &PMC_Ld, &PMC_Lq, &rtb_Gain3_f, &rtb_Gain6_m, (const
    real32_T *)&f32_P_Coef, (const real32_T *)&f32_P_Modulation, &PMC_PsiExc, (
    const real32_T *)&g_msgCore0to2_DecoupleEn, (const real32_T *)&FFW_enable,
              &FOCpmsmfoc_rtDWork.Model1_o1, &FOCpmsmfoc_rtDWork.Model1_o2,
              &FOCpmsmfoc_rtDWork.Model1_o3, y_KpCoef,
              &FOCpmsmfoc_rtDWork.Model1_o5,
              &(FOCpmsmfoc_rtDWork.Model1_InstanceData.rtdw));

  /* ModelReference: '<S1>/Model2' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  SVPWM(u_Drive, &FOCpmsmfoc_rtDWork.Model1_o1, &FOCpmsmfoc_rtDWork.Model1_o2,
        &rtb_Add6, &rtCP_Constant3_Value_i, &FOCpmsmfoc_rtDWork.Model2_o1,
        &cmprU, &cmprV, &cmprW, &(FOCpmsmfoc_rtDWork.Model2_InstanceData.rtdw));

  /* SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyUon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyUon;

  /* SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyVon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyVon;

  /* SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyWon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyWon;

  /* RateTransition: '<S7>/Rate Transition12' */
  if (rtmIsSpecialSampleHit(1, 0, tid)) {
    FOCpmsmfoc_rtDWork.RateTransition12_Buffer = PMC_LqSubLd;

    /* RateTransition: '<S7>/Rate Transition6' */
    FOCpmsmfoc_rtDWork.RateTransition6_Buffer = PMC_PsiExc;

    /* RateTransition: '<S7>/Rate Transition7' */
    FOCpmsmfoc_rtDWork.RateTransition7_Buffer = ISP_iDaFild;

    /* RateTransition: '<S7>/Rate Transition8' */
    FOCpmsmfoc_rtDWork.RateTransition8_Buffer = ISP_iQaFild;
  }

  /* End of RateTransition: '<S7>/Rate Transition12' */

  /* Sum: '<S13>/Plus' incorporates:
   *  Constant: '<S13>/Constant'
   *  Gain: '<S1>/Gain'
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product1'
   *  Product: '<S1>/Product'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  *y_Udref = (((rtb_Product1 * FOCpmsmfoc_rtDWork.Model1_o1) * 0.408248305F) *
              0.1F) + (FOCpmsmfoc_rtDWork.UnitDelay_DSTATE * 0.9F);

  /* Sum: '<S14>/Plus' incorporates:
   *  Constant: '<S14>/Constant'
   *  Gain: '<S1>/Gain3'
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   *  Product: '<S1>/Product1'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  *y_Uqref = (((FOCpmsmfoc_rtDWork.Model1_o2 * rtb_Product1) * 0.408248305F) *
              0.1F) + (FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_k * 0.9F);

  /* UnitDelay: '<S1>/Unit Delay' */
  *y_isdSet_last = FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_b;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE = rtb_Product1;

  /* Update for UnitDelay: '<S37>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_k = ISP_iDaFild;

  /* Update for UnitDelay: '<S38>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_a = ISP_iQaFild;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE = FOCpmsmfoc_rtDWork.Model1_o1;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc = FOCpmsmfoc_rtDWork.Model1_o2;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_j = *y_Usage;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_c = rtb_Sin;

  /* Update for UnitDelay: '<S41>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_e = rtb_Subtract;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE = *y_Udref;

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_k = *y_Uqref;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_b = FOCpmsmfoc_rtDWork.Model1_o3;

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as a local variable.
   * As result, some Output functions may have unused tid.
   */
  (void) (tid);
}

/* Output and update for referenced model: 'FOC' */
void FOCTID1(void)
{
  int_T tid = 1;
  real32_T rtb_Gain1_ie;

  /* Gain: '<S36>/Gain1' incorporates:
   *  Product: '<S36>/Product'
   *  Product: '<S36>/Product1'
   *  Product: '<S36>/Product2'
   *  RateTransition: '<S7>/Rate Transition12'
   *  RateTransition: '<S7>/Rate Transition6'
   *  RateTransition: '<S7>/Rate Transition7'
   *  RateTransition: '<S7>/Rate Transition8'
   *  Sum: '<S36>/Sum'
   */
  rtb_Gain1_ie = ((FOCpmsmfoc_rtDWork.RateTransition6_Buffer *
                   FOCpmsmfoc_rtDWork.RateTransition8_Buffer) -
                  ((FOCpmsmfoc_rtDWork.RateTransition7_Buffer *
                    FOCpmsmfoc_rtDWork.RateTransition12_Buffer) *
                   FOCpmsmfoc_rtDWork.RateTransition8_Buffer)) * (3.0F *
    u16_P_MotorPair);

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S39>/LowerRelop1'
   *  RelationalOperator: '<S39>/UpperRelop'
   *  Switch: '<S39>/Switch'
   */
  if (rtb_Gain1_ie > 500.0F) {
    /* Switch: '<S39>/Switch2' */
    PMC_TrqOutEst = 500.0F;
  } else if (rtb_Gain1_ie < -500.0F) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Switch: '<S39>/Switch2'
     */
    PMC_TrqOutEst = -500.0F;
  } else {
    /* Switch: '<S39>/Switch2' incorporates:
     *  Switch: '<S39>/Switch'
     */
    PMC_TrqOutEst = rtb_Gain1_ie;
  }

  /* End of Switch: '<S39>/Switch2' */

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as a local variable.
   * As result, some Output functions may have unused tid.
   */
  (void) (tid);
}

/* Model initialize function */
void FOC_initialize(const char_T **rt_errorStatus, const rtTimingBridge
                    *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1)
{
  FOCpmsmfoc_RT_MODEL *const FOCpmsmfoc_rtM = &(FOCpmsmfoc_rtMdlrefDWork.rtm);

  /* Registration code */

  /* setup the global timing engine */
  FOCpmsmfoc_rtGlobalTID[0] = mdlref_TID0;
  FOCpmsmfoc_rtGlobalTID[1] = mdlref_TID1;
  FOCpmsmfoc_rtTimingBridge = timingBridge;

  /* initialize error status */
  rtmSetErrorStatusPointer(FOCpmsmfoc_rtM, rt_errorStatus);

  /* Model Initialize function for ModelReference Block: '<S1>/Model1' */
  nxhg2dhc0l_prot(rtmGetErrorStatusPointer(FOCpmsmfoc_rtM),
                  &(FOCpmsmfoc_rtDWork.Model1_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/Model2' */
  bcegzfkptw_prot(rtmGetErrorStatusPointer(FOCpmsmfoc_rtM),
                  &(FOCpmsmfoc_rtDWork.Model2_InstanceData.rtm));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
