

/*
***************************************************************************************************
* Includes
***************************************************************************************************
*/

/* CanDriver Header */
#include "tcx_Can.h"
/* This header file is included for Canif HRH handle reference values*/
#include "CanIf_Cfg.h"
/* Import CanIf Callback functions */
#include "CanIf_Cbk.h"


/* TC27xx CPU registers */
#include "tcx_Can_Reg.h"

#include "tcx_Can_Prv.h"
#include "Can_Cfg.h"
/* SchM file included. Needed incase of Calibration */
#include "tcx_Can_Cfg_SchM.h"

#define TCX_CAN_START_SEC_DEFAULT_CONST_32
#include "tcx_Can_MemMap.h"

/* CAN Driver Controller Base Address */

const uint32 tcx_Can_NodeBA[8] = {0xF0018200, 0xF0018300, 0xF0018400, 0xF0018500, 0xF0018600, 0xF0018700, 0xF0018800, 0xF0018900 };

#define TCX_CAN_STOP_SEC_DEFAULT_CONST_32
#include "tcx_Can_MemMap.h"



#define TCX_CAN_START_SEC_DEFAULT_CONST_UNSPECIFIED
#include "tcx_Can_MemMap.h"


/* Hardware handle configuration for CAN */
static CONST (Can_HardwareHandleType_tst, CAN_CONST) Can_HrdHndlTable_acst_0[] =
{//Donot change the order of the message group.
/*      CanId   	FilterMask     Handle       BufferID       logic Node    	   Direction     CanIdType  CanIfHrh    Interrupt
*/

	putTxPollingCANDesc
	{       0x73D,            0x7FF    ,	     CanHwObj_ComUds_Tx,            0,        COMM_CAN_0,   	 CAN_TX,   	 CAN_STD,			putUdsTxCanIfHrh,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },
	{       0x7EE,            0x7FF    ,	     CanHwObj_ComObd_Tx,            1,        RES1_CAN_0,   	 CAN_TX,   	 CAN_STD,			putUdsObdTxCanIfHrh,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },
	{       0x7F1,            0x7FF    ,	     XcpTx_Var,                     2,        CALI_CAN_0,  	 CAN_TX,   	 CAN_STD,			putXcpTxCanIfHrh,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },
	putRxPollingCANDesc
	{       0x7DF,            0x7FF    ,	     CanHwObj_ComUds_Rx_func1,      putUdsRxfun1BufId,        COMM_CAN_0,   	 CAN_RX,   	 CAN_STD,			CanIfConf_CanIfHrhCfg_CanHwOjb_ComUds_Rx_func1,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },
	{       0x735,            0x7FF    ,	     CanHwObj_ComUdsObd_Rx,         putUdsObdRxBufId,        COMM_CAN_0,   	 CAN_RX,   	 CAN_STD,			CanIfConf_CanIfHrhCfg_CanHwOjb_ComUdsObd_Rx,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },
	{       0x7E6,            0x7FF    ,	     CanHwObj_ComObd_Rx,            putObdRxBufId,        RES1_CAN_0,   	 CAN_RX,   	 CAN_STD,			CanIfConf_CanIfHrhCfg_CanHwOjb_ComObd_Rx,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },
	{       0x7F0,            0x7FF    ,	 XcpRx_Cmd,                     putXcpRxCmdBufId,        CALI_CAN_0,    CAN_RX,   	 CAN_STD,			CanIfConf_CanIfHrhCfg_XcpRx_Cmd,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },
    {       0x6F1,            0x7FF    ,	 TcProg,                     putTcProgBufId,        CALI_CAN_0,    CAN_RX,   	 CAN_STD,			CanIfConf_CanIfHrhCfg_TcProg,       TCX_CAN_MCAN_SUPPORT,  		TRUE  },

};
#define TCX_CAN_STOP_SEC_DEFAULT_CONST_UNSPECIFIED
#include "tcx_Can_MemMap.h"


#define TCX_CAN_START_SEC_DEFAULT_CONST_UNSPECIFIED
#include "tcx_Can_MemMap.h"


