#line 1 "SRC\\Interrupt.c"









 
#line 1 "SRC\\../inc/Declare.h"









 



#line 1 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"


  
  typedef unsigned int size_t;








extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 185 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 201 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 224 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 239 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 262 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 494 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\string.h"



 

#line 15 "SRC\\../inc/Declare.h"
#line 1 "C:\\Keil_v4\\ARM\\ARMCC\\bin\\..\\include\\absacc.h"
 
 
 










#line 16 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_SFR_C.h"









 






 


 






 

#line 35 "SRC\\../inc/CIU98M25_SFR_C.h"


#line 46 "SRC\\../inc/CIU98M25_SFR_C.h"


#line 55 "SRC\\../inc/CIU98M25_SFR_C.h"







#line 69 "SRC\\../inc/CIU98M25_SFR_C.h"






#line 89 "SRC\\../inc/CIU98M25_SFR_C.h"



 







 
#line 109 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 121 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 133 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 158 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 171 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 201 "SRC\\../inc/CIU98M25_SFR_C.h"



 

#line 233 "SRC\\../inc/CIU98M25_SFR_C.h"



 
#line 252 "SRC\\../inc/CIU98M25_SFR_C.h"

#line 17 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/SubFunc.h"









 






void PpsExchange(void);
void FLASH_CLEAR_HVPT(void);
void RF_Config(void);
void Set_Init_SYSCLK(void);
void GlobalPARA_Init(void);

#line 30 "SRC\\../inc/SubFunc.h"



#line 18 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/APDU_7816.h"









 



void SCIAPDU_Dispatch(void);

#line 19 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/APDU_SWP_CARD.h"









 



void SWPAPDU_Dispatch(void);
void SWPAPDU_Dispatch_APDU_GATE(void);

#line 20 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/SCI.h"










 





void SCI_Send_ATR(void);
void SCI_DelayNETU(unsigned int nETU);
void SCI_RxStart(void);
void SCI_StartTx_INT(unsigned short index);
void SCI_StoreNBytes(void);
void SCI_WaitRx(unsigned char index);
void GVar_SCI_Init(void);
void HED_T0_SendByte(unsigned char byte);
void SCI_Init(void);
void SendINS(unsigned char ins);
void SCI_StopTx60(void);

extern volatile unsigned short G_SCIRecieveIndex;
extern volatile unsigned char G_SCIRecieveDone;
extern volatile unsigned short G_SCISendIndex;
extern unsigned char G_bSCILeSendDone;
extern unsigned int SCILeLength;

extern const unsigned char G_ATR[];
extern unsigned char SCIAPDUBuf[];

#line 21 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/TYPEDEF.h"










 











 




typedef     unsigned char   bool;

#line 56 "SRC\\../inc/TYPEDEF.h"






typedef struct 
{
    unsigned char ins;
    void (*func)(void);
}COMMANDLIST;
#line 22 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/Interrupt.h"









 



void SCIRST_HANDLER(void);
void SCIRx_HANDLER(void);
void SCITx_HANDLER(void);

extern unsigned short SW1SW2;
extern volatile unsigned char G_bATR_Done;
extern volatile unsigned char G_SCIRecieving;

#line 23 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/HCI_lib_API.h"











 



void HCI_GVar_Init(void);
void SWP_Init(void);
unsigned int HCI_Init(unsigned char appMode, unsigned short RFType);
unsigned int HCI_RxManage(void);
void HCI_CardMode_Send(void);
void HCI_ReaderMode_Send(void);
void HCI_APDU_Gate_Send(void);
unsigned int HCI_Connectivity_Send (unsigned int type, unsigned char *para, unsigned int paraLen);
unsigned int HCI_End_Of_Operation (void);
unsigned int HCI_Mode_Switch (unsigned int mode);
unsigned int HCI_APDU_Gate_Send_WTX(void);
void SWPIO_Detect_Handler (void);
void SWP_Tansfers_Handler(void);
void HCI_RSTSyncID (void);
unsigned char HCI_SetPara_Send(void);
unsigned char HCI_GetPara_Send(void);
unsigned int SWP_APIVersion (void);

