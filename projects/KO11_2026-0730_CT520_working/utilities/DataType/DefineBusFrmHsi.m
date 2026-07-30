
%% Guideline
% Read hsiGenBus xls file and generate bus structure:   VADCST  GPIST GPOST


%% Load parameters for model
if ~((exist('hsiFile','var')==1)) 
    a1DefineProjectEnv;
end

tmp = strfind(hsiFile,'\');
xFile = [hsiFile(1:tmp(length(tmp))-1),'\hsiGenBus.xlsx'];       
clear tmp

%%
busTbl = readtable(xFile,'sheet','BusDefinition');
busTbl = sortrows(busTbl,2); % sort on the second column
elemCnts = height(busTbl);
oldBusName = busTbl.SimulinkBusName{1};
j=1;
for i=1:1:elemCnts
    busName = busTbl.SimulinkBusName{i};
    if ~isequal(busName,oldBusName) % a new bus start
        clear tmp
        tmp = Simulink.Bus;
        
        tmp.Description = '';
        tmp.DataScope = 'Auto';
        tmp.Alignment = -1;
        tmp.Elements = elems;
        clear elems
        assignin('base',oldBusName,tmp);  
        j=1;
        clear elems;
    end
    % get the bus elements
    elems(j) = Simulink.BusElement;
    elems(j).Name = busTbl.BusElementName{i};
    elems(j).Dimensions = 1;
    elems(j).DimensionsMode = 'Fixed';
    elems(j).DataType = busTbl.DataType{i};
    elems(j).SampleTime = -1;
    elems(j).Complexity = 'real';
    elems(j).Min = [];
    elems(j).Max = [];
    elems(j).DocUnits = '';
    elems(j).Description = '';
    oldBusName = busName;  
    j = j+1;
end

clear tmp
tmp = Simulink.Bus;

tmp.Description = '';
tmp.DataScope = 'Auto';
tmp.Alignment = -1;
tmp.Elements = elems;
clear elems
assignin('base',oldBusName,tmp);

%% clear
clear alldata n m busTbl i j tmp text ndata oldBusName busName elemCnts xFile
    
    
    





