
/*-----------------------------------------------------------------------------
 *    Include files
 *----------------------------------------------------------------------------*/

#include "LIB_SinCosCalc.h"
#include "LIB_SqrtCalc.h"
#include "LIB_Atan2.h"


extern void SetDFC(boolean inh, boolean xactive,uint16 idx,uint32 debounceTime);
extern void ClrDFC(uint16 idx);
extern boolean Fid_xActive(uint16 idx);

#ifdef __GNUC__
#include "tcx_IoSigIfAdapt_Dio.h"
#include "tcx_IoSigIfAdapt_Adc.h"
#endif


void SinCosShell( sint32  Al, sint16 * SinAl,sint16 * CosAl)
{
	*SinAl = Lib_Sin_s32_s16(Al);
	*CosAl = Lib_Cos_s32_s16(Al);
}



void SqrtShell( float32  x, float32 * sqrtx,float32 * invsqrtx)
{

	*invsqrtx = Lib_InvSqrt_r32_r32(x);
    *sqrtx = x * (*invsqrtx);
}

void Atan2Shell( float32 yaxis, float32 xaxis, uint16 * Al)
{
    *Al = CmnLib_Atan2_r32r32_u16_Inl( yaxis,  xaxis);
}


void GetFidShell(uint16 idx, boolean *st )
{
    #ifdef __GNUC__
    /*call the c code function*/
    *st = Fid_xActive(idx);
    #else
    /*returen a dummy status (always true)*/
    *st = TRUE;
    #endif
}

void SetDfcShell(boolean inh, boolean xactive, uint16 idx, uint32 debounceTime )
{
     #ifdef __GNUC__
    /*call the c code function*/
    SetDFC(inh,xactive,idx,debounceTime);
    #else
    /*do nothing*/

    #endif
}
void ClrDfcShell(uint16 idx )
{
    #ifdef __GNUC__
    /*call the c code function*/
    ClrDFC(idx);
    #else
    /*do nothing*/
    #endif
}

void DioSetShell(boolean stSignal, uint16 idSignal, boolean * outSignal )
{
    #ifdef __GNUC__
    /*call the c code function*/
    Dio_Set(idSignal, stSignal);
    #else
    /*in simulink environment, out = in*/
    *outSignal = stSignal;
    #endif
}

void DioGetShell(boolean stSignal, uint16 idSignal,boolean * outSignal )
{
    #ifdef __GNUC__
    /*call the c code function*/
    *outSignal = Dio_Get(idSignal);
    #else
    /*in simulink environment, out = in*/
    *outSignal = stSignal;
    #endif
}

void AdcGetShell(uint16 valSignal, uint16 idSignal,uint16 * outSignal )
{
    #ifdef __GNUC__
    /*call the c code function*/
    *outSignal = Adc_Get(idSignal);
    #else
    /*in simulink environment, out = in*/
    *outSignal = valSignal;
    #endif
}