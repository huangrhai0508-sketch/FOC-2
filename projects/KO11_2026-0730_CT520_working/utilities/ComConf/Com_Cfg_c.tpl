

/* FC_VariationPoint_START */
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(uint8, COM_CODE)  COM_CheckTxIPduCalibrationVarStatus(VAR(PduIdType, AUTOMATIC) IpduId)
{

	switch(IpduId)
	{

     case 0:  return(0x3FF);
	 break;

     case 1:  return(0x3FF);
	 break;

     case 2:  return(0x3FF);
	 break;
	 default: return(1);
	 break;
	}

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(uint8, COM_CODE)  COM_CheckRxIPduCalibrationVarStatus(VAR(PduIdType, AUTOMATIC) IpduId)
{

	switch(IpduId)
	{

     case 0:  return(0x3FF);
	 break;

     case 1:  return(0x3FF);
	 break;

     case 2:  return(0x3FF);
	 break;
	 default: return(1);
	 break;
	}

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/* FC_VariationPoint_END */


#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

VAR(PduInfoType,COM_VAR)          Com_PduInfo_s[COM_NUM_TX_IPDU];

VAR(Com_TxIpduRamData,COM_VAR)	 Com_TxIpduRam_s[COM_NUM_TX_IPDU];

VAR(Com_RxIpduRamData,COM_VAR)    Com_RxIpduRam_s[COM_NUM_RX_IPDU];

VAR(Com_TxSignalFlagType,COM_VAR)   Com_TxSignalFlag[COM_NUM_TX_SIGNALS];

VAR(Com_RxSignalFlagType,COM_VAR)   Com_RxSignalFlag[COM_NUM_RX_SIGNALS];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

VAR(uint8,COM_VAR)    Com_IpduCounter_s[COM_NUM_TX_IPDU + COM_NUM_RX_IPDU];

VAR(uint8,COM_VAR)    Com_IpduCounter_DM[COM_NUM_RX_IPDU];
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

VAR(Com_IpduGroupVector, COM_VAR) Com_IpduGrpVector;

VAR(Com_IpduGroupVector, COM_VAR) Com_IpduGrpVector_DM;
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"


#ifdef COM_RX_SIGNALGROUP
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxSignalGrpFlagType,COM_VAR) Com_RxSignalGrpFlag[COM_NUM_RX_SIGNALGRP+1];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif

#ifdef COM_TX_SIGNALGROUP
#ifdef COM_SigGrpTriggeredOnChange
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxSignalGrpFlagType,COM_VAR) Com_TxSignalGrpFlag[COM_NUM_TX_SIGNALGRP+1];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxGrpSignalFlagType,COM_VAR) Com_TxGrpSignalFlag[COM_NUM_TX_GRPSIGNALS+1];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif


#ifdef COM_RxIPduDeferredProcessing
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
	/* Buffer to hold data for deferred signal processing */
	VAR(uint8,COM_VAR) Com_DeferredBuffer[COM_MAX_DEFERRED_IPDUBUFF_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
#endif /* #ifdef COM_RxIPduDeferredProcessing */
