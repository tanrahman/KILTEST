/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: CIU98M25_API_NVM_STABILITY.h
 Author:    	
 Version:       	
 Date:      	
 Description:   
 History:
                V1.0	2014-11-26	initial version                
******************************************************/
#ifndef __CIU98M25_API_NVM_STABILITY_H_
#define __CIU98M25_API_NVM_STABILITY_H_

unsigned int HED_FlashPageInit_St(unsigned int DestAddr);
unsigned int HED_FlashErWrPage_St(unsigned int DestAddr,unsigned int * SrcAddr);
void HED_FlashPageBufClr (void);

#endif   /* End of "__HED_ARM_LIB_H" */
