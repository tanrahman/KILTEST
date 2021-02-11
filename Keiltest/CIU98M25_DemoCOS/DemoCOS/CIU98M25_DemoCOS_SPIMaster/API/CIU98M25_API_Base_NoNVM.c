/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: CIU98M25_API_Base_NoNVM.c
 Author:    
 Version:	
 Date:      
 Description:   CIU98M25  User API Function
 History:	
                V1.0	2014-11-26	initial version
******************************************************/
#include "CIU98M25_SFR_C.H"
#include <stdlib.h>
#include <string.h>

#define FACTORY_CODE_SADDR 		0x1FFFFE00

#define SCI_IS_IDLE                      (((SCISSR & 0x08) == 0) && ((SCIRXFCR & 0x02) != 0))
/* MACRO DEFINE */
/* 7816 Interface */
#define SCI_START_SETU_COUNTER 				SET_REG_BIT(SCISSR,SCISSR_SETU)
#define SCI_START_SETU_COUNTER_IS_RUNNING 	REG_BIT_IS_SET(SCISSR,SCISSR_SETU)
#define SCI_IS_BUSY 					    (SCISSR & ((1 << SCISSR_RB)|(1 << SCISSR_TB)))
#define CLEAR_SCI_AUTO_RETRY_LIMIT 		    (SCISCON &= ~(3 << SCISCON_RCNT_0))
#define SET_SCI_AUTO_RETRY_LIMIT(num) 	    (SCISCON |= ((num - 2) & 0x3))
#define ENABLE_SCI 						    SET_REG_BIT(SCISCON,SCISCON_SE)
#define DISABLE_SCI 					    CLEAR_REG_BIT(SCISCON,SCISCON_SE) 
/*7816 send data*/
#define SCI_DATA_IS_SENDING 			    REG_BIT_IS_CLEAR(SCISSR,SCISSR_TI)
#define CLEAR_SCI_TI 					    CLEAR_REG_BIT(SCISSR,SCISSR_TI)
#define SCI_PARITY_IS_ERROR 			    REG_BIT_IS_SET(SCISSR,SCISSR_PE)
#define CLEAR_SCI_PARITY_ERROR 			    CLEAR_REG_BIT(SCISSR,SCISSR_PE)
#define FLUSH_SCI_TX_FIFO 				    SET_REG_BIT(SCITXFCR,SCITXFCR_FLUSH_TX_FIFO) 
#define FLUSH_SCI_TX_FIFO_IS_RUNNING 	    REG_BIT_IS_SET(SCITXFCR, SCITXFCR_FLUSH_TX_FIFO)
/*7816 receive data*/
#define CLEAR_SCI_RI 					    CLEAR_REG_BIT(SCISSR,SCISSR_RI)
#define SCIRXFCR_RX_IS_EMPTY  			    REG_BIT_IS_SET(SCIRXFCR,SCIRXFCR_RX_EMPTY)

/* Random */
#define ENABLE_RNG1_CLK 		            SET_REG_BIT(SYSCLKEN,SYSCLKEN_RNG1EN)
#define DISABLE_RNG1_CLK 		            SET_REG_BIT(SYSCLKCLR,SYSCLKEN_RNG1EN)
#define RANDOM_NUM_IS_OK 		            REG_BIT_IS_SET(RNG1STR,RNG1STR_RNGRDY)
#define RANDOM_NUM_IS_NOT_OK 	            REG_BIT_IS_CLEAR(RNG1STR,RNG1STR_RNGRDY) 
#define RANDOM_NUM_IS_TIMEOUT 	            REG_BIT_IS_SET(RNG1STR,RNG1STR_TIMEOUT)

#define SET_REG_BIT(reg,bit) 			    (reg |= (1 << (bit)))
#define CLEAR_REG_BIT(reg,bit) 			    (reg &= ~(1 << (bit)))
#define REG_BIT_IS_SET(reg,bit) 		    (reg & (1 << (bit)))
#define REG_BIT_IS_CLEAR(reg,bit) 		    ((reg & (1 << (bit))) == 0)
#define SET_BIT(bit) 					    (0x1 << (bit))
#define CLEAR_BIT(bit) 					    (~(0x1 << (bit)))

//system register bits
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

//SCI SFR
//SCISCON bits
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

//SCISSR bits
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


//timer
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

//CRC
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

/* Change Frequency */
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