unsigned int HED_M1_InitBlock(unsigned int * piBlock0Data);
unsigned int HED_M1_ResetSector (unsigned int sectorID);
unsigned int HED_M1_PwReadBlock (unsigned int *piPwData, unsigned char cMifareBlock);
unsigned int HED_M1_PwWriteBlock (unsigned int *piPwData, unsigned char cMifareBlock);

extern volatile unsigned char	G_bPowerMode;
extern volatile unsigned char	G_bSHDLC_Status;

#line 24 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/HCI_lib_GVar.h"












 









extern unsigned char G_SYNC_PARA;
extern unsigned char G_CmptblCtrl;
extern unsigned short G_triggerResult;
extern unsigned int G_AppOpenSta;
extern unsigned char G_bSWP_DetectStatus;
extern unsigned char G_bCardActivated;
extern unsigned char G_APDUBuf[];
extern unsigned short G_APDULen;
extern unsigned char G_HCIMode;
extern unsigned char G_bSWP_busy;
extern unsigned char G_bCLKSwitchValid;

extern unsigned char G_appMode;
extern unsigned short G_RFType;
extern unsigned char G_ReaderTimerOutInteger;
extern unsigned char G_bFstAPDU;
extern unsigned char G_SetParaBuf[];
extern unsigned char G_GetParaBuf[];
extern unsigned char G_bRFIndicator;
extern unsigned char G_bAPPSendType;
extern unsigned char G_GetRFType;
extern unsigned char G_APDUGateBuf[];
extern unsigned short G_APDUGateLen;


extern unsigned char pReg_ID_Gate_VerSW[];
extern unsigned char pReg_ID_Gate_VerHard[];
extern unsigned char pReg_ID_Gate_Vendor_Name[];
extern unsigned char pReg_ID_Gate_Model_ID[];

extern unsigned char aReg_CardRFTypeA_UID[]; 
extern unsigned char aReg_CardRFTypeA_SAK[]; 
extern unsigned char aReg_CardRFTypeA_ATQA[]; 
extern unsigned char aReg_CardRFTypeA_History[];
extern unsigned char aReg_CardRFTypeA_TB1[];
extern unsigned char aReg_CardRFTypeA_MAXDataRate[];
extern unsigned char aReg_CardRFTypeA_CID_SUPPORT[];

extern unsigned char aReg_ReaderRFTypeA_MAXDataRate [];

extern unsigned char aReg_CardRFTypeB_AFI[]; 
extern unsigned char aReg_CardRFTypeB_ATQB[]; 
extern unsigned char aReg_CardRFTypeB_MAXDataRate[];



extern unsigned char aReg_ReaderRFTypeA_UID[];
extern unsigned char aReg_ReaderRFTypeA_SAK[];
extern unsigned char aReg_ReaderRFTypeA_ATQA[];  
extern unsigned char aReg_ReaderRFTypeA_History[];
extern unsigned char aReg_ReaderRFTypeA_TB1[];

extern unsigned int HCIConfig_ADRESS;

 
extern unsigned char G_cM1_Mode;
extern unsigned char G_cM1_PwAlgType;

#line 25 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_LIB_STABILITY.h"










 



void openWrSwitch(void);
void closeWrSwitch(void);
void chkWrSwitch(void);    
void setWrMode(unsigned int nvmMode);

#line 26 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_LIB_SHA_RNG.h"










 





 
 
void HED_GetRandom_Enhanced (unsigned char *RandomData,unsigned int DataLen);
void HED_GetRandom(unsigned char *RandomData,unsigned int DataLen);
 
unsigned int HED_RNG1Check(void);
unsigned int HED_PokerCheck(void);
 
void HED_SHA1_Init(unsigned int *v);
unsigned int HED_SHA1_Block (unsigned int * V, const unsigned int * DataValue, unsigned int DataLen);
 
void HED_SHA256_Init(unsigned int *v);
unsigned int HED_SHA256_Block (unsigned int * V, const unsigned int * DataValue, unsigned int DataLen);

#line 27 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_Base_NoNVM.h"










 





 
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

 
 
unsigned int HED_T0_SendNBytes(unsigned char * DataAddr, unsigned int DataLen);
void HED_T0_ReceiveNBytesRam(unsigned char * DataAddr, unsigned int DataLen); 
 
