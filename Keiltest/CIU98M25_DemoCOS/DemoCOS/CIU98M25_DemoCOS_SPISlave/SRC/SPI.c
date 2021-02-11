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

#define SET_SPI_SLAVE 		CLEAR_REG_BIT(SPICON,SPICON_MSTR)
#define ENABLE_SPI_SS       CLEAR_REG_BIT(GPIODATA,SPI_SS) 
#define DISABLE_SPI_SS      SET_REG_BIT(GPIODATA,SPI_SS)

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
	SET_SPI_SLAVE;
	SetSpiWorkMode(SPI_STANDARD);
	SET_SPI_MSB_FIRST; //MSB
}

