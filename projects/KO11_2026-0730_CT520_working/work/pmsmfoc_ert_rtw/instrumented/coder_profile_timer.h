/*
 * File: coder_profile_timer.h
 *
 * Code generated for instrumentation.
 *
 */

#include "rtwtypes.h"

/* Called before starting a profiled section of code */
void profileStart(uint32_T);

/* Called on finishing a profiled section of code */
void profileEnd(uint32_T);

/* Pause the timer while running code associated with storing and uploading the data. */
void xilProfilingTimerFreeze(void);

/* Restart the timer after a pause */
void xilProfilingTimerUnFreeze(void);

/* Code instrumentation method(s) for model CDD_ISP */
void profileStart_CDD_ISP(uint32_T sectionId);
void profileEnd_CDD_ISP(uint32_T sectionId);

/* Code instrumentation method(s) for model FOC */
void profileStart_FOC(uint32_T sectionId);
void profileEnd_FOC(uint32_T sectionId);

/* Code instrumentation method(s) for model pmsmfoc */
void profileStart_pmsmfoc(uint32_T sectionId);
void profileEnd_pmsmfoc(uint32_T sectionId);
