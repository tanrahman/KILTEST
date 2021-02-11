/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	HCI_lib_GVar.h
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:
                V1.0	2014-11-26	initial version 
                V1.1	2015-08-06	add G_APDUGateBuf/G_APDUGateLen
                V1.2  2016-05-30  add G_SYNC_PARA/G_CmptblCtrl
******************************************************/
#ifndef _HCI_LIB_GVAR_H_
#define _HCI_LIB_GVAR_H_

#define  G_uiccHCIConfig_Flash  ((configData *)HCIConfig_ADRESS)

// #define SWP_PARA1 		 0x13F
// #define SWP_PARA2 		 0x0B
// #define SWP_PARA5 		 0x1A4

extern unsigned char G_SYNC_PARA;
extern unsigned char G_CmptblCtrl;
extern unsigned short G_triggerResult;
extern unsigned int G_AppOpenSta;
extern unsigned char G_bSWP_DetectStatus;
extern unsigned char G_bCardActivated;
extern unsigned char G_APDUBuf[];
extern unsigned short G_APDULen;
extern unsigned char G_HCIMode;
extern unsigned char G_bSWP_busy;
extern unsigned char G_bCLKSwitchValid;

extern unsigned char G_appMode;
extern unsigned short G_RFType;
extern unsigned char G_ReaderTimerOutInteger;
extern unsigned char G_bFstAPDU;
extern unsigned char G_SetParaBuf[];
extern unsigned char G_GetParaBuf[];
extern unsigned char G_bRFIndicator;
extern unsigned char G_bAPPSendType;
extern unsigned char G_GetRFType;
extern unsigned char G_APDUGateBuf[];
extern unsigned short G_APDUGateLen;
//const
//IDManagement Gate Registry
extern unsigned char pReg_ID_Gate_VerSW[];
extern unsigned char pReg_ID_Gate_VerHard[];
extern unsigned char pReg_ID_Gate_Vendor_Name[];
extern unsigned char pReg_ID_Gate_Model_ID[];
//CLF TYPEA card RF Gate Registry
extern unsigned char aReg_CardRFTypeA_UID[]; 
extern unsigned char aReg_CardRFTypeA_SAK[]; 
extern unsigned char aReg_CardRFTypeA_ATQA[]; 
extern unsigned char aReg_CardRFTypeA_History[];
extern unsigned char aReg_CardRFTypeA_TB1[];
extern unsigned char aReg_CardRFTypeA_MAXDataRate[];
extern unsigned char aReg_CardRFTypeA_CID_SUPPORT[];
//CLF TYPEA reader RF Gate Registry
extern unsigned char aReg_ReaderRFTypeA_MAXDataRate [];
//CLF TYPEB card RF Gate Registry
extern unsigned char aReg_CardRFTypeB_AFI[]; 
extern unsigned char aReg_CardRFTypeB_ATQB[]; 
extern unsigned char aReg_CardRFTypeB_MAXDataRate[];

//variable
//CLF TYPEA reader RF Gate Registry
extern unsigned char aReg_ReaderRFTypeA_UID[];
extern unsigned char aReg_ReaderRFTypeA_SAK[];
extern unsigned char aReg_ReaderRFTypeA_ATQA[];  
extern unsigned char aReg_ReaderRFTypeA_History[];
extern unsigned char aReg_ReaderRFTypeA_TB1[];

extern unsigned int HCIConfig_ADRESS;

/*variables below can be located in EEPROM, JAVA OS init and update*/
extern unsigned char G_cM1_Mode;
extern unsigned char G_cM1_PwAlgType;

#endif
