
if ~((exist('mdlRoot','var')==1) && (exist('prjRoot','var')==1))
    a1DefineProjectEnv;
end



%% Load the DSM class definitions
% creat and update FID and DFC enumeration for the fid and dfc index
% As the enumeration definition are based on the DSMAuto files, DSMAuto
% will be updated before enumuerator definition when dsmFile changed.
% The DSMAuto will be updated as well
currpath=cd();
cd([mdlRoot '\utilities\DSM']);         %The bat file must run at current path
%UpdateDsm
cd(currpath);
clear currpath
disp('2-1. DSM updated and enumeration(FID and DFC) defined');


%% HSI file handle
% creat the non-virtual bus types used between high and low level code
% update VADCST GPIST GPOST members in the middle file
%DefineBusMemberFrmHsi;

%% Load Enumeration class
% creat the enumerate class used in the simulink mode like
DefineSystemEnumeration;
% EGPI/EGPO/EVADC
%DefineIoEnumeration;
disp('2-2. Enumeration class defined');

%% Load structure definition
% creat the non-virtual bus types used between high and low level code
% creat CANTXDST and CANRXDST from dbc file
% cd([mdlRoot '\utilities\DataType']);
%%DefineBusFrmDbc;
% creat CDDINST and CDDOUTST and CDDHwMgrST
% A dedicated file to define cdd bus 
%DefineBusFrmCdd;
% read the csv file, generate the bus/enumeration/configuration
DefineBusFrmXls;
% read the csv file, generate the bus/enumeration/configuration
DefineBusFrmHsi;

disp('2-3. CAN/VADC/GPIO/CDD structure defined')


%% Load PMSM parameters
% define motor and hardware relative parameter, whose name ends with _P
% this file shall be revised manually

pmsmfoc_data;
disp('------------------------------------------------------')
disp('2-4. pmsmfoc_data defined');
disp('2-4. OPL: pmsmfoc_data data dictionary changed but no tested yet');
disp('------------------------------------------------------')
    
%% Load the model object definitions
%creat simulink signal SAQ_xxx from predefined bus types(GPIST,GPOST...)
DefineSignalFrmBus;
%creat simulink parameter xxxMdl_C and xxxOvrd_C from predefined bus types(GPIST,GPOST...)
DefineParameterFrmBus;
%creat simulink signal COM_xxx from dbc file for signals in can messages
%%DefineSignalFrmDbc;
% creat simulink signals from xls file, used inside model
DefineSignalFrmXls;
% creat simulink parameters from xls file, calibratable
DefineParameterFrmXls;
DefineParameterFrmXls2;
% crear simulink lookup tables xxx_TAB from xls file, calibratable
DefineTableFrmXls;
disp('2-5. objects of parameters ,Tables and signals defined')

%% Update the simulink model as the interface changed
% not implemented
    
% basic\SAQ\gpiRt
%CreatGpiRtBlock;
% basic\ISP\ISP_DIN\DigIn
%CreatGpiOvdBlock;         %Done by sub system
% basic\OSP\GpoRt
%CreatGpoRtBlock;
% basic\SAQ\vadcRt
%CreatVadcRtBlock;
% monitor\SAQ\cddRt
%CreatCdd1RtBlock
% pmsmfoc\SAQ\cddRt
%CreatCdd2RtBlock

disp('2-6. simulink model updated, Please check the bus input in edrive.slx')
disp('2-6. OPL  CreatGPORtBlock is incorrect')

disp('/*********************************************************/');
disp('/****************Step a2 done*****************************/');
disp('/*********************************************************/');