/* 7816 Interface */
/************************************************* 
  Function:      HED_T0_SendNBytes (unsigned char * DataAddr , unsigned int DataLen)
  Description:    
		send N bytes by 7816 interface(T = 0 protocol)			
  Calls: none    
  Input: 
		DataAddr:address of the data to be sent
		DataLen:lengtn of the data to be sent
  Output:нч
  Return:
		0x00:data sent successfully
		0x01:data sent fail
		0x02:API's para illegal  
  Others:none
*************************************************/ 
unsigned int HED_T0_SendNBytes (unsigned char * DataAddr , unsigned int DataLen)
{
	if(DataLen == 0) 
	{
		return (2);
	}

	//wait for idle time
	while(SCI_IS_BUSY); 

	//set auto retry time = 3
	CLEAR_SCI_AUTO_RETRY_LIMIT; 
	SET_SCI_AUTO_RETRY_LIMIT(3);

	while(DataLen--)
	{
		//write one byte to buffer a time
		SCISBUF = (*DataAddr++);
		while(SCI_DATA_IS_SENDING);

		if(SCI_PARITY_IS_ERROR == 0 )
		{
			SCISSR = 0;							//clr SCI status
		}
		else
		{
			SCITXFCR = 0x01;					//clr trans FIFO control
			while ((SCITXFCR & 0x01) == 0x01);
			SCISSR = 0;							//clr SCI status
			return (1);    	
		}
	}
	return (0);
}
/************************************************* 
  Function:     HED_T0_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
  Description:    
		receive N bytes to RAM by 7816 interface(T = 0 protocol)			
  Calls: none              
  Input: 
		DataAddr:address to store the data received
		DataLen:bytes number of the data received
  Output:data received
  Return:none
  Others:none
*************************************************/ 
void HED_T0_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
{
	while(SCI_IS_BUSY);

	while(DataLen--)
	{	 	      
		//wait for data
		while(SCIRXFCR_RX_IS_EMPTY);
		(*DataAddr++) = (unsigned char)SCISBUF; 
	}
}

/* CRC */
#define CHANGE_CRC_WIDTH_FROM_32_TO_8  (CRCCSR |= (1<<5))
/************************************************* 
  Function:     unsigned short HED_CRC16(unsigned short IV, unsigned int DataLen, unsigned char *DataBuf, unsigned char type)
  Description:    
		Calculate the CRC-16 of a block of bytes in RAM/EE			
  Calls:              
  Input: 
		DataLen:bytes number of the block of
		IV: initial value
		DataBuf: the address of the block of data to be calculate 
		type: input and output data order type
  Output:none
  Return:2 bytes CRC result (big endian)
  Others:none 
*************************************************/ 
unsigned short HED_CRC16(unsigned short IV, unsigned int DataLen, unsigned char *DataBuf, unsigned char type)
{
	unsigned int tmp_cnt = (unsigned int)DataBuf & 0x3; //distance to previous word border
	unsigned int div4_quotient, div4_mod;   //

	if(DataLen == 0)
	{
		return IV;
	}
	
	CRCIV = IV;
	CRCCSR = ((type&0x3)<<1) | SET_BIT(CRCCSR_CRC_ST);

	if (DataLen <= 0x07)
	{
		div4_quotient = 0;
		div4_mod = DataLen;   
	}
	else
	{
		unsigned int curr_crccsr = CRCCSR;
		if (tmp_cnt)
		{
			tmp_cnt = 0x4 - tmp_cnt;
			DataLen -= tmp_cnt;
			CHANGE_CRC_WIDTH_FROM_32_TO_8;   //CRCCSR[5:4] = 10 ->8
			while (tmp_cnt--)
			{
				CRCDATA = *DataBuf++;
			}
		}
		div4_quotient = DataLen >> 0x02; 
		div4_mod = DataLen & 0x3;   //word numbers
		CRCCSR = curr_crccsr;

		if (div4_quotient)
		{
			unsigned int * tmp_databuf = (unsigned int *)DataBuf;
			while (div4_quotient--)
			{
				CRCDATA = *(unsigned int *)tmp_databuf++;//4 bytes one time
			}
			DataBuf = (unsigned char *)tmp_databuf;
		}
	}

	if (div4_mod)	
	{
		CHANGE_CRC_WIDTH_FROM_32_TO_8;   //CRCCSR[5:4] = 10 ->8
		while (div4_mod--)
		{
			CRCDATA = *DataBuf++;
		}

	}

	return (unsigned short)CRCDATA;
}


