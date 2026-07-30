%% Guideline
% Read hsi file and generate the common bus info for high/low level interface
% Then write the bus info into the xlsFile
% The HW Accept items will be brought into the bus.
% members in VADCST/GPIST/GPOST are defined
%% hsi file handle
if ~(exist('hsiFile','var')==1)
    a1DefineProjectEnv;
end

tmp = strfind(hsiFile,'\');
xFile = [hsiFile(1:tmp(length(tmp))-1),'\hsiGenBus.xlsx'];       
clear tmp


%% read xFile busDefinition sheet, get the existed VADC0ST,GPIST,and GPOST
xTbl = readtable(xFile,'sheet','BusDefinition');
rowsVadc = contains(xTbl.SimulinkBusName,'VADC');
vadcstTbl = xTbl(rowsVadc,:);
rowsGpi = strcmp(xTbl.SimulinkBusName,'GPIST');
gpistTbl = xTbl(rowsGpi,:);
rowsGpo = strcmp(xTbl.SimulinkBusName,'GPOST');
gpostTbl = xTbl(rowsGpo,:);
rowsOther = ~(rowsGpo+rowsGpi+rowsVadc);
otherstTbl = xTbl(rowsOther,:);

%% read hsiFile£¬ get the target items
hsiTbl = readtable(hsiFile,'sheet','HSI','range','D8:N300');
rows = strcmp(hsiTbl.uCFun,'GPIO') & strcmp(hsiTbl.Accept,'Accept') & strcmp(hsiTbl.Dir,'I');
gpiTbl = hsiTbl(rows,{'ShortName','PinName'});
rows = strcmp(hsiTbl.uCFun,'GPIO') & strcmp(hsiTbl.Accept,'Accept') & strcmp(hsiTbl.Dir,'O');
gpoTbl = hsiTbl(rows,{'ShortName','PinName'});
rows = strcmp(hsiTbl.uCFun,'VADC') & strcmp(hsiTbl.Accept,'Accept') & strcmp(hsiTbl.Dir,'A');
vadcTbl = hsiTbl(rows,{'ShortName','PinName'});



%% gpiST
gpistTbl.Index = transpose(1:height(gpistTbl));     % Add index column
gpistTbl = sortrows(gpistTbl,'BusElementName');     % sort on the 
gpiTbl = sortrows(gpiTbl,'ShortName');              % sort on the
gpiRow = gpistTbl(1,:);
addRows = ~(ismember(gpiTbl.ShortName, gpistTbl.BusElementName));
delRows = (ismember( gpistTbl.BusElementName,gpiTbl.ShortName));

gpistTbl = gpistTbl(delRows,:); % delete rows not in the gpiTbl from hsi
gpiPart1Tbl = gpiTbl(~addRows,:);
gpiPart2Tbl = gpiTbl(addRows,:);
gpistTbl.ucPort = gpiPart1Tbl.PinName;
oldRows = height(gpistTbl);
newRows = sum(addRows);
if newRows>0
     for i=1:1:newRows
        gpistTbl = [gpistTbl;gpiRow];
    end
end
gpistTbl(oldRows+1:oldRows+newRows,:).BusElementName = gpiPart2Tbl.ShortName;
gpistTbl(oldRows+1:oldRows+newRows,:).ucPort = gpiPart2Tbl.PinName;
gpistTbl(oldRows+1:oldRows+newRows,:).Index = transpose((1:newRows)+100);
gpistTbl = sortrows(gpistTbl,'Index');
gpistTbl = gpistTbl(:,1:width(gpistTbl)-1);

%% gpoST
gpostTbl.Index = transpose(1:height(gpostTbl));     % Add index column
gpostTbl = sortrows(gpostTbl,'BusElementName');     % sort on the 
gpoTbl = sortrows(gpoTbl,'ShortName');              % sort on the
gpoRow = gpostTbl(1,:);
addRows = ~(ismember(gpoTbl.ShortName, gpostTbl.BusElementName));
delRows = (ismember( gpostTbl.BusElementName,gpoTbl.ShortName));

gpostTbl = gpostTbl(delRows,:); % delete rows not in the gpoTbl from hsi
gpoPart1Tbl = gpoTbl(~addRows,:);
gpoPart2Tbl = gpoTbl(addRows,:);
gpostTbl.ucPort = gpoPart1Tbl.PinName;
oldRows = height(gpostTbl);
newRows = sum(addRows);
if newRows>0
     for i=1:1:newRows
        gpostTbl = [gpostTbl;gpoRow];
    end
end
gpostTbl(oldRows+1:oldRows+newRows,:).BusElementName = gpoPart2Tbl.ShortName;
gpostTbl(oldRows+1:oldRows+newRows,:).ucPort = gpoPart2Tbl.PinName;
gpostTbl(oldRows+1:oldRows+newRows,:).Index = transpose((1:newRows)+100);
gpostTbl = sortrows(gpostTbl,'Index');
gpostTbl = gpostTbl(:,1:width(gpostTbl)-1);


%% vadcST
vadcstTbl.Index = transpose(1:height(vadcstTbl));     % Add index column
vadcstTbl = sortrows(vadcstTbl,'BusElementName');     % sort on the 
vadcTbl = sortrows(vadcTbl,'ShortName');              % sort on the
vadcRow = vadcstTbl(1,:);
vadcRow.SimulinkBusName = 'VADCST';

addRows = ~(ismember(vadcTbl.ShortName, vadcstTbl.BusElementName));
delRows = (ismember( vadcstTbl.BusElementName,vadcTbl.ShortName));

vadcstTbl = vadcstTbl(delRows,:); % delete rows not in the vadcTbl from hsi
vadcPart1Tbl = vadcTbl(~addRows,:);
vadcPart2Tbl = vadcTbl(addRows,:);
vadcstTbl.ucPort = vadcPart1Tbl.PinName;
oldRows = height(vadcstTbl);
newRows = sum(addRows);
if newRows>0
     for i=1:1:newRows
        vadcstTbl = [vadcstTbl;vadcRow];
    end
end
vadcstTbl(oldRows+1:oldRows+newRows,:).BusElementName = vadcPart2Tbl.ShortName;
vadcstTbl(oldRows+1:oldRows+newRows,:).ucPort = vadcPart2Tbl.PinName;
vadcstTbl(oldRows+1:oldRows+newRows,:).Index = transpose((1:newRows)+100);
vadcstTbl = sortrows(vadcstTbl,'Index');
vadcstTbl = vadcstTbl(:,1:width(vadcstTbl)-1);

%% write back to the File
% sort according to the bus name
xTbl=[vadcstTbl;gpistTbl;gpostTbl;otherstTbl];
xTbl = sortrows(xTbl,2);
writetable(xTbl,xFile,'sheet','BusDefinition');


clear xTbl hsiTbl xFile
clear rows newRow i elem
clear gpiTbl gpoTbl vadcTbl vadc0Tbl
clear gpistTbl gpostTbl vadc0stTbl vadcstTbl
clear gpoRow gpiRow vadc0Row
clear addRows delRows








