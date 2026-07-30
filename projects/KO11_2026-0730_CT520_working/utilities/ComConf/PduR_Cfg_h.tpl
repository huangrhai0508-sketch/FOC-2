
/*                                                                                                                     
<Key></Key>
*/                                                                                                                     
 
 
#ifndef _PDUR_CFG_H
#define _PDUR_CFG_H

#include "ComStack_Types.h"





#if !defined(PDUR_CANTP_RX_BASE)
#define PDUR_CANTP_RX_BASE    (PDUR_BASE_LOTP(0,LoTpRxToUp))
#endif /* PDUR_CANTP_RX_BASE */
#if !defined(PDUR_CANTP_TX_BASE)
#define PDUR_CANTP_TX_BASE    (PDUR_BASE_LOTP(0,LoTpTxToUp))
#endif /* PDUR_CANTP_TX_BASE */
#if !defined(PDUR_NR_VALID_CANTPTPRXTOUP_IDS)
#define PDUR_NR_VALID_CANTPTPRXTOUP_IDS    (PDUR_BASE_LOTP(0,LoTpRxToUp_NrEntries))
#endif /* PDUR_NR_VALID_CANTPTPRXTOUP_IDS */
#if !defined(PDUR_NR_VALID_CANTPTPTXTOUP_IDS)
#define PDUR_NR_VALID_CANTPTPTXTOUP_IDS    (PDUR_BASE_LOTP(0,LoTpTxToUp_NrEntries))
#endif /* PDUR_NR_VALID_CANTPTPTXTOUP_IDS */



#if !defined(PDUR_CANIF_RXIND_BASE)
#define PDUR_CANIF_RXIND_BASE    (PDUR_BASE_LOIFD(0,LoIfRxToUp))
#endif /* PDUR_CANIF_RXIND_BASE */
#if !defined(PDUR_CANIF_TXCONF_BASE)
#define PDUR_CANIF_TXCONF_BASE    (PDUR_BASE_LOIFD(0,LoIfTxToUp))
#endif /* PDUR_CANIF_TXCONF_BASE */
#if !defined(PDUR_NR_VALID_CANIFIFRXTOUP_IDS)
#define PDUR_NR_VALID_CANIFIFRXTOUP_IDS    (PDUR_BASE_LOIFD(0,LoIfRxToUp_NrEntries))
#endif /* PDUR_NR_VALID_CANIFIFRXTOUP_IDS */
#if !defined(PDUR_NR_VALID_CANIFIFTXTOUP_IDS)
#define PDUR_NR_VALID_CANIFIFTXTOUP_IDS    (PDUR_BASE_LOIFD(0,LoIfTxToUp_NrEntries))
#endif /* PDUR_NR_VALID_CANIFIFTXTOUP_IDS */



#if !defined(PDUR_CANNM_RXIND_BASE)
#define PDUR_CANNM_RXIND_BASE    (PDUR_BASE_LOIFTT(0,LoIfRxToUp))
#endif /* PDUR_CANNM_RXIND_BASE */
#if !defined(PDUR_CANNM_TXCONF_BASE)
#define PDUR_CANNM_TXCONF_BASE    (PDUR_BASE_LOIFTT(0,LoIfTxToUp))
#endif /* PDUR_CANNM_TXCONF_BASE */
#if !defined(PDUR_NR_VALID_CANNMIFRXTOUP_IDS)
#define PDUR_NR_VALID_CANNMIFRXTOUP_IDS    (PDUR_BASE_LOIFTT(0,LoIfRxToUp_NrEntries))
#endif /* PDUR_NR_VALID_CANNMIFRXTOUP_IDS */
#if !defined(PDUR_NR_VALID_CANNMIFTXTOUP_IDS)
#define PDUR_NR_VALID_CANNMIFTXTOUP_IDS    (PDUR_BASE_LOIFTT(0,LoIfTxToUp_NrEntries))
#endif /* PDUR_NR_VALID_CANNMIFTXTOUP_IDS */

