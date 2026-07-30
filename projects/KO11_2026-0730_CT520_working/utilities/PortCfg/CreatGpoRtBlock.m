%% Guideline
% update the simulink model as the interface changed.
% Creat GPO slx model
% name the signal
%     name = GPOST.Elements(i).Name;
%     signalName = ['SAQ_' name];
%     ph = get_param(gcb,'PortHandles');
%     lh = get_param(ph.Outport,'Line');
%     set_param(lh,'Name',signalName);
% get the parameter of port of block ,eg. Position. the parameters are read only
%     get_param(gcb,'PortConnectivity');

%%
if (~exist('GPOST','var')==1)
    DefineBusFrmXls;
end

%%
% creat a slx file
modelName = [mdlNameCore0 '/OSP/GpoRt'];
if(~bdIsLoaded(mdlNameCore0))
     open_system(mdlNameCore0);
 end
open_system(modelName);
%% delete all the blocks and lines first
blkPos = get_param(modelName,'position');
delete_block(modelName)
add_block('simulink/Ports & Subsystems/Subsystem', modelName)
blkPosOld = blkPos;
set_param(modelName,'position',blkPosOld+10);
inName = [modelName '/' 'In1'];
outName = [modelName '/' 'Out1'];
delete_line(modelName,'In1/1','Out1/1');

%% define two strings for display on the icon for readbility
% tmpx = get_param(gcbh,'Value');
% a= evalin('base',[tmpx,'.Value;']);
% if a==0
%     color('blue');
% else
%     color('green');
% end
% disp([tmpx,':',num2str(a)]);
MaskDisplay =['tmpx = get_param(gcbh,''Value'');',newline,...
              'a= evalin(''base'',[tmpx,''.Value;'']);',newline,...
              'if a==0',newline,...
              '    color(''blue'');',newline,...
              'else',newline,...
              '    color(''green'');',newline,...
              'end',newline,...
               'disp([tmpx,'': '',num2str(a)]);'];
% tmpx = get_param(gcbh,'Value');
% a= evalin('base',[tmpx,'.Value;']);
% disp([tmpx,':',num2str(a)]);
MaskDisplayValue =['tmpx = get_param(gcbh,''Value'');',newline,...
              'a= evalin(''base'',[tmpx,''.Value;'']);',newline,...
               'disp([tmpx,'': '',num2str(a)]);'];


%% Creat the model GPOST
 % input pin
 sigCnts = length(GPOST.Elements);


% bus creator
busName = 'DinCr';
busBlkName = [modelName '/' busName];
blkPos = [650 70 670 70+80*sigCnts];
add_block('simulink/Signal Routing/Bus Creator',busBlkName);
set_param(busBlkName,'position',blkPos); 
set_param(busBlkName,'Inputs',num2str(sigCnts));
   
%outport
outName = 'Gpo';
outBlkName = [modelName '/' outName];
set_param([modelName '/Out1' ],'Name',outName);
blkPos = [740,70+80*sigCnts/2-10,780,70+80*sigCnts/2+10];
%add_block('simulink/Sinks/Out1',outBlkName);
set_param(outBlkName,'position',blkPos);  
add_line(modelName,[busName '/1'],[outName '/1']);
 
 
 
