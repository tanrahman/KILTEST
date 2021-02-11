/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	Interrupt.c
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
******************************************************/
#include "../inc/Declare.h"

/****************************************************************************
  Function:      SCIRST_HANDLER
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/ 
void SCIRST_HANDLER(void)
{    
	SYSINTCLR = 0x01;//clear SCI RST int flag
    
    SCITA1 = 0x11;//back to default Fi/Di
	SCI_RxStart();
	SCI_WaitRx(0x00);
    
    NVIC_ICER = 1 << IRQ_7816TX;//disable 7816 Tx int 

	SCI_Send_ATR();
	G_bATR_Done = 1;
}
/****************************************************************************
  Function:      SCIRx_HANDLER
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/ 
void SCIRx_HANDLER(void)
{	
	SCISSR &= ~BIT2;//clear SCI Rx int flag
	
	G_SCIRecieving = 1;	
	
	SCI_StoreNBytes();//copy DATA from FIFO to SCIAPDUBuf
    
    if(G_SCIRecieveDone == 1)
    {
        return;
    }
    
    if(SCIAPDUBuf[0] == 0xFF)//CLASS judgement
    {
        if(G_SCIRecieveIndex >= 2)
        {
            G_SCIRecieveDone = 1;//pps header got
        }
    }
    else
    {
        if(G_SCIRecieveIndex == 5)
        {
            G_SCIRecieveDone = 1;//APDU header got
            SCIS60CON = 0x01;//enable sending 0x60 by SCI IP
        }
    }
}
/****************************************************************************
  Function:      SCITx_HANDLER
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SCITx_HANDLER(void)
{	
	SCISSR &= ~BIT4;//clear SCI Tx int flag
    
    if((SCISSR & BIT1) != 0)
	{
        SCISSR &= ~0x02;//as RTS == 1 ,so next byte will be sent 
        /*if last byte PE, no byte be sent below*/
    }
    
	if(G_SCISendIndex == (SCILeLength+2))
	{
		G_bSCILeSendDone = 1;
        NVIC_ICER = 1 << IRQ_7816TX;//disable 7816 Tx int 
		return;
	}

    /*le data must all have been input to FIFO,which ensure FIFO available more than two bytes here for SW1SW2*/ 
    while((SCITXFCR & BIT1) != 0);
	/*write SW1SW2*/
    SCISBUF = SW1SW2 >> 8;
    SCISBUF = SW1SW2;
	G_SCISendIndex += 2;	
}

