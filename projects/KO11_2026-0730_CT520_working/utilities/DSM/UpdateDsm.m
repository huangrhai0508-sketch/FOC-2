%% Guideline
% transfer the xls file into xml file
% invoke DSMGen.exe to generate files in DSMAuto folder.
% declare the enumeration on the generated files
if ~(exist('dsmFile','var')==1)
     a1DefineProjectEnv;
end


%% update DsmAuto folder
DsmAuto = [pwd,'\DSMAuto'];
if exist(DsmAuto,'dir')==7
    rmdir(DsmAuto,'s');
end
mkdir(DsmAuto);

if exist(dsmFile,'file')==2
    TransferXlsintoXml;
    eval('!DsmGen.bat');
    DefineDsmEnumeration;
else
    error('dsm xls file not found, or  more xls* files found');
end


%%
clear  DsmAuto 