#if !defined(PDUR_IPDUM_RXIND_BASE)
#define PDUR_IPDUM_RXIND_BASE    (PDUR_BASE_LOIFTT(1,LoIfRxToUp))
#endif /* PDUR_IPDUM_RXIND_BASE */
#if !defined(PDUR_IPDUM_TXCONF_BASE)
#define PDUR_IPDUM_TXCONF_BASE    (PDUR_BASE_LOIFTT(1,LoIfTxToUp))
#endif /* PDUR_IPDUM_TXCONF_BASE */
#if !defined(PDUR_NR_VALID_IPDUMIFRXTOUP_IDS)
#define PDUR_NR_VALID_IPDUMIFRXTOUP_IDS    (PDUR_BASE_LOIFTT(1,LoIfRxToUp_NrEntries))
#endif /* PDUR_NR_VALID_IPDUMIFRXTOUP_IDS */
#if !defined(PDUR_NR_VALID_IPDUMIFTXTOUP_IDS)
#define PDUR_NR_VALID_IPDUMIFTXTOUP_IDS    (PDUR_BASE_LOIFTT(1,LoIfTxToUp_NrEntries))
#endif /* PDUR_NR_VALID_IPDUMIFTXTOUP_IDS */

#if !defined(PDUR_LINIF_RXIND_BASE)
#define PDUR_LINIF_RXIND_BASE    (PDUR_BASE_LOIFTT(2,LoIfRxToUp))
#endif /* PDUR_LINIF_RXIND_BASE */
#if !defined(PDUR_LINIF_TXCONF_BASE)
#define PDUR_LINIF_TXCONF_BASE    (PDUR_BASE_LOIFTT(2,LoIfTxToUp))
#endif /* PDUR_LINIF_TXCONF_BASE */
#if !defined(PDUR_NR_VALID_LINIFIFRXTOUP_IDS)
#define PDUR_NR_VALID_LINIFIFRXTOUP_IDS    (PDUR_BASE_LOIFTT(2,LoIfRxToUp_NrEntries))
#endif /* PDUR_NR_VALID_LINIFIFRXTOUP_IDS */
#if !defined(PDUR_NR_VALID_LINIFIFTXTOUP_IDS)
#define PDUR_NR_VALID_LINIFIFTXTOUP_IDS    (PDUR_BASE_LOIFTT(2,LoIfTxToUp_NrEntries))
#endif /* PDUR_NR_VALID_LINIFIFTXTOUP_IDS */

#if !defined(PDUR_DCM_TX_BASE)
#define PDUR_DCM_TX_BASE    (PDUR_BASE_UPTP(0,UpTpToLo))
#endif /* PDUR_DCM_TX_BASE */

#if !defined(PDUR_DCM_MC_TX_BASE)
#define PDUR_DCM_MC_TX_BASE    (PDUR_BASE_UPTP(0,UpTpToLoMc))
#endif /* PDUR_DCM_MC_TX_BASE */

#if !defined(PDUR_NR_VALID_DCM_IDS)
#define PDUR_NR_VALID_DCM_IDS    (PDUR_BASE_UPTP(0,UpTpToLo_NrEntries))
#endif /* PDUR_NR_VALID_DCM_IDS */

#if !defined(PDUR_MODE_DEPENDENT_ROUTING)
	#define PDUR_MODE_DEPENDENT_ROUTING (0)
#endif /* PDUR_MODE_DEPENDENT_ROUTING */

#if !defined(PDUR_CANTP_CHANGE_PARAMETER_SUPPORT)
	#define PDUR_CANTP_CHANGE_PARAMETER_SUPPORT (0)
#endif /* PDUR_CANTP_CHANGE_PARAMETER_SUPPORT */

#if !defined(PDUR_FRTP_CHANGE_PARAMETER_SUPPORT)
	#define PDUR_FRTP_CHANGE_PARAMETER_SUPPORT (0)
#endif /* PDUR_FRTP_CHANGE_PARAMETER_SUPPORT */

#if ((PDUR_CANTP_CHANGE_PARAMETER_SUPPORT == 1) || (PDUR_FRTP_CHANGE_PARAMETER_SUPPORT == 1))
	#define PDUR_CHANGE_PARAMETER_SUPPORT	(1)
/* ------------------------------------------------------------------- */
/*Change Parameter Support*/
#define PDUR_NONE   0
#define PDUR_CANTP  1
#define PDUR_FRTP   2

