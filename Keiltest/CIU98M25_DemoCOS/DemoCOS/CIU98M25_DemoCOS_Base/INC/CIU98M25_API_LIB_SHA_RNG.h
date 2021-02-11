/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: CIU98M25_API_LIB_SHA_RNG.h
 Author:    
 Version:
 Date:  
 Description:   CIU98M25 User API Function header file
 History:
                V1.0	2014-11-26	initial version
******************************************************/


#ifndef __CIU98M25_API_LIB_SHA_RNG_H_
#define __CIU98M25_API_LIB_SHA_RNG_H_

/* API FUCTION DEFINE */
/* Random */
void HED_GetRandom_Enhanced (unsigned char *RandomData,unsigned int DataLen);
void HED_GetRandom(unsigned char *RandomData,unsigned int DataLen);
/* RNGCHECK */
unsigned int HED_RNG1Check(void);
unsigned int HED_PokerCheck(void);
/* SHA160 */
void HED_SHA1_Init(unsigned int *v);
unsigned int HED_SHA1_Block (unsigned int * V, const unsigned int * DataValue, unsigned int DataLen);
/* SHA256 */
void HED_SHA256_Init(unsigned int *v);
unsigned int HED_SHA256_Block (unsigned int * V, const unsigned int * DataValue, unsigned int DataLen);

#endif   /* End of "__HED_ARM_LIB_H" */
