������汾��v2.0
���ڣ�2018��1��25��
SVN�汾��5729
�޶���¼����1��2015��3��5���ύv1.0�汾
          ��2��2015��4��20���ύv1.1�汾������DemoCOS�е�SWP/HCI/Mifare API���޸�sony�ֻ�CLF�ļ��������⣬�޸�Collis�豸���Գ�������
          ��3��2015��6��10���ύv1.2�汾���޸���Ʒ��master DemoCOS SPIͨ���쳣�����⣺����SCK������18Mhz������DemoCOS_Base�е�SWP LIB API��
          ��4��2015��7��13���ύv1.3�汾������DemoCOS_Base�е�SWP LIB API��v1.3����
          ��5��2015��8��10���ύv1.4�汾������SWP/HCI/Mifare API LIBΪv1.4��
          ��6��2016��2��18���ύv1.5�汾������SWP/HCI/Mifare API LIBΪv1.5��ͬʱ���Ӷ�SSF33��ʾ��
          ��7��2016��5��09���ύv1.6�汾������SWP/HCI/Mifare API LIBΪv1.6���޸�PPS����������ô��룻
          ��8��2016��5��30���ύv1.7�汾������SWP/HCI/Mifare API LIBΪv1.7������ȫ�ֱ���G_CmptblCtrl��ʾ��
          ��9��2016��7��27���ύv1.8�汾������SWP/HCI/Mifare API LIBΪv1.8�����STD�µ����������⣻
          ��10��2017��1��22���ύv1.9�汾��
                        1) ����DemoCOS_Base�У�SWP/HCI/Mifare API LIBΪv1.9���޸�2���Ż���PPS��������Ӧ���⣨volatile�������⣩���޸�DemoCOS��AWTSΪ4096CLK��
                        2) ����DemoCOS_Single7816�У�SYSINFST�Ĵ�����bit0�ж���䣬��оƬ�ֲ���������һ�£�
          ��11��2018��1��25���ύv2.0�汾��������Ŀ��Ҫ���ϵ�׶θ�ֵ����SFR��SYSVR12PB/SYSNVMVR12PB/SYSVR18PB                        
          
��  README.txt
��  
����CIU98M25_DemoCOS_Base
��  ��  CIU98M25_DemoCOS_Base.uvopt
��  ��  CIU98M25_DemoCOS_Base.uvproj
��  ��  DEMO_Base_TEST_Script.apdu
��  ��  
��  ����API
��  ��      CIU98M25_ALG_LIB.lib
��  ��      CIU98M25_API_Base_NoNVM.c
��  ��      CIU98M25_API_LIB_SHA_RNG.lib
��  ��      CIU98M25_API_LIB_Stability.lib
��  ��      CIU98M25_API_NVM_STABILITY.c
��  ��      HCI_lib_GVar.c
��  ��      SWP_LIB_API_Chip_v1.9.lib
��  ��      SWP_LIB_API_Kit_v1.9.lib
��  ��      
��  ����INC
��  ��      APDU_7816.h
��  ��      APDU_SWP_CARD.h
��  ��      CIU98M25_ALG_LIB.h
��  ��      CIU98M25_API_Base_NoNVM.h
��  ��      CIU98M25_API_LIB_SHA_RNG.h
��  ��      CIU98M25_API_LIB_STABILITY.h
��  ��      CIU98M25_API_NVM_STABILITY.h
��  ��      CIU98M25_SFR_C.h
��  ��      Declare.h
��  ��      HCI_lib_API.h
��  ��      HCI_lib_GVar.h
��  ��      Interrupt.h
��  ��      SCI.h
��  ��      SubFunc.h
��  ��      TYPEDEF.h
��  ��      
��  ����lst
��  ����obj
��  ����SRC
��          APDU_7816.c
��          APDU_SWP_CARD.c
��          Interrupt.c
��          main.c
��          SCI.c
��          startup.s
��          SubFunc.c
��          
����CIU98M25_DemoCOS_Single7816
��  ��  CIU98M25_DemoCOS_Single7816.uvopt
��  ��  CIU98M25_DemoCOS_Single7816.uvproj
��  ��  DEMO_Single7816_TEST_Script.apdu
��  ��  
��  ����API
��  ��      CIU98M25_API_Base_NoNVM.c
��  ��      CIU98M25_API_LIB_Stability.lib
��  ��      
��  ����INC
��  ��      CIU98M25_API_Base_NoNVM.h
��  ��      CIU98M25_API_LIB_STABILITY.h
��  ��      CIU98M25_SFR_C.h
��  ��      Declare.h
��  ��      DEMO_APDU.h
��  ��      SCI.h
��  ��      SubFunc.h
��  ��      TYPEDEF.h
��  ��      
��  ����lst
��  ����obj
��  ����SRC
��          DEMO_APDU.c
��          main.c
��          startup.s
��          SubFunc.c
��          
����CIU98M25_DemoCOS_SPIMaster
��  ��  CIU98M25_DemoCOS_SPIMaster.uvopt
��  ��  CIU98M25_DemoCOS_SPIMaster.uvproj
��  ��  
��  ����API
��  ��      CIU98M25_API_Base_NoNVM.c
��  ��      CIU98M25_API_LIB_Stability.lib
��  ��      
��  ����INC
��  ��      CIU98M25_API_Base_NoNVM.h
��  ��      CIU98M25_API_LIB_STABILITY.h
��  ��      CIU98M25_SFR_C.h
��  ��      declare.h
��  ��      DEMO_APDU.h
��  ��      SPI.h
��  ��      SubFunc.h
��  ��      TYPEDEF.h
��  ��      
��  ����lst
��  ����obj
��  ����SRC
��          DEMO_APDU.c
��          main.c
��          SPI.c
��          startup.s
��          SubFunc.c
��          
����CIU98M25_DemoCOS_SPISlave
    ��  CIU98M25_DemoCOS_SPISlave.uvopt
    ��  CIU98M25_DemoCOS_SPISlave.uvproj
    ��  
    ����API
    ��      CIU98M25_API_Base_NoNVM.c
    ��      CIU98M25_API_LIB_Stability.lib
    ��      
    ����INC
    ��      CIU98M25_API_Base_NoNVM.h
    ��      CIU98M25_API_LIB_STABILITY.h
    ��      CIU98M25_SFR_C.h
    ��      declare.h
    ��      DEMO_APDU.h
    ��      SPI.h
    ��      SubFunc.h
    ��      TYPEDEF.h
    ��      
    ����lst
    ����obj
    ����SRC
            DEMO_APDU.c
            main.c
            SPI.c
            startup.s
            
