
#ifndef _COM_CFG_H
#define _COM_CFG_H
#include "std_type.h"
/***********************************************************************/
/*  Name           : COM_VersionInfoType                             */
/*  Description    : Vendor Information                                */
/***********************************************************************/



/*  START: Local #defines  */


#define COM_TX_TIME_BASE         0.01

#define COM_RX_TIME_BASE         0.01

#define COM_GW_TIME_BASE         0.0


#define COM_CONFIGURATION_ID                0

/************************ SIGNAL GROUP switches *************************/
/************************************************************************/
/* SIGNAL GROUP switches */

/* #define COM_TX_SIGNALGROUP */

/* #define COM_RX_SIGNALGROUP */
/************************************************************************/
/************************************************************************/

/************************ UPDATE_BIT switches ***************************/
/************************************************************************/

/* #define COM_RxSigUpdateBit */

/* #define COM_TxSigUpdateBit */

/* #define COM_RxSigGrpUpdateBit */

/* #define COM_TxSigGrpUpdateBit */

#if (defined(COM_RxSigUpdateBit) || defined(COM_TxSigUpdateBit) || defined(COM_RxSigGrpUpdateBit) || defined(COM_TxSigGrpUpdateBit))
#define COM_UPDATEBIT
#endif /* #if (defined(COM_RxSigUpdateBit) || defined(COM_TxUpdateBit) || defined(COM_RxSigGrpUpdateBit) || defined(COM_TxSigGrpUpdateBit)) */
/************************************************************************/
/************************************************************************/

/************************ RX TIME OUT switches **************************/
/************************************************************************/

/* #define COM_RxSigUpdateTimeout */

/* #define COM_RxSigGrpUpdateTimeout */

/* #define  COM_RxUpdateTimeoutNotify */

#define COM_RxIPduTimeout

#define COM_RxIPduTimeoutNotify

/* #define COM_RxTimeoutSignalActionReplace */


/* #define COM_RxTimeoutSignalGrpActionReplace */
/************************************************************************/
/************************************************************************/

/************************ TX TIME OUT switches **************************/
/************************************************************************/

#define COM_TxIPduTimeOut

#define COM_TxIPduTimeOutNotify
/************************************************************************/
/************************************************************************/


/********************* TRANSFER PROPERTY  switches **********************/
/************************************************************************/

/*#define COM_SigTriggeredOnChange*/


/*#define COM_SigGrpTriggeredOnChange*/

/************************************************************************/
/************************************************************************/

/********************* RX NOTIFICATION switches *************************/
/************************************************************************/

/* #define COM_RxSignalNotify */

#define COM_RxIPduNotification 

/* #define COM_RxSignalGrpNotify */
/************************************************************************/
/************************************************************************/


/********************* FILTER related switches **************************/
/************************************************************************/

/* #define COM_RxFilters */

#define COM_TxFilters

#if (defined(COM_RxFilters) || defined(COM_TxFilters))
#define COM_FILTERS
#endif

/* #define COM_F_MASKEDNEWEQUALSX */

/* #define COM_F_MASKEDNEWDIFFERSX */

/* #define COM_F_MASKEDNEWDIFFERSOLD */

/* #define COM_F_NEWISWITHIN_POS */

/* #define COM_F_NEWISWITHIN_NEG */

/* #define COM_F_NEWISOUTSIDE_POS */

/* #define COM_F_NEWISOUTSIDE_NEG */

/* #define COM_F_ONEEVERYN */
/************************************************************************/
/************************************************************************/

/*********************** RX INVALID switches ****************************/
/************************************************************************/

/* #define COM_RxSigInvalid */

/* #define COM_RxSigInvalidNotify */

/* #define COM_RxSigGrpInvalid */

/* #define COM_RxSigGrpInvalidNotify */

/* #define COM_RxSigGrpInvalidActionReplace */

/************************************************************************/
/************************************************************************/

/*********************** TX INVALID switches ****************************/
/************************************************************************/
/* #define COM_TxInvalid */

