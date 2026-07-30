/*
 * File: CDD_ISP.c
 *
 * Code generated for Simulink model 'CDD_ISP'.
 *
 * Model version                  : 1.238
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 20 08:50:47 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "CDD_ISP.h"
#include "rtwtypes.h"
#include "CDD_ISP_types.h"
#include <math.h>
#include "ECM.h"
#include "CDD_ISP_private.h"
#include "parameter.h"

int_T CDD_ISPpmsmfoc_rtGlobalTID[2];
const rtTimingBridge *CDD_ISPpmsmfoc_rtTimingBridge;

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
real32_T B;                            /* '<S3>/MATLAB Function1' */

/* TODO */
int16_T ISP_agRoughCal;                /* '<S3>/AlOfsCalPosSet' */

/* Rough Calibrated output offset rotor angle */
int16_T ISP_agRtrElec;                 /* '<S3>/AlOfsCalPosSet' */

/* Electric angle of rotor */
int16_T ISP_agRtrPoleTrans;            /* '<S3>/Product' */

/* Resolver electric angle transit to motor electric angle */
real32_T ISP_frqElec;                  /* '<S3>/Rate Transition10' */

/* Electric frequency of rotor */
real32_T ISP_frqElecCaln;              /* '<S11>/Sum1' */

/* Electric frequency of rotor by atan2 calculate */
real32_T ISP_iDcFlt;                   /* '<Root>/Constant2' */

/* Calculated Dc link current */
real32_T ISP_iPhaU;                    /* '<S7>/Switch2' */

/* U phase current, A */
real32_T ISP_iPhaV;                    /* '<S8>/Switch2' */

/* V phase current, A */
real32_T ISP_iPhaW;                    /* '<S9>/Switch2' */

/* W phase current, A */
real32_T ISP_lossTotalIGBT;            /* '<Root>/Constant1' */

/* Loss of IGBT */
real32_T ISP_n_test_notch;             /* '<S3>/MATLAB Function' */

/* TODO */
real32_T ISP_n_test_pp;                /* '<S3>/Data Type Conversion4' */

/* TODO */
real32_T ISP_speedref_final_wn;        /* '<S3>/Gain7' */

/* TODO */
real32_T ISP_tmpClnt;                  /* '<Root>/Constant3' */

/* Coolant temperature */
real32_T ISP_tmpMaxIGBT;               /* '<Root>/Constant' */

/* Tj of IGBT */
real32_T ISP_uDcFlt;                   /* '<S12>/Sum1' */

/* Filtered DC link voltage */
real32_T ISP_wElec;                    /* '<S3>/Rate Transition2' */

/* Electric frequency of rotor */
real32_T X111;                         /* '<S3>/Unit Delay4' */

/* TODO */
real32_T X222;                         /* '<S3>/Unit Delay5' */

/* TODO */
real32_T Y111;                         /* '<S3>/Unit Delay6' */

/* TODO */
real32_T Y222;                         /* '<S3>/Unit Delay7' */

/* TODO */
real32_T a1;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T a2;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T a3;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T b1;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T b2;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T b3;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T k1;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T k2;                           /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T omega_hat_K_1;                /* '<S5>/MATLAB Function' */

/* TODO */
real32_T temp1_111;                    /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T temp2_222;                    /* '<S3>/MATLAB Function1' */

/* TODO */
real32_T test2;                        /* '<S3>/Unit Delay3' */

/* TODO */
real32_T test8;                        /* '<S3>/Data Type Conversion2' */

/* TODO */
real32_T theta_hat_K_1;                /* '<S5>/MATLAB Function' */

/* TODO */
CDD_ISPpmsmfoc_rtMdlrefDWork_g CDD_ISPpmsmfoc_rtMdlrefDWork;

/* Block states (default storage) */
CDD_ISPpmsmfoc_rtDW_a CDD_ISPpmsmfoc_rtDWork;

/* System initialize for referenced model: 'CDD_ISP' */
void CDD_ISP_Init(void)
{
  /* Start for RateTransition: '<S3>/Rate Transition8' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition8 = 2730;

  /* Start for RateTransition: '<S3>/Rate Transition6' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition6 = 2730.0F;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition8' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition8_Buffer0 = 2730;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition6' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition6_Buffer0 = 2730.0F;

  /* '<S14>:1:22' reset = boolean(1); */
  /* '<S14>:1:23' times= uint8(0); */
  /* '<S14>:1:24' cnt = uint16(0); */
  /* '<S14>:1:25' tempofs = single(0); */
  /* '<S14>:1:26' tempU = single(0); */
  /* '<S14>:1:27' tempV = single(0); */
  /* '<S14>:1:28' tempW = single(0); */
  /* '<S14>:1:29' tempUU = single(0); */
  /* '<S14>:1:30' tempVV = single(0); */
  /* '<S14>:1:31' tempWW = single(0); */
  /* '<S14>:1:32' step = uint8(0); */
  /* '<S14>:1:33' Iddes = single(0); */
  /* '<S14>:1:34' Angle = single(0); */
  /* '<S14>:1:35' stAlOfsCaltemp = uint8(0); */
  /* '<S14>:1:36' agOffs_Caltemp_pos = single(0); */
  /* '<S14>:1:37' agOffs_Caltemp_neg = single(0); */
  /* '<S14>:1:38' tempV0 = single(0); */
  /* '<S15>:1:7' stRoughCalSetLast = uint8(0); */
  /* '<S15>:1:8' agRoughCal = int16(0); */
}

/* System reset for referenced model: 'CDD_ISP' */
void CDD_ISP_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE_n = 0;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_f = 0.0F;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition8' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition8_Buffer0 = 2730;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition6' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition6_Buffer0 = 2730.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_p = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay4' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay4_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay5' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay5_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay6' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay6_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay7' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay7_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay12' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay12_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay13' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay13_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay14' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay14_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay15' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay15_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE_j = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_d = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay3_DSTATE = 0.0F;

  /* SystemReset for MATLAB Function: '<S3>/AlOfsCalFun2' */
  /* '<S14>:1:22' reset = boolean(1); */
  /* '<S14>:1:23' times= uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.times = 0U;

  /* '<S14>:1:24' cnt = uint16(0); */
  CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

  /* '<S14>:1:25' tempofs = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

  /* '<S14>:1:26' tempU = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempU = 0.0F;

  /* '<S14>:1:27' tempV = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempV = 0.0F;

  /* '<S14>:1:28' tempW = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempW = 0.0F;

  /* '<S14>:1:29' tempUU = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempUU = 0.0F;

  /* '<S14>:1:30' tempVV = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempVV = 0.0F;

  /* '<S14>:1:31' tempWW = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempWW = 0.0F;

  /* '<S14>:1:32' step = uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.step = 0U;

  /* '<S14>:1:33' Iddes = single(0); */
  CDD_ISPpmsmfoc_rtDWork.Iddes = 0.0F;

  /* '<S14>:1:34' Angle = single(0); */
  CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;

  /* '<S14>:1:35' stAlOfsCaltemp = uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp = 0U;

  /* '<S14>:1:36' agOffs_Caltemp_pos = single(0); */
  CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_pos = 0.0F;

  /* '<S14>:1:37' agOffs_Caltemp_neg = single(0); */
  CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_neg = 0.0F;

  /* SystemReset for MATLAB Function: '<S3>/AlOfsCalPosSet' */
  /* '<S14>:1:38' tempV0 = single(0); */
  /* '<S15>:1:7' stRoughCalSetLast = uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.stRoughCalSetLast = 0U;

  /* '<S15>:1:8' agRoughCal = int16(0); */
  CDD_ISPpmsmfoc_rtDWork.agRoughCal = 0;

  /* SystemReset for MATLAB Function: '<S5>/MATLAB Function' */
  CDD_ISPpmsmfoc_rtDWork.reset_not_empty_ll = false;

  /* SystemReset for MATLAB Function: '<S3>/MATLAB Function1' */
  CDD_ISPpmsmfoc_rtDWork.reset_not_empty_e = false;

  /* SystemReset for MATLAB Function: '<S3>/MATLAB Function3' */
  CDD_ISPpmsmfoc_rtDWork.reset_not_empty = false;

  /* SystemReset for MATLAB Function: '<S3>/MATLAB Function' */
  CDD_ISPpmsmfoc_rtDWork.reset_not_empty_l = false;
}

