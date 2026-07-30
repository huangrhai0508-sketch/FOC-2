%% Guideline
% Read dbc file
% Creat structure:  CANTXD.EM01.sigxx           CANRXD.MSG01.sigyy
% the intermidiate message structure created automatically with the CANTXD CANRXD definition
%% define the Transmit node 
ecuNode = 'HYB_EM';         % motor controller node name
hostNode = 'HYB_MSG';       % vcu node name
%% get the dbc file
p1 = mfilename('fullpath');
[pathstr,name,ext]=fileparts(p1);
pos_v = strfind(pathstr,filesep);
dbcfile = [pathstr(1:pos_v(end)-1) filesep 'controller' filesep 'CAN_COM.dbc'];
clear pos_v pathstr name ext p1

%% open the dbc file 
db = canDatabase(dbcfile);
 MsgCnts = length(db.Messages);
 MsgNames = db.Messages;
 MsgStruct = reverse(insertBefore(reverse(MsgNames),1,'_'));    %add '_' for the msg content structure

%% creat bus structure CANTXD 
clear CANTXD

 for i=1:1:MsgCnts
     nodeNameTmp = char(db.MessageInfo(i).TxNodes);
     
     if strcmp(ecuNode , nodeNameTmp)   % a tramsmit message
         msgName = (char(MsgNames(i)));
         sigCnts = length(db.MessageInfo(i).Signals) ;
         eval(['clear ' msgName])   % clear the original definition
         for j = 1:1:sigCnts
            sigName = char(db.MessageInfo(i).Signals(j));
            % sigName = char(extractAfter(sigName,'_'));
            eval([ 'CANTXD.' msgName '.' sigName '= single(0);'])
      end
        
     end     
 end
 tmp_BusName = Simulink.Bus.createObject(CANTXD);
 tmp_Bus = evalin('base',tmp_BusName.busName);
 evalin('base',['clear ' tmp_BusName.busName]);
 assignin('base','CANTXDST',tmp_Bus);
 CANTXDST.DataScope = 'Exported';
 CANTXDST.HeaderFile = 'rte_can.h';
 for i=1:1:length(CANTXDST.Elements)
 tmpmsg = CANTXDST.Elements(i).Name;
 eval([tmpmsg,'.DataScope = ''Exported'';']);
 eval([tmpmsg,'.HeaderFile = ''rte_can.h'';']);
 end
 clear tmp_BusName tmp_Bus nodeNameTmp
      
%% creat bus structure CANRXD 
clear CANRXD

 for i=1:1:MsgCnts
     nodeNameTmp = char(db.MessageInfo(i).TxNodes);
     
     if strcmp(hostNode , nodeNameTmp)   % a tramsmit message
         msgName = (char(MsgNames(i)));
         sigCnts = length(db.MessageInfo(i).Signals) ;
         eval(['clear ' msgName])
         for j = 1:1:sigCnts
            sigName = char(db.MessageInfo(i).Signals(j));
            % sigName = char(extractAfter(sigName,'_'));
            eval([ 'CANRXD.' msgName '.' sigName '= single(0);'])
         end
     end     
 end
 tmp_BusName = Simulink.Bus.createObject(CANRXD);
 tmp_Bus = evalin('base',tmp_BusName.busName);
 evalin('base',['clear ' tmp_BusName.busName]);
 assignin('base','CANRXDST',tmp_Bus);
  CANRXDST.DataScope = 'Exported';
 CANRXDST.HeaderFile = 'rte_can.h';
 for i=1:1:length(CANRXDST.Elements)
 tmpmsg = CANRXDST.Elements(i).Name;
 eval([tmpmsg,'.DataScope = ''Exported'';']);
 eval([tmpmsg,'.HeaderFile = ''rte_can.h'';']);
 end
 clear tmp_BusName tmp_Bus nodeNameTmp tmpmsg
 
 clear db dbcfile ecuNode hostNode
 clear msgName MsgName  MsgStruct
 clear i j MsgCnts sigCnts sigName
 

