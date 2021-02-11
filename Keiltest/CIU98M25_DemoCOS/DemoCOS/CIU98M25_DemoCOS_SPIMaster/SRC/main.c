/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	CIU98M25_DemoCOS_SPIMaster
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
INT8U G_ATR[] = {0x07,0x06,0x81,0x17,0x01,0xDD,0xB2,0x10};//Length+Value,0x3B sent by hardware
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
    
    SYSCLKEN |= (1 << 18) | (1 << 19);//enable GPIO/SPI clk    
    HED_DEMO_SPI_Init();//spi init
    
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
            
            DemoCos_DelayNETU(4);
            HED_T0_SendNBytes(SCIAPDUBuf,G_APDU_SxLen);
        }            
    }
}
