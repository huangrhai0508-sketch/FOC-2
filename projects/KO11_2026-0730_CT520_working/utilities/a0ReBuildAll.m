
%% Guideline
% Run this file to perform all the steps following a clean process
% define the path 
% define simulink signals and enviornment 
% generate c-code from the models
% generate embedded code from the configuration
% copy files to the project folder
% build and release
% configuaration whenever the project has changed.
%%
if ~((exist('mdlRoot','var')==1) && (exist('prjRoot','var')==1))
    a1DefineProjectEnv;
end


%delete DSM
delete([mdlRoot '/utilities/DSM/DSMAuto/*.*']);
%clear work folder
dirs=[mdlRoot '/work'];
if exist(dirs,'dir')==7
    cd('c:\')
    rmdir(dirs,'s');
end
mkdir(dirs);
cd(dirs);

delete([mdlRoot '/work/*.*'])
% clear can relative files
delete([mdlRoot '/utilities/ComConf/cgen/ComConf/*.*']);

% clean workspace
clear;
clc;
% build all
a1DefineProjectEnv;
a2LoadEnviornment;
a3generate_controller_code;
a4cgen;
a5CopyFilestoProject;
a6BuildAndRelease;