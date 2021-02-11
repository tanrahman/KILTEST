#line 1 "SRC\\SubFunc.c"











 
#line 1 "SRC\\../inc/declare.h"









 



#line 1 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"


  
  typedef unsigned int size_t;








extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 185 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 201 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 224 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 239 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 262 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 494 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"



 

#line 15 "SRC\\../inc/declare.h"
#line 1 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\absacc.h"
 
 
 










#line 16 "SRC\\../inc/declare.h"
#line 1 "SRC\\../inc/CIU98M25_SFR_C.h"









 






 


 






 

#line 35 "SRC\\../inc/CIU98M25_SFR_C.h"


#line 46 "SRC\\../inc/CIU98M25_SFR_C.h"


#line 55 "SRC\\../inc/CIU98M25_SFR_C.h"







#line 69 "SRC\\../inc/CIU98M25_SFR_C.h"






#line 89 "SRC\\../inc/CIU98M25_SFR_C.h"



 







 
#line 109 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 121 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 133 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 158 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 171 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 201 "SRC\\../inc/CIU98M25_SFR_C.h"



 

#line 233 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 252 "SRC\\../inc/CIU98M25_SFR_C.h"

#line 17 "SRC\\../inc/declare.h"
#line 1 "SRC\\../inc/DEMO_APDU.h"









 



void DemoCos_APDU_Dispatch(void);

#line 18 "SRC\\../inc/declare.h"
#line 1 "SRC\\../inc/SubFunc.h"









 






void DEMOCOS_PPS(void);
void DemoCos_DelayNETU(unsigned int nETU);
void SCI_StopTx60(void);
void SCI_Init(void);
void DemoCos_SendINS(unsigned char ins);
void GlobalPARA_Init(void);

#line 31 "SRC\\../inc/SubFunc.h"



#line 19 "SRC\\../inc/declare.h"
#line 1 "SRC\\../inc/TYPEDEF.h"










 











 




typedef     unsigned char   bool;

#line 56 "SRC\\../inc/TYPEDEF.h"






typedef struct 
{
    unsigned char ins;
    void (*func)(void);
}COMMANDLIST;
#line 20 "SRC\\../inc/declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_Base_NoNVM.h"










 





 
typedef enum
{
    SYSCLK_AHB_36Mhz =  0x0, 
    SYSCLK_AHB_18Mhz  =  0x1, 
    SYSCLK_AHB_15Mhz  =  0x2, 
    SYSCLK_AHB_6Mhz  =  0x6, 
}SYS_FREQUENCY_DIVISOR;

typedef enum
{
	APB_EQU_AHB = 0,
	APB_HALF_AHB = 1,
} APB_FREQUENCY_DIVISOR;

 
 
unsigned int HED_T0_SendNBytes(unsigned char * DataAddr, unsigned int DataLen);
void HED_T0_ReceiveNBytesRam(unsigned char * DataAddr, unsigned int DataLen); 
 
unsigned short HED_CRC16(unsigned short IV, unsigned int DataLen, unsigned char *DataBuf, unsigned char type);
 
void HED_GetChipId(unsigned char *ChipId);
 
void HED_GetFactoryCode(unsigned char * FactoryCode);
 
void HED_ChangeSYSFreq(SYS_FREQUENCY_DIVISOR SysDiv, APB_FREQUENCY_DIVISOR APBDiv); 
 
void HED_SetToStandby(void);
 
void HED_SPIM_SendNBytes(unsigned char *DataAddr, unsigned int DataLen);
void HED_SPIM_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen);
 
void HED_SPIS_SendNBytes(unsigned char *DataAddr, unsigned int DataLen);
unsigned char HED_SPIS_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen);

#line 21 "SRC\\../inc/declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_LIB_STABILITY.h"










 



void openWrSwitch(void);
void closeWrSwitch(void);
void chkWrSwitch(void);    
void setWrMode(unsigned int nvmMode);

#line 22 "SRC\\../inc/declare.h"
#line 1 "SRC\\../inc/SPI.h"









 








#line 25 "SRC\\../inc/SPI.h"

typedef enum
{
	BIT_VAL_0 = 0,
	BIT_VAL_1 =1,
} BIT_VALUE;
typedef enum
{
	SPI_STANDARD = 0x00,
	SPI_DUAL_IN = 0x01,
	SPI_DUAL_OUT = 0x02,
	SPI_QUAD_IN = 0x03,
	SPI_QUAD_OUT = 0x04,
} SPI_WORK_MODE;
typedef enum 
{
	SPICON_MSTR = 0,
	SPICON_CPHA = 1,
	SPICON_CPOL = 2,
	SPICON_LSBFE = 3,
	SPICON_MODSEL = 4,
} SPICON_BITS;

typedef enum 
{
	SPIST_DONE = 0,
	SPIST_OVRF = 1,
} SPIST_BITS;

typedef enum 
{
	SPIDIV_DIV = 0,
	SPIDIV_MDIV_EN = 8,
} SPIDIV_BITS;

typedef enum 
{
	SPIIE_DONEI_EN = 0,
	SPIIE_OVRFI_EN = 1,
} SPIIE_BITS;

typedef enum 
{
	SPIIS_DONE_INT = 0,
	SPIIS_OVRF_INT = 1,
} SPIIS_BITS;

