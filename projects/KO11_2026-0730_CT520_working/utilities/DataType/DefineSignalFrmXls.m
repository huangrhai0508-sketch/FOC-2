%% Guideline
% all the global variables are stored in globalVariable.c with const volatile
% qualifier. 
% Post process is necessary to add other qualifier if Ax address
% used.

%% Load simulink signals
clear ndata;
clear text;
clear alldata;
[ndata, text, alldata] = xlsread('ParameterGenerator.xlsx','SignalDefinition');
[n,m] = size(alldata);

for i = 2:1:n
    sigName = char(alldata(i,1));
    eval([sigName, '=Simulink.Signal;']);
    Para = char(alldata(i,3));
    eval([sigName, '.DataType=Para;']);
    Para = char(alldata(i,4));
    eval([sigName, '.Complexity=Para;']);
    Para = cell2mat(alldata(i,5));
    eval([sigName, '.Dimensions=Para;']);
    Para = char(alldata(i,6));
    eval([sigName, '.DimensionsMode=Para;']);
    Para = cell2mat(alldata(i,7));
    eval([sigName, '.SampleTime=Para;']);
    Para = char(alldata(i,8));
    eval([sigName, '.SamplingMode=Para;']);
    Para = cell2mat(alldata(i,9));
    
    if ischar(Para)
        Para=[];
    end
    
    eval([sigName, '.Min=Para;']);
    Para = cell2mat(alldata(i,10));
    
    if ischar(Para)
        Para=[];
    end
    
    eval([sigName, '.Max=Para;']);
    %Para = mat2str(cell2mat(alldata(i,11)));
    Para = (cell2mat(alldata(i,11)));
    if isnumeric(Para)
        Para=mat2str(Para);
        eval([sigName, '.InitialValue=Para;']);
    end

    Para = cell2mat(alldata(i,12));
    if isequal(Para,NaN)
        Para='';
    else
        Para = char(Para);
    end
    
    eval([sigName, '.Unit=Para;']);
    Para = cell2mat(alldata(i,13));
    
    if strcmp(Para,'ExportedGlobal')
        eval([sigName, '.CoderInfo.StorageClass=''Custom'';']);
        eval([sigName, '.CoderInfo.CustomStorageClass=''ExportToFile'';']);
        %eval([sigName, '.CoderInfo.CustomAttributes.HeaderFile=''globalVariable.h'';']);
        %eval([sigName, '.CoderInfo.CustomAttributes.DefinitionFile=''globalVariable.c'';']);
    else
        eval([sigName, '.CoderInfo.StorageClass=Para;']);
        %eval([sigName, '.CoderInfo.CustomStorageClass=Para;']);
    end    
    Para = char(alldata(i,14));
    eval([sigName, '.Description=Para;']);
    %disp([SignalName ' is defined']);
    clear sigName;
end

clear i;
clear j;
clear n;
clear m;
clear alldata;
clear ndata;
clear Para;
clear text;
