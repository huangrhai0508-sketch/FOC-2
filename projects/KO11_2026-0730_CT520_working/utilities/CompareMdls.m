%% Guideline
% Select two simlulink models
% invoke visdiff comparison tools to comapre
if ~(exist('mdlRoot','var')==1)
    a1DefineProjectEnv;
end

file1 = uigetfile('*.slx','Select 1st file');
file2 = uigetfile('*.slx','Select 2nd file');
visdiff(file1,file2);
clear file1 file2
 

