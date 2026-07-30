%% Guideline
% Add pragma in pmsmfoc.c to locate the pmsmfoc_step0 in psram2
% Add pragma in pmsmfoc_data.c to locate the varaint at the calibration
% segament
% Only the hightech supported in this mfile
% Tested


%%  file handle
if ~(exist('prjRoot','var')==1)
	a1DefineProjectEnv;
end
%%  file handle

keys = 'Exported';
xfile = {   [mdlRoot1 '\lib\FOC.c']; ...   %1
            [mdlRoot1 '\lib\pmsmfoc.c']; ...   %2
            [mdlRoot1 '\lib\FOCSpdTrq.c']; ...   %3
            [mdlRoot1 '\lib\parameter.c']; ...   %4
            [mdlRoot1 '\lib\parameter0.c']; ...   %5
            [mdlRoot1 '\lib\CDD_ISP.c']; ...   %5
             ...   %5
         };

 pragmaStart = ['#define FOC_P1_START_SEC_VAR_UNSPECIFIED', newline ,...
                '#include "MemMap.h" '];
 pragmaStop = ['#define FOC_P1_STOP_SEC_VAR_UNSPECIFIED',newline,...
                '#include "MemMap.h" '];

 pragmaStart1 = ['#define SWC_IR_START_SEC_CALIB_UNSPECIFIED', newline ,...
                '#include "MemMap.h" '];
 pragmaStop1 = ['#define SWC_IR_STOP_SEC_CALIB_UNSPECIFIED',newline,...
                '#include "MemMap.h" '];
 

 %% add pragma in FOC.c file
fileName = xfile{1}; %FOC.c
fileTxt = fileread(fileName);
%if isempty(strfind(fileTxt,keys))
    key1 = '/* Exported data definition */';
    key2 = 'void';
    pos1 = strfind(fileTxt,key1) +length(key1) ;       % position before the void
    fileTxt = [ fileTxt(1:pos1),newline,...
                pragmaStart,...
                fileTxt(pos1:length(fileTxt))
                ];
    pos2 = min(strfind(fileTxt,key2))-1;       %position after the };
    fileTxt = [ fileTxt(1:pos2),newline,...
                pragmaStop,...
                fileTxt(pos2:length(fileTxt))
                ];
    fid = fopen(fileName,'w');
    fprintf(fid,'%s',fileTxt);
    fclose(fid);
%end
disp('/****************Add Pragma in FOC.c done*****************************/');

 %% add pragma in pmsmfoc.c file
fileName = xfile{2}; %pmsmfoc.c
fileTxt = fileread(fileName);
%if isempty(strfind(fileTxt,keys))
    key1 = '/* Exported data definition */';
    key2 = 'void';
    pos1 = strfind(fileTxt,key1) +length(key1) ;       % position before the void
    fileTxt = [ fileTxt(1:pos1),newline,...
                pragmaStart,...
                fileTxt(pos1:length(fileTxt))
                ];
    pos2 = min(strfind(fileTxt,key2))-1;       %position after the };
    fileTxt = [ fileTxt(1:pos2),newline,...
                pragmaStop,...
                fileTxt(pos2:length(fileTxt))
                ];
    fid = fopen(fileName,'w');
    fprintf(fid,'%s',fileTxt);
    fclose(fid);
%end
disp('/****************Add Pragma in pmsmfoc.c done*****************************/');

 %% add pragma in FOCSpdTrq.c file
fileName = xfile{3}; %FOCSpdTrq.c
fileTxt = fileread(fileName);
%if isempty(strfind(fileTxt,keys))
    key1 = '/* Exported data definition */';
    key2 = 'void';
    pos1 = strfind(fileTxt,key1) +length(key1) ;       % position before the void
    fileTxt = [ fileTxt(1:pos1),newline,...
                pragmaStart,...
                fileTxt(pos1:length(fileTxt))
                ];
    pos2 = min(strfind(fileTxt,key2))-1;       %position after the };
    fileTxt = [ fileTxt(1:pos2),newline,...
                pragmaStop,...
                fileTxt(pos2:length(fileTxt))
                ];
    fid = fopen(fileName,'w');
    fprintf(fid,'%s',fileTxt);
    fclose(fid);
%end
disp('/****************Add Pragma in FOCSpdTrq.c done*****************************/');

 %% add pragma in parameter.c file
fileName = xfile{4}; %parameter.c
fileTxt = fileread(fileName);
%if isempty(strfind(fileTxt,keys))
    key1 = '/* Exported data definition */';
    key2 = '/*';
    pos1 = strfind(fileTxt,key1) +length(key1) ;       % position before the void
    fileTxt = [ fileTxt(1:pos1),newline,...
                pragmaStart1,...
                fileTxt(pos1:length(fileTxt))
                ];
    pos2 = max(strfind(fileTxt,key2))-1;       %position after the };
    fileTxt = [ fileTxt(1:pos2),newline,...
                pragmaStop1,...
                fileTxt(pos2:length(fileTxt))
                ];
    fid = fopen(fileName,'w');
    fprintf(fid,'%s',fileTxt);
    fclose(fid);
%end
disp('/****************Add Pragma in parameter.c done*****************************/');

 %% add pragma in parameter0.c file
fileName = xfile{5}; %parameter0.c
fileTxt = fileread(fileName);
%if isempty(strfind(fileTxt,keys))
    key1 = '/* Exported data definition */';
    key2 = '/*';
    pos1 = strfind(fileTxt,key1) +length(key1) ;       % position before the void
    fileTxt = [ fileTxt(1:pos1),newline,...
                pragmaStart1,...
                fileTxt(pos1:length(fileTxt))
                ];
    pos2 = max(strfind(fileTxt,key2))-1;       %position after the };
    fileTxt = [ fileTxt(1:pos2),newline,...
                pragmaStop1,...
                fileTxt(pos2:length(fileTxt))
                ];
    fid = fopen(fileName,'w');
    fprintf(fid,'%s',fileTxt);
    fclose(fid);
%end
disp('/****************Add Pragma in parameter0.c done*****************************/');
 %% add pragma in CDD_ISP.c file
fileName = xfile{6}; %FOC.c
fileTxt = fileread(fileName);
%if isempty(strfind(fileTxt,keys))
    key1 = '/* Exported data definition */';
    key2 = 'void';
    pos1 = strfind(fileTxt,key1) +length(key1) ;       % position before the void
    fileTxt = [ fileTxt(1:pos1),newline,...
                pragmaStart,...
                fileTxt(pos1:length(fileTxt))
                ];
    pos2 = min(strfind(fileTxt,key2))-1;       %position after the };
    fileTxt = [ fileTxt(1:pos2),newline,...
                pragmaStop,...
                fileTxt(pos2:length(fileTxt))
                ];
    fid = fopen(fileName,'w');
    fprintf(fid,'%s',fileTxt);
    fclose(fid);
%end

%end
disp('/****************Add Pragma in CDD_ISP.c done*****************************/');
%% clear
clear key1 key2 pos1 pos2 fid filetxt
clear fileTxt oldStr newStr fid keys xfile i fileName

 

