
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

extern INT8U SCIAPDUBuf[];
extern INT16U G_APDU_SxLen;
extern INT16U SW1SW2;
void cmd_Read_SFlash(void);
void cmd_Write_SFlash(void);

#define APDU_CLA    SCIAPDUBuf[0]
#define APDU_INS    SCIAPDUBuf[1]
#define APDU_P1     SCIAPDUBuf[2]
#define APDU_P2     SCIAPDUBuf[3]
#define APDU_P3     SCIAPDUBuf[4]

#define SFLASH_PAGE_SIZE 0x200

//command list
static const COMMANDLIST CMD_INSList[]=
{ 
	{0xC0, cmd_Read_SFlash},
    {0xCE, cmd_Write_SFlash}
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
    *(SCIAPDUBuf + G_APDU_SxLen) = (INT8U)(SW1SW2 >> 8);
    *(SCIAPDUBuf + G_APDU_SxLen + 1) = (INT8U)(SW1SW2 & 0xFF);
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
    SCI_StopTx60();
}
/************************************************* 
  Function:      cmd_Read_SFlash
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_Read_SFlash(void)
{    
    unsigned int FlashAddr;
    unsigned int ucLen,ret;  
    unsigned char SpiBuf[256];

    FlashAddr = ((APDU_P1<<8) | APDU_P2) * SFLASH_PAGE_SIZE;
    HED_T0_SendNBytes(&APDU_INS,1);
    if(APDU_P3 == 0)
    {
        APDU_P3 = 0xFF;
        ucLen = APDU_P3 + 1;
    }
    else
    {
        ucLen = APDU_P3;
    }

    ret = SPIM_ReadSFlashNbytes(SpiBuf,FlashAddr,ucLen);
    if(ret == 0)
    {
        memcpy(SCIAPDUBuf,SpiBuf,ucLen);
        G_APDU_SxLen = ucLen; 
        SW1SW2 = 0x9000;
    }
    else
    {
        SW1SW2 = 0x6A86;
    }    
}
/************************************************* 
  Function:      cmd_Write_SFlash
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_Write_SFlash(void)
{
	unsigned char ucLen;
	unsigned int FlashAddr;
    unsigned char SpiBuf[256];
    unsigned int ret;
    
    FlashAddr = ((APDU_P1<<8) | APDU_P2) * SFLASH_PAGE_SIZE;
    HED_T0_SendNBytes(&APDU_INS,1);
	ucLen = APDU_P3;
	HED_T0_ReceiveNBytesRam(SpiBuf, ucLen);

	ret = SPIM_WriteSFlashNbytes(SpiBuf,FlashAddr,ucLen);
    if(ret == 0)
    {
        SW1SW2 = 0x9000;
    }
    else
    {
        SW1SW2 = 0x6A86;
    }
}
