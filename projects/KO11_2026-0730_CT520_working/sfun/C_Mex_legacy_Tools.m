%root path c and h files
oldpath = pwd;
p1 = mfilename('fullpath');
[pathstr,name,ext]=fileparts(p1);
cd(pathstr);
incpath = pathstr;
cFileNames = { 'C2SfunShell.c' };
hFileNames ={ 'C2SfunShell.h','Platform_Types.h' };

% math library path c and h files
% no including for dsm because function declared as extern
cd MathLib;
cFiles1 = dir('*.c');
cFileNames1 = { cFiles1.name };
incpath1 = cd();
hFiles1 = dir('*.h');
hFileNames1 ={ hFiles1.name };
cd(pathstr);

sourcefiles=[cFileNames,cFileNames1];
headerfiles=[hFileNames,hFileNames1];
includepath = {incpath,incpath1};
%LIB_SinCosCalc C files convert to sfunction 
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_LIB_SinCosCalc';
def.OutputFcnSpec = 'void SinCosShell(int32 u1,int16 y1[1],int16 y2[1])';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
%legacy_code('generate_for_sim', def);
legacy_code('compile', def);
%legacy_code('slblock_generate', def);

%LIB_SqrtCalc C files convert to sfunction 
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_LIB_SqrtCalc';
def.OutputFcnSpec = 'void SqrtShell(single u1,single y1[1],single y2[1])';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
%legacy_code('generate_for_sim', def);
legacy_code('compile', def);
%legacy_code('slblock_generate', def);

%LIB_Atan2 C files convert to sfunction 
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_Atan2';
def.OutputFcnSpec = 'void Atan2Shell(single u1,single u2,uint16 y1[1])';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
%legacy_code('generate_for_sim', def);
legacy_code('compile', def);
%legacy_code('slblock_generate', def);

% get fid
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_GetFid';
def.OutputFcnSpec = 'void GetFidShell(uint16 u1,boolean y1[1])';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
% legacy_code('generate_for_sim', def);
legacy_code('compile', def);
% legacy_code('slblock_generate', def);

%set dfc
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_SetDfc';
def.OutputFcnSpec = 'void SetDfcShell(boolean u1,boolean u2, uint16 u3, uint32 u4)';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
% legacy_code('generate_for_sim', def);
legacy_code('compile', def);
% legacy_code('slblock_generate', def);

% clear dfc
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_ClrDfc';
def.OutputFcnSpec = 'void ClrDfcShell(uint16 u1)';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
% legacy_code('generate_for_sim', def);
legacy_code('compile', def);
% legacy_code('slblock_generate', def);

% Dio_set
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_DioSet';
def.OutputFcnSpec = 'void DioSetShell(boolean u1, uint16 u2, boolean y1[1])';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
% legacy_code('generate_for_sim', def);
legacy_code('compile', def);
% legacy_code('slblock_generate', def);

% Dio_Get
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_DioGet';
def.OutputFcnSpec = 'void DioGetShell(boolean u1, uint16 u2, boolean y1[1])';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
 legacy_code('generate_for_sim', def);
legacy_code('compile', def);
 legacy_code('slblock_generate', def);

% Adc_Get
def = legacy_code('initialize');
def.IncPaths    = includepath;
def.SourceFiles = sourcefiles; % All the c files used in C2SFuncShell shall be included
def.HeaderFiles = headerfiles;% All the h files used in C2SFuncShell shall be included
def.SFunctionName = 'ex_sfun_AdcGet';
def.OutputFcnSpec = 'void AdcGetShell(uint16 u1, uint16 u2, uint16 y1[1])';
legacy_code('sfcn_tlc_generate', def);
legacy_code('sfcn_cmex_generate', def);
 legacy_code('generate_for_sim', def);
legacy_code('compile', def);
 legacy_code('slblock_generate', def);
