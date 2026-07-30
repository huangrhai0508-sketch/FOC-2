/*
 * File: pmsmfoc_types.h
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

#ifndef RTW_HEADER_pmsmfoc_types_h_
#define RTW_HEADER_pmsmfoc_types_h_
#include "ECM.h"
#include "EGM.h"
#include "rtwtypes.h"
#include "EiceSilSM.h"
#include "lookuptabletype.h"
#ifndef DEFINED_TYPEDEF_FOR_Sig10ms02ST_
#define DEFINED_TYPEDEF_FOR_Sig10ms02ST_

typedef struct {
  ECM SSM_stDrvMode;
  EGM SSM_stGateDrv;
  boolean_T SSM_flgReqSafeSt;
  boolean_T SSM_bPwrUpHiDrv;
  boolean_T SSM_bPwrUpLoDrv;
  boolean_T SSM_bVdd16Ok;
  real32_T TCC_trqSet;
  real32_T ISP_trqFrc;
  real32_T ISP_tDbcInvU;
  real32_T ISP_tDbcInvV;
  real32_T ISP_tDbcInvW;
  real32_T ISP_frqDes;
  real32_T ISP_isDes;
} Sig10ms02ST;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Sig1ms02ST_
#define DEFINED_TYPEDEF_FOR_Sig1ms02ST_

typedef struct {
  real32_T TCC_trqSet_1ms;
  boolean_T TCC_flgAlOfsCal;
  uint8_T TCC_stRoughCalSet;
  EiceSilSM SSM_ModLoIgbtDrv;
  EiceSilSM SSM_ModHiIgbtDrv;
  boolean_T SSM_bRelsLoDfw;
  boolean_T SSM_bRelsHiDfw;
} Sig1ms02ST;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_CDDIN2_
#define DEFINED_TYPEDEF_FOR_Core2_CDDIN2_

typedef struct {
  uint16_T Core2_iPhaU;
  uint16_T Core2_iPhaV;
  uint16_T Core2_iPhaW;
  int16_T Core2_RvSin;
  int16_T Core2_RvCos;
  real32_T Core2_Udc;
} Core2_CDDIN2;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_PMC_Out_
#define DEFINED_TYPEDEF_FOR_Core2_PMC_Out_

typedef struct {
  real32_T Core2_PMC_UsdScal;
  real32_T Core2_PMC_tiPerd;
  EGM Core2_PMC_stGateDrv;
  boolean_T Core2_PMC_flgReqSafeSt;
  real32_T Core2_PMC_Rs;
  real32_T Core2_PMC_TrqOutEst;
} Core2_PMC_Out;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_SAQ_Out_
#define DEFINED_TYPEDEF_FOR_Core2_SAQ_Out_

typedef struct {
  uint16_T Core2_SAQ_iPhaU;
  uint16_T Core2_SAQ_iPhaV;
  uint16_T Core2_SAQ_iPhaW;
  int16_T Core2_SAQ_rslvSinAmp;
  int16_T Core2_SAQ_rslvCosAmp;
  real32_T Core2_SAQ_HVU;
} Core2_SAQ_Out;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_ISP_Isx_
#define DEFINED_TYPEDEF_FOR_Core2_ISP_Isx_

typedef struct {
  real32_T Core2_ISP_Is;
  real32_T Core2_ISP_isd;
  real32_T Core2_ISP_isq;
  real32_T Core2_ISP_sin;
  real32_T Core2_ISP_isdH6;
  real32_T Core2_ISP_isqH6;
  uint16_T Core2_ISP_AngleOut;
} Core2_ISP_Isx;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_ISP_nx_
#define DEFINED_TYPEDEF_FOR_Core2_ISP_nx_

typedef struct {
  uint8_T Core2_ISP_stAlOfsCal;
  int16_T Core2_ISP_agOffsCal;
  int16_T Core2_ISP_agRtrElec;
  real32_T Core2_ISP_frqElec;
  real32_T Core2_ISP_wElec;
  real32_T Core2_ISP_n;
  real32_T Core2_ISP_nAbs;
} Core2_ISP_nx;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_ISP_agRtr_
#define DEFINED_TYPEDEF_FOR_Core2_ISP_agRtr_

typedef struct {
  int16_T Core2_ISC_agRtrElecAtan2;
  real32_T Core2_ISC_frqElecCaln;
} Core2_ISP_agRtr;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_ISP_iPhabc_
#define DEFINED_TYPEDEF_FOR_Core2_ISP_iPhabc_

typedef struct {
  real32_T Core2_ISP_iPhaU;
  real32_T Core2_ISP_iPhaV;
  real32_T Core2_ISP_iPhaW;
} Core2_ISP_iPhabc;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_ISP_AnaOut_
#define DEFINED_TYPEDEF_FOR_Core2_ISP_AnaOut_

typedef struct {
  Core2_ISP_agRtr Core2_ISP_agRtr;
  Core2_ISP_iPhabc Core2_ISP_iPhabc;
  boolean_T Core2_ISP_bIphCalDone;
  real32_T Core2_ISP_uDc;
} Core2_ISP_AnaOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_ISC_tmpOut_
#define DEFINED_TYPEDEF_FOR_Core2_ISC_tmpOut_

typedef struct {
  real32_T Core2_ISP_tmpMaxIGBT;
  real32_T Core2_ISP_lossTotalIGBT;
  real32_T Core2_ISP_iDcFlt;
  real32_T Core2_ISP_tmpClnt;
} Core2_ISC_tmpOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_ISP_Out_
#define DEFINED_TYPEDEF_FOR_Core2_ISP_Out_

typedef struct {
  Core2_ISP_Isx Core2_ISP_Isx;
  Core2_ISP_nx Core2_ISP_nx;
  Core2_ISP_AnaOut Core2_ISP_AnaOut;
  Core2_ISC_tmpOut Core2_ISC_tmpOut;
} Core2_ISP_Out;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Sig10ms20ST_
#define DEFINED_TYPEDEF_FOR_Sig10ms20ST_

typedef struct {
  real32_T ISP_phaCurrentU;
  real32_T ISP_phaCurrentV;
  real32_T ISP_phaCurrentW;
  real32_T ISP_frqElec;
  real32_T ISP_wElec;
  real32_T ISP_n;
  real32_T ISP_Is;
  uint8_T ISP_stAlOfsCal;
  real32_T ISP_agAlOfsCal;
  real32_T ISP_tmpMaxIGBT;
  real32_T ISP_tmpClnt;
  real32_T ISP_lossTotalIGBT;
  real32_T ISP_iDcFlt;
  boolean_T ISP_bIphCalDone;
  uint8_T ISP_flgResolver;
  real32_T ISP_isd;
  real32_T ISP_isq;
  real32_T ISP_agRtrElec;
  real32_T PMC_TrqOutEst;
} Sig10ms20ST;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Duty_
#define DEFINED_TYPEDEF_FOR_Duty_

typedef struct {
  real32_T f32_DutyUon;
  real32_T f32_DutyVon;
  real32_T f32_DutyWon;
} Duty;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Core2_FOC_Out_
#define DEFINED_TYPEDEF_FOR_Core2_FOC_Out_

typedef struct {
  Duty Duty;
  real32_T Core2_Iqref;
  real32_T Core2_Idref;
  real32_T Core2_Udref;
  real32_T Core2_Uqref;
  real32_T Core2_Usage;
  real32_T Core2_DCCurrent;
} Core2_FOC_Out;

#endif

/* Forward declaration for rtModel */
typedef struct pmsmfoc_tag_RTM pmsmfoc_RT_MODEL;

#endif                                 /* RTW_HEADER_pmsmfoc_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
