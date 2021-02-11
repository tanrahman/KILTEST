/*******************************************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 File name:     CIU98M25_ALG_LIB.h
 Author:        Wangyun
 Version:       V1.0 
 Date:          2014-12-17
 Description:  
 History:       
                V1.0	2014-12-17	initial version
*******************************************************************************/
#ifndef __CIU98M25_ALG_LIB_H__
#define __CIU98M25_ALG_LIB_H__

typedef struct
{
	const unsigned int	*pE;
	unsigned int		*pN;
	unsigned int		*pP;
	unsigned int		*pQ;
	unsigned int		*pDp;
	unsigned int		*pDq;
	unsigned int		*pQInv;
	unsigned int		*pD;
	unsigned int		*pPreKey;
	unsigned int		*pDataIn;
	unsigned int		*pDataOut;
	unsigned int		operMode;
	unsigned int		len;
}   RSA_Info;
typedef struct
{
	const	unsigned int    *pE;
			unsigned int    *pN;
	const	unsigned int    *pP;
	const	unsigned int    *pQ;
	const	unsigned int    *pDp;
	const	unsigned int    *pDq;
	const	unsigned int    *pQInv;
	const	unsigned int    *pD;
			unsigned int    *pPreKey;  
	const	unsigned int    *pDataIn;
			unsigned int    *pDataOut;
	const	unsigned int    operMode;
	const	unsigned int    len;
}   RSA_Info_Const;

typedef struct 
{
	unsigned int *pR2n;
	unsigned int *pMcn;
	unsigned int *pR2p;
	unsigned int *pMcp;
	unsigned int *pR2q;
	unsigned int *pMcq;
} RSA_PreKey_Info;

typedef struct 
{
	unsigned int *iDataPtr;
	unsigned int DataLen;
	unsigned int *iKeyPtr;
	unsigned int *IVPtr;
	unsigned int *oDataPtr;
	unsigned char Type;
}SM1_Parameters, SM4_Parameters, SSF33_Parameters;

typedef struct                      
{                                   
    const unsigned char  *iDataPtr;  
    unsigned char        *oDataPtr;  
    const unsigned int   *rndPtr;    
    unsigned int         *priKeyPtr; 
    unsigned int         *pubKeyPtr; 
    unsigned int          iEccSel;   
} SM2_Parameters;  

typedef struct                          
{                                       
    const unsigned char *AID;           
    const unsigned char *BID;           
    const unsigned int  *PublicKey;     
    const unsigned int  *PrivateKey;    
    const unsigned int  *BPublicKey;    
    const unsigned int  *TempPrivateKey;
    const unsigned int  *TempPubKeyX;   
    const unsigned int  *BTempPubKey;   
    unsigned int         oLen;          
    unsigned int         DataType;      
    unsigned int         iEccSel;       
} SM2KeyExch_Parameters;                

unsigned int HED_RSA2048_GenKey(RSA_Info *keys);
unsigned int HED_RSA2048_Complete(RSA_Info *keys);
unsigned int HED_RSA2048_PubOpt(RSA_Info *keys);
unsigned int HED_RSA2048_PriOpt(RSA_Info *keys);
unsigned int HED_RSA2048_CalE (unsigned int *e, unsigned int *p, unsigned int *dp, unsigned int len);


unsigned int HED_SM2GenKey(SM2_Parameters *SM2_Param);                                                                     
unsigned int HED_SM2GetZ(const unsigned char *AID, const unsigned int *PublicKey, unsigned int *Za, unsigned int iEccSel); 
unsigned int HED_SM2Sign(SM2_Parameters *SM2_Param);                                                                       
unsigned int HED_SM2Verify(SM2_Parameters *SM2_Param);                                                                     
unsigned int HED_SM2Encrypt(SM2_Parameters *SM2_Param, unsigned int iLen);                                                 
unsigned int HED_SM2Decrypt(SM2_Parameters *SM2_Param, unsigned int iLen);                                                 
//need input random                                                                                                        
unsigned int HED_SM2GenKey2(SM2_Parameters *SM2_Param);                                                                    
unsigned int HED_SM2Sign2(SM2_Parameters *SM2_Param);                                                                      
unsigned int HED_SM2Encrypt2(SM2_Parameters *SM2_Param, unsigned int iLen);                                                
unsigned int HED_SM2KeyExchange(const SM2KeyExch_Parameters *SM2KeyExch_Para, unsigned char *oDataPtr);                    
void HED_SM3Initial(unsigned int *tmpV);                                                                                   
unsigned int HED_SM3Block(unsigned int *tmpV,const unsigned int *DataValue, unsigned int DataLen);                               


unsigned int HED_SM1Block (SM1_Parameters * SM1_Param);
unsigned int HED_SM4Block (SM4_Parameters * SM4_Param);
unsigned int HED_SSF33Block (SSF33_Parameters * SSF33_Param);

unsigned int HED_HEFlash_Init(void);
unsigned int HED_HEFlashEWPage(unsigned int FlashAddr, unsigned int * DataBuf);
unsigned int HED_HEFlashMapReset(void);
unsigned char HED_GetAPIVersion(void);

#endif
