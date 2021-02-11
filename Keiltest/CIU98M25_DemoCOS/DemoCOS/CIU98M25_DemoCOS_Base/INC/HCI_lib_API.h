/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	HCI_lib_API.h
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
                V1.0	2014-11-26	initial version
                V1.1	2015-08-06	add two API, void HCI_APDU_Gate_Send(void)/unsigned int HCI_APDU_Gate_Send_WTX(void)
******************************************************/
#ifndef _HCI_LIB_API_H_
#define _HCI_LIB_API_H_

void HCI_GVar_Init(void);
void SWP_Init(void);
unsigned int HCI_Init(unsigned char appMode, unsigned short RFType);
unsigned int HCI_RxManage(void);
void HCI_CardMode_Send(void);
void HCI_ReaderMode_Send(void);
void HCI_APDU_Gate_Send(void);
unsigned int HCI_Connectivity_Send (unsigned int type, unsigned char *para, unsigned int paraLen);
unsigned int HCI_End_Of_Operation (void);
unsigned int HCI_Mode_Switch (unsigned int mode);
unsigned int HCI_APDU_Gate_Send_WTX(void);
void SWPIO_Detect_Handler (void);
void SWP_Tansfers_Handler(void);
void HCI_RSTSyncID (void);
unsigned char HCI_SetPara_Send(void);
unsigned char HCI_GetPara_Send(void);
unsigned int SWP_APIVersion (void);

unsigned int HED_M1_InitBlock(unsigned int * piBlock0Data);
unsigned int HED_M1_ResetSector (unsigned int sectorID);
unsigned int HED_M1_PwReadBlock (unsigned int *piPwData, unsigned char cMifareBlock);
unsigned int HED_M1_PwWriteBlock (unsigned int *piPwData, unsigned char cMifareBlock);

extern volatile unsigned char	G_bPowerMode;
extern volatile unsigned char	G_bSHDLC_Status;

#endif
