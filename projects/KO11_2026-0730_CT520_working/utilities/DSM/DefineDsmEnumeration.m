%% Guideline
% define FID and DFC enumeration 

%% file handle
if ~(exist('mdlRoot','var')==1)
    a1DefineProjectEnv;
end

%% read the dinh_auto_conf.c, generate enum class: FID
cfile = [mdlRoot,'\utilities\DSM\DSMAuto\dinh_auto_conf.c'];

fileId = fopen(cfile);
% const DSM_FIdType FId_DdcReqDeactvn = { 5 };
tline = fgetl(fileId);
xName = {};
xValue = [];
xCnt = 1;
while ischar(tline)
   if (contains(tline,'const DSM_FIdType FId_'))
   newStr = replace(tline,'const DSM_FIdType FId_','        ');
   newStr = replace(newStr,'= {',' ');
   newStr = replace(newStr, '};','');
   newStr = split(newStr);
   xName{xCnt} = newStr{2};
   xValue(xCnt) = str2num(newStr{3});
   xCnt = xCnt + 1;
   end
    tline = fgetl(fileId);
    
end

fclose(fileId);
 Simulink.defineIntEnumType('FID',xName,xValue,'HeaderFile','rte_aswType.h', 'DataScope','Exported');
% fileid = fopen(mfile,'w');
% fwrite(fileid,enumtext);
% fclose(fileid);
%% read the dfc_auto_conf.c, generate enum class: DFC
cfile = [mdlRoot,'\utilities\DSM\DSMAuto\dfc_auto_conf.c'];
%mfile = 'DFC.m';
fileId = fopen(cfile);
% const DSM_DFCType_st DFC_DdcITnetOverHw ={1, TIME_IN_ROW_SMALL};
xName = {};
xValue = [];
xCnt = 1;
tline = fgetl(fileId);
while ischar(tline)
   if (contains(tline,'const DSM_DFCType_st DFC_'))
   newStr = replace(tline,'const DSM_DFCType_st DFC_','        ');
   newStr = replace(newStr,'= {',' ');
   newStr = replace(newStr, ',','  ');
   
   newStr = split(newStr);
   xName{xCnt} = newStr{2};
   xValue(xCnt) = str2num(newStr{3});
   xCnt = xCnt + 1;
   end
    tline = fgetl(fileId);
end

fclose(fileId);
Simulink.defineIntEnumType('DFC',xName,xValue,'HeaderFile','rte_aswType.h', 'DataScope','Exported');
% fileid = fopen(mfile,'w');
% fwrite(fileid,enumtext);
% fclose(fileid);

 

 vars = {'cfile','cfilepath','enumtext','ext','fileId','mfile','mfilepath','name','p1','pathstr','pos_v','linecounter','newStr','searchstop','startLine','stopLine','textused','tline'};
 clear(vars{:});
 clear vars;

% disp('------------------------------------------------------')
% disp('Enumeration class for FID and DFC updated')
% disp('------------------------------------------------------')