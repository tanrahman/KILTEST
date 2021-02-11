/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	SCI.h
 Author:    	
 Version:			
 Date:  			
 Description: 
 History:	

******************************************************/
#ifndef _SCI_H_
#define _SCI_H_

#define	SCI_APDUBufSize	260

void SCI_Send_ATR(void);
void SCI_DelayNETU(unsigned int nETU);
void SCI_RxStart(void);
void SCI_StartTx_INT(unsigned short index);
void SCI_StoreNBytes(void);
void SCI_WaitRx(unsigned char index);
void GVar_SCI_Init(void);
void HED_T0_SendByte(unsigned char byte);
void SCI_Init(void);
void SendINS(unsigned char ins);
void SCI_StopTx60(void);

extern volatile unsigned short G_SCIRecieveIndex;
extern volatile unsigned char G_SCIRecieveDone;
extern volatile unsigned short G_SCISendIndex;
extern unsigned char G_bSCILeSendDone;
extern unsigned int SCILeLength;

extern const unsigned char G_ATR[];
extern unsigned char SCIAPDUBuf[];

#endif