unsigned short HED_CRC16(unsigned short IV, unsigned int DataLen, unsigned char *DataBuf, unsigned char type);
 
void HED_GetChipId(unsigned char *ChipId);
 
void HED_GetFactoryCode(unsigned char * FactoryCode);
 
void HED_ChangeSYSFreq(SYS_FREQUENCY_DIVISOR SysDiv, APB_FREQUENCY_DIVISOR APBDiv); 
 
void HED_SetToStandby(void);
 
void HED_SPIM_SendNBytes(unsigned char *DataAddr, unsigned int DataLen);
void HED_SPIM_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen);
 
void HED_SPIS_SendNBytes(unsigned char *DataAddr, unsigned int DataLen);
unsigned char HED_SPIS_ReceiveNBytesRam(unsigned char *DataAddr, unsigned int DataLen);

#line 28 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_NVM_STABILITY.h"










 



unsigned int HED_FlashPageInit_St(unsigned int DestAddr);
unsigned int HED_FlashErWrPage_St(unsigned int DestAddr,unsigned int * SrcAddr);
void HED_FlashPageBufClr (void);

#line 29 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_ALG_LIB.h"









 



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

#line 30 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_LIB_3DES.h"










 





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

#line 31 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_LIB_DES.h"










 





typedef struct 
{
	unsigned int *iDataPtr;
	unsigned int DataLen;
	unsigned int *iKeyPtr;
	unsigned int *IVPtr;
	unsigned int *oDataPtr;
	unsigned char Type;
}DES_Parameters;

unsigned int HED_DESBlock(DES_Parameters * DES3_Param);

#line 32 "SRC\\../inc/Declare.h"
#line 1 "SRC\\../inc/CIU98M25_API_LIB_AES.h"










 





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

#line 33 "SRC\\../inc/Declare.h"

#line 12 "SRC\\Interrupt.c"








  
void SCIRST_HANDLER(void)
{    
	(*((volatile unsigned long *)(0x50007000 + 0x190))) = 0x01;
    
    (*((volatile unsigned long *)(0x40001000 + 0x18 ))) = 0x11;
	SCI_RxStart();
	SCI_WaitRx(0x00);
    
    (*((volatile unsigned long *)( 0xE000E180 ))) = 1 << 9;

	SCI_Send_ATR();
	G_bATR_Done = 1;
}







  
void SCIRx_HANDLER(void)
{	
	(*((volatile unsigned long *)(0x40001000 + 0x08 ))) &= ~(1ul<<2);
	
	G_SCIRecieving = 1;	
	
	SCI_StoreNBytes();
    
    if(G_SCIRecieveDone == 1)
    {
        return;
    }
    
    if(SCIAPDUBuf[0] == 0xFF)
    {
        if(G_SCIRecieveIndex >= 2)
        {
            G_SCIRecieveDone = 1;
        }
    }
    else
    {
        if(G_SCIRecieveIndex == 5)
        {
            G_SCIRecieveDone = 1;
            (*((volatile unsigned long *)(0x40001000 + 0x1C ))) = 0x01;
        }
    }
}







 
void SCITx_HANDLER(void)
{	
	(*((volatile unsigned long *)(0x40001000 + 0x08 ))) &= ~(1ul<<4);
    
    if(((*((volatile unsigned long *)(0x40001000 + 0x08 ))) & (1ul<<1)) != 0)
	{
        (*((volatile unsigned long *)(0x40001000 + 0x08 ))) &= ~0x02;
         
    }
    
	if(G_SCISendIndex == (SCILeLength+2))
	{
		G_bSCILeSendDone = 1;
        (*((volatile unsigned long *)( 0xE000E180 ))) = 1 << 9;
		return;
	}

      
    while(((*((volatile unsigned long *)(0x40001000 + 0x10 ))) & (1ul<<1)) != 0);
	 
    (*((volatile unsigned long *)(0x40001000 + 0x00 ))) = SW1SW2 >> 8;
    (*((volatile unsigned long *)(0x40001000 + 0x00 ))) = SW1SW2;
	G_SCISendIndex += 2;	
}