/* Serial Num */
void HED_GetChipInfo(unsigned char *DataBuf, unsigned int FlashAddr, unsigned int DataLen)
{
	while(DataLen--)
	{
		*DataBuf++ = *(unsigned char *)FlashAddr;
		FlashAddr += 0x00000001;
	}
} 
/* Chip ID */
/************************************************* 
  Function:     void HED_GetChipId(unsigned char *ChipId)
  Description:  to get chip ID		
  Calls:              
  Input: ChipId:address to store the chip ID
  Output:none
  Return:
  Others:none
*************************************************/ 
void HED_GetChipId(unsigned char *ChipId)
{
    unsigned char die_YX_position;
    unsigned char test_month;
    
    HED_GetChipInfo(ChipId,  FACTORY_CODE_SADDR+0x09, 1);	//Test year
    
    /*get 2nd sequence number*/
    HED_GetChipInfo(&die_YX_position,  FACTORY_CODE_SADDR+0x17, 1);	//get die X/Y position on wafer
    HED_GetChipInfo(&test_month,  FACTORY_CODE_SADDR+0x0A, 1);	//get test_month
    die_YX_position = ((die_YX_position & 0x10) << 3) | ((die_YX_position & 0x01) << 6);    
    test_month = (test_month >> 4)*10 + (test_month & 0x0F);
    test_month &= 0x3F;
    ChipId[1] = die_YX_position | test_month;
    /*get 2nd sequence number*/
    
    HED_GetChipInfo(ChipId+2,  FACTORY_CODE_SADDR+0x1C, 1);	//lot number (highest byte)
    HED_GetChipInfo(ChipId+3,  FACTORY_CODE_SADDR+0x1D, 1);	//lot number (second byte)
    HED_GetChipInfo(ChipId+4,  FACTORY_CODE_SADDR+0x1E, 1);	//lot number (third byte)
    HED_GetChipInfo(ChipId+5,  FACTORY_CODE_SADDR+0x1F, 1);	//lot number (fourth byte)
    HED_GetChipInfo(ChipId+6,  FACTORY_CODE_SADDR+0x0B, 1);	//lot number (fifth byte)
    HED_GetChipInfo(ChipId+7,  FACTORY_CODE_SADDR+0x0C, 1);	//lot number (lowest byte)
    HED_GetChipInfo(ChipId+8,  FACTORY_CODE_SADDR+0x1A, 1);	//lot subsidiary number (high byte)
    HED_GetChipInfo(ChipId+9,  FACTORY_CODE_SADDR+0x1B, 1);	//lot subsidiary number (low byte)
    HED_GetChipInfo(ChipId+10,  FACTORY_CODE_SADDR+0x0D, 1); //wafer number
    HED_GetChipInfo(ChipId+11,  FACTORY_CODE_SADDR+0x0E, 1); //die X position on wafer
    HED_GetChipInfo(ChipId+12,  FACTORY_CODE_SADDR+0x0F, 1); //die Y position on wafer
}

/* Factory Code */
/************************************************* 
  Function:     HED_GetFactoryCode(unsigned char *FactoryCode)
  Description: to get 32 bytes long FactoryCode	
  Calls:               
  Input: address to store the FactoryCode
  Output:none
  Return:
  Others: 
*************************************************/ 
void HED_GetFactoryCode(unsigned char *FactoryCode)
{
	HED_GetChipInfo(FactoryCode, FACTORY_CODE_SADDR, 32);
}

/*delay function
PreFunction Instruction:

MOVS    r0,0xxx;    //1 cycle
BL      delay;      //4 cycle

InFunction Instruction:
loopStart
SUBS     r0,r0,#1;  //1 cycle
BCS      loopStart; //1 or 3 cycle
BX		    lr;     //3 cycle

LoopNum == 0:   delay == 10 cycle
LoopNum == 1:   delay == 14 cycle
LoopNum == 2:   delay == 18 cycle
.........
LoopNum == n:   delay == (10 + 4*n) cycle
*/
__asm void delay(unsigned int LoopNum)
{
loopStart
    SUBS     r0,r0,#1
    BCS      loopStart
	BX		    lr
}

