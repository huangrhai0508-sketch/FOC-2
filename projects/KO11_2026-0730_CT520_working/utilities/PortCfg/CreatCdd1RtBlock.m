%% Guideline
% update the simulink model as the interface changed.
% SAQ_xxx simulink signals must be created previously.
% Creat cddRt block in Monitor.slx model
% name the signal
%     name = CDDIN1ST.Elements(i).Name;
%     signalName = ['SAQ_' name];
%     ph = get_param(gcb,'PortHandles');
%     lh = get_param(ph.Outport,'Line');
%     set_param(lh,'Name',signalName);
% get the parameter of port of block ,eg. Position. the parameters are read only
%     get_param(gcb,'PortConnectivity');
%%

if (~exist('CDDIN1ST','var')==1)
    DefineBusFrmXls
end


%%
% creat a slx file
modelName = [mdlNameCore1 '/SAQ/cddRt'];
if(~bdIsLoaded(mdlNameCore1))
     open_system(mdlNameCore1);
 end
open_system(modelName);
%% delete all the blocks and lines first
blkPos = get_param(modelName,'position');
delete_block(modelName);
add_block('simulink/Ports & Subsystems/Subsystem', modelName)
set_param(modelName,'position',blkPos)
inName = [modelName '/' 'In1'];
outName = [modelName '/' 'Out1'];
delete_line(modelName,'In1/1','Out1/1');


%% Creat the model VADC
 % input pin
inPortName = 'cddSt';
blockName = [modelName '/' inPortName];
set_param(inName,'Name',inPortName)
set_param(blockName,'position',[200 780 240 800]);
% set_param(blockName,'OutDataTypeStr','Inherit: auto');

% bus selector for input pin
inBusName = 'bussel';
blockName = [modelName '/' inBusName];
add_block('simulink/Signal Routing/Bus Selector',blockName);
outputSignalNumber = length(CDDIN1ST.Elements);
% 坐标设置，以BUS Selector为基准，inPort与outPort同BUS Selector的输入口对齐
% Rate Transition的中心与相应的BUS Selector输出口对齐
% BUS Selector和BUS Creator的纵坐标相同
posLeft = 300;
posTop = 100;
posRight = 310;
posBottom = 70+50*outputSignalNumber;
% set_param(blockName,'position',[250 70 260 20+50*outputSignalNumber]);
set_param(blockName,'position',[posLeft posTop posRight posBottom]);
selsig = '';
for i = 1:outputSignalNumber
        name = CDDIN1ST.Elements(i).Name;
        signalName = name;%['ADC_' name];        
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

% bus for out pin
outBusName = 'buscrt';
blockName = [modelName '/' outBusName];
add_block('simulink/Signal Routing/Bus Creator',blockName);
set_param(blockName,'position',[posLeft+400 posTop posRight+400 posBottom]);
% set_param(blockName,'position',[500 100 510 70+50*outputSignalNumber]);
set_param(blockName,'Inputs',num2str(outputSignalNumber));
% outBusPortConn = get_param(gcb,'PortConnectivity');
% outBusPortPosArr =  outBusPortConn.Position;

% port for outport
outPortName = 'cddSig';
blockName = [modelName '/' outPortName];
set_param(outName,'Name',outPortName)
% set_param(blockName,'position',[600 780 640 800]);
% set_param(blockName,'OutDataTypeStr','Inherit: auto');
set_param(blockName,'position',...
    [inBusInPortPos(1)+450 inBusInPortPos(2)-10 inBusInPortPos(1)+490 inBusInPortPos(2)+10]);
%add line and add RT block
add_line(modelName,[inPortName,'/1'],[inBusName,'/1']);
add_line(modelName,[outBusName,'/1'],[outPortName,'/1']);
for i = 1:outputSignalNumber
    rtBlockName = [modelName,'/rtBlock',num2str(i)];
    add_block('simulink/Signal Attributes/Rate Transition',rtBlockName);
    %获取BUS Selector第i个输出口坐标
    inBusPortPos =  inBusPortConn(i+1).Position;
    set_param(rtBlockName,'ShowName','off','Position',...
        [inBusPortPos(1)+110,inBusPortPos(2)-20,inBusPortPos(1)+150,inBusPortPos(2)+20]);
%     adcBlockName = [modelName,'/GetAdc',num2str(i)];
%     add_block('IOLib/GetAdc',adcBlockName);
%     set_param(adcBlockName,'ShowName','off','Position',...
%         [inBusPortPos(1)+200,inBusPortPos(2)-20,inBusPortPos(1)+300,inBusPortPos(2)+20]);

    add_line(modelName,[inBusName,'/',num2str(i)],['rtBlock',num2str(i),'/1']);
    add_line(modelName,['rtBlock',num2str(i),'/1'],[outBusName,'/',num2str(i)]);
    % name the signal
    name = CDDIN1ST.Elements(i).Name;
    signalName = ['SAQ_' name];
    ph = get_param(rtBlockName,'PortHandles');
    lh = get_param(ph.Outport,'Line');
    set_param(lh,'Name',signalName);
    set_param(ph.Outport,'MustResolveToSignalObject','on');
    set_param(rtBlockName ,'OutPortSampleTimeOpt','Inherit');

end


 save_system(mdlNameCore1);
% close_system(modelName);
% movefile([modelName '.slx'], [controllerPath filesep modelName 'Gen.slx'],'f');
% 
clear blockName modelName signalName rtBlockName
clear outBusName outPortName inBusName inPortName
clear controllerPath
clear  outputSignalNumber inputSignalNumber selsig
clear i j p
clear lh ph
clear posLeft posTop posRight posBottom inBusInPortPos inBusPortConn inBusOutPortPos