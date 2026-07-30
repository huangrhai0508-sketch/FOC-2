/*
 * File: coder_profile_timer.c
 *
 * Code generated for instrumentation.
 *
 * This file contains stub implementations of the instrumentation utility
 * functions. These stubs allow instrumented code to be compiled
 * into an executable that does not support collection of execution
 * instrumentation data.
 *
 */

#include "coder_profile_timer.h"

/* Code instrumentation offset(s) for model CDD_ISP */
#define profileStart_CDD_ISP_offset    0
#define profileEnd_CDD_ISP_offset      0

/* Code instrumentation offset(s) for model FOC */
#define profileStart_FOC_offset        8
#define profileEnd_FOC_offset          8

/* Code instrumentation offset(s) for model pmsmfoc */
#define profileStart_pmsmfoc_offset    34
#define profileEnd_pmsmfoc_offset      34

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

void xilProfilingTimerFreezeInternal(void)
{
}

void xilProfilingTimerFreeze(void)
{
}

void xilProfilingTimerUnFreezeInternal(void)
{
}

void xilProfilingTimerUnFreeze(void)
{
}

void profileStart(uint32_T sectionId)
{
  UNUSED_PARAMETER(sectionId);
}

void profileEnd(uint32_T sectionId)
{
  UNUSED_PARAMETER(sectionId);
}

/* Code instrumentation method(s) for model CDD_ISP */
void profileStart_CDD_ISP(uint32_T sectionId)
{
  profileStart(profileStart_CDD_ISP_offset + sectionId);
}

void profileEnd_CDD_ISP(uint32_T sectionId)
{
  profileEnd(profileEnd_CDD_ISP_offset + sectionId);
}

/* Code instrumentation method(s) for model FOC */
void profileStart_FOC(uint32_T sectionId)
{
  profileStart(profileStart_FOC_offset + sectionId);
}

void profileEnd_FOC(uint32_T sectionId)
{
  profileEnd(profileEnd_FOC_offset + sectionId);
}

/* Code instrumentation method(s) for model pmsmfoc */
void profileStart_pmsmfoc(uint32_T sectionId)
{
  profileStart(profileStart_pmsmfoc_offset + sectionId);
}

void profileEnd_pmsmfoc(uint32_T sectionId)
{
  profileEnd(profileEnd_pmsmfoc_offset + sectionId);
}
