/*
 * File: lookuptabletype.h
 *
 * Code generated for Simulink model 'pmsmfoc'.
 *
 * Model version                  : 11.145
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 28 23:06:30 2026
 */

#ifndef RTW_HEADER_lookuptabletype_h_
#define RTW_HEADER_lookuptabletype_h_
#include "rtwtypes.h"

typedef struct {
  real32_T bp1[21];
  real32_T bp2[10];
  real32_T tab[210];
} ExFeedBackST;

typedef struct {
  real32_T bp1[121];
  real32_T tab[121];
} cPsiIsqAdptMotSTT;

typedef struct {
  real32_T bp1[61];
  real32_T bp2[25];
  real32_T tab[1525];
} cLdAdptMonST;

typedef struct {
  real32_T bp1[61];
  real32_T bp2[25];
  real32_T tab[1525];
} cLqAdptMonST;

typedef struct {
  real32_T bp1[9];
  real32_T tab[9];
} facIphaMaxFreqST;

typedef struct {
  real32_T bp1[21];
  real32_T bp2[5];
  real32_T tab[105];
} MTPAST;

#endif                                 /* RTW_HEADER_lookuptabletype_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
