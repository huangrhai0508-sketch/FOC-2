%% Guideline


% generate CAN related according to the dbcFile.
currpath=cd();
cd([mdlRoot '\utilities\ComConf']);
ComConf;
cd(currpath);
clear currpath;

% modify the gpio and vadc configuration in BSW.
currpath=cd();
cd([mdlRoot '\utilities\PortCfg']);
hsiGen;
cd(currpath);
clear currpath;


disp('/*********************************************************/');
disp('/****************Step a4 done*****************************/');
disp('/*********************************************************/');