for i = 1:1:sigCnts
    selSig=GPOST.Elements(i).Name;
    sigName = selSig;
    % constant1 block, overrid control
    cnst1Name = [sigName,'Ovrd_C'];
    cnst1BlkName = [modelName '/' cnst1Name ];        %xOvrd_C
    blkPos = [180,i*80+20,310,40+i*80];
    add_block('simulink/Sources/Constant',cnst1BlkName);
    set_param(cnst1BlkName,'position',blkPos);
    set_param(cnst1BlkName,'Value',cnst1Name);
    set_param(cnst1BlkName,'ShowName','off');
    p = Simulink.Mask.create(cnst1BlkName);
    p.Display = MaskDisplay;
     % constant2 block
    cnst2Name = [sigName,'Mdl_C'];
    cnst2BlkName = [modelName '/' cnst2Name ];        %xMdl_C
    blkPos = [180,i*80,310,20+i*80];
    add_block('simulink/Sources/Constant',cnst2BlkName);
    set_param(cnst2BlkName,'position',blkPos);
    set_param(cnst2BlkName,'value',cnst2Name);
    set_param(cnst2BlkName,'ShowName','off');
    p = Simulink.Mask.create(cnst2BlkName);
    p.Display = MaskDisplayValue;
    % in block
    inName = sigName;
    inBlkName = [modelName '/' inName];  
    blkPos = [60,i*80+40,100,60+i*80];
    add_block('simulink/Sources/In1',inBlkName);
    set_param(inBlkName,'position',blkPos);
    set_param(inBlkName,'ShowName','on');

    % switch block
    swtName = ['switch' num2str(i)];
    swtBlkName = [modelName '/' swtName ];        %Switch
    blkPos = [350,i*80,390,60+i*80];
    add_block('simulink/Signal Routing/Switch',swtBlkName);
    set_param(swtBlkName,'position',blkPos);
    set_param(swtBlkName,'ShowName','off');
    set_param(swtBlkName,'InputSameDT','on');
    % datatype conversion block
    boolName = ['bool' num2str(i)];
    boolBlkName = [modelName '/' boolName ];        %Switch
    blkPos = [180,i*80+40,310,60+i*80];
    add_block('simulink/Signal Attributes/Data Type Conversion',boolBlkName);
    set_param(boolBlkName,'position',blkPos);
    set_param(boolBlkName,'ShowName','off');
    set_param(boolBlkName,'OutDataTypeStr','boolean');
    
    % SetDo conversion block
    doName = ['do' num2str(i)];
    doBlkName = [modelName '/' doName ];        %Switch
    blkPos = [500,i*80+20,600,40+i*80];
    add_block('IOLib/SetDo',doBlkName);
    set_param(doBlkName,'position',blkPos);
    set_param(doBlkName,'ShowName','off');
    
               
        
            % add lines
            add_line(modelName,[inName '/1' ],[boolName '/1']);
            add_line(modelName,[cnst1Name '/1'],[swtName '/2']); 
            add_line(modelName,[cnst2Name '/1'],[swtName '/1']); 
            add_line(modelName,[swtName '/1'],[doName '/1']);
            add_line(modelName,[doName '/1'],[busName '/' num2str(i)]); 
            add_line(modelName,[boolName '/1'],[swtName '/3']); 
%             ptmp = get_param(subselblockname,'PortHandles');
%             p = ptmp(k);
%             set_param(p.Outport,'Name',['SAQ_' sigName],'MustResolveToSignalObject','on');
             p = get_param(swtBlkName,'PortHandles');
             set_param(p.Outport,'Name',['ISP_b' sigName],'MustResolveToSignalObject','on');
    
             % check the enumeration channel
            set_param([doBlkName '/Enumerated Constant'],'OutDataTypeStr',['Enum: EGPO']);
            set_param([doBlkName '/Enumerated Constant'],'Value',['EGPO.' sigName]);
            set_param(doBlkName,'LinkStatus','inactive');  % disable the link
            if strcmp(sigName,'LED0')       || ...          % comment out LED0
               strcmp(sigName,'LED1')       || ...          % comment out LED1
               strcmp(sigName,'LED2')       || ...          % comment out LED2
               strcmp(sigName,'L2ASCEN')    || ...          % comment out L2ASCEN
               strcmp(sigName,'ENCAN')      || ...          % comment out ENCAN
               strcmp(sigName,'NSTBCAN')                    % comment out NSTBCAN        
               
               set_param(doBlkName ,'Commented','on');      
               set_param(boolBlkName ,'Commented','on');    % comment out L2ASCEN
               set_param(swtBlkName ,'Commented','on');     % comment out L2ASCEN
               set_param(cnst1BlkName ,'Commented','on');   % comment out L2ASCEN
               set_param(cnst2BlkName ,'Commented','on');   % comment out L2ASCEN
            end

    
end
 delete_block([modelName '/In1']);
 set_param(modelName,'position',blkPosOld); % set the position again
 save_system(mdlNameCore0);
 
% save_system(modelName);
% close_system(modelName);
% movefile([modelName '.slx'], [controllerPath filesep modelName 'Gen.slx'],'f');
% 
clear blockName modelName signalName rtBlockName boolBlkName
clear outBusName outPortName inBusName inPortName boolName
clear controllerPath blkPosOld blkPos
clear  outputSignalNumber inputSignalNumber selsig
clear i j p
clear lh ph
clear posLeft posTop posRight posBottom inBusInPortPos inBusPortConn inBusOutPortPos