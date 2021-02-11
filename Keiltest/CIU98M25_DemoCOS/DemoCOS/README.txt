软件包版本：v2.0
日期：2018年1月25号
SVN版本：5729
修订记录：（1）2015年3月5号提交v1.0版本
          （2）2015年4月20号提交v1.1版本，升级DemoCOS中的SWP/HCI/Mifare API：修改sony手机CLF的兼容性问题，修改Collis设备测试出的问题
          （3）2015年6月10号提交v1.2版本，修改样品上master DemoCOS SPI通信异常的问题：设置SCK不高于18Mhz；更新DemoCOS_Base中的SWP LIB API；
          （4）2015年7月13号提交v1.3版本，更新DemoCOS_Base中的SWP LIB API（v1.3）；
          （5）2015年8月10号提交v1.4版本，更新SWP/HCI/Mifare API LIB为v1.4；
          （6）2016年2月18号提交v1.5版本，更新SWP/HCI/Mifare API LIB为v1.5，同时增加对SSF33演示；
          （7）2016年5月09号提交v1.6版本，更新SWP/HCI/Mifare API LIB为v1.6，修改PPS后高速率设置代码；
          （8）2016年5月30号提交v1.7版本，更新SWP/HCI/Mifare API LIB为v1.7，增加全局变量G_CmptblCtrl演示；
          （9）2016年7月27号提交v1.8版本，更新SWP/HCI/Mifare API LIB为v1.8，解决STD下电流超标问题；
          （10）2017年1月22号提交v1.9版本，
                        1) 更新DemoCOS_Base中，SWP/HCI/Mifare API LIB为v1.9，修复2级优化下PPS请求无响应问题（volatile属性问题），修改DemoCOS中AWTS为4096CLK；
                        2) 更新DemoCOS_Single7816中，SYSINFST寄存器的bit0判断语句，与芯片手册描述流程一致；
          （11）2018年1月25号提交v2.0版本，按照项目组要求，上电阶段赋值三个SFR：SYSVR12PB/SYSNVMVR12PB/SYSVR18PB                        
          
│  README.txt
│  
├─CIU98M25_DemoCOS_Base
│  │  CIU98M25_DemoCOS_Base.uvopt
│  │  CIU98M25_DemoCOS_Base.uvproj
│  │  DEMO_Base_TEST_Script.apdu
│  │  
│  ├─API
│  │      CIU98M25_ALG_LIB.lib
│  │      CIU98M25_API_Base_NoNVM.c
│  │      CIU98M25_API_LIB_SHA_RNG.lib
│  │      CIU98M25_API_LIB_Stability.lib
│  │      CIU98M25_API_NVM_STABILITY.c
│  │      HCI_lib_GVar.c
│  │      SWP_LIB_API_Chip_v1.9.lib
│  │      SWP_LIB_API_Kit_v1.9.lib
│  │      
│  ├─INC
│  │      APDU_7816.h
│  │      APDU_SWP_CARD.h
│  │      CIU98M25_ALG_LIB.h
│  │      CIU98M25_API_Base_NoNVM.h
│  │      CIU98M25_API_LIB_SHA_RNG.h
│  │      CIU98M25_API_LIB_STABILITY.h
│  │      CIU98M25_API_NVM_STABILITY.h
│  │      CIU98M25_SFR_C.h
│  │      Declare.h
│  │      HCI_lib_API.h
│  │      HCI_lib_GVar.h
│  │      Interrupt.h
│  │      SCI.h
│  │      SubFunc.h
│  │      TYPEDEF.h
│  │      
│  ├─lst
│  ├─obj
│  └─SRC
│          APDU_7816.c
│          APDU_SWP_CARD.c
│          Interrupt.c
│          main.c
│          SCI.c
│          startup.s
│          SubFunc.c
│          
├─CIU98M25_DemoCOS_Single7816
│  │  CIU98M25_DemoCOS_Single7816.uvopt
│  │  CIU98M25_DemoCOS_Single7816.uvproj
│  │  DEMO_Single7816_TEST_Script.apdu
│  │  
│  ├─API
│  │      CIU98M25_API_Base_NoNVM.c
│  │      CIU98M25_API_LIB_Stability.lib
│  │      
│  ├─INC
│  │      CIU98M25_API_Base_NoNVM.h
│  │      CIU98M25_API_LIB_STABILITY.h
│  │      CIU98M25_SFR_C.h
│  │      Declare.h
│  │      DEMO_APDU.h
│  │      SCI.h
│  │      SubFunc.h
│  │      TYPEDEF.h
│  │      
│  ├─lst
│  ├─obj
│  └─SRC
│          DEMO_APDU.c
│          main.c
│          startup.s
│          SubFunc.c
│          
├─CIU98M25_DemoCOS_SPIMaster
│  │  CIU98M25_DemoCOS_SPIMaster.uvopt
│  │  CIU98M25_DemoCOS_SPIMaster.uvproj
│  │  
│  ├─API
│  │      CIU98M25_API_Base_NoNVM.c
│  │      CIU98M25_API_LIB_Stability.lib
│  │      
│  ├─INC
│  │      CIU98M25_API_Base_NoNVM.h
│  │      CIU98M25_API_LIB_STABILITY.h
│  │      CIU98M25_SFR_C.h
│  │      declare.h
│  │      DEMO_APDU.h
│  │      SPI.h
│  │      SubFunc.h
│  │      TYPEDEF.h
│  │      
│  ├─lst
│  ├─obj
│  └─SRC
│          DEMO_APDU.c
│          main.c
│          SPI.c
│          startup.s
│          SubFunc.c
│          
└─CIU98M25_DemoCOS_SPISlave
    │  CIU98M25_DemoCOS_SPISlave.uvopt
    │  CIU98M25_DemoCOS_SPISlave.uvproj
    │  
    ├─API
    │      CIU98M25_API_Base_NoNVM.c
    │      CIU98M25_API_LIB_Stability.lib
    │      
    ├─INC
    │      CIU98M25_API_Base_NoNVM.h
    │      CIU98M25_API_LIB_STABILITY.h
    │      CIU98M25_SFR_C.h
    │      declare.h
    │      DEMO_APDU.h
    │      SPI.h
    │      SubFunc.h
    │      TYPEDEF.h
    │      
    ├─lst
    ├─obj
    └─SRC
            DEMO_APDU.c
            main.c
            SPI.c
            startup.s
            
