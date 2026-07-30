%% ===================== 1. 仅需修改这里 =====================
% 宏定义（只写1次，全局复用）
macroStr = [...
    '#define UCHAR_MAX 0xFFU', newline ,...
    '#define SCHAR_MAX 0x7F', newline ,...
    '#define USHRT_MAX 0xFFFFU', newline ,...
    '#define SHRT_MAX 0x7FFF',newline , ...
    '#define UINT_MAX 0xFFFFFFFFU',newline , ...
    '#define INT_MAX 0x7FFFFFFF',newline , ...
    '#define ULONG_MAX 0xFFFFFFFFU',newline , ...
    '#define LONG_MAX 0x7FFFFFFF' ...
];

% 5个.h文件路径（直接罗列，新增文件只加一行）
fileList = [
    "D:\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC\include\CDD_ISP_private.h"   % 头文件1
    "D:\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC\include\currentloop_private.h"   % 头文件2
    "D:\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC\include\FOC_private.h"   % 头文件3
    "D:\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC\include\FOCSpdTrq_private.h"   % 头文件4
    "D:\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC\include\pmsmfoc_private.h"   % 头文件5
    "D:\GL_V\Applications\SipAddon\StartApplication\Appel\App\ASW_FOC\include\SVPWM_private.h"   % 头文件5
];

%% ===================== 2. 一键批量执行 =====================
for i = 1:length(fileList)
    insertMacroToFile(fileList(i), macroStr);
end

%% ===================== 3. 通用函数（无需修改） =====================
% 在 #include 后、#ifndef 外部插入宏定义，源码自动下移
function insertMacroToFile(filePath, macro)
    % 读取文件
    fid = fopen(filePath, 'r');
    fileLines = textscan(fid, '%s', 'Delimiter', '\n', 'Whitespace', '');
    fclose(fid);
    content = fileLines{1};

    % 定位第一个 #ifndef 行（头文件保护宏）
    insertPos = 1;
    for i = 1:length(content)
        if startsWith(strtrim(content{i}), '#ifndef')
            insertPos = i;
            break;
        end
    end

    % 插入宏定义（#ifndef 外部，绝对不进去）
    newContent = [
        content(1:insertPos-1);
        strsplit(macro, '\n')';
        content(insertPos:end)
    ];

    % 写回文件
    fid = fopen(filePath, 'w');
    for i = 1:length(newContent)
        fprintf(fid, '%s\n', newContent{i});
    end
    fclose(fid);
    disp(['✅ 处理完成：', filePath]);
end


