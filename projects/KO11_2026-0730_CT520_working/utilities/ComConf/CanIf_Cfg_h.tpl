

/*                                                                                                                     
<Key></Key>
*/                                                                                                                     





#ifndef  _CANIF_CFG_H
#define  _CANIF_CFG_H
/**************************************************************************/
/*                            Include Section                             */
/**************************************************************************/

	


/*
**************************************************************************
* Defines
**************************************************************************
*/

/**************************************************************************/
/* Description :  Enables or disables the development error detection &   */
/*                notification mechanism                                  */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_DEV_ERROR_DETECT 			        STD_OFF //STD_ON
/**************************************************************************/
/* Description :  Enables or disables BaudRateChange in the CanDriver     */
/*               							                              */
/* Range       :  STD_ON/STD_OFF									      */
/**************************************************************************/
#define CANIF_PUBLIC_CHANGE_BAUDRATE_SUPPORT             STD_OFF

/**************************************************************************/
/* Description :  Enables or disables the API CanIf_CancelTransmit()     */
/*               							                              */
/* Range       :  STD_ON/STD_OFF									      */
/**************************************************************************/
#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT		STD_OFF



/***************************************************************************/
/* Description :  Enables/disables API for reading received L-PDU data    */
/* Range       : STD_OFFD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_READRXPDU_DATA_API 				STD_OFF //STD_ON

/**************************************************************************/
/* Description :  Enables/disables API for reading the notification status*/
/*                of transmit and receive L-PDU                           */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_READRXPDU_NOTIFY_STATUS_API 	    STD_ON

/**************************************************************************/
/* Description :  Enables/disables API for reading the notification status*/
/*                of transmit and receive L-PDU                           */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_READTXPDU_NOTIFY_STATUS_API 		STD_ON
/**************************************************************************/

/* Description :  Configure Error Passive support                         */
/* Range STD_OFF   :  STD_ON/STD_OFF                                                  */
/**************************************************************************/
#define CANIF_ERROR_PASSIVE_SUPPORT             STD_OFF


/**************************************************************************/
/* Description :  Configure Wakeup support                                */
/* Range       :  STD_ON/STD_OFF                                                  */
/**************************************************************************/
#define CANIF_WAKEUP_SUPPORT         				STD_OFF

/**************************************************************************/
/* Description :  Configure Controller Wakeup support                                */
/* Range       :  STD_ON/STD_OFF                                                  */
/**************************************************************************/
#define CANIF_CTRL_WAKEUP_SUPPORT                   STD_OFF

/**************************************************************************/
/* Description :  Configure  Transceiver Wakeup support                                */
/* Range       :  STD_ON/STD_OFF                                                  */
/**************************************************************************/
#define CANIF_TRCV_WAKEUP_SUPPORT                 	STD_OFF

/**************************************************************************/
/* Description :  Configure Wakeup support                                */
/* Range       :  STD_ON/STD_OFF                                                  */
/**************************************************************************/
#define CANIF_TRCV_DRV_CFG                     		STD_OFF

/**************************************************************************/
/* Description :  Configure Wakeup Validation                                 */
/* Range       :  STD_ON/STD_OFF                                                  */
/**************************************************************************/
#define CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_API   	STD_OFF

/**************************************************************************/
/* Description :  Configure Wakeup Validation                                 */
/* Range       :  0....Num of transceivers                                                  */
/**************************************************************************/
#define CANIF_NUM_TRANSCEIVERS						0


/**************************************************************************/
/* Description :  Enables/disables API for reading the version information*/
/*           .     about the CAN interface                                */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_VERSION_INFO_API 					STD_OFF

/**************************************************************************/

/* Description :  Enables/disables usage of dynamic IDs                   */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_DYNAMIC_ID 					    STD_OFF

/**************************************************************************/
/* Description :  Enables/disables API for reconfiguration of the CAN     */
/*                Identifier for each transmit L-PDU                      */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_SETDYNAMICTXID_API 				STD_OFF

/**************************************************************************/
/* Description :  Enables/disables use of transmit buffers                */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_TRANSMIT_BUFFER 					STD_OFF

/**************************************************************************/

/* Description :  Enables/disables use of receive buffers                 */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_RECEIVE_BUFFER  					STD_OFF //STD_ON


