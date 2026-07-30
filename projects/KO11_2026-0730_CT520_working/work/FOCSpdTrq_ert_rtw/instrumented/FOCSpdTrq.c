/*
 * File: FOCSpdTrq.c
 *
 * Code generated for Simulink model 'FOCSpdTrq'.
 *
 * Model version                  : 1.197
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 28 23:07:39 2026
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
#include "lookuptabletypeP1.h"
#include "ECM.h"
#include "look1_iflf_pbinlca.h"
#include "parameter0.h"
#include "lookuptableP1.h"

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
real32_T AntiWindup_Alfa;              /* '<S2>/MATLAB Function1' */

/* TODO */
real32_T AntiWindup_Kpvalue;           /* '<S2>/MATLAB Function1' */

/* TODO */
real32_T AntiWindup_Signal;            /* '<S2>/Data Type Conversion5' */

/* TODO */
real32_T AntiWindup_coef;              /* '<S2>/Data Type Conversion' */

/* TODO */
real32_T AntiWindup_integral;          /* '<S2>/MATLAB Function1' */

/* TODO */
real32_T AntiWindup_out;               /* '<S2>/MATLAB Function1' */

/* TODO */
real32_T AsrKp_Calvalue;               /* '<S2>/Data Type Conversion3' */

/* TODO */
real32_T Asrintgin_value;              /* '<S2>/MATLAB Function' */

/* TODO */
real32_T FFKp_value;                   /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T FFintgin_value;               /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T FFout;                        /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T FOC_Ki;                       /* '<S3>/AsrPI' */

/* speedki */
real32_T FOC_Kp;                       /* '<S3>/AsrPI' */

/* speedkp */
real32_T K1_Limitvalue_P1;             /* '<S14>/Switch2' */

/* TODO */
real32_T K1_value_P1;                  /* '<S2>/Amplitude_Table' */

/* TODO */
real32_T K3_value_P1;                  /* '<S2>/Amplitude_Table1' */

/* TODO */
real32_T LPFcoswave;                   /* '<S13>/Sum1' */

/* TODO */
real32_T LPFsinwave;                   /* '<S12>/Sum1' */

/* TODO */
real32_T PDFF_Kvp_coef;                /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T PDFF_SpdrefMuxKff;            /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T PIout;                        /* '<S2>/MATLAB Function' */

/* TODO */
real32_T R_finaloutput;                /* '<S2>/Gain4' */

/* TODO */
real32_T R_output;                     /* '<S2>/MATLAB Function6' */

/* TODO */
real32_T R_wo;                         /* '<S2>/Gain3' */

/* TODO */
real32_T Trqcomp_Max_P1;               /* '<S2>/Add2' */

/* TODO */
real32_T Trqcomp_Min_P1;               /* '<S2>/Add3' */

/* TODO */
real32_T alpha;                        /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T beta;                         /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T beta_signal;                  /* '<S2>/MATLAB Function3' */

/* TODO */
real32_T comp_P1;                      /* '<S2>/Switch5' */

/* TODO */
real32_T cosfixtrq;                    /* '<S2>/cos' */

/* TODO */
real32_T coswave;                      /* '<S2>/MATLAB Function5' */

/* TODO */
real32_T err_thresh_high;              /* '<S2>/MATLAB Function1' */

/* TODO */
real32_T err_thresh_low;               /* '<S2>/MATLAB Function1' */

/* TODO */
real32_T sinfixtrq;                    /* '<S2>/sin ' */

/* TODO */
real32_T sinwave;                      /* '<S2>/MATLAB Function4' */

/* TODO */
real32_T total_fixtrq;                 /* '<S2>/Gain' */

/* TODO */
real32_T wave_P1;                      /* '<S2>/MATLAB Function2' */

