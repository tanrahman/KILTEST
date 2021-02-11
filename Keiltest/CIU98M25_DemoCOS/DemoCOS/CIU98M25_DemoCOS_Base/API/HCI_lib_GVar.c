/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	HCI_lib_GVar.c
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
                V1.0	2014-11-26	initial version
                V1.1	2015-08-06	add APDU Gate Registry,add G_APDUGateBuf/G_APDUGateLen
                V1.2  2016-05-30  add G_SYNC_PARA/G_CmptblCtrl
******************************************************/
#include "../inc/CIU98M25_SFR_C.h"

/*
bit7~bit3:
    COS must set to 0!
bit2:
    1:support extended resume
    0:not support
bit1:
    1:support 0.59us bit duration
    0:not support
bit0: 
    1:support 10us bit duration
    0:not support
*/
__attribute__((zero_init)) unsigned char G_SYNC_PARA;

/*
bit7~bit1:
    COS must set to 0!
bit0: 
    1:between hosts, response  of ANY_OPEN_PIPE may or may not attach para as show in TS 102 622 Table 8,all is OK
    0:between hosts, response  of ANY_OPEN_PIPE shall attach para as show in TS 102 622 Table 8, otherwise UICC will treat the ANY_OPEN_PIPE command as Fail
*/
__attribute__((zero_init)) unsigned char G_CmptblCtrl;
/*
executed result of UICC trigger event
high nibble indicate trigger type:
00: Pro_Host_Request
else:RFU
low nibble indicate trigger result:
00:OK
01:Fail
else:RFU
*/
unsigned short G_triggerResult;

/*
    G_APDUBuf is used both in card emulation mode and reader mode
    
    if G_APDUBuf used for Rx,
    G_APDUBuf [0]:
    0,indicate TypeA RF data received;
    1,indicate TypeB RF data received;
    G_APDUBuf [1]~[263]:APDU
    
    if G_APDUBuf used for Tx,
    G_APDUBuf [0]:
    0,indicate TypeA RF data to send;
    1,indicate TypeB RF data to send;
    G_APDUBuf [1]~[263]:APDU    
*/
__align(4) unsigned char G_APDUBuf[264];

//number of available data start from G_APDUBuf[1]
unsigned short G_APDULen;

/*
    G_APDUGateBuf is used in APDU GATE app
    
    if G_APDUGateBuf used for Rx,
    G_APDUGateBuf [0]~[260]:C_APDU
    
    if G_APDUGateBuf used for Tx,
    G_APDUGateBuf [0]~[257]:R_APDU    
*/
unsigned char G_APDUGateBuf[261];

//number of available data start from G_APDUGateBuf[0]
unsigned short G_APDUGateLen;

/*
bit set 1,means open
bit0~7:Card mode
     bit0:TypeA
     bit1:TypeB
     bit2~7:RFU
bit8~15:reader mode
     bit8:TypeA
     bit9:TypeB
     bit10~15:RFU
bit16:  connectivity 
bit17~bit 31:RFU
*/
unsigned int G_AppOpenSta;

//whether SWP interface available
__attribute__((zero_init)) unsigned char G_bSWP_DetectStatus;

//indicate application mode ,card emulation or reader
unsigned char G_HCIMode;

//indicate SWIO status
__attribute__((zero_init)) unsigned char G_bSWP_busy;

//whether valid for SYSCLK switching
__attribute__((zero_init)) unsigned char G_bCLKSwitchValid;

//reader R_APDU wait time,Time-out=£¨256*16/13.56Mhz£©*2^G_ReaderTimerOutInteger 
unsigned char G_ReaderTimerOutInteger;

/*
    bit0:card emulation,1:enable,0:disable
    bit1:reader mode,1:enable,0:disable
    bit2:connectivity,1:enable,0:disable
    bit3:APDU GATE,1:enable,0:disable
    else:RFU
*/
unsigned char G_appMode;

/*
    bit7~0:define card emulation mode's RF Type
    bit0:TypeA,1:enable,0:disable
    bit1:TypeB,1:enable,0:disable
    else:RFU
    bit15~8:define reader mode's RF Type
    bit8:TypeA,1:enable,0:disable
    bit9:TypeB,1:enable,0:disable
    else:RFU
*/
unsigned short G_RFType;

/*
    valid when HCI_RxManage(void) return 0x11.
    0x00:no APDU available,initial value when chip rst or RF rst
    0x01:1st APDU received
    0xFF:non 1st APDU
*/
unsigned char G_bFstAPDU;

/*
before send ANY_SET_PARAMETER,
G_SetParaBuf [0]:
		0,indicate TypeA RF Type
    	1,indicate TypeB RF Type
        else,RFU
G_SetParaBuf [1]£º
        0,indicate target gate is card RF gate
        1,indicate target gate is reader RF gate
        else,RFU
G_SetParaBuf [2]:index of the parameter in the registry; 
G_SetParaBuf [3]:length of the parameter; 
G_SetParaBuf [4-19]:value of the parameter;

when receive ANY_SET_PARAMETER response,
G_SetParaBuf [0]:
        0,indicate TypeA RF Type
        1,indicate TypeB RF Type
        else,RFU
G_SetParaBuf [1]:
        0,indicate target gate is card RF gate
        1,indicate target gate is reader RF gate
        else,RFU
G_SetParaBuf [2],response of ANY_SET_PARAMETER,refer to TS102 622 Table 15, but highest bit set 1
*/
unsigned char G_SetParaBuf[20];