/* #define COM_TxGrpSigInvalid */
/************************************************************************/
/************************************************************************/

/******************* RX IPdu Deferred Processing ************************/
/************************************************************************/
/* #define COM_RxIPduDeferredProcessing */
/* #define COM_RxSignalGrpDeferredProcessing */

/************************************************************************/
/************************************************************************/

/********************* DYNAMIC SIGNAL switches **********************/
/************************************************************************/
/* #define COM_TX_DYNAMIC_SIGNAL_SUPPORT */


/* #define COM_RX_DYNAMIC_SIGNAL_SUPPORT */
/********************* FLOAT64 switches **********************/
/************************************************************************/
/* #define COM_TXGRPSIG_FLOAT64SUPP */

/* #define COM_TXSIG_FLOAT64SUPP */

/* #define COM_RXSIG_FLOAT64SUPP */

/* #define COM_RXGRPSIG_FLOAT64SUPP */
/************************** Misc FEATURES *******************************/
/************************************************************************/

/* #define COM_ERRORNOTIFICATION */

/* #define COM_TXDOUBLEBUFFER */

/* #define COM_RxIPduCallOuts */

/* #define COM_TxIPduCallOuts */


/*#define COM_MIXEDPHASESHIFT*/


#define COM_TxIPduNotification

#define COM_CONFIGURATION_USE_DET           STD_OFF
#define COM_VERSION_INFO_API                STD_OFF

#define COM_COMMON_TX_PERIOD				STD_OFF
#define COM_ENABLE_JITTERFLITER				STD_OFF
/* #define COM_ENABLE_READRXIPDULENGTH */

#define	 COM_IPDUCONTROL_VIA_CALIBRATION
#define COM_ARSRVLIB_SUPPORT
/* #define COM_PROVIDE_IPDU_STATUS */

/* #define COM_TXSCHEDULED_DIFF_TIMEBASE */
/* #define COM_MULTICORE_SUPPORT */

/************************************************************************/
/************************************************************************/



/*  START: Local #defines  */

#define COM_NUM_TOTAL_IPDU_GRP  2u
#define COM_NUM_ARR_IPDUGRPVECT	1u

#ifdef COM_RxIPduDeferredProcessing

	/* Buffer to hold data for deferred signal processing */
	#define COM_MAX_DEFERRED_IPDUBUFF_SIZE  1
#endif /* #ifdef COM_RxIPduDeferredProcessing */



#define COM_UPDATE_MAX      0xFF    /* max ipdu size */

#define COM_MAX_IPDU_SIZE 8 /* in bytes */

#define COM_RXTIMER_MAX			0xFFFFu
/*  END: Local #defines  */

/* Start Type Declarations*/

/* Enum for Com status, Init/uninit */
typedef enum
{
    COM_UNINIT,
    COM_INIT
}Com_StatusType;

/* Filter type */
#if defined(COM_F_MASKEDNEWEQUALSX) || defined(COM_F_MASKEDNEWDIFFERSX)
    typedef struct
    {
        uint32 Mask;
        uint32 X_Val;
    }Com_MaskXType;
#endif
#if defined(COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS)
    typedef struct
    {
        uint32 Min;
        uint32 Max;
    }Com_POSMinMaxType;
#endif
#if defined(COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG)
    typedef struct
    {
        sint32 Min;
        sint32 Max;
    }Com_NEGMinMaxType;
#endif
#ifdef COM_F_ONEEVERYN
    typedef struct
    {
        uint32 Period;
        uint32 Offset;
        uint8  Occurrence;
    }Com_OneEveryNType;
#endif

	typedef uint16 Com_SignalIdType;
#if defined(COM_TX_SIGNALGROUP) || defined(COM_RX_SIGNALGROUP)
	typedef uint16 Com_SignalGroupIdType;
#endif


typedef uint8 Com_IpduIdType;


typedef uint16 Com_IpduGroupIdType;

