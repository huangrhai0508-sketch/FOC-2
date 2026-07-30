%% Guideline
% all the parameters are stored in parameter.c with const volatile
% qualifier. 
% Post process is necessary to add other qualifier if Ax address
% used.


%% Load parameters for model
clear ndata;
clear text;
clear alldata;
[ndata, text, alldata] = xlsread('ParameterGenerator.xlsx','ParameterDefinition');
[n,m] = size(alldata);

for i = 2:1:n
    ParameterName = char(alldata(i,1));        % colunm 1  parameter name
    eval([ParameterName, '=Simulink.Parameter;']);
    
    Para = char(alldata(i,4));                  % shall define the type first
    eval([ParameterName, '.DataType=Para;']);
    
    Para = cell2mat(alldata(i,3));              %column 3 parameter value, can be a numeric , string, array.
    if isnumeric(Para)
        Para = num2str(Para);
    end
    eval([ParameterName, '.Value=',Para,';'])
  
    Para = cell2mat(alldata(i,5));
    if ischar(Para)
        Para=[];
    end
    
    eval([ParameterName, '.Min=Para;']);
    Para = cell2mat(alldata(i,6));
    if ischar(Para)
        Para=[];
    end
    
    eval([ParameterName, '.Max=Para;']);
    Para = char(alldata(i,7));
    eval([ParameterName, '.Unit=Para;']);
    eval([ParameterName, '.CoderInfo.StorageClass=''Custom'';']);
    eval([ParameterName, '.CoderInfo.CustomStorageClass=''ConstVolatile'';']);
    eval([ParameterName, '.CoderInfo.CustomAttributes.HeaderFile=''parameter.h'';']);
    eval([ParameterName, '.CoderInfo.CustomAttributes.DefinitionFile=''parameter.c'';']);
    Para = char(alldata(i,12));
    %eval([ParameterName, '.Description=Para;']);
    %disp([ParameterName ' is defined']);
    clear ParameterName;
end

%% clear
clear Para ParameterName
clear n m ndata text alldata;
