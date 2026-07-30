/*
 * File: pmsmfoc.c
 *
 * Code generated for Simulink model 'pmsmfoc'.
 *
 * Model version                  : 11.145
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 28 23:06:30 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "pmsmfoc.h"
#include "rtwtypes.h"
#include "EGM.h"
#include "ECM.h"
#include "pmsmfoc_types.h"
#include "parameter.h"
#include "pmsmfoc_private.h"
#define CDD_ISP_MDLREF_HIDE_CHILD_
#include "CDD_ISP.h"
#define FOC_MDLREF_HIDE_CHILD_
#include "FOC.h"

rtTimingBridge GRTimingBridge;         /* Exported data definition */

/* Definition for custom storage class: ExportToFile */
int16_T ISP_agRtrElecAtan2;            /* '<Root>/CDD&ISP' */

/* Electric angle of rotor calculated by atan2 */
real32_T ISP_n;                        /* '<Root>/CDD&ISP' */

/* mechanical speed */
real32_T ISP_speedref_final;           /* '<Root>/Rate Transition12' */

/* TODO */
real32_T PMC_IsdDes;                   /* '<S2>/Model' */

/* d-axis target current */
real32_T PMC_IsqDes;                   /* '<S2>/Model' */

/* q-axis target current */
real32_T PMC_TrqOutEst;                /* '<S2>/Model' */

/* Estimated output torque */
real32_T PMC_UsMax;                    /* '<S4>/facVdc2Vsmax' */

/* SVPWM maximum phase voltage */
real32_T PMC_UsdFlt;                   /* '<S2>/Model' */

/* d axis output Nrm voltage */
real32_T PMC_UsqFlt;                   /* '<S2>/Model' */

/* q axis output Nrm voltage */
boolean_T PMC_flgReqSafeSt;            /* '<S4>/Rate Transition5' */

/* Safe state flag */
EGM PMC_stGateDrv;                     /* '<S4>/Constant4' */

/* gate drive mode from the statemachine */
real32_T PMC_tiPerd;                   /* '<S4>/Constant3' */

/* Period time output from MCT considering variable freuqency and random frequency */
real32_T Trqdes_P1;                    /* '<Root>/Rate Transition8' */

/* TODO */
real32_T usage;                        /* '<S2>/Model' */

/* cmprW */

/* Block signals and states (default storage) */
pmsmfoc_D_Work GRDWork;

/* External inputs (root inport signals with default storage) */
pmsmfoc_ExternalInputs GRU;

/* External outputs (root outports fed by signals with default storage) */
pmsmfoc_ExternalOutputs GRY;

/* Real-time model */
static pmsmfoc_RT_MODEL GRM_;

/* Const memory section */
pmsmfoc_RT_MODEL *const GRM = &GRM_;

