20181220
:.
    CreatCdd1RtBlock.m			创建simulink中Cdd1 rating transmission block
    CreatCdd2RtBlock.m			创建simulink中Cdd2 rating transmission block
    CreatGpiOvdBlock.m			创建simulink中Gpi override block
    CreatGpiRtBlock.m			创建simulink中Gpi rating transmission block
    CreatGpoRtBlock.m			创建simulink中Gpo rating transmission block
    CreatVadcRtBlock.m			创建simulink中Vadc0 rating transmission block
    DefineBusMemberFrmHsi.m		从hsi文件中， 更新VADC0ST，GPIST，GPOST的成员到xlsFile中
    DefineIoEnumeration.m		将GPIST GPOST成员，做成枚举量进行索引
    hsiGen.m				hsi相关的底层代码修改的入口
    hsiGenGpio.m			根据hsi修改底层代码的gpio模块
    hsiGenVadc.m			根据hsi修改底层代码的vadc模块(包含cdd中模拟通道的定义)
    HSI_INVGEN2_TC277_BGA292.xlsx	hsi文件，用户文件，描述Hardware Software Interface
    hsiGenBus.xlsx			generated from the hsi xls file, include VADCST GPIST and GPOST
    readme.txt				本文件
    hsiTpl				用于生成adc gpio相关配置代码的模板 

