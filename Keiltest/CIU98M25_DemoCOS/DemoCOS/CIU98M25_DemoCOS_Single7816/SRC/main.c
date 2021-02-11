/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	CIU98M25_DemoCOS_Single7816
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
 
******************************************************/
/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	main.c
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
				
******************************************************/
#include "../inc/Declare.h"

/*SCI interface related variables*/
INT8U G_ATR[] = {0x08,0x16,0x96,0x81,0x17,0x01,0xDD,0xB1,0x10};//0x3B sent by hardware
INT16U G_APDU_SxLen;      //APDU send len 
INT16U SW1SW2;
INT8U G_FiDi;
INT8U SCIAPDUBuf[260];
/*SCI interface related variables*/

/****************************************************************************
  Function:      main
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
int main(void)
{    
    closeWrSwitch();//disable NVM operation
    
    while((SYSINFST & BIT0) == 0);
    while((SYSRSTFLAG & BIT2) == 0);

    if((SYSRSTFLAG & BIT9) != 0)
    {//cold reset
        ;
    }
    else
    {//warm reset
        ;
    }        
    G_FiDi = 0x11;
    HED_T0_SendNBytes(G_ATR+1,G_ATR[0]);//send ATR
    HED_ChangeSYSFreq(SYSCLK_AHB_36Mhz,APB_EQU_AHB);//switch SYSCLK to high level
    SYSRSTFLAG = 0;

    while(1)
    {
        /*if run on Develepment Tool's DEBUG MODE,don't enter standby*/
        /*if run on Develepment Tool's RUN MODE,do enter standby*/        
        //HED_SetToStandby();
        
        HED_T0_ReceiveNBytesRam(SCIAPDUBuf,1);
        if (SCIAPDUBuf[0] == 0xFF)
        {
            DEMOCOS_PPS();
        }
        else
        {
            HED_T0_ReceiveNBytesRam (SCIAPDUBuf+1, 4);
            
            openWrSwitch();//enable NVM operation            
            DemoCos_APDU_Dispatch();            
            closeWrSwitch();//disable NVM operation
            
            DemoCos_DelayNETU(2);
            HED_T0_SendNBytes(SCIAPDUBuf,G_APDU_SxLen);
        }            
    }
}
