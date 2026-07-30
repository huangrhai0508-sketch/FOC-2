%% Guideline
% Update c h files according to GPIST and GPOST. 5 files updated.
% the folder structure in xfiles must exist first.
% GPIST and GPOST are defined in the xFile
% tcx_IoSigDio_Cfg.h
% tcx_IoSigDio_PBcfg.c
% tcx_IoMcuDio_Cfg.h
% Dio_PBcfg.c
% Dio_cfg.h

%% csv file handle
if ~(exist('GPIST','var')==1) ||  ~(exist('GPOST','var')==1)
    DefineBusFrmHsi;
end

tmp = strfind(hsiFile,'\');
xFile = [hsiFile(1:tmp(length(tmp))-1),'\hsiGenBus.xlsx'];       
clear tmp

strtMark='/*@ START MARK FOR MFILE@*/';
stpMark='/*@ STOP MARK FOR MFILE@*/';
gpiCnts = length(GPIST.Elements);
gpoCnts = length(GPOST.Elements);
gpiName = {GPIST.Elements.Name};
gpoName = {GPOST.Elements.Name};
mFile = mfilename('fullpath');
xfiles = {  [prjRoot '\0_Src\3_Bsw\IoSrv\tcx_IoSigDio\tcx_IoSigDio_Cfg.h'],...
            [prjRoot '\0_Src\3_Bsw\IoSrv\tcx_IoSigDio\tcx_IoSigDio_PBcfg.c'],...
            [prjRoot '\0_Src\3_Bsw\Mcal\tcx_IoMcuDio\tcx_IoMcuDio_Cfg.h'],...
            [prjRoot '\0_Src\3_Bsw\Mcal\Dio\Dio_PBcfg.c'],...
            [prjRoot '\0_Src\3_Bsw\Mcal\Dio\Dio_cfg.h']
            };

    %% tcx_IoSigDio_Cfg.h
    xfile = xfiles{1};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
   
    txtNow = [];
    txtLine = ['#define TCX_IOSIGDIO_CFG_NUM_SIGNALS      (',num2str(gpiCnts+gpoCnts),')'];
    txtNow = [txtNow,newline,txtLine,newline,newline,'// Signal IDs'];
    
    for i = 1:1:gpiCnts
        txtLine = ['#define tcx_IoSigDioConf_tcx_IoSigDio_Signal_DI_',gpiName{i},'      (',num2str(i-1),')'];
        txtNow = [txtNow newline txtLine];
    end
    
    for i=1:1:gpoCnts
        txtLine = ['#define tcx_IoSigDioConf_tcx_IoSigDio_Signal_DO_',gpoName{i},'      (',num2str(i-1+gpiCnts),')'];
        txtNow = [txtNow newline txtLine];
    end
    
    txtNew = replace(txtOld,txtKey,txtNow);
    
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% tcx_IoSigDio_PBcfg.c
    xfile = xfiles{2};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
    
    
    txtNow = [];
    for i = 1:1:gpiCnts
        txtLine = ['    {'                                                                  ,newline,...
                   '        tcx_IoMcuDioConf_tcx_IoMcuDio_SignalDio_DI_',gpiName{i},','     ,newline,...
                   '        TCX_IOSIGDIO_CFG_DEVICE_TYPE_DIO,'                              ,newline,...
                   '        FALSE '                                                         ,newline,...
                   '    },'];
        txtNow = [txtNow newline txtLine];
    end
    
    for i=1:1:gpoCnts
        txtLine = ['    {'                                                                  ,newline,...
                   '        tcx_IoMcuDioConf_tcx_IoMcuDio_SignalDio_DO_',gpoName{i},','     ,newline,...
                   '        TCX_IOSIGDIO_CFG_DEVICE_TYPE_DIO,'                              ,newline,...
                   '        FALSE '                                                         ,newline,...
                   '    },'];
        txtNow = [txtNow newline txtLine];
    end
    
    txtNow = txtNow(1:length(txtNow)-1); %delete the last ,
    

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% tcx_IoMcuDio_Cfg.h
    xfile = xfiles{3};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
       

    txtNow = [];
    txtLine = ['#define TCX_IOMCUDIO_NR_OF_DIO_CHANNELS     (',num2str(gpiCnts+gpoCnts),')'];
    txtNow = [txtNow,newline,txtLine,newline];
    for i = 1:1:gpiCnts
        %#define tcx_IoMcuDioConf_tcx_IoMcuDio_SignalDio_DI_NFFLTH            DioConf_DioChannel_DI_NFFLTH
        txtLine = ['#define tcx_IoMcuDioConf_tcx_IoMcuDio_SignalDio_DI_',gpiName{i},...
                    '    DioConf_DioChannel_DI_',gpiName{i}];
        txtNow = [txtNow newline txtLine];
    end
    
    for i=1:1:gpoCnts
        txtLine = ['#define tcx_IoMcuDioConf_tcx_IoMcuDio_SignalDio_DO_',gpoName{i},...
                    '    DioConf_DioChannel_DO_',gpoName{i}];
        txtNow = [txtNow newline txtLine];
    end
    
    txtNow = [txtNow,newline,newline];

    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% Dio_PBcfg.c
    % get the port index first
    xfile = xfiles{4};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
    
    % get the port index first
    xTbl = readtable(xFile,'sheet','BusDefinition');
    rows = strcmp(xTbl.SimulinkBusName,'GPIST') | strcmp(xTbl.SimulinkBusName,'GPOST');
    gpiostTbl = xTbl(rows,{'BusElementName','ucPort'});
    gpioCnts = height(gpiostTbl);
    gpioName = gpiostTbl.BusElementName;
    gpioPortPin = gpiostTbl.ucPort;
    tmp = split(gpioPortPin,'.'); % split Pxx.yy into Pxx and yy
    gpioPort = tmp(:,1);          %Pxx  
    gpioPin = tmp(:,2);           %yy
    gpioPorts=unique(gpioPort);   % delete the repeated elements, get the ports array
    [tmp, gpioPort] = ismember(gpioPort,gpioPorts); %get the port position in the ports array
    gpioPort=gpioPort-1;    % array base is zero

    clear xTbl gpiostTbl rows tmp
    %

    txtNow = [];

    for i = 1:1:gpioCnts
        %    {   0,    0}, /* NFFLTH_DI                         Port: 00 Pin: 00 */
        txtLine = ['    { ',num2str(gpioPort(i)),',  ',gpioPin{i}, '}, /* ',gpioName{i},'    ',gpioPortPin{i}, '*/'];
        txtNow = [txtNow newline txtLine];
    end
    
    txtNow = [txtNow,newline,'};',newline,newline];
    txtLine = ['uint32* const Dio_PortInfo_acpu32[',num2str(length(gpioPorts)),'] = {'];
    txtNow = [txtNow,newline,txtLine];
    for i=1:1:length(gpioPorts)
        %txtLine = sprintf('    (uint32*) &P%02d, /*Index %02d*/',portGrp(i),i-1);
        txtLine = ['    (uint32*) &', gpioPorts{i},',     /*Index ',num2str(i-1),'    */'];
        txtNow = [txtNow newline txtLine];
    end


    txtNew = replace(txtOld,txtKey,txtNow);

    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);

    %% Dio_cfg.h
    xfile = xfiles{5};
    tplfile = split(xfile,'\');
    tplfile = tplfile{length(tplfile)};
    tplfile = [tplfile,'tpl'];
    txtKey = ['@',replace(tplfile,'.','_'),'@'];
    tplfile = [mdlRoot '\utilities\PortCfg\hsiTpl\',tplfile];
    
    txtOld = fileread(tplfile);
    
    
    txtNow = [];
    txtLine = ['#define DIO_NUMBER_OF_SIGNALS     (',num2str(gpiCnts+gpoCnts),')'];
    txtNow = [txtNow,newline,txtLine,newline,newline,'/* Dio ChannelIds */'];
    
    for i = 1:1:gpiCnts
        txtLine = ['#define DioConf_DioChannel_DI_',gpiName{i},'      (',num2str(i-1),')'];
        txtNow = [txtNow newline txtLine];
    end
    
    for i=1:1:gpoCnts
        txtLine = ['#define DioConf_DioChannel_DO_',gpoName{i},'      (',num2str(i-1+gpiCnts),')'];
        txtNow = [txtNow newline txtLine];
    end
    
    txtNow = [txtNow,newline,newline];
    txtLine = ['extern uint32* const        Dio_PortInfo_acpu32[',num2str(length(gpioPorts)),'];'];
    txtNow = [txtNow,newline,txtLine,newline];
    
    txtNew = replace(txtOld,txtKey,txtNow);
    fileId = fopen(xfile,'w');
    fprintf(fileId,'%s',txtNew);
    fclose(fileId);



%% clear

clear tmp_BusName tmp_Bus nodeNameTmp comment commentColumn
clear  ndata text alldata n m i j len
clear funcColumn nameColumn channel func name sig pinColumn
clear fun func name nameColumn dir dirColumn
clear varDef markDef funDef grpIdx groupChs newStr
clear txtAfter txtBefore txtNew txtOld  txtNow txtLine enumText
clear pos posadd rteFile fileId   GPI GPO xfile xfiles
clear tmpdir gpiCnts gpoCnts gpiComments gpoComments
clear a b mfile pin port pos1 pos2 portpin tmp portGrp portIdx
clear gpiPin gpiName 
clear gpoPin gpoName
clear strtMark stpMark
clear mFile xFile
clear gpioPort gpioPin gpioPorts gpioPortPin gpioCnts gpioName