/* ------------------------------------------------------------------- */
#else
	#define PDUR_CHANGE_PARAMETER_SUPPORT	(0)
#endif

#define PduRConf_PduRSrcPdu_Pdu_ComUds_Rx_CanTp2Pdur_func1_Src	0
#define PduRConf_PduRDestPdu_Pdu_ComUds_Rx_CanTp2Pdur_func1_Dest	0

#define PduRConf_PduRSrcPdu_Pdu_ComUds_Rx_CanTp2PduR_Src	1
#define PduRConf_PduRDestPdu_Pdu_ComUds_Rx_PduR2Dcm_Dest	0

#define PduRConf_PduRSrcPdu_Pdu_ComObd_Rx_CanTp2PduR_Src	2
#define PduRConf_PduRDestPdu_Pdu_ComObd_Rx_PduR2Dcm_Dest	0

#define PduRConf_PduRSrcPdu_Pdu_ComUds_Tx_Dcm2Pdur_Src	0
#define PduRConf_PduRDestPdu_Pdu_ComUds_tx_Pdur2CanTp_Dest	0

#define PduRConf_PduRSrcPdu_Pdu_ComObd_Tx_Dcm2Pdur_Src	1
#define PduRConf_PduRDestPdu_Pdu_ComObd_tx_Pdur2CanTp_Dest	1

put_PduR_Tx_Msg_SrcDst

put_PduR_Rx_Msg_SrcDst



#if !defined(PDUR_DEM_INIT_FAILED)
#define PDUR_DEM_INIT_FAILED        (0) /* STD_OFF */
#endif /* PDUR_DEM_INIT_FAILED */



#if !defined(PDUR_DEM_PDU_INSTANCE_LOST)
#define PDUR_DEM_PDU_INSTANCE_LOST  (0) /* STD_OFF */
#endif /* PDUR_DEM_PDU_INSTANCE_LOST */







/*
	These #defines are generated by the code generator tool. Respective module's function names are generated
	only if it is present in the PduR_PbCfg.c file in any one of the entries.
*/

/*
	These #defines correspond to the entries in the PduR_loTransmitTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_CanIf_Transmit)
#define PduR_RF_CanIf_Transmit    (0)
#endif /* PduR_RF_CanIf_Transmit */


#if !defined(PduR_RF_CanNm_Transmit)
#define PduR_RF_CanNm_Transmit    (1)
#endif /* PduR_RF_CanNm_Transmit */


#if !defined(PduR_RF_CanTp_Transmit)
#define PduR_RF_CanTp_Transmit    (2)
#endif /* PduR_RF_CanTp_Transmit */


#if !defined(PduR_RF_LinIf_Transmit)
#define PduR_RF_LinIf_Transmit    (3)
#endif /* PduR_RF_LinIf_Transmit */

#define MAX_NO_OF_LO_TXTABLE_ENTRIES 1

/*
	These #defines correspond to the entries in the PduR_loCancelTransmitTable in PduR_Cfg.c.
*/

#if !defined(PDUR_IH_CancelTransmitRequest)
#define PDUR_IH_CancelTransmitRequest    (0)
#endif /* PDUR_IH_CancelTransmitRequest */


#if !defined(PduR_RF_CanTp_CancelTransmit)
#define PduR_RF_CanTp_CancelTransmit    (1)
#endif /* PduR_RF_CanTp_CancelTransmit */

#define MAX_NO_OF_LO_CANCEL_TXTABLE_ENTRIES 1

/*
	These #defines correspond to the entries in the PduR_upIfRxIndicationTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Com_RxIndication)
#define PduR_RF_Com_RxIndication    (0)
#endif /* PduR_RF_Com_RxIndication */

#define MAX_NO_OF_UPIF_RXINDICATION_TABLE_ENTRIES 0

/*
	These #defines correspond to the entries in the PduR_upIfTxConfirmationTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Com_TxConfirmation)
#define PduR_RF_Com_TxConfirmation    (0)
#endif /* PduR_RF_Com_TxConfirmation */

#define MAX_NO_OF_UPIF_TXCONFIRMATION_TABLE_ENTRIES 0

