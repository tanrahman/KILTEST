/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: CIU98M25_API_Base_NoNVM.h
 Author:    
 Version:
 Date:  
 Description:   CIU98M25 User API Function header file
 History:
                V1.0	2014-11-26	initial version
******************************************************/


#ifndef __CIU98M25_API_BASE_NONVM_H_
#define __CIU98M25_API_BASE_NONVM_H_

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

/* API FUCTION DEFINE */
/* 7816 Interface */
unsigned int HED_T0_SendNBytes(unsigned char * DataAddr, unsigned int DataLen);
void HED_T0_ReceiveNBytesRam(unsigned char * DataAddr, unsigned int DataLen); 
/* CRC */
unsigned short HED_CRC16(unsigned short IV, unsigned int DataLen, unsigned char *DataBuf, unsigned char type);
/* Chip ID */
void HED_GetChipId(unsigned char *ChipId);
/* Factory Code */
void HED_GetFactoryCode(unsigned char * FactoryCode);
/* Change Frequency */
void HED_ChangeSYSFreq(SYS_FREQUENCY_DIVISOR SysDiv, APB_FREQUENCY_DIVISOR APBDiv); 
/* Set standby Mode */
void HED_SetToStandby(void);
/* SPI-Master */
void HED_SPIM_SendNBytes(unsigned char *DataAddr, unsigned int DataLen);
void HED_SPIM_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen);
/* SPI-Slave */
void HED_SPIS_SendNBytes(unsigned char *DataAddr, unsigned int DataLen);
unsigned char HED_SPIS_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen);

#endif   /* End of "__HED_ARM_LIB_H" */
