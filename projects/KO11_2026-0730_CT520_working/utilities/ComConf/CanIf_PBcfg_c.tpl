

/*                                                                                                                     
<Key></Key>
*/                                                                                                                     


/******************************************************************************/
/*              					Include Section	  						  */
/******************************************************************************/

/* CanIf Private header */
#include "CanIf_Priv.h"


/* BusOff callback functions to Can State Manager */
#include "CanSM_Cbk.h"



/*
******************************************************************************
* Variables
******************************************************************************
*/



/* Tx PDUs Configuration */
/* MISRA RULE 8.5 VIOLATION: This is variable is required for testing / debugging */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_TxPduInfo, CANIF_CONST) CanIf_TxPduConfig_0[]=
{

/*
CanTxPduId, TargetTxPduId, CanTxPduId, HthRefId, Controller, CanIdType,  User,  ReadTxPdu,  CbkIdx ,Tx_Buffer Offset , Start Indx , End Indx, CanId,  DLC

CanIf_Transmit used HthRefId to findout the handle of can_pbcfg,and then use the handle to find the mailbox(buffer) to send message
*/
{	CanIfConf_CanIfTxPduCfg_CanIfTxPduCfg_ComUds_Tx,	CanTpConf_CanTpTxNPdu_Pdu_ComUds_Tx_CanTp2CanIf ,	CANIF_STATIC,	CanHwObj_ComUds_Tx,	CANIF_COMM_CAN,	CANIF_STD,	CANTP,	TRUE	,	 0,	0x73D,	8},
{	CanIfConf_CanIfTxPduCfg_CanIfTxPduCfg_ComObd_Tx,	CanTpConf_CanTpTxNPdu_Pdu_ComObd_Tx_CanTp2CanIf ,	CANIF_STATIC,	CanHwObj_ComObd_Tx,	CANIF_RES1_CAN,	CANIF_STD,	CANTP,	TRUE	,	 0,	0x7EE,	8},
{	CanIfConf_CanIfTxPduCfg_XcpTx_Var,	0 ,	CANIF_STATIC,	XcpTx_Var,	CANIF_CALI_CAN,	CANIF_STD,	XCP,	FALSE	,	 0,	0x7F1,	8},
putRegularCANTxPduConfig

};

#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"


/* Rx Handle configuration */
/* MISRA RULE 8.5 VIOLATION: This is variable is required for testing / debugging */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_HrhConfigType, CANIF_CONST) CanIf_HrhConfig_0[] =
{
/*   HRHInfo ,    Pdu/ListIdx,   NumCanIds/NumRanges ,     Controller,  ReadRxPduInfo,		 CanId
 *
 *  rba_can_read used CanIfHrh to find the configuration in CanIf, and then used CanIf_RxIndication(Hrh, xxx) to receive messages
 *
 *  for example: rba_can receive a new message,we find its CanIfHrh is #define CanIfConf_CanIfHrhCfg_CanHwOjb_ComUds_Rx_func1       3
 *  we used this 3 find in the CanIf_HrhConfig[] to get the PduIdx is 0 and used this 0 to find in the RxPduCfg_0 get the RxPdu information
 *   */

putRegurlarCANHrhConfig
{ 	CANIF_FULL 	,		0	,	 	1 	,	CANIF_COMM_CAN,		CANIF_READ_NONE,	0x7DF},
{ 	CANIF_FULL 	,		1	,	 	1 	,	CANIF_COMM_CAN,		CANIF_READ_NONE,	0x735},
{ 	CANIF_FULL 	,		2	,	 	1 	,	CANIF_RES1_CAN,		CANIF_READ_NONE,	0x7E6},
{ 	CANIF_FULL 	,		3	,	 	1 	,	CANIF_CALI_CAN,		CANIF_READ_NONE,	0x7F0},
{ 	CANIF_FULL 	,		4	,	 	1 	,	CANIF_CALI_CAN,		CANIF_READ_NONE,	0x6F1}
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"



/* Rx PDUs Configuration */
/* MISRA RULE 8.5 VIOLATION: This is variable is required for testing / debugging */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"

CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig_0[]=
{
/*     RxBufferOffset,  target ID,  RxPduId , HRH , CbkIdx, User,  DLC      */

{CanTpConf_CanTpRxNPdu_Pdu_ComUds_Rx_CanIf2CanTp_func1, CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_ComUds_Rx_func_1, putUdsRxPdfHrh, 0, CANTP, 8},
{CanTpConf_CanTpRxNPdu_Pdu_ComUdsObd_Rx_CanIf2CanTp, CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_ComUdsObd_Rx,        putUdsObdRxPdfHrh, 0, CANTP, 8},
{CanTpConf_CanTpRxNPdu_Pdu_ComObd_Rx_CanIf2CanTp, CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_ComObd_Rx,              putObdRxPdfHrh, 0, CANTP, 8},
{0,                                               CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_XcpRx_Cmd,              putXcpRxPdfHrh, 0, XCP, 8},
{3,                                               CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_TcProg,                 putTcProgPdfHrh, 0, USER, 8},
putRegularCANRxPduConfig

};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"


extern void TcProgSrvMsgs_pfn(VAR(PduIdType, AUTOMATIC)CanRxPduId, P2CONST(CanIf_PduInfoType, AUTOMATIC,CANIF_APPL_CONST)PduInfoPtr);

CONST (CanIf_RxCbk_Prototype,CANIF_CONST) CanIf_RxCbk_0[] = 
{
	{&TcProgSrvMsgs_pfn},
	{NULL_PTR}
};


/* CANIF callback configuration */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_CallbackFuncType, CANIF_CONST) CanIf_Callback =
{
	&CanSM_ControllerBusOff,
	NULL_PTR,
	&CanSM_ControllerModeIndication,
	NULL_PTR,
	NULL_PTR,
	NULL_PTR
	

};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"


/* Global configuration structure */

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ConfigType, CANIF_CONST) CanIf_Config =
{
CanIf_TxPduConfig_0,
CanIf_RxPduConfig_0,
CanIf_HrhConfig_0,
CANIF_NUM_CANTXPDUIDS_0,
CANIF_NUM_CANRXPDUIDS_0,
CANIF_NUM_DYNAMIC_CANTXPDUIDS_0,
CANIF_NUM_CONTROLLERS_0

};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "CanIf_MemMap.h"




