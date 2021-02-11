/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	Interrupt.h
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
******************************************************/
#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

void SCIRST_HANDLER(void);
void SCIRx_HANDLER(void);
void SCITx_HANDLER(void);

extern unsigned short SW1SW2;
extern volatile unsigned char G_bATR_Done;
extern volatile unsigned char G_SCIRecieving;

#endif
