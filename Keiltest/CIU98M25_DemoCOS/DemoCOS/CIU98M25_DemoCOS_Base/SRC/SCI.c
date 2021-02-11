/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	SCI.c
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
				
******************************************************/
#include "../inc/Declare.h"

extern unsigned short SW1SW2;

/****************************************************************************
  Function:      SCI_Init
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SCI_Init(void)
{
	SYSCLKEN |= BIT17;//enable SCI module clk		       
    //SCISCON = 0xF53;//RTS==1,auto 0x3B sent by IP,SE=1,RCNT=3,other default setting
    SCISCON = 0xE53;//RTS==1,auto 0x3B sent by IP(AWTS=4096CLK),SE=1,RCNT=3,other default setting
    
    ;//according to chip default setting, 7816 rst is int,not system rst
    
    /*SCI retated variables init*/
	G_bCLKSwitchValid = 0;
	G_bATR_Done = 0;//must executed before SCI interface init
	G_SCIRecieving = 0;//must executed before SCI interface init
    /*SCI retated variables init*/
    
    NVIC_ISER = 1 << IRQ_7816RST;//enable 7816 rst int
}
 
/****************************************************************************
  Function:      GVar_SCI_Init
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void GVar_SCI_Init(void)
{
	G_SCIRecieveDone = 0;
	G_SCIRecieveIndex = 0;
	G_bSCILeSendDone = 1;
}
/****************************************************************************
  Function:      SCI_Send_ATR
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SCI_Send_ATR(void)
{
	unsigned int i;
	unsigned int tck;

	for(i=1,tck=0;i<(*G_ATR);i++)
	{
		/*ATR less than 256,no FIFO full or not judgement here*/
        SCISBUF = *(G_ATR+1+i);//write FIFO
		tck ^= *(G_ATR+1+i);
	}
	
    SCISBUF = tck;        
}
/****************************************************************************
  Function:      SCI_DelayNETU
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SCI_DelayNETU(unsigned int nETU)
{
	while(nETU)
	{
    	SCISSR |= BIT6;/* Begin 1ETU counter */
    	while((SCISSR & BIT6) != 0);//wait 1 ETU end
		nETU--;
	}
}

/****************************************************************************
  Function:      SCI_RxStart
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SCI_RxStart(void)
{
	while(SCISSR & BIT5);//wait if sending

	while(SCISSR & BIT3);//wait if receiving
    
    SCIRXFCR = 0x100;//set waterLevel to 1 byte
    NVIC_ISER = 1 << IRQ_7816RX;//enable 7816 rec int       
}
/****************************************************************************
  Function:      SCI_StartTx_INT
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SCI_StartTx_INT(unsigned short index)
{
    unsigned short i;
    
    SCISSR &= ~BIT4;//clear SCI Tx int flag of ATR or SW1SW2

	SCITXFCR |= BIT0;//clear FIFO
	while((SCITXFCR & BIT0) == 1);
    
    G_bSCILeSendDone = 0;
    G_SCISendIndex = index;
    
	if(SCILeLength == 0)
    {
        /*write SW1SW2*/
        /*SW1SW2 less than 256,no FIFO full or not judgement here*/
        SCISBUF = SW1SW2 >> 8;
        SCISBUF = SW1SW2;
        G_SCISendIndex += 2;
    }
    else
    {
        for(i=0;i<SCILeLength;i++)
        {
            /*Le Data no more than 256,no FIFO full or not judgement here*/
            SCISBUF = SCIAPDUBuf[G_SCISendIndex];
            G_SCISendIndex++;
        } 
    }
    
    NVIC_ICPR |= 1 << IRQ_7816TX;//if Tx int pending,clear it
    NVIC_ISER = 1 << IRQ_7816TX;//enable 7816 send int    
}

/****************************************************************************
  Function:      SCI_StoreNBytes
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SCI_StoreNBytes(void)
{
	while((SCIRXFCR & BIT1) == 0)
    {
		if(G_SCIRecieveIndex >= SCI_APDUBufSize)
		{
			return;
		}

        *(SCIAPDUBuf + G_SCIRecieveIndex) =(unsigned char)SCISBUF;
        G_SCIRecieveIndex++;
    }
}
/****************************************************************************
  Function:      SCI_WaitRx
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/ 
void SCI_WaitRx(unsigned char index)
{ 
	G_SCIRecieveIndex = index;
	G_SCIRecieveDone = 0;
	G_SCIRecieving = 0;
}
/****************************************************************************
  Function:      HED_T0_SendByte
  Description:    Clear FIFO before Tx
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/ 
void HED_T0_SendByte(unsigned char byte)
{
	while(SCISSR & BIT5);//TB

	while(SCISSR & BIT3);//RB

    SCITXFCR |= BIT0;//Clear Transfer FIFO 
    while((SCITXFCR & 0x00000001) == 1);//waiting for flag to 0
    
    SCISSR = 0;//clear TI/RI/PE/OE

	SCISBUF = byte;//write FIFO
	while((SCISSR & BIT4) == 0);//wait sending finish

    SCISSR = 0;//clear TI/RI/PE/OE
}
/****************************************************************************
  Function:      SendINS
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/ 
void SendINS(unsigned char ins)
{
	SCI_DelayNETU(4);
	HED_T0_SendByte(ins);//send INS
}
/****************************************************************************
  Function:      SCI_StopTx60
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/ 
void SCI_StopTx60(void)
{
    SCIS60CON = 0x00;//disable sending 0x60 by SCI IP
    while((SCISSR & BIT5) != 0);//wait TB == 0
    SCISSR = 0;//clear TI/RI/PE/OE
}

