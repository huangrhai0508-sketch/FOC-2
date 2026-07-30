#!/usr/bin/perl -w
#use strict;
use File::Spec;

my ($dbcfileName,$Main_node,$tplPath, $genFilePath) = @ARGV[0,1,2,3];

my $tplFilename_cancfg_h = "Can_Cfg_h.tpl";
my $tplFilename_canpbcfg_c = "Can_PBcfg_c.tpl";
my $tplFilename_canifcfg_h = "CanIf_Cfg_h.tpl";
my $tplFilename_canifpbcfg_c = "CanIf_PBcfg_c.tpl";
my $tplFilename_comcfg_h = "Com_Cfg_h.tpl";
my $tplFilename_comcfg_c = "Com_Cfg_c.tpl";
my $tplFilename_pdurcfg_h = "PduR_Cfg_h.tpl";
my $tplFilename_pdurpbcfg_c = "PduR_PBcfg_c.tpl";

my $genFilename_cancfg_h = "Can_Cfg.h";
my $genFilename_canpbcfg_c = "Can_PBcfg.c";
my $genFilename_canifcfg_h = "CanIf_Cfg.h";
my $genFilename_canifpbcfg_c = "CanIf_PBcfg.c";
my $genFilename_comcfg_h = "Com_Cfg.h";
my $genFilename_comcfg_c = "Com_Cfg.c";
my $genFilename_pdurcfg_h = "PduR_Cfg.h";
my $genFilename_pdurpbcfg_c = "PduR_PBcfg.c";
my $genFilename_comcbk_h = "com_cbk.h";
my $genFilename_comcbkadp_c = "Com_cbk_Adap.c";

sub putLine {

  my($file_handle, $context) = @_;
  print $file_handle $context."\n";
}