/*
	These #defines correspond to the entries in the PduR_upIfTriggerTxTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Com_TriggerTransmit)
#define PduR_RF_Com_TriggerTransmit    (0)
#endif /* PduR_RF_Com_TriggerTransmit */

#define MAX_NO_OF_UPIF_TRIGGERTRANSMIT_TABLE_ENTRIES 0

/*
	These #defines correspond to the entries in the PduR_upTpCopyRxDataTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Dcm_CopyRxData)
#define PduR_RF_Dcm_CopyRxData    (0)
#endif /* PduR_RF_Dcm_CopyRxData */

#define MAX_NO_OF_UPTP_COPYRXDATA_TABLE_ENTRIES 0


/*
	These #defines correspond to the entries in the PduR_upTpStartOfReceptionTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Dcm_StartOfReception)
#define PduR_RF_Dcm_StartOfReception    (0)
#endif /* PduR_RF_Dcm_StartOfReception */

#define MAX_NO_OF_UPTP_STARTOFRECEPTION_TABLE_ENTRIES 0


/*
	These #defines correspond to the entries in the PduR_upTpRxIndicationTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Dcm_RxIndication)
#define PduR_RF_Dcm_RxIndication    (0)
#endif /* PduR_RF_Dcm_RxIndication */

#define MAX_NO_OF_UPTP_RXINDICATION_TABLE_ENTRIES 0

/*
	These #defines correspond to the entries in the PduR_upTpCopyTxDataTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Dcm_CopyTxData)
#define PduR_RF_Dcm_CopyTxData    (0)
#endif /* PduR_RF_Dcm_CopyTxData */

#define MAX_NO_OF_UPTP_COPYTXDATA_TABLE_ENTRIES 0

/*
	These #defines correspond to the entries in the PduR_upTpTxConfirmationTable in PduR_Cfg.c.
*/

#if !defined(PduR_RF_Dcm_TxConfirmation)
#define PduR_RF_Dcm_TxConfirmation    (0)
#endif /* PduR_RF_Dcm_TxConfirmation */

#define MAX_NO_OF_UPTP_TXCONFIRMATION_TABLE_ENTRIES 0



#if !defined(PDUR_DEV_ERROR_DETECT)
#define PDUR_DEV_ERROR_DETECT    (0) //(1)
#endif /* PDUR_DEV_ERROR_DETECT */

#if !defined(PDUR_VERSION_INFO_API)
#define PDUR_VERSION_INFO_API    (0)
#endif /* PDUR_VERSION_INFO_API */

#if !defined(PDUR_ZERO_COST_OPERATION)
#define PDUR_ZERO_COST_OPERATION    (0)
#endif /* PDUR_ZERO_COST_OPERATION */

#if !defined(PDUR_IFGATEWAY_SUPPORT)
#define PDUR_IFGATEWAY_SUPPORT    (0)
#endif /* PDUR_IFGATEWAY_SUPPORT */

#if !defined(PDUR_TPGATEWAY_SUPPORT)
#define PDUR_TPGATEWAY_SUPPORT    (0)
#endif /* PDUR_TPGATEWAY_SUPPORT */




/*These Macros are used to indicate a unique no. assigned to each upper layer & is used in PduR_MC_SetTxConfirmationFlag() function if
	there are muticast routing paths existing from UpIf to Multiple LoIf*/

#define COM_PDURBSWMODNAME (1)
#define IPDUM_PDURBSWMODNAME (2)

#define PDUR_NULL_BSWMODNAME 255
#define PDUR_NULL_PDUID 0

#if !defined(PDUR_CANIF_SUPPORT)
#define PDUR_CANIF_SUPPORT    (1)
#endif /* PDUR_CANIF_SUPPORT */

#if !defined(PDUR_CANNM_SUPPORT)
#define PDUR_CANNM_SUPPORT    (1)
#endif /* PDUR_CANNM_SUPPORT */

#if !defined(PDUR_UDPNM_SUPPORT)
#define PDUR_UDPNM_SUPPORT    (0)
#endif /* PDUR_UDPNM_SUPPORT */

