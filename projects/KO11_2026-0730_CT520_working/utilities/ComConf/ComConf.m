%% Guideline 
% Three files is necessary for the CAN configuration
% 1. CAN dbc      message and signal definition
% 2. canPort.ini  hw can node pin assignment
% 3. EcuNode      EcuNode name in the dbc file
% 4. Change the cuurent path to mfile folder before execute mfile
%% file handle

if ~(exist('ecuNode','var')==1) || ~(exist('dbcFile','var')==1)
    a1DefineProjectEnv;
end

plfile = 'Com_cfg_autogen.pl';

disp('------------------------------------------------');
disp(['dbc file : ', dbcFile]);
disp(['port conf : ', 'canPort.ini' ]);
disp(['Ecu node : ', ecuNode]);
disp('------------------------------------------------'); 
%%

% delete files in cgen/comconf
delete([mdlRoot '\utilities\ComConf\cgen\ComConf\*.*']);
%invoke perl to generate CAN configurations
perl(plfile,dbcFile,ecuNode,[pwd '\'] ,[pwd '\']);
% generate adaptor c files
cgenComConf;
% generate can init files, only used in Tasking enviornment
updateCanPort;
%move files to \cgen\ComConf
movefile('*.c',[mdlRoot '\utilities\ComConf\cgen\ComConf'],'f');
movefile('*.h',[mdlRoot '\utilities\ComConf\cgen\ComConf'],'f');

%%

clear plfile des

disp('------------------------------------------------');
disp('Communication configuration generated. Done.');
disp('------------------------------------------------');