/* TODO */

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
void FOCSpdTrq_step(void)
{
  real32_T asrKiHi;
  real32_T asrKiLo;
  real32_T asr_rpm_Hi;
  real32_T asr_rpm_Lo;
  real32_T err_thresh_high_0;
  real32_T rtb_Abs1;
  real32_T rtb_Divide1;
  real32_T rtb_Divide2;
  real32_T rtb_Sum1;
  real32_T rtb_Switch_d;
  real32_T rtb_UnitDelay;

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S3>/Constant5'
   *  Inport: '<Root>/f32_SpeedAct_rpm'
   *  Product: '<S22>/Product1'
   *  Product: '<S22>/Product3'
   *  UnitDelay: '<S22>/Unit Delay1'
   */
  rtb_Sum1 = (GRSU.f32_SpeedAct_rpm * 0.0015F) + (GRSDWork.UnitDelay1_DSTATE *
    0.9985F);

  /* Abs: '<S3>/Abs1' */
  profileStart_FOCSpdTrq(1U); /* original_line:186 */rtb_Abs1 = fabsf(rtb_Sum1);profileEnd_FOCSpdTrq(1U); /* original_line:186 */

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant11'
   *  Constant: '<S3>/Constant8'
   */
  if (g_msgCore0to2_CalibEn2) {
    rtb_Divide1 = g_msgCore0to2_maxCur2;
  } else {
    rtb_Divide1 = g_msgCore0to2_maxTrq2;
  }

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant9'
   *  Switch: '<S3>/Switch'
   */
  rtb_Switch_d = rtb_Divide1 / 3000.0F;

  /* Product: '<S3>/Divide1' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  rtb_Divide1 = g_msgCore0to2_AsrKpHi * rtb_Switch_d;

  /* Product: '<S3>/Divide2' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  rtb_Divide2 = g_msgCore0to2_AsrKpLo * rtb_Switch_d;

  /* UnitDelay: '<S1>/Unit Delay' */
  rtb_UnitDelay = GRSDWork.UnitDelay_DSTATE;

  /* Product: '<S3>/Divide3' incorporates:
   *  Constant: '<S3>/Constant12'
   */
  rtb_Switch_d *= g_msgCore0to2_AsrKpZero;

  /* MATLAB Function: '<S3>/AsrPI' incorporates:
   *  Constant: '<S3>/Constant13'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant6'
   *  Constant: '<S3>/Constant7'
   *  Inport: '<Root>/Ts'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  /*  */
  /* MATLAB Function 'Subsystem/Subsystem1/AsrPI': '<S21>:1' */
  /* '<S21>:1:3' if TiHi == single(0) */
  if (g_msgCore0to2_AsrTiHi == 0.0F) {
    /* '<S21>:1:4' asrKiHi = single(0); */
    asrKiHi = 0.0F;
  } else {
    /* '<S21>:1:5' else */
    /* '<S21>:1:6' asrKiHi = KpHi*Ts/TiHi; */
    asrKiHi = (rtb_Divide1 * GRSU.Ts) / g_msgCore0to2_AsrTiHi;
  }

  /* '<S21>:1:9' if TiLo == single(0) */
  if (g_msgCore0to2_AsrTiLo == 0.0F) {
    /* '<S21>:1:10' asrKiLo = single(0); */
    asrKiLo = 0.0F;
  } else {
    /* '<S21>:1:11' else */
    /* '<S21>:1:12' asrKiLo = KpLo*Ts/TiLo; */
    asrKiLo = (rtb_Divide2 * GRSU.Ts) / g_msgCore0to2_AsrTiLo;
  }

  /* '<S21>:1:15' if rpm_Hi >= rpm_Lo */
  if (g_msgCore0to2_AsrSwtHiRpm >= g_msgCore0to2_AsrSwtLoRpm) {
    /* '<S21>:1:16' asr_rpm_Hi = rpm_Hi; */
    asr_rpm_Hi = g_msgCore0to2_AsrSwtHiRpm;

    /* '<S21>:1:17' asr_rpm_Lo = rpm_Lo; */
    asr_rpm_Lo = g_msgCore0to2_AsrSwtLoRpm;
  } else {
    /* '<S21>:1:18' else */
    /* '<S21>:1:19' asr_rpm_Hi = rpm_Lo; */
    asr_rpm_Hi = g_msgCore0to2_AsrSwtLoRpm;

    /* '<S21>:1:20' asr_rpm_Lo = rpm_Hi; */
    asr_rpm_Lo = g_msgCore0to2_AsrSwtHiRpm;
  }

  /* '<S21>:1:23' if fdb >= asr_rpm_Hi */
  if (rtb_Abs1 >= asr_rpm_Hi) {
    /* '<S21>:1:24' Kp = KpHi; */
    FOC_Kp = rtb_Divide1;

    /* '<S21>:1:25' Ki = asrKiHi; */
    FOC_Ki = asrKiHi;
  } else if (rtb_Abs1 <= asr_rpm_Lo) {
    /* '<S21>:1:26' elseif fdb <= asr_rpm_Lo */
    /* '<S21>:1:27' Kp = KpLo; */
    FOC_Kp = rtb_Divide2;

    /* '<S21>:1:28' Ki = asrKiLo; */
    FOC_Ki = asrKiLo;
  } else {
    /* '<S21>:1:29' else */
    /* '<S21>:1:30' Kp = (KpHi - KpLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + KpLo; */
    rtb_Abs1 -= asr_rpm_Lo;
    asr_rpm_Hi -= asr_rpm_Lo;
    FOC_Kp = (((rtb_Divide1 - rtb_Divide2) * rtb_Abs1) / asr_rpm_Hi) +
      rtb_Divide2;

    /* '<S21>:1:31' Ki = (asrKiHi - asrKiLo)*(fdb - asr_rpm_Lo)/(asr_rpm_Hi - asr_rpm_Lo) + asrKiLo; */
    FOC_Ki = (((asrKiHi - asrKiLo) * rtb_Abs1) / asr_rpm_Hi) + asrKiLo;
  }

  /* '<S21>:1:34' if (ref == 0) && (ref_1 ==0) */
  if ((rtb_UnitDelay == 0.0F) && (GRSDWork.UnitDelay_DSTATE_e == 0.0F)) {
    /* '<S21>:1:35' Kp = KpZero; */
    FOC_Kp = rtb_Switch_d;

    /* '<S21>:1:36' Ki = KpZero*Ts/TiZero; */
    FOC_Ki = (rtb_Switch_d * GRSU.Ts) / g_msgCore0to2_AsrTiZero;
  }

  /* End of MATLAB Function: '<S3>/AsrPI' */

  /* MinMax: '<S1>/Max' incorporates:
   *  Constant: '<S1>/Constant8'
   *  Inport: '<Root>/TrqMax'
   */
  profileStart_FOCSpdTrq(2U); /* original_line:311 */rtb_Abs1 = fminf(GRSU.TrqMax, g_msgCore0to2_maxTrq2);profileEnd_FOCSpdTrq(2U); /* original_line:311 */

  /* MinMax: '<S1>/Max1' incorporates:
   *  Constant: '<S1>/Constant8'
   *  Gain: '<S1>/Gain4'
   *  Inport: '<Root>/TrqMin'
   */
  profileStart_FOCSpdTrq(3U); /* original_line:318 */rtb_Divide1 = fmaxf(-g_msgCore0to2_maxTrq2, GRSU.TrqMin);profileEnd_FOCSpdTrq(3U); /* original_line:318 */

  /* Outputs for Enabled SubSystem: '<S1>/Torque Control' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* RelationalOperator: '<S1>/Equal2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/ControlMode'
   */
  if (GRSU.ControlMode == TrqCtrl) {
    if (!GRSDWork.TorqueControl_MODE) {
      /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_n = 0.0F;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_l = 0.0F;
      GRSDWork.TorqueControl_MODE = true;
    }

    /* Sum: '<S4>/Subtract1' incorporates:
     *  Inport: '<Root>/f32_TorqueCmd_Nm'
     */
    asrKiHi = rtb_Divide1 - GRSU.f32_TorqueCmd_Nm;

    /* MATLAB Function: '<S25>/MATLAB Function' incorporates:
     *  Constant: '<S25>/Constant1'
     *  Constant: '<S4>/Constant'
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  UnitDelay: '<S25>/Unit Delay'
     */
    rtb_Switch_d = GRSDWork.UnitDelay_DSTATE_n;

    /* MATLAB Function 'Subsystem/Torque Control/SpdPosLimit/MATLAB Function': '<S27>:1' */
    /* '<S27>:1:2' err = ref - act; */
    rtb_Divide2 = f32_P_SpdPoslimit_rpm - GRSU.f32_SpeedAct_rpm;

    /* '<S27>:1:3' temp = err*kp; */
    /* '<S27>:1:4' out = temp + intg; */
    err_thresh_high_0 = (rtb_Divide2 * FOC_Kp) + GRSDWork.UnitDelay_DSTATE_n;

    /* '<S27>:1:5' if(out>MAX) */
    if (err_thresh_high_0 > 0.0F) {
      /* '<S27>:1:6' out = MAX; */
      err_thresh_high_0 = 0.0F;

      /* '<S27>:1:7' if(err<0) */
      if (rtb_Divide2 < 0.0F) {
        /* '<S27>:1:8' intg = intg + ki*err; */
        rtb_Switch_d = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_n;
      }
    } else if (err_thresh_high_0 < asrKiHi) {
      /* '<S27>:1:10' elseif(out < MIN) */
      /* '<S27>:1:11' out = MIN; */
      err_thresh_high_0 = asrKiHi;

      /* '<S27>:1:12' if(err>0) */
      if (rtb_Divide2 > 0.0F) {
        /* '<S27>:1:13' intg = intg + ki*err; */
        rtb_Switch_d = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_n;
      }
    } else {
      /* '<S27>:1:15' else */
      /* '<S27>:1:16' intg = intg + ki*err; */
      rtb_Switch_d = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_n;
    }

    /* Sum: '<S4>/Subtract' incorporates:
     *  Inport: '<Root>/f32_TorqueCmd_Nm'
     */
    /* '<S27>:1:18' max(intg,MIN); */
    /* '<S27>:1:19' min(intg,MAX); */
    asrKiLo = rtb_Abs1 - GRSU.f32_TorqueCmd_Nm;

    /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
     *  Constant: '<S24>/Constant1'
     *  Constant: '<S4>/Constant1'
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  UnitDelay: '<S24>/Unit Delay'
     */
    asrKiHi = GRSDWork.UnitDelay_DSTATE_l;

    /* MATLAB Function 'Subsystem/Torque Control/SpdNegLimit/MATLAB Function': '<S26>:1' */
    /* '<S26>:1:3' err = ref - act; */
    rtb_Divide2 = f32_P_SpdNeglimit_rpm - GRSU.f32_SpeedAct_rpm;

    /* '<S26>:1:4' temp = err*kp; */
    /* '<S26>:1:5' out = temp + intg; */
    asr_rpm_Hi = (rtb_Divide2 * FOC_Kp) + GRSDWork.UnitDelay_DSTATE_l;

    /* '<S26>:1:6' if(out>MAX) */
    if (asr_rpm_Hi > asrKiLo) {
      /* '<S26>:1:7' out = MAX; */
      asr_rpm_Hi = asrKiLo;

      /* '<S26>:1:8' if(err<0) */
      if (rtb_Divide2 < 0.0F) {
        /* '<S26>:1:9' intg = intg + ki*err; */
        asrKiHi = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_l;
      }
    } else if (asr_rpm_Hi < 0.0F) {
      /* '<S26>:1:11' elseif(out < MIN) */
      /* '<S26>:1:12' out = MIN; */
      asr_rpm_Hi = 0.0F;

      /* '<S26>:1:13' if(err>0) */
      if (rtb_Divide2 > 0.0F) {
        /* '<S26>:1:14' intg = intg + ki*err; */
        asrKiHi = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_l;
      }
    } else {
      /* '<S26>:1:16' else */
      /* '<S26>:1:17' intg = intg + ki*err; */
      asrKiHi = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_l;
    }

    /* Sum: '<S4>/Add' incorporates:
     *  Inport: '<Root>/f32_TorqueCmd_Nm'
     *  MATLAB Function: '<S24>/MATLAB Function'
     *  MATLAB Function: '<S25>/MATLAB Function'
     */
    /* '<S26>:1:19' max(intg,MIN); */
    /* '<S26>:1:20' min(intg,MAX); */
    rtb_Divide2 = (err_thresh_high_0 + GRSU.f32_TorqueCmd_Nm) + asr_rpm_Hi;

    /* Switch: '<S23>/Switch2' incorporates:
     *  RelationalOperator: '<S23>/LowerRelop1'
     *  RelationalOperator: '<S23>/UpperRelop'
     *  Switch: '<S23>/Switch'
     */
    if (rtb_Divide2 > rtb_Abs1) {
      /* Switch: '<S23>/Switch2' */
      GRSDWork.Switch2 = rtb_Abs1;
    } else if (rtb_Divide2 < rtb_Divide1) {
      /* Switch: '<S23>/Switch' incorporates:
       *  Switch: '<S23>/Switch2'
       */
      GRSDWork.Switch2 = rtb_Divide1;
    } else {
      /* Switch: '<S23>/Switch2' incorporates:
       *  Switch: '<S23>/Switch'
       */
      GRSDWork.Switch2 = rtb_Divide2;
    }

    /* End of Switch: '<S23>/Switch2' */

    /* Update for UnitDelay: '<S25>/Unit Delay' incorporates:
     *  MATLAB Function: '<S25>/MATLAB Function'
     */
    GRSDWork.UnitDelay_DSTATE_n = rtb_Switch_d;

    /* Update for UnitDelay: '<S24>/Unit Delay' incorporates:
     *  MATLAB Function: '<S24>/MATLAB Function'
     */
    GRSDWork.UnitDelay_DSTATE_l = asrKiHi;
  } else if (GRSDWork.TorqueControl_MODE) {
    /* Disable for Switch: '<S23>/Switch2' incorporates:
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
    real_T tmp;
    real32_T b_tmp;
    real32_T err;
    real32_T err_abs;
    real32_T err_abs_tmp;
    real32_T err_thresh_high_tmp;
    real32_T err_thresh_low_0;
    real32_T err_thresh_low_tmp;
    real32_T rtb_Switch1;
    real32_T rtb_Switch2;
    if (!GRSDWork.SpeedControl_MODE) {
      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
      GRSDWork.UnitDelay1_DSTATE_o = 0.0F;

      /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_h = 0.0F;

      /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_m = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
      GRSDWork.UnitDelay_DSTATE_o = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
      GRSDWork.UnitDelay2_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
      GRSDWork.UnitDelay1_DSTATE_g = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay5' */
      GRSDWork.UnitDelay5_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay3' */
      GRSDWork.UnitDelay3_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay4' */
      GRSDWork.UnitDelay4_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S12>/Unit Delay1' */
      GRSDWork.UnitDelay1_DSTATE_l = 0.0F;

      /* InitializeConditions for UnitDelay: '<S13>/Unit Delay1' */
      GRSDWork.UnitDelay1_DSTATE_a = 0.0F;

      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay6' */
      GRSDWork.UnitDelay6_DSTATE = 0.0F;
      GRSDWork.SpeedControl_MODE = true;
    }

    /* Product: '<S2>/Product1' incorporates:
     *  Constant: '<S2>/Constant7'
     *  Constant: '<S2>/Constant8'
     *  DataTypeConversion: '<S2>/Data Type Conversion2'
     *  Inport: '<Root>/Angle'
     *  Sum: '<S2>/Add1'
     */
    rtb_Switch_d = ((real32_T)((uint16_T)(GRSU.Angle + 32767))) * 9.58752644E-5F;

    /* MATLAB Function: '<S2>/sin ' incorporates:
     *  Constant: '<S2>/Constant23'
     *  Constant: '<S2>/Constant24'
     *  Constant: '<S2>/Constant25'
     */
    /* MATLAB Function 'Subsystem/Speed Control/sin ': '<S19>:1' */
    /* '<S19>:1:4' out = A*sin(B*D+C); */
    profileStart_FOCSpdTrq(4U); /* original_line:559 */sinfixtrq = sinf((g_msgCore0to2_sin_frq * rtb_Switch_d) +
                     g_msgCore0to2_sin_phase) * g_msgCore0to2_sin_Amp;profileEnd_FOCSpdTrq(4U); /* original_line:560 */

    /* MATLAB Function: '<S2>/cos' incorporates:
     *  Constant: '<S2>/Constant26'
     *  Constant: '<S2>/Constant27'
     *  Constant: '<S2>/Constant28'
     */
    /* MATLAB Function 'Subsystem/Speed Control/cos': '<S18>:1' */
    /* '<S18>:1:4' out = A*cos(B*D+C); */
    profileStart_FOCSpdTrq(5U); /* original_line:569 */cosfixtrq = cosf((g_msgCore0to2_cos_frq * rtb_Switch_d) +
                     g_msgCore0to2_cos_phase) * g_msgCore0to2_cos_Amp;profileEnd_FOCSpdTrq(5U); /* original_line:570 */

    /* Gain: '<S2>/Gain' incorporates:
     *  Sum: '<S2>/Add5'
     */
    total_fixtrq = (sinfixtrq + cosfixtrq) * g_msgCore0to2_frqfix_K;

    /* Switch: '<S2>/Switch5' incorporates:
     *  Constant: '<S2>/Constant11'
     */
    if (g_msgCore0to2_Trqfix) {
      /* Switch: '<S2>/Switch5' */
      comp_P1 = total_fixtrq;
    } else {
      /* Switch: '<S2>/Switch5' incorporates:
       *  Constant: '<S2>/Constant10'
       */
      comp_P1 = 0.0F;
    }

    /* End of Switch: '<S2>/Switch5' */

    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant2'
     *  RelationalOperator: '<S2>/Equal'
     */
    if (GRSU.ControlMode == alOfsCal) {
      /* Outport: '<Root>/speedref' incorporates:
       *  Inport: '<Root>/SpdDes'
       */
      GRSY.speedref = GRSU.SpdDes;
    } else {
      /* Outport: '<Root>/speedref' incorporates:
       *  Gain: '<S2>/Gain1'
       *  Inport: '<Root>/f32_Speedref_rpm'
       */
      GRSY.speedref = 12.0F * GRSU.f32_Speedref_rpm;
    }

    /* End of Switch: '<S2>/Switch' */

    /* Sum: '<S20>/Sum1' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S15>/Constant2'
     *  Inport: '<Root>/isdSet_last'
     *  MinMax: '<S15>/Max'
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     *  Product: '<S20>/Product1'
     *  Product: '<S20>/Product3'
     *  Sqrt: '<S15>/Sqrt'
     *  Sum: '<S15>/Subtract'
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    profileStart_FOCSpdTrq(6U); /* original_line:625 */asrKiHi = (sqrtf(fmaxf(0.0F, (g_msgCore0to2_maxCur2 * g_msgCore0to2_maxCur2)
      - (GRSU.isdSet_last * GRSU.isdSet_last))) * 0.1F) +
      (GRSDWork.UnitDelay1_DSTATE_o * 0.9F);profileEnd_FOCSpdTrq(6U); /* original_line:627 */

    /* Sum: '<S17>/Plus' incorporates:
     *  Constant: '<S17>/Constant'
     *  Product: '<S17>/Product'
     *  Product: '<S17>/Product1'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    asrKiLo = (GRSDWork.UnitDelay_DSTATE_h * 0.9F) + (0.1F * rtb_Abs1);

    /* Sum: '<S16>/Plus' incorporates:
     *  Constant: '<S16>/Constant'
     *  Product: '<S16>/Product'
     *  Product: '<S16>/Product1'
     *  UnitDelay: '<S16>/Unit Delay'
     */
    asr_rpm_Hi = (GRSDWork.UnitDelay_DSTATE_m * 0.9F) + (0.1F * rtb_Divide1);

    /* Switch: '<S2>/Switch1' incorporates:
     *  Abs: '<S15>/Abs1'
     *  Abs: '<S15>/Abs2'
     *  Abs: '<S15>/Abs3'
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant3'
     *  Constant: '<S15>/Constant4'
     *  Constant: '<S15>/Constant5'
     *  Constant: '<S15>/Constant6'
     *  Constant: '<S2>/Constant'
     *  Gain: '<S15>/Gain1'
     *  Inport: '<Root>/SpeedPiMaxRatio'
     *  Inport: '<Root>/SpeedPiMinRatio'
     *  MinMax: '<S15>/Max1'
     *  MinMax: '<S15>/Max2'
     *  MinMax: '<S15>/Max3'
     *  MinMax: '<S15>/Max4'
     *  Product: '<S15>/Product2'
     *  Product: '<S15>/Product3'
     *  Switch: '<S2>/Switch2'
     */
    if (g_msgCore0to2_CalibEn2) {
      profileStart_FOCSpdTrq(7U); /* original_line:667 */rtb_Switch1 = fminf(fminf(fminf(f32_P_SpeedPiMaxRatio, 1.0F), fabsf
        (GRSU.SpeedPiMaxRatio)) * g_msgCore0to2_maxCur2, asrKiHi);profileEnd_FOCSpdTrq(7U); /* original_line:668 */
      profileStart_FOCSpdTrq(8U); /* original_line:669 */rtb_Switch2 = -fminf(asrKiHi, g_msgCore0to2_maxCur2 * fminf(fminf(fabsf
        (f32_P_SpeedPiMinRatio), 1.0F), fabsf(GRSU.SpeedPiMinRatio)));profileEnd_FOCSpdTrq(8U); /* original_line:670 */
    } else {
      rtb_Switch1 = asrKiLo;
      rtb_Switch2 = asr_rpm_Hi;
    }

    /* End of Switch: '<S2>/Switch1' */

    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  MATLAB Function: '<S2>/MATLAB Function1'
     *  MATLAB Function: '<S2>/MATLAB Function3'
     *  Outport: '<Root>/speedref'
     *  Sum: '<S2>/Add4'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    Asrintgin_value = GRSDWork.UnitDelay_DSTATE_o;

    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function': '<S5>:1' */
    /* '<S5>:1:2' err = (ref - act); */
    rtb_Divide2 = GRSY.speedref - GRSU.f32_SpeedAct_rpm;

    /* 去除系数 */
    /* '<S5>:1:3' Kp_value = err*kp; */
    /* '<S5>:1:5' temp = err*kp; */
    /* '<S5>:1:6' out = temp + intgin; */
    err_thresh_high_0 = (rtb_Divide2 * FOC_Kp) + GRSDWork.UnitDelay_DSTATE_o;

    /* '<S5>:1:9' if(out>MAX) */
    if (err_thresh_high_0 > rtb_Switch1) {
      /* '<S5>:1:10' out = MAX; */
      err_thresh_high_0 = rtb_Switch1;

      /* DataTypeConversion: '<S2>/Data Type Conversion5' */
      /* '<S5>:1:11' Anti_wind_signal =single(0); */
      AntiWindup_Signal = 0.0F;

      /* '<S5>:1:12' if(err<0) */
      if (rtb_Divide2 < 0.0F) {
        /* '<S5>:1:13' intgin = intgin + ki*err; */
        Asrintgin_value = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_o;

        /* DataTypeConversion: '<S2>/Data Type Conversion5' */
        /* '<S5>:1:14' Anti_wind_signal =single(1); */
        AntiWindup_Signal = 1.0F;
      }
    } else if (err_thresh_high_0 < rtb_Switch2) {
      /* '<S5>:1:16' elseif(out < MIN) */
      /* '<S5>:1:17' out = MIN; */
      err_thresh_high_0 = rtb_Switch2;

      /* DataTypeConversion: '<S2>/Data Type Conversion5' */
      /* '<S5>:1:18' Anti_wind_signal =single(0); */
      AntiWindup_Signal = 0.0F;

      /* '<S5>:1:20' if(err>0) */
      if (rtb_Divide2 > 0.0F) {
        /* '<S5>:1:21' intgin = intgin + ki*err; */
        Asrintgin_value = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_o;

        /* DataTypeConversion: '<S2>/Data Type Conversion5' */
        /* '<S5>:1:22' Anti_wind_signal =single(1); */
        AntiWindup_Signal = 1.0F;
      }
    } else {
      /* '<S5>:1:24' else */
      /* '<S5>:1:25' intgin = intgin + ki*err; */
      Asrintgin_value = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay_DSTATE_o;

      /* DataTypeConversion: '<S2>/Data Type Conversion5' */
      /* '<S5>:1:26' Anti_wind_signal =single(0); */
      AntiWindup_Signal = 0.0F;
    }

    /* '<S5>:1:28' max(intgin,MIN); */
    /* '<S5>:1:29' min(intgin,MAX); */
    /* '<S5>:1:30' intgout = intgin; */
    PIout = err_thresh_high_0;

    /* MATLAB Function: '<S2>/MATLAB Function3' incorporates:
     *  Constant: '<S2>/Constant15'
     *  Constant: '<S2>/Constant18'
     *  Constant: '<S2>/Constant19'
     *  Constant: '<S2>/Constant20'
     *  Constant: '<S2>/Constant29'
     *  Constant: '<S2>/Constant31'
     *  Constant: '<S2>/Constant32'
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     *  Inport: '<Root>/f32_speedfinal'
     *  MATLAB Function: '<S2>/MATLAB Function'
     *  MATLAB Function: '<S2>/MATLAB Function1'
     *  UnitDelay: '<S2>/Unit Delay2'
     */
    PDFF_Kvp_coef = g_msgCore0to2_Kvp;
    FFintgin_value = GRSDWork.UnitDelay2_DSTATE;

    /* %%%%%%%%%%% KVP取值约为0.001-0.005  */
    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function3': '<S8>:1' */
    /* '<S8>:1:3' err = (ref - act); */
    /* 去除系数 */
    /* '<S8>:1:4' temp = err*kp; */
    b_tmp = rtb_Divide2 * FOC_Kp;

    /* PDFF要折算 */
    /* '<S8>:1:9' err_thresh_high = speedfinal *Hcoef ; */
    err_thresh_high_tmp = GRSU.f32_speedfinal * g_msgCore0to2_H_coef;

    /* '<S8>:1:10' err_thresh_low = speedfinal * Lcoef; */
    err_thresh_low_tmp = GRSU.f32_speedfinal * g_msgCore0to2_L_coef;

    /* '<S8>:1:11' err_abs = abs(err); */
    profileStart_FOCSpdTrq(9U); /* original_line:781 */err_abs_tmp = fabsf(rtb_Divide2);profileEnd_FOCSpdTrq(9U); /* original_line:781 */

    /* '<S8>:1:12' if(err_abs > err_thresh_high) */
    if (err_abs_tmp > err_thresh_high_tmp) {
      /* '<S8>:1:13' alpha = single(alphaLow); */
      err_abs = g_msgCore0to2_alphaLow;

      /*  大误差：不能完全关积分 */
    } else if (err_abs_tmp < err_thresh_low_tmp) {
      /* '<S8>:1:14' elseif(err_abs < err_thresh_low) */
      /* '<S8>:1:15' alpha = single(1.0); */
      err_abs = 1.0F;

      /*  小误差：全开积分 */
    } else {
      /* '<S8>:1:16' else */
      /*  线性平滑过渡，彻底消除开关抖动 */
      /* '<S8>:1:18' alpha = single(((err_thresh_high - err_abs)*(single(1.0)-single(alphaLow)))/(err_thresh_high - err_thresh_low)) +  single(alphaLow) ; */
      err_abs = (((err_thresh_high_tmp - err_abs_tmp) * (1.0F -
        g_msgCore0to2_alphaLow)) / (err_thresh_high_tmp - err_thresh_low_tmp)) +
        g_msgCore0to2_alphaLow;
    }

    /* '<S8>:1:22' PDFF_high =  single(7000)*HFcoef ; */
    err_thresh_high_0 = 7000.0F * g_msgCore0to2_HFcoef;

    /* '<S8>:1:23' PDFF_low = single(7000)* LFcoef; */
    err_thresh_low_0 = 7000.0F * g_msgCore0to2_LFcoef;

    /* '<S8>:1:25' if(abs(speedfinal) >PDFF_high) */
    profileStart_FOCSpdTrq(10U); /* original_line:811 */asr_rpm_Lo = fabsf(GRSU.f32_speedfinal);profileEnd_FOCSpdTrq(10U); /* original_line:811 */
    if (asr_rpm_Lo > err_thresh_high_0) {
      /* 如果转速大于某个值 */
      /* '<S8>:1:26' beta = single(betaLow); */
      err_thresh_low_0 = g_msgCore0to2_betaLow;

      /* 要缩小PDFF系数 */
      /* '<S8>:1:27' beta_signal =single(0); */
      beta_signal = 0.0F;
    } else if (asr_rpm_Lo < err_thresh_low_0) {
      /* '<S8>:1:28' elseif(abs(speedfinal) < PDFF_low) */
      /* 如果小于某个值，保持不变  这样在低速下可以用较大的pdff系数 */
      /* '<S8>:1:29' beta = single(1.0); */
      err_thresh_low_0 = 1.0F;

      /* '<S8>:1:30' beta_signal =single(1); */
      beta_signal = 1.0F;
    } else {
      /* '<S8>:1:31' else */
      /*  线性平滑过渡，彻底消除开关抖动 */
      /* '<S8>:1:33' beta = single(((PDFF_high - abs(speedfinal))*(single(1.0)-single(betaLow)))/(PDFF_high - PDFF_low)) +  single(betaLow) ; */
      err_thresh_low_0 = (((err_thresh_high_0 - asr_rpm_Lo) * (1.0F -
        g_msgCore0to2_betaLow)) / (err_thresh_high_0 - err_thresh_low_0)) +
        g_msgCore0to2_betaLow;

      /* '<S8>:1:34' beta_signal =single(2); */
      beta_signal = 2.0F;
    }

    /* Kvp = kp *Kvp_coef*beta; */
    /* '<S8>:1:39' Kvp = kp *Kvp_coef*beta; */
    /* '<S8>:1:40' temp1=Kvp*act; */
    err = ((FOC_Kp * PDFF_Kvp_coef) * err_thresh_low_0) * GRSU.f32_SpeedAct_rpm;

    /* '<S8>:1:41' out = temp + intgin-temp1; */
    err_thresh_high_0 = (b_tmp + GRSDWork.UnitDelay2_DSTATE) - err;

    /* '<S8>:1:44' if(out>MAX) */
    if (err_thresh_high_0 > rtb_Switch1) {
      /* '<S8>:1:45' out = MAX; */
      err_thresh_high_0 = rtb_Switch1;

      /* '<S8>:1:46' if(err<0) */
      if (rtb_Divide2 < 0.0F) {
        /* '<S8>:1:47' intgin = intgin + ki*err; */
        FFintgin_value = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay2_DSTATE;
      }
    } else if (err_thresh_high_0 < rtb_Switch2) {
      /* '<S8>:1:49' elseif(out < MIN) */
      /* '<S8>:1:50' out = MIN; */
      err_thresh_high_0 = rtb_Switch2;

      /* '<S8>:1:51' if(err>0) */
      if (rtb_Divide2 > 0.0F) {
        /* '<S8>:1:52' intgin = intgin + ki*err; */
        FFintgin_value = (FOC_Ki * rtb_Divide2) + GRSDWork.UnitDelay2_DSTATE;
      }
    } else {
      /* '<S8>:1:54' else */
      /* '<S8>:1:55' intgin = intgin + alpha*ki*err; */
      FFintgin_value = ((err_abs * FOC_Ki) * rtb_Divide2) +
        GRSDWork.UnitDelay2_DSTATE;

      /* intgin = intgin + ki*err; */
    }

    /* ----------------------------------------------------------------------------% */
    /* '<S8>:1:61' max(intgin,MIN); */
    /* '<S8>:1:62' min(intgin,MAX); */
    /* '<S8>:1:63' intgout = intgin; */
    FFout = err_thresh_high_0;
    FFKp_value = b_tmp;
    PDFF_SpdrefMuxKff = err;
    alpha = err_abs;
    beta = err_thresh_low_0;

    /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
     *  UnitDelay: '<S2>/Unit Delay1'
     */
    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function1': '<S6>:1' */
    /* '<S6>:1:2' err = (ref - act); */
    /* 去除系数 */
    /* '<S6>:1:3' Kp_value = err*kp; */
    /* '<S6>:1:5' temp = Kp_value + intgin; */
    err_abs = b_tmp + GRSDWork.UnitDelay1_DSTATE_g;

    /* '<S6>:1:7' if(temp>MAX) */
    if (err_abs > rtb_Switch1) {
      /* '<S6>:1:8' out = MAX; */
      rtb_Switch2 = rtb_Switch1;
    } else if (err_abs >= rtb_Switch2) {
      /* '<S6>:1:11' else */
      /* '<S6>:1:12' out = temp; */
      rtb_Switch2 = err_abs;
    } else {
      /* '<S6>:1:9' elseif(temp < MIN) */
      /* '<S6>:1:10' out = MIN; */
    }

    /* '<S6>:1:15' Anti_windup_coef = abs(temp -out); */
    profileStart_FOCSpdTrq(11U); /* original_line:911 */rtb_Switch1 = fabsf(err_abs - rtb_Switch2);profileEnd_FOCSpdTrq(11U); /* original_line:911 */

    /* '<S6>:1:17' err_thresh_high = speedfinal *Hcoef ; */
    /* '<S6>:1:18' err_thresh_low = speedfinal * Lcoef; */
    /* '<S6>:1:21' err_abs = abs(err); */
    /* '<S6>:1:22' if(err_abs > err_thresh_high) */
    if (err_abs_tmp > err_thresh_high_tmp) {
      /* '<S6>:1:23' alpha = single(0.0); */
      err_abs = 0.0F;

      /*  大误差：完全关积分 */
    } else if (err_abs_tmp < err_thresh_low_tmp) {
      /* '<S6>:1:24' elseif(err_abs < err_thresh_low) */
      /* '<S6>:1:25' alpha = single(1.0); */
      err_abs = 1.0F;

      /*  小误差：全开积分 */
    } else {
      /* '<S6>:1:26' else */
      /*  线性平滑过渡，彻底消除开关抖动 */
      /* '<S6>:1:28' alpha = single((err_thresh_high - err_abs)/(err_thresh_high - err_thresh_low)); */
      err_abs = (err_thresh_high_tmp - err_abs_tmp) / (err_thresh_high_tmp -
        err_thresh_low_tmp);
    }

    /* '<S6>:1:31' if(abs(speedfinal)<300) */
    if (asr_rpm_Lo < 300.0F) {
      /* '<S6>:1:32' alpha = single(1); */
      err_abs = 1.0F;
    }

    /* '<S6>:1:35' if(Anti_windup_coef > single(0)) */
    if (rtb_Switch1 > 0.0F) {
      /* '<S6>:1:36' intgin =  out - Kp_value; */
      AntiWindup_integral = rtb_Switch2 - b_tmp;
    } else {
      /* '<S6>:1:37' else */
      /* intgin = intgin + ki*err; */
      /* '<S6>:1:39' intgin = intgin + alpha * ki * err; */
      AntiWindup_integral = ((err_abs * FOC_Ki) * rtb_Divide2) +
        GRSDWork.UnitDelay1_DSTATE_g;
    }

    /*  max(intgin,MIN); */
    /*  min(intgin,MAX); */
    /* '<S6>:1:44' intgout = intgin; */
    AntiWindup_out = rtb_Switch2;
    AntiWindup_Kpvalue = b_tmp;
    err_thresh_high = err_thresh_high_tmp;
    err_thresh_low = err_thresh_low_tmp;
    AntiWindup_Alfa = err_abs;

    /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
     *  Constant: '<S2>/Constant16'
     */
    switch ((int32_T)g_msgCore0to2_Asrctrlmode) {
     case 1:
      rtb_Switch2 = PIout;
      break;

     case 2:
      rtb_Switch2 = FFout;
      break;

     default:
      rtb_Switch2 = AntiWindup_out;
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

    /* Gain: '<S2>/Gain3' incorporates:
     *  Outport: '<Root>/speedref'
     */
    R_wo = (g_msgCoreoto2_R_woGain / 60.0F) * GRSY.speedref;

    /* UnitDelay: '<S2>/Unit Delay3' */
    asr_rpm_Lo = GRSDWork.UnitDelay3_DSTATE;

    /* MATLAB Function: '<S2>/MATLAB Function6' incorporates:
     *  Constant: '<S2>/Constant33'
     *  Constant: '<S2>/Constant34'
     *  Constant: '<S2>/Constant37'
     *  UnitDelay: '<S2>/Unit Delay3'
     *  UnitDelay: '<S2>/Unit Delay4'
     *  UnitDelay: '<S2>/Unit Delay5'
     */
    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function6': '<S11>:1' */
    /* '<S11>:1:3' Ts = 1/16000; */
    /* '<S11>:1:5' b=(4+4*wc*Ts+w0^2*Ts^2); */
    err_thresh_high_0 = R_wo * R_wo;
    err_thresh_high_tmp = (4.0F * g_msgCore0to2_R_Wc) * 6.25E-5F;
    err_thresh_low_tmp = err_thresh_high_0 * 3.90625E-9F;
    err_abs = (err_thresh_high_tmp + 4.0F) + err_thresh_low_tmp;

    /* '<S11>:1:7' b0=(4*Kr*wc*Ts)/b; */
    /* '<S11>:1:8' b2=(-4*Kr*wc*Ts)/b; */
    /* '<S11>:1:9' a1=(2*w0^2*Ts^2-8)/b; */
    /* '<S11>:1:10' a2=(4-4*wc*Ts+w0^2*Ts^2)/b; */
    /* '<S11>:1:12' yk = b0*ek+b2*ek_2-a1*yk_1-a2*yk_2; */
    R_output = (((((((4.0F * g_msgCore0to2_R_Kr) * g_msgCore0to2_R_Wc) *
                    6.25E-5F) / err_abs) * rtb_Divide2) + (((((-4.0F *
      g_msgCore0to2_R_Kr) * g_msgCore0to2_R_Wc) * 6.25E-5F) / err_abs) *
      GRSDWork.UnitDelay5_DSTATE)) - (((((err_thresh_high_0 * 2.0F) *
      3.90625E-9F) - 8.0F) / err_abs) * GRSDWork.UnitDelay3_DSTATE)) - ((((4.0F
      - err_thresh_high_tmp) + err_thresh_low_tmp) / err_abs) *
      GRSDWork.UnitDelay4_DSTATE);

    /* '<S11>:1:17' out_limt = R_optLimt; */
    /* '<S11>:1:18' if yk>out_limt */
    if (R_output > g_msgCore0to2_R_Outputlimit) {
      /* '<S11>:1:19' yk=out_limt; */
      R_output = g_msgCore0to2_R_Outputlimit;
    } else if (R_output < (-g_msgCore0to2_R_Outputlimit)) {
      /* '<S11>:1:20' elseif yk<-out_limt */
      /* '<S11>:1:21' yk=-out_limt; */
      R_output = -g_msgCore0to2_R_Outputlimit;
    }

    /* End of MATLAB Function: '<S2>/MATLAB Function6' */

    /* Switch: '<S2>/Switch3' incorporates:
     *  Constant: '<S2>/Constant35'
     *  Constant: '<S2>/Constant36'
     */
    if (g_msgCore0to2_Rswitch) {
      tmp = R_output;
    } else {
      tmp = 0.0;
    }

    /* Gain: '<S2>/Gain4' incorporates:
     *  Switch: '<S2>/Switch3'
     */
    R_finaloutput = (real32_T)(g_msgCore0to2_R_outputGain * tmp);

    /* Sum: '<S2>/Add' */
    GRSDWork.Add = (comp_P1 + rtb_Switch2) + R_finaloutput;

    /* Sum: '<S2>/Add2' incorporates:
     *  Constant: '<S2>/Constant12'
     *  MinMax: '<S2>/Max2'
     */
    profileStart_FOCSpdTrq(12U); /* original_line:1054 */Trqcomp_Max_P1 = fminf(rtb_Abs1, g_msgCore0to2_maxTrq2) - PIout;profileEnd_FOCSpdTrq(12U); /* original_line:1054 */

    /* Sum: '<S2>/Add3' incorporates:
     *  Constant: '<S2>/Constant12'
     *  Gain: '<S2>/Gain2'
     *  MinMax: '<S2>/Max3'
     */
    profileStart_FOCSpdTrq(13U); /* original_line:1061 */Trqcomp_Min_P1 = fmaxf(-g_msgCore0to2_maxTrq2, rtb_Divide1) - PIout;profileEnd_FOCSpdTrq(13U); /* original_line:1061 */

    /* Lookup_n-D: '<S2>/Amplitude_Table' incorporates:
     *  Abs: '<S2>/Abs'
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     */
    profileStart_FOCSpdTrq(14U); /* original_line:1067 */K1_value_P1 = look1_iflf_pbinlca(fabsf(GRSU.f32_SpeedAct_rpm), (const
      real32_T *)&cripple_T_P1.bp1[0], (const real32_T *)&cripple_T_P1.tab[0],
      &GRSDWork.m_bpIndex, 14U);profileEnd_FOCSpdTrq(14U); /* original_line:1069 */

    /* Lookup_n-D: '<S2>/Amplitude_Table1' incorporates:
     *  Inport: '<Root>/f32_SpeedAct_rpm'
     */
    profileStart_FOCSpdTrq(15U); /* original_line:1074 */K3_value_P1 = look1_iflf_pbinlca(GRSU.f32_SpeedAct_rpm, (const real32_T *)
      &cphase_T_P1.bp1[0], (const real32_T *)&cphase_T_P1.tab[0],
      &GRSDWork.m_bpIndex_e, 32U);profileEnd_FOCSpdTrq(15U); /* original_line:1076 */

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  MATLAB Function: '<S2>/MATLAB Function1'
     */
    AntiWindup_coef = rtb_Switch1;

    /* DataTypeConversion: '<S2>/Data Type Conversion3' */
    AsrKp_Calvalue = b_tmp;

    /* MATLAB Function: '<S2>/MATLAB Function4' incorporates:
     *  Constant: '<S2>/Constant17'
     *  MATLAB Function: '<S2>/MATLAB Function5'
     */
    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function4': '<S9>:1' */
    /* '<S9>:1:4' out = sin(B*D); */
    rtb_Divide1 = g_msgCore0to2_sin_frq * rtb_Switch_d;
    sinwave = rtb_Divide1;
    profileStart_FOCSpdTrq(16U); /* original_line:1094 */sinwave = sinf(sinwave);profileEnd_FOCSpdTrq(16U); /* original_line:1094 */

    /* MATLAB Function: '<S2>/MATLAB Function5' */
    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function5': '<S10>:1' */
    /* '<S10>:1:2' out = cos(B*D); */
    coswave = rtb_Divide1;
    profileStart_FOCSpdTrq(17U); /* original_line:1100 */coswave = cosf(coswave);profileEnd_FOCSpdTrq(17U); /* original_line:1100 */

    /* Switch: '<S14>/Switch2' incorporates:
     *  RelationalOperator: '<S14>/LowerRelop1'
     *  RelationalOperator: '<S14>/UpperRelop'
     *  Switch: '<S14>/Switch'
     */
    if (K1_value_P1 > Trqcomp_Max_P1) {
      /* Switch: '<S14>/Switch2' */
      K1_Limitvalue_P1 = Trqcomp_Max_P1;
    } else if (K1_value_P1 < Trqcomp_Min_P1) {
      /* Switch: '<S14>/Switch' incorporates:
       *  Switch: '<S14>/Switch2'
       */
      K1_Limitvalue_P1 = Trqcomp_Min_P1;
    } else {
      /* Switch: '<S14>/Switch2' incorporates:
       *  Switch: '<S14>/Switch'
       */
      K1_Limitvalue_P1 = K1_value_P1;
    }

    /* End of Switch: '<S14>/Switch2' */

    /* Switch: '<S2>/Switch4' incorporates:
     *  Constant: '<S2>/Constant4'
     *  Constant: '<S2>/Constant9'
     */
    /* MATLAB Function 'Subsystem/Speed Control/MATLAB Function2': '<S7>:1' */
    /* '<S7>:1:4' out = A*sin(B*D+C); */
    if (g_msgCore0to2_K1switch) {
      rtb_Divide1 = K1_Limitvalue_P1;
    } else {
      rtb_Divide1 = g_msgCore0to2_K1;
    }

    /* Switch: '<S2>/Switch6' incorporates:
     *  Constant: '<S2>/Constant14'
     *  Constant: '<S2>/Constant6'
     */
    if (g_msgCore0to2_K3switch) {
      rtb_Abs1 = K3_value_P1;
    } else {
      rtb_Abs1 = g_msgCore0to2_K3;
    }

    /* MATLAB Function: '<S2>/MATLAB Function2' incorporates:
     *  Constant: '<S2>/Constant5'
     *  Switch: '<S2>/Switch4'
     *  Switch: '<S2>/Switch6'
     */
    profileStart_FOCSpdTrq(18U); /* original_line:1151 */wave_P1 = sinf((g_msgCore0to2_K2 * rtb_Switch_d) + rtb_Abs1) * rtb_Divide1;profileEnd_FOCSpdTrq(18U); /* original_line:1151 */

    /* Sum: '<S12>/Sum1' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S2>/Constant21'
     *  Product: '<S12>/Product1'
     *  Product: '<S12>/Product3'
     *  Product: '<S2>/Divide1'
     *  Sum: '<S12>/Subtract'
     *  UnitDelay: '<S12>/Unit Delay1'
     */
    LPFsinwave = ((sinwave * rtb_Divide2) * g_msgCore0to2_LPF_coef) + ((1.0F -
      g_msgCore0to2_LPF_coef) * GRSDWork.UnitDelay1_DSTATE_l);

    /* Sum: '<S13>/Sum1' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S2>/Constant22'
     *  Product: '<S13>/Product1'
     *  Product: '<S13>/Product3'
     *  Product: '<S2>/Divide2'
     *  Sum: '<S13>/Subtract'
     *  UnitDelay: '<S13>/Unit Delay1'
     */
    LPFcoswave = ((rtb_Divide2 * coswave) * g_msgCore0to2_LPF_coef) + ((1.0F -
      g_msgCore0to2_LPF_coef) * GRSDWork.UnitDelay1_DSTATE_a);

    /* Update for UnitDelay: '<S20>/Unit Delay1' */
    GRSDWork.UnitDelay1_DSTATE_o = asrKiHi;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    GRSDWork.UnitDelay_DSTATE_h = asrKiLo;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    GRSDWork.UnitDelay_DSTATE_m = asr_rpm_Hi;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    GRSDWork.UnitDelay_DSTATE_o = Asrintgin_value;

    /* Update for UnitDelay: '<S2>/Unit Delay2' */
    GRSDWork.UnitDelay2_DSTATE = FFintgin_value;

    /* Update for UnitDelay: '<S2>/Unit Delay1' */
    GRSDWork.UnitDelay1_DSTATE_g = AntiWindup_integral;

    /* Update for UnitDelay: '<S2>/Unit Delay5' incorporates:
     *  UnitDelay: '<S2>/Unit Delay6'
     */
    GRSDWork.UnitDelay5_DSTATE = GRSDWork.UnitDelay6_DSTATE;

    /* Update for UnitDelay: '<S2>/Unit Delay3' */
    GRSDWork.UnitDelay3_DSTATE = R_output;

    /* Update for UnitDelay: '<S2>/Unit Delay4' */
    GRSDWork.UnitDelay4_DSTATE = asr_rpm_Lo;

    /* Update for UnitDelay: '<S12>/Unit Delay1' */
    GRSDWork.UnitDelay1_DSTATE_l = LPFsinwave;

    /* Update for UnitDelay: '<S13>/Unit Delay1' */
    GRSDWork.UnitDelay1_DSTATE_a = LPFcoswave;

    /* Update for UnitDelay: '<S2>/Unit Delay6' */
    GRSDWork.UnitDelay6_DSTATE = rtb_Divide2;
  } else if (GRSDWork.SpeedControl_MODE) {
    /* Disable for Sum: '<S2>/Add' incorporates:
     *  Outport: '<S2>/TrqCmd '
     */
    GRSDWork.Add = 0.0F;

    /* Disable for Outport: '<Root>/speedref' incorporates:
     *  Outport: '<S2>/speedref'
     */
    GRSY.speedref = 0.0F;
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
    GRSY.TrqEmDes = GRSDWork.Add;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  GRSDWork.UnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  Outport: '<Root>/speedref'
   */
  GRSDWork.UnitDelay_DSTATE = GRSY.speedref;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  GRSDWork.UnitDelay_DSTATE_e = rtb_UnitDelay;
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