typedef enum 
{
	SPISTR_TRE = 0,
} SPISTR_BITS;
	

typedef enum
{
    SPI_MOSI_1 = 1,
    SPI_MISO = 2,
    SPI_MOSI = 3,
    SPI_SCK = 4,
    SPI_SS = 5,
} GPIO_BITS;



typedef enum
{
	SFLASH_STATUS_REGISTER_WIP = 0,
	SFLASH_STATUS_REGISTER_WEL = 1,
	SFLASH_STATUS_REGISTER_BP0 = 2,
	SFLASH_STATUS_REGISTER_BP1 = 3,
	SFLASH_STATUS_REGISTER_BP2 = 4,
	SFLASH_STATUS_REGISTER_BP3 = 5,
	SFLASH_STATUS_REGISTER_BP4 = 6,
	SFLASH_STATUS_REGISTER_SRP0 = 7,
    SFLASH_STATUS_REGISTER_SRP1 = 8,
    SFLASH_STATUS_REGISTER_QE = 9
} SFLASH_STATUS_REGISTER_BITS;


#line 112 "SRC\\../inc/SPI.h"





















void WaitSFlashIdle(void);
unsigned char SPIM_ReadSFlashNbytes(unsigned char * DataBuf,unsigned int  FlashAddr , unsigned int  DataLen );
unsigned char SPIM_WriteSFlashNbytes(unsigned char * DataBuf,unsigned int  FlashAddr , unsigned int  DataLen );

void HED_DEMO_SPI_Init(void);

#line 23 "SRC\\../inc/declare.h"
#line 14 "SRC\\SubFunc.c"

extern unsigned char SCIAPDUBuf[];
extern unsigned char G_FiDi;





#line 28 "SRC\\SubFunc.c"









const unsigned int SFR_InitValue_Buffer[3] __attribute__ ((at((100*1024)))) = {0x0,0x0,0x020102};








 
void DemoCos_DelayNETU(unsigned int nETU)
{
	while(nETU)
	{
    	(*((volatile unsigned long *)(0x40001000 + 0x08 ))) |= (1ul<<6); 
    	while(((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & (1ul<<6)) != 0)
    	{
			;
    	}
		nETU--;
	}
}







  
void DEMOCOS_PPS(void)
{
	
	register unsigned int len,pck;
	register unsigned int i;
    unsigned char  PPSFailRES[3] = {0xFF,0x00,0xFF};
    

	SCIAPDUBuf[0] = 0xff;
	len = 1; 
    HED_T0_ReceiveNBytesRam(SCIAPDUBuf+1,1);
	for (i = 4; i<7; i++)
	{
		if (((SCIAPDUBuf[1] >> i) & 1) == 1)
			len++;
	}
	
	HED_T0_ReceiveNBytesRam(SCIAPDUBuf+2,len);

	 
	pck = 0x00;
	for (i = 0; i<(len+2); i++)
	{
		pck = pck ^ SCIAPDUBuf[i];
	}
	if (pck == 0)
	{
		DemoCos_DelayNETU(4);
		if ((SCIAPDUBuf[1] & 0x9F) == 0x10) 
		{
			 
			if (SCIAPDUBuf[2] == 0x96)
			{
				G_FiDi = SCIAPDUBuf[2];
                 
				SCIAPDUBuf[1] = 0x10;
				SCIAPDUBuf[3] = 0x79;
                HED_T0_SendNBytes(&SCIAPDUBuf[0],1);
                HED_T0_SendNBytes(&SCIAPDUBuf[1],1);
                HED_T0_SendNBytes(&SCIAPDUBuf[2],1);
                HED_T0_SendNBytes(&SCIAPDUBuf[3],1);				
        (*((volatile unsigned long *)(0x40001000 + 0x18 ))) = 0x96;               
				return;
			}
		}
		 
        HED_T0_SendNBytes(&PPSFailRES[0],1);
        HED_T0_SendNBytes(&PPSFailRES[1],1);
        HED_T0_SendNBytes(&PPSFailRES[2],1);
	}
	else
	{
		 
	}
}







 
void DemoCos_SendINS(unsigned char ins)
{
    HED_T0_SendNBytes(&ins,1);
}







  
void SCI_StopTx60(void)
{
    (*((volatile unsigned long *)(0x40001000 + 0x1C ))) = 0x00;
    while(((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & (1ul<<5)) != 0);
    (*((volatile unsigned long *)(0x40001000 + 0x08 ))) = 0;
}







 
void SCI_Init(void)
{
	(*((volatile unsigned long *)(0x50007000 + 0x200))) |= (1ul<<17);
    
    (*((volatile unsigned long *)(0x40001000 + 0x04 ))) = 0xE53;
    (*((volatile unsigned long *)(0x50007000 + 0x188))) |= (1ul<<2);
}








 
void GlobalPARA_Init(void)
{    
    (*((volatile unsigned long *)(0x50007000 + 0x294))) = SFR_InitValue_Buffer[0];
    (*((volatile unsigned long *)(0x50007000 + 0x298))) = SFR_InitValue_Buffer[1];
    (*((volatile unsigned long *)(0x50007000 + 0x29C))) = SFR_InitValue_Buffer[2];
}
