/*
 * File: pmsmfoc.c
 *
 * Code generated for Simulink model 'pmsmfoc'.
 *
 * Model version                  : 11.92
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  3 16:25:55 2025
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
#define FOC_P1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h" 

/* Definition for custom storage class: ExportToFile */
real32_T PMC_TrqOutEst;                /* '<S2>/Model' */

/* Estimated output torque */
real32_T PMC_UsMax;                    /* '<S4>/facVdc2Vsmax' */

/* SVPWM maximum phase voltage */
real32_T PMC_UsqScal;                  /* '<S4>/Constant2' */

/* q axis output Nrm voltage */
boolean_T PMC_flgReqSafeSt;            /* '<S4>/Rate Transition5' */

/* Safe state flag */
EGM PMC_stGateDrv;                     /* '<S4>/Constant4' */

/* gate drive mode from the statemachine */
real32_T PMC_tiPerd;                   /* '<S4>/Constant3' */

/* Period time output from MCT considering variable freuqency and random frequency */

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

#define FOC_P1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h" 
void pmsmfoc_step0(void)               /* Sample time: [0.0001s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_RateTransition3_g;
  real32_T rtb_f32_DutyUon;
  real32_T rtb_f32_DutyVon;
  real32_T rtb_f32_DutyWon;
  real32_T rtb_Iqref;
  real32_T rtb_Idref;
  real32_T rtb_Udref;
  real32_T rtb_Uqref;
  real32_T rtb_Usage;
  ECM rtb_RateTransition4;

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
  PMC_flgReqSafeSt = GRDWork.RateTransition5_Buffer0_d;

  /* RateTransition: '<S2>/Rate Transition5' */
  if (GRM->Timing.RateInteraction.TID0_2 == 1) {
    /* RateTransition: '<S2>/Rate Transition5' */
    GRDWork.RateTransition5 = GRDWork.RateTransition5_Buffer0;
  }

  /* End of RateTransition: '<S2>/Rate Transition5' */

  /* BusCreator: '<S4>/Bus Creator1' */
  GRDWork.BusCreator1.Core2_PMC_stGateDrv = PMC_stGateDrv;
  GRDWork.BusCreator1.Core2_PMC_flgReqSafeSt = PMC_flgReqSafeSt;
  GRDWork.BusCreator1.Core2_PMC_Rs = 0.0F;
  GRDWork.BusCreator1.Core2_PMC_TrqOutEst = GRDWork.RateTransition5;

  /* Outport: '<Root>/stGateDrv' */
  GRY.stGateDrv = GRDWork.BusCreator1.Core2_PMC_stGateDrv;

  /* RateTransition: '<Root>/Rate Transition' */
  GRDWork.RateTransition =
    GRDWork.RateTransition_Buffer[GRDWork.RateTransition_ActiveBufIdx];

  /* ModelReference generated from: '<Root>/CDD&ISP' incorporates:
   *  Inport: '<Root>/Angleoffset_Init'
   *  Inport: '<Root>/Uoffset'
   *  Inport: '<Root>/Voffset'
   *  Inport: '<Root>/Woffset'
   *  Inport: '<Root>/cddin'
   */
  CDD_ISPTID0(&GRDWork.BusCreator1.Core2_PMC_UsdScal,
              &GRDWork.BusCreator1.Core2_PMC_tiPerd, &GRU.cddin.Core2_iPhaU,
              &GRU.cddin.Core2_iPhaV, &GRU.cddin.Core2_iPhaW,
              &GRU.cddin.Core2_RvSin, &GRU.cddin.Core2_Udc,
              &GRDWork.RateTransition, &GRDWork.UD2.TCC_stRoughCalSet,
              &GRU.Angleoffset_Init, &GRU.Uoffset, &GRU.Voffset, &GRU.Woffset,
              &GRDWork.ISP_Out, &GRDWork.CDDISP_o2);

  /* RateTransition: '<S2>/Rate Transition3' */
  rtb_RateTransition3_g =
    GRDWork.RateTransition3_Buffer[GRDWork.RateTransition3_ActiveBufIdx];

  /* RateTransition: '<S2>/Rate Transition4' */
  rtb_RateTransition4 =
    GRDWork.RateTransition4_Buffer[GRDWork.RateTransition4_ActiveBufIdx];

  /* ModelReference generated from: '<S2>/Model' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/Drive'
   *  Inport: '<Root>/PWMFrqSet'
   *  Inport: '<Root>/TrqEmDes'
   *  Inport: '<Root>/f32_Iddes_A'
   *  Inport: '<Root>/f32_Iqdes_A'
   *  Outport: '<Root>/Id'
   *  Outport: '<Root>/Iq'
   *  Outport: '<Root>/KpCoef'
   *  Outport: '<Root>/Ts'
   *  Outport: '<Root>/isdSet_last'
   */
  FOCTID0(&GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaU,
          &GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaV,
          &GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaW,
          &GRDWork.ISP_Out.Core2_ISP_nx.Core2_ISP_n, &rtb_RateTransition3_g,
          &GRU.f32_Iddes_A, &GRU.f32_Iqdes_A,
          &GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_uDc, &rtCP_Constant_Value,
          &rtb_RateTransition4,
          &GRDWork.ISP_Out.Core2_ISP_Isx.Core2_ISP_AngleOut,
          &GRDWork.ISP_Out.Core2_ISP_nx.Core2_ISP_stAlOfsCal, &GRDWork.CDDISP_o2,
          &GRU.Drive, &GRU.PWMFrqSet, &GRU.TrqEmDes, &rtb_f32_DutyUon,
          &rtb_f32_DutyVon, &rtb_f32_DutyWon, &rtb_Iqref, &rtb_Idref, &rtb_Udref,
          &rtb_Uqref, &rtb_Usage, &GRY.KpCoef, &GRY.isdSet_last, &GRY.Ts,
          &GRY.Id, &GRY.Iq);

  /* BusCreator generated from: '<S2>/Bus Creator' */
  GRY.Core2_FOC_Out_b.Duty.f32_DutyUon = rtb_f32_DutyUon;
  GRY.Core2_FOC_Out_b.Duty.f32_DutyVon = rtb_f32_DutyVon;
  GRY.Core2_FOC_Out_b.Duty.f32_DutyWon = rtb_f32_DutyWon;

  /* BusCreator: '<S2>/Bus Creator' incorporates:
   *  Outport: '<Root>/Core2_FOC_Out'
   */
  GRY.Core2_FOC_Out_b.Core2_Iqref = rtb_Iqref;
  GRY.Core2_FOC_Out_b.Core2_Idref = rtb_Idref;
  GRY.Core2_FOC_Out_b.Core2_Udref = rtb_Udref;
  GRY.Core2_FOC_Out_b.Core2_Uqref = rtb_Uqref;
  GRY.Core2_FOC_Out_b.Core2_Usage = rtb_Usage;
  GRY.Core2_FOC_Out_b.Core2_DCCurrent = GRDWork.DCCurrent;

  /* Outport: '<Root>/ISP_id' */
  GRY.ISP_id = GRDWork.ISP_Out.Core2_ISP_Isx.Core2_ISP_isd;

  /* Outport: '<Root>/ISP_iq' */
  GRY.ISP_iq = GRDWork.ISP_Out.Core2_ISP_Isx.Core2_ISP_isq;

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

  /* Gain: '<S4>/facVdc2Vsmax' */
  PMC_UsMax = 0.408248305F * GRDWork.ISP_Out.Core2_ISP_AnaOut.Core2_ISP_uDc;

  /* Constant: '<S4>/Constant2' */
  PMC_UsqScal = 0.0F;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  GRDWork.UnitDelay_DSTATE = rtb_Udref;
}

