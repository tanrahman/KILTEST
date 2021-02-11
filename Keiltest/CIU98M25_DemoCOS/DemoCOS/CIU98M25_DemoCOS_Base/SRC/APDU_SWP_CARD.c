/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	APDU_SWP_CARD.c
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
				
******************************************************/
#include "../inc/Declare.h"

#define  cls	G_APDUBuf[1]
#define  ins	G_APDUBuf[2]
#define  p1		G_APDUBuf[3]
#define  p2		G_APDUBuf[4]
#define  p3		G_APDUBuf[5]	

#define  p3_APDU_Gate		G_APDUGateBuf[4]

extern unsigned short SW1SW2_SWP;
extern unsigned short SW1SW2_SWP_APDU_Gate;

/****************************************************************************
  Function:      cmd_TS695_SWP
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void cmd_TS695_SWP(void)
{
    G_APDULen = p3 + 5;
    SW1SW2_SWP = 0x9000;	    	
}
/****************************************************************************
  Function:      cmd_getResponse_SWP
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void cmd_getResponse_SWP(void)
{
	INT32U i;

	G_APDUBuf[1] = 0x61;
	G_APDUBuf[2] = 0x12;
	G_APDUBuf[3] = 0x12;
	G_APDUBuf[4] = 0x4F;
	G_APDUBuf[5] = 0x10;	
	for(i=0;i<16;i++)
	{
		G_APDUBuf[6+i] = i;
	}
    
	G_APDULen = 0x15;
    SW1SW2_SWP = 0x9000;
}
/****************************************************************************
  Function:      cmd_selectFile_SWP
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void cmd_selectFile_SWP(void)
{	
    if(p3 == 0x02)
    {
        SW1SW2_SWP = 0x6115; 
    }
    else
    {
        SW1SW2_SWP = 0x9000; 
    }
    G_APDULen = 0x00;
}
/****************************************************************************
  Function:      SWPAPDU_Dispatch
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SWPAPDU_Dispatch(void)
{
	SW1SW2_SWP = 0x6D00;

    if(G_GetRFType == 0)
	{
        G_APDUBuf[0] = 0x00;
    }
    else
    {
        G_APDUBuf[0] = 0x01;
    }    
    
	switch(ins)
	{
		case 0x01:
		    cmd_TS695_SWP();  
            break;
		case 0xC0:
			cmd_getResponse_SWP();
			break;
		case 0xA4:
            cmd_selectFile_SWP();						
			break;
		default:
			G_APDULen = 0x00;
			SW1SW2_SWP = 0x6D00;
			break;
	}
	
	G_APDUBuf[G_APDULen+1] = (INT8U)(SW1SW2_SWP>>8);
	G_APDUBuf[G_APDULen+2] = (INT8U)SW1SW2_SWP;
	G_APDULen += 0x02;
}

/****************************************************************************
  Function:      SWPAPDU_Dispatch_APDU_GATE
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void SWPAPDU_Dispatch_APDU_GATE(void)
{
	SW1SW2_SWP_APDU_Gate = 0x9000;    
	G_APDUGateLen = p3_APDU_Gate;
	
	G_APDUGateBuf[G_APDUGateLen] = (INT8U)(SW1SW2_SWP_APDU_Gate >> 8);
	G_APDUGateBuf[G_APDUGateLen+1] = (INT8U)SW1SW2_SWP_APDU_Gate;
	G_APDUGateLen += 0x02;
}