/* Model step function for TID0 */
void pmsmfoc_step0(void)               /* Sample time: [0.0001s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_RateTransition3_g;
  real32_T rtb_f32_DutyUon;
  real32_T rtb_f32_DutyVon;
  real32_T rtb_f32_DutyWon;
  ECM rtb_RateTransition4_f;
  real32_T rtb_RateTransition2;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0001s, 0.0s] to Sample time: [0.001s, 0.0s]  */
  GRM->Timing.RateInteraction.b_TID0_1 = (GRM->Timing.RateInteraction.TID0_1 ==
    0);
  (GRM->Timing.RateInteraction.TID0_1)++;
  if ((GRM->Timing.RateInteraction.TID0_1) > 9) {
    GRM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0001s, 0.0s] to Sample time: [0.01s, 0.0s]  */
  GRM->Timing.RateInteraction.b_TID0_2 = (GRM->Timing.RateInteraction.TID0_2 ==
    0);
  (GRM->Timing.RateInteraction.TID0_2)++;
  if ((GRM->Timing.RateInteraction.TID0_2) > 99) {
    GRM->Timing.RateInteraction.TID0_2 = 0;
  }

  /* UnitDelay: '<S2>/Unit Delay' */
  GRDWork.BusCreator1.Core2_PMC_UsdScal = GRDWork.UnitDelay_DSTATE;

  /* Constant: '<S4>/Constant3' */
  PMC_tiPerd = g_msgCore0to2_pwmFrqSet;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/PWMFrqSet'
   */
  if (PWMFrqSwitch_C) {
    GRDWork.BusCreator1.Core2_PMC_tiPerd = GRU.PWMFrqSet;
  } else {
    GRDWork.BusCreator1.Core2_PMC_tiPerd = PMC_tiPerd;
  }

  /* End of Switch: '<S4>/Switch' */

  /* RateTransition: '<S4>/Rate Transition5' */
  PMC_flgReqSafeSt = GRDWork.RateTransition5_Buffer0;

  /* RateTransition: '<S2>/Rate Transition2' */
  rtb_RateTransition2 =
    GRDWork.RateTransition2_Buffer[GRDWork.RateTransition2_ActiveBufIdx];

  /* BusCreator: '<S4>/Bus Creator1' */
  GRDWork.BusCreator1.Core2_PMC_stGateDrv = PMC_stGateDrv;
  GRDWork.BusCreator1.Core2_PMC_flgReqSafeSt = PMC_flgReqSafeSt;
  GRDWork.BusCreator1.Core2_PMC_Rs = 0.0F;
  GRDWork.BusCreator1.Core2_PMC_TrqOutEst = rtb_RateTransition2;

  /* Outport: '<Root>/stGateDrv' */
  GRY.stGateDrv = GRDWork.BusCreator1.Core2_PMC_stGateDrv;

  /* RateTransition: '<Root>/Rate Transition' */
  GRDWork.RateTransition =
    GRDWork.RateTransition_Buffer[GRDWork.RateTransition_ActiveBufIdx];

  /* RateTransition: '<Root>/Rate Transition12' incorporates:
   *  Inport: '<Root>/speed_ref'
   */
  ISP_speedref_final = GRU.speed_ref;

  /* ModelReference generated from: '<Root>/CDD&ISP' incorporates:
   *  Inport: '<Root>/Angleoffset_Init'
   *  Inport: '<Root>/Uoffset'
   *  Inport: '<Root>/Voffset'
   *  Inport: '<Root>/Woffset'
   *  Inport: '<Root>/cddin'
   *  Outport: '<Root>/ISP_n111'
   *  Outport: '<Root>/ISP_n222'
   */
  profileStart_pmsmfoc(1U); /* original_line:172 */CDD_ISPTID0(&GRDWork.BusCreator1.Core2_PMC_tiPerd, &GRU.cddin.Core2_iPhaU,
              &GRU.cddin.Core2_iPhaV, &GRU.cddin.Core2_iPhaW,
              &GRU.cddin.Core2_RvSin, &GRU.cddin.Core2_Udc,
              &GRDWork.RateTransition, &GRDWork.UD2.TCC_stRoughCalSet,
              &GRU.Angleoffset_Init, &GRU.Uoffset, &GRU.Voffset, &GRU.Woffset,
              &GRDWork.ISP_Out, &GRDWork.CDDISP_o2, &GRY.ISP_n111, &GRY.ISP_n222);profileEnd_pmsmfoc(1U); /* original_line:177 */

  /* RateTransition: '<S2>/Rate Transition3' */
  rtb_RateTransition3_g =
    GRDWork.RateTransition3_Buffer[GRDWork.RateTransition3_ActiveBufIdx];

  /* RateTransition: '<S2>/Rate Transition4' */
  rtb_RateTransition4_f =
    GRDWork.RateTransition4_Buffer[GRDWork.RateTransition4_ActiveBufIdx];

  /* RateTransition: '<Root>/Rate Transition8' incorporates:
   *  Inport: '<Root>/TrqEmDes'
   */
  Trqdes_P1 = GRU.TrqEmDes;

  /* ModelReference generated from: '<S2>/Model' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/Drive'
   *  Inport: '<Root>/PWMFrqSet'
   *  Inport: '<Root>/UdHCIF'
   *  Inport: '<Root>/UqHCIF'
   *  Inport: '<Root>/f32_Iddes_A'
   *  Inport: '<Root>/f32_Iqdes_A'
   *  Outport: '<Root>/Id'
   *  Outport: '<Root>/Iq'
   *  Outport: '<Root>/KpCoef'
   *  Outport: '<Root>/Ts'
   *  Outport: '<Root>/isdSet_last'
   */
  profileStart_pmsmfoc(2U); /* original_line:206 */FOCTID0(&GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaU,
          &GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaV,
          &GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaW,
          &GRDWork.ISP_Out.Core2_ISP_nx.Core2_ISP_n, &rtb_RateTransition3_g,
          &GRU.f32_Iddes_A, &GRU.f32_Iqdes_A,
          &GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_uDc, &rtCP_Constant_Value,
          &rtb_RateTransition4_f,
          &GRDWork.ISP_Out.Core2_ISP_Isx.Core2_ISP_AngleOut,
          &GRDWork.ISP_Out.Core2_ISP_nx.Core2_ISP_stAlOfsCal, &GRDWork.CDDISP_o2,
          &GRU.Drive, &GRU.PWMFrqSet, &GRU.UdHCIF, &GRU.UqHCIF, &rtb_f32_DutyUon,
          &rtb_f32_DutyVon, &rtb_f32_DutyWon, &GRY.KpCoef, &GRY.isdSet_last,
          &GRY.Ts, &GRY.Id, &GRY.Iq);profileEnd_pmsmfoc(2U); /* original_line:217 */

  /* BusCreator generated from: '<S2>/Bus Creator' */
  GRY.Core2_FOC_Out_b.Duty.f32_DutyUon = rtb_f32_DutyUon;
  GRY.Core2_FOC_Out_b.Duty.f32_DutyVon = rtb_f32_DutyVon;
  GRY.Core2_FOC_Out_b.Duty.f32_DutyWon = rtb_f32_DutyWon;

  /* BusCreator: '<S2>/Bus Creator' incorporates:
   *  Outport: '<Root>/Core2_FOC_Out'
   */
  GRY.Core2_FOC_Out_b.Core2_Iqref = PMC_IsqDes;
  GRY.Core2_FOC_Out_b.Core2_Idref = PMC_IsdDes;
  GRY.Core2_FOC_Out_b.Core2_Udref = PMC_UsdFlt;
  GRY.Core2_FOC_Out_b.Core2_Uqref = PMC_UsqFlt;
  GRY.Core2_FOC_Out_b.Core2_Usage = usage;
  GRY.Core2_FOC_Out_b.Core2_DCCurrent = GRDWork.DCCurrent;

  /* Outport: '<Root>/ISP_id' */
  GRY.ISP_id = GRDWork.ISP_Out.Core2_ISP_Isx.Core2_ISP_isd;

  /* Outport: '<Root>/ISP_iq' */
  GRY.ISP_iq = GRDWork.ISP_Out.Core2_ISP_Isx.Core2_ISP_isq;

  /* Outport: '<Root>/ISP_agRtrElecAtan2_i' incorporates:
   *  RateTransition: '<Root>/Rate Transition3'
   */
  GRY.ISP_agRtrElecAtan2_i = ISP_agRtrElecAtan2;

  /* Outport: '<Root>/ISP_n000' incorporates:
   *  RateTransition: '<Root>/Rate Transition10'
   */
  GRY.ISP_n000 = ISP_n;

  /* RateTransition: '<S1>/Rate Transition1' */
  if (GRDWork.RateTransition1_semaphoreTaken == 0) {
    GRDWork.RateTransition1_Buffer0 = GRDWork.ISP_Out;
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* RateTransition: '<S1>/Rate Transition3' */
  if (GRDWork.RateTransition3_semaphoreTaken == 0) {
    GRDWork.RateTransition3_Buffer0 = GRDWork.BusCreator1;
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */

  /* RateTransition: '<S1>/Rate Transition4' */
  if (GRDWork.RateTransition4_semaphoreTaken == 0) {
    GRDWork.RateTransition4_Buffer0 = ISP_n;
  }

  /* End of RateTransition: '<S1>/Rate Transition4' */

  /* RateTransition: '<S1>/Rate Transition6' incorporates:
   *  Outport: '<Root>/ISP_n222'
   */
  if (GRDWork.RateTransition6_semaphoreTaken == 0) {
    GRDWork.RateTransition6_Buffer0 = GRY.ISP_n222;
  }

  /* End of RateTransition: '<S1>/Rate Transition6' */

  /* Gain: '<S4>/facVdc2Vsmax' */
  PMC_UsMax = 0.408248305F * GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_uDc;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  GRDWork.UnitDelay_DSTATE = PMC_UsdFlt;
}

/* Model step function for TID1 */
void pmsmfoc_step1(void)               /* Sample time: [0.001s, 0.0s] */
{
  Sig10ms02ST rtb_UD1;
  real32_T rtb_RateTransition4;
  real32_T rtb_RateTransition6;
  int16_T rtb_RateTransition1_Core2_ISP_nx_Core2_ISP_agOffsCal;
  int16_T rtb_RateTransition1_Core2_ISP_nx_Core2_ISP_agRtrElec;

  /* RateTransition: '<S1>/Rate Transition1' */
  GRDWork.RateTransition1_semaphoreTaken = 1;

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Outport: '<Root>/msgCore2to0_10ms'
   *  RateTransition: '<S1>/Rate Transition1'
   */
  GRY.msgCore2to0_10ms.ISP_Is =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_Isx.Core2_ISP_Is;
  GRY.msgCore2to0_10ms.ISP_isd =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_Isx.Core2_ISP_isd;
  GRY.msgCore2to0_10ms.ISP_isq =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_Isx.Core2_ISP_isq;
  GRY.msgCore2to0_10ms.ISP_stAlOfsCal =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_nx.Core2_ISP_stAlOfsCal;

  /* RateTransition: '<S1>/Rate Transition1' */
  rtb_RateTransition1_Core2_ISP_nx_Core2_ISP_agOffsCal =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_nx.Core2_ISP_agOffsCal;
  rtb_RateTransition1_Core2_ISP_nx_Core2_ISP_agRtrElec =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_nx.Core2_ISP_agRtrElec;

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Outport: '<Root>/msgCore2to0_10ms'
   *  RateTransition: '<S1>/Rate Transition1'
   */
  GRY.msgCore2to0_10ms.ISP_frqElec =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_nx.Core2_ISP_frqElec;
  GRY.msgCore2to0_10ms.ISP_wElec =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_nx.Core2_ISP_wElec;
  GRY.msgCore2to0_10ms.ISP_phaCurrentU =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaU;
  GRY.msgCore2to0_10ms.ISP_phaCurrentV =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaV;
  GRY.msgCore2to0_10ms.ISP_phaCurrentW =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaW;
  GRY.msgCore2to0_10ms.ISP_iDcFlt =
    GRDWork.RateTransition1_Buffer0.Core2_ISC_tmpOut.Core2_ISP_iDcFlt;

  /* RateTransition: '<S1>/Rate Transition1' */
  GRDWork.RateTransition1_semaphoreTaken = 0;

  /* RateTransition: '<S1>/Rate Transition6' */
  GRDWork.RateTransition6_semaphoreTaken = 1;
  rtb_RateTransition6 = GRDWork.RateTransition6_Buffer0;
  GRDWork.RateTransition6_semaphoreTaken = 0;

  /* DataTypeConversion: '<S1>/DTC1' incorporates:
   *  RateTransition: '<S1>/Rate Transition1'
   */
  GRY.msgCore2to0_10ms.ISP_agAlOfsCal =
    rtb_RateTransition1_Core2_ISP_nx_Core2_ISP_agOffsCal;

  /* RateTransition: '<S1>/Rate Transition4' */
  GRDWork.RateTransition4_semaphoreTaken = 1;
  rtb_RateTransition4 = GRDWork.RateTransition4_Buffer0;
  GRDWork.RateTransition4_semaphoreTaken = 0;

  /* DataTypeConversion: '<S1>/DTC2' incorporates:
   *  RateTransition: '<S1>/Rate Transition1'
   */
  GRY.msgCore2to0_10ms.ISP_agRtrElec =
    rtb_RateTransition1_Core2_ISP_nx_Core2_ISP_agRtrElec;

  /* RateTransition: '<S1>/Rate Transition3' */
  GRDWork.RateTransition3_semaphoreTaken = 1;

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Outport: '<Root>/msgCore2to0_10ms'
   *  RateTransition: '<S1>/Rate Transition3'
   */
  GRY.msgCore2to0_10ms.PMC_TrqOutEst =
    GRDWork.RateTransition3_Buffer0.Core2_PMC_TrqOutEst;

  /* RateTransition: '<S1>/Rate Transition3' */
  GRDWork.RateTransition3_semaphoreTaken = 0;

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Outport: '<Root>/msgCore2to0_10ms'
   */
  GRY.msgCore2to0_10ms.ISP_n = rtb_RateTransition6;
  GRY.msgCore2to0_10ms.ISP_tmpMaxIGBT = 0.0F;
  GRY.msgCore2to0_10ms.ISP_tmpClnt = 0.0F;
  GRY.msgCore2to0_10ms.ISP_lossTotalIGBT = rtb_RateTransition4;
  GRY.msgCore2to0_10ms.ISP_bIphCalDone = false;
  GRY.msgCore2to0_10ms.ISP_flgResolver = 0U;

  /* ModelReference generated from: '<S2>/Model' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/Drive'
   *  Inport: '<Root>/PWMFrqSet'
   *  Inport: '<Root>/UdHCIF'
   *  Inport: '<Root>/UqHCIF'
   *  Inport: '<Root>/f32_Iddes_A'
   *  Inport: '<Root>/f32_Iqdes_A'
   *  Outport: '<Root>/Id'
   *  Outport: '<Root>/Iq'
   *  Outport: '<Root>/KpCoef'
   *  Outport: '<Root>/Ts'
   *  Outport: '<Root>/isdSet_last'
   */
  profileStart_pmsmfoc(3U); /* original_line:397 */FOCTID1();profileEnd_pmsmfoc(3U); /* original_line:397 */

  /* UnitDelay: '<Root>/UD1' */
  rtb_UD1 = GRDWork.UD1_DSTATE;

  /* RateTransition: '<S4>/Rate Transition5' */
  GRDWork.RateTransition5_Buffer0 = rtb_UD1.SSM_flgReqSafeSt;

  /* RateTransition: '<S2>/Rate Transition2' */
  GRDWork.RateTransition2_Buffer[GRDWork.RateTransition2_ActiveBufIdx == 0] =
    PMC_TrqOutEst;
  GRDWork.RateTransition2_ActiveBufIdx = (int8_T)
    (GRDWork.RateTransition2_ActiveBufIdx == 0);

  /* RateTransition: '<S2>/Rate Transition3' */
  GRDWork.RateTransition3_Buffer[GRDWork.RateTransition3_ActiveBufIdx == 0] =
    rtb_UD1.ISP_frqDes;
  GRDWork.RateTransition3_ActiveBufIdx = (int8_T)
    (GRDWork.RateTransition3_ActiveBufIdx == 0);

  /* RateTransition: '<S2>/Rate Transition4' */
  GRDWork.RateTransition4_Buffer[GRDWork.RateTransition4_ActiveBufIdx == 0] =
    rtb_UD1.SSM_stDrvMode;
  GRDWork.RateTransition4_ActiveBufIdx = (int8_T)
    (GRDWork.RateTransition4_ActiveBufIdx == 0);

  /* RateTransition: '<Root>/Rate Transition' */
  GRDWork.RateTransition_Buffer[GRDWork.RateTransition_ActiveBufIdx == 0] =
    rtb_UD1;
  GRDWork.RateTransition_ActiveBufIdx = (int8_T)
    (GRDWork.RateTransition_ActiveBufIdx == 0);

  /* UnitDelay: '<Root>/UD2' */
  GRDWork.UD2 = GRDWork.UD2_DSTATE;

  /* Update for UnitDelay: '<Root>/UD1' incorporates:
   *  Inport: '<Root>/msgCore0to2_10ms'
   */
  GRDWork.UD1_DSTATE = GRU.msgCore0to2_10ms_In;

  /* Update for UnitDelay: '<Root>/UD2' incorporates:
   *  Inport: '<Root>/msgCore0to2_1ms'
   */
  GRDWork.UD2_DSTATE = GRU.msgCore0to2_1ms_In;
}

/* Model step function for TID2 */
void pmsmfoc_step2(void)               /* Sample time: [0.01s, 0.0s] */
{
  /* ModelReference generated from: '<Root>/CDD&ISP' incorporates:
   *  Inport: '<Root>/Angleoffset_Init'
   *  Inport: '<Root>/Uoffset'
   *  Inport: '<Root>/Voffset'
   *  Inport: '<Root>/Woffset'
   *  Inport: '<Root>/cddin'
   *  Outport: '<Root>/ISP_n111'
   *  Outport: '<Root>/ISP_n222'
   */
  profileStart_pmsmfoc(4U); /* original_line:455 */CDD_ISPTID1();profileEnd_pmsmfoc(4U); /* original_line:455 */
}

/* Model initialize function */
void pmsmfoc_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (GRM)->Timing.TaskCounters.cLimit[0] = 1;
  (GRM)->Timing.TaskCounters.cLimit[1] = 10;
  (GRM)->Timing.TaskCounters.cLimit[2] = 100;

  {
    static uint32_T *taskCounterPtrs;
    static boolean_T *rateTransitionPtrs[(3 * 3)];
    GRTimingBridge.nTasks = 3;
    GRTimingBridge.clockTick = (NULL);
    GRTimingBridge.clockTickH = (NULL);
    taskCounterPtrs = &(GRM->Timing.TaskCounters.TID[0]);
    GRTimingBridge.taskCounter = taskCounterPtrs;
    rateTransitionPtrs[0*3 + 1] = &(GRM->Timing.RateInteraction.b_TID0_1);
    rateTransitionPtrs[0*3 + 2] = &(GRM->Timing.RateInteraction.b_TID0_2);
    GRTimingBridge.rateTransition = rateTransitionPtrs;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/CDD&ISP' */
  CDD_ISP_initialize(rtmGetErrorStatusPointer(GRM), &GRTimingBridge, 0, 2);

  /* Model Initialize function for ModelReference Block: '<S2>/Model' */
  FOC_initialize(rtmGetErrorStatusPointer(GRM), &GRTimingBridge, 0, 1);

  {
    /* local block i/o variables */
    real32_T rtb_f32_DutyUon;
    real32_T rtb_f32_DutyVon;
    real32_T rtb_f32_DutyWon;

    /* SystemInitialize for ModelReference generated from: '<Root>/CDD&ISP' incorporates:
     *  Inport: '<Root>/Angleoffset_Init'
     *  Inport: '<Root>/Uoffset'
     *  Inport: '<Root>/Voffset'
     *  Inport: '<Root>/Woffset'
     *  Inport: '<Root>/cddin'
     *  Outport: '<Root>/ISP_n111'
     *  Outport: '<Root>/ISP_n222'
     */
    profileStart_pmsmfoc(5U); /* original_line:502 */CDD_ISP_Init();profileEnd_pmsmfoc(5U); /* original_line:502 */

    /* SystemInitialize for ModelReference generated from: '<S2>/Model' incorporates:
     *  Constant: '<S2>/Constant'
     *  Inport: '<Root>/Drive'
     *  Inport: '<Root>/PWMFrqSet'
     *  Inport: '<Root>/UdHCIF'
     *  Inport: '<Root>/UqHCIF'
     *  Inport: '<Root>/f32_Iddes_A'
     *  Inport: '<Root>/f32_Iqdes_A'
     *  Outport: '<Root>/Id'
     *  Outport: '<Root>/Iq'
     *  Outport: '<Root>/KpCoef'
     *  Outport: '<Root>/Ts'
     *  Outport: '<Root>/isdSet_last'
     */
    profileStart_pmsmfoc(6U); /* original_line:518 */FOC_Init(&rtb_f32_DutyUon, &rtb_f32_DutyVon, &rtb_f32_DutyWon);profileEnd_pmsmfoc(6U); /* original_line:518 */

    /* ConstCode for Outport: '<Root>/IFAngle' */
    GRY.IFAngle = GRDWork.CDDISP_o3;

    /* ConstCode for Constant: '<S4>/Constant4' */
    PMC_stGateDrv = Shortcircuit;
  }
}

/* Model terminate function */
void pmsmfoc_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