/************************************************* 
  Function:     void HED_ChangeSYSFreq(SYS_FREQUENCY_DIVISOR SysDiv, APB_FREQUENCY_DIVISOR APBDiv) 
  Description:  config the system clock	and APB div	
  Calls:               
  Input: 
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
  Output:none
  Return:none
  Others:none
*************************************************/ 
const unsigned char SYS_PKE_ClkTable[7] = {0,1,1,7,7,7,7};

void HED_ChangeSYSFreq(SYS_FREQUENCY_DIVISOR SysDiv, APB_FREQUENCY_DIVISOR APBDiv) 
{	
	unsigned int currDiv,SysDivGap;
	unsigned int tmpSysClk;    
    
	if (APBDiv == APB_HALF_AHB)
	{
		SET_REG_BIT(SYSCLKCFG,SYSCLKCFG_APBDIV);
	}
	else
	{
		CLEAR_REG_BIT(SYSCLKCFG, SYSCLKCFG_APBDIV);
	}
    
	tmpSysClk = SYSCLKCFG;
    currDiv = (SYSCLKCFG & (0x07 << SYSCLKCFG_SYSDIV)) >> SYSCLKCFG_SYSDIV;//sysclk is SYSCLKCFG[6:4]

	if (currDiv == SysDiv)//no switch
	{
        tmpSysClk &= ~(0x07 << SYSCLKCFG_PKEDIV);
        tmpSysClk |= (SYS_PKE_ClkTable[SysDiv] << SYSCLKCFG_PKEDIV);
        SYSCLKCFG = tmpSysClk;//renew PKE Div        
        return;
	}
	else if(currDiv > SysDiv)//up switch
	{
        SysDivGap = currDiv - SysDiv;
	}	
    else//down switch
    {
        SysDivGap = SysDiv - currDiv;
    }
    
    if((SysDivGap == 2) || (SysDivGap == 6))//SysDIV switch to 18M first,then target Div
    {
        tmpSysClk &= ~(0x07 << SYSCLKCFG_SYSDIV);
        tmpSysClk |= (1 << SYSCLKCFG_SYSDIV); //prepare switch to 18Mhz 
        SYSCLKCFG = tmpSysClk; 
        delay(43);//delay 10us when 18Mhz
        tmpSysClk &= ~(0x07 << SYSCLKCFG_SYSDIV);
        tmpSysClk |= (SysDiv <<SYSCLKCFG_SYSDIV);//prepare switch to target Div
        SYSCLKCFG = tmpSysClk;
    }
    else//SysDIV switch to target Div directly
    {
        tmpSysClk &= ~(0x07 << SYSCLKCFG_SYSDIV);
        tmpSysClk |= (SysDiv <<SYSCLKCFG_SYSDIV);//prepare switch to target SYSDIV  
        SYSCLKCFG = tmpSysClk;            
    }    
    
    tmpSysClk &= ~(0x07 << SYSCLKCFG_PKEDIV);
    tmpSysClk |= (SYS_PKE_ClkTable[SysDiv] << SYSCLKCFG_PKEDIV);
    SYSCLKCFG = tmpSysClk;//set PKE Div
}

/* Set standby Mode */
extern unsigned char G_bSWP_busy;
/************************************************* 
  Function:     HED_SetToStandby(void)
  Description:  set chip to standby mode		
  Calls:              
  Input: none
  Output:none
  Return:
  Others: both SYSCLKCFG and SYSCLKEN remain the same before and after the execution of this API
*************************************************/ 
void HED_SetToStandby(void)
{
	unsigned int bak_SYSCLKEN,bak_SYSCLKCFG;
    unsigned int bak_SYSDiv,bak_APBDiv;
    
    bak_SYSCLKEN = SYSCLKEN;
    bak_SYSCLKCFG = SYSCLKCFG;
    bak_SYSDiv = (bak_SYSCLKCFG & (0x07 << SYSCLKCFG_SYSDIV)) >> SYSCLKCFG_SYSDIV;//sysclk is SYSCLKCFG[6:4]
    bak_APBDiv = (bak_SYSCLKCFG & (0x01 << SYSCLKCFG_APBDIV)) >> SYSCLKCFG_APBDIV;//sysclk is SYSCLKCFG[bit12]

	SYSCLKCLR = (1<<4) | (1<<11); //disable PKE/SM4 IP's clock
    
    HED_ChangeSYSFreq(SYSCLK_AHB_6Mhz,APB_HALF_AHB);
    
	if(SCI_IS_IDLE)
    {
         __wfe(); //set standby
    }
    
    if((bak_SYSDiv == 0) || (bak_SYSDiv == 1) || (bak_SYSDiv == 2) || (bak_SYSDiv == 6))
    {
        HED_ChangeSYSFreq((SYS_FREQUENCY_DIVISOR)bak_SYSDiv,(APB_FREQUENCY_DIVISOR)bak_APBDiv);//restore SYSCLKCFG
    }
    
	SYSCLKEN = bak_SYSCLKEN;//enable IP's CLK							
}

