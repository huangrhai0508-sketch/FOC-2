

#include "PduR_Com.h"
#include "PduR_LoIf.h"
#include "CanTp_Cfg.h"
#if 0
#include "PduR_IpduM.h"
#include "PduR_LoIfTT.h"


#include "PduR_LoTp.h"

#include "PduR_UpTp.h"

#include "PduR_Mc.h"
#include "PduR_Gw.h"
#endif
/* Generating PbCfg_c::PduR_PbCfg_c_Gw_TpBuf::PduR_bufferLocks */
/* Generating PbCfg_c::PduR_PbCfg_c_Gw_IfBuf::PduR_gw_buf_If */
/* Generating PbCfg_c::PduR_PbCfg_c_Gw_TpBuf::PduR_gw_Buf_TP_structure */
/* Generating PbCfg_c::PduR_PbCfg_c_UpIfToLo::upIf_To_Lo */
			

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
#if defined(PDUR_CONFIG_SINGLE_IFTX_LO)
#define PduR_comToLo	NULL_PTR
#else
static CONST(PduR_RT_UpToLo,PDUR_CONST ) PduR_comToLo[] = {
		put_PduR_Tx_Msg_Com2CanIf

};
#endif /* PDUR_CONFIG_SINGLE_IFTX_LO */

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"


			


/* Generating PbCfg_c::PduR_PbCfg_c_UpTpToLo::upTp_To_Lo */
			

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"


#if defined(PDUR_CONFIG_SINGLE_TPTX_LO)
#define PduR_DcmToLo	NULL_PTR
#else
static CONST(PduR_RT_UpToLo,PDUR_CONST ) PduR_DcmToLo[] = {
	{ CanTpConf_CanTpTxNSdu_Pdu_ComUds_Tx_Pdur2CanTp, (PduR_loTransmitFP)PduR_RF_CanTp_Transmit, (PduR_loCancelTransmitFP)PduR_RF_CanTp_CancelTransmit },	/*UdsOnCan_Tx_Dcm2PduR*/
	{ CanTpConf_CanTpTxNSdu_Pdu_ComObd_Tx_Pdur2CanTp, (PduR_loTransmitFP)PduR_RF_CanTp_Transmit, (PduR_loCancelTransmitFP)PduR_RF_CanTp_CancelTransmit }	/*ObdOnCan_Tx_Dcm2PduR*/

};
#endif /* PDUR_CONFIG_SINGLE_IFTX_LO */

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"


		
	
/* Generating PbCfg_c::PduR_PbCfg_c_LoIfRxToUp::loIfRx_To_Up */
	
		
			

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"


#if defined(PDUR_CONFIG_SINGLE_IFRX)
#define PduR_CanIfRxToUp   NULL_PTR
#else
static CONST( PduR_RT_LoIfRxToUp, PDUR_CONST ) PduR_CanIfRxToUp[] = {		
	put_PduR_Rx_Msg_CanIf2Com
 };
#endif  /* PDUR_CONFIG_SINGLE_IFRX */

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
		

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"

#if defined(PDUR_CONFIG_SINGLE_IFTX_UP )
#define PduR_CanIfTxToUp NULL_PTR
#else

static CONST(PduR_RT_LoIfTxToUp, PDUR_CONST ) PduR_CanIfTxToUp [] = { 
	put_PduR_TxConfirm_CanIf2Com
};
#endif  /* PDUR_CONFIG_SINGLE_IFTX_UP */

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
 
		
	
/* Generating PbCfg_c::PduR_PbCfg_c_LoIfTTxToUp::loIf_TTxToUp */
	
			

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"

#if defined(PDUR_CONFIG_SINGLE_IFTX_UP )
#define PduR_CanNmTxToUp NULL_PTR
#else
#define PduR_CanNmTxToUp NULL_PTR
// Mask the nm temperarily
//static CONST(PduR_RT_LoTtIfTxToUp, PDUR_CONST ) PduR_CanNmTxToUp [] = { 
//{ComConf_ComIPdu_MCUF_NM,(PduR_upIfTriggerTxFP) PduR_RF_Com_TriggerTransmit, (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation }	/* Index: 0  SrcPdu: CanNmUserData  DestPdu: UserData_PduR2CanNm*/
//};
#endif  /* PDUR_CONFIG_SINGLE_IFTX_UP */

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
 

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
 
		
	
/* Generating PbCfg_c::PduR_PbCfg_c_LoTpRxToUp::loTpRx_To_Up */
	
		
			

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"

