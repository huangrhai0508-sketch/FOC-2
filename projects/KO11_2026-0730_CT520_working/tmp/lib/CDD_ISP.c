/*
 * File: CDD_ISP.c
 *
 * Code generated for Simulink model 'CDD_ISP'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  3 16:25:09 2025
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
int16_T ISP_agRoughCal;                /* '<S3>/AlOfsCalPosSet' */

/* Rough Calibrated output offset rotor angle */
int16_T ISP_agRtrElecAtan2;            /* '<S5>/DTC8' */

/* Electric angle of rotor calculated by atan2 */
int16_T ISP_agRtrElecObvr;             /* '<S5>/Add1' */

/* Electric angle of rotor by observer */
int16_T ISP_agRtrElecOld;              /* '<S5>/Unit Delay' */

/* Last Electric angle of rotor */
int16_T ISP_agRtrPoleTrans;            /* '<S3>/Product' */

/* Resolver electric angle transit to motor electric angle */
real32_T ISP_frqElec;                  /* '<S3>/Rate Transition10' */

/* Electric frequency of rotor */
real32_T ISP_frqElecCaln;              /* '<S10>/Sum1' */

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
real32_T ISP_n;                        /* '<S3>/Rate Transition1' */

/* mechanical speed */
uint8_T ISP_stAlOfsCal;                /* '<S3>/Rate Transition4' */

/* Position offset calitation state */
real32_T ISP_tmpClnt;                  /* '<Root>/Constant3' */

/* Coolant temperature */
real32_T ISP_tmpMaxIGBT;               /* '<Root>/Constant' */

/* Tj of IGBT */
real32_T ISP_uDcFlt;                   /* '<S15>/Sum1' */

/* Filtered DC link voltage */
real32_T ISP_wElec;                    /* '<S3>/Rate Transition2' */

/* Electric frequency of rotor */
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

  /* SystemInitialize for Enabled SubSystem: '<S3>/Angle Cal' */
  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay2' */
  /* '<S17>:1:18' reset = boolean(1); */
  /* '<S17>:1:19' times= uint8(0); */
  /* '<S17>:1:20' cnt = uint16(0); */
  /* '<S17>:1:21' tempofs = single(0); */
  /* '<S17>:1:22' tempU = single(0); */
  /* '<S17>:1:23' tempV = single(0); */
  /* '<S17>:1:24' tempW = single(0); */
  /* '<S17>:1:25' step = uint8(0); */
  /* '<S17>:1:26' Iddes = single(0); */
  /* '<S17>:1:27' Angle = single(0); */
  /* '<S17>:1:28' stAlOfsCaltemp = uint8(0); */
  /* '<S17>:1:29' agOffs_Caltemp = single(0); */
  /* '<S17>:1:30' tempV0 = single(0); */
  /* '<S18>:1:7' stRoughCalSetLast = uint8(0); */
  /* '<S18>:1:8' agRoughCal = int16(0); */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE_h = 500;

  /* End of SystemInitialize for SubSystem: '<S3>/Angle Cal' */
  /* '<S23>:1:6' bout_flt = single(0); */
}

/* System reset for referenced model: 'CDD_ISP' */
void CDD_ISP_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_f = 0.0F;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition8' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition8_Buffer0 = 2730;

  /* InitializeConditions for RateLimiter: '<S3>/Rate Limiter1' */
  CDD_ISPpmsmfoc_rtDWork.PrevY = 0.0F;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition6' */
  CDD_ISPpmsmfoc_rtDWork.RateTransition6_Buffer0 = 2730.0F;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_g = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE = 0;

  /* SystemReset for MATLAB Function: '<S3>/AlOfsCalFun2' */
  /* '<S17>:1:18' reset = boolean(1); */
  /* '<S17>:1:19' times= uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.times = 0U;

  /* '<S17>:1:20' cnt = uint16(0); */
  CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

  /* '<S17>:1:21' tempofs = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

  /* '<S17>:1:22' tempU = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempU = 0.0F;

  /* '<S17>:1:23' tempV = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempV = 0.0F;

  /* '<S17>:1:24' tempW = single(0); */
  CDD_ISPpmsmfoc_rtDWork.tempW = 0.0F;

  /* '<S17>:1:25' step = uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.step = 0U;

  /* '<S17>:1:26' Iddes = single(0); */
  CDD_ISPpmsmfoc_rtDWork.Iddes = 0.0F;

  /* '<S17>:1:27' Angle = single(0); */
  CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;

  /* '<S17>:1:28' stAlOfsCaltemp = uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp = 0U;

  /* '<S17>:1:29' agOffs_Caltemp = single(0); */
  CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp = 0.0F;

  /* SystemReset for MATLAB Function: '<S3>/AlOfsCalPosSet' */
  /* '<S17>:1:30' tempV0 = single(0); */
  /* '<S18>:1:7' stRoughCalSetLast = uint8(0); */
  CDD_ISPpmsmfoc_rtDWork.stRoughCalSetLast = 0U;

  /* '<S18>:1:8' agRoughCal = int16(0); */
  CDD_ISPpmsmfoc_rtDWork.agRoughCal = 0;

  /* SystemReset for MATLAB Function: '<S3>/filter' */
  /* '<S23>:1:6' bout_flt = single(0); */
  CDD_ISPpmsmfoc_rtDWork.bout_flt = 0.0F;
}

