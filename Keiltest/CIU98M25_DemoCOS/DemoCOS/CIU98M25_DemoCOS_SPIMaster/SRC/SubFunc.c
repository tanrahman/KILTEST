
/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	DEMO_SubFunc.c
 Author:    	xuewsh
 Version:		V1.0
 Date:  		2014-11-14
 Description: 
 History:	
				V1.0	2014-11-14	initial version
******************************************************/
#include  "../inc/declare.h" 

extern INT8U SCIAPDUBuf[];
extern INT8U G_FiDi;

#define		b_SE_rd				(SCISCON & (1<<6))
#define 	MACRO_bSE_ENABLE	SCISCON |= (1<<6)
#define 	MACRO_bSE_DISABLE	SCISCON &= ~(1<<6)

#define PPS_PPSS SCIAPDUBuf[0]
#define PPS_PPS0 SCIAPDUBuf[1]
#define PPS_PPS1 SCIAPDUBuf[2]
#define PPS_PPS2 SCIAPDUBuf[3]
#define PPS_PPS3 SCIAPDUBuf[4]
#define PPS_PCK  SCIAPDUBuf[5]

#define         SFR_InitValue_Buffer_FlashLocation   (100*1024)//demo for user,cos can modify this address

#define         SYSVR12PB_InitValue             0x0
#define         SYSNVMVR12PB_InitValue          0x0
#define         SYSVR18PB_InitValue             0x020102


//this buffer can be abmodified by APDU in COS design
const unsigned int SFR_InitValue_Buffer[3] __at(SFR_InitValue_Buffer_FlashLocation) = {SYSVR12PB_InitValue,SYSNVMVR12PB_InitValue,SYSVR18PB_InitValue};

/****************************************************************************
  Function:      DemoCos_DelayNETU
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void DemoCos_DelayNETU(unsigned int nETU)
{
	while(nETU)
	{
    	SCISSR |= BIT6;/* Begin 1ETU counter */
    	while((SCISSR & BIT6) != 0)
    	{
			;
    	}
		nETU--;
	}
}
/*************************************************
  Function:      DEMOCOS_PPS
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                  
*************************************************/ 
void DEMOCOS_PPS(void)
{
	
	register INT32U len,pck;
	register INT32U i;
    INT8U  PPSFailRES[3] = {0xFF,0x00,0xFF};
    

	PPS_PPSS = 0xff;
	len = 1; 
    HED_T0_ReceiveNBytesRam(SCIAPDUBuf+1,1);
	for (i = 4; i<7; i++)
	{
		if (((PPS_PPS0 >> i) & 1) == 1)
			len++;
	}
	
	HED_T0_ReceiveNBytesRam(SCIAPDUBuf+2,len);

	/*get PCK */
	pck = 0x00;
	for (i = 0; i<(len+2); i++)
	{
		pck = pck ^ SCIAPDUBuf[i];
	}
	if (pck == 0)
	{
		DemoCos_DelayNETU(4);
		if ((PPS_PPS0 & 0x9F) == 0x10) 
		{
			/* find FD */
			if (PPS_PPS1 == 0x96)
			{
				G_FiDi = PPS_PPS1;
                /* send pps response */
				PPS_PPS0 = 0x10;
				PPS_PPS2 = 0x79;
                HED_T0_SendNBytes(&PPS_PPSS,1);
                HED_T0_SendNBytes(&PPS_PPS0,1);
                HED_T0_SendNBytes(&PPS_PPS1,1);
                HED_T0_SendNBytes(&PPS_PPS2,1);				
        SCITA1 = 0x96;               
				return;
			}
		}
		/* send pps err response */
        HED_T0_SendNBytes(&PPSFailRES[0],1);
        HED_T0_SendNBytes(&PPSFailRES[1],1);
        HED_T0_SendNBytes(&PPSFailRES[2],1);
	}
	else
	{
		/*means pps pck is err ,do nothing */
	}
}
/****************************************************************************
  Function:      DemoCos_SendINS(unsigned char ins)
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void DemoCos_SendINS(unsigned char ins)
{
    HED_T0_SendNBytes(&ins,1);//send INS
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
    SYSRSTCFG |= BIT2;//set 7816 rst to system rst
}

/****************************************************************************
  Function:      GlobalPARA_Init
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void GlobalPARA_Init(void)
{    
    SYSVR12PB = SFR_InitValue_Buffer[0];//modify default value of SFR here
    SYSNVMVR12PB = SFR_InitValue_Buffer[1];//modify default value of SFR here
    SYSVR18PB = SFR_InitValue_Buffer[2];//modify default value of SFR here
}
