%% Guideline
% 
% Creat structure: 
% CDDIN1ST
% CDDIN2ST
% CDDOUTST
% CDDHwMgrST
% 

%% creat bus structure
clear CDDIN1 CDDIN2 CDDOUT CDDHwMgr
%% CDDIN2ST




%% CDDIN1ST
% CDDIN1.SINH = uint16(0);
% CDDIN1.SINL = uint16(0);
% CDDIN1.COSH = uint16(0);
% CDDIN1.COSL = uint16(0);
% CDDIN1.IPH1B = uint16(0);
% CDDIN1.IPH2B = uint16(0);
% CDDIN1.IPH3B = uint16(0);
% CDDIN1.HVUEX = uint16(0);
% CDDIN1.DUTY1 = single(0);
% CDDIN1.DUTY2 = single(0);
% CDDIN1.DUTY3 = single(0);
% 
% 
% tmp_BusName = Simulink.Bus.createObject(CDDIN1);
% tmp_Bus = evalin('base',tmp_BusName.busName);
% evalin('base',['clear ' tmp_BusName.busName]);
% assignin('base','CDDIN1ST',tmp_Bus);
% CDDIN1ST.DataScope = 'Auto';
% CDDIN1ST.HeaderFile = 'Rte_Type.h';
% 
% 
% %% CDDHwMgrST
% CDDHwMgr.flgFltAHiDrv = false;
% CDDHwMgr.flgFltBHiDrv = false;
% CDDHwMgr.flgFltALoDrv = false;
% CDDHwMgr.flgFltBLoDrv = false;
% CDDHwMgr.flgFltOC = false;
% CDDHwMgr.flgFltOV = false;
% CDDHwMgr.modLo1IgbtDrv = EiceSilOPM.OPM0;
% CDDHwMgr.modLo2IgbtDrv = EiceSilOPM.OPM0;
% CDDHwMgr.modLo3IgbtDrv = EiceSilOPM.OPM0;
% CDDHwMgr.modHi1IgbtDrv = EiceSilOPM.OPM0;
% CDDHwMgr.modHi2IgbtDrv = EiceSilOPM.OPM0;
% CDDHwMgr.modHi3IgbtDrv = EiceSilOPM.OPM0;
% CDDHwMgr.stLvMoCSOP = false;
% CDDHwMgr.stHvMoCSOP = false;
% CDDHwMgr.stIgbtDrvCnfgOk = false;
% CDDHwMgr.TDBC1 = uint16(0);
% CDDHwMgr.TDBC2 = uint16(0);
% CDDHwMgr.TDBC3 = uint16(0);
% 
% tmp_BusName = Simulink.Bus.createObject(CDDHwMgr);
% tmp_Bus = evalin('base',tmp_BusName.busName);
% evalin('base',['clear ' tmp_BusName.busName]);
% assignin('base','CDDHwMgrST',tmp_Bus);
% CDDHwMgrST.DataScope = 'Auto';
% CDDHwMgrST.HeaderFile = 'Rte_Type.h';
% 
% %% CDDOUTST 
% CDDOUT.ti = [uint16(0) uint16(0) uint16(0) uint16(0) uint16(0) uint16(0) uint16(0) uint16(0) uint16(0) uint16(0) uint16(0) uint16(0)];
% tmp_BusName = Simulink.Bus.createObject(CDDOUT);
% tmp_Bus = evalin('base',tmp_BusName.busName);
% evalin('base',['clear ' tmp_BusName.busName]);
% assignin('base','CDDOUTST',tmp_Bus);
% CDDOUTST.DataScope = 'Auto';
% CDDOUTST.HeaderFile = 'Rte_Type.h';

%% clear
clear CDDIN1 CDDIN2 CDDOUT CDDHwMgr
clear tmp_Bus tmp_BusName





