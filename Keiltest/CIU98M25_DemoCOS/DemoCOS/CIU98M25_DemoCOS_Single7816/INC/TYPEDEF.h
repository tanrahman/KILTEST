/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	TYPEDEF.h
 Author:    	
 Version:			
 Date:  			
 Description: 
 History:	

******************************************************/
#ifndef __TYPEDEF_H_
#define __TYPEDEF_H_                                  

#ifndef false
#define false       (0)
#endif

#ifndef true
#define true        (1)
#endif

/* Type Definition */
#define INT8U   unsigned char
#define INT16U  unsigned short
#define INT32U  unsigned int

typedef     unsigned char   bool;

#define BIT0    (1ul<<0)
#define BIT1    (1ul<<1)
#define BIT2    (1ul<<2)
#define BIT3    (1ul<<3)
#define BIT4    (1ul<<4)
#define BIT5    (1ul<<5)
#define BIT6    (1ul<<6)
#define BIT7    (1ul<<7)
#define BIT8    (1ul<<8)
#define BIT9    (1ul<<9)
#define BIT10   (1ul<<10)
#define BIT11   (1ul<<11)
#define BIT12   (1ul<<12)
#define BIT13   (1ul<<13)
#define BIT14   (1ul<<14)
#define BIT15   (1ul<<15)
#define BIT16   (1ul<<16)
#define BIT17   (1ul<<17)
#define BIT18   (1ul<<18)
#define BIT19   (1ul<<19)
#define BIT20   (1ul<<20)
#define BIT21   (1ul<<21)
#define BIT24   (1ul<<24)
#define BIT26   (1ul<<26)
#define BIT30   (1ul<<30)
#define BIT31   (1ul<<31)  

#define 	DEMO_SET_BIT(x,y)  		(x |= (0x01 <<y))    //ÖÃÎ» 
#define 	DEMO_CLR_BIT(x,y)  		(x &= (~(0x01 <<y))) //ÇåÁã 
#define 	DEMO_CHECK_BIT(x,y) 	(x & (0x01 <<y))    //¼ì²â 

//define the function pointer structure for the APDU command
typedef struct 
{
    INT8U ins;
    void (*func)(void);
}COMMANDLIST;
#endif
