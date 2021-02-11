/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: CIU98M25_API_LIB_AES.h
 Author:    	
 Version:       	
 Date:      	
 Description:   
 History:
                
******************************************************/


#ifndef __CIU98M25_API_LIB_AES_H_
#define __CIU98M25_API_LIB_AES_H_

typedef struct 
{
	unsigned int *iDataPtr;
	unsigned int DataLen;
	unsigned int *iKeyPtr;
	unsigned int *IVPtr;
	unsigned int *oDataPtr;
	unsigned char Type;
}AES_Parameters;

unsigned int HED_AESBlock (AES_Parameters * AES_Param);

#endif   /* End of "__HED_ARM_LIB_H" */
