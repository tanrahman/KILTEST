
/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	DEMO_APDU.c
 Author:    	xuewsh
 Version:		V1.0
 Date:  		2014-11-14
 Description: 
 History:	
				V1.0	2014-11-14	initial version
******************************************************/
#include  "../inc/declare.h" 

extern INT8U SPIAPDUBuf[];
extern INT16U G_APDU_SxLen;
extern INT16U SW1SW2;
void CMD_GetInfo(void);
void CMD_ReadRAM(void);

#define APDU_CLA    SPIAPDUBuf[0]
#define APDU_INS    SPIAPDUBuf[1]
#define APDU_P1     SPIAPDUBuf[2]
#define APDU_P2     SPIAPDUBuf[3]
#define APDU_P3     SPIAPDUBuf[4]

#define RAM_SizeLimit       0x9FFF     

//command list
static const COMMANDLIST CMD_INSList[]=
{ 
	{0xC4, CMD_GetInfo},
    {0x08, CMD_ReadRAM}
};
/************************************************* 
  Function:       Get_APDUResp 
  Description:    
  Input:          SW1SW2, store sw1 sw2
                  SCIAPDUBuf, store apdu sx data 
                  G_APDU_SxLen, store  sx data' length                 
  Output:         SCIAPDUBuf, store apdu sx data  + sw 
                  G_APDU_SxLen, store  sx data+ sw ' length
  Return:         Null
  Others:         Null 
*************************************************/
void Get_APDUResp(void)
{
    *(SPIAPDUBuf + G_APDU_SxLen) = (INT8U)(SW1SW2 >> 8);
    *(SPIAPDUBuf + G_APDU_SxLen + 1) = (INT8U)(SW1SW2 & 0xFF);
    G_APDU_SxLen += 2;
}
/************************************************* 
  Function:      DemoCos_APDU_Dispatch
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void DemoCos_APDU_Dispatch(void)
{
    INT8U i;
    
    SW1SW2 = 0x6D00;
    G_APDU_SxLen = 0;
    
    for(i=0;i<(sizeof(CMD_INSList)/sizeof(COMMANDLIST));i++)
    {
    	if((CMD_INSList[i].ins == APDU_INS))
    	{
    		CMD_INSList[i].func();
    		break;
    	}                           			
    }
    Get_APDUResp();
    HED_SPIS_SendNBytes(SPIAPDUBuf,G_APDU_SxLen);
}
/************************************************* 
  Function:      CMD_GetInfo
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void CMD_GetInfo(void)
{
	HED_SPIS_SendNBytes(&APDU_INS,1);
    SPIAPDUBuf[0] = 0x0D;
    SPIAPDUBuf[1] = 0x04;
    SPIAPDUBuf[2] = 0x00;
    G_APDU_SxLen = 0x03;
    SW1SW2 = 0x9000;
}
/************************************************* 
  Function:      CMD_ReadRAM
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void CMD_ReadRAM(void)
{
	INT32U RAM_AddrBase;
	INT32U RAM_AddrOffset;
    
    RAM_AddrBase = 0x20000000;
    RAM_AddrOffset = (APDU_P1 << 8) | (APDU_P2);

    if(RAM_AddrOffset > RAM_SizeLimit)
    {
        SW1SW2 = 0x6A86;
    }
    else
    {
        HED_SPIS_SendNBytes(&APDU_INS,1);
        G_APDU_SxLen = APDU_P3;
        memcpy(SPIAPDUBuf,(INT8U *)(RAM_AddrBase+RAM_AddrOffset),APDU_P3);
        SW1SW2 = 0x9000;
    }
}