/**************************************************************************/
/* Description :  Enables/disables Cancel Tx Confirmation feature in CanIf        */
/* Range       :  STD_ON/STD_OFF											      */
/**************************************************************************/
#define CANIF_TRANSMIT_CANCELLATION				STD_OFF



/*Enable / Disable reporting Invalid DLC error*/
#define CANIF_DEM_INVALID_DLC_ERROR				STD_OFF //STD_ON

#define CANIF_DEM_INVALID_DLC_ERROR_VALUE		DemConf_DemEventParameter_CANIF_E_INVALID_DLC_ERROR



/*Enable / Disable reporting 'Controller in STOPPED' error*/
#define CANIF_DEM_CTRL_STOPPED_ERROR			STD_OFF //STD_ON

#define CANIF_DEM_CTRL_STOPPED_ERROR_VALUE		DemConf_DemEventParameter_CANIF_E_CTRL_STOPPED_ERROR_VALUE


/*Enable / Disable reporting 'Controller NOT in SLEEP' error*/
#define CANIF_DEM_CTRL_NOT_SLEEP_ERROR			STD_OFF //STD_ON

#define CANIF_DEM_CTRL_NOT_SLEEP_ERROR_VALUE	DemConf_DemEventParameter_CANIF_E_CTRL_NOT_SLEEP_ERROR_VALUE




/**************************************************************************/
/* Description :  Selects whether the DLC check is supported              */
/* Range       :  STD_ON/STD_STD_OFF		                                          */
/**************************************************************************/
#define CANIF_DLC_CHECK 					    STD_OFF //STD_ON




/**************************************************************************/
/* Description :  Total Number of Dynamic CanTxPduIds to be handled       */
/* Range       :  1..Max Number of defined CanTxPduIds			          */
/**************************************************************************/
#define CANIF_NUM_DYNAMIC_CANTXPDUIDS_0 			0

/**************************************************************************/
/* Description :  Total Number of CanTxPduIds to be handled               */
/* Range       :  1..Max Number of defined CanTxPduIds			          */
/**************************************************************************/

#define CANIF_NUM_CANRXPDUIDS_0 					putNumRxPdus

/**************************************************************************/
/* Description :  Total Number of CanTxPduIds to be handled               */
/* Range       :  1..Max Number of defined CanTxPduIds			          */
/**************************************************************************/

#define CANIF_NUM_CANTXPDUIDS_0 					putNumTxPdus


/**************************************************************************/
/* Description :  Define Number of transmit buffers.                      */
/*                The L-PDU buffers shall store DLC and max of 8bytes     */
/*                of data.                                                */
/* Range       :  0..Max Number of Tx buffers       		              */
/**************************************************************************/
#define CANIF_NUM_TXBUFFERS_0 					0

/**************************************************************************/
/* Description :  Gives the Number of BASIC CAN HTHs.                      */
/* Range       :  0..Max Number of BASIC CAN HTHs      		              */
/**************************************************************************/
#define CANIF_NUM_BASIC_HTH_0 					0

/******************** Parameters Newly Introduced *************************/



/* Total number of Controllers present in one or more drivers */


#define CANIF_NUM_CONTROLLERS_0                   3




/* Configuration for the Tx and Rx buffer size */


#define CANIF_TXBUFFER_SIZE_0                     0



#define CANIF_RXBUFFER_SIZE_0                     0



/* Configuration for retransmission of PDU */
#define CANIF_MAX_RETRY_TIMES             	    1  											






/**************************************************************************/
/* Description :  Number of served CAN hardware units                     */
/* Range       :  1..Max Number of underlying supportted CAN HW units     */
/**************************************************************************/
#define CANIF_NUM_CAN_DRIVERS                   1

/* Configuration for use of extended CAN identifiers */
#define CANIF_EXTENDED_ID 						STD_OFF


/* Instance ID */
#define CANIF_INSTANCE_ID 					    1



/* Configure CanIf Lite */
#define CANIF_LITE_CONFIGURATION				STD_OFF




/* Configure transmission of CANTP/USER Pdus when the Tx Pdu mode is OFFLINE */
#define CANIF_USER_TP_TX_OFFLINE_MODE			STD_OFF


/* Configuration for enabling/disabling the API CanIf_GetTxConfirmationState() */
#define CANIF_PUBLIC_TXCONFIRM_SUPPORT          STD_OFF


