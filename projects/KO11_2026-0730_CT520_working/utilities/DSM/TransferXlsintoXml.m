%% Guideline
% transfer the xls file into xml file
% All dsm info are defined in xls file.
% shall be run before DsmGen.bat
%% file handle
if ~(exist('mdlRoot','var')==1)
    a1DefineProjectEnv;
end

%% read xml file
% xmlFile = '1.XML';
% xDoc = xmlread(xmlFile);
% 
% dfcInXml = xDoc.getElementsByTagName('DSM_DFC');
% fidInXml = xDoc.getElementsByTagName('DSM_FID');
% dfcTblInXml = table; 
% fidTblInXml = table;
% 
% for i=0:dfcInXml.getLength-1
%     dfcItem = dfcInXml.item(i);
%     dfcName = cell(dfcItem.item(1).getFirstChild.getData);
%     dfcDesc = cell(dfcItem.item(3).getFirstChild.getData);
%     dfcDeb = cell(dfcItem.item(5).getFirstChild.getData);
%     dfcCal = cell(dfcItem.item(7).getFirstChild.getData);
%     dfcCnt = cell(dfcItem.item(9).getFirstChild.getData);
%     dfcMil = cell(dfcItem.item(11).getFirstChild.getData);
%     dfcInit = cell(dfcItem.item(13).getFirstChild.getData);
%     dfcTbl=table(dfcName,dfcDesc,dfcDeb,dfcCal,dfcCnt,dfcMil,dfcInit);
%     dfcTblInXml = [dfcTblInXml; dfcTbl];
% end
% 
% for i=0:fidInXml.getLength-1
%     fidItem = fidInXml.item(i);
%     fidName = cell(fidItem.item(1).getFirstChild.getData);
%     fidDesc = cell(fidItem.item(3).getFirstChild.getData);
%     fidInh = cell(fidItem.item(5).getFirstChild.getData);
%     fidPro = cell(fidItem.item(7).getFirstChild.getData);
%     fidTbl = table(fidName,fidDesc,fidInh,fidPro);
%     fidTblInXml = [fidTblInXml; fidTbl];
% end
% 
% clear dfcItem dfcName dfcDesc dfcDeb dfcCal dfcCnt dfcMil dfcInit;
% clear fidItem  fidName fidDesc fidInh fidPro;

%% read xlsx file


dfcTblInXls = readtable(dsmFile,'sheet','DSM DFC');
fidTblInXls = readtable(dsmFile,'sheet','DSM FID');

dfcName = dfcTblInXls.DFC;
dfcDesc = dfcTblInXls.Desc_____;
dfcDeb = dfcTblInXls.DSM_DEB_METHOD;
dfcCal = strcat(dfcTblInXls.DFC,dfcTblInXls.DebTime);
dfcCnt = cellstr(num2str(ones(height(dfcTblInXls),1)));
dfcMil = cellstr(num2str(ones(height(dfcTblInXls),1)));
dfcInit = cellstr(num2str(ones(height(dfcTblInXls),1)));
dfcTblInXls=table(dfcName,dfcDesc,dfcDeb,dfcCal,dfcCnt,dfcMil,dfcInit);

fidName = fidTblInXls.FID;
fidDesc = fidTblInXls.Desc;
fidInh  = fidTblInXls.DSM_IS_INHIBITED_BY;
fidPro = fidTblInXls.FID;
fidTblInXls = table(fidName,fidDesc,fidInh,fidPro);

clear dfcItem dfcName dfcDesc dfcDeb dfcCal dfcCnt dfcMil dfcInit;
clear fidItem  fidName fidDesc fidInh fidPro;

 %% merge tables
 dfcTblInXml = dfcTblInXls;
 fidTblInXml = fidTblInXls;

%% write table back into the xml file

docNode = com.mathworks.xml.XMLUtils.createDocument('CONF');
conf = docNode.getDocumentElement;
dsm = docNode.createElement('DSM');
conf.appendChild(dsm);

for i = 1:height(dfcTblInXml)
    dfcNode = docNode.createElement('DSM_DFC');
    
    dfcName = docNode.createElement('ELEMENT_NAME');
    dfcName.appendChild(docNode.createTextNode(dfcTblInXml.dfcName{i}));
    dfcNode.appendChild(dfcName);
    dfcDesc = docNode.createElement('DESC');
    dfcDesc.appendChild(docNode.createTextNode(dfcTblInXml.dfcDesc{i}));
    dfcNode.appendChild(dfcDesc);
    dfcDeb = docNode.createElement('DSM_DEB_METHOD');
    dfcDeb.appendChild(docNode.createTextNode(dfcTblInXml.dfcDeb{i}));
    dfcNode.appendChild(dfcDeb);
    dfcCal = docNode.createElement('DSM_CAL_PAR');
    dfcCal.appendChild(docNode.createTextNode(dfcTblInXml.dfcCal{i}));
    dfcNode.appendChild(dfcCal);
    dfcCnt = docNode.createElement('DSM_ELEMENT_COUNT');
    dfcCnt.appendChild(docNode.createTextNode(dfcTblInXml.dfcCnt{i}));
    dfcNode.appendChild(dfcCnt);
    dfcMil = docNode.createElement('DSM_MIL');
    dfcMil.appendChild(docNode.createTextNode(dfcTblInXml.dfcMil{i}));
    dfcNode.appendChild(dfcMil);
    dfcInit = docNode.createElement('DSM_RESET_AT_INIT');
    dfcInit.appendChild(docNode.createTextNode(dfcTblInXml.dfcInit{i}));
    dfcNode.appendChild(dfcInit);
    
    dsm.appendChild(dfcNode);
end



for i = 1:height(fidTblInXml)
    fidNode = docNode.createElement('DSM_FID');
    
    fidName = docNode.createElement('ELEMENT_NAME');
    fidName.appendChild(docNode.createTextNode(fidTblInXml.fidName{i}));
    fidNode.appendChild(fidName);
    fidDesc = docNode.createElement('DESC');
    fidDesc.appendChild(docNode.createTextNode(fidTblInXml.fidDesc{i}));
    fidNode.appendChild(fidDesc);
    fidInh = docNode.createElement('DSM_IS_INHIBITED_BY');
    fidInh.appendChild(docNode.createTextNode(fidTblInXml.fidInh{i}));
    fidNode.appendChild(fidInh);
    fidPro = docNode.createElement('DSM_PROVIDING');
    fidPro.appendChild(docNode.createTextNode(fidTblInXml.fidPro{i}));
    fidNode.appendChild(fidPro);
        
    dsm.appendChild(fidNode);
end
xmlwrite('INV_Diag_conf.xml',docNode);

clear dfcItem dfcName dfcDesc dfcDeb dfcCal dfcCnt dfcMil dfcInit;
clear fidItem  fidName fidDesc fidInh fidPro;


%% clear
clear dfcTblInXml dfcTbl dfcTblInXls dfcInXml dfcNode
clear fidTblInXml fidTbl fidTblInXls fidInXml fidNode
clear   i xDoc xlsFile xmlFile docNode dsm