#if !defined(PDUR_CANTP_SUPPORT)
#define PDUR_CANTP_SUPPORT    (1)
#endif /* PDUR_CANTP_SUPPORT */

#if !defined(PDUR_CANTP_TC_SUPPORT)
#define PDUR_CANTP_TC_SUPPORT    (0)
#endif /* PDUR_CANTP_TC_SUPPORT */

#if !defined(PDUR_FRIF_SUPPORT)
#define PDUR_FRIF_SUPPORT    (0)
#endif /* PDUR_FRIF_SUPPORT */

#if !defined(PDUR_FRNM_SUPPORT)
#define PDUR_FRNM_SUPPORT    (0)
#endif /* PDUR_FRNM_SUPPORT */

#if !defined(PDUR_FRTP_SUPPORT)
#define PDUR_FRTP_SUPPORT    (0)
#endif /* PDUR_FRTP_SUPPORT */

#if !defined(PDUR_LINIF_SUPPORT)
#define PDUR_LINIF_SUPPORT    (1)
#endif /* PDUR_LINIF_SUPPORT */

#if !defined(PDUR_LINTP_SUPPORT)
#define PDUR_LINTP_SUPPORT    (0)
#endif /* PDUR_LINTP_SUPPORT */

#if !defined(PDUR_SOADIF_SUPPORT)
#define PDUR_SOADIF_SUPPORT    (0)
#endif /* PDUR_SOADIF_SUPPORT */

#if !defined(PDUR_J1939TP_SUPPORT)
#define PDUR_J1939TP_SUPPORT    (0)
#endif /* PDUR_J1939TP_SUPPORT */

#if !defined(PDUR_SOADTP_SUPPORT)
#define PDUR_SOADTP_SUPPORT    (0)
#endif /* PDUR_SOADTP_SUPPORT */

#if !defined(PDUR_DOIP_SUPPORT)
#define PDUR_DOIP_SUPPORT    (0)
#endif /* PDUR_DOIP_SUPPORT */

#if !defined(PDUR_COM_SUPPORT)
#define PDUR_COM_SUPPORT    (1)
#endif /* PDUR_COM_SUPPORT */

#if !defined(PDUR_IPDUM_SUPPORT)
#define PDUR_IPDUM_SUPPORT    (1)
#endif /* PDUR_IPDUM_SUPPORT */

#if !defined(PDUR_DCM_SUPPORT)
#define PDUR_DCM_SUPPORT    (1)
#endif /* PDUR_DCM_SUPPORT */

#if !defined(PDUR_DLT_SUPPORT)
#define PDUR_DLT_SUPPORT    (0)
#endif /* PDUR_DLT_SUPPORT */


/*The size of the PduR_mcGwToLo Table in PduR_PBcfg.c*/
/*This #define will be used in PduR_MulticastUpToLo.c file for entry condition*/


#define MAX_NO_OF_MC_GWTOLO_ENTRIES 0  /* function PduR_MF_UpToLo needs this macro hence generating with default value */

/*Macro used for getting the size of Cdd config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_CddCfg     0

/*Macro used for getting the size of LoTp Rx config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_LoTpRxCfg  1

/*Macro used for getting the size of LoTp Tx config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_LoTpTxCfg  1

/*Macro used for getting the size of LoIf Rx with Direct data provision config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_LoIfRxDCfg  1

/*Macro used for getting the size of LoIf Tx with Direct data provision config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_LoIfTxDCfg  1

/*Macro used for getting the size of LoIf Rx with Trigger Transmit data provision config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_LoIfRxTTCfg  1

/*Macro used for getting the size of LoIf Tx with Trigger Transmit data provision config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_LoIfTxTTCfg  0

/*Macro used for getting the size of LoIf Tx with Trigger Transmit data provision config, this will be use in the reference configuration unit testing only*/
#define TableSize_PduR_UpTpCfg  	1


