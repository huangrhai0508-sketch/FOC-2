%clc;
%clear;
% The load sequence depends on each other.
disp('----------------------------------GUIDELINE---------------------------------------------')
disp('1. DefineProjectEnv.m -- define the key variants used in the whole project')
disp('2. LoadEnviornment.m  -- Load the simulink objects, bus structures,...')
disp('3. generate_controller_code.m  -- generate the controller code, ')
disp('4. cgen.m  -- generate the embeddded code')
disp('5. CopyFilestoProject.m  -- copy generated files into the complier IDE, add compiler info')
disp('6. BuildAndRelease.m  -- compile in the ide and release hex a2l file--Not fininshed')
disp('-----------------------------------------------------------------------------------------')
%% Guideline
% define simulink and project path
% define can node name, dbc
% define Pinmapper generated files
% define the dsm xml file
% define IDE definitions
% ATTETION : ALL m files will invoke this file to update the enviornment if
% relevant variable does not exist. So please correct and(or) confirm the
% configuaration whenever the project has changed.

%% root path
% Creat the matlab root
% Creat the Tasking root
% The content shall be defined as your project path
% All script files operation are based these two key path
% 
clear;
fileName=mfilename('fullpath');

%fileName1=mfilename('D\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC');

tmp = strfind(fileName,'\');
prjRoot = [fileName(1:tmp(length(tmp)-2)-1),'\code'];                % c code project root
mdlRoot = fileName(1:tmp(length(tmp)-1)-1);                             % simulink project root
mdlRoot1 = 'D:\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC';
prjName_1='D:\GL_V\Applications\SipAddon\StartApplication\Appel';
prjName_1_1='D:\GL_V\Applications\SipAddon\StartApplication\Appel\TOOLS';

tmp = split(prjRoot,'\');
prjName = char(tmp(length(tmp)));
mdlNameCore2 = 'pmsmfoc';             % target model name 
mdlNameCore0 = 'Basic';               % target model name in core0
mdlNameCore1 = 'Monitor';             % target model name in core2
mdlNameBlank = 'BlankForType';        % target model name for parameter definition
mdlNameCore2_1 = 'FOCSpdTrq';
clear tmp fileName
%% CAN node name
% Creat the ecu CAN node name 
% Creat the not ecu CAN node name 
% use shall rename the nodes in the dbc file if the recieved messages come
% from several differenct nodes
ecuNode = 'HYB_EM';         % motor controller node name
hostNode = 'HYB_MSG';       % vcu node name
dbcFile =[mdlRoot '\controller\' 'CAN_COM.dbc'];        % dbc name

%% pin file
% hsi file is used to define the hardware software interfece, instead of the pinFile

hsiFile = [mdlRoot '\utilities\PortCfg\HSI_INVGEN2_TC275_LQFP176_20181219.xlsx'];
parFile = [mdlRoot '\utilities\ParameterGenerator.xlsx'];

%% dsm file
% dsm file(xml file) is root of the dsm module
% perl(or exe) will handle this file to generate the dsm data
% Also m file will creat a FID and DFC enumeration based the generated
% data
dsmFile = [mdlRoot '\utilities\DSM\DSM_INVGEN2 V0.0.xlsx'];

%% pmsm file
% Data Dictionary for Permanent Magnet Synchronous Machine Controller
pmsmFile = [mdlRoot '\utilities\pmsmfoc_data.m'];

%% build info 
ides = {'Tasking','Framework','Hitech'};
compilers = {'Tasking','Hitech'};
IDE = char(ides(1));
Compiler = char(compilers(1));         % motor controller node name
 if strcmp(IDE, ides{1})
 %    user shall add BINUTILS_PATH in the system enviornment manually
 %    the value is the path of the baseframework 
 %    setenv('BINUTILS_PATH','C:\BaseFrameWork\bin');
     setenv('PATH', [getenv('BINUTILS_PATH') ';' getenv('PATH')]);
 end
 load ERT.mat;
%% display
disp('-------------ENVIRONMENT VARIABLES-------------------------')
fprintf(' prjRoot = %s \n',prjRoot);
fprintf(' mdlRoot = %s \n',mdlRoot);
fprintf(' prjName = %s \n',prjName);
fprintf(' mdlNameCore0 = %s \n',mdlNameCore0);
fprintf(' mdlNameCore1 = %s \n',mdlNameCore1);
fprintf(' mdlNameCore2 = %s \n',mdlNameCore2);
fprintf(' parFile = %s \n',parFile);
fprintf(' hsiFile = %s \n',hsiFile);
fprintf(' dsmFile = %s \n',dsmFile);
fprintf(' dbcFile = %s \n',dbcFile);
fprintf(' IDE = %s \n',IDE);
fprintf(' Compiler = %s \n',Compiler);
disp('-----------------------------------------------------------')
disp('/*********************************************************/');
disp('/****************Step a1 done*****************************/');
disp('/*********************************************************/');