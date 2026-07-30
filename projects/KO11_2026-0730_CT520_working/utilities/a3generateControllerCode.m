%% Generate the model c code
% Use the Simulink Coder API to generate code for controllerModel:
if~(exist('mdlNameBlank','var')==1)
    a2LoadEnviornment;
end

%% delete the shared folder to recollect the data
cd([mdlRoot '/work']);  
sharedPath = [mdlRoot '/work/slprj'];
if exist(sharedPath,'dir')==7
    rmdir(sharedPath,'s'); 
end

%% Blank for code generate build and generate 
%controllerModel = mdlNameBlank;
%if(~bdIsLoaded(controllerModel))
%     open_system(controllerModel);
%end
%setActiveConfigSet(controllerModel, 'ERT');
%slbuild(controllerModel);
%coder.report.generate(controllerModel);
%close_system(controllerModel, 0);

%% core2 pmsmfoc build and generate 
controllerModel = mdlNameCore2;
if(~bdIsLoaded(controllerModel))
     open_system(controllerModel);
end
%setActiveConfigSet(controllerModel, 'ERT');
slbuild(controllerModel);
coder.asap2.export(controllerModel, 'Version', '1.31', 'SupportStructureElements', false);
%coder.report.generate(controllerModel);
close_system(controllerModel, 0);

controllerModel = mdlNameCore2_1;
if(~bdIsLoaded(controllerModel))
     open_system(controllerModel);
end
%setActiveConfigSet(controllerModel, 'ERT');
slbuild(controllerModel);
coder.asap2.export(controllerModel, 'Version', '1.31', 'SupportStructureElements', false);
%coder.report.generate(controllerModel);
close_system(controllerModel, 0);
%% core0 basic build and generate 
%controllerModel = mdlNameCore0;
%if(~bdIsLoaded(controllerModel))
%     open_system(controllerModel);
%end
%setActiveConfigSet(controllerModel, 'ERT');
%slbuild(controllerModel);
%coder.report.generate(controllerModel);
close_system(controllerModel, 0);

%% core1 monitor build and generate 
%controllerModel = mdlNameCore1;
%if(~bdIsLoaded(controllerModel))
%     open_system(controllerModel);
%end
%setActiveConfigSet(controllerModel, 'ERT');
%slbuild(controllerModel);
%coder.report.generate(controllerModel);
close_system(controllerModel, 0);

disp('/*********************************************************/');
disp('/****************Step a3 done*****************************/');
disp('/*********************************************************/');

