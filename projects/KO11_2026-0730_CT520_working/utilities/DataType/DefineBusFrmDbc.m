%% Guideline
% Read dbc file
% Creat structure:  CANTXD.EM01.sigxx           CANRXD.MSG01.sigyy
% the intermidiate message structure created automatically with the CANTXD CANRXD definition

%% get the dbc file
if ~((exist('dbcFile','var')==1)&&(exist('ecuNode','var')==1)&&(exist('ecuNode','var')==1)) 
    a1DefineProjectEnv;
end

%% open the dbc file 
db = canDatabase(dbcFile);
MsgCnts = length(db.Messages);
MsgNames = db.Messages;
MsgStruct = reverse(insertBefore(reverse(MsgNames),1,'_'));    %add '_' for the msg content structure

%% creat bus structure CANTXD 
clear CANTXD

for i=1:1:MsgCnts
    nodeNameTmp = char(db.MessageInfo(i).TxNodes);

    if strcmp(ecuNode , nodeNameTmp)   % a tramsmit message
        msgName = ['msg_' char(MsgNames(i))];
        sigCnts = length(db.MessageInfo(i).Signals) ;
        eval(['clear ' msgName])   % clear the original definition
        for j = 1:1:sigCnts
            sigName = char(db.MessageInfo(i).Signals(j));
            % sigName = char(extractAfter(sigName,'_'));
            if db.MessageInfo(i).SignalInfo(j).SignalSize==1
                sigType = 'boolean';
            else
                sigType = 'single';
            end
            eval([ 'CANTXD.' msgName '.' sigName '= ' sigType '(0);'])
        end
    end     
end
 
tmp_BusName = Simulink.Bus.createObject(CANTXD);
tmp_Bus = evalin('base',tmp_BusName.busName);
evalin('base',['clear ' tmp_BusName.busName]);
assignin('base','CANTXDST',tmp_Bus);
CANTXDST.DataScope = 'Auto';


for i=1:1:length(CANTXDST.Elements)
    tmpmsg = CANTXDST.Elements(i).Name;
    eval([tmpmsg,'.DataScope = ''Auto'';']);
    
end

clear tmp_BusName tmp_Bus nodeNameTmp 
      
%% creat bus structure CANRXD 
clear CANRXD

for i=1:1:MsgCnts
    nodeNameTmp = char(db.MessageInfo(i).TxNodes);

    if strcmp(hostNode , nodeNameTmp)   % a tramsmit message
        msgName = ['msg_' char(MsgNames(i))];
        sigCnts = length(db.MessageInfo(i).Signals) ;
        eval(['clear ' msgName])
        for j = 1:1:sigCnts
            sigName = char(db.MessageInfo(i).Signals(j));
            % sigName = char(extractAfter(sigName,'_'));
            if db.MessageInfo(i).SignalInfo(j).SignalSize==1
                sigType = 'boolean';
            else
                sigType = 'single';
            end
            eval([ 'CANRXD.' msgName '.' sigName '=' sigType '(0);'])
        end
    end     
end

tmp_BusName = Simulink.Bus.createObject(CANRXD);
tmp_Bus = evalin('base',tmp_BusName.busName);
evalin('base',['clear ' tmp_BusName.busName]);
assignin('base','CANRXDST',tmp_Bus);
CANRXDST.DataScope = 'Auto';

for i=1:1:length(CANRXDST.Elements)
    tmpmsg = CANRXDST.Elements(i).Name;
    eval([tmpmsg,'.DataScope = ''Auto'';']);
    
end
 
%% clear
clear tmp_BusName tmp_Bus nodeNameTmp tmpmsg CANRXD CANTXD
clear msgName MsgName  MsgStruct
clear i j MsgCnts sigCnts sigName
 