/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 Project name: 	SPI.h
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
******************************************************/
#ifndef _SPI_H_
#define _SPI_H_

//SPI
#define SET_VAL_TO_BIT(val,bit)     ((val) << (bit))
#define SET_SPI_LSB_FIRST           SET_REG_BIT(SPICON,SPICON_LSBFE)
#define SET_SPI_MSB_FIRST           CLEAR_REG_BIT(SPICON,SPICON_LSBFE)

#define SET_REG_BIT(reg,bit) 			    (reg |= (1 << (bit)))
#define CLEAR_REG_BIT(reg,bit) 			    (reg &= ~(1 << (bit)))
#define REG_BIT_IS_SET(reg,bit) 		    (reg & (1 << (bit)))
#define REG_BIT_IS_CLEAR(reg,bit) 		    ((reg & (1 << (bit))) == 0)
#define SET_BIT(bit) 					    (0x1 << (bit))
#define CLEAR_BIT(bit) 					    (~(0x1 << (bit)))

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
	
//GPIO
typedef enum
{
    SPI_MOSI_1 = 1,
    SPI_MISO = 2,
    SPI_MOSI = 3,
    SPI_SCK = 4,
    SPI_SS = 5,
} GPIO_BITS;
#define ENABLE_SPI_SS CLEAR_REG_BIT(GPIODATA,SPI_SS) 
#define DISABLE_SPI_SS SET_REG_BIT(GPIODATA,SPI_SS)
//model:S25FL064P
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
//sflash commands
//read
#define SFLASH_CMD_READ                 0x03
#define SFLASH_CMD_FAST_READ            0x0B
#define SFLASH_CMD_DOR                  0x3B 
#define SFLASH_CMD_QOR                  0x6B 
#define SFLASH_CMD_DIOR                 0xBB 
#define SFLASH_CMD_QIOR                 0xEB 
#define SFLASH_CMD_RDID                 0x9F
#define SFLASH_CMD_READ_DEVICEID        0x90
//write
#define SFLASH_CMD_WREN                 0x06 
#define SFLASH_CMD_WRDI                 0x04 
//erase
#define SFLASH_CMD_SECTOR_E             0x20
#define SFLASH_CMD_BLOCK_E_32           0x52
#define SFLASH_CMD_BLOCK_E_64           0xD8 
#define SFLASH_CMD_BLOCK_E_128          0xD2 
#define SFLASH_CMD_CHIP_E               0xC7 
//program
#define SFLASH_CMD_PAGE_P               0x02
//status&configuration register
#define SFLASH_CMD_RDSR                 0x05
#define SFLASH_CMD_WRR                  0x01
#define SFLASH_CMD_RDSR_1               0x35
//power saving
#define SFLASH_CMD_DP                   0xB9
#define SFLASH_CMD_RES                  0xAB

#define SFLASH_PAGE_SIZE                0x200

void WaitSFlashIdle(void);
unsigned char SPIM_ReadSFlashNbytes(unsigned char * DataBuf,unsigned int  FlashAddr , unsigned int  DataLen );
unsigned char SPIM_WriteSFlashNbytes(unsigned char * DataBuf,unsigned int  FlashAddr , unsigned int  DataLen );

void HED_DEMO_SPI_Init(void);

#endif
