/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	SubFunc.h
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
******************************************************/
#ifndef __SUBFUNC_H_
#define __SUBFUNC_H_

#define SET_REG_BIT(reg,bit) 			(reg |= (1 << (bit)))
#define CLEAR_REG_BIT(reg,bit) 			(reg &= ~(1 << (bit)))

void DEMOCOS_PPS(void);
void DemoCos_DelayNETU(unsigned int nETU);
void SCI_StopTx60(void);
void SCI_Init(void);
void DemoCos_SendINS(unsigned char ins);
void GlobalPARA_Init(void);

#define PPS_PPSS SCIAPDUBuf[0]
#define PPS_PPS0 SCIAPDUBuf[1]
#define PPS_PPS1 SCIAPDUBuf[2]
#define PPS_PPS2 SCIAPDUBuf[3]
#define PPS_PPS3 SCIAPDUBuf[4]
#define PPS_PCK  SCIAPDUBuf[5]
#define PPS_NUM 5

#endif

