%% Guideline
% copy files into the code project
% Add complier pragma in files
% 1) comconf folder
% 2) rtw generated c and h file
% 3) c-mex sfun and library
%% file handle
if ~((exist('mdlRoot','var')==1) && (exist('prjRoot','var')==1))
    a1DefineProjectEnv
end


%% Simulink generated code
%des = [prjRoot '\0_Src\1_Asw\1_Inv'];
%rmdir([mdlRoot '\work\tmp'],'s');
des_include = [mdlRoot '\work\tmp\include'];
des_lib = [mdlRoot '\work\tmp\lib'];
des_a2l = [mdlRoot '\work\tmp\a2l'];

des_include_1 = [mdlRoot1 '\include'];
des_lib_1 = [mdlRoot1 '\lib'];
des_a2l_1 = [mdlRoot1 '\a2l'];



mkdir(des_include);
mkdir(des_lib);
mkdir(des_a2l);

mkdir(des_include_1);
mkdir(des_lib_1);
mkdir(des_a2l_1);



%AddPragmaInFile;

% monitor.slx generated
%src = [mdlRoot '\work\monitor_ert_rtw\*.h'];
%copyfile(src, des, 'f');
%src = [mdlRoot '\work\monitor_ert_rtw\*.c'];
%copyfile(src, des, 'f');
%rename c files for parameter globalvariable and lookuptable
%movefile([des,'\parameter.c'],[des,'\monitor_parameter.c']);
%movefile([des,'\globalVariable.c'],[des,'\monitor_globalVariable.c']);
%movefile([des,'\lookuptable.c'],[des,'\monitor_lookuptable.c']);

% basic.slx generated
%src = [mdlRoot '\work\basic_ert_rtw\*.h'];
%copyfile(src, des, 'f');
%src = [mdlRoot '\work\basic_ert_rtw\*.c'];
%copyfile(src, des, 'f');
%rename c files for parameter globalvariable and lookuptable
%movefile([des,'\parameter.c'],[des,'\basic_parameter.c']);
%movefile([des,'\globalVariable.c'],[des,'\basic_globalVariable.c']);
%movefile([des,'\lookuptable.c'],[des,'\basic_lookuptable.c']);

% pmsmfoc.slx generated
src = [mdlRoot '\work\pmsmfoc_ert_rtw\*.h'];
copyfile(src, des_include, 'f');
copyfile(src, des_include_1, 'f');
src = [mdlRoot '\work\pmsmfoc_ert_rtw\*.c'];
copyfile(src, des_lib, 'f');
copyfile(src, des_lib_1, 'f');



src = [mdlRoot '\work\slprj\ert\_sharedutils\*.h'];
copyfile(src,des_include,'f');
copyfile(src, des_include_1, 'f');
src = [mdlRoot '\work\slprj\ert\_sharedutils\*.c'];
copyfile(src,des_lib,'f');
copyfile(src, des_lib_1, 'f');



src = [mdlRoot '\work\slprj\ert\CDD_ISP\*.h'];
copyfile(src,des_include,'f');
copyfile(src, des_include_1, 'f');
src = [mdlRoot '\work\slprj\ert\CDD_ISP\*.c'];
copyfile(src,des_lib,'f');
copyfile(src, des_lib_1, 'f');


src = [mdlRoot '\work\slprj\ert\currentloop\*.h'];
copyfile(src,des_include,'f');
copyfile(src, des_include_1, 'f');
src = [mdlRoot '\work\slprj\ert\currentloop\*.c'];
copyfile(src,des_lib,'f');
copyfile(src, des_lib_1, 'f');

src = [mdlRoot '\work\slprj\ert\FOC\*.h'];
copyfile(src,des_include,'f');
copyfile(src, des_include_1, 'f');
src = [mdlRoot '\work\slprj\ert\FOC\*.c'];
copyfile(src,des_lib,'f');
copyfile(src, des_lib_1, 'f');


src = [mdlRoot '\work\slprj\ert\SVPWM\*.h'];
copyfile(src,des_include,'f');
copyfile(src, des_include_1, 'f');
src = [mdlRoot '\work\slprj\ert\SVPWM\*.c'];
copyfile(src,des_lib,'f');
copyfile(src, des_lib_1, 'f');

src = [mdlRoot '\work\FOCSpdTrq_ert_rtw\*.h'];
copyfile(src,des_include,'f');
copyfile(src, des_include_1, 'f');
src = [mdlRoot '\work\FOCSpdTrq_ert_rtw\*.c'];
copyfile(src,des_lib,'f');
copyfile(src, des_lib_1, 'f');

src = [mdlRoot '\work\FOCSpdTrq_ert_rtw\*.a2l'];
copyfile(src,des_a2l,'f');
copyfile(src, des_a2l_1, 'f');
src = [mdlRoot '\work\pmsmfoc_ert_rtw\*.a2l'];
copyfile(src,des_a2l,'f');
copyfile(src, des_a2l_1, 'f');
%rmdir(des_lib,'s');
%%rename c files for parameter globalvariable and lookuptable
%movefile([des,'\parameter.c'],[des,'\pmsmfoc_parameter.c']);
%movefile([des,'\globalVariable.c'],[des,'\pmsmfoc_globalVariable.c']);
%movefile([des,'\lookuptable.c'],[des,'\pmsmfoc_lookuptable.c']);

%% blankfortype.slx generated
%src = [mdlRoot '\work\slprj\ert\_sharedutils\*.h'];
%copyfile(src,des,'f');
%src = [mdlRoot '\work\slprj\ert\_sharedutils\*.c'];
%copyfile(src,des,'f');

%%copy to the c project
%src=des;
%des = [prjRoot '\0_Src\1_Asw\1_Inv'];
%copyfile(src, des, 'f');
%rmdir(src,'s');

%AddPragmaInFile;
AddPragmaInFile1;
defineadd;
disp('/**************Copy ASW generation to Project file*******************/');
%%
%Add pragma in Core2
%AddPragmaInFile;

%%copy to the c project


disp('/*********************************************************/');
disp('/****************Step a5 done*****************************/');
disp('/*********************************************************/');
%% clear
clear src des


