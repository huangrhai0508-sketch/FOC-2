%% Guideline
% Read the structure and generate the SAQ_XXX ISP_XXX for the simulink signal definition.
% signals in GPOST  GPIST  VADC0ST are declared
%% file handle
if (~exist('CDDIN1ST','var')==1)   || ...
   (~exist('CDDIN2ST','var')==1)   || ...
   (~exist('GPOST','var')==1)   || ...
   (~exist('GPIST','var')==1)   || ...
   (~exist('VADCST','var')==1) 
    
    %%DefineBusFrmDbc;
    DefineBusFrmXls;
    DefineBusFrmCdd;
    DefineBusFrmHsi;
    
end


%buses = [GPOST,GPIST,VADCST,CDDIN1ST,CDDIN2ST];
%% gpio  gpost and  gpist
% for k = 1:1:length(buses)
%     clear ST;
%     ST = buses(k);
%     n = length(ST.Elements);
%     for i=1:n
%         name = ST.Elements(i).Name;
%         min = ST.Elements(i).Min;    
%         max = ST.Elements(i).Max;
%         dataType = ST.Elements(i).DataType;
%         dimensions = ST.Elements(i).Dimensions;
%         complexity = ST.Elements(i).Complexity;
%         dimensionsMode = ST.Elements(i).DimensionsMode;
%         sampleTime = ST.Elements(i).SampleTime;
%         unit = ST.Elements(i).Unit;
%         description = ST.Elements(i).Description;
%         sigName = ['SAQ_' name];
%         eval(['clear ' sigName]);
%         eval([sigName, '=Simulink.Signal;']);
%         eval([sigName, '.DataType= dataType ;']);
%         eval([sigName, '.Complexity= complexity ;']);
%         eval([sigName, '.Dimensions= dimensions ;']);
%         eval([sigName, '.DimensionsMode= dimensionsMode ;']);
%         eval([sigName, '.SampleTime= sampleTime ;']);
%         if ~isempty(min)
%             eval([sigName '.Min= min ;']);
%         end
%         if ~isempty(max)
%             eval([sigName '.Max= max ;']);
%         end
%       if isnumeric(Para)
%           Para=mat2str(Para);
%           eval([SignalName, '.InitialValue=Para;']);
%       end
%         if isequal(unit,NaN)
%             unit='';
%         else
%             unit = char(unit);
%         end
%         eval([sigName, '.Unit= unit ;']);
% 
%         eval([sigName, '.CoderInfo.StorageClass=''Custom'';']);
%         eval([sigName, '.CoderInfo.CustomStorageClass=''ExportToFile'';']);
%         eval([sigName, '.CoderInfo.CustomAttributes.HeaderFile=''globalVariable.h'';']);
%         eval([sigName, '.CoderInfo.CustomAttributes.DefinitionFile=''globalVariable.c'';']);
%         eval([sigName, '.Description= description ;']);
%         
%         only boolean and signel datatype for the ISP_signals
%         if strcmp(dataType,'boolean')
%             sigName = ['ISP_b' name];
%         else
%             sigName = ['ISP_' name];
%             dataType = 'single';
%         end
%         description = ['Input value after the override block for ' name ' if override function exist'];
%         eval(['clear ' sigName]);
%         eval([sigName, '=Simulink.Signal;']);
%         eval([sigName, '.DataType= dataType ;']);
%         eval([sigName, '.Complexity= complexity ;']);
%         eval([sigName, '.Dimensions= dimensions ;']);
%         eval([sigName, '.DimensionsMode= dimensionsMode ;']);
%         eval([sigName, '.SampleTime= sampleTime ;']);
%         if ~isempty(min)
%             eval([sigName '.Min= min ;']);
%         end
%         if ~isempty(max)
%             eval([sigName '.Max= max ;']);
%         end
%       if isnumeric(Para)
%           Para=mat2str(Para);
%           eval([SignalName, '.InitialValue=Para;']);
%       end
%         if isequal(unit,NaN)
%             unit='';
%         else
%             unit = char(unit);
%         end
%         eval([sigName, '.Unit= unit ;']);
% 
%         eval([sigName, '.CoderInfo.StorageClass=''Custom'';']);
%         eval([sigName, '.CoderInfo.CustomStorageClass=''ExportToFile'';']);
%         eval([sigName, '.CoderInfo.CustomAttributes.HeaderFile=''globalVariable.h'';']);
%         eval([sigName, '.CoderInfo.CustomAttributes.DefinitionFile=''globalVariable.c'';']);
%         eval([sigName, '.Description= description ;']);
% 
%     end
% end



%% clear

clear i k n

clear SignalName buses ST complexity
clear dataType description dimensions dimensionsMode min max unit name sampleTime;
clear Para;
clear text;
