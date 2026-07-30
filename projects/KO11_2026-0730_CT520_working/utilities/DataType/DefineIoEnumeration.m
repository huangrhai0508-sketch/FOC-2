%% Guideline
% define EGPI and EGPO enumeration 
% define EVADC enumeration, including all the adc channels

%% file handle
if ~(exist('hsiFile','var')==1)
    a1DefineProjectEnv;
end

tmp = strfind(hsiFile,'\');
xFile = [hsiFile(1:tmp(length(tmp))-1),'\hsiGenBus.xlsx'];       
clear tmp


%% read the xFile
parTbl = readtable(xFile,'sheet','BusDefinition');
rows = strcmp(parTbl.SimulinkBusName,'VADCST');
vadc0stTbl = parTbl(rows,:);
rows = strcmp(parTbl.SimulinkBusName,'GPIST');
gpistTbl = parTbl(rows,:);
rows = strcmp(parTbl.SimulinkBusName,'GPOST');
gpostTbl = parTbl(rows,:);

%% Generate the EGPI enumeration
clear EGPI
xName = gpistTbl.BusElementName;
xValue = (1:height(gpistTbl))-1;  % init value start from 0
Simulink.defineIntEnumType('EGPI',xName,xValue,'HeaderFile','Rte_Type.h', 'DataScope','Auto');

%% Generate the EGPO enumeration
clear EGPO
xName = gpostTbl.BusElementName;
xValue = (1:height(gpostTbl)) + height(gpistTbl)-1;   %init value start from GPI element counter
Simulink.defineIntEnumType('EGPO',xName,xValue,'HeaderFile','Rte_Type.h', 'DataScope','Auto');


%% Generate the EVADC1 enumeration
clear EVADC
xName = vadc0stTbl.BusElementName;
xValue = (1:height(vadc0stTbl))-1;   
Simulink.defineIntEnumType('EVADC',xName,xValue,'HeaderFile','Rte_Type.h', 'DataScope','Auto');



%% clear
clear parTbl gpistTbl gpostTbl vadc0stTbl vadc1stTbl vadc2stTbl
clear rows xName xValue