typedef uint8 Com_IpduGroupVector[COM_NUM_ARR_IPDUGRPVECT];




typedef uint8    Com_GrpSignalIdType;



typedef uint16    Com_NoOfTxGrpSignalType;
	

typedef uint16    Com_NoOfRxGrpSignalType;
	

#ifdef COM_TX_SIGNALGROUP




typedef uint8    Com_TxIntGrpSignalIdType;

#endif

#ifdef COM_RX_SIGNALGROUP

typedef uint8    Com_RxIntGrpSignalIdType; 


#endif






typedef uint8    Com_TxIntSignalIdType;



typedef uint8    Com_RxIntSignalIdType;







#ifdef COM_TX_SIGNALGROUP



 
 typedef uint8 Com_TxIntSignalGroupIdType;
 
#endif

#ifdef COM_RX_SIGNALGROUP 
  
 typedef uint8 Com_RxIntSignalGroupIdType;
 
 

#endif







typedef uint8   Com_BitsizeType;
typedef uint8 Com_BitpositionType;
#if defined(COM_TxFilters) || defined (COM_RxFilters) 
typedef uint8   Com_FilterType;
#endif

#if defined(COM_SigTriggeredOnChange) || defined(COM_SigGrpTriggeredOnChange)
typedef uint8   Com_OldValType;
#endif


typedef uint8 Com_SigBuffIndexType;



typedef uint8 Com_RxGrpSigBuffIndexType;


typedef uint8 Com_TxGrpSigBuffIndexType;

/*  END: Type Declaration  */



/* Signal IDs*/
/* Tx Signal ID*/


/* Rx Signal ID*/





/* Group Signal Ids */


/* Tx GroupSignal ID*/
#ifdef COM_TX_SIGNALGROUP

#endif
#ifdef COM_RX_SIGNALGROUP
/* Rx GroupSignal ID*/

#endif



/* START: Signal Group Ids */

/* Tx SignalGroup ID*/

/* Rx SignalGroup ID*/






/* END: Signal Group Ids   */

/* START: IPDU Ids */
/* Tx IPdus */

	/* Rx IPdus */
	
/* END: IPDU Ids   */

/* START: IPDU Group Ids   */
/* IPduGroup ID*/
	#define ComIPduGroup_RBM_INV_BASE_TX 0
	#define ComIPduGroup_RBM_INV_BASE_RX 1


typedef struct
{
    uint32 Com_Num_Signals;
    uint32 Com_Num_SignalGrp;
    uint32 Com_Num_GrpSignals;
    uint32 Com_Num_Tx_Ipdu;
    uint32 Com_Num_Rx_Ipdu;
    uint32 Com_Num_FirstLevel_Ipdu_Grp;
    uint32 Com_Num_Total_Ipdu_Grp;
}Com_ConfigType;



/* START: I-PDU Buffers */
/* ComIPdu*/

