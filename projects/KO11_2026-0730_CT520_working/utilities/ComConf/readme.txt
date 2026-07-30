20180928：
:.
│  CanIf_Cfg_h.tpl		CanIf_Cfg.h的模板
│  CanIf_PBcfg_c.tpl		CanIf_PBcfg.c的模板
│  canPort.ini			Can port口配置，已经在代码中确定，无意义
│  Can_Cfg_h.tpl		Can_Cfg.h的模板
│  Can_PBcfg_c.tpl		Can_PBcfg.c的模板
│  cgenComConf.m		生成Com底层Adaptor 和 callback函数
│  ComConf.m			Com模块工具入口
│  Com_cfg_autogen.pl		调用模板生成Com底层的配置文件	
│  Com_Cfg_c.tpl		Can_Cfg.c的模板
│  Com_Cfg_h.tpl		Com_Cfg.h的模板
│  PduR_Cfg_h.tpl		PduR_Cfg.h的模板
│  PduR_PBcfg_c.tpl		PduR_PBcfg.c的模板
│  readme.txt			本文件
│  updateCanPort.m		将port口更新在canPort.ini， Tasking中应用，无意义
│  writeEcuNode2pl.m		将Ecu节点信息，写入到Com_cfg_autogen.pl文件中
│  
└─cgen
    └─ComConf			生成的c code文件夹，整体拷贝到c工程中
