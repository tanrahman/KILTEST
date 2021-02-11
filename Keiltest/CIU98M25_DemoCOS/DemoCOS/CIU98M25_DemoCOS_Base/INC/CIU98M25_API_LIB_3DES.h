/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: CIU98M25_API_LIB_3DES.h
 Author:    	
 Version:       	
 Date:      	
 Description:   
 History:
                
******************************************************/


#ifndef __CIU98M25_API_LIB_3DES_H_
#define __CIU98M25_API_LIB_3DES_H_

typedef struct 
{
	unsigned int *iDataPtr;
	unsigned int DataLen;
	unsigned int *iKeyPtr;
	unsigned int *IVPtr;
	unsigned int *oDataPtr;
	unsigned char Type;
}DES3_Parameters;

unsigned int HED_DES3Block(DES3_Parameters * DES3_Param);

#endif   /* End of "__HED_ARM_LIB_H" */
