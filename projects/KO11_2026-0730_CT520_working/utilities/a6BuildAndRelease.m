%% Guideline
% invoke the compiler to build the c code project
% generate the a2l and hex fil after build
% if ~((exist('mdlRoot1','var')==1) && (exist('prjRoot_1','var')==1))
%     a1DefineProjectEnv;
% end

% elf file
%elfFile = [prjRoot  '\2_Out\Gnuc\'  prjName '_Tricore.elf'];

%% Invoke the compiler to build
% %TSKPATH% is the system enviornment varialbe, which is
% c:\tasking\v621\ctc\bin. If not defined. use the absolute path to replace
% it.
% use ctrl+c to break the building process
%currentpath = pwd;
cd(prjName_1);
%disp('/********************perform clean****************************/');
%eval('!scons -c');
disp('/********************perform build****************************/');
eval('!.\m.bat -j8');
disp('/******************** build finish****************************/');

%cd(prjName_1_1);
%eval('!integration.bat');
%if strcmp(Compiler,'Tasking')
%     eval('!%TSKPATH%\amk -a -J -G Debug -f makefile');
%elseif strcmp(Compiler,'Hitech')
%    % perform clean when the files fetched from SVN
%    if ~(exist(elfFile,'file')==2)
%		disp('/********************perform clean****************************/');
%        eval('!make -j clean');
%    else
%        delete(elfFile) %delete elf to force relink.
%    end
    
%    eval('!make -j all');
%end
%cd(currentpath);

%% postbuild at a2l
%if exist(elfFile,'file')==2
%    flagBuildSuccess = 1;
%    AddAddressInA2l;
%else
%    flagBuildSuccess = 0;
%end

% des = [prjRoot '\ASW_FOC\ASW_IR\lib\*'];
% delete(des);
% des = [prjRoot '\ASW_FOC\ASW_IR\lib'];
% src = [prjRoot '\output\objs\ASW_FOC\ASW_IR\*.a'];
% copyfile(src,des,'f');

disp('/*********************************************************/');
disp('/****************Step a6 done*****************************/');
disp('/*********************************************************/');

 