/* Output and update for referenced model: 'CDD_ISP' */
void CDD_ISPTID0(const real32_T *u_PMC_Out_Core2_PMC_tiPerd, const uint16_T
                 *u_ACI_Out_Core2_SAQ_iPhaU, const uint16_T
                 *u_ACI_Out_Core2_SAQ_iPhaV, const uint16_T
                 *u_ACI_Out_Core2_SAQ_iPhaW, const int16_T
                 *u_ACI_Out_Core2_SAQ_rslvSinAmp, const real32_T
                 *u_ACI_Out_Core2_SAQ_HVU, const Sig10ms02ST *u_msgCore0to2_10ms,
                 const uint8_T *u_msgCore0to2_1ms_TCC_stRoughCalSet, const
                 int16_T *u_Angleoffset_Init, const real32_T *u_Uoffset, const
                 real32_T *u_Voffset, const real32_T *u_Woffset, Core2_ISP_Out
                 *y_ISP_Out, real32_T *y_Iddes, real32_T *y_ISP_nNotch, real32_T
                 *y_ISP_nNotch2)
{
  int_T tid = 0;
  real_T rtb_Divide1;
  int32_T tmp_0;
  real32_T a0;
  real32_T a0_tmp;
  real32_T b1_0;
  real32_T b1_tmp;
  real32_T b2_0;
  real32_T k1_0;
  real32_T k2_0;
  real32_T rtb_Abs1;
  real32_T rtb_DTC3;
  real32_T rtb_Gain1;
  real32_T rtb_ISC_wElec;
  real32_T rtb_UnitDelay12;
  real32_T rtb_UnitDelay14;
  real32_T rtb_UnitDelay14_tmp;
  real32_T rtb_UnitDelay2;
  real32_T temp2_tmp_tmp;
  int16_T rtb_agNegTrans;
  boolean_T rtb_Equal;

  /* DataTypeConversion: '<S1>/DTC3' */
  rtb_DTC3 = *u_ACI_Out_Core2_SAQ_rslvSinAmp;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant3'
   *  Sum: '<S5>/Minus'
   */
  if (rotatedirection_C <= 0) {
    rtb_DTC3 = 65535.0F - rtb_DTC3;
  }

  /* End of Switch: '<S5>/Switch' */

  /* DataTypeConversion: '<S5>/DTC8' */
  ISP_agRtrElecAtan2 = (int16_T)rtb_DTC3;

  /* Gain: '<S5>/Gain1' */
  rtb_Gain1 = 1.52587891E-5F * (*u_PMC_Out_Core2_PMC_tiPerd);

  /* Product: '<S5>/Divide2' incorporates:
   *  Constant: '<S5>/Constant7'
   */
  rtb_ISC_wElec = (*u_PMC_Out_Core2_PMC_tiPerd) * f32_SpeedFltCoef;

  /* Product: '<S5>/Divide1' incorporates:
   *  Constant: '<S5>/Constant6'
   */
  rtb_Divide1 = 1.0 / rtb_ISC_wElec;

  /* Product: '<S5>/Divide' incorporates:
   *  DataTypeConversion: '<S5>/DTC6'
   *  Sum: '<S5>/Add3'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_Gain1 *= (real32_T)((int16_T)(ISP_agRtrElecAtan2 -
    CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE_n));

  /* Saturate: '<S5>/Saturation' */
  if (rtb_Gain1 > 2000.0F) {
    rtb_Gain1 = 2000.0F;
  } else if (rtb_Gain1 < -2000.0F) {
    rtb_Gain1 = -2000.0F;
  }

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<S11>/Constant'
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product3'
   *  Saturate: '<S5>/Saturation'
   *  Sum: '<S11>/Subtract'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  ISP_frqElecCaln = ((real32_T)((1.0 - rtb_Divide1) *
    CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE)) + ((real32_T)(rtb_Gain1 *
    rtb_Divide1));

  /* Sum: '<S4>/sub' */
  rtb_ISC_wElec = ((real32_T)(*u_ACI_Out_Core2_SAQ_iPhaU)) - (*u_Uoffset);

  /* Product: '<S4>/mul' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C'
   */
  rtb_ISC_wElec *= facAdc2iPh_C;

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C2'
   *  Constant: '<S4>/IdcMaxMdl_C3'
   *  RelationalOperator: '<S7>/LowerRelop1'
   *  RelationalOperator: '<S7>/UpperRelop'
   *  Switch: '<S7>/Switch'
   */
  if (rtb_ISC_wElec > iPhaMax_C) {
    /* Switch: '<S7>/Switch2' */
    ISP_iPhaU = iPhaMax_C;
  } else if (rtb_ISC_wElec < iPhaMin_C) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S4>/IdcMaxMdl_C3'
     *  Switch: '<S7>/Switch2'
     */
    ISP_iPhaU = iPhaMin_C;
  } else {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Switch: '<S7>/Switch'
     */
    ISP_iPhaU = rtb_ISC_wElec;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Sum: '<S4>/sub 1' */
  rtb_ISC_wElec = ((real32_T)(*u_ACI_Out_Core2_SAQ_iPhaV)) - (*u_Voffset);

  /* Product: '<S4>/mul 1' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C'
   */
  rtb_ISC_wElec *= facAdc2iPh_C;

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C2'
   *  Constant: '<S4>/IdcMaxMdl_C3'
   *  RelationalOperator: '<S8>/LowerRelop1'
   *  RelationalOperator: '<S8>/UpperRelop'
   *  Switch: '<S8>/Switch'
   */
  if (rtb_ISC_wElec > iPhaMax_C) {
    /* Switch: '<S8>/Switch2' */
    ISP_iPhaV = iPhaMax_C;
  } else if (rtb_ISC_wElec < iPhaMin_C) {
    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S4>/IdcMaxMdl_C3'
     *  Switch: '<S8>/Switch2'
     */
    ISP_iPhaV = iPhaMin_C;
  } else {
    /* Switch: '<S8>/Switch2' incorporates:
     *  Switch: '<S8>/Switch'
     */
    ISP_iPhaV = rtb_ISC_wElec;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Sum: '<S4>/sub 2' */
  rtb_ISC_wElec = ((real32_T)(*u_ACI_Out_Core2_SAQ_iPhaW)) - (*u_Woffset);

  /* Product: '<S4>/mul 2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C'
   */
  rtb_ISC_wElec *= facAdc2iPh_C;

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C2'
   *  Constant: '<S4>/IdcMaxMdl_C3'
   *  RelationalOperator: '<S9>/LowerRelop1'
   *  RelationalOperator: '<S9>/UpperRelop'
   *  Switch: '<S9>/Switch'
   */
  if (rtb_ISC_wElec > iPhaMax_C) {
    /* Switch: '<S9>/Switch2' */
    ISP_iPhaW = iPhaMax_C;
  } else if (rtb_ISC_wElec < iPhaMin_C) {
    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S4>/IdcMaxMdl_C3'
     *  Switch: '<S9>/Switch2'
     */
    ISP_iPhaW = iPhaMin_C;
  } else {
    /* Switch: '<S9>/Switch2' incorporates:
     *  Switch: '<S9>/Switch'
     */
    ISP_iPhaW = rtb_ISC_wElec;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Product: '<S6>/Product3' incorporates:
   *  Constant: '<S6>/facAdc2uDclnk_C'
   */
  rtb_ISC_wElec = (*u_ACI_Out_Core2_SAQ_HVU) * facAdc2uDclnk_C;

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S6>/IdcMaxMdl_C1'
   *  Constant: '<S6>/IdcMaxMdl_C2'
   *  RelationalOperator: '<S13>/LowerRelop1'
   *  RelationalOperator: '<S13>/UpperRelop'
   *  Switch: '<S13>/Switch'
   */
  if (rtb_ISC_wElec > uDcMax_C) {
    rtb_Abs1 = uDcMax_C;
  } else if (rtb_ISC_wElec < uDcMin_C) {
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S6>/IdcMaxMdl_C1'
     */
    rtb_Abs1 = uDcMin_C;
  } else {
    rtb_Abs1 = rtb_ISC_wElec;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/dtPT1UdcLink1'
   *  Constant: '<S6>/tauUdcPT1_C'
   */
  rtb_ISC_wElec = 0.0001F / tauUdcPT1_C;

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Product: '<S12>/Product1'
   *  Product: '<S12>/Product3'
   *  Sum: '<S12>/Subtract'
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  ISP_uDcFlt = ((1.0F - rtb_ISC_wElec) *
                CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_f) + (rtb_Abs1 *
    rtb_ISC_wElec);

  /* RateTransition: '<S3>/Rate Transition8' */
  if (rtmIsSpecialSampleHit(1, 0, tid)) {
    /* RateTransition: '<S3>/Rate Transition8' */
    CDD_ISPpmsmfoc_rtDWork.RateTransition8 =
      CDD_ISPpmsmfoc_rtDWork.RateTransition8_Buffer0;
  }

  /* End of RateTransition: '<S3>/Rate Transition8' */

  /* Product: '<S3>/Product' incorporates:
   *  BusCreator: '<S1>/Bus Creator'
   */
  ISP_agRtrPoleTrans = (int16_T)(ISP_agRtrElecAtan2 *
    CDD_ISPpmsmfoc_rtDWork.RateTransition8);

  /* Gain: '<S3>/agNegTrans' */
  tmp_0 = agNegTrans_C * ISP_agRtrPoleTrans;
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else if (tmp_0 < -32768) {
    tmp_0 = -32768;
  }

  /* Gain: '<S3>/Gain4' incorporates:
   *  Gain: '<S3>/Gain6'
   *  Gain: '<S3>/agNegTrans'
   */
  rtb_ISC_wElec = 0.00549328327F * ((real32_T)((uint16_T)tmp_0));

  /* RelationalOperator: '<S3>/Equal' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  rtb_Equal = (u_msgCore0to2_10ms->SSM_stDrvMode != alOfsCal);

  /* MATLAB Function: '<S3>/AlOfsCalFun2' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant4'
   */
  /*  */
  /* MATLAB Function 'ISP_ResolverSel/AlOfsCalFun2': '<S14>:1' */
  /* ISC_agOffs_P = int16(Angleoffset_Init);  % */
  /* '<S14>:1:21' if isempty(reset) */
  /* '<S14>:1:40' if (ROLreset==boolean(1)) */
  if (rtb_Equal) {
    /* '<S14>:1:41' times= uint8(0); */
    CDD_ISPpmsmfoc_rtDWork.times = 0U;

    /* '<S14>:1:42' cnt = uint16(0); */
    CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

    /* '<S14>:1:43' tempofs = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

    /* '<S14>:1:44' tempU = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempU = 0.0F;

    /* '<S14>:1:45' tempV = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempV = 0.0F;

    /* '<S14>:1:46' tempW = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempW = 0.0F;

    /* '<S14>:1:47' tempUU = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempUU = 0.0F;

    /* '<S14>:1:48' tempVV = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempVV = 0.0F;

    /* '<S14>:1:49' tempWW = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempWW = 0.0F;

    /* '<S14>:1:50' step = uint8(0); */
    CDD_ISPpmsmfoc_rtDWork.step = 0U;

    /* '<S14>:1:51' Iddes = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Iddes = 0.0F;

    /* '<S14>:1:52' Angle = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;

    /* '<S14>:1:53' stAlOfsCaltemp = uint8(0); */
    CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp = 0U;

    /* '<S14>:1:54' agOffs_Caltemp_pos = single(0); */
    CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_pos = 0.0F;

    /* '<S14>:1:55' agOffs_Caltemp_neg = single(0); */
    CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_neg = 0.0F;

    /* '<S14>:1:56' tempV0 = single(0); */
  }

  /* '<S14>:1:59' if(stDrvMode == ECM.alOfsCal&&step==uint8(0)&&stAlOfsCaltemp==uint8(0)) */
  if (((u_msgCore0to2_10ms->SSM_stDrvMode == alOfsCal) &&
       (CDD_ISPpmsmfoc_rtDWork.step == 0)) &&
      (CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp == 0)) {
    /* '<S14>:1:60' Angle = single(120); */
    CDD_ISPpmsmfoc_rtDWork.Angle = 120.0F;

    /* '<S14>:1:61' if(Iddes<single(IdROL_C)) */
    if (CDD_ISPpmsmfoc_rtDWork.Iddes < IdROL_C) {
      /* '<S14>:1:62' Iddes = Iddes+single(0.01); */
      CDD_ISPpmsmfoc_rtDWork.Iddes += 0.01F;
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:63' elseif(cnt<uint16(10000)) */
      /* '<S14>:1:64' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:65' else */
      /* '<S14>:1:66' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:67' step=uint8(1); */
      CDD_ISPpmsmfoc_rtDWork.step = 1U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 1) {
    /* '<S14>:1:69' elseif(step==uint8(1)) */
    /* '<S14>:1:70' if(Angle < single(240)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 240.0F) {
      /* '<S14>:1:71' Angle = Angle + single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle += g_msgCore0to2_detlaAngle_single;
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:73' elseif(cnt<uint16(10000)) */
      /* '<S14>:1:74' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:75' else */
      /* '<S14>:1:76' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:77' step=uint8(2); */
      CDD_ISPpmsmfoc_rtDWork.step = 2U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 2) {
    /* '<S14>:1:79' elseif(step==uint8(2)) */
    /* '<S14>:1:80' if(Angle < single(360)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 360.0F) {
      /* '<S14>:1:81' Angle = Angle + single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle += g_msgCore0to2_detlaAngle_single;
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:83' elseif(cnt<uint16(10000)) */
      /* '<S14>:1:84' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:85' else */
      /* '<S14>:1:86' Angle = single(0); */
      CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;

      /* '<S14>:1:87' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:88' step=uint8(3); */
      CDD_ISPpmsmfoc_rtDWork.step = 3U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 3) {
    /* '<S14>:1:92' elseif(step==uint8(3)) */
    /* '<S14>:1:93' if(Angle<single(120)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 120.0F) {
      /* '<S14>:1:94' Angle=Angle+single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle += g_msgCore0to2_detlaAngle_single;

      /* '<S14>:1:95' else */
      /* '<S14>:1:96' if(cnt<10000) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:97' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:98' else */
      /* '<S14>:1:99' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:100' step=uint8(4); */
      CDD_ISPpmsmfoc_rtDWork.step = 4U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 4) {
    /* '<S14>:1:103' elseif(step==4) */
    /* '<S14>:1:104' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S14>:1:105' tempV0 = Angle - AngleAct; */
      rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_ISC_wElec;

      /* '<S14>:1:106' if(tempV0<single(0)) */
      if (rtb_ISC_wElec < 0.0F) {
        /* '<S14>:1:107' tempV0=tempV0+single(360); */
        rtb_ISC_wElec += 360.0F;
      }

      /* '<S14>:1:109' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_ISC_wElec;

      /* '<S14>:1:110' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:111' else */
      /* '<S14>:1:112' tempV=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempV = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S14>:1:113' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S14>:1:114' step=uint8(5); */
      CDD_ISPpmsmfoc_rtDWork.step = 5U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 5) {
    /* '<S14>:1:118' elseif(step==5) */
    /* '<S14>:1:119' if(Angle<single(240)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 240.0F) {
      /* '<S14>:1:120' Angle=Angle+single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle += g_msgCore0to2_detlaAngle_single;

      /* '<S14>:1:121' else */
      /* '<S14>:1:122' if(cnt<uint16(10000)) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:123' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:124' else */
      /* '<S14>:1:125' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:126' step=uint8(6); */
      CDD_ISPpmsmfoc_rtDWork.step = 6U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 6) {
    /* '<S14>:1:130' elseif(step==6) */
    /* '<S14>:1:131' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S14>:1:132' tempV0 = Angle - AngleAct; */
      rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_ISC_wElec;

      /* '<S14>:1:133' if(tempV0<single(0)) */
      if (rtb_ISC_wElec < 0.0F) {
        /* '<S14>:1:134' tempV0=tempV0+single(360); */
        rtb_ISC_wElec += 360.0F;
      }

      /* '<S14>:1:136' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_ISC_wElec;

      /* '<S14>:1:137' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:138' else */
      /* '<S14>:1:139' tempW=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempW = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S14>:1:140' if(tempW<0) */
      if (CDD_ISPpmsmfoc_rtDWork.tempW < 0.0F) {
        /* '<S14>:1:141' tempW=tempW+single(360); */
        CDD_ISPpmsmfoc_rtDWork.tempW += 360.0F;
      }

      /* '<S14>:1:143' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S14>:1:144' step=uint8(7); */
      CDD_ISPpmsmfoc_rtDWork.step = 7U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 7) {
    /* '<S14>:1:147' elseif(step==uint8(7)) */
    /* '<S14>:1:148' if(Angle<single(360)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 360.0F) {
      /* '<S14>:1:149' Angle=Angle+single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle += g_msgCore0to2_detlaAngle_single;

      /* '<S14>:1:150' else */
      /* '<S14>:1:152' if(cnt<uint16(10000)) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:153' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:154' else */
      /* '<S14>:1:155' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:156' step=uint8(8); */
      CDD_ISPpmsmfoc_rtDWork.step = 8U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 8) {
    /* '<S14>:1:159' elseif(step==uint8(8)) */
    /* '<S14>:1:160' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S14>:1:161' tempV0 = Angle - AngleAct; */
      rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_ISC_wElec;

      /* '<S14>:1:162' if(tempV0<single(0)) */
      if (rtb_ISC_wElec < 0.0F) {
        /* '<S14>:1:163' tempV0=tempV0+single(360); */
        rtb_ISC_wElec += 360.0F;
      }

      /* '<S14>:1:165' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_ISC_wElec;

      /* '<S14>:1:166' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:167' else */
      /* '<S14>:1:168' tempU=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempU = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S14>:1:169' if(tempU<0) */
      if (CDD_ISPpmsmfoc_rtDWork.tempU < 0.0F) {
        /* '<S14>:1:170' tempU=tempU+single(360); */
        CDD_ISPpmsmfoc_rtDWork.tempU += 360.0F;
      }

      /* '<S14>:1:173' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S14>:1:174' step=uint8(9); */
      CDD_ISPpmsmfoc_rtDWork.step = 9U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 9) {
    int32_T tmp;

    /* '<S14>:1:178' elseif(step==uint8(9)) */
    /* '<S14>:1:179' agOffs_Caltemp_pos = agOffs_Caltemp_pos + ((tempU)+(tempV)+(tempW))/3; */
    CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_pos += ((CDD_ISPpmsmfoc_rtDWork.tempU
      + CDD_ISPpmsmfoc_rtDWork.tempV) + CDD_ISPpmsmfoc_rtDWork.tempW) / 3.0F;

    /* '<S14>:1:180' times = times + uint8(1); */
    tmp = (int32_T)(CDD_ISPpmsmfoc_rtDWork.times + 1U);
    if ((CDD_ISPpmsmfoc_rtDWork.times + 1U) > 255U) {
      tmp = 255;
    }

    CDD_ISPpmsmfoc_rtDWork.times = (uint8_T)tmp;

    /* '<S14>:1:181' if(times>uint8(9)) */
    if (CDD_ISPpmsmfoc_rtDWork.times > 9) {
      /* '<S14>:1:182' agOffs_Caltemp_pos = agOffs_Caltemp_pos/single(10); */
      CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_pos /= 10.0F;

      /* '<S14>:1:183' stAlOfsCaltemp = uint8(0); */
      CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp = 0U;

      /* '<S14>:1:184' step=uint8(10); */
      CDD_ISPpmsmfoc_rtDWork.step = 10U;

      /* '<S14>:1:185' times= uint8(0); */
      CDD_ISPpmsmfoc_rtDWork.times = 0U;

      /* '<S14>:1:186' Angle= single(360); */
      CDD_ISPpmsmfoc_rtDWork.Angle = 360.0F;

      /* '<S14>:1:187' if(Iddes>single(0)) */
      if (CDD_ISPpmsmfoc_rtDWork.Iddes > 0.0F) {
        /* '<S14>:1:188' Iddes = Iddes - single(0.1); */
        CDD_ISPpmsmfoc_rtDWork.Iddes -= 0.1F;
      }
    } else {
      /* '<S14>:1:190' else */
      /* '<S14>:1:191' step=uint8(3); */
      CDD_ISPpmsmfoc_rtDWork.step = 3U;

      /* '<S14>:1:192' Angle = single(0); */
      CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%反转%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 10) {
    /* '<S14>:1:197' elseif(step==uint8(10)) */
    /* '<S14>:1:198' if(Angle>single(240)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle > 240.0F) {
      /* 要选大于号 */
      /* '<S14>:1:199' Angle=Angle-single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle -= g_msgCore0to2_detlaAngle_single;

      /* '<S14>:1:200' else */
      /* '<S14>:1:202' if(cnt<uint16(10000)) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:203' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:204' else */
      /* '<S14>:1:205' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:206' step=uint8(11); */
      CDD_ISPpmsmfoc_rtDWork.step = 11U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 11) {
    /* '<S14>:1:209' elseif(step==uint8(11)) */
    /* '<S14>:1:210' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S14>:1:211' tempV0 = Angle - AngleAct; */
      rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_ISC_wElec;

      /* '<S14>:1:212' if(tempV0<single(0)) */
      if (rtb_ISC_wElec < 0.0F) {
        /* '<S14>:1:213' tempV0=tempV0+single(360); */
        rtb_ISC_wElec += 360.0F;
      }

      /* '<S14>:1:215' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_ISC_wElec;

      /* '<S14>:1:216' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:217' else */
      /* '<S14>:1:218' tempVV=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempVV = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S14>:1:219' if(tempVV<0) */
      if (CDD_ISPpmsmfoc_rtDWork.tempVV < 0.0F) {
        /* '<S14>:1:220' tempVV=tempVV+single(360); */
        CDD_ISPpmsmfoc_rtDWork.tempVV += 360.0F;
      }

      /* '<S14>:1:223' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S14>:1:224' step=uint8(12); */
      CDD_ISPpmsmfoc_rtDWork.step = 12U;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 12) {
    /* '<S14>:1:228' elseif(step==uint8(12)) */
    /* '<S14>:1:229' if(Angle>single(120)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle > 120.0F) {
      /* '<S14>:1:230' Angle=Angle-single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle -= g_msgCore0to2_detlaAngle_single;

      /* '<S14>:1:231' else */
      /* '<S14>:1:233' if(cnt<uint16(10000)) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:234' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:235' else */
      /* '<S14>:1:236' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:237' step=uint8(13); */
      CDD_ISPpmsmfoc_rtDWork.step = 13U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 13) {
    /* '<S14>:1:240' elseif(step==uint8(13)) */
    /* '<S14>:1:241' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S14>:1:242' tempV0 = Angle - AngleAct; */
      rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_ISC_wElec;

      /* '<S14>:1:243' if(tempV0<single(0)) */
      if (rtb_ISC_wElec < 0.0F) {
        /* '<S14>:1:244' tempV0=tempV0+single(360); */
        rtb_ISC_wElec += 360.0F;
      }

      /* '<S14>:1:246' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_ISC_wElec;

      /* '<S14>:1:247' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:248' else */
      /* '<S14>:1:249' tempWW=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempWW = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S14>:1:250' if(tempWW<0) */
      if (CDD_ISPpmsmfoc_rtDWork.tempWW < 0.0F) {
        /* '<S14>:1:251' tempWW=tempWW+single(360); */
        CDD_ISPpmsmfoc_rtDWork.tempWW += 360.0F;
      }

      /* '<S14>:1:254' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S14>:1:255' step=uint8(14); */
      CDD_ISPpmsmfoc_rtDWork.step = 14U;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 14) {
    /* '<S14>:1:258' elseif(step==uint8(14)) */
    /* '<S14>:1:259' if(Angle>single(0)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle > 0.0F) {
      /* '<S14>:1:260' Angle=Angle-single(dataAngle); */
      CDD_ISPpmsmfoc_rtDWork.Angle -= g_msgCore0to2_detlaAngle_single;

      /* '<S14>:1:261' else */
      /* '<S14>:1:263' if(cnt<uint16(10000)) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S14>:1:264' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:265' else */
      /* '<S14>:1:266' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S14>:1:267' step=uint8(15); */
      CDD_ISPpmsmfoc_rtDWork.step = 15U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 15) {
    /* '<S14>:1:270' elseif(step==uint8(15)) */
    /* '<S14>:1:271' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S14>:1:272' tempV0 = Angle - AngleAct; */
      rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_ISC_wElec;

      /* '<S14>:1:273' if(tempV0<single(0)) */
      if (rtb_ISC_wElec < 0.0F) {
        /* '<S14>:1:274' tempV0=tempV0+single(360); */
        rtb_ISC_wElec += 360.0F;
      }

      /* '<S14>:1:276' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_ISC_wElec;

      /* '<S14>:1:277' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S14>:1:278' else */
      /* '<S14>:1:279' tempUU=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempUU = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S14>:1:280' if(tempUU<0) */
      if (CDD_ISPpmsmfoc_rtDWork.tempUU < 0.0F) {
        /* '<S14>:1:281' tempUU=tempUU+single(360); */
        CDD_ISPpmsmfoc_rtDWork.tempUU += 360.0F;
      }

      /* '<S14>:1:284' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S14>:1:285' step=uint8(16); */
      CDD_ISPpmsmfoc_rtDWork.step = 16U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 16) {
    int32_T tmp;

    /* '<S14>:1:288' elseif(step==uint8(16)) */
    /* '<S14>:1:289' agOffs_Caltemp_neg = agOffs_Caltemp_neg + ((tempUU)+(tempVV)+(tempWW))/3; */
    CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_neg += ((CDD_ISPpmsmfoc_rtDWork.tempUU
      + CDD_ISPpmsmfoc_rtDWork.tempVV) + CDD_ISPpmsmfoc_rtDWork.tempWW) / 3.0F;

    /* '<S14>:1:290' times = times + uint8(1); */
    tmp = (int32_T)(CDD_ISPpmsmfoc_rtDWork.times + 1U);
    if ((CDD_ISPpmsmfoc_rtDWork.times + 1U) > 255U) {
      tmp = 255;
    }

    CDD_ISPpmsmfoc_rtDWork.times = (uint8_T)tmp;

    /* '<S14>:1:291' if(times>uint8(9)) */
    if (CDD_ISPpmsmfoc_rtDWork.times > 9) {
      /* '<S14>:1:292' agOffs_Caltemp_neg = agOffs_Caltemp_neg/single(10); */
      CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_neg /= 10.0F;

      /* '<S14>:1:293' stAlOfsCaltemp = uint8(1); */
      CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp = 1U;

      /* '<S14>:1:294' step=uint8(0); */
      CDD_ISPpmsmfoc_rtDWork.step = 0U;

      /* '<S14>:1:295' if(Iddes>single(0)) */
      if (CDD_ISPpmsmfoc_rtDWork.Iddes > 0.0F) {
        /* '<S14>:1:296' Iddes = Iddes - single(0.1); */
        CDD_ISPpmsmfoc_rtDWork.Iddes -= 0.1F;
      }
    } else {
      /* '<S14>:1:298' else */
      /* '<S14>:1:299' step=uint8(10); */
      CDD_ISPpmsmfoc_rtDWork.step = 10U;

      /* '<S14>:1:300' Angle = single(360); */
      CDD_ISPpmsmfoc_rtDWork.Angle = 360.0F;
    }
  } else {
    /* '<S14>:1:302' else */
    /* '<S14>:1:303' Iddes = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Iddes = 0.0F;

    /* '<S14>:1:304' Angle = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;
  }

  /* '<S14>:1:307' stAlOfsCal = stAlOfsCaltemp; */
  /* '<S14>:1:308' AngleOP = Angle; */
  /* '<S14>:1:309' Iddesout = Iddes; */
  *y_Iddes = CDD_ISPpmsmfoc_rtDWork.Iddes;

  /* Switch: '<S3>/Switch' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Gain: '<S3>/Gain5'
   *  MATLAB Function: '<S3>/AlOfsCalFun2'
   */
  /* '<S14>:1:310' agOffs_Cal = single((agOffs_Caltemp_pos+agOffs_Caltemp_neg)/2); */
  /* '<S14>:1:311' step_output =single(step); */
  /* '<S14>:1:312' U=single(tempU); */
  /* '<S14>:1:313' V=single(tempV); */
  /* '<S14>:1:314' W=single(tempW); */
  /* '<S14>:1:315' UU=single(tempUU); */
  /* '<S14>:1:316' VV=single(tempVV); */
  /* '<S14>:1:317' WW=single(tempWW); */
  /* '<S14>:1:318' pos=single(agOffs_Caltemp_pos); */
  /* '<S14>:1:319' neg=single(agOffs_Caltemp_neg); */
  if (rtb_Equal) {
    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S3>/agOffs_test'
     *  Gain: '<S3>/agNegTrans'
     */
    rtb_agNegTrans = (int16_T)(((int16_T)((*u_Angleoffset_Init) + ((int16_T)
      tmp_0))) + offsAgRtrElec_C);
  } else {
    rtb_agNegTrans = (int16_T)((int32_T)floorf(182.041672F *
      CDD_ISPpmsmfoc_rtDWork.Angle));
  }

  /* End of Switch: '<S3>/Switch' */

  /* MATLAB Function: '<S3>/AlOfsCalPosSet' */
  /*  */
  /* MATLAB Function 'ISP_ResolverSel/AlOfsCalPosSet': '<S15>:1' */
  /* '<S15>:1:6' if isempty(stRoughCalSetLast) */
  /* '<S15>:1:11' if stRoughCalSet==uint8(0) */
  if ((*u_msgCore0to2_1ms_TCC_stRoughCalSet) == 0) {
    /* '<S15>:1:12' agOut = agIn; */
    ISP_agRtrElec = rtb_agNegTrans;
  } else if ((*u_msgCore0to2_1ms_TCC_stRoughCalSet) == 5) {
    /* '<S15>:1:13' elseif stRoughCalSet==uint8(5) */
    /* '<S15>:1:14' if stRoughCalSetLast==uint8(4) */
    if (CDD_ISPpmsmfoc_rtDWork.stRoughCalSetLast == 4) {
      /* '<S15>:1:15' agRoughCal = agIn; */
      CDD_ISPpmsmfoc_rtDWork.agRoughCal = rtb_agNegTrans;
    }

    /* '<S15>:1:17' agOut = agIn + agRoughCal; */
    tmp_0 = rtb_agNegTrans + CDD_ISPpmsmfoc_rtDWork.agRoughCal;
    if (tmp_0 > 32767) {
      tmp_0 = 32767;
    } else if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }

    ISP_agRtrElec = (int16_T)tmp_0;
  } else {
    /* '<S15>:1:18' else */
    /* '<S15>:1:19' agOut = int16(0); */
    ISP_agRtrElec = 0;
  }

  /* '<S15>:1:22' stRoughCalSetLast = stRoughCalSet; */
  CDD_ISPpmsmfoc_rtDWork.stRoughCalSetLast =
    *u_msgCore0to2_1ms_TCC_stRoughCalSet;

  /* '<S15>:1:23' agRoughCalOut = agRoughCal; */
  ISP_agRoughCal = CDD_ISPpmsmfoc_rtDWork.agRoughCal;

  /* End of MATLAB Function: '<S3>/AlOfsCalPosSet' */

  /* RateTransition: '<S3>/Rate Transition6' */
  if (rtmIsSpecialSampleHit(1, 0, tid)) {
    /* RateTransition: '<S3>/Rate Transition6' */
    CDD_ISPpmsmfoc_rtDWork.RateTransition6 =
      CDD_ISPpmsmfoc_rtDWork.RateTransition6_Buffer0;
  }

  /* End of RateTransition: '<S3>/Rate Transition6' */

  /* Product: '<S3>/Product1' incorporates:
   *  BusCreator: '<S1>/Bus Creator'
   */
  rtb_Abs1 = CDD_ISPpmsmfoc_rtDWork.RateTransition6 * ISP_frqElecCaln;

  /* RateTransition: '<S3>/Rate Transition10' */
  ISP_frqElec = rtb_Abs1;

  /* RateTransition: '<S3>/Rate Transition2' incorporates:
   *  Gain: '<S3>/fac2piFrq2w'
   */
  ISP_wElec = 6.28318548F * rtb_Abs1;

  /* Gain: '<S3>/facf2n' */
  rtb_Abs1 *= 60.0F / SC_p_P;

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Abs1 > 20000.0F) {
    rtb_Abs1 = 20000.0F;
  } else if (rtb_Abs1 < -20000.0F) {
    rtb_Abs1 = -20000.0F;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* RateTransition: '<S3>/Rate Transition1' */
  ISP_n = rtb_Abs1;

  /* BusCreator: '<S2>/Bus Creator' incorporates:
   *  BusCreator: '<S3>/Bus Creator'
   */
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_Is = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isd = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isq = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_sin = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isdH6 = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isqH6 = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_AngleOut = (uint16_T)ISP_agRtrElec;

  /* Constant: '<Root>/Constant' */
  ISP_tmpMaxIGBT = 0.0F;

  /* Constant: '<Root>/Constant1' */
  ISP_lossTotalIGBT = 0.0F;

  /* Constant: '<Root>/Constant2' */
  ISP_iDcFlt = 0.0F;

  /* Constant: '<Root>/Constant3' */
  ISP_tmpClnt = 0.0F;

  /* BusCreator generated from: '<Root>/Bus Creator' */
  y_ISP_Out->Core2_ISC_tmpOut.Core2_ISP_tmpMaxIGBT = 0.0F;
  y_ISP_Out->Core2_ISC_tmpOut.Core2_ISP_lossTotalIGBT = 0.0F;
  y_ISP_Out->Core2_ISC_tmpOut.Core2_ISP_iDcFlt = 0.0F;
  y_ISP_Out->Core2_ISC_tmpOut.Core2_ISP_tmpClnt = 0.0F;

  /* BusCreator: '<Root>/Bus Creator' incorporates:
   *  Abs: '<S3>/Abs'
   *  BusCreator: '<S1>/Bus Creator'
   *  BusCreator: '<S1>/Bus Creator2'
   *  BusCreator: '<S3>/Bus Creator'
   *  BusCreator: '<S4>/Bus Creator'
   *  Constant: '<S1>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gain3'
   *  MATLAB Function: '<S3>/AlOfsCalFun2'
   */
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_stAlOfsCal =
    CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_agOffsCal = (int16_T)((int32_T)floorf
    (((CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_pos +
       CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp_neg) / 2.0F) * 182.041672F));
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_agRtrElec = ISP_agRtrElec;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_frqElec = ISP_frqElec;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_wElec = ISP_wElec;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_n = ISP_n;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_nAbs = fabsf(rtb_Abs1);
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISC_agRtrElecAtan2 =
    ISP_agRtrElecAtan2;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISC_frqElecCaln =
    ISP_frqElecCaln;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaU = ISP_iPhaU;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaV = ISP_iPhaV;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaW = ISP_iPhaW;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_bIphCalDone = true;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_uDc = ISP_uDcFlt;

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  UnitDelay: '<S5>/Unit Delay'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_p;
  rtb_Gain1 = CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE;

  /* MATLAB Function 'CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/MATLAB Function': '<S10>:1' */
  /* '<S10>:1:4' if isempty(reset) */
  if (!CDD_ISPpmsmfoc_rtDWork.reset_not_empty_ll) {
    /* '<S10>:1:5' reset = boolean(1); */
    CDD_ISPpmsmfoc_rtDWork.reset_not_empty_ll = true;

    /*      theta_hat_K_1 = single(0); */
    /*      omega_hat_K_1 = sinle(0); */
    /* '<S10>:1:8' omega_hat_K =  single(0); */
    rtb_ISC_wElec = 0.0F;

    /* '<S10>:1:9' theta_hat_k = single(0); */
    rtb_Gain1 = 0.0F;
  }

  /* '<S10>:1:11' Ts= single(1/16000); */
  /* '<S10>:1:12' ek = theta_meas_k - theta_hat_k; */
  rtb_DTC3 -= rtb_Gain1;

  /* '<S10>:1:13' theta_hat_K_1 = theta_hat_k + (omega_hat_K + L1 * ek)* Ts; */
  theta_hat_K_1 = (((g_msgCore0to2_L1 * rtb_DTC3) + rtb_ISC_wElec) * 6.25E-5F) +
    rtb_Gain1;

  /* '<S10>:1:14' omega_hat_K_1 = omega_hat_K + L2 * ek * Ts; */
  omega_hat_K_1 = ((g_msgCore0to2_L2 * rtb_DTC3) * 6.25E-5F) + rtb_ISC_wElec;

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* Gain: '<S3>/Gain7' incorporates:
   *  Gain: '<S3>/Gain'
   *  Inport generated from: '<Root>/speed_ref'
   */
  /*  # 输入：theta_meas(k) = 编码器实测机械位置(rad) */
  /*  # 输出：omega_hat(k) = 平滑转速(rad/s) */
  /*  # 调参：l1, l2（观测器增益），dt = 控制周期(s) */
  /*   */
  /*  # 1. 计算位置误差（核心修正项） */
  /*  e(k) = theta_meas(k) - theta_hat(k) */
  /*   */
  /*  # 2. 更新内部预测位置（仅用于误差计算，不输出） */
  /*  theta_hat(k+1) = theta_hat(k) + [omega_hat(k) + l1 * e(k)] * dt */
  /*   */
  /*  # 3. 更新输出转速（无参数，仅用误差修正） */
  /*  omega_hat(k+1) = omega_hat(k) + l2 * e(k) * dt */
  ISP_speedref_final_wn = (0.0833333358F * ISP_speedref_final) * 6.28318548F;

  /* Abs: '<S3>/Abs1' */
  rtb_Abs1 = fabsf(ISP_speedref_final_wn);

  /* UnitDelay: '<S3>/Unit Delay4' */
  X111 = CDD_ISPpmsmfoc_rtDWork.UnitDelay4_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay5' */
  X222 = CDD_ISPpmsmfoc_rtDWork.UnitDelay5_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay6' */
  Y111 = CDD_ISPpmsmfoc_rtDWork.UnitDelay6_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay7' */
  Y222 = CDD_ISPpmsmfoc_rtDWork.UnitDelay7_DSTATE;

  /* Gain: '<S3>/Gain2' */
  rtb_Gain1 = (g_msgCore0to2_N222 / 5.0F) * rtb_Abs1;

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  Constant: '<S3>/Constant5'
   *  Constant: '<S3>/Constant6'
   */
  rtb_DTC3 = Y111;
  rtb_ISC_wElec = Y222;

  /* MATLAB Function 'ISP_ResolverSel/MATLAB Function1': '<S17>:1' */
  /* ISC_agOffs_P = int16(Angleoffset_Init);  % */
  /* '<S17>:1:5' if isempty(reset) */
  if (!CDD_ISPpmsmfoc_rtDWork.reset_not_empty_e) {
    /* '<S17>:1:6' reset = boolean(1); */
    CDD_ISPpmsmfoc_rtDWork.reset_not_empty_e = true;

    /* '<S17>:1:7' a1=single(1); */
    /* '<S17>:1:8' y1=single(0); */
    rtb_DTC3 = 0.0F;

    /* '<S17>:1:9' y2=single(0); */
    rtb_ISC_wElec = 0.0F;
  }

  /*  if(x0<0) */
  /*   */
  /*  temp_abs_signal =single(-1); */
  /*  else */
  /*  temp_abs_signal =single(1); */
  /*  end */
  /*  x0 = abs(x0); */
  /* '<S17>:1:23' Ts= single(1/16000); */
  /* '<S17>:1:24' B = 2*pi*fbw; */
  rtb_UnitDelay12 = 6.28318548F * g_msgCore0to2_fbw;

  /* '<S17>:1:25' temp1= single(1)-single(sqrt(1+(B^2/wn^2))); */
  rtb_UnitDelay14_tmp = rtb_Gain1 * rtb_Gain1;
  rtb_UnitDelay14 = 1.0F - sqrtf(((rtb_UnitDelay12 * rtb_UnitDelay12) /
    rtb_UnitDelay14_tmp) + 1.0F);

  /* '<S17>:1:26' temp2= single(4*depth^2-2); */
  temp2_tmp_tmp = ((g_msgCore0to2_depth * g_msgCore0to2_depth) * 4.0F) - 2.0F;

  /* '<S17>:1:27' k1 = sqrt(temp1/temp2); */
  k1_0 = sqrtf(rtb_UnitDelay14 / temp2_tmp_tmp);

  /* '<S17>:1:28' k2 = k1 *depth; */
  k2_0 = k1_0 * g_msgCore0to2_depth;

  /* '<S17>:1:31' a1= single(wn^2*Ts^2 + 4*Ts*k1*wn + 4); */
  /* '<S17>:1:32' a2= single(2*wn^2*Ts^2-8); */
  rtb_UnitDelay2 = ((rtb_UnitDelay14_tmp * 2.0F) * 3.90625043E-9F) - 8.0F;

  /* '<S17>:1:33' a3 =single(wn^2*Ts^2 - 4*Ts*k1*wn + 4); */
  rtb_UnitDelay14_tmp *= 3.90625043E-9F;
  a0_tmp = (0.00025F * k1_0) * rtb_Gain1;
  a0 = (rtb_UnitDelay14_tmp - a0_tmp) + 4.0F;

  /* '<S17>:1:35' b1 = single(wn^2*Ts^2 + 4*Ts*k2*wn + 4); */
  b1_tmp = (0.00025F * k2_0) * rtb_Gain1;
  b1_0 = (rtb_UnitDelay14_tmp + b1_tmp) + 4.0F;

  /* '<S17>:1:36' b2 = single(2*wn^2*Ts^2-8); */
  b2_0 = rtb_UnitDelay2;

  /* '<S17>:1:37' b3 = single(wn^2*Ts^2 - 4*Ts*k2*wn + 4); */
  b1_tmp = (rtb_UnitDelay14_tmp - b1_tmp) + 4.0F;

  /* '<S17>:1:39' if(abs(wn)<200) */
  if (fabsf(rtb_Gain1) < 200.0F) {
    /* '<S17>:1:40' y1=single(0); */
    rtb_DTC3 = 0.0F;

    /* '<S17>:1:41' y2=single(0); */
    rtb_ISC_wElec = 0.0F;

    /* '<S17>:1:42' a1=single(1); */
    rtb_Gain1 = 1.0F;

    /* '<S17>:1:43' a2=single(0); */
    rtb_UnitDelay2 = 0.0F;

    /* '<S17>:1:44' a3=single(0); */
    a0 = 0.0F;

    /* '<S17>:1:45' b1=single(1); */
    b1_0 = 1.0F;

    /* '<S17>:1:46' b2=single(0); */
    b2_0 = 0.0F;

    /* '<S17>:1:47' b3=single(0); */
    b1_tmp = 0.0F;
  } else {
    /* '<S17>:1:48' else */
    /* '<S17>:1:49' y1=y1; */
    /* '<S17>:1:50' y2=y2; */
    /* '<S17>:1:51' a1=a1; */
    rtb_Gain1 = (rtb_UnitDelay14_tmp + a0_tmp) + 4.0F;
  }

  /* '<S17>:1:53' temp = single(b1*x0 + b2*x1 + b3*x2 - a2*y1 - a3*y2); */
  /* '<S17>:1:54' y = single(temp/a1); */
  *y_ISP_nNotch = (((((b1_0 * ISP_n) + (b2_0 * X111)) + (b1_tmp * X222)) -
                    (rtb_UnitDelay2 * rtb_DTC3)) - (a0 * rtb_ISC_wElec)) /
    rtb_Gain1;
  B = rtb_UnitDelay12;
  temp1_111 = rtb_UnitDelay14;
  temp2_222 = temp2_tmp_tmp;
  k1 = k1_0;
  k2 = k2_0;
  a1 = rtb_Gain1;
  a2 = rtb_UnitDelay2;
  a3 = a0;
  b1 = b1_0;
  b2 = b2_0;
  b3 = b1_tmp;

  /* End of MATLAB Function: '<S3>/MATLAB Function1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  test8 = *y_ISP_nNotch;

  /* UnitDelay: '<S3>/Unit Delay12' */
  rtb_UnitDelay12 = CDD_ISPpmsmfoc_rtDWork.UnitDelay12_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay14' */
  rtb_UnitDelay14 = CDD_ISPpmsmfoc_rtDWork.UnitDelay14_DSTATE;

  /* Gain: '<S3>/Gain1' */
  rtb_Gain1 = (g_msgCore0to2_N111 / 5.0F) * rtb_Abs1;

  /* MATLAB Function: '<S3>/MATLAB Function3' incorporates:
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant7'
   *  UnitDelay: '<S3>/Unit Delay12'
   *  UnitDelay: '<S3>/Unit Delay13'
   *  UnitDelay: '<S3>/Unit Delay14'
   *  UnitDelay: '<S3>/Unit Delay15'
   */
  rtb_DTC3 = CDD_ISPpmsmfoc_rtDWork.UnitDelay14_DSTATE;
  rtb_ISC_wElec = CDD_ISPpmsmfoc_rtDWork.UnitDelay15_DSTATE;

  /* MATLAB Function 'ISP_ResolverSel/MATLAB Function3': '<S18>:1' */
  /* ISC_agOffs_P = int16(Angleoffset_Init);  % */
  /* '<S18>:1:5' if isempty(reset) */
  if (!CDD_ISPpmsmfoc_rtDWork.reset_not_empty) {
    /* '<S18>:1:6' reset = boolean(1); */
    CDD_ISPpmsmfoc_rtDWork.reset_not_empty = true;

    /* '<S18>:1:7' a1=single(1); */
    /* '<S18>:1:8' y1=single(0); */
    rtb_DTC3 = 0.0F;

    /* '<S18>:1:9' y2=single(0); */
    rtb_ISC_wElec = 0.0F;
  }

  /*  if(x0<0) */
  /*   */
  /*  temp_abs_signal =single(-1); */
  /*  else */
  /*  temp_abs_signal =single(1); */
  /*  end */
  /*  x0 = abs(x0); */
  /* '<S18>:1:23' Ts= single(1/16000); */
  /* '<S18>:1:24' B = 2*pi*fbw; */
  rtb_Abs1 = 6.28318548F * g_msgCore0to2_fbw;

  /* '<S18>:1:25' temp1= single(1)-single(sqrt(1+(B^2/wn^2))); */
  /* '<S18>:1:26' temp2= single(4*depth^2-2); */
  /* '<S18>:1:27' k1 = sqrt(temp1/temp2); */
  rtb_UnitDelay14_tmp = rtb_Gain1 * rtb_Gain1;
  k1_0 = sqrtf((1.0F - sqrtf(((rtb_Abs1 * rtb_Abs1) / rtb_UnitDelay14_tmp) +
    1.0F)) / (((g_msgCore0to2_depth * g_msgCore0to2_depth) * 4.0F) - 2.0F));

  /* '<S18>:1:28' k2 = k1 *depth; */
  /* '<S18>:1:31' a1= single(wn^2*Ts^2 + 4*Ts*k1*wn + 4); */
  /* '<S18>:1:32' a2= single(2*wn^2*Ts^2-8); */
  rtb_UnitDelay2 = ((rtb_UnitDelay14_tmp * 2.0F) * 3.90625043E-9F) - 8.0F;

  /* '<S18>:1:33' a3 =single(wn^2*Ts^2 - 4*Ts*k1*wn + 4); */
  rtb_UnitDelay14_tmp *= 3.90625043E-9F;
  a0_tmp = (0.00025F * k1_0) * rtb_Gain1;
  a0 = (rtb_UnitDelay14_tmp - a0_tmp) + 4.0F;

  /* '<S18>:1:35' b1 = single(wn^2*Ts^2 + 4*Ts*k2*wn + 4); */
  b1_tmp = ((k1_0 * g_msgCore0to2_depth) * 0.00025F) * rtb_Gain1;
  b1_0 = (rtb_UnitDelay14_tmp + b1_tmp) + 4.0F;

  /* '<S18>:1:36' b2 = single(2*wn^2*Ts^2-8); */
  b2_0 = rtb_UnitDelay2;

  /* '<S18>:1:37' b3 = single(wn^2*Ts^2 - 4*Ts*k2*wn + 4); */
  b1_tmp = (rtb_UnitDelay14_tmp - b1_tmp) + 4.0F;

  /* '<S18>:1:39' if(abs(wn)<200) */
  if (fabsf(rtb_Gain1) < 200.0F) {
    /* '<S18>:1:40' y1=single(0); */
    rtb_DTC3 = 0.0F;

    /* '<S18>:1:41' y2=single(0); */
    rtb_ISC_wElec = 0.0F;

    /* '<S18>:1:42' a1=single(1); */
    rtb_Gain1 = 1.0F;

    /* '<S18>:1:43' a2=single(0); */
    rtb_UnitDelay2 = 0.0F;

    /* '<S18>:1:44' a3=single(0); */
    a0 = 0.0F;

    /* '<S18>:1:45' b1=single(1); */
    b1_0 = 1.0F;

    /* '<S18>:1:46' b2=single(0); */
    b2_0 = 0.0F;

    /* '<S18>:1:47' b3=single(0); */
    b1_tmp = 0.0F;
  } else {
    /* '<S18>:1:48' else */
    /* '<S18>:1:49' y1=y1; */
    /* '<S18>:1:50' y2=y2; */
    /* '<S18>:1:51' a1=a1; */
    rtb_Gain1 = (rtb_UnitDelay14_tmp + a0_tmp) + 4.0F;
  }

  /* '<S18>:1:53' temp = single(b1*x0 + b2*x1 + b3*x2 - a2*y1 - a3*y2); */
  /* '<S18>:1:54' y = single(temp/a1); */
  *y_ISP_nNotch2 = (((((b1_0 * (*y_ISP_nNotch)) + (b2_0 *
    CDD_ISPpmsmfoc_rtDWork.UnitDelay12_DSTATE)) + (b1_tmp *
    CDD_ISPpmsmfoc_rtDWork.UnitDelay13_DSTATE)) - (rtb_UnitDelay2 * rtb_DTC3)) -
                    (a0 * rtb_ISC_wElec)) / rtb_Gain1;

  /* End of MATLAB Function: '<S3>/MATLAB Function3' */

  /* DataTypeConversion: '<S3>/Data Type Conversion4' */
  ISP_n_test_pp = *y_ISP_nNotch2;

  /* UnitDelay: '<S3>/Unit Delay' */
  rtb_Abs1 = CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE_j;

  /* UnitDelay: '<S3>/Unit Delay2' */
  rtb_UnitDelay2 = CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay3' */
  test2 = CDD_ISPpmsmfoc_rtDWork.UnitDelay3_DSTATE;

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant1'
   *  UnitDelay: '<S3>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay1'
   *  UnitDelay: '<S3>/Unit Delay2'
   */
  rtb_DTC3 = CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE;
  rtb_ISC_wElec = test2;

  /* MATLAB Function 'ISP_ResolverSel/MATLAB Function': '<S16>:1' */
  /* ISC_agOffs_P = int16(Angleoffset_Init);  % */
  /* '<S16>:1:6' if isempty(reset) */
  if (!CDD_ISPpmsmfoc_rtDWork.reset_not_empty_l) {
    /* '<S16>:1:7' reset = boolean(1); */
    CDD_ISPpmsmfoc_rtDWork.reset_not_empty_l = true;

    /* '<S16>:1:8' a0=single(0); */
    /* '<S16>:1:9' a1=single(0); */
    /* '<S16>:1:10' y1=single(0); */
    rtb_DTC3 = 0.0F;

    /* '<S16>:1:11' y2=single(0); */
    rtb_ISC_wElec = 0.0F;
  }

  /* '<S16>:1:16' Ts= single(1/16000); */
  /* '<S16>:1:17' a0= single(4+wc^2*Ts^2); */
  rtb_UnitDelay14_tmp = ISP_speedref_final_wn * ISP_speedref_final_wn;
  a0_tmp = (rtb_UnitDelay14_tmp * 3.90625043E-9F) + 4.0F;

  /* '<S16>:1:18' a1= single(2*Ts^2*wc^2-8); */
  rtb_Gain1 = (rtb_UnitDelay14_tmp * 7.81250087E-9F) - 8.0F;

  /* '<S16>:1:19' a2= single(a0); */
  /* '<S16>:1:20' b0 =single(4+wc^2*Ts^2+2*wb*Ts); */
  /* '<S16>:1:21' b1 =single(a1); */
  /* '<S16>:1:22' b2 =single(4+wc^2*Ts^2-2*wb*Ts); */
  /* '<S16>:1:24' temp = single(a0*x0+a1*x1+a2*x2-b1*y1-b2*y2); */
  ISP_n_test_notch = ((((a0_tmp * ISP_n) + (rtb_Gain1 *
    CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE_j)) + (a0_tmp *
    CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_d)) - (rtb_Gain1 * rtb_DTC3)) -
    ((a0_tmp - ((2.0F * g_msgCore0to2_wb) * 6.25E-5F)) * rtb_ISC_wElec);

  /* '<S16>:1:27' if(wc == single(0)) */
  if (ISP_speedref_final_wn == 0.0F) {
    /* '<S16>:1:28' temp = x0; */
    ISP_n_test_notch = ISP_n;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* Update for UnitDelay: '<S5>/Unit Delay2' */
  /*  if(n_abs<=500) */
  /*   */
  /*  y=x0; */
  /*   */
  /*  else */
  /* '<S16>:1:35' y= single(temp); */
  /* end */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE_n = ISP_agRtrElecAtan2;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE = ISP_frqElecCaln;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_f = ISP_uDcFlt;

  /* Update for UnitDelay: '<S5>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_p = omega_hat_K_1;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE = theta_hat_K_1;

  /* Update for UnitDelay: '<S3>/Unit Delay4' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay4_DSTATE = ISP_n;

  /* Update for UnitDelay: '<S3>/Unit Delay5' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay5_DSTATE = X111;

  /* Update for UnitDelay: '<S3>/Unit Delay6' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay6_DSTATE = test8;

  /* Update for UnitDelay: '<S3>/Unit Delay7' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay7_DSTATE = Y111;

  /* Update for UnitDelay: '<S3>/Unit Delay12' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay12_DSTATE = *y_ISP_nNotch;

  /* Update for UnitDelay: '<S3>/Unit Delay13' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay13_DSTATE = rtb_UnitDelay12;

  /* Update for UnitDelay: '<S3>/Unit Delay14' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay14_DSTATE = ISP_n_test_pp;

  /* Update for UnitDelay: '<S3>/Unit Delay15' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay15_DSTATE = rtb_UnitDelay14;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE_j = ISP_n;

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_d = rtb_Abs1;

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE = ISP_n_test_notch;

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay3_DSTATE = rtb_UnitDelay2;

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as a local variable.
   * As result, some Output functions may have unused tid.
   */
  (void) (tid);
}

/* Output and update for referenced model: 'CDD_ISP' */
void CDD_ISPTID1(void)
{
  int_T tid = 1;
  real32_T rtb_Divide;
  real32_T tmp;
  int16_T rtb_DTC4;

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/NpMotorDivNpResolver'
   *  Constant: '<S3>/NpMotorDivNpResolver1'
   */
  rtb_Divide = SC_p_P / SC_pRsv_P;

  /* DataTypeConversion: '<S3>/DTC4' */
  tmp = floorf(rtb_Divide);
  if (tmp < 32768.0F) {
    if (tmp >= -32768.0F) {
      rtb_DTC4 = (int16_T)tmp;
    } else {
      rtb_DTC4 = MIN_int16_T;
    }
  } else {
    rtb_DTC4 = MAX_int16_T;
  }

  /* End of DataTypeConversion: '<S3>/DTC4' */

  /* RateTransition: '<S3>/Rate Transition6' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition6_Buffer0 = rtb_Divide;

  /* RateTransition: '<S3>/Rate Transition8' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition8_Buffer0 = rtb_DTC4;

  /* If subsystem generates rate grouping Output functions,
   * when tid is used in Output function for one rate,
   * all Output functions include tid as a local variable.
   * As result, some Output functions may have unused tid.
   */
  (void) (tid);
}

/* Model initialize function */
void CDD_ISP_initialize(const char_T **rt_errorStatus, const rtTimingBridge
  *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1)
{
  CDD_ISPpmsmfoc_RT_MODEL *const CDD_ISPpmsmfoc_rtM =
    &(CDD_ISPpmsmfoc_rtMdlrefDWork.rtm);

  /* Registration code */

  /* setup the global timing engine */
  CDD_ISPpmsmfoc_rtGlobalTID[0] = mdlref_TID0;
  CDD_ISPpmsmfoc_rtGlobalTID[1] = mdlref_TID1;
  CDD_ISPpmsmfoc_rtTimingBridge = timingBridge;

  /* initialize error status */
  rtmSetErrorStatusPointer(CDD_ISPpmsmfoc_rtM, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