/*SPI*/
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

/* SPI-Master */
#define SET_SPI_MSTR 				SET_REG_BIT(SPICON,SPICON_MSTR)
#define DISABLE_SPI_MSTR_DONE_INT 	CLEAR_REG_BIT(SPIIE,SPIIE_DONEI_EN)
#define START_SPI_MSTR_TRANS 		SET_REG_BIT(SPISTR,SPISTR_TRE)
#define SPI_IS_BUSY 				REG_BIT_IS_CLEAR(SPIST,SPIST_DONE)
#define CLEAR_SPI_DONE CLEAR_REG_BIT(SPIST,SPIST_DONE) ;\
	CLEAR_REG_BIT(SPIIS,SPIIS_DONE_INT)
/* SPI-Slave */
#define SET_SPI_SLAVE 					CLEAR_REG_BIT(SPICON,SPICON_MSTR)
#define SPI_SLAVE_RECEIVER_IS_OVERFLOW 	REG_BIT_IS_SET(SPIST,SPIST_OVRF)
#define CLEAR_SPI_RECEIVER_OVERFLOW 	CLEAR_REG_BIT(SPIST,SPIST_OVRF)

/************************************************* 
  Function:     HED_Memcpy
  Description:  sub function		
  Calls:              
  Input: 
  Output:
  Return:
  Others: 
*************************************************/ 
void HED_Memcpy(unsigned char* to,unsigned char* from,unsigned int count)
{
	while(count-- != 0)
	{
		*to++ = *from++;
	}
}
/************************************************* 
  Function:     HED_WordEndianAlter
  Description: 		
  Calls:              
  Input: 
  Output:
  Return:
  Others: 
*************************************************/ 
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
/* SPI-Master */
/************************************************* 
  Function:     HED_SPIM_SendNBytes(unsigned char *DataAddr, unsigned int DataLen)
  Description:  		
  Calls:              
  Input: none
  Output:none
  Return:
  Others: 
*************************************************/ 
void HED_SPIM_SendNBytes(unsigned char *DataAddr, unsigned int DataLen)
{
	unsigned int div16Quotien, div16Mod;
	unsigned int * tmpDataAddr,* tmpSpiData;
	unsigned int disToPreviousWord,disToNextWord; //distance to previous/next word border
	
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
			SPIDLEN = DataLen - 1; 
			SPIDATA = (unsigned int)((DataAddr[3] << 24) | (DataAddr[2] << 16) | (DataAddr[1] << 8) | DataAddr[0]);
			START_SPI_MSTR_TRANS; //transfer start
			while (SPI_IS_BUSY);
			CLEAR_SPI_DONE; 
			return;
		}
		else //front n bytes
		{
			SPIDLEN = disToNextWord - 0x01;
            SPIDATA = (unsigned int)((DataAddr[3] << 24) | (DataAddr[2] << 16) | (DataAddr[1] << 8) | DataAddr[0]);
			START_SPI_MSTR_TRANS; //transfer start
			while (SPI_IS_BUSY);
			CLEAR_SPI_DONE;
			DataLen -= disToNextWord;
			DataAddr += disToNextWord;
		}
	}
	div16Quotien = DataLen >> 4; 
	div16Mod = DataLen & 0xF;
	tmpDataAddr = (unsigned int *)DataAddr;
	if (div16Quotien)
	{
		//16 bytes a time
		SPIDLEN = 0xF; 
		while (div16Quotien--)
		{
			tmpSpiData = (unsigned int *)&SPIDATA;
            
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
            *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);

			START_SPI_MSTR_TRANS; //transfer start
			while (SPI_IS_BUSY);
			CLEAR_SPI_DONE; 
		}
	}

	if (div16Mod)
	{
		SPIDLEN = div16Mod - 1; //left bytes
		tmpSpiData = (unsigned int *)&SPIDATA;
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
		START_SPI_MSTR_TRANS; //transfer start 
		while (SPI_IS_BUSY);
		CLEAR_SPI_DONE;
	}
}
/************************************************* 
  Function:     HED_SPIM_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
  Description:  		
  Calls:              
  Input: none
  Output:none
  Return:
  Others: 
*************************************************/ 
void HED_SPIM_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
{
	unsigned int div16Quotien, div16Mod;
	unsigned int* tmpDataAddr,*tmpSpiData;
	unsigned int disToPreviousWord,disToNextWord; //distance to previous/next word border
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
		tmpSpiData = (unsigned int *)&SPIDATA;
		if (DataLen <= 0x10)
		{
			SPIDLEN = DataLen - 1;
			START_SPI_MSTR_TRANS; 
			while (SPI_IS_BUSY);

			//read 16 bytes
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);

			CLEAR_SPI_DONE; 
			HED_Memcpy(DataAddr,(unsigned char*)databuf,DataLen);
			return;
		}
		else
		{
			SPIDLEN = disToNextWord - 0x01;
			START_SPI_MSTR_TRANS; 
			while (SPI_IS_BUSY);
			//read 
            *tmpDataAddr++ = HED_WordEndianAlter(SPIDATA);

			CLEAR_SPI_DONE; 
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
		//SPIDLEN
		SPIDLEN = 0xF; //16 bytes a time
		while (div16Quotien--)
		{
			tmpSpiData = (unsigned int *)&SPIDATA;
			START_SPI_MSTR_TRANS; 
			while (SPI_IS_BUSY);
            
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
            *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
			CLEAR_SPI_DONE; 
		}
		DataAddr = (unsigned char *)tmpDataAddr;
	}

	if (div16Mod)
	{
		SPIDLEN = div16Mod - 1; //left bytes
		tmpDataAddr = databuf;
		tmpSpiData = (unsigned int *)&SPIDATA;
		START_SPI_MSTR_TRANS; 
		while (SPI_IS_BUSY);

		//read 16 bytes
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		*tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);    
		CLEAR_SPI_DONE; 

		HED_Memcpy(DataAddr,(unsigned char*)databuf,div16Mod);
	}
}
/* SPI-Slave */
/************************************************* 
  Function:     HED_SPIS_SendNBytes(unsigned char *DataAddr, unsigned int DataLen)
  Description:  		
  Calls:              
  Input: none
  Output:none
  Return:
  Others: 
*************************************************/ 
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

		//write 16 bytes to buffer every time
		tmpSpiData = (unsigned int *)&SPIDATA;
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
        *tmpSpiData++ = HED_WordEndianAlter(*tmpDataAddr++);
		
		CLEAR_SPI_DONE;
		while (SPI_IS_BUSY);//wait transfer over

		//read spidlen
		tmpSpiden = SPIDLEN+1; //how many bytes transfer success
		tmpDataNum += tmpSpiden;
		DataAddr += tmpSpiden;
	}
}
/************************************************* 
  Function:     HED_SPIS_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
  Description:  		
  Calls:              
  Input: none
  Output:none
  Return:
  Others: 
*************************************************/ 
unsigned char HED_SPIS_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen)
{

	unsigned int tmpSpiden = 0,tmpDataNum = 0;
	unsigned int databuf[4];
	unsigned int* tmpDataAddr,*tmpSpiData;

	while (tmpDataNum < DataLen)
	{
		tmpDataAddr = databuf;
		tmpSpiData = (unsigned int *)&SPIDATA;
		while (SPI_IS_BUSY);
		if (SPI_SLAVE_RECEIVER_IS_OVERFLOW)
		{
			CLEAR_SPI_RECEIVER_OVERFLOW;
			return (1);
		}	
		//read spidlen
		tmpSpiden = SPIDLEN+1; //received bytes 
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
        *tmpDataAddr++ = HED_WordEndianAlter(*tmpSpiData++);
		HED_Memcpy(DataAddr,(unsigned char *)databuf,tmpSpiden);
		DataAddr += tmpSpiden;
		tmpDataNum += tmpSpiden;
        if(tmpDataNum < DataLen)
        {
            CLEAR_SPI_DONE;
        }		          
	}
	return (0);
}
