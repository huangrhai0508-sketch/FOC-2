/*
 * File: lookuptabletype.h
 *
 * Code generated for Simulink model 'pmsmfoc'.
 *
 * Model version                  : 11.92
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  3 16:25:55 2025
 */

#ifndef RTW_HEADER_lookuptabletype_h_
#define RTW_HEADER_lookuptabletype_h_
#include "rtwtypes.h"

typedef struct {
  real32_T bp1[9];
  real32_T tab[9];
} facIphaMaxFreqST;

typedef struct {
  real32_T bp1[8];
  real32_T bp2[21];
  real32_T tab[168];
} ExFeedBackST;

typedef struct {
  real32_T bp1[21];
  real32_T bp2[5];
  real32_T tab[105];
} MTPAST;

typedef struct {
  real32_T bp1[41];
  real32_T tab[41];
} cPsiIsqAdptMotST;

typedef struct {
  real32_T bp1[41];
  real32_T bp2[17];
  real32_T tab[697];
} cLdAdptST;

typedef struct {
  real32_T bp1[41];
  real32_T bp2[17];
  real32_T tab[697];
} cLqNewAdptST;

#endif                                 /* RTW_HEADER_lookuptabletype_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
