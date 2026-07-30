%% Guideline
% Read the bus and generate the XXXMdl_C and XXXOvrd_C for the simulink signal definition.
% GPIST supported
% GPOST supported
% VADC0ST supported
% CDDHwMgrST supported.  as TDBC1 TDBC2 TDBC3 are located in this ST.

%% file handle
% if (~exist('GPOST','var')==1)   || ...
%    (~exist('GPIST','var')==1)   || ...
%    (~exist('VADCST','var')==1)   || ...
%    (~exist('CDDHwMgrST','var')==1) 
%     
%     DefineBusFrmDbc;
%     DefineBusFrmXls;
%     DefineBusFrmCdd;
%     DefineBusFrmHsi;
% end

% buses = [GPIST,GPOST,VADCST,CDDHwMgrST];
% %% gpi override parameters
% for k = 1:1:length(buses)
% clear ST
% ST=buses(k);
% for i=1:length(ST.Elements)
%     name = ST.Elements(i).Name;
% 
%     description = ['Override flag for ' name];
%     sigName = [ name 'Ovrd_C'];
%     eval(['clear ' sigName]);
%     eval([sigName, '=Simulink.Parameter;']);
%     eval([sigName, '.DataType= ''boolean'' ;']);
%     eval([sigName, '.Value= 0 ;']);
%     eval([sigName, '.Description=description;']);
%     eval([sigName, '.CoderInfo.StorageClass=''Custom'';']);
%     eval([sigName, '.CoderInfo.CustomStorageClass=''ConstVolatile'';']);
%     eval([sigName, '.CoderInfo.CustomAttributes.HeaderFile=''parameter.h'';']);
%     eval([sigName, '.CoderInfo.CustomAttributes.DefinitionFile=''parameter.c'';']);
% 
%     description = ['Override value for ' name];
%     dataType = ST.Elements(i).DataType;
%     sigName = [ name 'Mdl_C'];
%     eval(['clear ' sigName]);
%     eval([sigName, '=Simulink.Parameter;']);
%     if ~strcmp(dataType,'boolean')
%         dataType = 'single';       
%     end
%     eval([sigName, '.DataType= dataType ;']);
%     eval([sigName, '.Value= 0 ;']);
%     eval([sigName, '.Description=description;']);
%     eval([sigName, '.CoderInfo.StorageClass=''Custom'';']);
%     eval([sigName, '.CoderInfo.CustomStorageClass=''ConstVolatile'';']);
%     eval([sigName, '.CoderInfo.CustomAttributes.HeaderFile=''parameter.h'';']);
%     eval([sigName, '.CoderInfo.CustomAttributes.DefinitionFile=''parameter.c'';']);
% 
% end
% end
%% clear

clear i k n

clear SignalName;
clear dataType description dimensions dimensionsMode min max unit name sampleTime;
clear Para;
clear text dataType