#define DcmConf_DcmDslProtocolRx_Pdu_ComUds_Rx_Pdur2Dcm_func1 2
#define DcmConf_DcmDslProtocolRx_Pdu_ComUds_Rx_Pdur2Dcm 0
#define DcmConf_DcmDslProtocolRx_Pdu_ComObd_Rx_Pdur2Dcm 1

#if defined ( PDUR_CONFIG_SINGLE_TPRX )
#define PduR_CanTpRxToUp   NULL_PTR
#else
static CONST( PduR_RT_LoTpRxToUp, PDUR_CONST ) PduR_CanTpRxToUp[] = {
	{DcmConf_DcmDslProtocolRx_Pdu_ComUds_Rx_Pdur2Dcm_func1, (PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,(PduR_upTpRxIndicationFP) PduR_RF_Dcm_RxIndication },	/*ObdOnCan_Rx_Func_CanTp2PduR*/
	{DcmConf_DcmDslProtocolRx_Pdu_ComUds_Rx_Pdur2Dcm, (PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,(PduR_upTpRxIndicationFP) PduR_RF_Dcm_RxIndication },	/*UdsOnCan_Rx_Phys_CanTp2PduR*/
	{DcmConf_DcmDslProtocolRx_Pdu_ComObd_Rx_Pdur2Dcm, (PduR_upTpStartOfReceptionFP) PduR_RF_Dcm_StartOfReception,(PduR_upTpProvideRxBufFP) PduR_RF_Dcm_CopyRxData,(PduR_upTpRxIndicationFP) PduR_RF_Dcm_RxIndication }	/*UdsOnCan_Rx_Func_CanTp2PduR*/
};
#endif  /* PDUR_CONFIG_SINGLE_TPRX */

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"



		
	
/* Generating PbCfg_c::PduR_PbCfg_c_LoTpTxToUp::loTpTx_To_Up */
	
		

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"

#define DcmConf_DcmDslProtocolTx_Pdu_ComUds_Tx_Dcm2PduR 1
#define DcmConf_DcmDslProtocolTx_Pdu_ComObd_Tx_Dcm2PduR 0

#if defined(PDUR_CONFIG_SINGLE_TPTX_UP )
#define PduR_CanTpTxToUp NULL_PTR
#else
static CONST(PduR_RT_LoTpTxToUp, PDUR_CONST ) PduR_CanTpTxToUp [] = {  
		{ DcmConf_DcmDslProtocolTx_Pdu_ComUds_Tx_Dcm2PduR, (PduR_upTpProvideTxBufFP) PduR_RF_Dcm_CopyTxData,(PduR_upTpTxConfirmationFP) PduR_RF_Dcm_TxConfirmation },	/*Index: 0 UdsOnCan_Tx_Dcm2PduR*/
		{ DcmConf_DcmDslProtocolTx_Pdu_ComObd_Tx_Dcm2PduR, (PduR_upTpProvideTxBufFP) PduR_RF_Dcm_CopyTxData,(PduR_upTpTxConfirmationFP) PduR_RF_Dcm_TxConfirmation }	/*Index: 1 ObdOnCan_Tx_Dcm2PduR*/
};
#endif  /* PDUR_CONFIG_SINGLE_TPTX_UP */

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"


		
	
/* Generating PbCfg_c::PduR_PbCfg_c_Mc_ComToLo::mcComToLow */
/* Generating PbCfg_c::PduR_PbCfg_c_Mc_DcmToLo::mcDcmToLow */
/* Generating PbCfg_c::PduR_PbCfg_c_Mc_IpduMToLo::MC_IpduMUp_Lo */
/* Generating PbCfg_c::PduR_PbCfg_c_Mc_TpTxToUp::xpandMcTpTxToUp */
/* Generating PbCfg_c::PduR_PbCfg_c_Mc_TpTxToUp::xpandMsTpTxToUp */
/* Generating PbCfg_c::PduR_PbCfg_c_Cdd::Xpand_Cdd_body */
/* Generating PbCfg_c::PduR_PbCfg_c_Mc_GwToLo::DisplayPduR_mcGwToLo */
/* Generating PbCfg_c::PduR_PbCfg_c_GwIfTx::display_GwIfTx */
/* Generating PbCfg_c::PduR_PbCfg_c_GwIf::display_GwIf */
/* Generating PbCfg_c::PduR_PbCfg_c_GwTp::display_GwTp */
/* Generating PbCfg_c::PduR_PbCfg_c_Rpg::display_PduR_RPG*/

	/* Generating PbCfg_c::PduR_PbCfg_c_PbConfigType::PduR_BswLoCfg */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST( PduR_LoTpConfig, PDUR_CONST ) PduR_LoTpCfg[] = {
  {
  	PduR_CanTpRxToUp,		/* CanTp */
  	PduR_CanTpTxToUp,		/* CanTp */
  	3,		/* CanTp RxToUp Number Of Entries*/
  	2		/* CanTp TxToUp Number Of Entries*/
  	}
  };

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST( PduR_LoIfDConfig, PDUR_CONST ) PduR_LoIfDCfg[] = {
  {
  	PduR_CanIfRxToUp,		/* CanIf */
  	PduR_CanIfTxToUp,		/* CanIf */
  	3,		/* CanIf RxToUp NrEntries*/
  	3		/* CanIf TxToUp NrEntries*/
  	}
  };

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
static CONST( PduR_UpTpConfig, PDUR_CONST ) PduR_UpTpCfg[] = {
  {
  	PduR_DcmToLo,		/* Dcm */
	NULL_PTR,		/* mcDcmToLo */
  	2		/* Dcm */
  	}
  };

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
/* Generating PbCfg_c::PduR_PbCfg_c_Cdd::PduR_CddCfg */
/* Generating PbCfg_c::PduR_PbCfg_c_PbConfigType::pdur_PBConfigType */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"
CONST( PduR_PBConfigType, PDUR_CONST ) PduR_Config = {
#if (PDUR_DISABLE_CONFIGTYPE_MAGIC == 0)
     0x025fe8a7,         /*  magic */
#endif     
     1,                  /* PDUR_CONFIGURATION_ID */
	(P2CONST( PduR_CddConfig, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* PduR_CddCfg */
     (P2CONST( PduR_LoTpConfig, AUTOMATIC, PDUR_CONST )) PduR_LoTpCfg,           /* Pointer to lowerlayer Tp config structure */
     (P2CONST( PduR_LoIfDConfig, AUTOMATIC, PDUR_CONST )) PduR_LoIfDCfg,         /* Pointer to Direct lowerlayer If config structure */
     (P2CONST( PduR_LoIfTTConfig, AUTOMATIC, PDUR_CONST )) NULL_PTR,       /* Pointer to TT lowerlayer If config structure */
     (P2CONST( PduR_RT_UpToLo, AUTOMATIC, PDUR_CONST )) PduR_comToLo,            /* Com */
     (P2CONST( PduR_UpTpConfig, AUTOMATIC, PDUR_CONST )) PduR_UpTpCfg,           /* Pointer to Upperlayer Tp config structure */
     (P2CONST( PduR_RT_UpToLo, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* IpduMUp */
     (P2CONST( PduR_MT_UpToLo, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* mcComToLo */
     (P2CONST( PduR_MT_UpToLo, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* mcDcmToLo */
     (P2CONST( PduR_MT_UpToLo, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* mcGwToLo */
     (P2CONST( PduR_MT_UpToLo, AUTOMATIC, PDUR_CONST )) NULL_PTR,                /* mcIpduMToLo */
	 (P2CONST( PduR_MT_LoIfTxToUp, AUTOMATIC, PDUR_CONST )) NULL_PTR,            /* McIfRx */
     (P2CONST( PduR_MT_LoTpTxToUp, AUTOMATIC, PDUR_CONST )) NULL_PTR,            /* McTpTx */
     (P2VAR(   PduR_MS_LoTpTxToUp, AUTOMATIC, PDUR_VAR )) NULL_PTR,              /* PduR_msTpTxToUp*/
     (P2CONST( PduR_GT_IfTx, AUTOMATIC, PDUR_CONST )) NULL_PTR,                  /* gwIfTx */
     (P2CONST( PduR_GT_If, AUTOMATIC, PDUR_CONST )) NULL_PTR,                    /* gwIf   */
     (P2CONST( PduR_GT_Tp, AUTOMATIC, PDUR_CONST )) NULL_PTR,                    /* GwTp   */

     (PduIdType) 3,     /* Com */
     (PduIdType) 0,      /* IpdumUp */
     (PduIdType) 0       /* McTpTx */			
};

/* ------------------------------------------------------------------------ */
/* End section for constants */

#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "PduR_MemMap.h"