/*PN support*/
#define CANIF_PUBLIC_PN_SUPPORT			STD_OFF



/* CanIf variant info */
#define CANIF_VARIANT_INFO				1



/*Number of config sets (CanIfInitcfgs) configured in CanIf*/
#define CANIF_TOTAL_CFG_SETS				1


/*Total number of Tx-Pdus configured in CanIf*/
#define CANIF_TOTAL_TXPDUS 					putNumTxPdus


/*Total number of Rx-Pdus configured in CanIf*/
#define CANIF_TOTAL_RXPDUS 					putNumRxPdus


/*Number of entries in CanIf_TxPduId_CustId_LUT[][]*/
#define CANIF_NUM_CUSTID_ENTRIES			putNumTxPdus


/* Configure support of filtering of CanNm transmit CanIds during reception */
#define CANIF_CANNM_TXID_FILTER                 STD_OFF



/* Enable/Disable CanNm Support */
#define CANIF_CANNM_ENABLED                     STD_OFF //STD_ON



/* Enable/Disable CanTp Support */
#define CANIF_CANTP_ENABLED                     STD_ON




/* Enable/Disable PduR Support */
#define CANIF_PDUR_ENABLED                      STD_ON




/* Enable/Disable CDD Support */
#define CANIF_CDD_RX_ENABLED					STD_OFF



/* Enable/Disable USER Support */
#define CANIF_USER_RX_ENABLED					STD_ON




/* Enable/Disable USER or CDD Support */
#define CANIF_USER_CDD_TX_ENABLED				STD_OFF



/* Enable/Disable XCP Support */
#define CANIF_XCP_ENABLED                       STD_ON


/* Enable/Disable XCP Support */
#define CANIF_J1939TP_ENABLED                       STD_OFF


/* Configure support of BASIC CAN Reception */
#define CANIF_BASIC_CAN_SUPPORT   				STD_OFF

/* Configure support of CanId List for reception */
#define CANIF_BASIC_CAN_SUPPORT_LIST			STD_OFF

/* Macro generated via scripts when multiple Ranges of CanIds are configured under a HRH */
#define CANIF_RXPDU_CANID_RANGE				    STD_OFF



/* Calibration Enabled/Disabled */

#define CANIF_CALIBRATION				STD_OFF





/* Configure the number of HRH handles */
#define CANIF_NUM_HRH_HANDLES_0                   putNumRxPdus


/* Configure total number of CanIds to be received in the list */
#define CANIF_NUM_LIST_CANID_0 				0


/* Definition of Rx Receive Handles (HRH) for CanIfInitConfiguration_0*/

#define CanIfConf_CanIfHrhCfg_CanHwOjb_ComUds_Rx_func1       putUdsHrhcfg
#define CanIfConf_CanIfHrhCfg_CanHwOjb_ComUdsObd_Rx          putUdsObdHrhcfg
#define CanIfConf_CanIfHrhCfg_CanHwOjb_ComObd_Rx             putObdHrhcfg
#define CanIfConf_CanIfHrhCfg_XcpRx_Cmd                      putXcpRxHrhcfg
#define CanIfConf_CanIfHrhCfg_TcProg                         putTcProgHrhcfg

putRegularCANRxHrhDefinition





/* Definition of TxPduIds for CanIfInitConfiguration_0*/

#define CanIfConf_CanIfTxPduCfg_CanIfTxPduCfg_ComUds_Tx        0
#define CanIfConf_CanIfTxPduCfg_CanIfTxPduCfg_ComObd_Tx        1
#define CanIfConf_CanIfTxPduCfg_XcpTx_Var                      2

putDefineofCanIfTxPdu_Name



/* Definition of RxPduIds CanIfInitConfiguration_0*/
#define CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_ComUds_Rx_func_1     0
#define CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_ComUdsObd_Rx         1
#define CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_ComObd_Rx            2
#define CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_XcpRx_Cmd            3
#define CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_TcProg               4

putCanIfRxPduIndx



/* Include the Controller name */
typedef enum
{
	CANIF_CALI_CAN = 0,
	CANIF_COMM_CAN = 1,
	CANIF_RES1_CAN = 2,
    CANIF_RES2_CAN = 3


}CanIf_ControllerName;











#endif /* _CANIF_CFG_H */