sub putMapStartDesc($$$$)
{
	my($file_handle, $module, $Type, $context)= @_;

	my $writeLine;

	$writeLine = "\/\* START: ".$context." Details \*\/";
	putLine($file_handle,$writeLine);

	if($Type eq 'CONST'){
		
		putLine($file_handle, q{#define COM_START_SEC_CONST_UNSPECIFIED});
	}elsif($Type eq 'VAR8'){
		putLine($file_handle, q{#define COM_START_SEC_VAR_CLEARED_8});
		}elsif($Type eq 'VAR16'){
		putLine($file_handle, q{#define COM_START_SEC_VAR_CLEARED_16});
	}elsif($Type eq 'VAR32'){
		putLine($file_handle, q{#define COM_START_SEC_VAR_CLEARED_32});
	}elsif($Type eq 'CODE'){
		putLine($file_handle, q{#define COM_START_SEC_CODE});
	}

	$writeLine = "#include \"".$module."\_MemMap.h\"";
	putLine($file_handle, $writeLine);
}

sub putMapEndDesc($$$$)
{
	my($file_handle, $module, $Type, $context)= @_;

	my $writeLine;

	if($Type eq 'CONST'){
		putLine($file_handle, q{#define COM_STOP_SEC_CONST_UNSPECIFIED});
	}elsif($Type eq 'VAR8'){
		putLine($file_handle, q{#define COM_STOP_SEC_VAR_CLEARED_8});
		}elsif($Type eq 'VAR16'){
		putLine($file_handle, q{#define COM_STOP_SEC_VAR_CLEARED_16});
	}elsif($Type eq 'VAR32'){
		putLine($file_handle, q{#define COM_STOP_SEC_VAR_CLEARED_32});
	}elsif($Type eq 'CODE'){
		putLine($file_handle, q{#define COM_STOP_SEC_CODE});
	}

	$writeLine = "#include \"".$module."\_MemMap.h\"";
	putLine($file_handle, $writeLine);
	$writeLine = "\/\* END: ".$context." Details \*\/";
	putLine($file_handle,$writeLine);
}

open(DBC_FILE, "$dbcfileName");

#set the main node
my $masterNode_name = $Main_node;

# Tx messages and signals
my @arrTxMsgDesc;
my @arrTxSigDesc;

# Rx messages and signals
my @arrRxMsgDesc;
my @arrRxSigDesc;

my $msg_Max_Tx_NUM = 0;
my $msg_Max_Rx_NUM = 0;

my $totol_Txsig_num = 0; #total Txsignal number
my $totol_Rxsig_num = 0; #total Rxsignal number

my $msg_sig_num=0;   #every message signal number

my $numSig_Boolean = 0;  #Rx signal type is boolean
my $numSig_int8 = 0;     # Rx siganl type is int8
my $numSig_int16 = 0;    # Rx siganl type is int16
my $numSig_int32 = 0;    # Rx siganl type is int32

my $istxMsgDesc = 0;  # start process Tx message
my $isRxMsgDesc = 0;  # start process Rx message

my %msg_def;  #description of every message

my $msg_name4Sig;

#-------------------------------------------------------------------------------------------------------
# Start handle dbc file
#-----------------------------------------------------------------------------------------------------------
while(<DBC_FILE>){

	my $line = $_;         #read every line
    $line =~ s/^ +//;      # delete the null of the line_beginning

#----------------------------------------------------------------------------------------------------------------------------
# process Tx message
#----------------------------------------------------------------------------------------------------------------------------
    #message description begin
    if($line =~ /^BO\_ /) # this is a message description
    {
    	#judge message type
    	if($line =~ /$masterNode_name$/ and $istxMsgDesc eq 0){
    		$istxMsgDesc = 1;
    		$msg_Sig_begin = $totol_Txsig_num;
    	}else{
    		$isRxMsgDesc = 1;
    		$msg_Sig_begin = $totol_Rxsig_num;
    	}
    	
    	#get message attribute
    	my @msg_desp = split(/ +/, $line);
    	#print $msg_desp[2]."Id=".$msg_desp[1]."\n";
    	$msg_def{'msg_name'} = $msg_desp[2];
    	$msg_def{'msg_name'} =~ s/\://;
    	my $msg_name_temp = $msg_def{'msg_name'};
    	$msg_def{'msg_TMS'} = "Com_".$msg_name_temp."_TransModeInfo";
    	$msg_name4Sig = $msg_def{'msg_name'};
    	$msg_def{'msg_Id'} = $msg_desp[1];
    	$msg_def{'msg_dlc'} = $msg_desp[3];

    	$msg_sig_num = 0;

    	#putLine(COM_CFG_C, "/*  */");
    }

    #process signal description
    if($line =~ /^SG\_ /){ #parse the signals of tx message

    	my %sig_def;
    	my @sig_temp = split(/ +/, $line);

    	$sig_def{'sig_name'} = $sig_temp[1];
    	my $sig_pos = $sig_temp[3];
    	my @sig_pos_temp = split(/\|/, $sig_pos);
    	#$sig_def{'startbit'} = $sig_pos_temp[0];
    	my $startBit = $sig_pos_temp[0];

    	my @bitsize_direction_temp = split(/\@/, $sig_pos_temp[1]);
    	$sig_def{'bitsize'} = $bitsize_direction_temp[0];
    	my $bitSize = $bitsize_direction_temp[0];

    	$sig_def{'Endian'} = $bitsize_direction_temp[1];
		#$sig_def{'Endian'} = s/\+//;
		

		if($sig_def{'Endian'} eq '0+') #motorola
		{
			my $startByte = int($startBit/8)+1;   # start byte
			my $msb_bits = ($startBit % 8)+1;     # bit numbers in 1st byte(start byte)
            if   (($bitSize - $msb_bits) > 24){
                my $lsb_bit_start = ($startByte +4)*8 - ($bitSize - $msb_bits-24);
                $sig_def{'startbit'} = $lsb_bit_start;        
            }elsif(($bitSize - $msb_bits) > 16){
                my $lsb_bit_start = ($startByte +3)*8 - ($bitSize - $msb_bits-16);
                $sig_def{'startbit'} = $lsb_bit_start;
            }elsif(($bitSize - $msb_bits) > 8){
                my $lsb_bit_start = ($startByte +2)*8 - ($bitSize - $msb_bits-8);
                $sig_def{'startbit'} = $lsb_bit_start;
            }elsif(($bitSize - $msb_bits) > 0){
                my $lsb_bit_start = ($startByte +1)*8 - ($bitSize - $msb_bits);
                $sig_def{'startbit'} = $lsb_bit_start;
			}else{
				$sig_def{'startbit'} = $startBit - $bitSize + 1;
			}      
			
			print $sig_def{'sig_name'}."\n";
			print $sig_def{'startbit'}."\n";
			#print $startByte."\n";
		}


if($sig_def{'Endian'} eq '1+') #intel
		{
				$sig_def{'startbit'} = $startBit;
			print $sig_def{'sig_name'}."\n";
			print $sig_def{'startbit'}."\n";
			#print $startByte."\n";
		}





		my $sig_factor_offset = $sig_temp[4];
		my @sig_factor_ofset_temp = split(/\,/, $sig_factor_offset);
		$sig_def{'factor'} = $sig_factor_ofset_temp[0];
		$sig_def{'factor'} =~ s/\(//;
		$sig_def{'offset'} = $sig_factor_ofset_temp[1];
		$sig_def{'offset'} =~ s/\)//;

		my $sig_min_max = $sig_temp[5];
		my @sig_min_max_temp = split(/\|/, $sig_min_max);
		$sig_def{'min'} = $sig_min_max_temp[0];
		$sig_def{'min'} =~ s/\[//;
		$sig_def{'max'} = $sig_min_max_temp[1];
		$sig_def{'max'} =~ s/\[//;

		$sig_def{'Ipdu_reference'} = $msg_name4Sig;
		$sig_def{'InitValue'} = 0;
		$sig_def{'DataInValid'} = 0;
		$sig_def{'UpdataBitPos'} = 0;
		$sig_def{'Filter_index'} = 0xff;
		$sig_def{'OldVal_Index'} = 0xff;

		if($sig_def{'Endian'} eq '0+') #moto and unsigned
		{
			if($bitSize <= 8){
				$sig_def{'General'} = '0x10';
			}elsif($bitSize <= 16){
				$sig_def{'General'} = '0x12';
			}elsif($bitSize <= 32){
				$sig_def{'General'} = '0x14';
			}
		}elsif($sig_def{'Endian'} eq '0-'){
			if($bitSize <= 8){
				$sig_def{'General'} = '0x11';
			}elsif($bitSize <= 16){
				$sig_def{'General'} = '0x13';
			}elsif($bitSize <= 32){
				$sig_def{'General'} = '0x15';
			}
		}elsif($sig_def{'Endian'} eq '1+'){
			if($bitSize <= 8){
				$sig_def{'General'} = '0x00';
			}elsif($bitSize <= 16){
				$sig_def{'General'} = '0x02';
			}elsif($bitSize <= 32){
				$sig_def{'General'} = '0x04';
			}
		}elsif($sig_def{'Endian'} eq '1-'){
			if($bitSize <= 8){
				$sig_def{'General'} = '0x01';
			}elsif($bitSize <= 16){
				$sig_def{'General'} = '0x03';
			}elsif($bitSize <= 32){
				$sig_def{'General'} = '0x05';
			}
		}

		$sig_def{'DataInvTimeout'} = '0x1';
		$sig_def{'SigBufIdx'} = 0;


		if($istxMsgDesc eq 1){

			push @arrTxSigDesc, {%sig_def};
			$totol_Txsig_num += 1;
			
		}elsif($isRxMsgDesc eq 1){
			

			if($bitSize <= 8){
				$sig_def{'SigBufIdx'} = $numSig_int8;
				$numSig_int8++;
			}elsif($bitSize <= 16){
				$sig_def{'SigBufIdx'} = $numSig_int16;
				$numSig_int16++;
			}elsif($bitSize <= 32){
				$sig_def{'SigBufIdx'} = $numSig_int32;
				$numSig_int32++;
			}

			$sig_def{'DataInvTimeout'} = '0x0';

			push @arrRxSigDesc, {%sig_def};
			$totol_Rxsig_num += 1;
		}
		
		$msg_sig_num += 1;
		
		if($msg_sig_num eq 1){
			$msg_def{'msg_firstSigIdx'} = "(Com_TxIntSignalIdType)ComSignal_".$sig_def{'sig_name'};
		}

    }

    #message description finished
    if($line =~ /^\s/ and (($istxMsgDesc eq 1 ) or ($isRxMsgDesc eq 1 ))){

    	$msg_def{'numSig'} =  $msg_sig_num;
	    	#$msg_def{'startSiggroup'} = $msg_Sig_begin;
	    $msg_def{'msg_CycleTime'} = 0;
	    $msg_def{'msg_TimeOffsetFact'} = 0;
	    $msg_def{'RepetitionPeriodFact'} = 0;
	    $msg_def{'NumRepetitions'} = 0;
	    $msg_def{'Mode'} = 'COM_TXMODE_PERIODIC';
	    $msg_def{'MixedPhaseShift_status'} = 'COM_FALSE';
	    #$msg_def{'msg_firstSigIdx'} = $msg_Sig_begin;
	    #$msg_def{'msg_firstSigIdx'} = $msg_Sig_begin;
	    

    	if($istxMsgDesc eq 1 ){

	    	#$msg_def{'msg_delayTime'} = 0;

	    	if( $msg_sig_num > 0){
	    		$msg_Max_Tx_NUM += 1;
	    		push @arrTxMsgDesc, {%msg_def};
	    		#print $msg_sig_num."\n";
	    	}
    		$istxMsgDesc = 0;
    	}elsif($isRxMsgDesc eq 1 ){

    		if( $msg_sig_num > 0){
	    		$msg_Max_Rx_NUM += 1;
	    		push @arrRxMsgDesc, {%msg_def};
	    		#print $msg_sig_num."\n";
	    	}
    		$isRxMsgDesc = 0;
    	}
    	


  	
    }

    #get the send cycle time
    if($line =~ /^BA\_ / and $line =~ /GenMsgCycleTime/ ){

    	#print $line;
    	my @genMsgCyT = split(/ +/, $line);
    	#print $genMsgCyT[3];
    	for(my $i=0; $i < $msg_Max_Tx_NUM; $i=$i+1){
    		
    		my $msg_Id = $arrTxMsgDesc[$i]{'msg_Id'};

    		if($msg_Id eq $genMsgCyT[3]){
    			$arrTxMsgDesc[$i]{'msg_CycleTime'} = $genMsgCyT[4];
    			$arrTxMsgDesc[$i]{'msg_CycleTime'} =~ s/\;//;
    			#print $arrTxMsgDesc[$i]{'msg_CycleTime'};
    			last;
    		}
    	}

    	for(my $i=0; $i < $msg_Max_Rx_NUM; $i=$i+1){
    		
    		my $msg_Id = $arrRxMsgDesc[$i]{'msg_Id'};

    		if($msg_Id eq $genMsgCyT[3]){
    			$arrRxMsgDesc[$i]{'msg_CycleTime'} = $genMsgCyT[4];
    			$arrRxMsgDesc[$i]{'msg_CycleTime'} =~ s/\;//;
    			#print $arrTxMsgDesc[$i]{'msg_CycleTime'};
    			last;
    		}
    	}

    }

}


close(DBC_FILE);

for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
	print $arrTxMsgDesc[$i]{'msg_name'}."\t";
	print $arrTxMsgDesc[$i]{'msg_Id'}."\t";
	print $arrTxMsgDesc[$i]{'msg_CycleTime'}."\n"; 
}

for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
	print $arrRxMsgDesc[$i]{'msg_name'}."\t";
	print $arrRxMsgDesc[$i]{'msg_Id'}."\t";
	print $arrRxMsgDesc[$i]{'msg_CycleTime'}."\n"; 
}

#-------------------------------------------------------------------------------
# Write signal attribute
#-------------------------------------------------------------------------------

sub putSignalAttrib
{
	my ($file_handle, $SignAttr_Val, $attr) = (@_);

	#my %hash = %$Signal_desc;
	my $writeLine;
	if($attr eq 'SigBegin'){
		$writeLine = " \{  \/\*  ".$SignAttr_Val." \*\/";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\n");
	}elsif($attr eq 'DataInValid'){
		putLine($file_handle, "\t#ifdef COM_TxInvalid");
		putLine($file_handle, "\t0ul,   \/\* DataInValid_Val \*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'Init_Val'){
		$writeLine = "\t".$SignAttr_Val."ul,   \/\* Init_val   \*\/";
		putLine($file_handle, $writeLine);
	}elsif($attr eq 'UpdataBitPos'){
		putLine($file_handle, "\t#ifdef COM_TxSigUpdateBit");
		putLine($file_handle, "\tCOM_UPDATE_MAX,   \/\* Update bit Position \*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'BitPos'){
		$writeLine = "\t".$SignAttr_Val.",   \/\* BitPosition   \*\/";
		putLine($file_handle, $writeLine);
	}elsif($attr eq 'BitSize'){
		$writeLine = "\t".$SignAttr_Val.",   \/\* BitSize   \*\/";
		putLine($file_handle, $writeLine);
	}elsif($attr eq 'Filter_index'){
		putLine($file_handle, "\t#ifdef COM_TxFilters");
		putLine($file_handle, "\t0xff,   \/\* Filter_Index \*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'OldVal_Index'){
		putLine($file_handle, "\t#ifdef COM_SigTriggeredOnChange");
		putLine($file_handle, "\t0xff,   \/\* OldVal_Index \*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'IpduRef'){
		$writeLine = "\t\(Com_IpduIdType\)ComConf_ComIPdu_".$SignAttr_Val.",   \/\* Ipdu Reference   \*\/";
		putLine($file_handle, $writeLine);
	}elsif($attr eq 'General'){
		$writeLine = "\t".$SignAttr_Val.",   \/\* General   \*\/";
		putLine($file_handle, $writeLine);
	}elsif($attr eq 'DataInvTimeout'){
		$writeLine = "\t".$SignAttr_Val."   \/\* DataInvTimeout   \*\/";
		putLine($file_handle, $writeLine);
	}elsif($attr eq 'SigEnd'){
		$writeLine = " \},  ";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\n");
	}elsif($attr eq 'Notification Signal part'){
		putLine($file_handle, "\t#ifdef COM_RxSignalNotify");
		putLine($file_handle, "\tNULL_PTR,   \/\* Notification Signal part \*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'Com Invalid Notification'){
		putLine($file_handle, "\t#ifdef COM_RxSigInvalidNotify");
		putLine($file_handle, "\tNULL_PTR,   \/\* Com Invalid Notification\*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'Rx DataInValid'){
		putLine($file_handle, "\t#ifdef COM_RxSigInvalid");
		putLine($file_handle, "\t0ul,   \/\* DataInValid_Val \*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'Rx UpdataBitPos'){
		putLine($file_handle, "\t#ifdef COM_RxSigUpdateBit");
		putLine($file_handle, "\tCOM_UPDATE_MAX,   \/\* Update bit Position \*\/");
		putLine($file_handle, "\t#endif");
	}elsif($attr eq 'Signal Buffer Index'){
		$writeLine = "\t".$SignAttr_Val.",   \/\* Signal Buffer Index   \*\/";
		putLine($file_handle, $writeLine);
	}elsif($attr eq 'Rx Filter_index'){
		putLine($file_handle, "\t#ifdef COM_RxFilters");
		putLine($file_handle, "\t0xff,   \/\* Filter_Index \*\/");
		putLine($file_handle, "\t#endif");
	}

}

#-------------------------------------------------------------------------------
# Write Tx siganls
#-------------------------------------------------------------------------------
sub putTxSigDesc
{
	my ($Signal_desc, $file_handle) = (@_);
	my %hash = %$Signal_desc;

	putSignalAttrib($file_handle, $hash{'sig_name'}, 'SigBegin');
	putSignalAttrib($file_handle, $hash{'DataInValid'}, 'DataInValid');
	putSignalAttrib($file_handle, $hash{'InitValue'}, 'Init_Val');
	putSignalAttrib($file_handle, $hash{'UpdataBitPos'}, 'UpdataBitPos');
	putSignalAttrib($file_handle, $hash{'startbit'}, 'BitPos');
	putSignalAttrib($file_handle, $hash{'bitsize'}, 'BitSize');
	putSignalAttrib($file_handle, $hash{'Filter_Index'}, 'Filter_index');
	putSignalAttrib($file_handle, $hash{'OldVal_Index'}, 'OldVal_Index');
	putSignalAttrib($file_handle, $hash{'Ipdu_reference'}, 'IpduRef');
	putSignalAttrib($file_handle, $hash{'General'}, 'General');
	putSignalAttrib($file_handle, $hash{'DataInvTimeout'}, 'DataInvTimeout');
	putSignalAttrib($file_handle, $hash{'sig_name'}, 'SigEnd');
}

#-------------------------------------------------------------------------------
# Write Tx Message
#-------------------------------------------------------------------------------
sub putTxMsgDesc
{

	my ($Signal_desc, $file_handle) = (@_);
	my %hash = %$Signal_desc;
	my $writeLine;

	#message description start
	$writeLine = " \{  \/\*Ipdu  ".$hash{'msg_name'}." \*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#message Ipdu Buff
	$writeLine = "\tCom_IpduBuf_".$hash{'msg_name'}."\,   \/\* Pointer to the Ipdu Buffer \*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#message TMS
	$writeLine = "\t".$hash{'msg_TMS'}."\,";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#callout function
	putLine($file_handle, "\t#ifdef COM_TxIPduCallOuts");
	putLine($file_handle, "\tNULL_PTR,   \/\* Ipdu Callout Function \*\/");
	putLine($file_handle, "\t#endif");

	#Ipdu Notification function
	putLine($file_handle, "\t#ifdef COM_TxIPduNotification");
	putLine($file_handle, "\t&Com_TxNotify_".$hash{'msg_name'}.",   \/\* Ipdu Notification Function \*\/");
	putLine($file_handle, "\t#endif");

	#error notification
	putLine($file_handle, "\t#ifdef COM_ERRORNOTIFICATION");
	putLine($file_handle, "\tNULL_PTR,   \/\* Error Notification part  \*\/");
	putLine($file_handle, "\t#endif");

	#timeout notification part
	putLine($file_handle, "\t#ifdef COM_TxIPduNotification");
	putLine($file_handle, "\t&Com_TxTONotify_".$hash{'msg_name'}.",   \/\* Timeout Notification part \*\/");
	putLine($file_handle, "\t#endif");

	#local buffer
	putLine($file_handle, "\t#ifdef COM_TXDOUBLEBUFFER");
	putLine($file_handle, "\tCom_LocalBuf_".$hash{'msg_name'}.",   \/\* Timeout Notification part \*\/");
	putLine($file_handle, "\t#endif");

	#size in Byte
	$writeLine = "\t".$hash{'msg_dlc'}."\,  \/\*Size in Bytes\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#timeout
	my $TimePeriodFact = $hash{'msg_CycleTime'}/5;
	putLine($file_handle, "\t#ifdef COM_TxIPduTimeOut");
	putLine($file_handle, "\t".$TimePeriodFact.", \/\*  No Of Signals present in the IPDUTimeout Fact\*\/");
	putLine($file_handle, "\t#endif");

	#MinDelay
	$writeLine = "\t0"."\,   \/\* MinDelay Time factor\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#num of signals
	$writeLine = "\t".$hash{'numSig'}."\, \/\*No Of Signals present in the IPDU\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#signal group
	putLine($file_handle, "\t#ifdef COM_TX_SIGNALGROUP");
	putLine($file_handle, "\t0".",   \/\* No of Signal Groups present in the IPDU \*\/");
	putLine($file_handle, "\t#endif");

	#Pdu Id
	$writeLine = "\t(PduIdType)PduRConf_PduRSrcPdu_".$hash{'msg_name'}."_Com2PduR_Src,  \/\* PduR Id\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#first signal
	$writeLine = "\t".$hash{'msg_firstSigIdx'} .",  \/\* Index to First Signal within this Ipdu\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#signal group
	putLine($file_handle, "\t#ifdef COM_TX_SIGNALGROUP");
	putLine($file_handle, "\t0".",   \/\* This IPDU does not contain any Signal Groups \*\/");
	putLine($file_handle, "\t#endif");
	
	#transmission type
	$writeLine = "\t0x40".",  \/\* Transmission Type\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#padding Byte
	$writeLine = "\t0x00"."  \/\* Padding Byt\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#end
	$writeLine = " \},";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");
}


#-------------------------------------------------------------------------------
# Write Rx signal
#-------------------------------------------------------------------------------

sub putRxSigDesc
{
	my ($Signal_desc, $file_handle) = (@_);
	my %hash = %$Signal_desc;

	putSignalAttrib($file_handle, $hash{'sig_name'}, 'SigBegin');
	putSignalAttrib($file_handle, 'NULL_PTR', 'Notification Signal part');
	putSignalAttrib($file_handle, 'NULL_PTR', 'Com Invalid Notification');
	putSignalAttrib($file_handle, '0', 'Rx DataInValid');
	putSignalAttrib($file_handle, $hash{'InitValue'}, 'Init_Val');
	putSignalAttrib($file_handle, 'COM_UPDATA_MAX', 'Rx UpdataBitPos');
	putSignalAttrib($file_handle, $hash{'startbit'}, 'BitPos');
	putSignalAttrib($file_handle, $hash{'SigBufIdx'}, 'Signal Buffer Index');
	putSignalAttrib($file_handle, $hash{'bitsize'}, 'BitSize');
	putSignalAttrib($file_handle, $hash{'Filter_Index'}, 'Rx Filter_index');
	putSignalAttrib($file_handle, $hash{'Ipdu_reference'}, 'IpduRef');
	putSignalAttrib($file_handle, $hash{'General'}, 'General');
	putSignalAttrib($file_handle, $hash{'DataInvTimeout'}, 'DataInvTimeout');
	putSignalAttrib($file_handle, $hash{'sig_name'}, 'SigEnd');
}

#-------------------------------------------------------------------------------
# Write Rx Message
#-------------------------------------------------------------------------------
sub putRxMsgDesc
{

	my ($Signal_desc, $file_handle) = (@_);
	my %hash = %$Signal_desc;
	my $writeLine;

	#message description start
	$writeLine = " \{  \/\*Ipdu  ".$hash{'msg_name'}." \*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#message localIpdu Buff
	$writeLine = "\tCom_LocalBuf_".$hash{'msg_name'}."\,   \/\* Pointer to the Local Ipdu Buffer \*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#callout function
	putLine($file_handle, "\t#ifdef COM_RxSigUpdateTimeout");
	putLine($file_handle, "\tNULL_PTR,   \/\* Pointer to timeout information structure for signals with update-bits, within the IPdu \*\/");
	putLine($file_handle, "\t#endif");

	#Pointer to timeout information structure
	putLine($file_handle, "\t#ifdef COM_RxSigGrpUpdateTimeout");
	putLine($file_handle, "\tNULL_PTR,   \/\* Pointer to timeout information structure for signal groups with update-bits, within the IPdu \*\/");
	putLine($file_handle, "\t#endif");

	#Ipdu callout
	putLine($file_handle, "\t#ifdef COM_RxIPduCallOuts");
	putLine($file_handle, "\tNULL_PTR,   \/\* Rx IPdu callout  \*\/");
	putLine($file_handle, "\t#endif");

	#timeout notification part
	putLine($file_handle, "\t#ifdef COM_TxIPduNotification");
	putLine($file_handle, "\t&Com_RxTONotify_".$hash{'msg_name'}.",   \/\* Timeout Notification part \*\/");
	putLine($file_handle, "\t#endif");

	#Ipdu Notification Function
	putLine($file_handle, "\t#ifdef COM_RxSigUpdateTimeout");
	putLine($file_handle, "\tNULL_PTR,   \/\* Pointer to timeout information structure for signals with update-bits, within the IPdu \*\/");
	putLine($file_handle, "\t#endif");

	#error notification
	putLine($file_handle, "\t#ifdef COM_RxIPduNotification");
	putLine($file_handle, "\t&Com_RxCbk_".$hash{'msg_name'}.",   \/\* Rx IPdu notification callbackn \*\/");
	#putLine($file_handle, "\tNULL_PTR,   \/\* Rx IPdu notification callback  \*\/");
	putLine($file_handle, "\t#endif");

	#size in Byte
	$writeLine = "\t".$hash{'msg_dlc'}."\,  \/\* Size in Bytes\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#timeout
	my $TimePeriodFact = $hash{'msg_CycleTime'}/5;
	putLine($file_handle, "\t#ifdef COM_RxIPduTimeout");
	putLine($file_handle, "\t".$TimePeriodFact.",   \/\* First time out value after IPDU group start\*\/");
	putLine($file_handle, "\t".$TimePeriodFact.",   \/\* CC requriment: Support Rx IPDU Timeout\*\/");
	putLine($file_handle, "\t#endif");

	#num of signals
	$writeLine = "\t".$hash{'numSig'}."\,  \/\* No Of Signals present in the IPDU\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#signal group
	putLine($file_handle, "\t#ifdef COM_RX_SIGNALGROUP");
	putLine($file_handle, "\t0".",   \/\* No of Signal Groups present in the IPDU \*\/");
	putLine($file_handle, "\t#endif");

	#first signal
	$writeLine = "\t".$hash{'msg_firstSigIdx'} .",  \/\* Index to First Signal within this Ipdu\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#signal group
	putLine($file_handle, "\t#ifdef COM_RX_SIGNALGROUP");
	putLine($file_handle, "\t0".",   \/\* This IPDU does not contain any Signal Groups \*\/");
	putLine($file_handle, "\t#endif");
	
	#transmission type
	$writeLine = "\t0x00"." \/\* Transmission Type\*\/";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	#end
	$writeLine = " \},";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");
}



#-------------------------------------------------------------------------------
# Write all Tx signal
#-------------------------------------------------------------------------------
sub putAllTxSigDescription
{
	my $file_handle = $_[0];
	my $writeLine;
	$writeLine = q{/* START: Tx Signal Details  */};
	putLine($file_handle, $writeLine);
	$writeLine = q{#define COM_START_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	$writeLine = q{CONST(Com_TxSigType ,COM_CONST) Com_TxSig[COM_NUM_TX_SIGNALS] =};
	putLine($file_handle, $writeLine);
	$writeLine = "\{";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	for(my $SigIdx=0; $SigIdx < $totol_Txsig_num; $SigIdx++ ){
		putTxSigDesc($arrTxSigDesc[$SigIdx], $file_handle);
	}

	$writeLine = "\}\;";
	putLine($file_handle, $writeLine);
	$writeLine = q{#define COM_STOP_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	$writeLine = q{/* END: Tx Signal Details  */};
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

}

#-------------------------------------------------------------------------------
# Write all Rx signal
#-------------------------------------------------------------------------------
sub putAllRxSigDescription
{
	my $file_handle = $_[0];
	my $writeLine;
	$writeLine = q{/* START: Rx Signal Details  */};
	putLine($file_handle, $writeLine);
	$writeLine = q{#define COM_START_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	$writeLine = q{CONST(Com_RxSigType ,COM_CONST) Com_RxSig[COM_NUM_RX_SIGNALS] =};
	putLine($file_handle, $writeLine);
	$writeLine = "\{";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

	for(my $SigIdx=0; $SigIdx < $totol_Rxsig_num; $SigIdx++ ){
		putRxSigDesc($arrRxSigDesc[$SigIdx], $file_handle);
	}

	$writeLine = "\}\;";
	putLine($file_handle, $writeLine);
	$writeLine = q{#define COM_STOP_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	$writeLine = q{/* END: Rx Signal Details  */};
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

}

#-------------------------------------------------------------------------------
# Write TMS Details
#-------------------------------------------------------------------------------
sub putTxMsgTMS
{
	my ($Msg_desc, $file_handle) = (@_);
	my %hash = %$Msg_desc;

	my $writeLine;

	
	$writeLine = q{#define COM_START_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	$writeLine = "\/\*".$hash{'msg_name'}."has a TMS switch\*\/";
	putLine($file_handle, $writeLine);

	$writeLine = "static CONST(Com_TransModeInfo ,COM_CONST) ".$hash{'msg_TMS'}."[] = {";
	putLine($file_handle, $writeLine);

	putLine($file_handle, "\t\{");

	my $TimePeriodFact = $hash{'msg_CycleTime'}/10;
	$writeLine = "\t".$TimePeriodFact.",   \/\* TimePeriodFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t".$hash{'msg_TimeOffsetFact'}.",   \/\* TimeOffsetFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t".$hash{'RepetitionPeriodFact'}.",   \/\* RepetitionPeriodFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t".$hash{'NumRepetitions'}.",   \/\* NumRepetitions   \*\/";
	putLine($file_handle, $writeLine);

	putLine($file_handle, "#ifdef COM_MIXEDPHASESHIFT");
	putLine($file_handle, "\t$hash{'Mode'},   \/\* Mode \*\/");
	putLine($file_handle, "\t$hash{'MixedPhaseShift_status'}   \/\* MixedPhaseShift status \*\/");
	putLine($file_handle, "#else");
	putLine($file_handle, "\t$hash{'Mode'}   \/\* Mode \*\/");
	putLine($file_handle, "#endif   \/\* #ifdef COM_MIXEDPHASESHIFT \*\/");

	putLine($file_handle, "\t\}\,");

	putLine($file_handle, "\t\{");

	$TimePeriodFact = $hash{'msg_CycleTime'}/10;
	$writeLine = "\t".$TimePeriodFact.",   \/\* TimePeriodFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t".$hash{'msg_TimeOffsetFact'}.",   \/\* TimeOffsetFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t".$hash{'RepetitionPeriodFact'}.",   \/\* RepetitionPeriodFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t".$hash{'NumRepetitions'}.",   \/\* NumRepetitions   \*\/";
	putLine($file_handle, $writeLine);

	putLine($file_handle, "#ifdef COM_MIXEDPHASESHIFT");
	putLine($file_handle, "\t$hash{'Mode'},   \/\* Mode \*\/");
	putLine($file_handle, "\t$hash{'MixedPhaseShift_status'}  \/\* MixedPhaseShift status \*\/");
	putLine($file_handle, "#else");
	putLine($file_handle, "\t$hash{'Mode'}   \/\* Mode \*\/");
	putLine($file_handle, "#endif   \/\* #ifdef COM_MIXEDPHASESHIFT \*\/");

	putLine($file_handle, "\t\}");

	putLine($file_handle, "\};");

	$writeLine = q{#define COM_STOP_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");

}

sub putAllTxMsgTMS
{
	my $file_handle = $_[0];
	my $writeLine;
	$writeLine = q{/* START: TMS Details  */};
	putLine($file_handle, $writeLine);

	for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
		putTxMsgTMS($arrTxMsgDesc[$i], $file_handle);
	}

	$writeLine = q{#define COM_START_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);

	$writeLine = "CONST(Com_TransModeInfo ,COM_CONST) Com_NONE_TransModeInfo"." = {";
	putLine($file_handle, $writeLine);

	my $TimePeriodFact = '0';
	$writeLine = "\t".$TimePeriodFact.",   \/\* TimePeriodFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t0".",   \/\* TimeOffsetFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t0".",   \/\* RepetitionPeriodFact   \*\/";
	putLine($file_handle, $writeLine);
	$writeLine = "\t0".",   \/\* NumRepetitions   \*\/";
	putLine($file_handle, $writeLine);

	putLine($file_handle, "#ifdef COM_MIXEDPHASESHIFT");
	putLine($file_handle, "\tCOM_TXMODE_NONE,   \/\* Mode \*\/");
	putLine($file_handle, "\tCOM_FALSE  \/\* MixedPhaseShift status \*\/");
	putLine($file_handle, "#else");
	putLine($file_handle, "\tCOM_TXMODE_NONE   \/\* Mode \*\/");
	putLine($file_handle, "#endif   \/\* #ifdef COM_MIXEDPHASESHIFT \*\/");

	putLine($file_handle, "\}\;");
	$writeLine = q{#define COM_STOP_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");


	$writeLine = q{/* END: TMS Details  */};
	putLine($file_handle, $writeLine);
}


sub putAllTxMsgDesc
{
	my $file_handle = $_[0];
	my $writeLine;

	$writeLine = q{/* START: Tx IPDU Details  */};
	putLine($file_handle, $writeLine);
	$writeLine = q{#define COM_START_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);

	$writeLine = q{CONST(Com_TxIpduInfo ,COM_CONST) Com_TxIpdu[COM_NUM_TX_IPDU] = \{};
	putLine($file_handle, $writeLine);

	for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
		putTxMsgDesc($arrTxMsgDesc[$i], $file_handle);
	}

	putLine($file_handle, "\}\;");
	$writeLine = q{#define COM_STOP_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");


	$writeLine = q{/* END: Tx IPDU Details  */};
	putLine($file_handle, $writeLine);
}


sub putAllRxMsgDesc
{
	my $file_handle = $_[0];
	my $writeLine;

	$writeLine = q{/* START: Rx IPDU Details  */};
	putLine($file_handle, $writeLine);
	$writeLine = q{#define COM_START_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);

	$writeLine = q{CONST(Com_RxIpduInfo ,COM_CONST) Com_RxIpdu[COM_NUM_RX_IPDU]  = \{};
	putLine($file_handle, $writeLine);

	for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
		putRxMsgDesc($arrRxMsgDesc[$i], $file_handle);
	}

	putLine($file_handle, "\}\;");
	$writeLine = q{#define COM_STOP_SEC_CONST_UNSPECIFIED};
	putLine($file_handle, $writeLine);
	$writeLine = q{#include "Com_MemMap.h"};
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\n");


	$writeLine = q{/* END: Rx IPDU Details  */};
	putLine($file_handle, $writeLine);
}

#-------------------------------------------------------------------------------
# Write IPDU Group
#-------------------------------------------------------------------------------
sub putIPDUGroup
{
	my $file_handle = $_[0];
	my $writeLine;

	putMapStartDesc($file_handle, 'Com', 'CONST', 'IPDU Group');

	putLine($file_handle, q{CONST(Com_IpduGrpInfo ,COM_CONST) Com_IpduGrp[COM_NUM_TOTAL_IPDU_GRP] =});
	putLine($file_handle, "{           \/\* \"Index of First IPdu\"               \"No of Ipdus\" \*\/");
	putLine($file_handle, "\{ \/\* RBM_INV_BASE_TX  \*\/");

	putLine($file_handle, "\t0,");
	putLine($file_handle, "\t$msg_Max_Tx_NUM");
	putLine($file_handle, "\},");

	putLine($file_handle, "\{ \/\* RBM_INV_BASE_RX  \*\/");

	putLine($file_handle, "\t$msg_Max_Tx_NUM,");
	putLine($file_handle, "\t$msg_Max_Rx_NUM");
	putLine($file_handle, "\}");
	putLine($file_handle, "\};");

	putMapEndDesc($file_handle, 'Com', 'CONST', 'IPDU Group');

}


#-------------------------------------------------------------------------------
# Write Tx Ipdu Buffer
#-------------------------------------------------------------------------------
sub putTxIpduBufDesc($$)
{
	my ($file_handle, $comment) = @_;
	my $writeLine;

	putMapStartDesc($file_handle, 'Com', 'VAR8', 'Tx Ipdu Buffers');

	for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
		if($comment eq 'definition'){
			$writeLine = "\tVAR(uint8,COM_VAR) Com_IpduBuf_".$arrTxMsgDesc[$i]{'msg_name'}."\[".$arrTxMsgDesc[$i]{'msg_dlc'}."\]\;";
		}else{
			$writeLine = "\textern VAR(uint8,COM_VAR) Com_IpduBuf_".$arrTxMsgDesc[$i]{'msg_name'}."\[".$arrTxMsgDesc[$i]{'msg_dlc'}."\]\;";
		}
		
		putLine($file_handle, $writeLine);
		putLine($file_handle,"\n");
	}

	putMapEndDesc($file_handle, 'Com', 'VAR8', 'Tx Ipdu Buffers');
}


#-------------------------------------------------------------------------------
# Write Rx local Buffer
#-------------------------------------------------------------------------------
sub putRxIpduBufDesc($$)
{
	my ($file_handle, $comment) = @_;
	my $writeLine;

	putMapStartDesc($file_handle, 'Com', 'VAR8', 'Rx local Buffers');

	for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
		if($comment eq 'definition'){
			$writeLine = "\tVAR(uint8,COM_VAR) Com_LocalBuf_".$arrRxMsgDesc[$i]{'msg_name'}."\[".$arrRxMsgDesc[$i]{'msg_dlc'}."\]\;";
		}else{
			$writeLine = "\textern VAR(uint8,COM_VAR) Com_LocalBuf_".$arrRxMsgDesc[$i]{'msg_name'}."\[".$arrRxMsgDesc[$i]{'msg_dlc'}."\]\;";
		}
		
		putLine($file_handle, $writeLine);
		putLine($file_handle,"\n");
	}

	putMapEndDesc($file_handle, 'Com', 'VAR8', 'Rx local Buffers');
}

#-------------------------------------------------------------------------------
# Write Rx signal buffer
#-------------------------------------------------------------------------------
sub putRxSigBuffDesc($$)
{
	my ($file_handle, $Type) = @_;
	my $writeLine;

	#int8
	putMapStartDesc($file_handle, 'Com', 'VAR8', 'Type: UINT8, SINT8, UINT8_N, BOOLEAN');

	if($Type eq 'c'){
		$writeLine = "VAR(uint8,COM_VAR) Com_SigType_u8[".$numSig_int8."\] = ";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\{");

		$writeLine = "\t";
		for(my $i=0; $i< ($numSig_int8-1); $i++){
			$writeLine = $writeLine."0, ";
			
		}

		$writeLine = $writeLine."0";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\};");
		putLine($file_handle,"\n");
	}else{
		$writeLine = "extern VAR(uint8,COM_VAR) Com_SigType_u8[".$numSig_int8."\];";
		putLine($file_handle, $writeLine);
	}
	

	putMapEndDesc($file_handle, 'Com', 'VAR8', 'Type: UINT8, SINT8, UINT8_N, BOOLEAN');


	#int16
	putMapStartDesc($file_handle, 'Com', 'VAR16', 'Type: UINT8, SINT8, UINT8_N, BOOLEAN');

	if($Type eq 'c'){
		$writeLine = "VAR(uint16,COM_VAR) Com_SigType_u16[".$numSig_int16."\] = ";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\{");

		$writeLine = "\t";
		for($i=0; $i< ($numSig_int16-1); $i++){
			$writeLine = $writeLine."0, ";
			
		}

		$writeLine = $writeLine."0";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\};");
		putLine($file_handle,"\n");

	}else{
		$writeLine = "extern VAR(uint16,COM_VAR) Com_SigType_u16[".$numSig_int16."\];";
		putLine($file_handle, $writeLine);
	}
	

	putMapEndDesc($file_handle, 'Com', 'VAR16', 'Type: UINT8, SINT8, UINT8_N, BOOLEAN');


	#int32
	if($numSig_int32 eq 0){
		$numSig_int32 = 1;
	}
	putMapStartDesc($file_handle, 'Com', 'VAR32', 'Type: UINT8, SINT8, UINT8_N, BOOLEAN');

	if($Type eq 'c'){
		$writeLine = "VAR(uint32,COM_VAR) Com_SigType_u32[".$numSig_int32."\] = ";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\{");

		$writeLine = "\t";
		for($i=0; $i< ($numSig_int32-1); $i++){
			$writeLine = $writeLine."0, ";
			
		}

		$writeLine = $writeLine."0";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\};");
		putLine($file_handle,"\n");

	}else{
		$writeLine = "extern VAR(uint32,COM_VAR) Com_SigType_u32[".$numSig_int32."\]; ";
		putLine($file_handle, $writeLine);
	}
	

	putMapEndDesc($file_handle, 'Com', 'VAR32', 'Type: UINT8, SINT8, UINT8_N, BOOLEAN');

}

#-------------------------------------------------------------------------------
# Reference to Ipdus belonging to the Ipdu Groups
#-------------------------------------------------------------------------------
sub putIpdusBelongGroup
{
	my $file_handle = $_[0];
	my $writeLine;

	putMapStartDesc($file_handle, 'Com', 'CONST', 'Reference to Ipdus belonging to the Ipdu Groups');

	$total_msg_num = $msg_Max_Rx_NUM+$msg_Max_Tx_NUM;

	$writeLine = "CONST(Com_IpduIdType ,COM_CONST) Com_IPduGrp_IpduRef[".$total_msg_num."] = ";
	putLine($file_handle, $writeLine);
	putLine($file_handle, "\{");

	putLine($file_handle, "/*RBM_INV_BASE_TX */");
	for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
		$writeLine = "(COM_NUM_RX_IPDU + ComConf_ComIPdu_".$arrTxMsgDesc[$i]{'msg_name'}."\),";
		putLine($file_handle, $writeLine);
	}

	putLine($file_handle, "/*RBM_INV_BASE_RX */");
	for(my $i=0; $i< ($msg_Max_Rx_NUM-1); $i++){
		$writeLine = "ComConf_ComIPdu_".$arrRxMsgDesc[$i]{'msg_name'}.",";
		putLine($file_handle, $writeLine);
	}

	$writeLine = "ComConf_ComIPdu_".$arrRxMsgDesc[$msg_Max_Rx_NUM-1]{'msg_name'};
	putLine($file_handle, $writeLine);

	putLine($file_handle, "\};");

	putMapEndDesc($file_handle, 'Com', 'CONST', 'Reference to Ipdus belonging to the Ipdu Groups');
}


sub putTxIpduNotiFuncs
{
	my $file_handle = $_[0];
	my $writeLine;

	#Tx notification
	putLine($file_handle, q{#ifdef COM_TxIPduNotification});
	for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
		putMapStartDesc($file_handle, 'Com', 'CODE', 'Tx IPDU notification functions');
		$writeLine = "static FUNC(void,COM_CODE) Com_TxNotify_".$arrTxMsgDesc[$i]{'msg_name'}."(void);";
		putLine($file_handle, $writeLine);
		$writeLine = "static FUNC(void,COM_CODE) Com_TxNotify_".$arrTxMsgDesc[$i]{'msg_name'}."(void)";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\{");
		putLine($file_handle, "\tCom_TxConfirmCbk_".$arrTxMsgDesc[$i]{'msg_name'}."();" );
		putLine($file_handle, "\}");
		putMapEndDesc($file_handle, 'Com', 'CODE', '');
	}
	putLine($file_handle, q{#endif});

		#Tx notification
	putLine($file_handle, q{#ifdef COM_TxIPduTimeOutNotify});
	for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
		putMapStartDesc($file_handle, 'Com', 'CODE', 'Tx IPDU timeout  notification functionss');
		$writeLine = "static FUNC(void,COM_CODE) Com_TxTONotify_".$arrTxMsgDesc[$i]{'msg_name'}."(void);";
		putLine($file_handle, $writeLine);
		$writeLine = "static FUNC(void,COM_CODE) Com_TxTONotify_".$arrTxMsgDesc[$i]{'msg_name'}."(void)";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\{");
		#putLine($file_handle, "Com_TxConfirmCbk_".$arrTxMsgDesc[$i]{'msg_name'}."();" );
		putLine($file_handle, "\}");
		putMapEndDesc($file_handle, 'Com', 'CODE', '');
	}
	putLine($file_handle, q{#endif});

}

sub putRxIpduTimeoutCbk
{
	my $file_handle = $_[0];
	my $writeLine;

	#Tx notification
	putLine($file_handle, q{#ifdef COM_RxIPduTimeoutNotify});
	for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
		putMapStartDesc($file_handle, 'Com', 'CODE', 'Rx IPDU timeout callback functions');
		$writeLine = "static FUNC(void,COM_CODE) Com_RxTONotify_".$arrRxMsgDesc[$i]{'msg_name'}."(void);";
		putLine($file_handle, $writeLine);
		$writeLine = "static FUNC(void,COM_CODE) Com_RxTONotify_".$arrRxMsgDesc[$i]{'msg_name'}."(void)";
		putLine($file_handle, $writeLine);
		putLine($file_handle, "\{");
		putLine($file_handle, "\tCom_RxTimeoutCbk_".$arrRxMsgDesc[$i]{'msg_name'}."();" );
		putLine($file_handle, "\}");
		putMapEndDesc($file_handle, 'Com', 'CODE', '');
	}
	putLine($file_handle, q{#endif});

}


#----------------------------------------------------------------------------------------------------------------------------
# Write Com_cfg.c files
#$tplPath, $genFilePath
#----------------------------------------------------------------------------------------------------------------------------


my $genTempFile = $genFilePath.$genFilename_comcfg_c;
my $tplTempFile = $tplPath.$tplFilename_comcfg_c;

open(COM_CFG_C, "> $genTempFile");
open(COM_CFG_C_TPL, "< $tplTempFile") || die("no file read");


putLine(COM_CFG_C, q{#include "Com.h"});
putLine(COM_CFG_C, q{#include "Com_Cbk.h"});
putLine(COM_CFG_C, q{#include "Com_Priv.h"});
putLine(COM_CFG_C, q{#include "Com_Types.h"});
putLine(COM_CFG_C, q{#include "PduR_Com.h"});

putAllTxSigDescription(COM_CFG_C);
putAllRxSigDescription(COM_CFG_C);
putTxIpduNotiFuncs(COM_CFG_C);
putAllTxMsgTMS(COM_CFG_C);
putAllTxMsgDesc(COM_CFG_C);
putRxIpduTimeoutCbk(COM_CFG_C);
putAllRxMsgDesc(COM_CFG_C);
putIPDUGroup(COM_CFG_C);
putTxIpduBufDesc(COM_CFG_C,'definition');
putRxIpduBufDesc(COM_CFG_C, 'definition');
putRxSigBuffDesc(COM_CFG_C, 'c');
putIpdusBelongGroup(COM_CFG_C);


while(<COM_CFG_C_TPL>){

	my $line = $_;

	print COM_CFG_C $line;
}

close(COM_CFG_C);
close(COM_CFG_C_TPL);

#----------------------------------------------------------------------------------------------------------------------------
# Write Com_cfg.h files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_comcfg_h;
$tplTempFile = $tplPath.$tplFilename_comcfg_h;

open(COM_CFG_H, "> $genTempFile");
open(COM_CFG_H_TPL, "< $tplTempFile");

while(<COM_CFG_H_TPL>)
{
	my $line = $_;

	if($line =~ /COM_NUM_TOTAL_IPDU_GRP/)
	{
		#write number of messages
		putLine(COM_CFG_H, "#define COM_NUM_RX_SIGNALS   ".$totol_Rxsig_num);
		putLine(COM_CFG_H, "#define COM_NUM_TX_SIGNALS   ".$totol_Txsig_num);
		putLine(COM_CFG_H, "#define COM_NUM_TX_IPDU   ".$msg_Max_Tx_NUM);
		putLine(COM_CFG_H, "#define COM_NUM_RX_IPDU   ".$msg_Max_Rx_NUM);
	}

	if($line =~ /Tx Signal ID/){
		print COM_CFG_H $line;
		for(my $i=0; $i< $totol_Txsig_num; $i++){
			putLine(COM_CFG_H, "#define ComSignal_".$arrTxSigDesc[$i]{'sig_name'}."   $i");
		}
		next;
	}

	if($line =~ /Rx Signal ID/){
		print COM_CFG_H $line;
		for(my $i=0; $i< $totol_Rxsig_num; $i++){
			putLine(COM_CFG_H, "#define ComSignal_".$arrRxSigDesc[$i]{'sig_name'}."   $i");
		}
		next;
	}

	if($line =~ /Tx IPdus/){
		print COM_CFG_H $line;
		for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
			putLine(COM_CFG_H, "#define ComConf_ComIPdu_".$arrTxMsgDesc[$i]{'msg_name'}."   $i");
		}
		next;
	}

	if($line =~ /Rx IPdus/){
		print COM_CFG_H $line;
		for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
			putLine(COM_CFG_H, "#define ComConf_ComIPdu_".$arrRxMsgDesc[$i]{'msg_name'}."   $i");
		}
		next;
	}

	if($line =~ /START: I-PDU Buffers/){
		print COM_CFG_H $line;

		putTxIpduBufDesc(COM_CFG_H,'declaration');
		putRxIpduBufDesc(COM_CFG_H, 'declaration');
		next;
	}

	if($line =~ /Com_getfloat64InitValue/){
		print COM_CFG_H $line;
		print COM_CFG_H "\n";

		putRxSigBuffDesc(COM_CFG_H, 'h');
		next;
	}
	

	print COM_CFG_H $line;
}

close(COM_CFG_H);
close(COM_CFG_H_TPL);


#----------------------------------------------------------------------------------------------------------------------------
# Write PduR_cfg.h files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_pdurcfg_h;
$tplTempFile = $tplPath.$tplFilename_pdurcfg_h;

open(PDUR_CFG_H, "> $genTempFile");
open(PDUR_CFG_H_TPL, "< $tplTempFile");


while(<PDUR_CFG_H_TPL>)
{
	my $line = $_;

	if($line =~ /put_PduR_Tx_Msg_SrcDst/){

		for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
			putLine(PDUR_CFG_H, "#define PduRConf_PduRSrcPdu_".$arrTxMsgDesc[$i]{'msg_name'}."_Com2PduR_Src   $i");
			putLine(PDUR_CFG_H, "#define PduRConf_PduRDestPdu_".$arrTxMsgDesc[$i]{'msg_name'}."_PduR2CanIf_Dest   $i");
			putLine(PDUR_CFG_H, "\n");
		}

		next;
	}

	if($line =~ /put_PduR_Rx_Msg_SrcDst/){

		 for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
			putLine(PDUR_CFG_H, "#define PduRConf_PduRSrcPdu_".$arrRxMsgDesc[$i]{'msg_name'}."_CanIf2PduR_Src   $i");
			putLine(PDUR_CFG_H, "#define PduRConf_PduRDestPdu_".$arrRxMsgDesc[$i]{'msg_name'}."_PduR2Com_Dest   $i");
			putLine(PDUR_CFG_H, "\n");
		}
		next;
	}

	print PDUR_CFG_H $line;
}

close(PDUR_CFG_H);
close(PDUR_CFG_H_TPL);


#----------------------------------------------------------------------------------------------------------------------------
# Write PduR_Pbcfg.c files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_pdurpbcfg_c;
$tplTempFile = $tplPath.$tplFilename_pdurpbcfg_c;


open(PDUR_PBCFG_C, "> $genTempFile");
open(PDUR_PBCFG_C_TPL, "< $tplTempFile");

while (<PDUR_PBCFG_C_TPL>) {
	# body...

	my $line = $_;

	if($line =~ /put_PduR_Tx_Msg_Com2CanIf/){

		for(my $i=0; $i< ($msg_Max_Tx_NUM-1); $i++){
			putLine(PDUR_PBCFG_C, "\t{ CanIfConf_CanIfTxPduCfg_".$arrTxMsgDesc[$i]{'msg_name'}.", (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PDUR_IH_CancelTransmitRequest },");

		}
		putLine(PDUR_PBCFG_C, "\t{ CanIfConf_CanIfTxPduCfg_".$arrTxMsgDesc[($msg_Max_Tx_NUM-1)]{'msg_name'}.", (PduR_loTransmitFP)PduR_RF_CanIf_Transmit, (PduR_loCancelTransmitFP)PDUR_IH_CancelTransmitRequest }");
		next;
	}

	if($line =~ /put_PduR_Rx_Msg_CanIf2Com/){
		for(my $i=0; $i< ($msg_Max_Rx_NUM-1); $i++){
			putLine(PDUR_PBCFG_C, "\t{ ComConf_ComIPdu_".$arrRxMsgDesc[$i]{'msg_name'}.",  (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication },");

		}
		putLine(PDUR_PBCFG_C, "\t{ ComConf_ComIPdu_".$arrRxMsgDesc[($msg_Max_Rx_NUM-1)]{'msg_name'}.", (PduR_upIfRxIndicationFP) PduR_RF_Com_RxIndication }");
		next;
	}

	if($line =~ /put_PduR_TxConfirm_CanIf2Com/)
	{
		for(my $i=0; $i< ($msg_Max_Tx_NUM-1); $i++){
			putLine(PDUR_PBCFG_C, "\t{ ComConf_ComIPdu_".$arrTxMsgDesc[$i]{'msg_name'}.", (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation} ,");

		}
		putLine(PDUR_PBCFG_C, "\t{ ComConf_ComIPdu_".$arrTxMsgDesc[($msg_Max_Tx_NUM-1)]{'msg_name'}.", (PduR_upIfTxConfirmationFP) PduR_RF_Com_TxConfirmation}");
		next;
	}

	if($line =~ /CanIf RxToUp NrEntries/)
	{
		$line =~ s/3/$msg_Max_Rx_NUM/g;
	}

	if($line =~ /CanIf TxToUp NrEntries/)
	{
		$line =~ s/3/$msg_Max_Tx_NUM/g;
	}

	if($line =~ /Com/ and $line =~ /PduIdType/)
	{
		$line =~ s/3/$msg_Max_Tx_NUM/g;
	}



	print PDUR_PBCFG_C $line;
}

close(PDUR_PBCFG_C);
close(PDUR_PBCFG_C_TPL);



#----------------------------------------------------------------------------------------------------------------------------
# Write CanIf_cfg.h files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_canifcfg_h;
$tplTempFile = $tplPath.$tplFilename_canifcfg_h;


open(CANIF_CFG_H, "> $genTempFile");
open(CANIF_CFG_H_TPL, "< $tplTempFile");


while(<CANIF_CFG_H_TPL>)
{
	my $line = $_;

	if($line =~ /putNumRxPdus/){
		my $NumRx= $msg_Max_Rx_NUM+5;
		$line =~ s/putNumRxPdus/$NumRx/g;
	}

	if($line =~ /putNumTxPdus/){
		my $NumTx= $msg_Max_Tx_NUM+3;
		$line =~ s/putNumTxPdus/$NumTx/g;
	}

	if($line =~ /putDefineofCanIfTxPdu_Name/){

		for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
			my $Index = $i+3;
			putLine(CANIF_CFG_H, "#define CanIfConf_CanIfTxPduCfg_".$arrTxMsgDesc[$i]{'msg_name'}."\t".$Index);
		}

		next;
	}

	if($line =~ /putRegularCANRxHrhDefinition/){

		 for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
			putLine(CANIF_CFG_H, "#define CanIfConf_CanIfHrhCfg_".$arrRxMsgDesc[$i]{'msg_name'}."   $i");
		}
		next;
	}

	if($line =~ /putCanIfRxPduIndx/){

		 for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
		 	my $Index = $i+5;
			putLine(CANIF_CFG_H, "#define CanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_".$arrRxMsgDesc[$i]{'msg_name'}."\t".$Index);
		}
		next;
	}

	if($line =~ /putUdsHrhcfg/){
		$line =~ s/putUdsHrhcfg/$msg_Max_Rx_NUM/g;
	}

	if($line =~ /putUdsObdHrhcfg/){
		my $hrhUdsObd = ($msg_Max_Rx_NUM+1);
		$line =~ s/putUdsObdHrhcfg/$hrhUdsObd/g;
	}

	if($line =~ /putObdHrhcfg/){
		my $hrhObd = ($msg_Max_Rx_NUM+2);
		$line =~ s/putObdHrhcfg/$hrhObd/g;
	}

	if($line =~ /putXcpRxHrhcfg/){
		my $hrhXcpRx = ($msg_Max_Rx_NUM+3);
		$line =~ s/putXcpRxHrhcfg/$hrhXcpRx/g;
	}

	if($line =~ /putTcProgHrhcfg/){
		my $hrhTcProg = ($msg_Max_Rx_NUM+4);
		$line =~ s/putTcProgHrhcfg/$hrhTcProg/g;
	}

	print CANIF_CFG_H $line;
}

close(CANIF_CFG_H, );
close(CANIF_CFG_H_TPL);


#----------------------------------------------------------------------------------------------------------------------------
# Write CanIf_PBcfg.c files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_canifpbcfg_c;
$tplTempFile = $tplPath.$tplFilename_canifpbcfg_c;

open(CANIF_PBCFG_C, "> $genTempFile");
open(CANIF_PBCFG_C_TPL, "< $tplTempFile");


while(<CANIF_PBCFG_C_TPL>)
{
	my $line = $_;
	my $writeLine;

	if($line =~ /putRegularCANTxPduConfig/){

		for(my $i=0; $i< $msg_Max_Tx_NUM-1; $i++){
            my $CanId_obt = $arrTxMsgDesc[$i]{'msg_Id'};
            my $canId_hex = sprintf("%x", $CanId_obt);
			$writeLine = "{	CanIfConf_CanIfTxPduCfg_".$arrTxMsgDesc[$i]{'msg_name'}.", $i\, CANIF_STATIC,	".$arrTxMsgDesc[$i]{'msg_name'}.",	CANIF_COMM_CAN,	CANIF_STD,	PDUR,	FALSE,    0, 0x".$canId_hex.", ".$arrTxMsgDesc[$i]{'msg_dlc'}."\}\,";
			putLine(CANIF_PBCFG_C, $writeLine);
		}
        
        my $CanId_obt = $arrTxMsgDesc[$msg_Max_Tx_NUM-1]{'msg_Id'};
        my $canId_hex = sprintf("%x", $CanId_obt);
        my $last_msg_targetid = $msg_Max_Tx_NUM-1;
		$writeLine = "{	CanIfConf_CanIfTxPduCfg_".$arrTxMsgDesc[$msg_Max_Tx_NUM-1]{'msg_name'}.", $last_msg_targetid\, CANIF_STATIC,	".$arrTxMsgDesc[$msg_Max_Tx_NUM-1]{'msg_name'}.",	CANIF_COMM_CAN,	CANIF_STD,	PDUR,	FALSE,    0, 0x".$canId_hex.", ".$arrTxMsgDesc[$i]{'msg_dlc'}."\}";
		putLine(CANIF_PBCFG_C, $writeLine);

		next;
	}

	if($line =~ /putRegurlarCANHrhConfig/){

		 for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
		 	my $var = ($i+5);
			putLine(CANIF_PBCFG_C, "{ 	CANIF_FULL 	,		".$var."   ,      1,  CANIF_COMM_CAN,		CANIF_READ_NONE,	".$arrRxMsgDesc[$i]{'msg_Id'}."\},");
		}

		next;
	}

	if($line =~ /putRegularCANRxPduConfig/)
	{
		for(my $i=0; $i< $msg_Max_Rx_NUM-1; $i++){
			putLine(CANIF_PBCFG_C, "\{PduRConf_PduRSrcPdu_".$arrRxMsgDesc[$i]{'msg_name'}."_CanIf2PduR_Src,\t\tCanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_".$arrRxMsgDesc[$i]{'msg_name'}.",\t".$i.",\t0,\tPDUR,\t".$arrRxMsgDesc[$i]{'msg_dlc'}."\},");
		}
		putLine(CANIF_PBCFG_C, "\{PduRConf_PduRSrcPdu_".$arrRxMsgDesc[$msg_Max_Rx_NUM-1]{'msg_name'}."_CanIf2PduR_Src,\t\tCanIfConf_CanIfRxPduCfg_CanIfRxPduCfg_".$arrRxMsgDesc[$msg_Max_Rx_NUM-1]{'msg_name'}.",\t".($msg_Max_Rx_NUM-1).",\t0,\tPDUR,\t".$arrRxMsgDesc[$msg_Max_Rx_NUM-1]{'msg_dlc'}."\}");
		next;
	}

	if($line =~ /putUdsRxPdfHrh/){
		my $Index = $msg_Max_Rx_NUM;
		$line =~ s/putUdsRxPdfHrh/$Index/g;
	}

	if($line =~ /putUdsObdRxPdfHrh/){
		my $Index = $msg_Max_Rx_NUM+1;
		$line =~ s/putUdsObdRxPdfHrh/$Index/g;
	}

	if($line =~ /putObdRxPdfHrh/){
		my $Index = $msg_Max_Rx_NUM+2;
		$line =~ s/putObdRxPdfHrh/$Index/g;
	}

	if($line =~ /putXcpRxPdfHrh/){
		my $Index = $msg_Max_Rx_NUM+3;
		$line =~ s/putXcpRxPdfHrh/$Index/g;
	}

	if($line =~ /putTcProgPdfHrh/){
		my $Index = $msg_Max_Rx_NUM+4;
		$line =~ s/putTcProgPdfHrh/$Index/g;
	}

	print CANIF_PBCFG_C $line;
}

close(CANIF_PBCFG_C);
close(CANIF_PBCFG_C_TPL);

#----------------------------------------------------------------------------------------------------------------------------
# Write Can_cfg.h files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_cancfg_h;
$tplTempFile = $tplPath.$tplFilename_cancfg_h;

open(CAN_CFG_H, "> $genTempFile");
open(CAN_CFG_H_TPL, "< $tplTempFile");


while(<CAN_CFG_H_TPL>)
{
	my $line = $_;

	if($line =~ /putMaxHandles/){

		my $numHandle = $msg_Max_Rx_NUM + $msg_Max_Tx_NUM+8;
		$line =~ s/putMaxHandles/$numHandle/g;

	}

	if($line =~ /putTxMaxHandles/){

		my $numHandle = $msg_Max_Tx_NUM+3;
		$line =~ s/putTxMaxHandles/$numHandle/g;

	}

	if($line =~ /putRxMaxHandles/){

		my $numHandle = $msg_Max_Rx_NUM+5;
		$line =~ s/putRxMaxHandles/$numHandle/g;

	}

	if($line =~ /putNumHandleinNode1/){

		my $numHandle = $msg_Max_Rx_NUM + $msg_Max_Tx_NUM+3;
		$line =~ s/putNumHandleinNode1/$numHandle/g;

	}

	if($line =~ /putCanHwObjTxPolling/){

		for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
			putLine(CAN_CFG_H, "\t".$arrTxMsgDesc[$i]{'msg_name'}."\,")
		}
		next;
	}

	if($line =~ /putCanHwObjRxPolling/){

		for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
			putLine(CAN_CFG_H, "\t".$arrRxMsgDesc[$i]{'msg_name'}."\,")
		}
		next;
	}


	print CAN_CFG_H $line;
}

close(CAN_CFG_H);
close(CAN_CFG_H_TPL);


#----------------------------------------------------------------------------------------------------------------------------
# Write Can_PBCfg.c files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_canpbcfg_c;
$tplTempFile = $tplPath.$tplFilename_canpbcfg_c;


open(CAN_PBCFG_C, "> $genTempFile");
open(CAN_PBCFG_C_TPL, "< $tplTempFile");

my $InteruptCANTx = 3;
my $InteruptCANRx = 5;

while(<CAN_PBCFG_C_TPL>)
{
	my $line = $_;

	if($line =~ /putTxPollingCANDesc/)
	{
		for(my $i=0; $i< $msg_Max_Tx_NUM; $i++){
			my $PollingTxBuffer = $i + $InteruptCANTx;
            my $CanId_obt = $arrTxMsgDesc[$i]{'msg_Id'};
            my $canId_hex = sprintf("%x", $CanId_obt);
			putLine(CAN_PBCFG_C, "\t\{\t\t0x".$canId_hex."\,\t\t\t 0x7FF\t,\t\t".$arrTxMsgDesc[$i]{'msg_name'}.",\t\t".$PollingTxBuffer.",\t\tCOMM_CAN_0,   	 CAN_TX,   	 CAN_STD,\t".$i.",\tTCX_CAN_MCAN_SUPPORT,  		FALSE  },");
		}
		next;
	}

	if($line =~ /putUdsTxCanIfHrh/){
		my $Canifhrh = $msg_Max_Tx_NUM;
		$line =~ s/putUdsTxCanIfHrh/$Canifhrh/g;
 	}

 	if($line =~ /putUdsObdTxCanIfHrh/){
		my $Canifhrh = $msg_Max_Tx_NUM+1;
		$line =~ s/putUdsObdTxCanIfHrh/$Canifhrh/g;
 	}

 	if($line =~ /putXcpTxCanIfHrh/){
		my $Canifhrh = $msg_Max_Tx_NUM+2;
		$line =~ s/putXcpTxCanIfHrh/$Canifhrh/g;
 	}

 	if($line =~ /putRxPollingCANDesc/){

 		for(my $i=0; $i< $msg_Max_Rx_NUM; $i++){
			my $PollingTxBuffer = $i + $InteruptCANTx+$InteruptCANRx+$msg_Max_Tx_NUM;
            my $CanId_obt = $arrRxMsgDesc[$i]{'msg_Id'};
            my $canId_hex = sprintf("%x", $CanId_obt);
			putLine(CAN_PBCFG_C, "\t\{\t\t0x".$canId_hex."\,\t\t\t 0x7FF\t,\t\t".$arrRxMsgDesc[$i]{'msg_name'}.",\t\t".$PollingTxBuffer.",\t\tCOMM_CAN_0,   	 CAN_RX,   	 CAN_STD,\tCanIfConf_CanIfHrhCfg_".$arrRxMsgDesc[$i]{'msg_name'}.",\tTCX_CAN_MCAN_SUPPORT,  		FALSE  },");
		}
		next;
 	}

 	if($line =~ /putUdsRxfun1BufId/){
		my $Canifhrh = $msg_Max_Tx_NUM+$InteruptCANTx;
		$line =~ s/putUdsRxfun1BufId/$Canifhrh/g;
 	}

 	if($line =~ /putUdsObdRxBufId/){
		my $Canifhrh = $msg_Max_Tx_NUM+$InteruptCANTx+1;
		$line =~ s/putUdsObdRxBufId/$Canifhrh/g;
 	}

 	if($line =~ /putObdRxBufId/){
		my $Canifhrh = $msg_Max_Tx_NUM+$InteruptCANTx+2;
		$line =~ s/putObdRxBufId/$Canifhrh/g;
 	}

 	if($line =~ /putXcpRxCmdBufId/){
		my $Canifhrh = $msg_Max_Tx_NUM+$InteruptCANTx+3;
		$line =~ s/putXcpRxCmdBufId/$Canifhrh/g;
 	}

 	if($line =~ /putTcProgBufId/){
		my $Canifhrh = $msg_Max_Tx_NUM+$InteruptCANTx+4;
		$line =~ s/putTcProgBufId/$Canifhrh/g;
 	}


 	if($line =~ /putNumTxHandle/){
		my $Canifhrh = $msg_Max_Tx_NUM+$InteruptCANTx;
		$line =~ s/putNumTxHandle/$Canifhrh/g;
 	}

 	if($line =~ /putNumRxHandle/){
		my $Canifhrh = $msg_Max_Rx_NUM+$InteruptCANRx;
		$line =~ s/putNumRxHandle/$Canifhrh/g;
 	}

 	if($line =~ /putNumTxPollHandle/){
		my $Canifhrh = $msg_Max_Tx_NUM;
		$line =~ s/putNumTxPollHandle/$Canifhrh/g;
 	}

 	if($line =~ /putNumRxPollHandle/){
		my $Canifhrh = $msg_Max_Rx_NUM;
		$line =~ s/putNumRxPollHandle/$Canifhrh/g;
 	}

 	if($line =~ /putNumMCANTxhandle/){
		my $Canifhrh = $msg_Max_Tx_NUM+$InteruptCANTx;
		$line =~ s/putNumMCANTxhandle/$Canifhrh/g;
 	}


	print CAN_PBCFG_C $line;
}

close(CAN_PBCFG_C);
close(CAN_PBCFG_C_TPL);
#----------------------------------------------------------------------------------------------------------------------------
# Write Com_cbk.h files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_comcbk_h;
open(COM_CBK_H, "> $genTempFile");

putLine(COM_CBK_H, "#ifndef _COM_CBK_H");
putLine(COM_CBK_H, "#define _COM_CBK_H");

putLine(COM_CBK_H, "#include \"Compiler_Cfg.h\"");

putLine(COM_CBK_H, "//#define COMCallback(CALLBACKROUTINENAME) FUNC(void,COM_CODE)(CALLBACKROUTINENAME)(void)");

for(my $i=0; $i<$msg_Max_Rx_NUM; $i++ )
{
	putMapStartDesc(COM_CBK_H, 'Com','CODE','ComNotification for Signals');

	putLine(COM_CBK_H, "extern void Com_RxCbk_".$arrRxMsgDesc[$i]{'msg_name'}."(void);");

	putMapEndDesc(COM_CBK_H, 'Com', 'CODE', 'ComNotification for Signals');
	putLine(COM_CBK_H, "\n");
}

for(my $i=0; $i<$msg_Max_Rx_NUM; $i++ )
{
	putMapStartDesc(COM_CBK_H, 'Com','CODE','ComRx timeout for Signals');

	putLine(COM_CBK_H, "extern void Com_RxTimeoutCbk_".$arrRxMsgDesc[$i]{'msg_name'}."(void);");

	putMapEndDesc(COM_CBK_H, 'Com', 'CODE', 'ComRx timeout for Signals');
	putLine(COM_CBK_H, "\n");
}

for(my $i=0; $i<$msg_Max_Tx_NUM; $i++ )
{
	putMapStartDesc(COM_CBK_H, 'Com','CODE','IPDU notification for TX IPDUs');

	putLine(COM_CBK_H, "extern void Com_TxConfirmCbk_".$arrTxMsgDesc[$i]{'msg_name'}."(void);");

	putMapEndDesc(COM_CBK_H, 'Com', 'CODE', 'IPDU notification for TX IPDUs');
	putLine(COM_CBK_H, "\n");
}

putLine(COM_CBK_H, "#endif");

close(COM_CBK_H);

#----------------------------------------------------------------------------------------------------------------------------
# Write Com_cbk_Adap.c files
#----------------------------------------------------------------------------------------------------------------------------
$genTempFile = $genFilePath.$genFilename_comcbkadp_c;

open(COM_CBK_ADAP_C, "> $genTempFile");

putLine(COM_CBK_ADAP_C, "#include \"Com_Cbk.h\"");
putLine(COM_CBK_ADAP_C, "#include \"Com.h\"");

for(my $i=0; $i<$msg_Max_Rx_NUM; $i++ )
{
	putMapStartDesc(COM_CBK_ADAP_C, 'Com','CODE','ComNotification for Signals');

	putLine(COM_CBK_ADAP_C, "void Com_RxCbk_".$arrRxMsgDesc[$i]{'msg_name'}."(void)");

	putLine(COM_CBK_ADAP_C, "\{");
	putLine(COM_CBK_ADAP_C, "\n");
	putLine(COM_CBK_ADAP_C, "\}");

	putMapEndDesc(COM_CBK_ADAP_C, 'Com', 'CODE', 'ComNotification for Signals');
	putLine(COM_CBK_ADAP_C, "\n");
}

for(my $i=0; $i<$msg_Max_Rx_NUM; $i++ )
{
	putMapStartDesc(COM_CBK_ADAP_C, 'Com','CODE','Com Rx timeout for Signals');

	putLine(COM_CBK_ADAP_C, "void Com_RxTimeoutCbk_".$arrRxMsgDesc[$i]{'msg_name'}."(void)");

	putLine(COM_CBK_ADAP_C, "\{");
	putLine(COM_CBK_ADAP_C, "\n");
	putLine(COM_CBK_ADAP_C, "\}");

	putMapEndDesc(COM_CBK_ADAP_C, 'Com', 'CODE', 'ComNotification for Signals');
	putLine(COM_CBK_ADAP_C, "\n");
}

for(my $i=0; $i<$msg_Max_Tx_NUM; $i++ )
{
	putMapStartDesc(COM_CBK_ADAP_C, 'Com','CODE','Com Rx timeout for TX IPDUs');

	putLine(COM_CBK_ADAP_C, "void Com_TxConfirmCbk_".$arrTxMsgDesc[$i]{'msg_name'}."(void)");

	putLine(COM_CBK_ADAP_C, "\{");
	putLine(COM_CBK_ADAP_C, "\n");
	putLine(COM_CBK_ADAP_C, "\}");

	putMapEndDesc(COM_CBK_ADAP_C, 'Com', 'CODE', 'IPDU notification for TX IPDUs');
	putLine(COM_CBK_ADAP_C, "\n");
}

close(COM_CBK_ADAP_C);
