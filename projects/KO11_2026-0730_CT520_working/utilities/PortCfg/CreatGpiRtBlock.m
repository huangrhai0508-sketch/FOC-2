%% Guideline
% update the simulink model as the interface changed.
% Creat GPI slx model
% name the signal
%     name = GPIST.Elements(i).Name;
%     signalName = ['SAQ_' name];
%     ph = get_param(gcb,'PortHandles');
%     lh = get_param(ph.Outport,'Line');
%     set_param(lh,'Name',signalName);
% get the parameter of port of block ,eg. Position. the parameters are read only
%     get_param(gcb,'PortConnectivity');

%%

if (~exist('GPIST','var')==1)
    DefineBusFrmXls;
end

%%
% creat a slx file
modelName = [mdlNameCore0 '/SAQ/gpiRt'];
if(~bdIsLoaded(mdlNameCore0))
     open_system(mdlNameCore0);
 end
open_system(modelName);
%% delete all the blocks and lines first
blkPos = get_param(modelName,'position');
delete_block(modelName)
add_block('simulink/Ports & Subsystems/Subsystem', modelName)
set_param(modelName,'position',blkPos)
inName = [modelName '/' 'In1'];
outName = [modelName '/' 'Out1'];
delete_line(modelName,'In1/1','Out1/1');


%% Creat the model GPIST
 % out pin
inPortName = 'gpiSt';
blockName = [modelName '/' inPortName];
set_param(inName,'Name',inPortName)
% set_param(blockName,'position',[200 300 240 320]);
% set_param(blockName,'OutDataTypeStr','Inherit: auto');

% bus for out pin
inBusName = 'bussel';
blockName = [modelName '/' inBusName];
add_block('simulink/Signal Routing/Bus Selector',blockName);
inputSignalNumber = length(GPIST.Elements);
% 坐标设置，以BUS Selector为基准，inPort与outPort同BUS Selector的输入口对齐
% Rate Transition的中心与相应的BUS Selector输出口对齐
% BUS Selector和BUS Creator的纵坐标相同
posLeft = 300;
posTop = 100;
posRight = 310;
posBottom = 70+50*inputSignalNumber;
set_param(blockName,'position',[posLeft posTop posRight posBottom]);
% set_param(blockName,'position',[300 100 310 70+50*inputSignalNumber]);

% set_param(blockName,'OutDataTypeStr','BUS: CANRXD');
% set_param(blockName,'Inputs','50');
selsig = '';
for i = 1:inputSignalNumber
        name = GPIST.Elements(i).Name;
        signalName = name; %['ACI_' name];
        if isempty(selsig)
            selsig = signalName;
        else
            selsig = [selsig,',',signalName];
        end
end
set_param(blockName,'OutputSignals',selsig);
inBusPortConn = get_param(blockName,'PortConnectivity');
% outBusPortPosArr =  outBusPortConn.Position;
%读取BUS Selector的输入口坐标值[x,y]
inBusInPortPos = inBusPortConn(1).Position;
%设置inport的坐标及大小
set_param([modelName '/' inPortName],'position',...
    [inBusInPortPos(1)-140 inBusInPortPos(2)-10 inBusInPortPos(1)-100 inBusInPortPos(2)+10]);


outBusName = 'busCrt';
blockName = [modelName,'/',outBusName];
add_block('simulink/Signal Routing/Bus Creator',blockName);
set_param(blockName,'Position',[posLeft+400 posTop posRight+400 posBottom])
set_param(blockName,'Inputs',num2str(inputSignalNumber));

outPortName = 'gpiSig';
blockName = [modelName '/' outPortName];
set_param(outName,'Name',outPortName)
% set_param(blockName,'position',[800 300 840 320]);
%set_param(blockName,'OutDataTypeStr','Inherit: auto');
set_param(blockName,'position',...
    [inBusInPortPos(1)+450 inBusInPortPos(2)-10 inBusInPortPos(1)+490 inBusInPortPos(2)+10]);


add_line(modelName,[inPortName,'/1'],[inBusName,'/1']);
add_line(modelName,[outBusName,'/1'],[outPortName,'/1']);
for i = 1:inputSignalNumber
    rtBlockName = [modelName,'/rtBlock',num2str(i)];
    add_block('simulink/Signal Attributes/Rate Transition',rtBlockName);
    inBusOutPortPos =  inBusPortConn(i+1).Position;
    set_param(rtBlockName,'ShowName','off','Position',...
        [inBusOutPortPos(1)+110,inBusOutPortPos(2)-20,inBusOutPortPos(1)+150,inBusOutPortPos(2)+20]);
%     set_param(rtBlockName,'position',[500 75+45*i 550 95+45*i]);
    diBlockName = [modelName,'/GetDi',num2str(i)];
    add_block('IOLib/GetDi',diBlockName);
    set_param(diBlockName,'ShowName','off','Position',...
        [inBusOutPortPos(1)+200,inBusOutPortPos(2)-20,inBusOutPortPos(1)+300,inBusOutPortPos(2)+20]);

    add_line(modelName,[inBusName,'/',num2str(i)],['rtBlock',num2str(i),'/1']);
    add_line(modelName,['rtBlock',num2str(i),'/1'],['GetDi',num2str(i),'/1']);
    add_line(modelName,['GetDi',num2str(i),'/1'],[outBusName,'/',num2str(i)]);
    % name the signal
    name = GPIST.Elements(i).Name;
    signalName = ['SAQ_' name];    
    ph = get_param(diBlockName,'PortHandles');
    lh = get_param(ph.Outport,'Line');
    set_param(lh,'Name',signalName);
    set_param(ph.Outport,'MustResolveToSignalObject','on');
    % check the enumeration channel
    set_param([diBlockName '/Enumerated Constant'],'OutDataTypeStr',['Enum: EGPI']);
    set_param([diBlockName '/Enumerated Constant'],'Value',['EGPI.' name]);
    set_param(diBlockName,'LinkStatus','inactive');  % disable the link
    set_param(rtBlockName ,'OutPortSampleTimeOpt','Inherit');
end

 save_system(mdlNameCore0);
% close_system(modelName);

clear blockName modelName signalName rtBlockName
clear outBusName outPortName inBusName inPortName
clear controllerPath
clear  outputSignalNumber inputSignalNumber selsig
clear i j p
clear lh ph
clear posLeft posTop posRight posBottom inBusInPortPos inBusPortConn inBusOutPortPos