/* Model step function for TID1 */
void pmsmfoc_step1(void)               /* Sample time: [0.001s, 0.0s] */
{
  Sig10ms02ST rtb_UD1;
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
  GRY.msgCore2to0_10ms.ISP_n =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_nx.Core2_ISP_n;
  GRY.msgCore2to0_10ms.ISP_flgResolver =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_agRtr.Core2_ISP_flgResolver;
  GRY.msgCore2to0_10ms.ISP_phaCurrentU =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaU;
  GRY.msgCore2to0_10ms.ISP_phaCurrentV =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaV;
  GRY.msgCore2to0_10ms.ISP_phaCurrentW =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_iPhabc.Core2_ISP_iPhaW;
  GRY.msgCore2to0_10ms.ISP_bIphCalDone =
    GRDWork.RateTransition1_Buffer0.Core2_ISP_AnaOut.Core2_ISP_bIphCalDone;
  GRY.msgCore2to0_10ms.ISP_tmpMaxIGBT =
    GRDWork.RateTransition1_Buffer0.Core2_ISC_tmpOut.Core2_ISP_tmpMaxIGBT;
  GRY.msgCore2to0_10ms.ISP_lossTotalIGBT =
    GRDWork.RateTransition1_Buffer0.Core2_ISC_tmpOut.Core2_ISP_lossTotalIGBT;
  GRY.msgCore2to0_10ms.ISP_iDcFlt =
    GRDWork.RateTransition1_Buffer0.Core2_ISC_tmpOut.Core2_ISP_iDcFlt;
  GRY.msgCore2to0_10ms.ISP_tmpClnt =
    GRDWork.RateTransition1_Buffer0.Core2_ISC_tmpOut.Core2_ISP_tmpClnt;

  /* RateTransition: '<S1>/Rate Transition1' */
  GRDWork.RateTransition1_semaphoreTaken = 0;

  /* DataTypeConversion: '<S1>/DTC1' incorporates:
   *  RateTransition: '<S1>/Rate Transition1'
   */
  GRY.msgCore2to0_10ms.ISP_agAlOfsCal =
    rtb_RateTransition1_Core2_ISP_nx_Core2_ISP_agOffsCal;

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

  /* UnitDelay: '<Root>/UD1' */
  rtb_UD1 = GRDWork.UD1_DSTATE;

  /* RateTransition: '<S4>/Rate Transition5' */
  GRDWork.RateTransition5_Buffer0_d = rtb_UD1.SSM_flgReqSafeSt;

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
   */
  CDD_ISPTID1();

  /* ModelReference generated from: '<S2>/Model' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/Drive'
   *  Inport: '<Root>/PWMFrqSet'
   *  Inport: '<Root>/TrqEmDes'
   *  Inport: '<Root>/f32_Iddes_A'
   *  Inport: '<Root>/f32_Iqdes_A'
   *  Outport: '<Root>/Id'
   *  Outport: '<Root>/Iq'
   *  Outport: '<Root>/KpCoef'
   *  Outport: '<Root>/Ts'
   *  Outport: '<Root>/isdSet_last'
   */
  FOCTID1();

  /* RateTransition: '<S2>/Rate Transition5' */
  GRDWork.RateTransition5_Buffer0 = PMC_TrqOutEst;
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
    rateTransitionPtrs[0*3 + 2] = &(GRM->Timing.RateInteraction.b_TID0_2);
    GRTimingBridge.rateTransition = rateTransitionPtrs;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/CDD&ISP' */
  CDD_ISP_initialize(rtmGetErrorStatusPointer(GRM), &GRTimingBridge, 0, 2);

  /* Model Initialize function for ModelReference Block: '<S2>/Model' */
  FOC_initialize(rtmGetErrorStatusPointer(GRM), &GRTimingBridge, 0, 2);

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
     */
    CDD_ISP_Init();

    /* SystemInitialize for ModelReference generated from: '<S2>/Model' incorporates:
     *  Constant: '<S2>/Constant'
     *  Inport: '<Root>/Drive'
     *  Inport: '<Root>/PWMFrqSet'
     *  Inport: '<Root>/TrqEmDes'
     *  Inport: '<Root>/f32_Iddes_A'
     *  Inport: '<Root>/f32_Iqdes_A'
     *  Outport: '<Root>/Id'
     *  Outport: '<Root>/Iq'
     *  Outport: '<Root>/KpCoef'
     *  Outport: '<Root>/Ts'
     *  Outport: '<Root>/isdSet_last'
     */
    FOC_Init(&rtb_f32_DutyUon, &rtb_f32_DutyVon, &rtb_f32_DutyWon);

    /* ConstCode for Outport: '<Root>/IFAngle' */
    GRY.IFAngle = GRDWork.CDDISP_o4;

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
