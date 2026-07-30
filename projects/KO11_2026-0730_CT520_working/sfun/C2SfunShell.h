#ifndef _C2SFUNSHELL_H_
#define _C2SFUNSHELL_H_

#include "Platform_Types.h"


extern void SinCosShell( sint32  Al, sint16 * SinAl,sint16 * CosAl);
extern void SqrtShell( float32  x, float32 * sqrtx,float32 * invsqrtx);
extern void Atan2Shell(float32 yaxis, float32 xaxis, uint16 * Al);
extern void GetFidShell(uint16 idx, boolean *st );
extern void SetDfcShell(boolean inh, boolean xactive, uint16 idx, uint32 debounceTime );
extern void ClrDfcShell(uint16 idx );
extern void DioSetShell(boolean stSignal, uint16 idSignal,boolean * outSignal);
extern void DioGetShell(boolean stSignal, uint16 idSignal,boolean * outSignal );
extern void AdcGetShell(uint16 valSignal, uint16 idSignal,uint16 * outSignal );
#endif 