/* Output and update for referenced model: 'CDD_ISP' */
void CDD_ISPTID0(const real32_T *u_PMC_Out_Core2_PMC_UsdScal, const real32_T
                 *u_PMC_Out_Core2_PMC_tiPerd, const uint16_T
                 *u_ACI_Out_Core2_SAQ_iPhaU, const uint16_T
                 *u_ACI_Out_Core2_SAQ_iPhaV, const uint16_T
                 *u_ACI_Out_Core2_SAQ_iPhaW, const int16_T
                 *u_ACI_Out_Core2_SAQ_rslvSinAmp, const real32_T
                 *u_ACI_Out_Core2_SAQ_HVU, const Sig10ms02ST *u_msgCore0to2_10ms,
                 const uint8_T *u_msgCore0to2_1ms_TCC_stRoughCalSet, const
                 int16_T *u_Angleoffset_Init, const real32_T *u_Uoffset, const
                 real32_T *u_Voffset, const real32_T *u_Woffset, Core2_ISP_Out
                 *y_ISP_Out, real32_T *y_Iddes)
{
  int_T tid = 0;
  real_T rtb_Divide1;
  int32_T tmp_0;
  real32_T rtb_DTC3;
  real32_T rtb_Divide_i;
  real32_T rtb_Gain1;
  int16_T rtb_Gain3;
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
  rtb_Divide_i = (*u_PMC_Out_Core2_PMC_tiPerd) * f32_SpeedFltCoef;

  /* Product: '<S5>/Divide1' incorporates:
   *  Constant: '<S5>/Constant6'
   */
  rtb_Divide1 = 1.0 / rtb_Divide_i;

  /* Product: '<S5>/Divide' incorporates:
   *  DataTypeConversion: '<S5>/DTC6'
   *  Sum: '<S5>/Add3'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_Gain1 *= (real32_T)((int16_T)floorf(rtb_DTC3 -
    CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE));

  /* Saturate: '<S5>/Saturation' */
  if (rtb_Gain1 > 2000.0F) {
    rtb_Gain1 = 2000.0F;
  } else if (rtb_Gain1 < -2000.0F) {
    rtb_Gain1 = -2000.0F;
  }

  /* Sum: '<S10>/Sum1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product3'
   *  Saturate: '<S5>/Saturation'
   *  Sum: '<S10>/Subtract'
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  ISP_frqElecCaln = ((real32_T)((1.0 - rtb_Divide1) *
    CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE)) + ((real32_T)(rtb_Gain1 *
    rtb_Divide1));

  /* Sum: '<S4>/sub' */
  rtb_Gain1 = ((real32_T)(*u_ACI_Out_Core2_SAQ_iPhaU)) - (*u_Uoffset);

  /* Product: '<S4>/mul' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C'
   */
  rtb_Gain1 *= facAdc2iPh_C;

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C2'
   *  Constant: '<S4>/IdcMaxMdl_C3'
   *  RelationalOperator: '<S7>/LowerRelop1'
   *  RelationalOperator: '<S7>/UpperRelop'
   *  Switch: '<S7>/Switch'
   */
  if (rtb_Gain1 > iPhaMax_C) {
    /* Switch: '<S7>/Switch2' */
    ISP_iPhaU = iPhaMax_C;
  } else if (rtb_Gain1 < iPhaMin_C) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S4>/IdcMaxMdl_C3'
     *  Switch: '<S7>/Switch2'
     */
    ISP_iPhaU = iPhaMin_C;
  } else {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Switch: '<S7>/Switch'
     */
    ISP_iPhaU = rtb_Gain1;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Sum: '<S4>/sub 1' */
  rtb_Gain1 = ((real32_T)(*u_ACI_Out_Core2_SAQ_iPhaV)) - (*u_Voffset);

  /* Product: '<S4>/mul 1' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C'
   */
  rtb_Gain1 *= facAdc2iPh_C;

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C2'
   *  Constant: '<S4>/IdcMaxMdl_C3'
   *  RelationalOperator: '<S8>/LowerRelop1'
   *  RelationalOperator: '<S8>/UpperRelop'
   *  Switch: '<S8>/Switch'
   */
  if (rtb_Gain1 > iPhaMax_C) {
    /* Switch: '<S8>/Switch2' */
    ISP_iPhaV = iPhaMax_C;
  } else if (rtb_Gain1 < iPhaMin_C) {
    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S4>/IdcMaxMdl_C3'
     *  Switch: '<S8>/Switch2'
     */
    ISP_iPhaV = iPhaMin_C;
  } else {
    /* Switch: '<S8>/Switch2' incorporates:
     *  Switch: '<S8>/Switch'
     */
    ISP_iPhaV = rtb_Gain1;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Sum: '<S4>/sub 2' */
  rtb_Gain1 = ((real32_T)(*u_ACI_Out_Core2_SAQ_iPhaW)) - (*u_Woffset);

  /* Product: '<S4>/mul 2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C'
   */
  rtb_Gain1 *= facAdc2iPh_C;

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S4>/IdcMaxMdl_C2'
   *  Constant: '<S4>/IdcMaxMdl_C3'
   *  RelationalOperator: '<S9>/LowerRelop1'
   *  RelationalOperator: '<S9>/UpperRelop'
   *  Switch: '<S9>/Switch'
   */
  if (rtb_Gain1 > iPhaMax_C) {
    /* Switch: '<S9>/Switch2' */
    ISP_iPhaW = iPhaMax_C;
  } else if (rtb_Gain1 < iPhaMin_C) {
    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S4>/IdcMaxMdl_C3'
     *  Switch: '<S9>/Switch2'
     */
    ISP_iPhaW = iPhaMin_C;
  } else {
    /* Switch: '<S9>/Switch2' incorporates:
     *  Switch: '<S9>/Switch'
     */
    ISP_iPhaW = rtb_Gain1;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Product: '<S6>/Product3' incorporates:
   *  Constant: '<S6>/facAdc2uDclnk_C'
   */
  rtb_Gain1 = (*u_ACI_Out_Core2_SAQ_HVU) * facAdc2uDclnk_C;

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S6>/IdcMaxMdl_C1'
   *  Constant: '<S6>/IdcMaxMdl_C2'
   *  RelationalOperator: '<S16>/LowerRelop1'
   *  RelationalOperator: '<S16>/UpperRelop'
   *  Switch: '<S16>/Switch'
   */
  if (rtb_Gain1 > uDcMax_C) {
    rtb_Gain1 = uDcMax_C;
  } else if (rtb_Gain1 < uDcMin_C) {
    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S6>/IdcMaxMdl_C1'
     */
    rtb_Gain1 = uDcMin_C;
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/dtPT1UdcLink1'
   *  Constant: '<S6>/tauUdcPT1_C'
   */
  rtb_Divide_i = 0.0001F / tauUdcPT1_C;

  /* Sum: '<S15>/Sum1' incorporates:
   *  Constant: '<S15>/Constant'
   *  Product: '<S15>/Product1'
   *  Product: '<S15>/Product3'
   *  Sum: '<S15>/Subtract'
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  ISP_uDcFlt = ((1.0F - rtb_Divide_i) *
                CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_f) + (rtb_Gain1 *
    rtb_Divide_i);

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
  rtb_Gain1 = 0.00549328327F * ((real32_T)((uint16_T)tmp_0));

  /* RelationalOperator: '<S3>/Equal' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  rtb_Equal = (u_msgCore0to2_10ms->SSM_stDrvMode != alOfsCal);

  /* MATLAB Function: '<S3>/AlOfsCalFun2' incorporates:
   *  Constant: '<S3>/Constant4'
   */
  /*  */
  /* MATLAB Function 'ISP_ResolverSel/AlOfsCalFun2': '<S17>:1' */
  /* ISC_agOffs_P = int16(Angleoffset_Init);  % */
  /* '<S17>:1:17' if isempty(reset) */
  /* '<S17>:1:32' if (ROLreset==boolean(1)) */
  if (rtb_Equal) {
    /* '<S17>:1:33' times= uint8(0); */
    CDD_ISPpmsmfoc_rtDWork.times = 0U;

    /* '<S17>:1:34' cnt = uint16(0); */
    CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

    /* '<S17>:1:35' tempofs = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

    /* '<S17>:1:36' tempU = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempU = 0.0F;

    /* '<S17>:1:37' tempV = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempV = 0.0F;

    /* '<S17>:1:38' tempW = single(0); */
    CDD_ISPpmsmfoc_rtDWork.tempW = 0.0F;

    /* '<S17>:1:39' step = uint8(0); */
    CDD_ISPpmsmfoc_rtDWork.step = 0U;

    /* '<S17>:1:40' Iddes = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Iddes = 0.0F;

    /* '<S17>:1:41' Angle = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;

    /* '<S17>:1:42' stAlOfsCaltemp = uint8(0); */
    CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp = 0U;

    /* '<S17>:1:43' agOffs_Caltemp = single(0); */
    CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp = 0.0F;

    /* '<S17>:1:44' tempV0 = single(0); */
  }

  /* '<S17>:1:47' if(stDrvMode == ECM.alOfsCal&&step==uint8(0)&&stAlOfsCaltemp==uint8(0)) */
  if (((u_msgCore0to2_10ms->SSM_stDrvMode == alOfsCal) &&
       (CDD_ISPpmsmfoc_rtDWork.step == 0)) &&
      (CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp == 0)) {
    /* '<S17>:1:48' Angle = single(120); */
    CDD_ISPpmsmfoc_rtDWork.Angle = 120.0F;

    /* '<S17>:1:49' if(Iddes<single(IdROL_C)) */
    if (CDD_ISPpmsmfoc_rtDWork.Iddes < IdROL_C) {
      /* '<S17>:1:50' Iddes = Iddes+single(0.01); */
      CDD_ISPpmsmfoc_rtDWork.Iddes += 0.01F;
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S17>:1:51' elseif(cnt<uint16(10000)) */
      /* '<S17>:1:52' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:53' else */
      /* '<S17>:1:54' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S17>:1:55' step=uint8(1); */
      CDD_ISPpmsmfoc_rtDWork.step = 1U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 1) {
    /* '<S17>:1:57' elseif(step==uint8(1)) */
    /* '<S17>:1:58' if(Angle < single(240)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 240.0F) {
      /* '<S17>:1:59' Angle = Angle + single(0.05); */
      CDD_ISPpmsmfoc_rtDWork.Angle += 0.05F;
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S17>:1:61' elseif(cnt<uint16(10000)) */
      /* '<S17>:1:62' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:63' else */
      /* '<S17>:1:64' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S17>:1:65' step=uint8(2); */
      CDD_ISPpmsmfoc_rtDWork.step = 2U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 2) {
    /* '<S17>:1:67' elseif(step==uint8(2)) */
    /* '<S17>:1:68' if(Angle < single(360)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 360.0F) {
      /* '<S17>:1:69' Angle = Angle + single(0.05); */
      CDD_ISPpmsmfoc_rtDWork.Angle += 0.05F;
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S17>:1:71' elseif(cnt<uint16(10000)) */
      /* '<S17>:1:72' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:73' else */
      /* '<S17>:1:74' Angle = single(0); */
      CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;

      /* '<S17>:1:75' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S17>:1:76' step=uint8(3); */
      CDD_ISPpmsmfoc_rtDWork.step = 3U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 3) {
    /* '<S17>:1:78' elseif(step==uint8(3)) */
    /* '<S17>:1:79' if(Angle<single(120)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 120.0F) {
      /* '<S17>:1:80' Angle=Angle+single(0.005); */
      CDD_ISPpmsmfoc_rtDWork.Angle += 0.005F;

      /* '<S17>:1:81' else */
      /* '<S17>:1:82' if(cnt<10000) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S17>:1:83' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:84' else */
      /* '<S17>:1:85' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S17>:1:86' step=uint8(4); */
      CDD_ISPpmsmfoc_rtDWork.step = 4U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 4) {
    /* '<S17>:1:89' elseif(step==4) */
    /* '<S17>:1:90' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S17>:1:91' tempV0 = Angle - AngleAct; */
      rtb_Gain1 = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_Gain1;

      /* '<S17>:1:92' if(tempV0<single(0)) */
      if (rtb_Gain1 < 0.0F) {
        /* '<S17>:1:93' tempV0=tempV0+single(360); */
        rtb_Gain1 += 360.0F;
      }

      /* '<S17>:1:95' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_Gain1;

      /* '<S17>:1:96' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:97' else */
      /* '<S17>:1:98' tempV=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempV = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S17>:1:99' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S17>:1:100' step=uint8(5); */
      CDD_ISPpmsmfoc_rtDWork.step = 5U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 5) {
    /* '<S17>:1:102' elseif(step==5) */
    /* '<S17>:1:103' if(Angle<single(240)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 240.0F) {
      /* '<S17>:1:104' Angle=Angle+single(0.005); */
      CDD_ISPpmsmfoc_rtDWork.Angle += 0.005F;

      /* '<S17>:1:105' else */
      /* '<S17>:1:106' if(cnt<uint16(10000)) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S17>:1:107' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:108' else */
      /* '<S17>:1:109' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S17>:1:110' step=uint8(6); */
      CDD_ISPpmsmfoc_rtDWork.step = 6U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 6) {
    /* '<S17>:1:114' elseif(step==6) */
    /* '<S17>:1:115' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S17>:1:116' tempV0 = Angle - AngleAct; */
      rtb_Gain1 = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_Gain1;

      /* '<S17>:1:117' if(tempV0<single(0)) */
      if (rtb_Gain1 < 0.0F) {
        /* '<S17>:1:118' tempV0=tempV0+single(360); */
        rtb_Gain1 += 360.0F;
      }

      /* '<S17>:1:120' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_Gain1;

      /* '<S17>:1:121' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:122' else */
      /* '<S17>:1:123' tempW=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempW = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S17>:1:124' if(tempW<0) */
      if (CDD_ISPpmsmfoc_rtDWork.tempW < 0.0F) {
        /* '<S17>:1:125' tempW=tempW+single(360); */
        CDD_ISPpmsmfoc_rtDWork.tempW += 360.0F;
      }

      /* '<S17>:1:127' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S17>:1:128' step=uint8(7); */
      CDD_ISPpmsmfoc_rtDWork.step = 7U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 7) {
    /* '<S17>:1:131' elseif(step==uint8(7)) */
    /* '<S17>:1:132' if(Angle<single(360)) */
    if (CDD_ISPpmsmfoc_rtDWork.Angle < 360.0F) {
      /* '<S17>:1:133' Angle=Angle+single(0.005); */
      CDD_ISPpmsmfoc_rtDWork.Angle += 0.005F;

      /* '<S17>:1:134' else */
      /* '<S17>:1:136' if(cnt<uint16(10000)) */
    } else if (CDD_ISPpmsmfoc_rtDWork.cnt < 10000) {
      /* '<S17>:1:137' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:138' else */
      /* '<S17>:1:139' cnt=uint16(0); */
      CDD_ISPpmsmfoc_rtDWork.cnt = 0U;

      /* '<S17>:1:140' step=uint8(8); */
      CDD_ISPpmsmfoc_rtDWork.step = 8U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 8) {
    /* '<S17>:1:143' elseif(step==uint8(8)) */
    /* '<S17>:1:144' if(cnt<uint16(100)) */
    if (CDD_ISPpmsmfoc_rtDWork.cnt < 100) {
      /* '<S17>:1:145' tempV0 = Angle - AngleAct; */
      rtb_Gain1 = CDD_ISPpmsmfoc_rtDWork.Angle - rtb_Gain1;

      /* '<S17>:1:146' if(tempV0<single(0)) */
      if (rtb_Gain1 < 0.0F) {
        /* '<S17>:1:147' tempV0=tempV0+single(360); */
        rtb_Gain1 += 360.0F;
      }

      /* '<S17>:1:149' tempofs=tempofs + tempV0; */
      CDD_ISPpmsmfoc_rtDWork.tempofs += rtb_Gain1;

      /* '<S17>:1:150' cnt=cnt+uint16(1); */
      CDD_ISPpmsmfoc_rtDWork.cnt++;
    } else {
      /* '<S17>:1:151' else */
      /* '<S17>:1:152' tempU=single(tempofs/single(100)); */
      CDD_ISPpmsmfoc_rtDWork.tempU = CDD_ISPpmsmfoc_rtDWork.tempofs / 100.0F;

      /* '<S17>:1:153' if(tempU<0) */
      if (CDD_ISPpmsmfoc_rtDWork.tempU < 0.0F) {
        /* '<S17>:1:154' tempU=tempU+single(360); */
        CDD_ISPpmsmfoc_rtDWork.tempU += 360.0F;
      }

      /* '<S17>:1:157' tempofs = single(0); */
      CDD_ISPpmsmfoc_rtDWork.tempofs = 0.0F;

      /* '<S17>:1:158' step=uint8(9); */
      CDD_ISPpmsmfoc_rtDWork.step = 9U;
    }
  } else if (CDD_ISPpmsmfoc_rtDWork.step == 9) {
    int32_T tmp;

    /* '<S17>:1:161' elseif(step==uint8(9)) */
    /* '<S17>:1:162' agOffs_Caltemp = agOffs_Caltemp + ((tempU)+(tempV)+(tempW))/3; */
    CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp += ((CDD_ISPpmsmfoc_rtDWork.tempU +
      CDD_ISPpmsmfoc_rtDWork.tempV) + CDD_ISPpmsmfoc_rtDWork.tempW) / 3.0F;

    /* '<S17>:1:163' times = times + uint8(1); */
    tmp = (int32_T)(CDD_ISPpmsmfoc_rtDWork.times + 1U);
    if ((CDD_ISPpmsmfoc_rtDWork.times + 1U) > 255U) {
      tmp = 255;
    }

    CDD_ISPpmsmfoc_rtDWork.times = (uint8_T)tmp;

    /* '<S17>:1:164' if(times>uint8(9)) */
    if (CDD_ISPpmsmfoc_rtDWork.times > 9) {
      /* '<S17>:1:165' agOffs_Caltemp = agOffs_Caltemp/single(10); */
      CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp /= 10.0F;

      /* '<S17>:1:166' stAlOfsCaltemp = uint8(1); */
      CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp = 1U;

      /* '<S17>:1:167' step=uint8(0); */
      CDD_ISPpmsmfoc_rtDWork.step = 0U;

      /* '<S17>:1:168' if(Iddes>single(0)) */
      if (CDD_ISPpmsmfoc_rtDWork.Iddes > 0.0F) {
        /* '<S17>:1:169' Iddes = Iddes - single(0.1); */
        CDD_ISPpmsmfoc_rtDWork.Iddes -= 0.1F;
      }
    } else {
      /* '<S17>:1:171' else */
      /* '<S17>:1:172' step=uint8(3); */
      CDD_ISPpmsmfoc_rtDWork.step = 3U;

      /* '<S17>:1:173' Angle = single(0); */
      CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;
    }
  } else {
    /* '<S17>:1:175' else */
    /* '<S17>:1:176' Iddes = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Iddes = 0.0F;

    /* '<S17>:1:177' Angle = single(0); */
    CDD_ISPpmsmfoc_rtDWork.Angle = 0.0F;
  }

  /* '<S17>:1:179' stAlOfsCal = stAlOfsCaltemp; */
  /* '<S17>:1:180' AngleOP = Angle; */
  /* '<S17>:1:181' Iddesout = Iddes; */
  *y_Iddes = CDD_ISPpmsmfoc_rtDWork.Iddes;

  /* Switch: '<S3>/Switch' incorporates:
   *  Gain: '<S3>/Gain5'
   *  MATLAB Function: '<S3>/AlOfsCalFun2'
   */
  /* '<S17>:1:182' agOffs_Cal = single(agOffs_Caltemp); */
  if (rtb_Equal) {
    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S3>/agOffs_test'
     *  Gain: '<S3>/agNegTrans'
     */
    rtb_Gain3 = (int16_T)(((int16_T)((*u_Angleoffset_Init) + ((int16_T)tmp_0)))
                          + offsAgRtrElec_C);
  } else {
    rtb_Gain3 = (int16_T)floorf(182.041672F * CDD_ISPpmsmfoc_rtDWork.Angle);
  }

  /* End of Switch: '<S3>/Switch' */

  /* MATLAB Function: '<S3>/AlOfsCalPosSet' */
  /*  */
  /* MATLAB Function 'ISP_ResolverSel/AlOfsCalPosSet': '<S18>:1' */
  /* '<S18>:1:6' if isempty(stRoughCalSetLast) */
  /* '<S18>:1:11' if stRoughCalSet==uint8(0) */
  if ((*u_msgCore0to2_1ms_TCC_stRoughCalSet) != 0) {
    if ((*u_msgCore0to2_1ms_TCC_stRoughCalSet) == 5) {
      /* '<S18>:1:13' elseif stRoughCalSet==uint8(5) */
      /* '<S18>:1:14' if stRoughCalSetLast==uint8(4) */
      if (CDD_ISPpmsmfoc_rtDWork.stRoughCalSetLast == 4) {
        /* '<S18>:1:15' agRoughCal = agIn; */
        CDD_ISPpmsmfoc_rtDWork.agRoughCal = rtb_Gain3;
      }

      /* '<S18>:1:17' agOut = agIn + agRoughCal; */
      tmp_0 = rtb_Gain3 + CDD_ISPpmsmfoc_rtDWork.agRoughCal;
      if (tmp_0 > 32767) {
        tmp_0 = 32767;
      } else if (tmp_0 < -32768) {
        tmp_0 = -32768;
      }

      rtb_Gain3 = (int16_T)tmp_0;
    } else {
      /* '<S18>:1:18' else */
      /* '<S18>:1:19' agOut = int16(0); */
      rtb_Gain3 = 0;
    }
  } else {
    /* '<S18>:1:12' agOut = agIn; */
  }

  /* '<S18>:1:22' stRoughCalSetLast = stRoughCalSet; */
  CDD_ISPpmsmfoc_rtDWork.stRoughCalSetLast =
    *u_msgCore0to2_1ms_TCC_stRoughCalSet;

  /* '<S18>:1:23' agRoughCalOut = agRoughCal; */
  ISP_agRoughCal = CDD_ISPpmsmfoc_rtDWork.agRoughCal;

  /* End of MATLAB Function: '<S3>/AlOfsCalPosSet' */

  /* RateLimiter: '<S3>/Rate Limiter1' incorporates:
   *  RateTransition: '<Root>/Rate Transition1'
   */
  rtb_Gain1 = u_msgCore0to2_10ms->ISP_frqDes - CDD_ISPpmsmfoc_rtDWork.PrevY;
  if (rtb_Gain1 > 0.05F) {
    CDD_ISPpmsmfoc_rtDWork.PrevY += 0.05F;
  } else if (rtb_Gain1 < -0.05F) {
    CDD_ISPpmsmfoc_rtDWork.PrevY -= 0.05F;
  } else {
    CDD_ISPpmsmfoc_rtDWork.PrevY = u_msgCore0to2_10ms->ISP_frqDes;
  }

  /* End of RateLimiter: '<S3>/Rate Limiter1' */

  /* RateTransition: '<S3>/Rate Transition6' */
  if (rtmIsSpecialSampleHit(1, 0, tid)) {
    /* RateTransition: '<S3>/Rate Transition6' */
    CDD_ISPpmsmfoc_rtDWork.RateTransition6 =
      CDD_ISPpmsmfoc_rtDWork.RateTransition6_Buffer0;
  }

  /* End of RateTransition: '<S3>/Rate Transition6' */

  /* Sum: '<S21>/Sum1' incorporates:
   *  BusCreator: '<S1>/Bus Creator'
   *  Product: '<S3>/Product1'
   */
  rtb_Divide_i = CDD_ISPpmsmfoc_rtDWork.RateTransition6 * ISP_frqElecCaln;

  /* Gain: '<S3>/wNegTrans' */
  rtb_Gain1 = ((real32_T)wNegTrans_C) * rtb_Divide_i;

  /* RateTransition: '<S3>/Rate Transition10' incorporates:
   *  MultiPortSwitch: '<S3>/IV3'
   */
  ISP_frqElec = rtb_Gain1;

  /* RateTransition: '<S3>/Rate Transition2' incorporates:
   *  Gain: '<S3>/fac2piFrq2w'
   *  MultiPortSwitch: '<S3>/IV4'
   */
  ISP_wElec = 6.28318548F * rtb_Gain1;

  /* Gain: '<S3>/facf2n' incorporates:
   *  MultiPortSwitch: '<S3>/IV5'
   */
  rtb_Gain1 *= 60.0F / SC_p_P;

  /* Saturate: '<S3>/Saturation' incorporates:
   *  MultiPortSwitch: '<S3>/IV5'
   */
  if (rtb_Gain1 > 20000.0F) {
    rtb_Gain1 = 20000.0F;
  } else if (rtb_Gain1 < -20000.0F) {
    rtb_Gain1 = -20000.0F;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* RateTransition: '<S3>/Rate Transition1' */
  ISP_n = rtb_Gain1;

  /* BusCreator: '<S2>/Bus Creator' incorporates:
   *  BusCreator: '<S3>/Bus Creator'
   */
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_Is = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isd = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isq = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_sin = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isdH6 = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_isqH6 = 0.0F;
  y_ISP_Out->Core2_ISP_Isx.Core2_ISP_AngleOut = (uint16_T)rtb_Gain3;

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
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S5>/Constant4'
   *  Gain: '<S3>/Gain3'
   *  MATLAB Function: '<S3>/AlOfsCalFun2'
   */
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_stAlOfsCal =
    CDD_ISPpmsmfoc_rtDWork.stAlOfsCaltemp;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_agOffsCal = (int16_T)floorf(182.041672F *
    CDD_ISPpmsmfoc_rtDWork.agOffs_Caltemp);
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_agRtrElec = rtb_Gain3;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_frqElec = ISP_frqElec;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_wElec = ISP_wElec;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_n = ISP_n;
  y_ISP_Out->Core2_ISP_nx.Core2_ISP_nAbs = fabsf(rtb_Gain1);
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISP_flgResolver = 1U;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISC_agRtrElecObvr = 0;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISC_frqElecObvr = 0.0F;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISC_agRtrElecAtan2 =
    ISP_agRtrElecAtan2;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISC_frqElecCaln =
    ISP_frqElecCaln;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaU = ISP_iPhaU;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaV = ISP_iPhaV;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaW = ISP_iPhaW;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_bIphCalDone = true;
  y_ISP_Out->Core2_ISP_AnaOut.Core2_ISP_uDc = ISP_uDcFlt;

  /* UnitDelay: '<S5>/Unit Delay' */
  ISP_agRtrElecOld = CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE;

  /* Sum: '<S5>/Add1' */
  ISP_agRtrElecObvr = ISP_agRtrElecOld;

  /* MATLAB Function: '<S3>/filter' incorporates:
   *  Constant: '<S3>/Constant'
   */
  /*  */
  /* MATLAB Function 'ISP_ResolverSel/filter': '<S23>:1' */
  /* '<S23>:1:5' if isempty(bout_flt) */
  /* '<S23>:1:9' Out = bin*Cof+bout_flt*(single(1)-Cof); */
  CDD_ISPpmsmfoc_rtDWork.bout_flt = ((*u_PMC_Out_Core2_PMC_UsdScal) * 0.2F) +
    (CDD_ISPpmsmfoc_rtDWork.bout_flt * 0.8F);

  /* RateTransition: '<S3>/Rate Transition4' */
  /* '<S23>:1:10' bout_flt = Out; */
  ISP_stAlOfsCal = 0U;

  /* Update for UnitDelay: '<S5>/Unit Delay2' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay2_DSTATE = rtb_DTC3;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE = ISP_frqElecCaln;

  /* Update for UnitDelay: '<S15>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_f = ISP_uDcFlt;

  /* Update for UnitDelay: '<S21>/Unit Delay1' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay1_DSTATE_g = rtb_Divide_i;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  CDD_ISPpmsmfoc_rtDWork.UnitDelay_DSTATE = ISP_agRtrElecObvr;

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