/* Node configuration table */
static CONST (Can_NodeConfigType_tst, CAN_CONST) Can_NodeTable_acst_0[]=
{
	/*HwNodeId_u8,  DefaultBdrateIdx_u8
	 *
	 * acst_0[index], index means the logic Node like DCDC_CAN,COMM_CAN
	 * HwNodeId_u8 means the real hardware node
	 * DefaultBdrateIdx_u8, means use tcx_Can_BaudRateConfig_acst_0[DefaultBdrateIdx_u8] to configuration the node baudrate
	 * */
	
	 { 1,             0},
	 { 0,             1},
	 { 2,             2},
	 { 3,             3}
};




/*Multiple BaudRate Configuration Table  */
static CONST (tcx_Can_BaudRateConfigType_tst, CAN_CONST) tcx_Can_BaudRateConfig_acst_0[CAN_NUMBAUDRATE_CONFIG_0]=
{
	/* BaudRate(bps) NodeId_u8  HwNodeId_u8  PropSeg  PSEG1  PSEG2  SJW  BRP  */

	    {	500000      ,     0  ,     1  ,     3 ,     4  ,    2  ,   1 ,   10  },
	    {	500000      ,     1  ,     0  ,     3 ,     4  ,    2  ,   1 ,   10  },
	    {	500000      ,     2  ,     2  ,     3 ,     4  ,    2  ,   1 ,   10  },
        {	500000      ,     3  ,     3  ,     3 ,     4  ,    2  ,   1 ,   10  }
};


#define TCX_CAN_STOP_SEC_DEFAULT_CONST_UNSPECIFIED
#include "tcx_Can_MemMap.h"

#define TCX_CAN_START_SEC_DEFAULT_CODE
#include "tcx_Can_MemMap.h"
/* Port Initialization */
void tcx_Can_InitPort(uint8 Config_Number_u8)
{
	/* MISRA RULE 11.3 VIOLATION: Warning is "Not Critical". The pointer cast is required here since
Controller Base address has to be typecasted to Node/Controller
specific register structure type */
	if(Config_Number_u8 == 0)
	{
		((tcx_Can_Reg_Node_tst*)(tcx_Can_NodeBA[0]))->NPCR = 0x2;
		((tcx_Can_Reg_Node_tst*)(tcx_Can_NodeBA[1]))->NPCR = 0x1;
		((tcx_Can_Reg_Node_tst*)(tcx_Can_NodeBA[2]))->NPCR = 0x0;
		((tcx_Can_Reg_Node_tst*)(tcx_Can_NodeBA[3]))->NPCR = 0x1;
	
	}
}
#define TCX_CAN_STOP_SEC_DEFAULT_CODE
#include "tcx_Can_MemMap.h"

#define TCX_CAN_START_SEC_DEFAULT_CONST_UNSPECIFIED
#include "tcx_Can_MemMap.h"

/* Configuration parameters table */
static CONST (tcx_Can_PB_Parameters_tst, CAN_CONST) tcx_Can_PB_Configuration_cst_0=
{
/* Number_TxHandles,  Number_RxHandles,  Number_TxPollHandles,  Number_RxPollHandles,  Number_TxHandles_MCAN,  Number_TxHandles_MCANR,  Number_Baudrate_Config,  Number_Nodes,  Number_Configuration */

	putNumTxHandle,                 putNumRxHandle,                 putNumTxPollHandle,                     putNumRxPollHandle,                    putNumMCANTxhandle,                 0,                 4,                    4,                    0
};


#define TCX_CAN_STOP_SEC_DEFAULT_CONST_UNSPECIFIED
#include "tcx_Can_MemMap.h"

#define CAN_START_SEC_DEFAULT_CONST_UNSPECIFIED
#include "Can_MemMap.h"
/* Can Controller Configuration */
const Can_ControllerBaudrateConfigType Can_Controller_acst[] =
{
{
	Can_NodeTable_acst_0,
	Can_HrdHndlTable_acst_0
}      
};
#define CAN_STOP_SEC_DEFAULT_CONST_UNSPECIFIED
#include "Can_MemMap.h"


#define CAN_START_SEC_DEFAULT_CONST_UNSPECIFIED
#include "Can_MemMap.h"
/* Can Driver Configuration */
const Can_ConfigType Can_DriverConfiguration_acst[] =
{
	{
	NULL_PTR,
	NULL_PTR,
	&Can_Controller_acst[0],
	tcx_Can_BaudRateConfig_acst_0,
	&tcx_Can_PB_Configuration_cst_0
	}
};
#define CAN_STOP_SEC_DEFAULT_CONST_UNSPECIFIED
#include "Can_MemMap.h"









