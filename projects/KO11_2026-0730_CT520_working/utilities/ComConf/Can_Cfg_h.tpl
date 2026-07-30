

#ifndef  CAN_CFG_H
#define  CAN_CFG_H

/**************************************************************************/
/*                            Include Section                             */
/**************************************************************************/

/*
**************************************************************************
* Defines
**************************************************************************
*/
#define CAN_TC27X_DEV3C					1
/* Select the controller */
#define	CAN_CPUTYPE		CAN_TC27X_DEV3C

/* Type of Can_HwHandleType, uint8 / uint16 */
#define CAN_HW_HANDLE_TYPE 			 uint8


/* Size of CanId */
typedef uint16 Can_IdType;


/* Value for Polling */
#define CAN_AR_POLLING					0UL
/* Value for Interrupt */
#define CAN_AR_INTERRUPT				1UL
/* Value for WakeUp OFF */
#define WAKEUP_OFF						2UL
/* CAN Standard Identifier(11 bits) */
#define CAN_STD							0UL
/* CAN Extended Identifier(29 bits) */
#define CAN_XTD							1UL

/* CC Specific: Enable the development error detection and notification mechanism always for DNCSIM */
/* Enable/Disable the development error detection and notification mechanism */
#ifndef CAN_DEV_ERROR_DETECT
#define CAN_DEV_ERROR_DETECT			STD_OFF
#endif

/* Enable/Disable of Callout functions */
#define CAN_TXCALLOUT_ENABLE 			STD_OFF
#define CAN_RXCALLOUT_ENABLE 			STD_OFF

/* Enable/Disable the use of Extended CAN identifiers */
#define CAN_EXTENDED_ID					STD_OFF

/* Enable/Disable Version Info Api */
#define CAN_VERSION_INFO_API			STD_OFF

/* Enable/Disable Can_InitController() function */
#define CAN_USE_INIT_CONTROLLER			STD_OFF

/* define Can_EnableControllerInterrupts() and Can_DisableControllerInterrupts() functions */
#define CAN_USE_CTRL_INTERRUPTS			STD_ON

/* This parameter defines whether Can Lite configuration is required(TRUE) or not(FALSE). */
/* By setting this to true, a non AUTOSAR CAN driver is enabled. This new driver has reduced code size. */
#define CANDRV_LITE_CONFIGURATION		STD_OFF

/* Enable/Disable the Diagnostics Event Manager error notification mechanism */
#define CAN_DPRAM_CHECK					STD_OFF

/*Maximum nodes present among different configurations*/
#define CAN_MAX_NODES                   4

/*Maximum handles among different configurations*/
#define CAN_MAX_HANDLES                 putMaxHandles

/*Maximum Tx Handles among different configurations*/
#define CAN_MAX_TX_HANDLES              putTxMaxHandles

/*Maximum Rx Handles among different configurations*/
#define CAN_MAX_RX_HANDLES              putRxMaxHandles



/* Number of handles configured on a particular node */
#define CAN_NUM_HANDLES_NODE0_0			3
#define CAN_NUM_HANDLES_NODE1_0		    putNumHandleinNode1
#define CAN_NUM_HANDLES_NODE2_0			2
#define CAN_NUM_HANDLES_NODE3_0			0


/* Select POLLING/INTERRUPT mode for Transmit monitoring */
#define CAN_TX_PROCESSING				CAN_AR_POLLING

/* Select POLLING/INTERRUPT mode for Reception monitoring */
#define CAN_RX_PROCESSING				CAN_AR_POLLING

/* Set POLLING mode for BusOff monitoring */
#define CAN_BUSOFF_PROCESSING			CAN_AR_POLLING

/* Enable/Disable Error Passive monitoring */
#define CAN_ERRORPASSIVE_SUPPORT		STD_OFF


#define CAN_NUM_HANDLES_0               putMaxHandles

#define CAN_NUM_NODES_0                 4

#define CAN_NUMBAUDRATE_CONFIG_0        4

/*
***************************************************************************************************
* Type definitions
***************************************************************************************************
*/


/* Generate FDR register value */
#define CAN_FDR_STEP							0x3FE

/* Generate Divider mode for FDR register */
#define CAN_FDR_DM								0x1

/* Select the Can clock
0x0 No clock supplied
0x1 fCLC
0x2 Oscillator Clock
0x4 E-Ray PLL clock
*/
#define CAN_CLK									        0x1

#define TCX_CAN_MCAN_SUPPORT                            1

#define TCX_CAN_MCANR_SUPPORT                           2

#define TCX_CAN_MCAN                            TCX_CAN_MCAN_SUPPORT


/* Enable/Disable BaudRate change during run time*/
#define CAN_CHANGE_BAUDRATE_API         STD_OFF


/* Wakeup monitoring is not supported */
#define CAN_WAKEUP_PROCESSING            WAKEUP_OFF

/* Can Calibration support*/

#define CAN_CALIBRATION			STD_OFF



#define CanConfigSet  Can_DriverConfiguration_acst[0]







/* Can Hardware handles */
typedef enum
{
putCanHwObjTxPolling,
	CanHwObj_ComUds_Tx,
	CanHwObj_ComObd_Tx,
	XcpTx_Var,
	
 putCanHwObjRxPolling
	CanHwObj_ComUds_Rx_func1,
	CanHwObj_ComUdsObd_Rx,
	CanHwObj_ComObd_Rx,
	XcpRx_Cmd,
	TcProg

}Can_HardwareHndleType_ten_0;


/* Can Nodes */
// The virtual can node concept is deleted as it brings the distinguish when code reviewing and revision
// New rules here to map the hw node and driver node.
//1) COMM_CAN_0 CALI_CAN_0 RES1_CAN_0 RES2_CAN_0 are used as handle as the both hw node id and driver node id. 
// The enumeration value shall be equal to the HW can node 
//2) Can_NodeTable_acst_0 in Can_PBCfg.c shall keep one-on-one mapping
//3) tcx_Can_BaudRateConfig_acst_0 in Can_PBCfg.c, NodeId_u8 and HwNodeId_u8 shall keep one-on-one mapping
typedef enum
{
	CALI_CAN_0=0,
	COMM_CAN_0=1,
	RES1_CAN_0=2

}Can_NodeType_ten_0;


#endif



