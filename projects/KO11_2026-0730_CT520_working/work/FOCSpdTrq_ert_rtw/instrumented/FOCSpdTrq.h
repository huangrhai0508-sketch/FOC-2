/*
 * File: FOCSpdTrq.h
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

#ifndef RTW_HEADER_FOCSpdTrq_h_
#define RTW_HEADER_FOCSpdTrq_h_
#ifndef FOCSpdTrq_COMMON_INCLUDES_
#define FOCSpdTrq_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOCSpdTrq_COMMON_INCLUDES_ */

#include "FOCSpdTrq_types.h"
#include "ECM.h"
#include "lookuptabletypeP1.h"

/* Includes for objects with custom storage classes */
#include "lookuptableP1.h"
#include "parameter0.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define FOCSpdTrq_M                    (GRSM)

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Switch2;                    /* '<S23>/Switch2' */
  real32_T Add;                        /* '<S2>/Add' */
  real32_T UnitDelay1_DSTATE;          /* '<S22>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
  real32_T UnitDelay_DSTATE_e;         /* '<S3>/Unit Delay' */
  real32_T UnitDelay_DSTATE_n;         /* '<S25>/Unit Delay' */
  real32_T UnitDelay_DSTATE_l;         /* '<S24>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_o;        /* '<S20>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_h;         /* '<S17>/Unit Delay' */
  real32_T UnitDelay_DSTATE_m;         /* '<S16>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o;         /* '<S2>/Unit Delay' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_g;        /* '<S2>/Unit Delay1' */
  real32_T UnitDelay5_DSTATE;          /* '<S2>/Unit Delay5' */
  real32_T UnitDelay3_DSTATE;          /* '<S2>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S2>/Unit Delay4' */
  real32_T UnitDelay1_DSTATE_l;        /* '<S12>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_a;        /* '<S13>/Unit Delay1' */
  real32_T UnitDelay6_DSTATE;          /* '<S2>/Unit Delay6' */
  uint32_T m_bpIndex;                  /* '<S2>/Amplitude_Table' */
  uint32_T m_bpIndex_e;                /* '<S2>/Amplitude_Table1' */
  boolean_T TorqueControl_MODE;        /* '<S1>/Torque Control' */
  boolean_T SpeedControl_MODE;         /* '<S1>/Speed Control' */
} pmsmfocS_D_Work;

/* External inputs (root inport signals with default storage) */
typedef struct {
  ECM ControlMode;                     /* '<Root>/ControlMode' */
  real32_T TrqMax;                     /* '<Root>/TrqMax' */
  real32_T TrqMin;                     /* '<Root>/TrqMin' */
  boolean_T Drive;                     /* '<Root>/Drive' */
  real32_T SpeedPiMaxRatio;            /* '<Root>/SpeedPiMaxRatio' */
  real32_T SpeedPiMinRatio;            /* '<Root>/SpeedPiMinRatio' */
  real32_T f32_TorqueCmd_Nm;           /* '<Root>/f32_TorqueCmd_Nm' */
  real32_T f32_Speedref_rpm;           /* '<Root>/f32_Speedref_rpm' */
  real32_T SpdDes;                     /* '<Root>/SpdDes' */
  real32_T f32_SpeedAct_rpm;           /* '<Root>/f32_SpeedAct_rpm' */
  real32_T isdSet_last;                /* '<Root>/isdSet_last' */
  real32_T Ts;                         /* '<Root>/Ts' */
  int16_T Angle;                       /* '<Root>/Angle' */
  real32_T f32_speedfinal;             /* '<Root>/f32_speedfinal' */
} pmsmfocS_ExternalInputs;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T TrqEmDes;                   /* '<Root>/TrqEmDes' */
  real32_T speedref;                   /* '<Root>/speedref' */
} pmsmfocS_ExternalOutputs;



/* Declare global externs for instrumentation */
extern void profileStart_FOCSpdTrq(uint32_T);
extern void profileEnd_FOCSpdTrq(uint32_T);
/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct pmsmfocS_tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern pmsmfocS_D_Work GRSDWork;

/* External inputs (root inport signals with default storage) */
extern pmsmfocS_ExternalInputs GRSU;

/* External outputs (root outports fed by signals with default storage) */
extern pmsmfocS_ExternalOutputs GRSY;

/* Model entry point functions */
extern void FOCSpdTrq_initialize(void);
extern void FOCSpdTrq_step(void);
extern void FOCSpdTrq_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern real32_T AntiWindup_Alfa;       /* '<S2>/MATLAB Function1' */

/* TODO */
extern real32_T AntiWindup_Kpvalue;    /* '<S2>/MATLAB Function1' */

/* TODO */
extern real32_T AntiWindup_Signal;     /* '<S2>/Data Type Conversion5' */

/* TODO */
extern real32_T AntiWindup_coef;       /* '<S2>/Data Type Conversion' */

/* TODO */
extern real32_T AntiWindup_integral;   /* '<S2>/MATLAB Function1' */

