
%% Guideline
% Run this file to perform all the steps 
% define the path 
% define simulink signals and enviornment 
% generate c-code from the models
% generate embedded code from the configuration
% copy files to the project folder
% build and release
% configuaration whenever the project has changed.

a1DefineProjectEnv;
a2LoadEnviornment;
a3generate_controller_code;
a4cgen;
a5CopyFilestoProject;
a6BuildAndRelease;