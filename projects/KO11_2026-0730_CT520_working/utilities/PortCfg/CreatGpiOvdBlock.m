%% Guideline
% creat block which include all the digital input override
% Signal path:
% in            Par1         Par2       out
% SAQ_x         xOvrd_C   xMdl_C     ISC_bx   --> bus creator

%% file handle
if (~exist('GPIST','var')==1)
    DefineBusFrmXls;
end

%% creat a slx file
modelName = [mdlNameCore0 '/ISP/ISP_DIN/DigIn'];
if(~bdIsLoaded(mdlNameCore0))
     open_system(mdlNameCore0);
end
open_system(modelName);

%% delete all the blocks and lines first
blkPos = get_param(modelName,'position');
delete_block(modelName)
add_block('simulink/Ports & Subsystems/Subsystem', modelName)
set_param(modelName,'position',blkPos)
delete_line(modelName,'In1/1','Out1/1');

%% display on the icon for readbility
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


%% Creat the model
sigCnts = length(GPIST.Elements);
%inport
inName = 'SAQ';
inBlkNamename = [modelName '/' inName];
set_param([modelName '/In1' ],'Name',inName);
blkPos = [-40,90+80*sigCnts/2-10,0,90+80*sigCnts/2+10];
% add_block('simulink/Sources/In1',inBlkNamename);
set_param(inBlkNamename,'position',blkPos);  
%set_param(inBlkNamename,'OutDataTypeStr','Bus: GPIST');

% bus select
selName = 'Sel';
selBlkName = [modelName '/' selName];
blkPos = [40 90 60 90+80*sigCnts];
add_block('simulink/Signal Routing/Bus Selector',selBlkName);
add_line(modelName,[inName '/1'],[selName '/1']);
set_param(selBlkName,'position',blkPos); 
selSigs='';
for i=1:1:sigCnts
    selSigs =[selSigs,',','gpiRt.SAQ_',GPIST.Elements(i).Name];
end
selSigs=selSigs(2:length(selSigs));
set_param(selBlkName,'OutputSignals',selSigs);

% bus creator
busName = 'DinCr';
busBlkName = [modelName '/' busName];
blkPos = [550 70 570 70+80*sigCnts];
add_block('simulink/Signal Routing/Bus Creator',busBlkName);
set_param(busBlkName,'position',blkPos); 
set_param(busBlkName,'Inputs',num2str(sigCnts));
   
%outport
outName = 'ISC_DIN';
outBlkName = [modelName '/' outName];
set_param([modelName '/Out1' ],'Name',outName);
blkPos = [640,70+80*sigCnts/2-10,680,70+80*sigCnts/2+10];
%add_block('simulink/Sinks/Out1',outBlkName);
set_param(outBlkName,'position',blkPos);  
add_line(modelName,[busName '/1'],[outName '/1']);


for i = 1:1:sigCnts
    selSig=GPIST.Elements(i).Name;
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
    cnst2blockname = [modelName '/' cnst2Name ];        %xMdl_C
    blkPos = [180,i*80,310,20+i*80];
    add_block('simulink/Sources/Constant',cnst2blockname);
    set_param(cnst2blockname,'position',blkPos);
    set_param(cnst2blockname,'value',cnst2Name);
    set_param(cnst2blockname,'ShowName','off');
    p = Simulink.Mask.create(cnst2blockname);
    p.Display = MaskDisplayValue;
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
               
        
            % add lines
            add_line(modelName,[selName '/' num2str(i)],[boolName '/1']);
            add_line(modelName,[cnst1Name '/1'],[swtName '/2']); 
            add_line(modelName,[cnst2Name '/1'],[swtName '/1']); 
            add_line(modelName,[swtName '/1'],[busName '/' num2str(i)]); 
            add_line(modelName,[boolName '/1'],[swtName '/3']); 
%             ptmp = get_param(subselblockname,'PortHandles');
%             p = ptmp(k);
%             set_param(p.Outport,'Name',['SAQ_' sigName],'MustResolveToSignalObject','on');
             p = get_param(swtBlkName,'PortHandles');
             set_param(p.Outport,'Name',['ISP_b' sigName],'MustResolveToSignalObject','on');
    
    
    
end


 save_system(mdlNameCore0);
 open_system(modelName);
% close_system(modelName);

 vars = {'p','l','modelname','i','m','n','raw','txt','p1','busblockname','blockposition','getSignals','SignalStart','inblockname','outblockname','num','SignalColunm','SignalName','SignalsCount'};
 clear(vars{:});
 clear vars;
 vars = {'busName','outName','cnst1Name','cnst2Name','swtName','inName','SigName','swtblockname','cnst1blockname','cnst2blockname',''};
  clear(vars{:});
 clear vars;
 clear busBlkName blkPos boolBlkName