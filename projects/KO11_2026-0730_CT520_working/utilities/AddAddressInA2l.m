%% Guideline
% postbuild at a2l file
% fill address info in the simulink generated a2l file
% fill address info in the bsw a2lfile by pavast
% Merge the two a2l files

%% file handle
if ~((exist('mdlRoot','var')==1) && (exist('prjRoot','var')==1))
    a1DefineProjectEnv;
end

%% clear
clear elfFile hexFile  bswA2lFile  
clear slGenTxt a2lTxt 
clear pos1 pos2 key
clear sl_RECORD_LAYOUT_Txt 
clear sl_COMPU_METHOD_Txt
clear sl_CHARACTERISTIC_Txt
clear sl_MEASUREMENT_Txt
clear sl_RECORD_LAYOUT_Modify_Txt
clear i j
clear fid RlsA2lFile a2lFile0 a2lFile1 a2lFile2 slA2lFile0 slA2lFile1 slA2lFile2

% elf file
elfFile = [prjRoot  '\2_Out\Gnuc\'  prjName '_Tricore.elf'];
% simulink generated a2l file
slA2lFile0 = [mdlRoot filesep 'work\' mdlNameCore0 '_ert_rtw\' mdlNameCore0 '.a2l' ];
slA2lFile1 = [mdlRoot filesep 'work\' mdlNameCore1 '_ert_rtw\' mdlNameCore1 '.a2l' ];
slA2lFile2 = [mdlRoot filesep 'work\' mdlNameCore2 '_ert_rtw\' mdlNameCore2 '.a2l' ];
% slA2lFile3 = [prjRoot filesep 'cfg\A2L_Generator\Bsw_Pava.a2l'  ];
% slA2lFile4 = [prjRoot filesep '0_Src\4_CDrv\Cdd.a2l'  ];

% temperary a2l files with address
a2lFile0 = [mdlRoot filesep 'work\a2lFile0.a2l'];
a2lFile1 = [mdlRoot filesep 'work\a2lFile1.a2l'];
a2lFile2 = [mdlRoot filesep 'work\a2lFile2.a2l'];
% bswa2lFile = [mdlRoot filesep 'work\bswa2lFile.a2l' ];
% a2lFile4 = [mdlRoot filesep 'work\a2lFile4.a2l' ];

% bsw generated a2l file
headerA2lFile = [prjRoot filesep 'cfg\A2L_Generator\INVGEN2_Merged_A_Step.a2l' ];
RlsA2lFile = [prjRoot filesep 'cfg\' prjName '_Release.a2l' ];
testA2lFile = [prjRoot filesep 'cfg\test.a2l' ];

%% fill address info in the simulink generated a2l file
% get the calibratable and measurable info
copyfile(slA2lFile0,a2lFile0,'f');
rtw.asap2SetAddress(a2lFile0, elfFile);
copyfile(slA2lFile1,a2lFile1,'f');
rtw.asap2SetAddress(a2lFile1, elfFile);
copyfile(slA2lFile2,a2lFile2,'f');
rtw.asap2SetAddress(a2lFile2, elfFile);
% copyfile(slA2lFile3,bswa2lFile,'f');
% rtw.asap2SetAddress(bswa2lFile, elfFile);
% copyfile(slA2lFile4,a2lFile4,'f');
% rtw.asap2SetAddress(a2lFile4, elfFile);

% merge the three a2l files with address
a2lTxt = [  fileread(a2lFile0),newline,...
            fileread(a2lFile1),newline,...
            fileread(a2lFile2),newline,...
%             fileread(bswa2lFile),newline,...
%             fileread(a2lFile4),...
            ];

pos1 = strfind(a2lTxt,'RECORD_LAYOUT');
sl_RECORD_LAYOUT_Txt =[];
for i = 1:2:length(pos1)
    txtElement = [newline '    /begin ' a2lTxt(pos1(i):pos1(i+1)-1) 'RECORD_LAYOUT'];
    sl_RECORD_LAYOUT_Txt = [sl_RECORD_LAYOUT_Txt newline txtElement];
end
disp('/****************Extract RECORD_LAYOUT done**********************/');


pos1 = strfind(sl_RECORD_LAYOUT_Txt,'AXIS_PTS_Y 2');
New2DLayoutText = ['      AXIS_PTS_Y 1 FLOAT32_IEEE INDEX_INCR DIRECT' newline '      AXIS_PTS_X 2 FLOAT32_IEEE INDEX_INCR DIRECT'];
j = length(pos1);
sl_RECORD_LAYOUT_Modify_Txt = [sl_RECORD_LAYOUT_Txt(1:(pos1(1)-54)) New2DLayoutText]; % sl_RECORD_LAYOUT_Txt((pos1(1)+45):)
for i=2:1:j
    sl_RECORD_LAYOUT_Modify_Txt = [sl_RECORD_LAYOUT_Modify_Txt newline sl_RECORD_LAYOUT_Txt((pos1(i-1)+45):(pos1(i)-54)) newline New2DLayoutText];
end
sl_RECORD_LAYOUT_Modify_Txt = [sl_RECORD_LAYOUT_Modify_Txt newline sl_RECORD_LAYOUT_Txt((pos1(j)+45):length(sl_RECORD_LAYOUT_Txt))];
disp('/****************Change XY axis in 2-D Map done******************/');


pos1 = strfind(a2lTxt,'COMPU_METHOD');
sl_COMPU_METHOD_Txt =[];
for i = 1:2:length(pos1)
    txtElement = [newline '    /begin ' a2lTxt(pos1(i):pos1(i+1)-1) 'COMPU_METHOD'];
    sl_COMPU_METHOD_Txt = [sl_COMPU_METHOD_Txt newline txtElement];
end
pos1 = strfind(a2lTxt,'COMPU_VTAB');    % the method for enumerator contains compu_vtab
for i = 1:2:length(pos1)
    txtElement = [newline '    /begin ' a2lTxt(pos1(i):pos1(i+1)-1) 'COMPU_VTAB'];
    sl_COMPU_METHOD_Txt = [sl_COMPU_METHOD_Txt newline txtElement];
end
disp('/****************Extract COMPU_METHOD done***********************/');

pos1 = strfind(a2lTxt,' CHARACTERISTIC');
sl_CHARACTERISTIC_Txt =[];
for i = 1:2:length(pos1)
    txtElement = [newline '    /begin' a2lTxt(pos1(i):pos1(i+1)-1) ' CHARACTERISTIC'];
    sl_CHARACTERISTIC_Txt = [sl_CHARACTERISTIC_Txt newline txtElement];
end
disp('/****************Extract CHARACTERISTIC done*********************/');

pos1 = strfind(a2lTxt,' MEASUREMENT');
sl_MEASUREMENT_Txt =[];
for i = 1:2:length(pos1)
    txtElement = [newline '    /begin' a2lTxt(pos1(i):pos1(i+1)-1) ' MEASUREMENT']; % no space for begin and 1 space for MEASUREMENT
    sl_MEASUREMENT_Txt = [sl_MEASUREMENT_Txt newline txtElement];
end
disp('/****************Extract MEASUREMENT done*********************/');


%%
%delete the structure define
%delete the structure define
key = 'ECU_ADDRESS                       0x0000 /* @';          % key is remained after the address added
keyStart = '/begin MEASUREMENT';                               % one space beteen begin and MEASUREMENT
keyStop = '/end MEASUREMENT';                                  % one space beteen end and MEASUREMENT
pos = strfind(sl_MEASUREMENT_Txt,key);
while ~isempty(pos)
    pos1 = pos(1);                                              %get the first key position in the sl_MEASUREMENT_Txt
    posStart = strfind(sl_MEASUREMENT_Txt(1:pos1),keyStart);    
    posStart = posStart(length(posStart));                      %get the /begin  MEASUREMENT near the first key
    posStop = strfind(sl_MEASUREMENT_Txt(pos1:pos1+500),keyStop);
    posStop = posStop(1)+pos1+length(keyStop);                  %get the /end  MEASUREMENT near the first key
    delBlk = sl_MEASUREMENT_Txt(posStart:posStop);              
    sl_MEASUREMENT_Txt = replace(sl_MEASUREMENT_Txt,delBlk,''); % delete the block defined by posStart posStop
    pos = strfind(sl_MEASUREMENT_Txt,key);
end


delete(a2lFile0);
delete(a2lFile1);
delete(a2lFile2);
% delete(bswa2lFile);
% delete(a2lFile4);
 
%% Add slxxxxTxt into the headerA2lFile
a2lTxt = fileread(headerA2lFile);
key= '/***********   Start of merged CHARACTERISTIC blocks    ***********/';
pos1 = strfind(a2lTxt,key) + length('/***********   Start of merged CHARACTERISTIC blocks    ***********/');
key= '/***********   Start of merged MEASUREMENT blocks    ***********/';
pos2 = strfind(a2lTxt,key) + length('/***********   Start of merged MEASUREMENT blocks    ***********/');
key= '/***********   Start of merged COMPU_METHOD blocks    ***********/';
pos3 = strfind(a2lTxt,key) + length('/***********   Start of merged COMPU_METHOD blocks    ***********/');
key= '/***********   Start of merged RECORD_LAYOUT blocks    ***********/';
pos4 = strfind(a2lTxt,key) + length('/***********   Start of merged RECORD_LAYOUT blocks    ***********/');
% get the first key and insert before 1
a2lTxt = [a2lTxt(1:pos1),newline,sl_CHARACTERISTIC_Txt,...
          a2lTxt(pos1:pos2),sl_MEASUREMENT_Txt,...
          a2lTxt(pos2:pos3),sl_COMPU_METHOD_Txt,...
          a2lTxt(pos3:pos4),sl_RECORD_LAYOUT_Modify_Txt...
          a2lTxt(pos4:length(a2lTxt))];
%a2lTxt = [a2lTxt(1:pos1-1),newline,slGenTxt,newline,a2lTxt(pos1:length(a2lTxt))];
%% write into release file
fid=fopen(RlsA2lFile,'w');
fprintf(fid,'%s',a2lTxt);
fclose(fid);
%% clear
clear elfFile hexFile  bswA2lFile
clear slGenTxt a2lTxt 
clear pos1 pos2 key
clear sl_RECORD_LAYOUT_Txt 
clear sl_COMPU_METHOD_Txt
clear sl_CHARACTERISTIC_Txt
clear sl_MEASUREMENT_Txt
clear sl_RECORD_LAYOUT_Modify_Txt
clear i j
clear fid RlsA2lFile a2lFile0 a2lFile1 a2lFile2 a2lFile4 slA2lFile0 slA2lFile1 slA2lFile2 slA2lFile4

disp('/****************AddAddressInA2L done****************************/');