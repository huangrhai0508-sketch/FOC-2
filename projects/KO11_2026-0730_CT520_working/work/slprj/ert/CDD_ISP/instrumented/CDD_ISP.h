/*
 * File: CDD_ISP.h
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
  real32_T UnitDelay1_DSTATE;          /* '<S11>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_f;        /* '<S12>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S5>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S5>/Unit Delay' */
  real32_T UnitDelay4_DSTATE;          /* '<S3>/Unit Delay4' */
  real32_T UnitDelay5_DSTATE;          /* '<S3>/Unit Delay5' */
  real32_T UnitDelay6_DSTATE;          /* '<S3>/Unit Delay6' */
  real32_T UnitDelay7_DSTATE;          /* '<S3>/Unit Delay7' */
  real32_T UnitDelay12_DSTATE;         /* '<S3>/Unit Delay12' */
  real32_T UnitDelay13_DSTATE;         /* '<S3>/Unit Delay13' */
  real32_T UnitDelay14_DSTATE;         /* '<S3>/Unit Delay14' */
  real32_T UnitDelay15_DSTATE;         /* '<S3>/Unit Delay15' */
  real32_T UnitDelay_DSTATE_j;         /* '<S3>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_d;        /* '<S3>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S3>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE;          /* '<S3>/Unit Delay3' */
  real32_T RateTransition6_Buffer0;    /* '<S3>/Rate Transition6' */
  real32_T tempU;                      /* '<S3>/AlOfsCalFun2' */
  real32_T tempV;                      /* '<S3>/AlOfsCalFun2' */
  real32_T tempW;                      /* '<S3>/AlOfsCalFun2' */
  real32_T tempUU;                     /* '<S3>/AlOfsCalFun2' */
  real32_T tempVV;                     /* '<S3>/AlOfsCalFun2' */
  real32_T tempWW;                     /* '<S3>/AlOfsCalFun2' */
  real32_T tempofs;                    /* '<S3>/AlOfsCalFun2' */
  real32_T Angle;                      /* '<S3>/AlOfsCalFun2' */
  real32_T Iddes;                      /* '<S3>/AlOfsCalFun2' */
  real32_T agOffs_Caltemp_pos;         /* '<S3>/AlOfsCalFun2' */
  real32_T agOffs_Caltemp_neg;         /* '<S3>/AlOfsCalFun2' */
  int16_T RateTransition8;             /* '<S3>/Rate Transition8' */
  int16_T UnitDelay2_DSTATE_n;         /* '<S5>/Unit Delay2' */
  int16_T RateTransition8_Buffer0;     /* '<S3>/Rate Transition8' */
  int16_T agRoughCal;                  /* '<S3>/AlOfsCalPosSet' */
  uint16_T cnt;                        /* '<S3>/AlOfsCalFun2' */
  uint8_T stRoughCalSetLast;           /* '<S3>/AlOfsCalPosSet' */
  uint8_T stAlOfsCaltemp;              /* '<S3>/AlOfsCalFun2' */
  uint8_T step;                        /* '<S3>/AlOfsCalFun2' */
  uint8_T times;                       /* '<S3>/AlOfsCalFun2' */
  boolean_T reset_not_empty;           /* '<S3>/MATLAB Function3' */
  boolean_T reset_not_empty_e;         /* '<S3>/MATLAB Function1' */
  boolean_T reset_not_empty_l;         /* '<S3>/MATLAB Function' */
  boolean_T reset_not_empty_ll;        /* '<S5>/MATLAB Function' */
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



/* Declare global externs for instrumentation */
extern void profileStart_CDD_ISP(uint32_T);
extern void profileEnd_CDD_ISP(uint32_T);
/* Code_Instrumentation_Declarations_Placeholder */
extern void CDD_ISP_Init(void);
extern void CDD_ISP_Reset(void);
extern void CDD_ISPTID0(const real32_T *u_PMC_Out_Core2_PMC_tiPerd, const
  uint16_T *u_ACI_Out_Core2_SAQ_iPhaU, const uint16_T *u_ACI_Out_Core2_SAQ_iPhaV,
  const uint16_T *u_ACI_Out_Core2_SAQ_iPhaW, const int16_T
  *u_ACI_Out_Core2_SAQ_rslvSinAmp, const real32_T *u_ACI_Out_Core2_SAQ_HVU,
  const Sig10ms02ST *u_msgCore0to2_10ms, const uint8_T
  *u_msgCore0to2_1ms_TCC_stRoughCalSet, const int16_T *u_Angleoffset_Init, const
  real32_T *u_Uoffset, const real32_T *u_Voffset, const real32_T *u_Woffset,
  Core2_ISP_Out *y_ISP_Out, real32_T *y_Iddes, real32_T *y_ISP_nNotch, real32_T *
  y_ISP_nNotch2);
