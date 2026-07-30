/*
 * File: FOC.c
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

/* Definition for custom storage class: ExportToFile */
real32_T FOC_AcrKpCalOpt;              /* '<S17>/AsrPI1' */

/* TODO */
real32_T FOC_CurKp;                    /* '<S17>/Divide' */

/* curkp */
real32_T ISP_iDaFild;                  /* '<S41>/Sum1' */

/* d-axis filtered current,A */
real32_T ISP_iQaFild;                  /* '<S42>/Sum1' */

/* q-axis filtered current,A */
real32_T PMC_FFW_opt;                  /* '<S33>/Gain' */

/* TODO */
real32_T PMC_FWC_opt;                  /* '<S24>/MATLAB Function1' */

/* TODO */
real32_T PMC_IsMax;                    /* '<S25>/Ismax1' */

/* Caculated maximum phase current at current frequency */
real32_T PMC_Ld;                       /* '<S39>/Product4' */

/* d-axis inductance */
real32_T PMC_LpfOpt;                   /* '<S1>/MATLAB Function1' */

/* TODO */
real32_T PMC_LpfSpdAct;                /* '<S14>/Sum1' */

/* TODO */
real32_T PMC_Lq;                       /* '<S39>/Product5' */

/* q-axis inductance */
real32_T PMC_LqSubLd;                  /* '<S39>/Add1' */

/* q-axis sub d-axis inductance */
real32_T PMC_MTPA_opt;                 /* '<S33>/Gain2' */

/* TODO */
real32_T PMC_PsiExc;                   /* '<S39>/Product1' */

/* flux */
real32_T PMC_PsiMax;                   /* '<S33>/Saturation' */

/* Calculated maximum flux for flux weakening control */
real32_T PMC_UsdScal;                  /* '<S1>/Model1' */

/* d axis output Nrm voltage */
real32_T PMC_UsqScal;                  /* '<S1>/Model1' */

/* q axis output Nrm voltage */
real32_T PMC_isdFlt;                   /* '<S13>/Sum1' */

/* alphaBeta-dq current, A */
real32_T PMC_isqFlt;                   /* '<S10>/Sum1' */

/* alphaBeta-dq current, A */
real32_T PMC_pwmfrq;                   /* '<S15>/Switch' */

/* cmprW */
real32_T ToSee_idAnti_windup;          /* '<S1>/MATLAB Function' */

/* TODO */
real32_T ToSee_iqAnti_windup;          /* '<S1>/MATLAB Function' */

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
real32_T usd_output;                   /* '<S1>/MATLAB Function' */

/* TODO */
real32_T usq_output;                   /* '<S1>/MATLAB Function' */

/* TODO */
FOCpmsmfoc_rtMdlrefDWork_n FOCpmsmfoc_rtMdlrefDWork;

/* Block states (default storage) */
FOCpmsmfoc_rtDW_a FOCpmsmfoc_rtDWork;

/* System initialize for referenced model: 'FOC' */
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
  profileStart_FOC(1U); /* original_line:161 */idkqe0cpzy_prot(&(FOCpmsmfoc_rtDWork.Model1_InstanceData.rtdw));profileEnd_FOC(1U); /* original_line:161 */
}

/* System reset for referenced model: 'FOC' */
void FOC_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay5' */
  FOCpmsmfoc_rtDWork.UnitDelay5_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_i = 0.0F;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_i2 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_k = 0.0F;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_e = 0.0F;

  /* InitializeConditions for UnitDelay: '<S42>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_a = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
  FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc = 0.0F;

  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_j = 0.0F;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_c = 0.0F;

  /* InitializeConditions for UnitDelay: '<S45>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_eu = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay3' */
  FOCpmsmfoc_rtDWork.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay4' */
  FOCpmsmfoc_rtDWork.UnitDelay4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_k = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_b = 0.0F;

  /* SystemReset for Atomic SubSystem: '<S1>/AngleComp' */
  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_i = 0U;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_o = 0U;

  /* End of SystemReset for SubSystem: '<S1>/AngleComp' */

  /* SystemReset for MATLAB Function: '<S1>/MATLAB Function' */
  FOCpmsmfoc_rtDWork.reset_not_empty = false;
}