/* TODO */
extern real32_T AntiWindup_out;        /* '<S2>/MATLAB Function1' */

/* TODO */
extern real32_T AsrKp_Calvalue;        /* '<S2>/Data Type Conversion3' */

/* TODO */
extern real32_T Asrintgin_value;       /* '<S2>/MATLAB Function' */

/* TODO */
extern real32_T FFKp_value;            /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T FFintgin_value;        /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T FFout;                 /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T FOC_Ki;                /* '<S3>/AsrPI' */

/* speedki */
extern real32_T FOC_Kp;                /* '<S3>/AsrPI' */

/* speedkp */
extern real32_T K1_Limitvalue_P1;      /* '<S14>/Switch2' */

/* TODO */
extern real32_T K1_value_P1;           /* '<S2>/Amplitude_Table' */

/* TODO */
extern real32_T K3_value_P1;           /* '<S2>/Amplitude_Table1' */

/* TODO */
extern real32_T LPFcoswave;            /* '<S13>/Sum1' */

/* TODO */
extern real32_T LPFsinwave;            /* '<S12>/Sum1' */

/* TODO */
extern real32_T PDFF_Kvp_coef;         /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T PDFF_SpdrefMuxKff;     /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T PIout;                 /* '<S2>/MATLAB Function' */

/* TODO */
extern real32_T R_finaloutput;         /* '<S2>/Gain4' */

/* TODO */
extern real32_T R_output;              /* '<S2>/MATLAB Function6' */

/* TODO */
extern real32_T R_wo;                  /* '<S2>/Gain3' */

/* TODO */
extern real32_T Trqcomp_Max_P1;        /* '<S2>/Add2' */

/* TODO */
extern real32_T Trqcomp_Min_P1;        /* '<S2>/Add3' */

/* TODO */
extern real32_T alpha;                 /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T beta;                  /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T beta_signal;           /* '<S2>/MATLAB Function3' */

/* TODO */
extern real32_T comp_P1;               /* '<S2>/Switch5' */

/* TODO */
extern real32_T cosfixtrq;             /* '<S2>/cos' */

/* TODO */
extern real32_T coswave;               /* '<S2>/MATLAB Function5' */

/* TODO */
extern real32_T err_thresh_high;       /* '<S2>/MATLAB Function1' */

/* TODO */
extern real32_T err_thresh_low;        /* '<S2>/MATLAB Function1' */

/* TODO */
extern real32_T sinfixtrq;             /* '<S2>/sin ' */

/* TODO */
extern real32_T sinwave;               /* '<S2>/MATLAB Function4' */

/* TODO */
extern real32_T total_fixtrq;          /* '<S2>/Gain' */

/* TODO */
extern real32_T wave_P1;               /* '<S2>/MATLAB Function2' */

/* TODO */

/* Real-time Model object */

/* Const memory section */
extern pmsmfocS_RT_MODEL *const GRSM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant13' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Unit Delay1' : Unused code path elimination
 * Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'FOCSpdTrq'
 * '<S1>'   : 'FOCSpdTrq/Subsystem'
 * '<S2>'   : 'FOCSpdTrq/Subsystem/Speed Control'
 * '<S3>'   : 'FOCSpdTrq/Subsystem/Subsystem1'
 * '<S4>'   : 'FOCSpdTrq/Subsystem/Torque Control'
 * '<S5>'   : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function'
 * '<S6>'   : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function1'
 * '<S7>'   : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function2'
 * '<S8>'   : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function3'
 * '<S9>'   : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function4'
 * '<S10>'  : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function5'
 * '<S11>'  : 'FOCSpdTrq/Subsystem/Speed Control/MATLAB Function6'
 * '<S12>'  : 'FOCSpdTrq/Subsystem/Speed Control/PT1_1'
 * '<S13>'  : 'FOCSpdTrq/Subsystem/Speed Control/PT1_2'
 * '<S14>'  : 'FOCSpdTrq/Subsystem/Speed Control/Saturation Dynamic'
 * '<S15>'  : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem'
 * '<S16>'  : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem1'
 * '<S17>'  : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem4'
 * '<S18>'  : 'FOCSpdTrq/Subsystem/Speed Control/cos'
 * '<S19>'  : 'FOCSpdTrq/Subsystem/Speed Control/sin '
 * '<S20>'  : 'FOCSpdTrq/Subsystem/Speed Control/Subsystem/PT1_1'
 * '<S21>'  : 'FOCSpdTrq/Subsystem/Subsystem1/AsrPI'
 * '<S22>'  : 'FOCSpdTrq/Subsystem/Subsystem1/PT1_1'
 * '<S23>'  : 'FOCSpdTrq/Subsystem/Torque Control/Saturation Dynamic'
 * '<S24>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdNegLimit'
 * '<S25>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdPosLimit'
 * '<S26>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdNegLimit/MATLAB Function'
 * '<S27>'  : 'FOCSpdTrq/Subsystem/Torque Control/SpdPosLimit/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_FOCSpdTrq_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
