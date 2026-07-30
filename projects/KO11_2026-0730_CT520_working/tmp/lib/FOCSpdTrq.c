/*
 * File: FOCSpdTrq.c
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

#include "FOCSpdTrq.h"
#include <math.h>
#include "rtwtypes.h"
#include "ECM.h"
#include "parameter0.h"

/* Exported data definition */
#define FOC_P1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h" 

/* Definition for custom storage class: ExportToFile */
real32_T FOC_Ki;                       /* '<S3>/AsrPI' */

/* speedki */
real32_T FOC_Kp;                       /* '<S3>/AsrPI' */

/* speedkp */

/* Block signals and states (default storage) */
pmsmfocS_D_Work GRSDWork;

/* External inputs (root inport signals with default storage) */
pmsmfocS_ExternalInputs GRSU;

/* External outputs (root outports fed by signals with default storage) */
pmsmfocS_ExternalOutputs GRSY;

/* Real-time model */
static pmsmfocS_RT_MODEL GRSM_;

/* Const memory section */
pmsmfocS_RT_MODEL *const GRSM = &GRSM_;

/* Model step function */

#define FOC_P1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h" 
void FOCSpdTrq_step(void)
{
  real32_T asrKiLo;
  real32_T asr_rpm_Hi;
  real32_T asr_rpm_Lo;
  real32_T rtb_Abs1;
  real32_T rtb_Divide1;
  real32_T rtb_Divide2;
  real32_T rtb_Sum1;
  real32_T rtb_Switch2;
  real32_T rtb_Switch_o2;

  /* Sum: '<S14>/Sum1' incorporates:
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/f32_SpeedAct_rpm'
   *  Product: '<S14>/Product1'
   *  Product: '<S14>/Product3'
   *  UnitDelay: '<S14>/Unit Delay1'
   */
  rtb_Sum1 = (GRSU.f32_SpeedAct_rpm * 0.0015F) + (GRSDWork.UnitDelay1_DSTATE *
    0.9985F);

  /* Abs: '<S3>/Abs1' */
  rtb_Abs1 = fabsf(rtb_Sum1);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant11'
   *  Constant: '<S3>/Constant8'
   */
  if (g_msgCore0to2_CalibEn2) {
    rtb_Switch_o2 = g_msgCore0to2_maxCur2;
  } else {
    rtb_Switch_o2 = g_msgCore0to2_maxTrq;
  }

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant9'
   *  Switch: '<S3>/Switch'
   */
  rtb_Switch_o2 /= 3000.0F;

  /* Product: '<S3>/Divide1' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  rtb_Divide1 = g_msgCore0to2_AsrKpHi * rtb_Switch_o2;

  /* Product: '<S3>/Divide2' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  rtb_Divide2 = g_msgCore0to2_AsrKpLo * rtb_Switch_o2;

  /* MATLAB Function: '<S3>/AsrPI' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant6'
   *  Constant: '<S3>/Constant7'
   *  Inport: '<Root>/Ts'
   */
  /*  */
  /* MATLAB Function 'Subsystem/Subsystem1/AsrPI': '<S13>:1' */
  /* '<S13>:1:3' if TiHi == single(0) */
  if (g_msgCore0to2_AsrTiHi == 0.0F) {
    /* '<S13>:1:4' asrKiHi = single(0); */
    rtb_Switch_o2 = 0.0F;
  } else {
    /* '<S13>:1:5' else */
    /* '<S13>:1:6' asrKiHi = KpHi*Ts/TiHi; */
    rtb_Switch_o2 = (rtb_Divide1 * GRSU.Ts) / g_msgCore0to2_AsrTiHi;
  }

  /* '<S13>:1:9' if TiLo == single(0) */
  if (g_msgCore0to2_AsrTiLo == 0.0F) {
    /* '<S13>:1:10' asrKiLo = single(0); */
    asrKiLo = 0.0F;
  } else {
    /* '<S13>:1:11' else */
    /* '<S13>:1:12' asrKiLo = KpLo*Ts/TiLo; */
    asrKiLo = (rtb_Divide2 * GRSU.Ts) / g_msgCore0to2_AsrTiLo;
  }

  /* '<S13>:1:15' if rpm_Hi >= rpm_Lo */
  if (g_msgCore0to2_AsrSwtHiRpm >= g_msgCore0to2_AsrSwtLoRpm) {
    /* '<S13>:1:16' asr_rpm_Hi = rpm_Hi; */
    asr_rpm_Hi = g_msgCore0to2_AsrSwtHiRpm;

    /* '<S13>:1:17' asr_rpm_Lo = rpm_Lo; */
    asr_rpm_Lo = g_msgCore0to2_AsrSwtLoRpm;
  } else {
    /* '<S13>:1:18' else */
    /* '<S13>:1:19' asr_rpm_Hi = rpm_Lo; */
    asr_rpm_Hi = g_msgCore0to2_AsrSwtLoRpm;

    /* '<S13>:1:20' asr_rpm_Lo = rpm_Hi; */
    asr_rpm_Lo = g_msgCore0to2_AsrSwtHiRpm;
  }

  /* '<S13>:1:23' if fdb >= asr_rpm_Hi */
  if (rtb_Abs1 >= asr_rpm_Hi) {
    /* '<S13>:1:24' Kp = KpHi; */
    FOC_Kp = rtb_Divide1;

    /* '<S13>:1:25' Ki = asrKiHi; */
    FOC_Ki = rtb_Switch_o2;
  } else if (rtb_Abs1 <= asr_rpm_Lo) {
    /* '<S13>:1:26' elseif fdb <= asr_rpm_Lo */
    /* '<S13>:1:27' Kp = KpLo; */
    FOC_Kp = rtb_Divide2;

    /* '<S13>:1:28' Ki = asrKiLo; */
    FOC_Ki = asrKiLo;
  } else {
    /* '<S13>:1:29' else */
    /* '<S13>:1:30' Kp = (KpHi - KpLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + KpLo; */
    rtb_Abs1 -= asr_rpm_Lo;
    asr_rpm_Hi -= asr_rpm_Lo;
    FOC_Kp = (((rtb_Divide1 - rtb_Divide2) * rtb_Abs1) / asr_rpm_Hi) +
      rtb_Divide2;

    /* '<S13>:1:31' Ki = (asrKiHi - asrKiLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + asrKiLo; */
    FOC_Ki = (((rtb_Switch_o2 - asrKiLo) * rtb_Abs1) / asr_rpm_Hi) + asrKiLo;
  }

  /* End of MATLAB Function: '<S3>/AsrPI' */

  /* MinMax: '<S1>/Max' incorporates:
   *  Constant: '<S1>/Constant8'
   *  Inport: '<Root>/TrqMax'
   */
  rtb_Divide1 = fminf(GRSU.TrqMax, g_msgCore0to2_maxTrq);

  /* MinMax: '<S1>/Max1' incorporates:
   *  Constant: '<S1>/Constant8'
   *  Gain: '<S1>/Gain4'
   *  Inport: '<Root>/TrqMin'
   */
  rtb_Abs1 = fmaxf(-g_msgCore0to2_maxTrq, GRSU.TrqMin);

  /* Outputs for Enabled SubSystem: '<S1>/Torque Control' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* RelationalOperator: '<S1>/Equal2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/ControlMode'
   */
  if (GRSU.ControlMode == TrqCtrl) {
    if (!GRSDWork.TorqueControl_MODE) {
      /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_a = 0.0F;
      GRSDWork.TorqueControl_MODE = true;
    }

    /* Sum: '<S4>/Subtract1' incorporates:
     *  Inport: '<Root>/f32_TorqueCmd_Nm'
     */
    asr_rpm_Hi = rtb_Abs1 - GRSU.f32_TorqueCmd_Nm;

    /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S4>/Constant'
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    asrKiLo = GRSDWork.UnitDelay_DSTATE;

    /* MATLAB Function 'Subsystem/Torque Control/SpdPosLimit/MATLAB Function': '<S19>:1' */
    /* '<S19>:1:2' err = ref - act; */
    rtb_Divide2 = f32_P_SpdPoslimit_rpm - GRSU.f32_SpeedAct_rpm;

    /* '<S19>:1:3' temp = err*kp; */
    /* '<S19>:1:4' out = temp + intg; */
    rtb_Switch_o2 = (rtb_Divide2 * FOC_Kp) + GRSDWork.UnitDelay_DSTATE;

    /* '<S19>:1:5' if(out>MAX) */
    if (rtb_Switch_o2 > 0.0F) {
      /* '<S19>:1:6' out = MAX; */
      rtb_Switch_o2 = 0.0F;

      /* '<S19>:1:7' if(err<0) */
      if (rtb_Divide2 < 0.0F) {
        /* '<S19>:1:8' intg = intg + ki*err; */
        asrKiLo = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE;
      }
    } else if (rtb_Switch_o2 < asr_rpm_Hi) {
      /* '<S19>:1:10' elseif(out < MIN) */
      /* '<S19>:1:11' out = MIN; */
      rtb_Switch_o2 = asr_rpm_Hi;

      /* '<S19>:1:12' if(err>0) */
      if (rtb_Divide2 > 0.0F) {
        /* '<S19>:1:13' intg = intg + ki*err; */
        asrKiLo = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE;
      }
    } else {
      /* '<S19>:1:15' else */
      /* '<S19>:1:16' intg = intg + ki*err; */
      asrKiLo = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE;
    }

    /* Sum: '<S4>/Subtract' incorporates:
     *  Inport: '<Root>/f32_TorqueCmd_Nm'
     */
    /* '<S19>:1:18' max(intg,MIN); */
    /* '<S19>:1:19' min(intg,MAX); */
    asr_rpm_Lo = rtb_Divide1 - GRSU.f32_TorqueCmd_Nm;

    /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
     *  Constant: '<S16>/Constant1'
     *  Constant: '<S4>/Constant1'
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  UnitDelay: '<S16>/Unit Delay'
     */
    asr_rpm_Hi = GRSDWork.UnitDelay_DSTATE_a;

    /* MATLAB Function 'Subsystem/Torque Control/SpdNegLimit/MATLAB Function': '<S18>:1' */
    /* '<S18>:1:3' err = ref - act; */
    rtb_Divide2 = f32_P_SpdNeglimit_rpm - GRSU.f32_SpeedAct_rpm;

    /* '<S18>:1:4' temp = err*kp; */
    /* '<S18>:1:5' out = temp + intg; */
    rtb_Switch2 = (rtb_Divide2 * FOC_Kp) + GRSDWork.UnitDelay_DSTATE_a;

    /* '<S18>:1:6' if(out>MAX) */
    if (rtb_Switch2 > asr_rpm_Lo) {
      /* '<S18>:1:7' out = MAX; */
      rtb_Switch2 = asr_rpm_Lo;

      /* '<S18>:1:8' if(err<0) */
      if (rtb_Divide2 < 0.0F) {
        /* '<S18>:1:9' intg = intg + ki*err; */
        asr_rpm_Hi = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_a;
      }
    } else if (rtb_Switch2 < 0.0F) {
      /* '<S18>:1:11' elseif(out < MIN) */
      /* '<S18>:1:12' out = MIN; */
      rtb_Switch2 = 0.0F;

      /* '<S18>:1:13' if(err>0) */
      if (rtb_Divide2 > 0.0F) {
        /* '<S18>:1:14' intg = intg + ki*err; */
        asr_rpm_Hi = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_a;
      }
    } else {
      /* '<S18>:1:16' else */
      /* '<S18>:1:17' intg = intg + ki*err; */
      asr_rpm_Hi = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_a;
    }

    /* Sum: '<S4>/Add' incorporates:
     *  Inport: '<Root>/f32_TorqueCmd_Nm'
     *  MATLAB Function: '<S16>/MATLAB Function'
     *  MATLAB Function: '<S17>/MATLAB Function'
     */
    /* '<S18>:1:19' max(intg,MIN); */
    /* '<S18>:1:20' min(intg,MAX); */
    rtb_Divide2 = (rtb_Switch_o2 + GRSU.f32_TorqueCmd_Nm) + rtb_Switch2;

    /* Switch: '<S15>/Switch2' incorporates:
     *  RelationalOperator: '<S15>/LowerRelop1'
     *  RelationalOperator: '<S15>/UpperRelop'
     *  Switch: '<S15>/Switch'
     */
    if (rtb_Divide2 > rtb_Divide1) {
      /* Switch: '<S15>/Switch2' */
      GRSDWork.Switch2 = rtb_Divide1;
    } else if (rtb_Divide2 < rtb_Abs1) {
      /* Switch: '<S15>/Switch' incorporates:
       *  Switch: '<S15>/Switch2'
       */
      GRSDWork.Switch2 = rtb_Abs1;
    } else {
      /* Switch: '<S15>/Switch2' incorporates:
       *  Switch: '<S15>/Switch'
       */
      GRSDWork.Switch2 = rtb_Divide2;
    }

    /* End of Switch: '<S15>/Switch2' */

    /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
     *  MATLAB Function: '<S17>/MATLAB Function'
     */
    GRSDWork.UnitDelay_DSTATE = asrKiLo;

    /* Update for UnitDelay: '<S16>/Unit Delay' incorporates:
     *  MATLAB Function: '<S16>/MATLAB Function'
     */
    GRSDWork.UnitDelay_DSTATE_a = asr_rpm_Hi;
  } else if (GRSDWork.TorqueControl_MODE) {
    /* Disable for Switch: '<S15>/Switch2' incorporates:
     *  Outport: '<S4>/TrqSet'
     */
    GRSDWork.Switch2 = 0.0F;
    GRSDWork.TorqueControl_MODE = false;
  }

  /* End of RelationalOperator: '<S1>/Equal2' */
  /* End of Outputs for SubSystem: '<S1>/Torque Control' */

  /* Outputs for Enabled SubSystem: '<S1>/Speed Control' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* RelationalOperator: '<S1>/Equal3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/ControlMode'
   *  Inport: '<Root>/Drive'
   *  RelationalOperator: '<S1>/Equal1'
   */
  if ((GRSU.ControlMode == nCtrl) == ((int32_T)GRSU.Drive)) {
    real32_T intgin;
    if (!GRSDWork.SpeedControl_MODE) {
      /* InitializeConditions for UnitDelay: '<S10>/Delay Input2'
       *
       * Block description for '<S10>/Delay Input2':
       *
       *  Store in Global RAM
       */
      GRSDWork.DelayInput2_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S12>/Unit Delay1' */
      GRSDWork.UnitDelay1_DSTATE_f = 0.0F;

      /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_k = 0.0F;

      /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_am = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_ao = 0.0F;
      GRSDWork.SpeedControl_MODE = true;
    }

    /* Product: '<S10>/delta rise limit' incorporates:
     *  Inport: '<Root>/f32_SpdLimitPos'
     *  SampleTimeMath: '<S10>/sample time'
     *
     * About '<S10>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_Switch_o2 = GRSU.f32_SpdLimitPos * 0.0001F;

    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Gain: '<S2>/Gain1'
     *  Inport: '<Root>/SpdDes'
     *  Inport: '<Root>/f32_Speedref_rpm'
     *  RelationalOperator: '<S2>/Equal'
     */
    if (GRSU.ControlMode == alOfsCal) {
      rtb_Divide2 = GRSU.SpdDes;
    } else {
      rtb_Divide2 = 12.0F * GRSU.f32_Speedref_rpm;
    }

    /* End of Switch: '<S2>/Switch' */

    /* Sum: '<S10>/Difference Inputs1' incorporates:
     *  UnitDelay: '<S10>/Delay Input2'
     *
     * Block description for '<S10>/Difference Inputs1':
     *
     *  Add in CPU
     *
     * Block description for '<S10>/Delay Input2':
     *
     *  Store in Global RAM
     */
    asrKiLo = rtb_Divide2 - GRSDWork.DelayInput2_DSTATE;

    /* Switch: '<S11>/Switch2' incorporates:
     *  RelationalOperator: '<S11>/LowerRelop1'
     */
    if (asrKiLo <= rtb_Switch_o2) {
      /* Product: '<S10>/delta fall limit' incorporates:
       *  Inport: '<Root>/f32_SpdLimitNeg'
       *  SampleTimeMath: '<S10>/sample time'
       *
       * About '<S10>/sample time':
       *  y = K where K = ( w * Ts )
       */
      rtb_Switch_o2 = GRSU.f32_SpdLimitNeg * 0.0001F;

      /* Switch: '<S11>/Switch' incorporates:
       *  RelationalOperator: '<S11>/UpperRelop'
       */
      if (asrKiLo >= rtb_Switch_o2) {
        rtb_Switch_o2 = asrKiLo;
      }

      /* End of Switch: '<S11>/Switch' */
    }

    /* End of Switch: '<S11>/Switch2' */

    /* Sum: '<S10>/Difference Inputs2' incorporates:
     *  UnitDelay: '<S10>/Delay Input2'
     *
     * Block description for '<S10>/Difference Inputs2':
     *
     *  Add in CPU
     *
     * Block description for '<S10>/Delay Input2':
     *
     *  Store in Global RAM
     */
    asrKiLo = rtb_Switch_o2 + GRSDWork.DelayInput2_DSTATE;

    /* Sum: '<S12>/Sum1' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Constant: '<S7>/Constant2'
     *  Inport: '<Root>/isdSet_last'
     *  MinMax: '<S7>/Max'
     *  Product: '<S12>/Product1'
     *  Product: '<S12>/Product3'
     *  Product: '<S7>/Product'
     *  Product: '<S7>/Product1'
     *  Sqrt: '<S7>/Sqrt'
     *  Sum: '<S7>/Subtract'
     *  UnitDelay: '<S12>/Unit Delay1'
     */
    asr_rpm_Hi = (sqrtf(fmaxf(0.0F, (g_msgCore0to2_maxCur2 *
      g_msgCore0to2_maxCur2) - (GRSU.isdSet_last * GRSU.isdSet_last))) * 0.1F) +
      (GRSDWork.UnitDelay1_DSTATE_f * 0.9F);

    /* Sum: '<S9>/Plus' incorporates:
     *  Constant: '<S9>/Constant'
     *  Product: '<S9>/Product'
     *  Product: '<S9>/Product1'
     *  UnitDelay: '<S9>/Unit Delay'
     */
    rtb_Divide1 = (GRSDWork.UnitDelay_DSTATE_k * 0.9F) + (0.1F * rtb_Divide1);

    /* Sum: '<S8>/Plus' incorporates:
     *  Constant: '<S8>/Constant'
     *  Product: '<S8>/Product'
     *  Product: '<S8>/Product1'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    rtb_Abs1 = (GRSDWork.UnitDelay_DSTATE_am * 0.9F) + (0.1F * rtb_Abs1);

    /* Switch: '<S2>/Switch1' incorporates:
     *  Abs: '<S7>/Abs1'
     *  Abs: '<S7>/Abs2'
     *  Abs: '<S7>/Abs3'
     *  Constant: '<S2>/Constant'
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant3'
     *  Constant: '<S7>/Constant4'
     *  Constant: '<S7>/Constant5'
     *  Constant: '<S7>/Constant6'
     *  Gain: '<S7>/Gain1'
     *  Inport: '<Root>/SpeedPiMaxRatio'
     *  Inport: '<Root>/SpeedPiMinRatio'
     *  MinMax: '<S7>/Max1'
     *  MinMax: '<S7>/Max2'
     *  MinMax: '<S7>/Max3'
     *  MinMax: '<S7>/Max4'
     *  Product: '<S7>/Product2'
     *  Product: '<S7>/Product3'
     *  Switch: '<S2>/Switch2'
     */
    if (g_msgCore0to2_CalibEn2) {
      asr_rpm_Lo = fminf(fminf(fminf(f32_P_SpeedPiMaxRatio, 1.0F), fabsf
        (GRSU.SpeedPiMaxRatio)) * g_msgCore0to2_maxCur2, asr_rpm_Hi);
      rtb_Switch2 = -fminf(asr_rpm_Hi, g_msgCore0to2_maxCur2 * fminf(fminf(fabsf
        (f32_P_SpeedPiMinRatio), 1.0F), fabsf(GRSU.SpeedPiMinRatio)));
    } else {
      asr_rpm_Lo = rtb_Divide1;
      rtb_Switch2 = rtb_Abs1;
    }

    /* End of Switch: '<S2>/Switch1' */

    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    intgin = GRSDWork.UnitDelay_DSTATE_ao;

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant'
     */
    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function': '<S5>:1' */
    /* '<S5>:1:2' err = (ref - act); */
    if (Spdratelimit_C) {
      rtb_Divide2 = asrKiLo;
    }

    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  Switch: '<S6>/Switch'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    rtb_Divide2 -= GRSU.f32_SpeedAct_rpm;

    /* 去除系数 */
    /* '<S5>:1:3' temp = err*kp; */
    /* '<S5>:1:4' out = temp + intgin; */
    rtb_Switch_o2 = (rtb_Divide2 * FOC_Kp) + GRSDWork.UnitDelay_DSTATE_ao;

    /* '<S5>:1:5' if(out>MAX) */
    if (rtb_Switch_o2 > asr_rpm_Lo) {
      /* '<S5>:1:6' out = MAX; */
      rtb_Switch_o2 = asr_rpm_Lo;

      /* '<S5>:1:7' if(err<0) */
      if (rtb_Divide2 < 0.0F) {
        /* '<S5>:1:8' intgin = intgin + ki*err; */
        intgin = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_ao;
      }
    } else if (rtb_Switch_o2 < rtb_Switch2) {
      /* '<S5>:1:10' elseif(out < MIN) */
      /* '<S5>:1:11' out = MIN; */
      rtb_Switch_o2 = rtb_Switch2;

      /* '<S5>:1:12' if(err>0) */
      if (rtb_Divide2 > 0.0F) {
        /* '<S5>:1:13' intgin = intgin + ki*err; */
        intgin = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_ao;
      }
    } else {
      /* '<S5>:1:15' else */
      /* '<S5>:1:16' intgin = intgin + ki*err; */
      intgin = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_ao;
    }

    /* '<S5>:1:18' max(intgin,MIN); */
    /* '<S5>:1:19' min(intgin,MAX); */
    /* '<S5>:1:20' intgout = intgin; */
    GRSDWork.out = rtb_Switch_o2;

    /* Update for UnitDelay: '<S10>/Delay Input2'
     *
     * Block description for '<S10>/Delay Input2':
     *
     *  Store in Global RAM
     */
    GRSDWork.DelayInput2_DSTATE = asrKiLo;

    /* Update for UnitDelay: '<S12>/Unit Delay1' */
    GRSDWork.UnitDelay1_DSTATE_f = asr_rpm_Hi;

    /* Update for UnitDelay: '<S9>/Unit Delay' */
    GRSDWork.UnitDelay_DSTATE_k = rtb_Divide1;

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    GRSDWork.UnitDelay_DSTATE_am = rtb_Abs1;

    /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    GRSDWork.UnitDelay_DSTATE_ao = intgin;
  } else if (GRSDWork.SpeedControl_MODE) {
    /* Disable for Outport: '<S2>/TrqCmd ' */
    GRSDWork.out = 0.0F;
    GRSDWork.SpeedControl_MODE = false;
  }

  /* End of RelationalOperator: '<S1>/Equal3' */
  /* End of Outputs for SubSystem: '<S1>/Speed Control' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Inport: '<Root>/ControlMode'
   *  RelationalOperator: '<S1>/Equal'
   */
  if (GRSU.ControlMode == TrqCtrl) {
    /* Outport: '<Root>/TrqEmDes' */
    GRSY.TrqEmDes = GRSDWork.Switch2;
  } else {
    /* Outport: '<Root>/TrqEmDes' */
    GRSY.TrqEmDes = GRSDWork.out;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  GRSDWork.UnitDelay1_DSTATE = rtb_Sum1;
}

/* Model initialize function */
void FOCSpdTrq_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void FOCSpdTrq_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
