/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: CIU98M25_API_NVM_STABILITY.c
 Author:    	
 Version:       
 Date:      	
 Description:   NVM operation function
 History:	
                V1.0	2014-11-26	initial version                
******************************************************/
#include "CIU98M25_SFR_C.H"

#define ONE_PAGE_SIZE 		        0x200

#define NVMEPKEY	 		        0x57AF6C00
#define NVM_MODE_ClrBuf             0x02
#define NVM_MODE_ErWr_Page		    0x04
#define NVM_MODE_ErWrCmp_Page 	    0x05
#define NVM_MODE_Er_Blk		        0x09
#define NVM_MODE_Er_Page            0x0A 
#define NVM_MODE_Wr_Page            0x0C
#define NVM_MODE_WrCmp_Page		    0x0E

#define SET_REG_BIT(reg,bit) 			(reg |= (1 << (bit)))
#define CLEAR_REG_BIT(reg,bit) 			(reg &= ~(1 << (bit)))
#define REG_BIT_IS_SET(reg,bit) 		(reg & (1 << (bit)))
#define REG_BIT_IS_CLEAR(reg,bit) 		((reg & (1 << (bit))) == 0)
#define SET_BIT(bit) 					(0x1 << (bit))
#define CLEAR_BIT(bit) 					(~(0x1 << (bit)))

typedef enum
{
    SYSNVMSTATUS_EPP = 0,
    SYSNVMSTATUS_EINT = 1,
    SYSNVMSTATUS_ABORTFLAG = 8,   
    SYSNVMSTATUS_VERIERR = 9,
    SYSNVMSTATUS_VERICRCERR = 10,
    SYSNVMSTATUS_ECCERR1 = 24,
    SYSNVMSTATUS_ALLONE = 27,
    SYSNVMSTATUS_SDPERR = 31,
}SYSNVMSTATUS_BITS;

#define FLSH_OPRT_IS_NOT_OVER               REG_BIT_IS_SET(SYSNVMSTATUS,SYSNVMSTATUS_EPP)
#define FLSH_OPRT_IS_ABORT                  REG_BIT_IS_SET(SYSNVMSTATUS,SYSNVMSTATUS_ABORTFLAG)
#define FLSH_DATA_CMP_FAIL                  REG_BIT_IS_SET(SYSNVMSTATUS,SYSNVMSTATUS_VERIERR)
#define FLSH_DATA_CMP_CRC_ECC_FAIL          REG_BIT_IS_SET(SYSNVMSTATUS,SYSNVMSTATUS_VERICRCERR)
#define FLSH_DATA_READ_ECC_FAIL             REG_BIT_IS_SET(SYSNVMSTATUS,SYSNVMSTATUS_ECCERR1)
#define FLSH_DATA_READ_ALLONE               REG_BIT_IS_SET(SYSNVMSTATUS,SYSNVMSTATUS_ALLONE)

#define CLR_FLSH_ABORT_FLAG                 CLEAR_REG_BIT(SYSNVMSTATUS,SYSNVMSTATUS_ABORTFLAG)
#define CLR_FLSH_VERIERR_FLAG               CLEAR_REG_BIT(SYSNVMSTATUS,SYSNVMSTATUS_VERIERR)

extern void setWrMode(unsigned int wrMode);

/************************************************* 
  Function:       NVMOprtInPage(unsigned int DestAddr,unsigned int * SrcAddr,unsigned int OprtMode)
  Description:    NVM operation
  Calls:          
  Input:          if SrcAddr == 0,write ~0
                  if NVM_MODE_ClrBuf,both DestAddr and SrcAddr are no sense
  Output:         none 
  Return:         none
  Others:         none 
*************************************************/ 
void FLSHOprtInPage(unsigned int DestAddr,unsigned int * SrcAddr,unsigned int OprtMode)
{
    unsigned int i;
    
    do
    {
        CLR_FLSH_ABORT_FLAG;
        __disable_irq();
        SYSNVMSDPK1 = SYSSWITCHTAG1;
        SYSNVMSDPK2 = SYSSWITCHTAG2;
        SYSNVMSDPK3 = SYSSWITCHTAG3;

        if(OprtMode == NVM_MODE_ClrBuf)
        {
            ;//no FLASH oprt,just clr PageBuffer
        }
        else if((OprtMode == NVM_MODE_Er_Blk) || (OprtMode == NVM_MODE_Er_Page))
        {
            *((unsigned int*)DestAddr) = ~0;//erase FALSH
        }
        else
        {
            if(SrcAddr == 0)
            {
                for(i=0;i<(ONE_PAGE_SIZE>>2);i++)
                {
                    *((unsigned int*)DestAddr + i) = ~0;//init FLASH with ~0
                }    
            }
            else
            {
                for(i=0;i<(ONE_PAGE_SIZE>>2);i++)
                {
                    *((unsigned int*)DestAddr + i) = *(SrcAddr + i);//write FLASH with RAM data   
                } 
            }
        }

        
        setWrMode(NVMEPKEY | OprtMode);//EE operation
        while(FLSH_OPRT_IS_NOT_OVER);
        __enable_irq();
    }while(FLSH_OPRT_IS_ABORT);
}
/************************************************* 
  Function:       HED_FlashPageInit_St (unsigned int DestAddr)   
  Description:    
  Calls:          
  Input:          
  Output:          
  Return:         
  Others:          
*************************************************/     
unsigned int HED_FlashPageInit_St (unsigned int DestAddr)
{
    DestAddr &= ~0x1FF;//page aligned

    FLSHOprtInPage(DestAddr,(unsigned int *)0,NVM_MODE_ErWrCmp_Page);
    
    if(FLSH_DATA_CMP_FAIL)
    {
        CLR_FLSH_VERIERR_FLAG;
        return ~0;//operation fail
    }
        
    return 0x00;//operation success   
}  
/************************************************* 
  Function:       HED_FlashErWrPage_St(unsigned int DestAddr,unsigned int * SrcAddr)  
  Description:    
  Calls:          
  Input:          
  Output:          
  Return:         
  Others:          
*************************************************/     
unsigned int HED_FlashErWrPage_St(unsigned int DestAddr,unsigned int * SrcAddr)
{
    DestAddr &= ~0x1FF;//page aligned

    FLSHOprtInPage(DestAddr,SrcAddr,NVM_MODE_ErWrCmp_Page);
    
    if(FLSH_DATA_CMP_FAIL)
    {
        CLR_FLSH_VERIERR_FLAG;
        return ~0;//operation fail
    }
        
    return 0x00;//operation success   
}  
/************************************************** 
  Function:       void HED_FlashPageBufClr(void) 
  Description:    
  Calls:          
  Input:          
  Output:          
  Return:         
  Others:          
*************************************************/     
void HED_FlashPageBufClr(void)
{    
    FLSHOprtInPage(0,(unsigned int *)0,NVM_MODE_ClrBuf); 
}

