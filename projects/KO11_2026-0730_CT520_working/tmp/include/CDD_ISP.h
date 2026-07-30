/*
 * File: CDD_ISP.h
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

#ifndef RTW_HEADER_CDD_ISP_h_
#define RTW_HEADER_CDD_ISP_h_
#ifndef CDD_ISP_COMMON_INCLUDES_
#define CDD_ISP_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CDD_ISP_COMMON_INCLUDES_ */

#include "CDD_ISP_types.h"
#include "EGM.h"
#include "EiceSilSM.h"
#include "model_reference_types.h"

/* Includes for objects with custom storage classes */
#include "parameter.h"

/* Block signals and states (default storage) for model 'CDD_ISP' */
#ifndef CDD_ISP_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T RateTransition6;            /* '<S3>/Rate Transition6' */
  real32_T UnitDelay2_DSTATE;          /* '<S5>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S10>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_f;        /* '<S15>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_g;        /* '<S21>/Unit Delay1' */
  real32_T PrevY;                      /* '<S3>/Rate Limiter1' */
  real32_T RateTransition6_Buffer0;    /* '<S3>/Rate Transition6' */
  real32_T bout_flt;                   /* '<S3>/filter' */
  real32_T tempU;                      /* '<S3>/AlOfsCalFun2' */
  real32_T tempV;                      /* '<S3>/AlOfsCalFun2' */
  real32_T tempW;                      /* '<S3>/AlOfsCalFun2' */
  real32_T tempofs;                    /* '<S3>/AlOfsCalFun2' */
  real32_T Angle;                      /* '<S3>/AlOfsCalFun2' */
  real32_T Iddes;                      /* '<S3>/AlOfsCalFun2' */
  real32_T agOffs_Caltemp;             /* '<S3>/AlOfsCalFun2' */
  int16_T RateTransition8;             /* '<S3>/Rate Transition8' */
  int16_T UnitDelay_DSTATE;            /* '<S5>/Unit Delay' */
  int16_T UnitDelay2_DSTATE_h;         /* '<S19>/Unit Delay2' */
  int16_T RateTransition8_Buffer0;     /* '<S3>/Rate Transition8' */
  int16_T agRoughCal;                  /* '<S3>/AlOfsCalPosSet' */
  uint16_T cnt;                        /* '<S3>/AlOfsCalFun2' */
  uint8_T stRoughCalSetLast;           /* '<S3>/AlOfsCalPosSet' */
  uint8_T stAlOfsCaltemp;              /* '<S3>/AlOfsCalFun2' */
  uint8_T step;                        /* '<S3>/AlOfsCalFun2' */
  uint8_T times;                       /* '<S3>/AlOfsCalFun2' */
} CDD_ISPpmsmfoc_rtDW_a;

#endif                                 /*CDD_ISP_MDLREF_HIDE_CHILD_*/

#ifndef CDD_ISP_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct CDD_ISPpmsmfoc_tag_RTM {
  const char_T **errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID0_1;
    } RateInteraction;
  } Timing;
};

#endif                                 /*CDD_ISP_MDLREF_HIDE_CHILD_*/

#ifndef CDD_ISP_MDLREF_HIDE_CHILD_

typedef struct {
  CDD_ISPpmsmfoc_RT_MODEL rtm;
} CDD_ISPpmsmfoc_rtMdlrefDWork_g;

#endif                                 /*CDD_ISP_MDLREF_HIDE_CHILD_*/

/* Code_Instrumentation_Declarations_Placeholder */
extern void CDD_ISP_Init(void);
extern void CDD_ISP_Reset(void);
extern void CDD_ISPTID0(const real32_T *u_PMC_Out_Core2_PMC_UsdScal, const
  real32_T *u_PMC_Out_Core2_PMC_tiPerd, const uint16_T
  *u_ACI_Out_Core2_SAQ_iPhaU, const uint16_T *u_ACI_Out_Core2_SAQ_iPhaV, const
  uint16_T *u_ACI_Out_Core2_SAQ_iPhaW, const int16_T
  *u_ACI_Out_Core2_SAQ_rslvSinAmp, const real32_T *u_ACI_Out_Core2_SAQ_HVU,
  const Sig10ms02ST *u_msgCore0to2_10ms, const uint8_T
  *u_msgCore0to2_1ms_TCC_stRoughCalSet, const int16_T *u_Angleoffset_Init, const
  real32_T *u_Uoffset, const real32_T *u_Voffset, const real32_T *u_Woffset,
  Core2_ISP_Out *y_ISP_Out, real32_T *y_Iddes);
