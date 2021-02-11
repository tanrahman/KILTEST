/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	CIU98M25_DemoCOS_SPISlave
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

INT8U SPIAPDUBuf[200];
INT16U G_APDU_SxLen;
INT16U SW1SW2;

#define         SFR_InitValue_Buffer_FlashLocation   (100*1024)//demo for user,cos can modify this address

#define         SYSVR12PB_InitValue             0x0
#define         SYSNVMVR12PB_InitValue          0x0
#define         SYSVR18PB_InitValue             0x020102


//this buffer can be abmodified by APDU in COS design
const unsigned int SFR_InitValue_Buffer[3] __at(SFR_InitValue_Buffer_FlashLocation) = {SYSVR12PB_InitValue,SYSNVMVR12PB_InitValue,SYSVR18PB_InitValue};



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
    HED_DEMO_SPI_Init();//SPI init

    while(1)
    {
        /*if run on Develepment Tool's DEBUG MODE,don't enter standby*/
        /*if run on Develepment Tool's RUN MODE,do enter standby*/        
        //HED_SetToStandby();
        HED_SPIS_ReceiveNBytesRam(SPIAPDUBuf,0x05); //Rx APDU
        openWrSwitch();//enable NVM operation            
        DemoCos_APDU_Dispatch();            
        closeWrSwitch();//disable NVM operation           
        SPIST &= ~1;
    }
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

