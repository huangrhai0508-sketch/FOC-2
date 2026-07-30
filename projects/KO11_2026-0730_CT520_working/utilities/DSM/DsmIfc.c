#include "DsmIfc.h"
#include "dfc_auto_conf.h"
#include "dinh_auto_conf.h"
#include "Platform_Types.h"

#pragma section ".sdata_cal.a1" as
const volatile uint8 uXxxDiagActive_C=0;
const volatile uint8 uYyyDiagActive_C=0;
#pragma section


/*point array to all the DFC type constant*/
extern const DSM_DFCType_st* DFC_autogen_pcst[];
/*point array to all the FID type constant*/
extern const DSM_FIdType* Fid_autogen_pcst[];


bool Fid_xActive(uint16 idx)
{
	const DSM_FIdType * FID_x;
	FID_x = Fid_autogen_pcst[idx-1];
	return DSM_GetDscPermission(*FID_x);

}


void ClrDFC(uint16 idx)
{
	const DSM_DFCType_st *DFC_x;
	DFC_x = DFC_autogen_pcst[idx-1];
	DSM_ResetDebounce(*DFC_x);
}

void SetDFC(bool inh, bool xActive, uint16 idx, uint32 debounceTime)
{
	const DSM_DFCType_st *DFC_x;
	uint16 debounceType;
	DFC_x = DFC_autogen_pcst[idx-1];
	debounceType = DFC_x->debType;


	if(inh) //diagnosis is enbled
	{
		if(debounceType == TIME_IN_ROW_SMALL)
		{// DFC has debounce
			if(xActive)
			{
				DSM_DebRepCheck( *DFC_x
		                 , DSM_FAULT_PERCENT_100
		                 , 0
		                 , debounceTime);
			}
			else
			{
				DSM_DebRepCheck( *DFC_x
		                 , DSM_FAULT_PERCENT_00
		                 , 0
		                 , debounceTime);
			}
		}
		else if(debounceType == NATIVE)
		{// DFC has no debounce
			if(xActive)
			{
				DSM_RepCheck( *DFC_x
		                 , DSM_FAULT_PERCENT_100
		                 , DSM_TST_READY
		                 , DSM_DEBOUNCE_PERCENT_100
		                 , 0);
			}
			else
			{
				DSM_RepCheck(  *DFC_x
		                 , DSM_FAULT_PERCENT_00
		                 , DSM_TST_READY
		                 , DSM_DEBOUNCE_PERCENT_00
		                 , 0);
			}
		}
		else
		{
			//do nothing
		}
	}
	else
	{
		ClrDFC(idx);
	}
}








void XxxDiag_Test_10ms_proc(void)
{
	/*
	if(Fid_InvDiagXXXActive())
	{
		SetDFC_InvXxx(uXxxDiagActive_C);
	}else{
		clrDFC_InvXxx();
	}


	SetDFC_InvYyy(uYyyDiagActive_C);
	*/

}