#if !defined(PDUR_MIN_ROUTING_PREBUILD_CANIF)
#define PDUR_MIN_ROUTING_PREBUILD_CANIF    (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_CANIF */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_CANTP)
#define PDUR_MIN_ROUTING_PREBUILD_CANTP    (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_CANTP */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_FRIF)
#define PDUR_MIN_ROUTING_PREBUILD_FRIF     (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_FRIF */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_FRTP)
#define PDUR_MIN_ROUTING_PREBUILD_FRTP     (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_FRTP */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_LINIF)
#define PDUR_MIN_ROUTING_PREBUILD_LINIF    (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_LINIF */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_LINTP)
#define PDUR_MIN_ROUTING_PREBUILD_LINTP    (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_LINTP */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_COM)
#define PDUR_MIN_ROUTING_PREBUILD_COM      (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_COM */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_DCM)
#define PDUR_MIN_ROUTING_PREBUILD_DCM      (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_DCM */

#if !defined(PDUR_MIN_ROUTING_PREBUILD_DLT)
#define PDUR_MIN_ROUTING_PREBUILD_DLT      (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_DLT */

/* These Modules are not supported for Minimum Routing & hence defined as Zero */
#if !defined(PDUR_MIN_ROUTING_PREBUILD_CANNM)
#define PDUR_MIN_ROUTING_PREBUILD_CANNM	 (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_CANNM */
#if !defined(PDUR_MIN_ROUTING_PREBUILD_IPDUM)
#define PDUR_MIN_ROUTING_PREBUILD_IPDUM	 (0)
#endif /* PDUR_MIN_ROUTING_PREBUILD_IPDUM */

/* These Modules are not supported for TC SUPPORT */



#if !defined(PDUR_MIN_ROUTING_LINKTIME_CANIF)
#define PDUR_MIN_ROUTING_LINKTIME_CANIF     (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_CANIF */

#if !defined(PDUR_MIN_ROUTING_LINKTIME_CANTP)
#define PDUR_MIN_ROUTING_LINKTIME_CANTP     (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_CANTP */

#if !defined(PDUR_MIN_ROUTING_LINKTIME_FRIF)
#define PDUR_MIN_ROUTING_LINKTIME_FRIF      (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_FRIF */

#if !defined(PDUR_MIN_ROUTING_LINKTIME_FRTP)
#define PDUR_MIN_ROUTING_LINKTIME_FRTP      (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_FRTP */

#if !defined(PDUR_MIN_ROUTING_LINKTIME_LINIF)
#define PDUR_MIN_ROUTING_LINKTIME_LINIF     (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_LINIF */

#if !defined(PDUR_MIN_ROUTING_LINKTIME_LINTP)
#define PDUR_MIN_ROUTING_LINKTIME_LINTP     (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_LINTP */

#if !defined(PDUR_MIN_ROUTING_LINKTIME_COM)
#define PDUR_MIN_ROUTING_LINKTIME_COM       (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_COM */

#if !defined(PDUR_MIN_ROUTING_LINKTIME_DCM)
#define PDUR_MIN_ROUTING_LINKTIME_DCM       (0)
#endif /* PDUR_MIN_ROUTING_LINKTIME_DCM */





#if !defined(PDUR_DISABLE_MULTICAST_SUPPORT)
#define PDUR_DISABLE_MULTICAST_SUPPORT    (1) /* used internally to disable */
#endif /* PDUR_DISABLE_MULTICAST_SUPPORT */


#if !defined(PDUR_MULTICAST_TO_IF_SUPPORT)
#define PDUR_MULTICAST_TO_IF_SUPPORT    (0) /* Disabled as there are no Multicast routes to IF Modules */
#endif /* PDUR_MULTICAST_TO_IF_SUPPORT */


#if !defined(PDUR_MULTICAST_TO_TP_SUPPORT)
#define PDUR_MULTICAST_TO_TP_SUPPORT    (0) /* Disabled as there are no Multicast routes to TP Modules */
#endif /* PDUR_MULTICAST_TO_TP_SUPPORT */


#if !defined(PDUR_MULTICAST_FROM_TP_SUPPORT)
#define PDUR_MULTICAST_FROM_TP_SUPPORT    (0) /* Disabled as there are no Multicast routes from TP Modules */
#endif /* PDUR_MULTICAST_FROM_TP_SUPPORT */

#if !defined(PDUR_PBCONFIG_TYPE)
#define PDUR_PBCONFIG_TYPE (1)
#endif


#endif /* _PDUR_CFG_H */


