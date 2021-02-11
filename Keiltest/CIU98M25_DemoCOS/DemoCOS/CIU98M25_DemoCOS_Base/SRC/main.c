/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	CIU98M25_DemoCOS_Base
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
const unsigned char G_ATR[] = {0x0D,0x3B,0x96,0x96,0x80,0x3F,0x47,0xA0,0x81,0x17,0x01,0xDD,0xB0,0x19};//tck generated when sending ATR
__attribute__((zero_init)) volatile unsigned char G_bATR_Done;//ATR sent or not
__attribute__((zero_init)) volatile unsigned char G_SCIRecieving;//C_APDU receving or not
volatile unsigned short G_SCIRecieveIndex;//received offset index of SCIAPDUBuf
volatile unsigned char G_SCIRecieveDone;//received or not for APDU Header/PPS,1:yes,0:no
volatile unsigned short G_SCISendIndex;//sent offset index of SCIAPDUBuf
unsigned char G_bSCILeSendDone;//Le data sent finish or not,1:yes,0:no
unsigned char SCIAPDUBuf[SCI_APDUBufSize];
unsigned int SCILeLength;
unsigned short SW1SW2;//for SCI
/*SCI interface related variables*/

/*SWP interface related variables*/
unsigned short SW1SW2_SWP;//for SWP card emulation
unsigned short SW1SW2_SWP_APDU_Gate;//for SWP APDU Gate
/*SWP interface related variables*/

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
	INT32U result;
    
    ;//if neccessary,COS initialize variables group 1 in HCI_lib_GVar.c
    
	HCI_GVar_Init();//SWP interface global variables' init
	GVar_SCI_Init();//SCI interface init	
	RF_Config();//RF related init
    SYSNVMCON = 0x01;//m1 related init
    G_cM1_Mode = 0x04;

	while ((G_bSWP_DetectStatus == 0) && (G_bATR_Done == 0))
	{
		;//no interface no work 
	}

	while(1)
	{
		if(G_bCLKSwitchValid == 0)
		{
			if (G_bATR_Done == 1)
			{
				HED_ChangeSYSFreq(SYSCLK_AHB_36Mhz,APB_EQU_AHB);//switch SYSCLK to high level
                //set MAX sys clk 36Mhz here,but 18Mhz on Develepment Tool
				G_bCLKSwitchValid = 1;
			}
			else if(G_bSWP_busy == 1)
			{
      			if(G_bPowerMode == 0)
				{
					HED_ChangeSYSFreq(SYSCLK_AHB_18Mhz,APB_EQU_AHB);//switch SYSCLK to low level
                    //set MAX sys clk 18Mhz here,but 9Mhz on Develepment Tool
				}
				else  
				{
                	HED_ChangeSYSFreq(SYSCLK_AHB_36Mhz,APB_EQU_AHB);//switch SYSCLK to high level
                    //set MAX sys clk 36Mhz here,but 9Mhz on Develepment Tool
				}

				if(G_bSHDLC_Status == 1)
				{
                    G_bCLKSwitchValid = 1;
				}
			}
		}
		
		if((G_bSWP_busy == 0) && (G_SCIRecieving == 0) && (G_bSCILeSendDone == 1)) 
		{
			/*if run on Develepment Tool's DEBUG MODE,don't enter standby*/
            /*if run on Develepment Tool's RUN MODE,do enter standby*/
			//HED_SetToStandby();//set chip to standby          
		}
		
		if(G_SCIRecieveDone == 1)
		{
			if(SCIAPDUBuf[0] == 0xFF)
			{
				PpsExchange();//pps process
				SCI_WaitRx(0x00);
			}
			else
			{  				
				openWrSwitch();
                SCIAPDU_Dispatch();//APDU process
                closeWrSwitch();
			}
		}
        
        openWrSwitch();
		result = HCI_RxManage();//HCI process
        closeWrSwitch();
        
		if(result == 0x11)//output data available from HCI Layer
		{
			if(G_HCIMode == 0)//card emulation mode
			{
				if((result == 0x11) && (G_bRFIndicator == 0))//APDU received on card emulation mode 
				{
					openWrSwitch();
                    SWPAPDU_Dispatch();//SWP C_APDU process
                    closeWrSwitch();
					HCI_CardMode_Send();//send R_APDU
				}
			}			
		}
        else if(result == 0x15)
        {
            openWrSwitch();
            SWPAPDU_Dispatch_APDU_GATE();//SWP C_APDU process
            closeWrSwitch();
            HCI_APDU_Gate_Send();//send R_APDU
        }
        else if(result == 0x61)
        {
            ;
        } 
        else if(result == 0x62)
        {
            ;
        }         
	}
}