extern void CDD_ISPTID1(void);

/* Model reference registration function */
extern void CDD_ISP_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T B;                     /* '<S3>/MATLAB Function1' */

/* TODO */
extern int16_T ISP_agRoughCal;         /* '<S3>/AlOfsCalPosSet' */

/* Rough Calibrated output offset rotor angle */
extern int16_T ISP_agRtrElec;          /* '<S3>/AlOfsCalPosSet' */

/* Electric angle of rotor */
extern int16_T ISP_agRtrElecAtan2;     /* '<S5>/DTC8' */

/* Electric angle of rotor calculated by atan2 */
extern int16_T ISP_agRtrPoleTrans;     /* '<S3>/Product' */

/* Resolver electric angle transit to motor electric angle */
extern real32_T ISP_frqElec;           /* '<S3>/Rate Transition10' */

/* Electric frequency of rotor */
extern real32_T ISP_frqElecCaln;       /* '<S11>/Sum1' */

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
extern real32_T ISP_n_test_notch;      /* '<S3>/MATLAB Function' */

/* TODO */
extern real32_T ISP_n_test_pp;         /* '<S3>/Data Type Conversion4' */

/* TODO */
extern real32_T ISP_speedref_final;

/* TODO */
extern real32_T ISP_speedref_final_wn; /* '<S3>/Gain7' */

/* TODO */
extern real32_T ISP_tmpClnt;           /* '<Root>/Constant3' */

/* Coolant temperature */
extern real32_T ISP_tmpMaxIGBT;        /* '<Root>/Constant' */

/* Tj of IGBT */
extern real32_T ISP_uDcFlt;            /* '<S12>/Sum1' */

/* Filtered DC link voltage */
extern real32_T ISP_wElec;             /* '<S3>/Rate Transition2' */

/* Electric frequency of rotor */
extern real32_T X111;                  /* '<S3>/Unit Delay4' */

/* TODO */
extern real32_T X222;                  /* '<S3>/Unit Delay5' */

/* TODO */
extern real32_T Y111;                  /* '<S3>/Unit Delay6' */

/* TODO */
extern real32_T Y222;                  /* '<S3>/Unit Delay7' */

/* TODO */
extern real32_T a1;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T a2;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T a3;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T b1;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T b2;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T b3;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T k1;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T k2;                    /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T omega_hat_K_1;         /* '<S5>/MATLAB Function' */

/* TODO */
extern real32_T temp1_111;             /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T temp2_222;             /* '<S3>/MATLAB Function1' */

/* TODO */
extern real32_T test2;                 /* '<S3>/Unit Delay3' */

/* TODO */
extern real32_T test8;                 /* '<S3>/Data Type Conversion2' */

/* TODO */
extern real32_T theta_hat_K_1;         /* '<S5>/MATLAB Function' */

/* TODO */
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
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/DTC1' : Eliminate redundant data type conversion
 * Block '<S4>/DTC2' : Eliminate redundant data type conversion
 * Block '<S4>/DTC4' : Eliminate redundant data type conversion
 * Block '<S5>/DTC1' : Eliminate redundant data type conversion
 * Block '<S6>/DTC2' : Eliminate redundant data type conversion
 * Block '<S3>/Rate Transition' : Eliminated since input and output rates are identical
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
 * '<S10>'  : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/MATLAB Function'
 * '<S11>'  : 'CDD_ISP/CddPhaCur&CddRslvr/CddRslvr_CalnPosCaln/PT1'
 * '<S12>'  : 'CDD_ISP/CddPhaCur&CddRslvr/ISP_AnaCalnUdcLnk and Flt/PT1'
 * '<S13>'  : 'CDD_ISP/CddPhaCur&CddRslvr/ISP_AnaCalnUdcLnk and Flt/Saturation Dynamic'
 * '<S14>'  : 'CDD_ISP/ISP_ResolverSel/AlOfsCalFun2'
 * '<S15>'  : 'CDD_ISP/ISP_ResolverSel/AlOfsCalPosSet'
 * '<S16>'  : 'CDD_ISP/ISP_ResolverSel/MATLAB Function'
 * '<S17>'  : 'CDD_ISP/ISP_ResolverSel/MATLAB Function1'
 * '<S18>'  : 'CDD_ISP/ISP_ResolverSel/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_CDD_ISP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
