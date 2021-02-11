/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	SubFunc.c
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
******************************************************/
#include "../inc/Declare.h"

#define         SFR_InitValue_Buffer_FlashLocation   (100*1024)//demo for user,cos can modify this address

#define         SYSVR12PB_InitValue             0x0
#define         SYSNVMVR12PB_InitValue          0x0
#define         SYSVR18PB_InitValue             0x020102


//this buffer can be abmodified by APDU in COS design
const unsigned int SFR_InitValue_Buffer[3] __at(SFR_InitValue_Buffer_FlashLocation) = {SYSVR12PB_InitValue,SYSNVMVR12PB_InitValue,SYSVR18PB_InitValue};

/****************************************************************************
  Function:      PpsExchange
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void PpsExchange(void)
{
	
	register INT32U len,pck;
	register INT32U i;

	PPS_PPSS = 0xff;
	len = 1; 
	for (i = 4; i<7; i++)
	{
		if (((PPS_PPS0 >> i) & 1) == 1)
			len++;
	}
	
	while(G_SCIRecieveIndex != (len+2));//wait pps data all received

	pck = 0x00;
	for (i = 0; i<(len+2); i++)
	{
		pck = pck ^ SCIAPDUBuf[i];
	}
	if (pck == 0)
	{
		SCI_DelayNETU(4);
		if ((PPS_PPS0 & 0x9F) == 0x10) 
		{
			/* find FD */
            if (PPS_PPS1 == 0x96)
			{
				/* send pps response */
				PPS_PPS0 = 0x10;
				SCIAPDUBuf[3] = 0x79;
				HED_T0_SendByte(PPS_PPSS);
				HED_T0_SendByte(PPS_PPS0);
				HED_T0_SendByte(PPS_PPS1);
				HED_T0_SendByte(PPS_PPS2);
        SCITA1 = 0x96;               
				return;
			}            
		}
		/* send pps err response */
		HED_T0_SendByte(0xFF);
		HED_T0_SendByte(0x00);
		HED_T0_SendByte(0xFF);
	}
	else
	{
		/*means pps pck is err ,do nothing */
	}
}
/****************************************************************************
  Function:      RF_Config
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void RF_Config(void)
{
	G_APDULen = 0;//0 bytes received of HCI layer
	G_triggerResult = 0xf0;//trigger result init
	G_HCIMode = 0;//default mode is card emulation 
	G_AppOpenSta = 0;
	G_appMode = 0x0F;//APDUGate/card /reader /connectivity
	G_RFType = 0x0303;//card typeA & card typeB & reader typeA & reader typeB
	G_ReaderTimerOutInteger = 0x18;
    G_bFstAPDU = 0;
    G_bRFIndicator = 0;
    G_bAPPSendType = 1;
    G_GetRFType = 0;   	
}

/****************************************************************************
  Function:      UID_Init
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void UID_Init(void)
{
    #define FACTORY_CODE_ADDR        0x1FFFFE00
    #define FACTORY_UID_OFFSET       0x20
    
    aReg_CardRFTypeA_UID[0] = 0x04;//UID Length
    aReg_CardRFTypeA_UID[1] = *((unsigned char *)(FACTORY_CODE_ADDR+FACTORY_UID_OFFSET+0));//UID0
    aReg_CardRFTypeA_UID[2] = *((unsigned char *)(FACTORY_CODE_ADDR+FACTORY_UID_OFFSET+1));//UID1
    aReg_CardRFTypeA_UID[3] = *((unsigned char *)(FACTORY_CODE_ADDR+FACTORY_UID_OFFSET+2));//UID2
    aReg_CardRFTypeA_UID[4] = *((unsigned char *)(FACTORY_CODE_ADDR+FACTORY_UID_OFFSET+3));//UID3
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
    G_SYNC_PARA = 0x01;
    G_CmptblCtrl = 0x00;
    
    SYSVR12PB = SFR_InitValue_Buffer[0];//modify default value of SFR here
    SYSNVMVR12PB = SFR_InitValue_Buffer[1];//modify default value of SFR here
    SYSVR18PB = SFR_InitValue_Buffer[2];//modify default value of SFR here
}

