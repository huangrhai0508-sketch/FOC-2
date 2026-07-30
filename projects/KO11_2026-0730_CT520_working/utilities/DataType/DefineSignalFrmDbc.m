%% Guideline
% define the COM_xxx objects, be referred by the model
% only one line in dbc comments support
% in the dbc file. almost no one set the value type correctly. the
% unsigned is the default. So here we define boolean for
% bitsize==1 and float for others.
disp('---------OPL SignalDefineFrmDbc.m---------------------')
disp('!!!variables in enumeration type shall be redefined to support xcp!!!')
disp('---------------------------------------------------')
%% get the dbc file
if ~((exist('dbcFile','var')==1)&&(exist('ecuNode','var')==1)&&(exist('ecuNode','var')==1)) 
    a1DefineProjectEnv;
end

%% open the dbc file 
db = canDatabase(dbcFile);
MsgCnts = length(db.Messages);

%% creat simulink signals 

for i=1:1:MsgCnts
    clear signals
    signals = db.MessageInfo(i).SignalInfo;
    sigCnts = length(signals);
    
    for j = 1:1:sigCnts
        clear tmp
        sigName=signals(j).Name;
        tmp = split(sigName,'_');
        sigName = ['COM_' char(tmp(length(tmp)))];
        sigComment = ['''',deblank(signals(j).Comment),''''];
        sigMin =  num2str(signals(j).Minimum);
        sigMax =  num2str(signals(j).Maximum);
        sigUnits = ['''',signals(j).Units, ''''];
        %elimilate error
        strForPass = ['''','count value', ''''];
        if strcmp(sigUnits,strForPass)
            sigUnits = ['''', ''''];
        end

        strForPass = ['''','Deg C', ''''];
        if strcmp(sigUnits,strForPass)
            sigUnits = ['''','DegC', ''''];
        end
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        sigOffset = signals(j).Offset;
        sigFactor = signals(j).Factor;
        attributeInfoCnts = length(signals(j).AttributeInfo);
        sigInit = ['''', num2str((signals(j).AttributeInfo(attributeInfoCnts).Value)*sigFactor+sigOffset) ,''''];
        % in the dbc file. almost no one set the value type correctly. the
        % unsigned is the default. So here we define boolean for
        % bitsize==1 and float for others.
        if signals(j).SignalSize ==1
            sigType = '''boolean''';
        else
            sigType = '''single''';
        end
        %           sigType = '''auto''';
        eval([sigName '=Simulink.Signal;']);
        eval([sigName, '.CoderInfo.StorageClass=''Custom'';']);
        eval([sigName, '.CoderInfo.CustomStorageClass=''ExportToFile'';']);
        eval([sigName, '.CoderInfo.CustomAttributes.HeaderFile=''globalVariable.h'';']);
        eval([sigName, '.CoderInfo.CustomAttributes.DefinitionFile=''globalVariable.c'';']);

        eval([sigName '.Description = ' sigComment ';']);
        eval([sigName '.DataType = ' sigType '; ']);
        eval([sigName '.InitialValue = ' sigInit ';']);
        eval([sigName '.Min = ' sigMin ';']);
        eval([sigName '.Max = ' sigMax ';']);
        eval([sigName '.Unit =' sigUnits ';']);
        eval([sigName '.Dimensions = 1 ;']);
        eval([sigName '.DimensionsMode = ''Fixed'' ;']);
        eval([sigName '.Complexity = ''Real'' ;']);
        eval([sigName '.SampleTime = -1; ']);
        %        eval([sigName '.InitialValue = ''auto'' ']);
    end
end
     
%% clear
clear i j MsgCnts sigCnts sigName signals
clear sigType sigName sigMax sigMin sigUnits sigComment tmp
 