extern void CDD_ISPTID1(void);

/* Model reference registration function */
extern void CDD_ISP_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern int16_T ISP_agRoughCal;         /* '<S3>/AlOfsCalPosSet' */

/* Rough Calibrated output offset rotor angle */
extern int16_T ISP_agRtrElecAtan2;     /* '<S5>/DTC8' */

/* Electric angle of rotor calculated by atan2 */
extern int16_T ISP_agRtrElecObvr;      /* '<S5>/Add1' */

/* Electric angle of rotor by observer */
extern int16_T ISP_agRtrElecOld;       /* '<S5>/Unit Delay' */

/* Last Electric angle of rotor */
extern int16_T ISP_agRtrPoleTrans;     /* '<S3>/Product' */

/* Resolver electric angle transit to motor electric angle */
extern real32_T ISP_frqElec;           /* '<S3>/Rate Transition10' */

/* Electric frequency of rotor */
extern real32_T ISP_frqElecCaln;       /* '<S10>/Sum1' */

/* Electric frequency of rotor by atan2 calculate */
extern real32_T ISP_iDcFlt;            /* '<Root>/Constant2' */

/* Calculated Dc link current */
extern real32_T ISP_iPhaU;             /* '<S7>/Switch2' */

/* U phase current, A */
extern real32_T ISP_iPhaV;             /* '<S8>/Switch2' */

/* V phase current, A */
extern real32_T ISP_iPhaW;             /* '<S9>/Switch2' */

/* W phase current, A */
extern real32_T ISP_lossTotalIGBT;     /* '<Root>/Constant1' */

/* Loss of IGBT */
extern real32_T ISP_n;                 /* '<S3>/Rate Transition1' */

/* mechanical speed */
extern uint8_T ISP_stAlOfsCal;         /* '<S3>/Rate Transition4' */

/* Position offset calitation state */
extern real32_T ISP_tmpClnt;           /* '<Root>/Constant3' */

/* Coolant temperature */
extern real32_T ISP_tmpMaxIGBT;        /* '<Root>/Constant' */

/* Tj of IGBT */
extern real32_T ISP_uDcFlt;            /* '<S15>/Sum1' */

/* Filtered DC link voltage */
extern real32_T ISP_wElec;             /* '<S3>/Rate Transition2' */

/* Electric frequency of rotor */
#ifndef CDD_ISP_MDLREF_HIDE_CHILD_

extern CDD_ISPpmsmfoc_rtMdlrefDWork_g CDD_ISPpmsmfoc_rtMdlrefDWork;

#endif                                 /*CDD_ISP_MDLREF_HIDE_CHILD_*/

#ifndef CDD_ISP_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern CDD_ISPpmsmfoc_rtDW_a CDD_ISPpmsmfoc_rtDWork;

