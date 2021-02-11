#line 1 "API\\CIU98M25_API_Base_NoNVM.c"










 
#line 1 ".\\INC\\CIU98M25_SFR_C.H"









 






 


 






 

#line 35 ".\\INC\\CIU98M25_SFR_C.H"


#line 46 ".\\INC\\CIU98M25_SFR_C.H"


#line 55 ".\\INC\\CIU98M25_SFR_C.H"







#line 69 ".\\INC\\CIU98M25_SFR_C.H"






#line 89 ".\\INC\\CIU98M25_SFR_C.H"



 







 
#line 109 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 121 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 133 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 158 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 171 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 201 ".\\INC\\CIU98M25_SFR_C.H"



 

#line 233 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 252 ".\\INC\\CIU98M25_SFR_C.H"

#line 13 "API\\CIU98M25_API_Base_NoNVM.c"
#line 1 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
 
 
 




 
 



 













  


 








#line 46 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


  
  typedef unsigned int size_t;










    



    typedef unsigned short wchar_t;  
#line 75 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { __int64 quot, rem; } lldiv_t;
    


#line 96 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
   



 

   




 
#line 115 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) __int64 atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) __int64 strtoll(const char * __restrict  ,
                               char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned __int64 strtoull(const char * __restrict  ,
                                         char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 415 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 503 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 532 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __pure int abs(int  );
   



 

extern __declspec(__nothrow) __pure div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __pure long int labs(long int  );
   



 




extern __declspec(__nothrow) __pure ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __pure __int64 llabs(__int64  );
   



 




extern __declspec(__nothrow) __pure lldiv_t lldiv(__int64  , __int64  );
   











 
#line 613 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"



 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __pure __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 



 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 867 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\stdlib.h"


 

#line 14 "API\\CIU98M25_API_Base_NoNVM.c"
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



 

#line 15 "API\\CIU98M25_API_Base_NoNVM.c"




 
 
#line 28 "API\\CIU98M25_API_Base_NoNVM.c"
 
#line 35 "API\\CIU98M25_API_Base_NoNVM.c"
 



 






#line 52 "API\\CIU98M25_API_Base_NoNVM.c"


typedef  enum 
{
	SEC_SYSCLKEN_CRCEN = 0,
	SEC_SYSCLKEN_DESEN = 1,
	SEC_SYSCLKEN_SM1EN = 2,
	SEC_SYSCLKEN_PKEEN = 4,
	SEC_SYSCLKEN_AESEN = 5,    
	SEC_SYSCLKEN_RNG1EN  = 8,
	SEC_SYSCLKEN_TIMEREN = 9,
	SEC_SYSCLKEN_WDTEN = 10,
	SEC_SYSCLKEN_SM4EN = 11,
	SEC_SYSCLKEN_SM3EN = 12,    
	SEC_SYSCLKEN_SCIEN = 17,
	SEC_SYSCLKEN_SPIEN = 18,    
	SEC_SYSCLKEN_GPIOEN = 19,
	SEC_SYSCLKEN_SWPEN = 20,    
} SEC_SYSCLKEN_BITS;

typedef enum 
{
	SYSRSTCFG_7816RSTEN = 2,
	SYSRSTCFG_FDRSTEN = 3,
	SYSRSTCFG_TDRSTEN = 4,
    SYSRSTCFG_GDRSTEN = 5,
	SYSRSTCFG_VDRSTEN = 6,
    SYSRSTCFG_LDRSTEN = 7,
	SYSRSTCFG_SECRSTEN = 8,
} SYSRSTCFG_BITS;



typedef enum 
{
	SCISCON_RCNT_0 = 0,
	SCISCON_RCNT_1 = 1,
	SCISCON_PARITY = 2 ,
	SCISCON_IVC = 3,
	SCISCON_EGB = 4,
	SCISCON_PS = 5,
	SCISCON_SE = 6,
    SCISCON_WTC = 7,
    SCISCON_AWTS = 8,
    SCISCON_SAFB = 10,
    SCISCON_RTS = 11,
} SCISCON_BITS;


typedef enum 
{
	SCISSR_OE = 0,
	SCISSR_PE = 1,
	SCISSR_RI = 2 ,
	SCISSR_RB = 3,
	SCISSR_TI = 4,
	SCISSR_TB = 5,
	SCISSR_SETU = 6,
} SCISSR_BITS;

typedef enum 
{
	SCIRXFCR_FLUSH_RX_FIFO = 0,
	SCIRXFCR_RX_EMPTY = 1,
	SCIRXFCR_WATER_LEVEL = 2 ,
} SCIRXFCR_BITS;

typedef enum 
{
	SCITXFCR_FLUSH_TX_FIFO = 0,
	SCITXFCR_TX_FULL = 1,
} SCITXFCR_BITS;



typedef enum
{
	TIMERXCONTROL_ONESHOTCOUNT = 0,
	TIMERXCONTROL_TIMERSIZE = 1,
	TIMERXCONTROL_TIMERPRE = 2,
	TIMERXCONTROL_ETUCOUNT = 4,
	TIMERXCONTROL_TIMERMODE = 6,
	TIMERXCONTROL_TIMERENABLE = 7,
} TIMERXCONTROL_BITS;

typedef enum
{
	TIMERXIS_TIMERINERRUPT = 0,
} TIMERXIS_BITS;


typedef enum
{
	CRCCSR_CRC_ST = 0,
	CRCCSR_INPUT_REV = 1,
	CRCCSR_OUTPUT_REV = 2,
	CRCCSR_OUTPUT_NOT = 3,
	CRCCSR_WIDTH_0 = 4,
	CRCCSR_WIDTH_1 = 5,
} CRCCSR_BITS;	

typedef enum 
{
	SYSCLKCFG_SYSDIV = 4,
    SYSCLKCFG_APBDIV = 12,
    SYSCLKCFG_PKEDIV = 20,
} SYSCLKCFG_BITS;

 
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

 














  
unsigned int HED_T0_SendNBytes (unsigned char * DataAddr , unsigned int DataLen)
{
	if(DataLen == 0) 
	{
		return (2);
	}

	
	while(((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & ((1 << SCISSR_RB)|(1 << SCISSR_TB)))); 

	
	((*((volatile unsigned long *)(0x40001000 + 0x04 ))) &= ~(3 << SCISCON_RCNT_0)); 
	((*((volatile unsigned long *)(0x40001000 + 0x04 ))) |= ((3 - 2) & 0x3));

	while(DataLen--)
	{
		
		(*((volatile unsigned long *)(0x40001000 + 0x00 ))) = (*DataAddr++);
		while((((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & (1 << (SCISSR_TI))) == 0));

		if(((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & (1 << (SCISSR_PE))) == 0 )
		{
			(*((volatile unsigned long *)(0x40001000 + 0x08 ))) = 0;							
		}
		else
		{
			(*((volatile unsigned long *)(0x40001000 + 0x10 ))) = 0x01;					
			while (((*((volatile unsigned long *)(0x40001000 + 0x10 ))) & 0x01) == 0x01);
			(*((volatile unsigned long *)(0x40001000 + 0x08 ))) = 0;							
			return (1);    	
		}
	}
	return (0);
}











  
void HED_T0_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
{
	while(((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & ((1 << SCISSR_RB)|(1 << SCISSR_TB))));

	while(DataLen--)
	{	 	      
		
		while(((*((volatile unsigned long *)(0x40001000 + 0x14 ))) & (1 << (SCIRXFCR_RX_EMPTY))));
		(*DataAddr++) = (unsigned char)(*((volatile unsigned long *)(0x40001000 + 0x00 ))); 
	}
}

 














  
unsigned short HED_CRC16(unsigned short IV, unsigned int DataLen, unsigned char *DataBuf, unsigned char type)
{
	unsigned int tmp_cnt = (unsigned int)DataBuf & 0x3; 
	unsigned int div4_quotient, div4_mod;   

	if(DataLen == 0)
	{
		return IV;
	}
	
	(*((volatile unsigned long *)(0x50005000 + 0x08 ))) = IV;
	(*((volatile unsigned long *)(0x50005000 + 0x00 ))) = ((type&0x3)<<1) | (0x1 << (CRCCSR_CRC_ST));

	if (DataLen <= 0x07)
	{
		div4_quotient = 0;
		div4_mod = DataLen;   
	}
	else
	{
		unsigned int curr_crccsr = (*((volatile unsigned long *)(0x50005000 + 0x00 )));
		if (tmp_cnt)
		{
			tmp_cnt = 0x4 - tmp_cnt;
			DataLen -= tmp_cnt;
			((*((volatile unsigned long *)(0x50005000 + 0x00 ))) |= (1<<5));   
			while (tmp_cnt--)
			{
				(*((volatile unsigned long *)(0x50005000 + 0x04 ))) = *DataBuf++;
			}
		}
		div4_quotient = DataLen >> 0x02; 
		div4_mod = DataLen & 0x3;   
		(*((volatile unsigned long *)(0x50005000 + 0x00 ))) = curr_crccsr;

		if (div4_quotient)
		{
			unsigned int * tmp_databuf = (unsigned int *)DataBuf;
			while (div4_quotient--)
			{
				(*((volatile unsigned long *)(0x50005000 + 0x04 ))) = *(unsigned int *)tmp_databuf++;
			}
			DataBuf = (unsigned char *)tmp_databuf;
		}
	}

	if (div4_mod)	
	{
		((*((volatile unsigned long *)(0x50005000 + 0x00 ))) |= (1<<5));   
		while (div4_mod--)
		{
			(*((volatile unsigned long *)(0x50005000 + 0x04 ))) = *DataBuf++;
		}

	}

	return (unsigned short)(*((volatile unsigned long *)(0x50005000 + 0x04 )));
}


 
void HED_GetChipInfo(unsigned char *DataBuf, unsigned int FlashAddr, unsigned int DataLen)
{
	while(DataLen--)
	{
		*DataBuf++ = *(unsigned char *)FlashAddr;
		FlashAddr += 0x00000001;
	}
} 
 








  
void HED_GetChipId(unsigned char *ChipId)
{
    unsigned char die_YX_position;
    unsigned char test_month;
    
    HED_GetChipInfo(ChipId,  0x1FFFFE00+0x09, 1);	
    
     
    HED_GetChipInfo(&die_YX_position,  0x1FFFFE00+0x17, 1);	
    HED_GetChipInfo(&test_month,  0x1FFFFE00+0x0A, 1);	
    die_YX_position = ((die_YX_position & 0x10) << 3) | ((die_YX_position & 0x01) << 6);    
    test_month = (test_month >> 4)*10 + (test_month & 0x0F);
    test_month &= 0x3F;
    ChipId[1] = die_YX_position | test_month;
     
    
    HED_GetChipInfo(ChipId+2,  0x1FFFFE00+0x1C, 1);	
    HED_GetChipInfo(ChipId+3,  0x1FFFFE00+0x1D, 1);	
    HED_GetChipInfo(ChipId+4,  0x1FFFFE00+0x1E, 1);	
    HED_GetChipInfo(ChipId+5,  0x1FFFFE00+0x1F, 1);	
    HED_GetChipInfo(ChipId+6,  0x1FFFFE00+0x0B, 1);	
    HED_GetChipInfo(ChipId+7,  0x1FFFFE00+0x0C, 1);	
    HED_GetChipInfo(ChipId+8,  0x1FFFFE00+0x1A, 1);	
    HED_GetChipInfo(ChipId+9,  0x1FFFFE00+0x1B, 1);	
    HED_GetChipInfo(ChipId+10,  0x1FFFFE00+0x0D, 1); 
    HED_GetChipInfo(ChipId+11,  0x1FFFFE00+0x0E, 1); 
    HED_GetChipInfo(ChipId+12,  0x1FFFFE00+0x0F, 1); 
}

 








  
void HED_GetFactoryCode(unsigned char *FactoryCode)
{
	HED_GetChipInfo(FactoryCode, 0x1FFFFE00, 32);
}


















 
__asm void delay(unsigned int LoopNum)
{
loopStart
    SUBS     r0,r0,#1
    BCS      loopStart
	BX		    lr
}






















  
const unsigned char SYS_PKE_ClkTable[7] = {0,1,1,7,7,7,7};

void HED_ChangeSYSFreq(SYS_FREQUENCY_DIVISOR SysDiv, APB_FREQUENCY_DIVISOR APBDiv) 
{	
	unsigned int currDiv,SysDivGap;
	unsigned int tmpSysClk;    
    
	if (APBDiv == APB_HALF_AHB)
	{
		((*((volatile unsigned long *)(0x50007000 + 0x208))) |= (1 << (SYSCLKCFG_APBDIV)));
	}
	else
	{
		((*((volatile unsigned long *)(0x50007000 + 0x208))) &= ~(1 << (SYSCLKCFG_APBDIV)));
	}
    
	tmpSysClk = (*((volatile unsigned long *)(0x50007000 + 0x208)));
    currDiv = ((*((volatile unsigned long *)(0x50007000 + 0x208))) & (0x07 << SYSCLKCFG_SYSDIV)) >> SYSCLKCFG_SYSDIV;

	if (currDiv == SysDiv)
	{
        tmpSysClk &= ~(0x07 << SYSCLKCFG_PKEDIV);
        tmpSysClk |= (SYS_PKE_ClkTable[SysDiv] << SYSCLKCFG_PKEDIV);
        (*((volatile unsigned long *)(0x50007000 + 0x208))) = tmpSysClk;
        return;
	}
	else if(currDiv > SysDiv)
	{
        SysDivGap = currDiv - SysDiv;
	}	
    else
    {
        SysDivGap = SysDiv - currDiv;
    }
    
    if((SysDivGap == 2) || (SysDivGap == 6))
    {
        tmpSysClk &= ~(0x07 << SYSCLKCFG_SYSDIV);
        tmpSysClk |= (1 << SYSCLKCFG_SYSDIV); 
        (*((volatile unsigned long *)(0x50007000 + 0x208))) = tmpSysClk; 
        delay(43);
        tmpSysClk &= ~(0x07 << SYSCLKCFG_SYSDIV);
        tmpSysClk |= (SysDiv <<SYSCLKCFG_SYSDIV);
        (*((volatile unsigned long *)(0x50007000 + 0x208))) = tmpSysClk;
    }
    else
    {
        tmpSysClk &= ~(0x07 << SYSCLKCFG_SYSDIV);
        tmpSysClk |= (SysDiv <<SYSCLKCFG_SYSDIV);
        (*((volatile unsigned long *)(0x50007000 + 0x208))) = tmpSysClk;            
    }    
    
    tmpSysClk &= ~(0x07 << SYSCLKCFG_PKEDIV);
    tmpSysClk |= (SYS_PKE_ClkTable[SysDiv] << SYSCLKCFG_PKEDIV);
    (*((volatile unsigned long *)(0x50007000 + 0x208))) = tmpSysClk;
}

 
extern unsigned char G_bSWP_busy;








  
void HED_SetToStandby(void)
{
	unsigned int bak_SYSCLKEN,bak_SYSCLKCFG;
    unsigned int bak_SYSDiv,bak_APBDiv;
    
    bak_SYSCLKEN = (*((volatile unsigned long *)(0x50007000 + 0x200)));
    bak_SYSCLKCFG = (*((volatile unsigned long *)(0x50007000 + 0x208)));
    bak_SYSDiv = (bak_SYSCLKCFG & (0x07 << SYSCLKCFG_SYSDIV)) >> SYSCLKCFG_SYSDIV;
    bak_APBDiv = (bak_SYSCLKCFG & (0x01 << SYSCLKCFG_APBDIV)) >> SYSCLKCFG_APBDIV;

	(*((volatile unsigned long *)(0x50007000 + 0x204))) = (1<<4) | (1<<11); 
    
    HED_ChangeSYSFreq(SYSCLK_AHB_6Mhz,APB_HALF_AHB);
    
	if((((((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & 0x08) == 0) && (((*((volatile unsigned long *)(0x40001000 + 0x14 ))) & 0x02) != 0))) && (G_bSWP_busy == 0x00))
    {
         __wfe(); 
    }
    
    if((bak_SYSDiv == 0) || (bak_SYSDiv == 1) || (bak_SYSDiv == 2) || (bak_SYSDiv == 6))
    {
        HED_ChangeSYSFreq((SYS_FREQUENCY_DIVISOR)bak_SYSDiv,(APB_FREQUENCY_DIVISOR)bak_APBDiv);
    }
    
	(*((volatile unsigned long *)(0x50007000 + 0x200))) = bak_SYSCLKEN;
}

 
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

 
#line 577 "API\\CIU98M25_API_Base_NoNVM.c"
 












  
void HED_Memcpy(unsigned char* to,unsigned char* from,unsigned int count)
{
	while(count-- != 0)
	{
		*to++ = *from++;
	}
}








  
unsigned int HED_WordEndianAlter(unsigned int inWord)
{
	unsigned int outWord;
    unsigned char* tmpBytePtr;
    
    tmpBytePtr = (unsigned char*)(&outWord);
    tmpBytePtr[0] = inWord >> 0;
    tmpBytePtr[1] = inWord >> 8;
    tmpBytePtr[2] = inWord >> 16;
    tmpBytePtr[3] = inWord >> 24;
    
    return outWord;
}
 








  
void HED_SPIM_SendNBytes(unsigned char *DataAddr, unsigned int DataLen)
{
	unsigned int div16Quotien, div16Mod;
	unsigned int * tmpDataAddr,* tmpSpiData;
	unsigned int disToPreviousWord,disToNextWord; 
	
    disToPreviousWord = (unsigned int)DataAddr & 0x03;
    disToNextWord = 0x04 - disToPreviousWord;
	if (DataLen == 0x00)
	{
		return;
	}

	if (disToPreviousWord) 
	{
		if (DataLen <= 0x04)
		{
			(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = DataLen - 1; 
			(*((volatile unsigned long *)(0x40001800 + 0x40 ))) = (unsigned int)((DataAddr[3] << 24) | (DataAddr[2] << 16) | (DataAddr[1] << 8) | DataAddr[0]);
			((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
			while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));
			((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT))); 
			return;
		}
		else 
		{
			(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = disToNextWord - 0x01;
            (*((volatile unsigned long *)(0x40001800 + 0x40 ))) = (unsigned int)((DataAddr[3] << 24) | (DataAddr[2] << 16) | (DataAddr[1] << 8) | DataAddr[0]);
			((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
			while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));
			((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT)));
			DataLen -= disToNextWord;
			DataAddr += disToNextWord;
		}
	}
	div16Quotien = DataLen >> 4; 
	div16Mod = DataLen & 0xF;
	tmpDataAddr = (unsigned int *)DataAddr;
	if (div16Quotien)
	{
		
		(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = 0xF; 
		while (div16Quotien--)
		{
			tmpSpiData = (unsigned int *)&(*((volatile unsigned long *)(0x40001800 + 0x40 )));
            
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);

			((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
			while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));
			((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT))); 
		}
	}

	if (div16Mod)
	{
		(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = div16Mod - 1; 
		tmpSpiData = (unsigned int *)&(*((volatile unsigned long *)(0x40001800 + 0x40 )));
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
		((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
		while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));
		((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT)));
	}
}








  
void HED_SPIM_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
{
	unsigned int div16Quotien, div16Mod;
	unsigned int* tmpDataAddr,*tmpSpiData;
	unsigned int disToPreviousWord,disToNextWord; 
	unsigned int databuf[4];
    
    disToPreviousWord = (unsigned int)DataAddr & 0x03;
	disToNextWord = 0x04 - disToPreviousWord;
	if (DataLen == 0x00)
	{
		return;
	}
	if (disToPreviousWord)
	{
		tmpDataAddr = databuf;
		tmpSpiData = (unsigned int *)&(*((volatile unsigned long *)(0x40001800 + 0x40 )));
		if (DataLen <= 0x10)
		{
			(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = DataLen - 1;
			((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
			while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));

			
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);

			((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT))); 
			HED_Memcpy(DataAddr,(unsigned char*)databuf,DataLen);
			return;
		}
		else
		{
			(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = disToNextWord - 0x01;
			((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
			while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));
			
            *tmpDataAddr++ = HED_WordEndianAlter((*((volatile unsigned long *)(0x40001800 + 0x40 ))));

			((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT))); 
			HED_Memcpy(DataAddr,(unsigned char*)databuf,disToNextWord);
			DataAddr += disToNextWord;
			DataLen -= disToNextWord;
		}
	}

	div16Quotien = DataLen >> 4; 
	div16Mod = DataLen & 0xF;
	tmpDataAddr = (unsigned int *)DataAddr;
	if (div16Quotien)
	{
		
		(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = 0xF; 
		while (div16Quotien--)
		{
			tmpSpiData = (unsigned int *)&(*((volatile unsigned long *)(0x40001800 + 0x40 )));
			((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
			while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));
            
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT))); 
		}
		DataAddr = (unsigned char *)tmpDataAddr;
	}

	if (div16Mod)
	{
		(*((volatile unsigned long *)(0x40001800 + 0x04 ))) = div16Mod - 1; 
		tmpDataAddr = databuf;
		tmpSpiData = (unsigned int *)&(*((volatile unsigned long *)(0x40001800 + 0x40 )));
		((*((volatile unsigned long *)(0x40001800 + 0x18 ))) |= (1 << (SPISTR_TRE))); 
		while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));

		
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);    
		((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT))); 

		HED_Memcpy(DataAddr,(unsigned char*)databuf,div16Mod);
	}
}
 








  
void HED_SPIS_SendNBytes(unsigned char *DataAddr, unsigned int DataLen)
{
	unsigned int tmpSpiden,tmpDataNum;

	__packed unsigned int* tmpDataAddr;
	unsigned int* tmpSpiData;

    tmpSpiden = 0;
    tmpDataNum = 0;
	while (tmpDataNum < DataLen)
	{
		tmpDataAddr = (__packed unsigned int*)DataAddr;

		
		tmpSpiData = (unsigned int *)&(*((volatile unsigned long *)(0x40001800 + 0x40 )));
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
		
		((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT)));
		while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));

		
		tmpSpiden = (*((volatile unsigned long *)(0x40001800 + 0x04 )))+1; 
		tmpDataNum += tmpSpiden;
		DataAddr += tmpSpiden;
	}
}








  
unsigned char HED_SPIS_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
{

	unsigned int tmpSpiden = 0,tmpDataNum = 0;
	unsigned int databuf[4];
	unsigned int* tmpDataAddr,*tmpSpiData;

	while (tmpDataNum < DataLen)
	{
		tmpDataAddr = databuf;
		tmpSpiData = (unsigned int *)&(*((volatile unsigned long *)(0x40001800 + 0x40 )));
		while ((((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_DONE))) == 0));
		if (((*((volatile unsigned long *)(0x40001800 + 0x08 ))) & (1 << (SPIST_OVRF))))
		{
			((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_OVRF)));
			return (1);
		}	
		
		tmpSpiden = (*((volatile unsigned long *)(0x40001800 + 0x04 )))+1; 
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		HED_Memcpy(DataAddr,(unsigned char *)databuf,tmpSpiden);
		DataAddr += tmpSpiden;
		tmpDataNum += tmpSpiden;
        if(tmpDataNum < DataLen)
        {
            ((*((volatile unsigned long *)(0x40001800 + 0x08 ))) &= ~(1 << (SPIST_DONE))) ; ((*((volatile unsigned long *)(0x40001800 + 0x14 ))) &= ~(1 << (SPIIS_DONE_INT)));
        }		          
	}
	return (0);
}