/* Disable for referenced model: 'FOC' */
void FOC_Disable(real32_T *y_f32_Duty_f32_DutyUon, real32_T
                 *y_f32_Duty_f32_DutyVon, real32_T *y_f32_Duty_f32_DutyWon)
{
  /* Disable for Enabled SubSystem: '<S1>/Subsystem' */
  if (FOCpmsmfoc_rtDWork.Subsystem_MODE) {
    /* Disable for Switch: '<S16>/Switch' incorporates:
     *  Outport: '<S16>/Out1'
     */
    FOCpmsmfoc_rtDWork.Switch = Init;
    FOCpmsmfoc_rtDWork.Subsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/Subsystem' */

  /* Disable for SwitchCase: '<S1>/Switch Case' */
  FOCpmsmfoc_rtDWork.SwitchCase_ActiveSubsystem = -1;

  /* Disable for ModelReference: '<S1>/Model1' */
  profileStart_FOC(25U); /* original_line:250 */hfht11bpny_prot(&PMC_UsdScal, &PMC_UsqScal, &FOCpmsmfoc_rtDWork.Model1_o3,
                  &(FOCpmsmfoc_rtDWork.Model1_InstanceData.rtdw));profileEnd_FOC(25U); /* original_line:251 */

  /* Disable for ModelReference: '<S1>/Model2' */
  profileStart_FOC(26U); /* original_line:254 */kxj4bmtjtf_prot(&FOCpmsmfoc_rtDWork.Model2_o1,
                  &(FOCpmsmfoc_rtDWork.Model2_InstanceData.rtdw));profileEnd_FOC(26U); /* original_line:255 */

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
             *u_PWMFrqSet, const real32_T *u_UdHCIF, const real32_T *u_UqHCIF,
             real32_T *y_f32_Duty_f32_DutyUon, real32_T *y_f32_Duty_f32_DutyVon,
             real32_T *y_f32_Duty_f32_DutyWon, real32_T *y_KpCoef, real32_T
             *y_isdSet_last, real32_T *y_Ts, real32_T *y_Id, real32_T *y_Iq)
{
  int_T tid = 0;
  real32_T UdNeglimt;
  real32_T UdPoslimt;
  real32_T act_Ki;
  real32_T pi_d_AxleOutput;
  real32_T rtb_Divide_m;
  real32_T rtb_Gain2_b;
  real32_T rtb_Gain2_h;
  real32_T rtb_Gain3_f;
  real32_T rtb_Product1;
  real32_T rtb_Sin;
  real32_T rtb_Subtract;
  real32_T rtb_Subtract_a;
  real32_T rtb_Switch2_c;
  real32_T temp2;
  int16_T rtb_CastToSingle1;
  uint16_T rtb_Add3;
  uint16_T rtb_Add5;
  uint16_T rtb_Gain8_h;
  uint16_T rtb_angleElec;
  int8_T rtAction;
  int8_T rtPrevAction;

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (*u_Drive) {
    FOCpmsmfoc_rtDWork.Subsystem_MODE = true;

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S16>/Constant1'
     *  Logic: '<S16>/AND'
     *  Logic: '<S16>/NOT'
     *  RelationalOperator: '<S16>/Equal'
     *  RelationalOperator: '<S16>/Equal1'
     */
    if (((*u_ControlMode) != alOfsCal) || ((*u_ROLState) == 1)) {
      /* Switch: '<S16>/Switch' */
      FOCpmsmfoc_rtDWork.Switch = *u_ControlMode;
    } else {
      /* Switch: '<S16>/Switch' incorporates:
       *  Constant: '<S16>/Constant3'
       */
      FOCpmsmfoc_rtDWork.Switch = IsCtrl;
    }

    /* End of Switch: '<S16>/Switch' */
  } else if (FOCpmsmfoc_rtDWork.Subsystem_MODE) {
    /* Disable for Switch: '<S16>/Switch' incorporates:
     *  Outport: '<S16>/Out1'
     */
    FOCpmsmfoc_rtDWork.Switch = Init;
    FOCpmsmfoc_rtDWork.Subsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Product: '<S11>/Product1' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  rtb_Product1 = (*u_Udc) * 0.001F;

  /* Sum: '<S11>/Sum1' incorporates:
   *  Product: '<S11>/Product3'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_Product1 += FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE * 0.999F;

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S47>/Constant'
   *  Switch: '<S47>/Switch'
   */
  if (g_msgCore0to2_motorseq) {
    rtb_Sin = *u_f32_CurrentV_A;
    rtb_Gain3_f = *u_f32_CurrentW_A;
  } else {
    rtb_Sin = *u_f32_CurrentW_A;
    rtb_Gain3_f = *u_f32_CurrentV_A;
  }

  /* End of Switch: '<S47>/Switch1' */

  /* Sum: '<S46>/Subtract' incorporates:
   *  Gain: '<S46>/Gain'
   *  Gain: '<S46>/Gain1'
   */
  rtb_Subtract = ((*u_f32_CurrentU_A) - (0.5F * rtb_Sin)) - (0.5F * rtb_Gain3_f);

  /* Gain: '<S46>/Gain2' */
  rtb_Gain2_h = 0.666666687F * rtb_Subtract;

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  if (PWMFrqSwitch_C) {
    /* Switch: '<S15>/Switch' */
    PMC_pwmfrq = *u_PWMFrqSet;
  } else {
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     */
    PMC_pwmfrq = g_msgCore0to2_pwmFrqSet;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1>/AngleComp' */
  /* Gain: '<S2>/Gain6' */
  rtb_Subtract = 65536.0F * (*u_f32_Speedref_rpm);

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S2>/Constant8'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Add2'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Add3 = (uint16_T)(((uint32_T)((uint16_T)((rtb_Subtract / PMC_pwmfrq) +
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
    FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_o));

  /* Sum: '<S2>/Add5' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Product: '<S2>/Product1'
   */
  profileStart_FOC(2U); /* original_line:427 */rtb_Add5 = (uint16_T)(((int16_T)floorf(f32_P_AngleCompCur * ((real32_T)
    rtb_CastToSingle1))) + rtb_angleElec);profileEnd_FOC(2U); /* original_line:428 */

  /* Sum: '<S2>/Add6' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Product: '<S2>/Product3'
   */
  profileStart_FOC(3U); /* original_line:434 */rtb_angleElec = (uint16_T)(((uint32_T)((uint16_T)((int16_T)floorf(((real32_T)
    rtb_CastToSingle1) * f32_P_AngleCompVol)))) + rtb_Add5);profileEnd_FOC(3U); /* original_line:435 */

  /* Gain: '<S2>/Gain2' */
  rtb_Gain2_b = 9.58740711E-5F * ((real32_T)rtb_Add5);

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  Gain: '<S2>/Gain7'
   */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_i = rtb_Add3;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_o = rtb_Gain8_h;

  /* End of Outputs for SubSystem: '<S1>/AngleComp' */

  /* Trigonometry: '<S46>/Cos' */
  profileStart_FOC(4U); /* original_line:451 */rtb_Subtract = cosf(rtb_Gain2_b);profileEnd_FOC(4U); /* original_line:451 */

  /* Gain: '<S46>/Gain3' incorporates:
   *  Sum: '<S46>/Subtract1'
   */
  rtb_Gain3_f = (rtb_Sin - rtb_Gain3_f) * 0.577350259F;

  /* Trigonometry: '<S46>/Sin' */
  profileStart_FOC(5U); /* original_line:459 */rtb_Sin = sinf(rtb_Gain2_b);profileEnd_FOC(5U); /* original_line:459 */

  /* Sum: '<S46>/Add' incorporates:
   *  Product: '<S46>/Product'
   *  Product: '<S46>/Product1'
   */
  *y_Id = (rtb_Gain2_h * rtb_Subtract) + (rtb_Gain3_f * rtb_Sin);

  /* Product: '<S14>/Product1' incorporates:
   *  Constant: '<S1>/Constant14'
   */
  rtb_Gain2_b = (*u_f32_SpeedAct_rpm) * g_msgCore0to2_dqLpfSpdCoef;

  /* Sum: '<S14>/Sum1' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S1>/Constant14'
   *  Product: '<S14>/Product3'
   *  Sum: '<S14>/Subtract'
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  PMC_LpfSpdAct = ((1.0F - g_msgCore0to2_dqLpfSpdCoef) *
                   FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_i) + rtb_Gain2_b;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<S1>/Constant12'
   *  Constant: '<S1>/Constant15'
   */
  /* MATLAB Function 'bldc/MATLAB Function1': '<S7>:1' */
  /* '<S7>:1:3' if(speedref<=abs(single(spdswitch))) */
  if (PMC_LpfSpdAct <= fabsf(g_msgCore0to2_spdswitch)) {
    /* '<S7>:1:5' y=LpfCoef; */
    PMC_LpfOpt = g_msgCore0to2_dqLpf;
  } else {
    /* '<S7>:1:6' else */
    /* '<S7>:1:7' y=single(1); */
    PMC_LpfOpt = 1.0F;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* Sum: '<S13>/Sum1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Product: '<S13>/Product1'
   *  Product: '<S13>/Product3'
   *  Sum: '<S13>/Subtract'
   *  UnitDelay: '<S13>/Unit Delay1'
   */
  PMC_isdFlt = ((1.0F - PMC_LpfOpt) * FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_i2) +
    ((*y_Id) * PMC_LpfOpt);

  /* Sum: '<S41>/Sum1' incorporates:
   *  Constant: '<S38>/tauPT1Isd'
   *  Gain: '<S9>/Gain'
   *  Product: '<S41>/Product1'
   *  Product: '<S41>/Product3'
   *  UnitDelay: '<S41>/Unit Delay1'
   */
  ISP_iDaFild = ((0.707106769F * PMC_isdFlt) * 0.1F) +
    (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_k * 0.9F);

  /* Sum: '<S46>/Subtract2' incorporates:
   *  Product: '<S46>/Product2'
   *  Product: '<S46>/Product3'
   */
  *y_Iq = (rtb_Gain3_f * rtb_Subtract) - (rtb_Gain2_h * rtb_Sin);

  /* Sum: '<S10>/Sum1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product3'
   *  Sum: '<S10>/Subtract'
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  PMC_isqFlt = ((1.0F - PMC_LpfOpt) * FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_e) +
    ((*y_Iq) * PMC_LpfOpt);

  /* Sum: '<S42>/Sum1' incorporates:
   *  Constant: '<S38>/tauPT1Isd'
   *  Gain: '<S9>/Gain1'
   *  Product: '<S42>/Product1'
   *  Product: '<S42>/Product3'
   *  UnitDelay: '<S42>/Unit Delay1'
   */
  ISP_iQaFild = ((0.707106769F * PMC_isqFlt) * 0.1F) +
    (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_a * 0.9F);

  /* Outputs for Atomic SubSystem: '<S9>/MCT_PsmParCalc' */
  /* Abs: '<S39>/Abs' */
  profileStart_FOC(6U); /* original_line:547 */rtb_Sin = fabsf(ISP_iDaFild);profileEnd_FOC(6U); /* original_line:547 */

  /* Lookup_n-D: '<S39>/cLdAdpt' incorporates:
   *  Sum: '<S42>/Sum1'
   *  UnitDelay: '<S19>/Unit Delay'
   */
  profileStart_FOC(7U); /* original_line:553 */rtb_Subtract = look2_iflf_pbinlca(ISP_iQaFild, rtb_Sin, (const real32_T *)
    &cLdAdptMon_T.bp1[0], (const real32_T *)&cLdAdptMon_T.bp2[0], (const
    real32_T *)&cLdAdptMon_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex_h,
    rtCP_cLdAdpt_maxIndex, 61U);profileEnd_FOC(7U); /* original_line:556 */

  /* Product: '<S39>/Product4' incorporates:
   *  Constant: '<S39>/LdBas'
   */
  PMC_Ld = SC_Ld_P * rtb_Subtract;

  /* Lookup_n-D: '<S39>/cLqAdpt' incorporates:
   *  Sum: '<S42>/Sum1'
   *  UnitDelay: '<S19>/Unit Delay'
   */
  profileStart_FOC(8U); /* original_line:567 */rtb_Sin = look2_iflf_pbinlca(ISP_iQaFild, rtb_Sin, (const real32_T *)
    &cLqAdptMon_T.bp1[0], (const real32_T *)&cLqAdptMon_T.bp2[0], (const
    real32_T *)&cLqAdptMon_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex_i,
    rtCP_cLqAdpt_maxIndex, 61U);profileEnd_FOC(8U); /* original_line:570 */

  /* Product: '<S39>/Product5' incorporates:
   *  Constant: '<S39>/LqBas'
   */
  PMC_Lq = rtb_Sin * SC_Lq_P;

  /* Sum: '<S39>/Add1' */
  PMC_LqSubLd = PMC_Lq - PMC_Ld;

  /* Lookup_n-D: '<S39>/cPsiIsqAdptMot' incorporates:
   *  Sum: '<S42>/Sum1'
   */
  profileStart_FOC(9U); /* original_line:583 */rtb_Sin = look1_iflf_pbinlca(ISP_iQaFild, (const real32_T *)
    &cPsiIsqAdptMot_TT.bp1[0], (const real32_T *)&cPsiIsqAdptMot_TT.tab[0],
    &FOCpmsmfoc_rtDWork.m_bpIndex_c, 120U);profileEnd_FOC(9U); /* original_line:585 */

  /* Product: '<S39>/Product1' incorporates:
   *  Constant: '<S9>/psiExc_25degC'
   */
  PMC_PsiExc = SC_Psi_P * rtb_Sin;

  /* End of Outputs for SubSystem: '<S9>/MCT_PsmParCalc' */

  /* MinMax: '<S1>/Min' incorporates:
   *  Constant: '<S1>/Constant4'
   */
  profileStart_FOC(10U); /* original_line:597 */rtb_Gain3_f = fminf(f32_P_Modulation, *u_f32_ModulationReq);profileEnd_FOC(10U); /* original_line:597 */

  /* Product: '<S15>/Divide' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  *y_Ts = 1.0F / PMC_pwmfrq;

  /* Product: '<S4>/Product2' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_Subtract = (*y_Ts) * 500.0F;

  /* Sum: '<S23>/Sum1' incorporates:
   *  Constant: '<S23>/Constant'
   *  Product: '<S23>/Product1'
   *  Product: '<S23>/Product3'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Sqrt: '<S4>/Sqrt'
   *  Sum: '<S23>/Subtract'
   *  Sum: '<S4>/Add'
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S1>/Unit Delay2'
   *  UnitDelay: '<S23>/Unit Delay1'
   */
  profileStart_FOC(11U); /* original_line:622 */usage = (sqrtf((FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE *
                  FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE) +
                 (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc *
                  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc)) * rtb_Subtract) +
    ((1.0F - rtb_Subtract) * FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_j);profileEnd_FOC(11U); /* original_line:626 */

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Constant: '<S25>/Ismax1'
   *  Constant: '<S34>/IsResDes'
   *  Math: '<S34>/Math Function2'
   *  RelationalOperator: '<S34>/Relational Operator'
   *  Sum: '<S34>/Sum2'
   */
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

   case Discharge:
    rtAction = 3;
    break;

   default:
    rtAction = 4;
    break;
  }

  FOCpmsmfoc_rtDWork.SwitchCase_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/PMC_IsDesCalc' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S24>/Unit Delay1'
       *  UnitDelay: '<S8>/Unit Delay'
       */
      FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m = 0.0F;
      FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S1>/PMC_IsDesCalc' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/PMC_IsDesCalc' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Gain: '<S8>/Gain' */
    rtb_Sin = (u16_P_MotorPair / 60.0F) * (*u_f32_SpeedAct_rpm);

    /* Outputs for Atomic SubSystem: '<S8>/PMC_IsdDesCalc' */
    /* Abs: '<S33>/Abs' incorporates:
     *  Inport generated from: '<Root>/TrqEmDes'
     */
    profileStart_FOC(12U); /* original_line:687 */rtb_Subtract = fabsf(Trqdes_P1);profileEnd_FOC(12U); /* original_line:687 */

    /* End of Outputs for SubSystem: '<S8>/PMC_IsdDesCalc' */

    /* Outputs for Atomic SubSystem: '<S8>/PMC_PwmModCalcn' */
    /* Outputs for Atomic SubSystem: '<S8>/PMC_GenSigCalcn' */
    /* Product: '<S29>/Product' incorporates:
     *  Abs: '<S26>/Abs'
     *  Constant: '<S26>/unit'
     *  Constant: '<S26>/w10Hz'
     *  Gain: '<S8>/Gain2'
     *  Gain: '<S8>/Gain3'
     *  Gain: '<S8>/facMaxMI'
     *  MinMax: '<S26>/MinMax'
     *  Product: '<S26>/Divide'
     */
    profileStart_FOC(13U); /* original_line:703 */rtb_Gain2_h = ((0.408248305F * rtb_Product1) * f32_P_Modulation) * (1.0F /
      fmaxf(62.831852F, fabsf(6.28318548F * rtb_Sin)));profileEnd_FOC(13U); /* original_line:704 */

    /* End of Outputs for SubSystem: '<S8>/PMC_GenSigCalcn' */
    /* End of Outputs for SubSystem: '<S8>/PMC_PwmModCalcn' */

    /* Outputs for Atomic SubSystem: '<S8>/PMC_IsdDesCalc' */
    /* Saturate: '<S33>/Saturation' */
    if (rtb_Gain2_h > 0.18F) {
      /* Saturate: '<S33>/Saturation' */
      PMC_PsiMax = 0.18F;
    } else if (rtb_Gain2_h < 0.006F) {
      /* Saturate: '<S33>/Saturation' */
      PMC_PsiMax = 0.006F;
    } else {
      /* Saturate: '<S33>/Saturation' */
      PMC_PsiMax = rtb_Gain2_h;
    }

    /* End of Saturate: '<S33>/Saturation' */

    /* Lookup_n-D: '<S33>/ExFeedBack' incorporates:
     *  Abs: '<S33>/Abs'
     *  Saturate: '<S33>/Saturation'
     */
    profileStart_FOC(14U); /* original_line:728 */rtb_Gain2_h = look2_iflf_pbinlca(rtb_Subtract, PMC_PsiMax, (const real32_T *)
      &ExFeedBack_T.bp1[0], (const real32_T *)&ExFeedBack_T.bp2[0], (const
      real32_T *)&ExFeedBack_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex,
      rtCP_ExFeedBack_maxIndex, 21U);profileEnd_FOC(14U); /* original_line:731 */

    /* Gain: '<S33>/Gain' incorporates:
     *  Sum: '<S33>/Add'
     */
    PMC_FFW_opt = g_msgCore0to2_FFW_Gain * rtb_Gain2_h;

    /* Gain: '<S33>/Gain1' incorporates:
     *  Abs: '<S33>/Abs1'
     *  Constant: '<S33>/Constant1'
     *  Constant: '<S33>/Constant2'
     *  Constant: '<S33>/Constant3'
     *  MinMax: '<S33>/Min1'
     *  Product: '<S33>/Divide'
     */
    profileStart_FOC(15U); /* original_line:746 */rtb_Gain2_h = -fabsf(g_msgCore0to2_maxCur * fminf
                         (g_msgCore0to2_maxFwcCurRatio, 1.0F));profileEnd_FOC(15U); /* original_line:747 */

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S33>/Constant5'
     */
    if (g_msgCore0to2_CalibEn) {
      rtb_Switch2_c = 0.0F;
    } else {
      /* Lookup_n-D: '<S33>/MTPA_T' incorporates:
       *  Abs: '<S33>/Abs'
       */
      profileStart_FOC(16U); /* original_line:759 */rtb_Switch2_c = look2_iflf_pbinlca(rtb_Subtract, 0.0F, (const real32_T *)
        &MTPA_T.bp1[0], (const real32_T *)&MTPA_T.bp2[0], (const real32_T *)
        &MTPA_T.tab[0], FOCpmsmfoc_rtDWork.m_bpIndex_j, rtCP_MTPA_T_maxIndex,
        21U);profileEnd_FOC(16U); /* original_line:762 */
    }

    /* End of Switch: '<S33>/Switch' */

    /* Gain: '<S33>/Gain2' */
    PMC_MTPA_opt = g_msgCore0to2_MTPA_Gain * rtb_Switch2_c;

    /* MinMax: '<S33>/MinMax' incorporates:
     *  MinMax: '<S33>/MinMax1'
     */
    profileStart_FOC(17U); /* original_line:773 */rtb_Subtract = fmaxf(rtb_Gain2_h, fminf(PMC_FFW_opt, PMC_MTPA_opt));profileEnd_FOC(17U); /* original_line:773 */

    /* End of Outputs for SubSystem: '<S8>/PMC_IsdDesCalc' */

    /* Sum: '<S24>/Add' incorporates:
     *  MinMax: '<S24>/Min2'
     */
    profileStart_FOC(18U); /* original_line:780 */rtb_Sin = fmaxf(PMC_MTPA_opt, rtb_Gain2_h) - rtb_Subtract;profileEnd_FOC(18U); /* original_line:780 */

    /* Sum: '<S24>/Add1' */
    rtb_Gain2_b = rtb_Gain2_h - rtb_Subtract;

    /* Sum: '<S24>/Subtract' incorporates:
     *  MinMax: '<S1>/Min'
     */
    rtb_Subtract_a = rtb_Gain3_f - usage;

    /* Product: '<S31>/Divide' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant4'
     */
    rtb_Divide_m = g_msgCore0to2_AfrKp * g_msgCore0to2_maxCur;

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Constant2'
     */
    if (rtb_Subtract_a > 0.0F) {
      rtb_Gain2_h = 0.25F;
    } else {
      rtb_Gain2_h = 1.0F;
    }

    /* End of Switch: '<S31>/Switch' */

    /* Switch: '<S31>/Switch2' incorporates:
     *  Constant: '<S31>/Constant5'
     *  Constant: '<S31>/Constant6'
     *  Product: '<S31>/Divide1'
     */
    if (g_msgCore0to2_AfrTi != 0.0F) {
      rtb_Switch2_c = (rtb_Divide_m * (*y_Ts)) / g_msgCore0to2_AfrTi;
    } else {
      rtb_Switch2_c = 0.0F;
    }

    /* End of Switch: '<S31>/Switch2' */

    /* Product: '<S31>/Divide3' */
    rtb_Switch2_c *= rtb_Gain2_h;

    /* MATLAB Function: '<S24>/MATLAB Function1' incorporates:
     *  Product: '<S31>/Divide2'
     *  UnitDelay: '<S24>/Unit Delay1'
     */
    rtb_Gain3_f = FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;

    /* MATLAB Function 'bldc/PMC_IsDesCalc/FWC/MATLAB Function1': '<S30>:1' */
    /* '<S30>:1:2' temp = err*kp; */
    /* '<S30>:1:3' out = temp + intg; */
    rtb_Gain2_h = ((rtb_Divide_m * rtb_Gain2_h) * rtb_Subtract_a) +
      FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;

    /* '<S30>:1:4' if(out>MAX) */
    if (rtb_Gain2_h > rtb_Sin) {
      /* '<S30>:1:5' out = MAX; */
      rtb_Gain2_h = rtb_Sin;

      /* '<S30>:1:6' if(err<0) */
      if (rtb_Subtract_a < 0.0F) {
        /* '<S30>:1:7' intg = intg + ki*err; */
        rtb_Gain3_f = (rtb_Switch2_c * rtb_Subtract_a) +
          FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
      }
    } else if (rtb_Gain2_h < rtb_Gain2_b) {
      /* '<S30>:1:9' elseif(out < MIN) */
      /* '<S30>:1:10' out = MIN; */
      rtb_Gain2_h = rtb_Gain2_b;

      /* '<S30>:1:11' if(err>0) */
      if (rtb_Subtract_a > 0.0F) {
        /* '<S30>:1:12' intg = intg + ki*err; */
        rtb_Gain3_f = (rtb_Switch2_c * rtb_Subtract_a) +
          FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
      }
    } else {
      /* '<S30>:1:14' else */
      /* '<S30>:1:15' intg = intg + ki*err; */
      rtb_Gain3_f = (rtb_Switch2_c * rtb_Subtract_a) +
        FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m;
    }

    /* '<S30>:1:17' max(intg,MIN); */
    /* '<S30>:1:18' min(intg,MAX); */
    PMC_FWC_opt = rtb_Gain2_h;

    /* Sum: '<S24>/Add2' */
    rtb_Subtract += PMC_FWC_opt;
    PMC_IsMax = g_msgCore0to2_maxCur;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S25>/Ismax1'
     *  SignalConversion generated from: '<S8>/PMC_IdDes'
     */
    FOCpmsmfoc_rtDWork.Merge1 = rtb_Subtract;

    /* Outputs for Atomic SubSystem: '<S8>/PMC_IsqDesCalc' */
    /* Outputs for Atomic SubSystem: '<S28>/IsqTrqDes_Calc' */
    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/Constant10'
     *  Constant: '<S37>/3p'
     *  Gain: '<S37>/unitNeg'
     *  Inport generated from: '<Root>/TrqEmDes'
     *  Product: '<S35>/Product'
     *  Product: '<S37>/Product1'
     *  Product: '<S37>/Product2'
     *  SignalConversion generated from: '<S35>/MCT_PsiExc'
     *  Sum: '<S37>/Sum1'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    if (g_msgCore0to2_CalibEn) {
      rtb_Sin = Trqdes_P1;
    } else {
      rtb_Sin = Trqdes_P1 / (((PMC_LqSubLd *
        (-FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l)) + PMC_PsiExc) *
        (u16_P_MotorPair * 3.0F));
    }

    /* End of Switch: '<S35>/Switch' */
    /* End of Outputs for SubSystem: '<S28>/IsqTrqDes_Calc' */

    /* Outputs for Atomic SubSystem: '<S28>/IsqDesLim_Calc' */
    /* Sum: '<S34>/Sum1' incorporates:
     *  Math: '<S34>/Math Function'
     *  Math: '<S34>/Math Function1'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    rtb_Gain2_h = (PMC_IsMax * PMC_IsMax) -
      (FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l *
       FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l);

    /* Outputs for Enabled SubSystem: '<S34>/SQRT' incorporates:
     *  EnablePort: '<S36>/Enable'
     */
    if ((rtb_Gain2_h - (rtb_Sin * rtb_Sin)) <= 0.0F) {
      /* Sqrt: '<S36>/Sqrt' incorporates:
       *  Abs: '<S36>/Abs'
       */
      profileStart_FOC(19U); /* original_line:921 */FOCpmsmfoc_rtDWork.Sqrt = sqrtf(fabsf(rtb_Gain2_h));profileEnd_FOC(19U); /* original_line:921 */

      /* Signum: '<S8>/Sign' incorporates:
       *  Inport generated from: '<Root>/TrqEmDes'
       */
      if (Trqdes_P1 < 0.0F) {
        act_Ki = -1.0F;
      } else {
        act_Ki = (real32_T)(Trqdes_P1 > 0.0F);
      }

      /* Merge: '<S1>/Merge' incorporates:
       *  MultiPortSwitch: '<S28>/Index Vector'
       *  Product: '<S34>/Product'
       *  Signum: '<S8>/Sign'
       */
      FOCpmsmfoc_rtDWork.Merge = FOCpmsmfoc_rtDWork.Sqrt * act_Ki;
    } else {
      /* Merge: '<S1>/Merge' incorporates:
       *  MultiPortSwitch: '<S28>/Index Vector'
       */
      FOCpmsmfoc_rtDWork.Merge = rtb_Sin;
    }

    /* End of Outputs for SubSystem: '<S34>/SQRT' */
    /* End of Outputs for SubSystem: '<S28>/IsqDesLim_Calc' */
    /* End of Outputs for SubSystem: '<S8>/PMC_IsqDesCalc' */

    /* Update for UnitDelay: '<S24>/Unit Delay1' incorporates:
     *  Constant: '<S34>/IsResDes'
     *  MATLAB Function: '<S24>/MATLAB Function1'
     *  Math: '<S34>/Math Function2'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  Sum: '<S34>/Sum2'
     */
    FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_m = rtb_Gain3_f;

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_l = rtb_Subtract;

    /* End of Outputs for SubSystem: '<S1>/PMC_IsDesCalc' */
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
     *  ActionPort: '<S20>/Action Port'
     */
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant'
     *  RelationalOperator: '<S20>/Equal'
     *  Switch: '<S20>/Switch1'
     */
    if ((*u_ControlMode) == alOfsCal) {
      /* Merge: '<S1>/Merge1' */
      FOCpmsmfoc_rtDWork.Merge1 = *u_iddes;

      /* Merge: '<S1>/Merge' incorporates:
       *  Constant: '<S20>/Constant1'
       */
      FOCpmsmfoc_rtDWork.Merge = 0.0F;
    } else {
      /* Merge: '<S1>/Merge1' */
      FOCpmsmfoc_rtDWork.Merge1 = *u_f32_Iddes_A;

      /* Merge: '<S1>/Merge' */
      FOCpmsmfoc_rtDWork.Merge = *u_f32_Iqdes_A;
    }

    /* End of Switch: '<S20>/Switch' */
    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Merge: '<S1>/Merge1' incorporates:
     *  SignalConversion generated from: '<S21>/Iddes'
     */
    FOCpmsmfoc_rtDWork.Merge1 = *u_f32_Iddes_A;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S21>/Iqdes'
     *  SignalConversion generated from: '<S21>/Iqref'
     */
    FOCpmsmfoc_rtDWork.Merge = 0.0F;

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

  /* Gain: '<S1>/Gain1' */
  PMC_IsqDes = 1.41421354F * FOCpmsmfoc_rtDWork.Merge;

  /* Gain: '<S1>/Gain2' */
  PMC_IsdDes = 1.41421354F * FOCpmsmfoc_rtDWork.Merge1;

  /* Gain: '<S1>/Gain5' */
  rtb_Subtract = (((u16_P_MotorPair * 2.0F) * 3.14159274F) / 60.0F) *
    (*u_f32_SpeedAct_rpm);

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S12>/Product1'
   *  Product: '<S12>/Product3'
   *  Sum: '<S12>/Subtract'
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  rtb_Subtract = ((1.0F - g_msgCore0to2_arc_dd_fi) *
                  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_c) + (rtb_Subtract *
    g_msgCore0to2_arc_dd_fi);

  /* Abs: '<S17>/Abs' */
  profileStart_FOC(20U); /* original_line:1074 */rtb_Sin = fabsf(PMC_LpfSpdAct);profileEnd_FOC(20U); /* original_line:1074 */

  /* MATLAB Function: '<S17>/AsrPI1' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S17>/Constant10'
   *  Constant: '<S17>/Constant13'
   *  Constant: '<S17>/Constant16'
   *  Constant: '<S17>/Constant17'
   *  Constant: '<S17>/Constant7'
   */
  /*  */
  /* MATLAB Function 'bldc/Subsystem1/AsrPI1': '<S44>:1' */
  /* '<S44>:1:3' if KiHi == single(0) */
  if (g_msgCore0to2_AcrKiStb == 0.0F) {
    /* '<S44>:1:4' asrKiHi = single(0); */
    rtb_Gain2_h = 0.0F;
  } else {
    /* '<S44>:1:5' else */
    /* '<S44>:1:6' asrKiHi = KiHi; */
    rtb_Gain2_h = g_msgCore0to2_AcrKiStb;
  }

  /* '<S44>:1:9' if KiLo == single(0) */
  if (g_msgCore0to2_AcrKi == 0.0F) {
    /* '<S44>:1:10' asrKiLo = single(0); */
    rtb_Gain3_f = 0.0F;
  } else {
    /* '<S44>:1:11' else */
    /* '<S44>:1:12' asrKiLo = KiLo; */
    rtb_Gain3_f = g_msgCore0to2_AcrKi;
  }

  /* '<S44>:1:15' if rpm_Hi >= rpm_Lo */
  if (g_msgCore0to2_AcrSwtHiRpm >= g_msgCore0to2_AcrSwtLoRpm) {
    /* '<S44>:1:16' asr_rpm_Hi = rpm_Hi; */
    rtb_Gain2_b = g_msgCore0to2_AcrSwtHiRpm;

    /* '<S44>:1:17' asr_rpm_Lo = rpm_Lo; */
    rtb_Subtract_a = g_msgCore0to2_AcrSwtLoRpm;
  } else {
    /* '<S44>:1:18' else */
    /* '<S44>:1:19' asr_rpm_Hi = rpm_Lo; */
    rtb_Gain2_b = g_msgCore0to2_AcrSwtLoRpm;

    /* '<S44>:1:20' asr_rpm_Lo = rpm_Hi; */
    rtb_Subtract_a = g_msgCore0to2_AcrSwtHiRpm;
  }

  /* '<S44>:1:23' if fdb >= asr_rpm_Hi */
  if (rtb_Sin >= rtb_Gain2_b) {
    /* '<S44>:1:24' Kp = KpHi; */
    FOC_AcrKpCalOpt = g_msgCore0to2_AcrKpStb;

    /* '<S44>:1:25' Ki = asrKiHi; */
    rtb_Gain3_f = rtb_Gain2_h;
  } else if (rtb_Sin <= rtb_Subtract_a) {
    /* '<S44>:1:26' elseif fdb <= asr_rpm_Lo */
    /* '<S44>:1:27' Kp = KpLo; */
    FOC_AcrKpCalOpt = g_msgCore0to2_AcrKp;

    /* '<S44>:1:28' Ki = asrKiLo; */
  } else {
    /* '<S44>:1:29' else */
    /* '<S44>:1:30' Kp = (KpHi - KpLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + KpLo; */
    rtb_Sin -= rtb_Subtract_a;
    rtb_Gain2_b -= rtb_Subtract_a;
    FOC_AcrKpCalOpt = (((g_msgCore0to2_AcrKpStb - g_msgCore0to2_AcrKp) * rtb_Sin)
                       / rtb_Gain2_b) + g_msgCore0to2_AcrKp;

    /* '<S44>:1:31' Ki = (asrKiHi - asrKiLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + asrKiLo; */
    rtb_Gain3_f += ((rtb_Gain2_h - rtb_Gain3_f) * rtb_Sin) / rtb_Gain2_b;
  }

  /* End of MATLAB Function: '<S17>/AsrPI1' */

  /* Saturate: '<S17>/Saturation1' */
  if (PMC_pwmfrq > g_msgCore0to2_pwmFrqSet) {
    act_Ki = g_msgCore0to2_pwmFrqSet;
  } else if (PMC_pwmfrq < 2000.0F) {
    act_Ki = 2000.0F;
  } else {
    act_Ki = PMC_pwmfrq;
  }

  /* Product: '<S17>/Divide' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Saturate: '<S17>/Saturation1'
   */
  FOC_CurKp = (act_Ki * FOC_AcrKpCalOpt) / g_msgCore0to2_pwmFrqSet;

  /* Sum: '<S45>/Sum1' incorporates:
   *  Constant: '<S22>/Constant'
   *  Product: '<S22>/Product4'
   *  Product: '<S22>/Product5'
   *  Product: '<S45>/Product1'
   *  Product: '<S45>/Product3'
   *  Saturate: '<S22>/Saturation'
   *  Sqrt: '<S22>/Sqrt'
   *  Sum: '<S22>/Sum1'
   *  UnitDelay: '<S45>/Unit Delay1'
   */
  profileStart_FOC(21U); /* original_line:1175 */rtb_Sin = (sqrtf(fmaxf(((*y_Iq) * (*y_Iq)) + ((*y_Id) * (*y_Id)), 0.0F)) *
             0.05F) + (FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_eu * 0.95F);profileEnd_FOC(21U); /* original_line:1176 */

  /* Switch: '<S17>/Switch1' incorporates:
   *  Constant: '<S17>/Constant12'
   *  Product: '<S17>/Product4'
   *  Saturate: '<S17>/Saturation'
   */
  if (g_msgCore0to2_linearKpEn) {
    rtb_Gain2_h = FOC_CurKp;
  } else {
    /* Product: '<S17>/Divide2' incorporates:
     *  Constant: '<S17>/Constant11'
     *  Gain: '<S17>/Gain6'
     *  Gain: '<S17>/Gain7'
     *  Gain: '<S17>/Gain8'
     *  Sum: '<S17>/Minus1'
     */
    rtb_Gain2_h = ((0.6F * g_msgCore0to2_maxCur) - (0.35360679F * rtb_Sin)) /
      (0.4F * g_msgCore0to2_maxCur);

    /* Saturate: '<S17>/Saturation' */
    if (rtb_Gain2_h > 1.0F) {
      rtb_Gain2_h = 1.0F;
    } else if (rtb_Gain2_h < 0.5F) {
      rtb_Gain2_h = 0.5F;
    }

    rtb_Gain2_h *= FOC_CurKp;
  }

  /* End of Switch: '<S17>/Switch1' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   *  UnitDelay: '<S1>/Unit Delay3'
   *  UnitDelay: '<S1>/Unit Delay4'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  d_integral = FOCpmsmfoc_rtDWork.UnitDelay3_DSTATE;
  q_integral = FOCpmsmfoc_rtDWork.UnitDelay4_DSTATE;
  rtb_Gain2_b = d_integral;
  rtb_Subtract_a = q_integral;

  /* persistent temp_d_integral; */
  /* MATLAB Function 'bldc/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:7' if isempty(reset) */
  if (!FOCpmsmfoc_rtDWork.reset_not_empty) {
    /* '<S6>:1:8' reset = boolean(1); */
    FOCpmsmfoc_rtDWork.reset_not_empty = true;

    /* modulation_state = single(0); */
    /* '<S6>:1:10' q_integral = single(0); */
    rtb_Subtract_a = 0.0F;

    /* '<S6>:1:11' d_integral = single(0); */
    rtb_Gain2_b = 0.0F;

    /* modulation_state_new = single(0); */
  }

  /* '<S6>:1:16' if(Drive==1) */
  if (*u_Drive) {
    real32_T anti_sat_term;
    real32_T id_error;
    real32_T iq_error;
    real32_T pi_q_AxleOutput;
    real32_T pi_q_AxleOutput_tmp;

    /* '<S6>:1:17' act_Kp= single((sqrt(3)* acr_kp)/Vdc); */
    rtb_Divide_m = (1.73205078F * rtb_Gain2_h) / rtb_Product1;

    /* '<S6>:1:18' act_Ki= single((sqrt(3)* acr_ki*sample_time)/Vdc); */
    act_Ki = ((1.73205078F * rtb_Gain3_f) * (*y_Ts)) / rtb_Product1;

    /* '<S6>:1:19' anti_sat_term = (act_Kp * kc * omega) *sample_time; */
    anti_sat_term = ((rtb_Divide_m * f32_P_Coef) * rtb_Subtract) * (*y_Ts);

    /* '<S6>:1:21' id_error = single(idref - idact); */
    id_error = PMC_IsdDes - PMC_isdFlt;

    /* '<S6>:1:22' iq_error = single(iqref - iqact); */
    iq_error = PMC_IsqDes - PMC_isqFlt;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%d_axle%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* '<S6>:1:26' d_decouple = (-(omega *Lq*iqref*decouple_gain)*sqrt(3))/Vdc; */
    rtb_Switch2_c = ((-(((rtb_Subtract * PMC_Lq) * PMC_IsqDes) *
                        g_msgCore0to2_DecoupleEn)) * 1.73205078F) / rtb_Product1;

    /* '<S6>:1:30' UdPoslimt = f32_P_Modulation -d_decouple; */
    UdPoslimt = f32_P_Modulation - rtb_Switch2_c;

    /* 上限 */
    /* '<S6>:1:31' UdNeglimt = -f32_P_Modulation -d_decouple; */
    UdNeglimt = (-f32_P_Modulation) - rtb_Switch2_c;

    /* 下限 */
    /* '<S6>:1:33' integral_delta = act_Ki * id_error; */
    /* 求当前拍积分 */
    /* '<S6>:1:34' d_integral = d_integral + integral_delta; */
    temp2 = act_Ki * id_error;
    rtb_Gain2_b += temp2;

    /* 累加 */
    /* '<S6>:1:35' pi_d_AxleOutput=act_Kp*id_error +d_integral; */
    pi_d_AxleOutput = (rtb_Divide_m * id_error) + rtb_Gain2_b;

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
        rtb_Gain2_b += UdPoslimt;
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
        rtb_Gain2_b += UdPoslimt;
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
    pi_d_AxleOutput += rtb_Switch2_c;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%限幅值%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* '<S6>:1:70' temp1 =  single(1.177225) - usd_output*usd_output; */
    /* '<S6>:1:71' temp1 = sqrt(temp1); */
    /* '<S6>:1:72' if(temp1 <0) */
    /* '<S6>:1:75' temp2 = single(0.1)*single(temp1)+single(0.9)*uqlimit_1; */
    profileStart_FOC(22U); /* original_line:1350 */temp2 = (sqrtf(1.17722499F - (pi_d_AxleOutput * pi_d_AxleOutput)) * 0.1F) +
      (0.9F * FOCpmsmfoc_rtDWork.UnitDelay5_DSTATE);profileEnd_FOC(22U); /* original_line:1351 */

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
    UdPoslimt = (((((rtb_Subtract * PMC_Ld) * PMC_IsdDes) *
                   g_msgCore0to2_DecoupleEn) * 1.73205078F) + (((rtb_Subtract *
      PMC_PsiExc) * FFW_enable) * 1.41421354F)) / rtb_Product1;

    /* '<S6>:1:88' UqPoslimt = uqlimit - q_decouple_Add_ffw; */
    UdNeglimt = temp2 - UdPoslimt;

    /* '<S6>:1:89' UqNeglimt = -uqlimit - q_decouple_Add_ffw ; */
    temp2 = (-temp2) - UdPoslimt;

    /* integral_delta_q = act_Ki * iq_error; */
    /* q_integral = q_integral + integral_delta_q; */
    /* '<S6>:1:95' pi_q_AxleOutput=act_Kp*iq_error +q_integral; */
    pi_q_AxleOutput_tmp = rtb_Divide_m * iq_error;
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
      rtb_Divide_m = UdNeglimt;
    } else if (act_Ki < temp2) {
      /* '<S6>:1:141' elseif(act_Kp*iq_error+q_integral<UqNeglimt) */
      /* '<S6>:1:142' Q_Axle_final = UqNeglimt; */
      rtb_Divide_m = temp2;
    } else {
      /* '<S6>:1:143' else */
      /* '<S6>:1:144' Q_Axle_final =act_Kp*iq_error+q_integral; */
      rtb_Divide_m = (rtb_Divide_m * iq_error) + rtb_Subtract_a;
    }

    /* '<S6>:1:147' usq_output = Q_Axle_final +q_decouple_Add_ffw; */
    usq_output = rtb_Divide_m + UdPoslimt;

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else {
    /* '<S6>:1:149' else */
    /* '<S6>:1:150' q_integral = single(0); */
    rtb_Subtract_a = 0.0F;

    /* '<S6>:1:151' d_integral = single(0); */
    rtb_Gain2_b = 0.0F;

    /* '<S6>:1:152' usd_output = single(0); */
    pi_d_AxleOutput = 0.0F;

    /* '<S6>:1:153' usq_output = single(0); */
    usq_output = 0.0F;

    /* '<S6>:1:154' q_decouple_Add_ffw = single(0); */
    UdPoslimt = 0.0F;

    /* '<S6>:1:155' d_decouple = single(0); */
    rtb_Switch2_c = 0.0F;

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
  d_integral = rtb_Gain2_b;
  q_integral = rtb_Subtract_a;
  q_decouple_Add_ffw = UdPoslimt;
  d_decouple = rtb_Switch2_c;

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* ModelReference: '<S1>/Model1' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/Constant16'
   *  Constant: '<S1>/Constant6'
   */
  profileStart_FOC(23U); /* original_line:1528 */currentloop(u_Drive, &PMC_IsdDes, &PMC_isdFlt, &PMC_IsqDes, &PMC_isqFlt, y_Ts,
              &rtb_Product1, &rtb_Subtract, &PMC_Ld, &PMC_Lq, &rtb_Gain2_h,
              &rtb_Gain3_f, (const real32_T *)&f32_P_Coef, (const real32_T *)
              &f32_P_Modulation, &PMC_PsiExc, (const real32_T *)
              &g_msgCore0to2_DecoupleEn, (const real32_T *)&FFW_enable,
              &PMC_UsdScal, &PMC_UsqScal, &FOCpmsmfoc_rtDWork.Model1_o3,
              y_KpCoef, &FOCpmsmfoc_rtDWork.Model1_o5,
              &(FOCpmsmfoc_rtDWork.Model1_InstanceData.rtdw));profileEnd_FOC(23U); /* original_line:1535 */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Switch: '<S1>/Switch1'
   */
  if (g_msgCore0to2_clpwitch) {
    rtb_Gain3_f = usd_output;
    rtb_Gain2_h = usq_output;
  } else {
    /* Sum: '<S1>/Add' */
    rtb_Gain3_f = PMC_UsdScal + (*u_UdHCIF);

    /* Sum: '<S1>/Add1' */
    rtb_Gain2_h = PMC_UsqScal + (*u_UqHCIF);
  }

  /* End of Switch: '<S1>/Switch' */

  /* Constant: '<S1>/Constant3' */
  rtb_Add3 = g_msgCore0to2_motorseq;

  /* ModelReference: '<S1>/Model2' */
  profileStart_FOC(24U); /* original_line:1558 */SVPWM(u_Drive, &rtb_Gain3_f, &rtb_Gain2_h, &rtb_angleElec, &rtb_Add3,
        &FOCpmsmfoc_rtDWork.Model2_o1, &cmprU, &cmprV, &cmprW,
        &(FOCpmsmfoc_rtDWork.Model2_InstanceData.rtdw));profileEnd_FOC(24U); /* original_line:1560 */

  /* SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyUon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyUon;

  /* SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyVon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyVon;

  /* SignalConversion generated from: '<Root>/f32_Duty' */
  *y_f32_Duty_f32_DutyWon = FOCpmsmfoc_rtDWork.Model2_o1.f32_DutyWon;

  /* RateTransition: '<S9>/Rate Transition12' */
  if (rtmIsSpecialSampleHit(1, 0, tid)) {
    FOCpmsmfoc_rtDWork.RateTransition12_Buffer = PMC_LqSubLd;

    /* RateTransition: '<S9>/Rate Transition6' */
    FOCpmsmfoc_rtDWork.RateTransition6_Buffer = PMC_PsiExc;

    /* RateTransition: '<S9>/Rate Transition7' */
    FOCpmsmfoc_rtDWork.RateTransition7_Buffer = ISP_iDaFild;

    /* RateTransition: '<S9>/Rate Transition8' */
    FOCpmsmfoc_rtDWork.RateTransition8_Buffer = ISP_iQaFild;
  }

  /* End of RateTransition: '<S9>/Rate Transition12' */

  /* Sum: '<S18>/Plus' incorporates:
   *  Constant: '<S18>/Constant'
   *  Gain: '<S1>/Gain'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Product: '<S1>/Product'
   *  UnitDelay: '<S18>/Unit Delay'
   */
  PMC_UsdFlt = (((rtb_Product1 * PMC_UsdScal) * 0.408248305F) * 0.1F) +
    (FOCpmsmfoc_rtDWork.UnitDelay_DSTATE * 0.9F);

  /* Sum: '<S19>/Plus' incorporates:
   *  Constant: '<S19>/Constant'
   *  Gain: '<S1>/Gain3'
   *  Product: '<S19>/Product'
   *  Product: '<S19>/Product1'
   *  Product: '<S1>/Product1'
   *  UnitDelay: '<S19>/Unit Delay'
   */
  PMC_UsqFlt = (((PMC_UsqScal * rtb_Product1) * 0.408248305F) * 0.1F) +
    (FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_k * 0.9F);

  /* UnitDelay: '<S1>/Unit Delay' */
  *y_isdSet_last = FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_b;

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  FOCpmsmfoc_rtDWork.UnitDelay5_DSTATE = Uq_output_limit;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE = rtb_Product1;

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_i = PMC_LpfSpdAct;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_i2 = PMC_isdFlt;

  /* Update for UnitDelay: '<S41>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_k = ISP_iDaFild;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_e = PMC_isqFlt;

  /* Update for UnitDelay: '<S42>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_a = ISP_iQaFild;

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Switch: '<S1>/Switch3'
   */
  if (g_msgCore0to2_clpwitch) {
    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE = usd_output;

    /* Update for UnitDelay: '<S1>/Unit Delay1' */
    FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc = usq_output;
  } else {
    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    FOCpmsmfoc_rtDWork.UnitDelay2_DSTATE = PMC_UsdScal;

    /* Update for UnitDelay: '<S1>/Unit Delay1' */
    FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_kc = PMC_UsqScal;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Update for UnitDelay: '<S23>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_j = usage;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_c = rtb_Subtract;

  /* Update for UnitDelay: '<S45>/Unit Delay1' */
  FOCpmsmfoc_rtDWork.UnitDelay1_DSTATE_eu = rtb_Sin;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  FOCpmsmfoc_rtDWork.UnitDelay3_DSTATE = d_integral;

  /* Update for UnitDelay: '<S1>/Unit Delay4' */
  FOCpmsmfoc_rtDWork.UnitDelay4_DSTATE = q_integral;

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE = PMC_UsdFlt;

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  FOCpmsmfoc_rtDWork.UnitDelay_DSTATE_k = PMC_UsqFlt;

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
  real32_T rtb_Gain1_me;

  /* Gain: '<S40>/Gain1' incorporates:
   *  Product: '<S40>/Product'
   *  Product: '<S40>/Product1'
   *  Product: '<S40>/Product2'
   *  RateTransition: '<S9>/Rate Transition12'
   *  RateTransition: '<S9>/Rate Transition6'
   *  RateTransition: '<S9>/Rate Transition7'
   *  RateTransition: '<S9>/Rate Transition8'
   *  Sum: '<S40>/Sum'
   */
  rtb_Gain1_me = ((FOCpmsmfoc_rtDWork.RateTransition6_Buffer *
                   FOCpmsmfoc_rtDWork.RateTransition8_Buffer) -
                  ((FOCpmsmfoc_rtDWork.RateTransition7_Buffer *
                    FOCpmsmfoc_rtDWork.RateTransition12_Buffer) *
                   FOCpmsmfoc_rtDWork.RateTransition8_Buffer)) * (3.0F *
    u16_P_MotorPair);

  /* Switch: '<S43>/Switch2' incorporates:
   *  Constant: '<S40>/Constant'
   *  RelationalOperator: '<S43>/LowerRelop1'
   *  RelationalOperator: '<S43>/UpperRelop'
   *  Switch: '<S43>/Switch'
   */
  if (rtb_Gain1_me > 500.0F) {
    /* Switch: '<S43>/Switch2' */
    PMC_TrqOutEst = 500.0F;
  } else if (rtb_Gain1_me < -500.0F) {
    /* Switch: '<S43>/Switch' incorporates:
     *  Switch: '<S43>/Switch2'
     */
    PMC_TrqOutEst = -500.0F;
  } else {
    /* Switch: '<S43>/Switch2' incorporates:
     *  Switch: '<S43>/Switch'
     */
    PMC_TrqOutEst = rtb_Gain1_me;
  }

  /* End of Switch: '<S43>/Switch2' */

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