#endif                                 /*CDD_ISP_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Add2' : Unused code path elimination
 * Block '<S5>/Add4' : Unused code path elimination
 * Block '<S5>/Add5' : Unused code path elimination
 * Block '<S5>/Atan2' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S5>/Constant1' : Unused code path elimination
 * Block '<S5>/Constant5' : Unused code path elimination
 * Block '<S5>/DTC1' : Unused code path elimination
 * Block '<S5>/DTC4' : Unused code path elimination
 * Block '<S5>/Gain3' : Unused code path elimination
 * Block '<S5>/Product' : Unused code path elimination
 * Block '<S5>/Product1' : Unused code path elimination
 * Block '<S5>/Rate Transition7' : Unused code path elimination
 * Block '<S5>/SinCos' : Unused code path elimination
 * Block '<S11>/Add6' : Unused code path elimination
 * Block '<S13>/Compare' : Unused code path elimination
 * Block '<S13>/Constant' : Unused code path elimination
 * Block '<S11>/Constant1' : Unused code path elimination
 * Block '<S11>/Gain' : Unused code path elimination
 * Block '<S11>/Switch1' : Unused code path elimination
 * Block '<S12>/Add6' : Unused code path elimination
 * Block '<S14>/Compare' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S12>/Constant1' : Unused code path elimination
 * Block '<S12>/Gain' : Unused code path elimination
 * Block '<S12>/Switch1' : Unused code path elimination
 * Block '<S5>/Sum' : Unused code path elimination
 * Block '<S5>/Unit Delay1' : Unused code path elimination
 * Block '<S5>/kiRslvPI' : Unused code path elimination
 * Block '<S5>/kpRslvPI' : Unused code path elimination
 * Block '<S1>/DTC1' : Unused code path elimination
 * Block '<S1>/DTC2' : Unused code path elimination
 * Block '<S1>/DTC4' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Rate Transition2' : Unused code path elimination
 * Block '<S1>/Rate Transition7' : Unused code path elimination
 * Block '<S20>/Constant' : Unused code path elimination
 * Block '<S3>/Gain' : Unused code path elimination
 * Block '<S3>/Gain1' : Unused code path elimination
 * Block '<S3>/Gain2' : Unused code path elimination
 * Block '<S3>/Rate Transition7' : Unused code path elimination
 * Block '<S3>/Relational Operator' : Unused code path elimination
 * Block '<S3>/TrqSetAlOfsCal_C' : Unused code path elimination
 * Block '<Root>/Rate Transition' : Unused code path elimination
 * Block '<S4>/DTC1' : Eliminate redundant data type conversion
 * Block '<S4>/DTC2' : Eliminate redundant data type conversion
 * Block '<S4>/DTC4' : Eliminate redundant data type conversion
 * Block '<S5>/DTC2' : Eliminate redundant data type conversion
 * Block '<S6>/DTC2' : Eliminate redundant data type conversion
 * Block '<S3>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition15' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'CDD_ISP'
 * '<S1>'   : 'CDD_ISP/CddPhaCur&CddRslvr'
 * '<S2>'   : 'CDD_ISP/ISP_IsttrTrafoAB2DQ1'
 * '<S3>'   : 'CDD_ISP/ISP_ResolverSel'
 * '<S4>'   : 'CDD_ISP/CddPhaCur&CddRslvr/CddPhaCur_CalnIpha'
 * '<S5>'   : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln'
 * '<S6>'   : 'CDD_ISP/CddPhaCur&CddRslvr/ISP_AnaCalnUdcLnk and Flt'
 * '<S7>'   : 'CDD_ISP/CddPhaCur&CddRslvr/CddPhaCur_CalnIpha/Saturation Dynamic'
 * '<S8>'   : 'CDD_ISP/CddPhaCur&CddRslvr/CddPhaCur_CalnIpha/Saturation Dynamic1'
 * '<S9>'   : 'CDD_ISP/CddPhaCur&CddRslvr/CddPhaCur_CalnIpha/Saturation Dynamic2'
 * '<S10>'  : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/PT1'
 * '<S11>'  : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/Subsystem'
 * '<S12>'  : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/Subsystem1'
 * '<S13>'  : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/Subsystem/Compare To Zero1'
 * '<S14>'  : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/Subsystem1/Compare To Zero1'
 * '<S15>'  : 'CDD_ISP/CddPhaCur&CddRslvr/ISP_AnaCalnUdcLnk and Flt/PT1'
 * '<S16>'  : 'CDD_ISP/CddPhaCur&CddRslvr/ISP_AnaCalnUdcLnk and Flt/Saturation Dynamic'
 * '<S17>'  : 'CDD_ISP/ISP_ResolverSel/AlOfsCalFun2'
 * '<S18>'  : 'CDD_ISP/ISP_ResolverSel/AlOfsCalPosSet'
 * '<S19>'  : 'CDD_ISP/ISP_ResolverSel/Angle Cal'
 * '<S20>'  : 'CDD_ISP/ISP_ResolverSel/Enumerated Constant'
 * '<S21>'  : 'CDD_ISP/ISP_ResolverSel/PT2'
 * '<S22>'  : 'CDD_ISP/ISP_ResolverSel/Subsystem1'
 * '<S23>'  : 'CDD_ISP/ISP_ResolverSel/filter'
 */
#endif                                 /* RTW_HEADER_CDD_ISP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
