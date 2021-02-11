/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name:     spi.c
 Author:    	
 Version:		v1.0
 Date:      	2014-11-25
 Description:   
 History:
******************************************************/
#include "declare.h"

static unsigned char SpiCmdBuf[0x10];

#define SET_SPI_MSTR 		SET_REG_BIT(SPICON,SPICON_MSTR)

void SetSpiWorkMode(SPI_WORK_MODE mode)
{
	SPICON = (SPICON & 0xF) | SET_VAL_TO_BIT(mode,SPICON_MODSEL);
}
void SetPolarityAndPhase(BIT_VALUE polarity, BIT_VALUE phase)
{

	SPICON = (SPICON & (CLEAR_BIT(SPICON_CPOL) & CLEAR_BIT(SPICON_CPHA))) | \
			 SET_VAL_TO_BIT(polarity, SPICON_CPOL) | \
			 SET_VAL_TO_BIT(phase, SPICON_CPHA);
}
void HED_DEMO_SPI_Init(void)
{
	//configure gpio pins
	GPIODIR = SET_BIT(SPI_SS)  | \
			  SET_BIT(SPI_SCK) | \
			  SET_BIT(SPI_MOSI)| \
			  SET_BIT(SPI_MOSI_1);
	//disable gpio interrupt
	GPIOIE = 0x00;
	//disable spi interrupt
	SPIIE = 0x00;
	//set to master
	SET_SPI_MSTR;
	SetSpiWorkMode(SPI_STANDARD);
	SET_REG_BIT(SPIDIV,SPIDIV_MDIV_EN); //frequece division enable
	SetPolarityAndPhase(BIT_VAL_0, BIT_VAL_0);
	SET_SPI_MSB_FIRST; //MSB
}

//wait 
/************************************************* 
  Function:      WaitSFlashIdle
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void WaitSFlashIdle(void)
{
	do
	{
 		ENABLE_SPI_SS;	
		SpiCmdBuf[0] = SFLASH_CMD_RDSR; //read sflash status register
		HED_SPIM_SendNBytes(SpiCmdBuf,0x01);
		HED_SPIM_ReceiveNBytesRam(SpiCmdBuf,0x01);
	    DISABLE_SPI_SS;	
	}while(REG_BIT_IS_SET(SpiCmdBuf[0],SFLASH_STATUS_REGISTER_WIP));
}
/************************************************* 
  Function:      SPIM_ReadSFlashNbytes
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
unsigned char SPIM_ReadSFlashNbytes(unsigned char * DataBuf,unsigned int  FlashAddr , unsigned int  DataLen )
{

	unsigned char * flashAddr;
    
    flashAddr = (unsigned char *)(&FlashAddr);
    
	if ((FlashAddr+DataLen) >= 0x200000)
	{
		return (0x01);
	}

	WaitSFlashIdle();
	SpiCmdBuf[0] = SFLASH_CMD_READ; //
	SpiCmdBuf[1] = flashAddr[1]; //MSB
	SpiCmdBuf[2] = flashAddr[2];
	SpiCmdBuf[3] = flashAddr[3];
	ENABLE_SPI_SS;
	HED_SPIM_SendNBytes(SpiCmdBuf,0x04); //ins & address
	HED_SPIM_ReceiveNBytesRam(DataBuf,DataLen);
	DISABLE_SPI_SS;
	return 0;
}
/************************************************* 
  Function:      SPIM_WriteSFlashNbytes
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
unsigned char SPIM_WriteSFlashNbytes(unsigned char * DataBuf,unsigned int  FlashAddr , unsigned int  DataLen )
{

	unsigned char * flashAddr = (unsigned char *)(&FlashAddr);
    
	if ((FlashAddr+DataLen) >= 0x200000)
	{
		return (0x01);
	}

	WaitSFlashIdle();

	SpiCmdBuf[0] = SFLASH_CMD_WREN; //write enable
	ENABLE_SPI_SS;
	HED_SPIM_SendNBytes(SpiCmdBuf,0x01); //
	DISABLE_SPI_SS;

 	WaitSFlashIdle();
	SpiCmdBuf[0] = SFLASH_CMD_BLOCK_E_32; //erase 32K
	SpiCmdBuf[1] = flashAddr[1];
	SpiCmdBuf[2] = flashAddr[2];
	SpiCmdBuf[3] = flashAddr[3];
  	ENABLE_SPI_SS;
	HED_SPIM_SendNBytes(SpiCmdBuf,0x04); //ins & address
	DISABLE_SPI_SS;

	WaitSFlashIdle();
    SpiCmdBuf[0] = SFLASH_CMD_WREN; //write enable
	ENABLE_SPI_SS;
	HED_SPIM_SendNBytes(SpiCmdBuf,0x01); //
	DISABLE_SPI_SS;

 	WaitSFlashIdle();
	SpiCmdBuf[0] = SFLASH_CMD_PAGE_P; //page program 
	SpiCmdBuf[1] = flashAddr[1];
	SpiCmdBuf[2] = flashAddr[2];
	SpiCmdBuf[3] = flashAddr[3];
 	ENABLE_SPI_SS;
	HED_SPIM_SendNBytes(SpiCmdBuf,0x04); //ins & address
	HED_SPIM_SendNBytes(DataBuf,DataLen);//data
	DISABLE_SPI_SS;

	WaitSFlashIdle();
	ENABLE_SPI_SS;
	SpiCmdBuf[0] = SFLASH_CMD_WRDI; //write disable
	HED_SPIM_SendNBytes(SpiCmdBuf,0x01); //
	DISABLE_SPI_SS;
	return 0;
}