/*
before send ANY_GET_PARAMETER,
G_GetParaBuf [0]:
        0,indicate TypeA RF Type
    	1,indicate TypeB RF Type
        else,RFU
G_GetParaBuf [1]:
        0,indicate target gate is card RF gate
        1,indicate target gate is reader RF gate
        else,RFU
G_GetParaBuf [2]:index of the parameter in the registry

when receive ANY_GET_PARAMETER response,
G_GetParaBuf [0]:
        0,indicate TypeA RF Type
        1,indicate TypeB RF Type
        else,RFU
G_GetParaBuf [1]:
        0,indicate target gate is card RF gate
        1,indicate target gate is reader RF gate
        else,RFU
G_GetParaBuf [2]:response of ANY_GET_PARAMETER,refer to TS102 622 Table 15, but highest bit set 1
G_GetParaBuf [3]:length of the parameter;
G_GetParaBuf [4-19]:value of the parameter;
*/
unsigned char G_GetParaBuf[20]; 

/*
 parameter "RF error indicator" of EVT_SEND_DATA or WR_XCHG_DATA 
 0:no error;
 1 or else:error;
*/
unsigned char G_bRFIndicator; 

/*
1: just 1 frame sent in HCI_CardMode_Send(void) and HCI_ReaderMode_Send(void),other frame sent in Rx_Manage()
0: all frames sent in HCI_CardMode_Send(void) and HCI_ReaderMode_Send(void)
*/
unsigned char G_bAPPSendType;

/* 	for check the current RF Type
 	0:TypeA
 	1:TypeB
    2:TypeB'
    3:TypeF
    else:RFU
*/
unsigned char G_GetRFType;

//const
//IDManagement Gate Registry
const unsigned char pReg_ID_Gate_VerSW[4] = {0x03,0x01,0x00,0x00};
const unsigned char pReg_ID_Gate_VerHard[4] = {0x03,0x00,0x00,0x00};
const unsigned char pReg_ID_Gate_Vendor_Name[4] = {0x03,0x48,0x45,0x44};
const unsigned char pReg_ID_Gate_Model_ID[2] = {0x01,0x00};

//variables group 1
/*all variables below need initialize before calling HCI_GVar_Init()*/
//CLF TYPEA card RF Gate Registry
__attribute__((zero_init)) unsigned char aReg_CardRFTypeA_UID[5]; 
unsigned char aReg_CardRFTypeA_SAK[2] = {0x01,0x28}; 
unsigned char aReg_CardRFTypeA_ATQA[3] = {0x02,0x04,0x01}; 
unsigned char aReg_CardRFTypeA_History[7] = {0x06,0x81,0x17,0x01,0x0D,0x10,0x00};
unsigned char aReg_CardRFTypeA_TB1[2] = {0x01,0x81};
unsigned char aReg_CardRFTypeA_MAXDataRate[4] = {0x03,0x00,0x00,0x00};
unsigned char aReg_CardRFTypeA_CID_SUPPORT[2] = {0x01,0x00};
//CLF TYPEA reader RF Gate Registry
unsigned char aReg_ReaderRFTypeA_MAXDataRate [2] = {0x01,0x03};
//CLF TYPEB card RF Gate Registry
unsigned char aReg_CardRFTypeB_AFI[2] = {0x01,0x00};
unsigned char aReg_CardRFTypeB_ATQB[5] = {0x04,0x00,0x00,0x00,0x84};
unsigned char aReg_CardRFTypeB_MAXDataRate[4] = {0x03,0x00,0x00,0x00}; 

//variables group 2
//CLF TYPEA reader RF Gate Registry
unsigned char aReg_ReaderRFTypeA_UID[11] = {0x0A, 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A};
unsigned char aReg_ReaderRFTypeA_SAK[2] = {0x01,0x00};
unsigned char aReg_ReaderRFTypeA_ATQA[3] = {0x02,0x00,0x00};  
unsigned char aReg_ReaderRFTypeA_History[16] = {0x0F,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
unsigned char aReg_ReaderRFTypeA_TB1[2] = {0x01,0x00};

//variables group 3
//APDU Application Gate Registry
unsigned char pReg_APDU_App_Gate_ATR[9] = {0x08,0x3B,0x06,0x81,0x17,0x01,0xDD,0xB0,0x16};
/*
value of the const below define the address of 1 page FLASH,where store pipe id£¬pipe status£¬refer data,session id,etc;
SWP API init and manage this page FLASH
*/
const unsigned int HCIConfig_ADRESS = 0x11BE00;//the page that next to HE FLASH,COS can modify this value    
