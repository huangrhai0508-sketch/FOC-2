%% Guideline
% Update c h files according to VADCST, VADC1ST and VADC2ST. 
% the folder structure in xfiles must exist first.
% 7 files updated.
% Adc_Cfg.h
% Adc_PBCfg.c
% tcx_IoSigAdc_Cfg.h
% tcx_IoSigAdc_Cfg.c
% tcx_IoSigAdc_PBcfg.c
% tcx_IoMcuAdc_PBcfg.h
% tcx_IoMcuAdc_PBcfg.c


%% csv file handle
if ~(exist('VADCST','var')==1)
    DefineBusFrmHsi;
end

tmp = strfind(hsiFile,'\');
xFile = [hsiFile(1:tmp(length(tmp))-1),'\hsiGenBus.xlsx'];       
clear tmp

strtMark='/*@ START MARK FOR MFILE@*/';
stpMark='/*@ STOP MARK FOR MFILE@*/';

xfiles = {	[prjRoot '\0_Src\3_Bsw\Mcal\Adc\Adc_Cfg.h'] ,...
			[prjRoot '\0_Src\3_Bsw\Mcal\Adc\Adc_PBCfg.c'],...
			[prjRoot '\0_Src\3_Bsw\IoSrv\tcx_IoSigAdc\tcx_IoSigAdc_Cfg.h'],...
			[prjRoot '\0_Src\3_Bsw\IoSrv\tcx_IoSigAdc\tcx_IoSigAdc_Cfg.c'],...
			[prjRoot '\0_Src\3_Bsw\IoSrv\tcx_IoSigAdc\tcx_IoSigAdc_PBcfg.c'],...
			[prjRoot '\0_Src\3_Bsw\Mcal\tcx_IoMcuAdc\tcx_IoMcuAdc_PBcfg.h'],...
			[prjRoot '\0_Src\3_Bsw\Mcal\tcx_IoMcuAdc\tcx_IoMcuAdc_PBcfg.c']
    };
mFile = mfilename('fullpath');
%% vadc group info
 % get the port index first
    xTbl = readtable(xFile,'sheet','BusDefinition');
    rows = strcmp(xTbl.SimulinkBusName,'VADCST');
    vadcstTbl = xTbl(rows,{'BusElementName','ucPort'});
    vadcCnts = height(vadcstTbl);
    vadcName = vadcstTbl.BusElementName;
    vadcPortPin = vadcstTbl.ucPort;
    vadcPortPin = char(replace(vadcPortPin,'AN',''));
    vadcPortPin = str2num(vadcPortPin);
    vadcGrp = floor(vadcPortPin/8);
    vadcCh = mod(vadcPortPin, 8);
    [vadcChs,vadcGrps] = hist(vadcGrp, unique(vadcGrp));    % vadcChs channel numbers in each group
                                                            % vadcGrps groups index used 


    
     %% Adc_Cfg.h
	 
	xfile = xfiles{1};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
   
    txtNow = [];
	txtLine = ['typedef enum'];
    txtNow = [txtNow,newline,txtLine,newline,'{'];
    
    for i = 1:1:vadcCnts
        txtLine = ['    Adc_',vadcName{i},'_AIN,'];
        txtNow = [txtNow newline txtLine];
    end
    
    txtNow = [txtNow, newline, '    ADC_CFG_LAST_SIGNAL_NUMBER',          newline,...
                '} Adc_Cfg_SignalNumber_ten;'];
            
    for i=1:1:length(vadcGrps)
        txtTmp = sprintf('#define Adc_AdcGroup_Id%d    ((uint16)%d)',vadcGrps(i),vadcGrps(i));
        txtNow = [txtNow,newline, txtTmp];
    end
    
    txtNow = [txtNow newline newline '#define ADC_MAX_GROUPS    ((uint16)',num2str(length(vadcGrps)),')'];
    txtNow = [txtNow newline '#define ADC_PRV_MAX_UNIT_ENTRIES    ((uint16)',num2str(length(vadcGrps)),')'];
    txtNow = [txtNow newline '#define ADC_PRV_MAX_GROUP_ENTRIES    ((uint16)',num2str(length(vadcGrps)),')'];
    txtNow = [txtNow newline '#define ADC_PRV_MAX_EMUX_ENTRIES    ((uint16)',num2str(0),')',newline,newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);
    
     %% Adc_PBCfg.c
    xfile = xfiles{2};
	tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
   
    txtNow = [];
	
	
	txtLine = ['static const Adc_Cfg_SignalEntry_tst Adc_SignalIndex_INVGEN2_pcst[ADC_CFG_LAST_SIGNAL_NUMBER] =', newline, '{'];
    txtNow = [txtNow,newline,txtLine];
    for i = 1:1:vadcCnts
        %  {          ADC_TC_HW_UNIT0,     0,   ADC_CH4,      (Adc_ValueGroupType*)((uint32)(&VADC.UNIT[ADC_TC_HW_UNIT0].GxRES[4])),}, /* RSV_SINHI_AIN */
        txtLine = sprintf('  { ADC_TC_HW_UNIT%d,  %d,   ADC_CH%d,  (Adc_ValueGroupType*)((uint32)(&VADC.UNIT[ADC_TC_HW_UNIT%d].GxRES[%d])),}, /* %s */',...
                            vadcGrp(i),vadcGrp(i),vadcCh(i),vadcGrp(i),vadcCh(i),vadcName{i});
        txtNow = [txtNow newline txtLine];
    end
    
    txtNow = [txtNow, newline, '};'];
    txtNow = [txtNow, newline , '#define TCX_ADC_STOP_SECTION_CONST_32',newline,'#include "Adc_MemMap.h"'];
    txtNow = [txtNow, newline , newline, '#define Adc_Cfg_ExtMuxConfigNum_',prjName,'    (0)'];
    
    for i = 1:1:length(vadcGrps)
        txtLine = sprintf('#define Adc_Cfg_AdcGroup_Id%d_ChnNum_%s    (%d)',vadcGrps(i),prjName,vadcChs(i));
        txtNow = [txtNow, newline, txtLine];
    end
    
    for i = 1:1:length(vadcGrps)
        txtLine = sprintf('#define Adc_HwU%d_GrpNum_%s    (1)',vadcGrps(i),prjName);
        txtNow = [txtNow, newline, txtLine];
    end

    txtNow = [txtNow, newline ,newline, '#define TCX_ADC_START_SECTION_CONST_32',newline,'#include "Adc_MemMap.h"'];
    for i = 1:1:length(vadcGrps)
        txtLine = sprintf('static const Adc_GroupType Adc_Cfg_Unit%d_GroupList_%s_aen[] ={%d};',vadcGrps(i),prjName,vadcGrps(i));
        txtNow = [txtNow, newline, txtLine];
    end
    txtNow = [txtNow, newline ,newline, '#define TCX_ADC_STOP_SECTION_CONST_32',newline,'#include "Adc_MemMap.h"',newline];

    for i = 1:1:length(vadcGrps)
        txtLine = sprintf('#define Adc_Cfg_UnitConfigType_AdcHwUnitId_%d_%s_st  {Adc_Cfg_Unit%d_GroupList_%s_aen,ADC_TC_HW_UNIT%d}',...
                            vadcGrps(i),prjName,vadcGrps(i),prjName,vadcGrps(i));
        txtNow = [txtNow, newline, txtLine];
    end

    txtNow = [txtNow, newline ,newline, '#define TCX_ADC_START_SECTION_CONST_32',newline,'#include "Adc_MemMap.h"'];
    txtNow = [txtNow,newline,'static const Adc_Cfg_UnitConfigType Adc_Cfg_UnitConfigType_INVGEN2_ast[] =',newline,'{'];
    for i = 1:1:length(vadcGrps)
        txtLine = sprintf('    Adc_Cfg_UnitConfigType_AdcHwUnitId_%d_%s_st,',vadcGrps(i),prjName);
        txtNow = [txtNow, newline, txtLine];
    end
    txtNow = [txtNow, newline,'};'];
    txtNow = [txtNow, newline , '#define TCX_ADC_STOP_SECTION_CONST_32',newline,'#include "Adc_MemMap.h"',newline];

    grpCfgFmt = ['#define Adc_Tc_GroupConfig_AdcGroup_Id%d_%s_st \\','\n', ...
    '{ \\','\n',...
    '    %d,                                            /* number of used ports */ \\', '\n',...
    '    {0x00%x,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,} ,/* channel list */ \\', '\n',...
    '    ADC_PRV_RESOLUTION_12BIT,                     /* resolution */ \\', '\n',...
    '    ADC_TRIGG_SRC_HW,                             /* trigger source */ \\', '\n',...
    '    ADC_HW_TRIG_RISING_EDGE,                      /* trigger type */ \\', '\n',...
    '    %d,                                            /* logical HW Id */ \\', '\n',...
    '    &Adc_Cfg_UnitConfigType_%s_ast[%d],       /* physical HW Id */ \\', '\n',...
    '    ADC_PRV_PRIORITY_HIGH,                        /* group priority */ \\', '\n',...
    '    ADC_PRIORITY_NONE,                            /* priority implementation */ \\', '\n',...
    '    ADC_GROUP_REPL_ABORT_RESTART,                 /* replacement mode */ \\', '\n',...
    '    ADC_ACCESS_MODE_SINGLE,                       /* access mode */ \\', '\n',...
    '    ADC_CONV_MODE_ONESHOT,                        /* conversion mode */ \\', '\n',...
    '    ADC_STREAM_BUFFER_LINEAR,                     /* buffer mode */ \\', '\n',...
    '    1,                                            /* number of conversions */ \\', '\n',...
    '    ADC_PRV_GROUP_GATE_EMPTY,                     /* gate signal */ \\', '\n',...
    '    ADC_PRV_GROUP_TRIG0,                          /* trigger line */ \\', '\n',...
    '    NULL_PTR,                                     /* multiplexer configuration */ \\', '\n',...
    '	 NULL_PTR,            /*&tcx_IoMcuCB_AdcGroup_Id0_INV5 Callback */ \\', '\n',...
    '    0x00%x,                                       /* Bitmask for direct accessed channels */ \\', '\n',...
    '    0x0000,                                       /* Bitmask for DMA handled channels */ \\', '\n',...
    '    TCX_DMA_NUM_IDS_E,                            /* Shortname of DMA */ \\', '\n',...
    '}','\n'];
    for i=1:1:length(vadcGrps)
        grp =vadcGrps(i);
        chList = (eq(grp, vadcGrp'))*(2.^vadcCh);
        txtLine = sprintf(grpCfgFmt,vadcGrps(i),prjName,vadcChs(i),chList,vadcGrps(i),prjName,vadcGrps(i),chList);
        txtNow = [txtNow,newline,txtLine];
    end

    txtNow = [txtNow, newline ,newline, '#define TCX_ADC_START_SECTION_CONST_32',newline,'#include "Adc_MemMap.h"'];
    txtNow = [txtNow,newline,'static const Adc_Cfg_GroupConfigType Adc_Tc_GroupConfig_INVGEN2_ast[] =',newline,'{'];
    for i = 1:1:length(vadcGrps)
        txtLine = sprintf('    Adc_Tc_GroupConfig_AdcGroup_Id%d_%s_st,',vadcGrps(i),prjName);
        txtNow = [txtNow, newline, txtLine];
    end
    txtNow = [txtNow, newline,'};'];
    txtNow = [txtNow, newline , '#define TCX_ADC_STOP_SECTION_CONST_32',newline,'#include "Adc_MemMap.h"',newline,newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% tcx_IoSigAdc_Cfg.h
    xfile = xfiles{3};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
   
    txtNow = [];
    txtLine = ['#define TCX_IOSIGADC_CFG_NR_SIGNALS    (',num2str(vadcCnts),')'];
    txtNow = [txtNow newline txtLine];
    for i = 1:1:vadcCnts
        %#define tcx_IoSigAdcConf_tcx_IoSigAdc_Signal_ADCTEST_AIN                    0
        txtLine = sprintf('#define tcx_IoSigAdcConf_tcx_IoSigAdc_Signal_%s_AIN (%d)',vadcName{i},i-1);
        txtNow = [txtNow newline txtLine];
    end
    txtNow = [txtNow,newline,newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% tcx_IoSigAdc_Cfg.c
	xfile = xfiles{4};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
    
    txtNow = [];

    for i = 1:1:vadcCnts
        txtLine = ['    {           25000,        13107,          65536,        13107,         0,        0,        12     },'];
        txtNow = [txtNow newline txtLine];
    end
    txtNow = [txtNow,newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% tcx_IoSigAdc_PBcfg.c
	xfile = xfiles{5};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
    
    txtNow = [];

    for i = 1:1:vadcCnts
        txtLine = sprintf('    {tcx_IoMcuAdcConf_tcx_IoMcuAdc_SignalAdc_%s_AIN,TCX_IOSIGADC_CFG_DEVICE_TYPE_ADC},', vadcName{i});
        txtNow = [txtNow newline txtLine];
    end
    txtNow = [txtNow(1:length(txtNow)-1),newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% tcx_IoMcuAdc_PBcfg.h
    xfile = xfiles{6};
	tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
    
    txtNow = [];
    for i = 1:1:vadcCnts
        %#define tcx_IoSigAdcConf_tcx_IoSigAdc_Signal_ADCTEST_AIN                    0
        txtLine = sprintf('#define tcx_IoMcuAdcConf_tcx_IoMcuAdc_SignalAdc_%s_AIN    (%d)',vadcName{i},i-1);
        txtNow = [txtNow newline txtLine];
    end
    %tcx_IoMcuAdc_noof_Channel
    txtNow = [txtNow,newline,'#define tcx_IoMcuAdc_noof_Channel (',num2str(vadcCnts),')'];
    %tcx_IoMcuAdc_noof_Trigger
    txtNow = [txtNow,newline,'#define tcx_IoMcuAdc_noof_Trigger (',num2str(length(vadcGrps)),')'];

    txtNow = [txtNow,newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% tcx_IoMcuAdc_PBcfg.c
    xfile = xfiles{7};
	tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
    
    txtNow = [];
    txtLine = ['#define  TCX_IOMCUADC_START_SECTION_VAR_INIT_UNSPECIFIED',newline,'#include TCX_IOMCUADC_MEMMAP_H'];
    txtNow = [txtNow,newline,txtLine];
    txtLine = sprintf('tcx_IoMcuAdc_ValueGroupType_tu16* GroupRamIndex_INVGEN2[%d] = \n{',length(vadcGrps));
    txtNow = [txtNow,newline,txtLine];
    chsAdd = 0;
    for i = 1:1:length(vadcGrps)
        chs = vadcChs(i);
        txtLine = sprintf('    &tcx_IoMcuAdc_rambuffer[%d],',chsAdd);
        txtNow = [txtNow newline txtLine];
        chsAdd = chsAdd + chs;
    end
    txtNow = [txtNow,newline,'};',newline,'#define  TCX_IOMCUADC_STOP_SECTION_VAR_INIT_UNSPECIFIED',newline,'#include TCX_IOMCUADC_MEMMAP_H'];
    txtNow = [txtNow,newline,newline,'#define  TCX_IOMCUADC_START_SECTION_VAR_INIT_UNSPECIFIED',newline,'#include TCX_IOMCUADC_MEMMAP_H'];
    txtNow = [txtNow,newline,'static tcx_IoMcuAdc_SigGrpConfig_tst tcx_IoMcuAdc_ConfigSet_INVGEN2SigGrpDescs_ast[] ='];
    txtNow = [txtNow,newline,'{ // GroupId, Resolution,RAM buffer locatoin, ID,Accessmode'];
    for i = 1:1:vadcCnts
        %#define tcx_IoSigAdcConf_tcx_IoSigAdc_Signal_ADCTEST_AIN                    0
        txtLine = sprintf('   {%d,  12,  &tcx_IoMcuAdc_rambuffer[%d],  Adc_%s_AIN,  tcx_IoMcuAdc_Directregister_mode},',...
                            vadcGrp(i),i-1,vadcName{i});

        txtNow = [txtNow newline txtLine];
    end
    txtNow = [txtNow,newline,'};',newline,'#define  TCX_IOMCUADC_STOP_SECTION_VAR_INIT_UNSPECIFIED',newline,'#include TCX_IOMCUADC_MEMMAP_H'];
    txtNow = [txtNow,newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);
    
  
    

    
%% clear
clear vadcCh vadcGrp vadcChs vadcGrps vadcCnts
clear vadcName vadcPortPin vadcstTbl rows
clear xfile xfiles txtKey
clear i txtOld txtNow txtAfter txtBefore txtNew txtTmp
clear chs chsAdd chlist fileId grp grpCfgFmt
clear mFile pos1 pos2 stpMark strtMark txtLine