/* END: I-PDU Buffers */
/* Filter type */
#if defined (COM_F_MASKEDNEWEQUALSX) || defined(COM_F_MASKEDNEWDIFFERSX)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
extern  CONST(Com_MaskXType ,COM_CONST) Com_MaskX[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#endif

#ifdef COM_F_MASKEDNEWDIFFERSOLD

#define COM_START_SEC_CONST_32
#include "Com_MemMap.h"
extern CONST(uint32 ,COM_CONST)  Com_Mask[1];
#define COM_STOP_SEC_CONST_32
#include "Com_MemMap.h"
#define COM_START_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR)  Com_F_OldVal[1];
#define COM_STOP_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"

#endif

#if defined(COM_SigTriggeredOnChange) || defined(COM_SigGrpTriggeredOnChange)
#define COM_START_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_OldValTrigOnChng[1];
#define COM_STOP_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"


#endif

#if defined(COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
extern CONST(Com_POSMinMaxType ,COM_CONST) Com_POSMinMax[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#endif

#if defined(COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG)
#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
extern CONST(Com_NEGMinMaxType ,COM_CONST) Com_NEGMinMax[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

#endif

#ifdef COM_F_ONEEVERYN
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(Com_OneEveryNType,COM_VAR) Com_OneEveryN[1];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"

#endif

#define Com_getfloat64InitValue(val) 0


#ifdef COM_RXSIG_FLOAT64SUPP
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_SigType_f64[];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_RXSIG_FLOAT64SUPP */



#ifdef COM_RX_SIGNALGROUP


/*Start: Rx Group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern VAR(uint8,COM_VAR) Com_RxGrpSigType_u8[];
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
/*End: Rx Group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/*Start: Rx Group Signal Buffer -----> uint16/sint16*/
#define COM_START_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
extern VAR(uint16,COM_VAR) Com_RxGrpSigType_u16[];
#define COM_STOP_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
/*End:Rx Group Signal Buffer -----> uint16/sint16*/

/*Start: Rx Group Signal Buffer -----> uint32/sint32*/
#define COM_START_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_RxGrpSigType_u32[];
#define COM_STOP_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
/*End: Rx Group Signal Buffer -----> uint32/sint32*/

#ifdef COM_RXGRPSIG_FLOAT64SUPP
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_RxGrpSigType_f64[];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_RXGRPSIG_FLOAT64SUPP */



/*Start:Rx Group Signal second Buffer -----> uint8/sint8/boolean/uint8[n]*/
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern VAR(uint8,COM_VAR) Com_SecondRxGrpSigType_u8[];
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
/*End: Rx Group Signal second Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/*Start: Rx Group Signal second Signal Buffer -----> uint16/sint16*/
#define COM_START_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
extern VAR(uint16,COM_VAR) Com_SecondRxGrpSigType_u16[];
#define COM_STOP_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
/*End: Rx Group Signal second Signal Buffer -----> uint16/sint16*/

/*Start: Rx Group Signal second Signal Buffer -----> uint32/sint32*/
#define COM_START_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_SecondRxGrpSigType_u32[];
#define COM_STOP_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
/*End: Rx Group Signal second Signal Buffer -----> uint32/sint32*/

#ifdef COM_RXGRPSIG_FLOAT64SUPP
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_SecondRxGrpSigType_f64[];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_RXGRPSIG_FLOAT64SUPP */

#endif /* #ifdef COM_RX_SIGNALGROUP*/

#ifdef COM_TX_SIGNALGROUP

/*Start: Tx group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/
#define COM_START_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
extern VAR(uint8,COM_VAR) Com_TxGrpSigType_u8[];
#define COM_STOP_SEC_VAR_CLEARED_8
#include "Com_MemMap.h"
/*End: Tx group Signal Buffer -----> uint8/sint8/boolean/uint8[n]*/

/*Start: Tx group Signal Buffer -----> uint16/sint16*/
#define COM_START_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
extern VAR(uint16,COM_VAR) Com_TxGrpSigType_u16[];
#define COM_STOP_SEC_VAR_CLEARED_16
#include "Com_MemMap.h"
/*End: Tx group  Signal Buffer -----> uint16/sint16*/

/*Start: Tx group Signal Buffer -----> uint32/sint32*/
#define COM_START_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
extern VAR(uint32,COM_VAR) Com_TxGrpSigType_u32[];
#define COM_STOP_SEC_VAR_CLEARED_32
#include "Com_MemMap.h"
/*End: Tx group Signal Buffer -----> uint32/sint32*/

#ifdef COM_TXGRPSIG_FLOAT64SUPP
/*Start: Tx group Signal Buffer -----> float64 */
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
extern VAR(float64,COM_VAR) Com_TxGrpSigType_f64[];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
/*End: Tx group Signal Buffer -----> float64 */
#endif /* #ifdef COM_TXGRPSIG_FLOAT64SUPP */

#endif /* #ifdef COM_TX_SIGNALGROUP */
#endif   /* COM_CFG_H_ */
