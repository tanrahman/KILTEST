#line 1 "SRC\\DEMO_APDU.c"











 
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
#line 14 "SRC\\DEMO_APDU.c"

extern unsigned char SCIAPDUBuf[];
extern unsigned short G_APDU_SxLen;
extern unsigned short SW1SW2;
void cmd_Data_Loop(void);








static const COMMANDLIST CMD_INSList[]=
{ 
	{0x01, cmd_Data_Loop},
};










 
void Get_APDUResp(void)
{
    *(SCIAPDUBuf + G_APDU_SxLen) = (unsigned char)(SW1SW2 >> 8);
    *(SCIAPDUBuf + G_APDU_SxLen + 1) = (unsigned char)(SW1SW2 & 0xFF);
    G_APDU_SxLen += 2;
}







 
void DemoCos_APDU_Dispatch(void)
{
    unsigned char i;
    
    SW1SW2 = 0x6D00;
    G_APDU_SxLen = 0;
    
    for(i=0;i<(sizeof(CMD_INSList)/sizeof(COMMANDLIST));i++)
    {
    	if((CMD_INSList[i].ins == SCIAPDUBuf[1]))
    	{
    		CMD_INSList[i].func();
    		break;
    	}                           			
    }
    Get_APDUResp();
    SCI_StopTx60();
}








 
void cmd_Data_Loop(void)
{
    if(SCIAPDUBuf[2] == 0x02)
    {
        DemoCos_SendINS(SCIAPDUBuf[1]);
        HED_T0_ReceiveNBytesRam(SCIAPDUBuf+5, SCIAPDUBuf[4]);
    }
    else
    {
        DemoCos_SendINS(SCIAPDUBuf[1]);
        G_APDU_SxLen = SCIAPDUBuf[4];
    }
    SW1SW2 = 0x9000;
}
