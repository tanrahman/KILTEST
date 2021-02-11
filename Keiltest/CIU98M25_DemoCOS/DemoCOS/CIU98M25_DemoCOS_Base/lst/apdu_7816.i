#line 1 "SRC\\APDU_7816.c"










 
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

#line 13 "SRC\\APDU_7816.c"






















extern unsigned int SCILeLength;
extern unsigned short SW1SW2;

unsigned int G_output[100];








 
void cmd_Symmetry_ALG(void)
{
    unsigned char ret;
    
    DES_Parameters * Demo_DES_Param;
    DES_Parameters  Demo_DES_ParamVar;
    DES3_Parameters  Demo_3DES_Param;
    SM4_Parameters  Demo_SM4_Param;
    SM1_Parameters  Demo_SM1_Param;
    AES_Parameters  Demo_AES_Param;
	SSF33_Parameters Demo_SSF33_Param;
	

    

 
    unsigned int  std_DES_Key[4] = {0x53D6A7A9,0x0D38BC86,                                0x13B88389,0x963E20CB};

    unsigned int  std_DES_IV[2] = {0x3DCD8D1E,0x76F1233B};
    unsigned int  std_DES_InData[8] = {0xF0E5AC7F,0x803571B0,0xA7408E0C,0x378C05AE,                                   0xE58732C7,0xCC28A34E,0x0B52EE7A,0x8214C162};

    
    unsigned int  std_DES_ECB_EncData[8] = {0x1D1A9D5A,0x7BE7C2F0,0xDD3BFC0A,0x74DBA3C3,0x5DAFFB8C,0x87286F17,0xE36194F3,0x307DFAA3};
    unsigned int  std_2Key3DES_CBC_EncData[8] = {0x8E507B1D,0x81EF13C6,0x56BCF427,0x8A35434D,0xA5DB5C40,0x04B9FE12,0x5A81FED3,0x82AC8DF7};                                              
    
    unsigned int  std_SM4_Key[4]= {0x53D6A7A9,0x0D38BC86,0x13B88389,0x963E20CB};    
    unsigned int  std_SM4_InData[8]= {0xF0E5AC7F,0x803571B0,0xA7408E0C,0x378C05AE,0xE58732C7,0xCC28A34E,0x0B52EE7A,0x8214C162};    
    unsigned int  std_SM4_ECB_EncData[8] = {0xA106CCAB,0x5FA73D12,0xD20150EB,0x3E0C3F72,0x82C19A1B,0xE04097BC,0xC1BC9F09,0x3A349EAD};        
    
    unsigned int  std_SM1_Key[8] = {0x891E5349,0x9FDBE309,0x4E0E4B89,0xB40A8608,0x0,0x0,0x0,0x0};                                  
    unsigned int  std_SM1_IV[4] = {0x65062726,0xBD109208,0x8ABC16A8,0xF93323E9};                           
    unsigned int  std_SM1_InData[8] = {0xE8C03160,0x3EB4347F,0x7EACE55D,0x34B11E9E,0xC93C62E4,0x8A124F86,0xF8644891,0x51265DFF};
    unsigned int  std_SM1_ExtMode_MACData[4] = {0x84FA74A2,0x8A5529D3,0x0C745B64,0x7CE480C8};
    
    unsigned int  std_AES_Key[4] = {0xABF41AEC,0x3AD45119,0x9D86AC50,0x84346C60};                                  
    unsigned int  std_AES_IV[4] = {0x9C945B04,0xCDA87AAD,0x8BBA1956,0x8F9DECFF};                           
    unsigned int  std_AES_InData[8] = {0x73EECE91,0x460F6140,0x646E3486,0xC221E412,0x9F77527F,0x43687B5E,0xF8419782,0x488F6F8C};    
    unsigned int  std_AES_CBC_EncData[8] = {0x0165E254,0xDFF63D63,0x1829AF44,0x000C7F9F,0x61825ABA,0x8AD476A1,0x77B6EDA0,0x8C85E4C0};    
    
	unsigned int  std_SSF33_Key[4] = {0xC95310CC,0xC2B556C3,0x9C3AFB5C,0x72E94B62}; 
	unsigned int  std_SSF33_InData[4] = {0x052C238A,0xCF5F00B1,0x405DEE28,0x08A766AC};
	unsigned int  std_SSF33_ECB_EncData[4] = {0xCD803447,0x0EEB5773,0xDD681675,0x7B4F2ECF};
	
	
     
    
    Demo_DES_Param = &Demo_DES_ParamVar;
    Demo_DES_Param->iDataPtr = std_DES_InData;
    Demo_DES_Param->oDataPtr = G_output;
    Demo_DES_Param->DataLen = sizeof(std_DES_InData);
    
    Demo_DES_Param->iKeyPtr = std_DES_Key;
    Demo_DES_Param->Type = 0x00;
    
    
    ret = HED_DESBlock(Demo_DES_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F01;
        return;
    }
    
    
    ret = memcmp(Demo_DES_Param->oDataPtr, std_DES_ECB_EncData, sizeof(std_DES_ECB_EncData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F02;
        return;
    } 
    
     
    
    Demo_3DES_Param.iDataPtr = std_DES_InData;
    Demo_3DES_Param.oDataPtr = G_output;
    Demo_3DES_Param.DataLen = sizeof(std_DES_InData);
    Demo_3DES_Param.IVPtr = std_DES_IV;
    Demo_3DES_Param.iKeyPtr = std_DES_Key;
    Demo_3DES_Param.Type = 0x20;
    
    
    ret = HED_DES3Block(&Demo_3DES_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F03;
        return;
    }
    
    
    ret = memcmp(Demo_3DES_Param.oDataPtr, std_2Key3DES_CBC_EncData, sizeof(std_2Key3DES_CBC_EncData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F04;
        return;
    } 
    
    
    Demo_3DES_Param.iDataPtr = std_2Key3DES_CBC_EncData;
    Demo_3DES_Param.oDataPtr = G_output;
    Demo_3DES_Param.DataLen = sizeof(std_2Key3DES_CBC_EncData);
    Demo_3DES_Param.IVPtr = std_DES_IV;
    Demo_3DES_Param.iKeyPtr = std_DES_Key;
    Demo_3DES_Param.Type = 0x60;
    
    HED_DES3Block(&Demo_3DES_Param);
    ret = memcmp(Demo_3DES_Param.oDataPtr, std_DES_InData, sizeof(std_DES_InData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F05;
        return;
    }    
    
     
    Demo_SM4_Param.iDataPtr = std_SM4_InData;
    Demo_SM4_Param.oDataPtr = G_output;
    Demo_SM4_Param.DataLen = sizeof(std_SM4_InData);
    Demo_SM4_Param.iKeyPtr = std_SM4_Key;
    Demo_SM4_Param.Type = 0x00;
    
    ret = HED_SM4Block (&Demo_SM4_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F06;
        return;
    }
    ret = memcmp(Demo_SM4_Param.oDataPtr, std_SM4_ECB_EncData, sizeof(std_SM4_ECB_EncData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F07;
        return;
    }
    
     
    Demo_SM1_Param.iDataPtr = std_SM1_InData;
    Demo_SM1_Param.oDataPtr = G_output;
    Demo_SM1_Param.DataLen = sizeof(std_SM1_InData);
    Demo_SM1_Param.iKeyPtr = std_SM1_Key;
    Demo_SM1_Param.IVPtr = std_SM1_IV;
    Demo_SM1_Param.Type = 0x84;
    
    ret = HED_SM1Block (&Demo_SM1_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F08;
        return;
    }
    ret = memcmp(Demo_SM1_Param.oDataPtr, std_SM1_ExtMode_MACData, sizeof(std_SM1_ExtMode_MACData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F09;
        return;
    } 
    
     
    Demo_AES_Param.iDataPtr = std_AES_InData;
    Demo_AES_Param.oDataPtr = G_output;
    Demo_AES_Param.DataLen = sizeof(std_AES_InData);
    Demo_AES_Param.iKeyPtr = std_AES_Key;
    Demo_AES_Param.IVPtr = std_AES_IV;
    Demo_AES_Param.Type = 0x20;
    
    ret = HED_AESBlock (&Demo_AES_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F0A;
        return;
    }
    ret = memcmp(Demo_AES_Param.oDataPtr, std_AES_CBC_EncData, sizeof(std_AES_CBC_EncData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F0B;
        return;
    }

     
    Demo_SSF33_Param.iDataPtr = std_SSF33_InData;
    Demo_SSF33_Param.oDataPtr = G_output;
    Demo_SSF33_Param.DataLen = sizeof(std_SSF33_InData);
    Demo_SSF33_Param.iKeyPtr = std_SSF33_Key;
    Demo_SSF33_Param.Type = 0x00;
    
    ret = HED_SSF33Block (&Demo_SSF33_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F0C;
        return;
    }
    ret = memcmp(Demo_SSF33_Param.oDataPtr, std_SSF33_ECB_EncData, sizeof(std_SSF33_ECB_EncData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F0D;
        return;
    }	
       
    
    SW1SW2 = 0x9000;       
}







 
void cmd_CRC_Calculate(void)
{
    unsigned short ret;
    unsigned char crcXInput[261];

    

 
    const unsigned char crcFInput[261] = {0xBA,0x37,0xB1,0x5A,0xCF,0xF7,0x7C,0x7D,0x0C,0xFD,0xA4,0x06,0xC2,0xA6,0x6D,0xD8,0x35,0x02,0x8D,0x5C,0x28,0x4A,0x57,0x1B,0xA7,0xA0,0x25,0x9D,0x16,0x08,0x06,0x83,                              0x79,0xA5,0xA7,0xE3,0x04,0x37,0x85,0xE2,0xE4,0xD3,0x52,0x96,0x4E,0xE3,0xA6,0x1D,0xC8,0x60,0xE9,0xF7,0xB6,0x4C,0x7F,0xAB,0x26,0x74,0x34,0x98,0xDF,0x66,0xE9,0x1A,                              0xA6,0xB0,0x7F,0xE0,0xD1,0x59,0x02,0x8B,0x10,0xA3,0x18,0x8A,0x7A,0x01,0xAA,0x33,0xD5,0x54,0xD3,0x24,0x29,0x6D,0x08,0xDB,0x86,0xBE,0x87,0x92,0x13,0x61,0x04,0x5E,                              0x59,0x4D,0x90,0x8A,0xD0,0xD6,0xCC,0x30,0xA9,0x64,0x4D,0x18,0xDC,0x76,0x51,0xD3,0x74,0xD9,0xA2,0x19,0x19,0x23,0xC9,0x62,0xDD,0x75,0x75,0xC2,0x4A,0x70,0x2D,0x09,                              0xAA,0x76,0x33,0x19,0x97,0x24,0xBA,0x88,0xC5,0x0E,0x4A,0x79,0x0E,0xBC,0x72,0xB5,0xBD,0xE4,0xAF,0x10,0x1E,0xE8,0x9A,0xF9,0x44,0x91,0x57,0x61,0x1C,0x0B,0x3C,0xD1,                              0xB1,0x22,0xC0,0xC5,0xC0,0xBD,0xA5,0x4C,0x7E,0x9A,0x67,0xE4,0xA6,0x4B,0xE6,0x91,0xC8,0x6F,0x51,0x3F,0xD0,0x33,0x54,0x58,0xD4,0x0A,0x85,0xA8,0x21,0xAA,0x0A,0x6F,                              0x86,0x49,0x8E,0xC5,0xE1,0x18,0x64,0x34,0xEA,0xFF,0xFB,0x93,0x3E,0x99,0x84,0x1F,0xAE,0x71,0xE1,0xDF,0xC7,0x7C,0xCF,0x37,0xA3,0xD9,0x56,0xCC,0xF1,0xC6,0x6F,0x9A,                              0x42,0xE4,0xF5,0x52,0x94,0xAE,0xD0,0xF8,0x23,0x35,0x5F,0xBC,0x6D,0x20,0x25,0x17,0x85,0xE2,0xB6,0x27,0x9B,0x3C,0xE2,0x4E,0xCB,0xF5,0x22,0x08,0x24,0xD6,0x42,0x0C,                              0xFB,0xEA,0x4E,0xA5,0x70}; 
#line 269 "SRC\\APDU_7816.c"
    const unsigned char crcFInput2[13] = {0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x11,0x22,0x33,0x44};                                
    



    
    (*((volatile unsigned long *)(0x50007000 + 0x200))) |= (1ul<<0);
    memcpy(crcXInput, crcFInput, sizeof(crcXInput));
        
    ret = HED_CRC16(0x6363, sizeof(crcXInput), crcXInput,2);
    if (ret != 0x8AA0)
    {
        SW1SW2 = 0x6F01;
        return;
    }
        
    ret = HED_CRC16(0xFFFF, sizeof(crcFInput), (unsigned char *)crcFInput,2);
    if ((unsigned short)(~ret) != 0x2152)
    {
        SW1SW2 = 0x6F02;
        return;
    }
    
    ret = HED_CRC16(0xFFFF, sizeof(crcFInput2), (unsigned char *)crcFInput2,1);
    if ((unsigned short)(~ret) != 0x3A2F)
    {
        SW1SW2 = 0x6F03;
        return;
    }
    
    SW1SW2 = 0x9000;
}







 
void cmd_RSA_ALG(void)
{
    unsigned char ret;
    
     
    unsigned int  Demo_RSA_e[1];
    unsigned int  Demo_RSA_n[64];
    unsigned int  Demo_RSA_p[32];
    unsigned int  Demo_RSA_q[32];
    unsigned int  Demo_RSA_dp[32];
    unsigned int  Demo_RSA_dq[32];
    unsigned int  Demo_RSA_qInv[32];
    unsigned int  Demo_RSA_d[64];
    unsigned int  Demo_RSA_preKey[134];
    unsigned int  Demo_RSA_iData[64];
    unsigned int  Demo_RSA_oData[64];    
    
    RSA_Info * RSA_Param;
    RSA_Info  RSA_ParamVar;


    

 
     const unsigned int std_RSA_e[1] = {0x00010001};
     const unsigned int std_RSA2048_p[32] = {0xAB9C27FF,0x7745BA4E,0xB2F3499E,0xB86B6F98,0x66E62F7E,0x3867198F,0x3CAB7B48,0x6CD1358B,                                  0x94C9352B,0xC1E19FFF,0x09B30FEF,0x5AADA132,0xD9FB9F40,0x9047DC7E,0x594168D1,0xAF9843AB,                                  0x8AED0357,0x4A220A7A,0x1F7F24F4,0xFDD95C3A,0xA2811AF7,0x36935D39,0x7A49A408,0x574C865E,                                  0x305EF0EF,0x6ABDAC25,0x4534CB92,0xDBF3A52E,0xA3283921,0x17F0C925,0xFF199A31,0xB6B13E31};        



         

    const unsigned int std_RSA2048_q[32] = {0xC3AF3333,0x0BF5E51B,0xDD5629E7,0x904FD609,0xB465C676,0x49CFADA1,0x467B3C53,0x97E4F5D3,                                  0x12770D85,0xE3D26C38,0x8FCE0B06,0xB72A0856,0xD4E03E1D,0x7CDCE5F8,0xBE9D9EF9,0x37A08D7E,                                  0xD6B2A91D,0x6AC24A37,0x75148F1E,0xE17C16D7,0x58ECF7EC,0xEC314434,0xDADD6918,0x15EA58F7,                                  0x486EFCD2,0xB4086CBE,0x5AC73B16,0x7C5004BB,0xD6FD635A,0x5A1D069D,0x221A3DFC,0x0B992529};




    const unsigned int std_RSA2048_d[64] = {0x7C72B121,0xA45321BB,0xDEA75557,0x41854F44,0x4D12AC87,0x66AC701B,0x0FC0A4AF,0x4A515F7F,                                  0x330A4F2F,0x720AFD8B,0x469564B1,0x7A1949C3,0xC5389DFD,0xE550A2B8,0x9C9BCC1C,0x7648F659,                                  0xDDC194C3,0x96FF7AC6,0xCE633687,0x478184A0,0xBD5ED586,0xFE11FA9E,0x8538E88D,0x3541A8B1,                                  0x7A7DCC82,0x8541DC1D,0xEB2B031A,0x02C5961C,0x39D1D2D1,0x24FF0054,0xCE114F2B,0xD5CA3EB8,                                  0x597B256A,0x1811BB6C,0x91ABB345,0x3E204285,0xF9F0CD1F,0x1D1BEA48,0xD488F902,0x1EF2C5DC,                                  0xC563BB73,0xE57163E8,0x56C59731,0xBE0E8100,0x6A9D9DD7,0x5764E34A,0xBD2EBE74,0x4A85799D,                                  0xEF2BBD2C,0xEE5BA2FB,0xD5278831,0x7ECF0D63,0x4710EA32,0xB61AC97A,0xBBA15B58,0x7CCFCE52,                                  0x80C45C75,0x97A7FDB4,0x306A7319,0x737C32F3,0xFAC8B41E,0x4D21D77A,0x79D5D429,0x0049E881};
#line 353 "SRC\\APDU_7816.c"
    
    const unsigned int std_RSA2048_n[64] = {0x832D6489,0x43950DFB,0x9459E42B,0x31F7943A,0xB2FEFF71,0xC806FA64,0xE692E2E4,0xCCE6CBEB,                                  0xD5CB659A,0xB561C85D,0xDC6B8B35,0x88A19545,0xD9027CDF,0xFBF9B138,0xFC7F6DB7,0xBB9B813E,                                  0xABEA847A,0x779F9811,0xCAC0F430,0x6DDB1577,0x1246829E,0xB97A1477,0x30AD83D5,0xFA1749B1,                                  0xA8A67895,0x73EB4537,0x8534C83D,0xFBA4620D,0x1E26E982,0xB4D87312,0x95614FD6,0x51BD39D8,                                  0x66C5FB03,0xFDF39C7A,0x48C6DF18,0x850A9375,0x16B9B913,0x217ACA84,0xF9E36874,0xEC64CBD6,                                  0xFE71810C,0xF34F37C8,0x4AD7452D,0xAB0A396B,0x9FD6B301,0xDE1B73F7,0x19F3D69D,0x483E5F3B,                                  0xFFB5D9F8,0xF5C4A723,0x75D57185,0x117947AE,0xAD1AF2CF,0x953BF175,0x88D06678,0x3F5D33B1,                                  0x51C00DD3,0x116506D1,0x8EE8786E,0xF2227676,0x1D298184,0x6E4548A9,0xBE379434,0x26A90AD9};
#line 362 "SRC\\APDU_7816.c"

    const unsigned int std_RSA2048_pdata[64] = {0x008CDF2F,0xD5CE12ED,0xDB4078CD,0x442D7BA2,0x6525BF95,0x98AD0275,0x3C36474D,0xFE4C333C,                                      0x5710B781,0x56E8EFD6,0xA0754AFF,0xB5C6ECA2,0x75CB5059,0xE20C3206,0x279AAC66,0xD9469FEA,                                      0x7E1254C2,0x4CE5633A,0x3283D449,0x1DBB8567,0x74E2CBA0,0xE4815CE7,0x634B6DAC,0x6F5217B0,                                      0x977AFF19,0x3D2D36C1,0x9A505ED4,0x02760F9A,0x6A547891,0x27754ABF,0xF82FD146,0x47D66439,                                      0xAC2F00AE,0xB3283015,0xDFC630C8,0xEF5E51E2,0x5F089F55,0x3251C237,0xEF30225D,0xEA3B4E2B,                                      0xC41B9FAA,0x353E18DB,0x09CB914C,0x69DB15E8,0x5CE68813,0x8D7B8DF7,0x4F35A618,0xDEEA9D2F,                                      0xE8252435,0x4CD7B8BE,0x2149CB88,0xFA552154,0x68D67BF4,0xC15D73A6,0x2025A7A0,0xAD4A19EC,                                      0x1F35D676,0x7E5BD664,0x2E2724A5,0x29343ECD,0x8CC0BF20,0x555E3BEC,0x6BEA6B1C,0xDEC28A0B};
#line 371 "SRC\\APDU_7816.c"
  
    const unsigned int std_RSA2048_cdata[64] = {0x72339510,0xB2C145BD,0xE348FFB9,0x855A43E4,0x53F2F12A,0xFCF638E2,0xBC13646F,0x3CABDA96,                                      0x5D04D100,0x1F579A39,0x0370A84F,0xFEC7ECCB,0x5289AF9C,0x78EB1C16,0x1006C1DD,0x3DB851B9,                                      0x9534B555,0x6EE0D93D,0x9C9E63B5,0xAC3FA3C2,0x23EAC0ED,0x79F28D17,0xAF3B8C70,0x1DB25DAA,                                      0x06AD55BC,0x03B61B64,0x5F46F7E6,0xEBF27467,0x7A7272D7,0xEB3F3605,0x2DE17B0C,0x17B4F0F3,                                      0xDF98977B,0x80C266A6,0x7098BC09,0x40AA1049,0x42EEF868,0x98533498,0xC8C18B8B,0x40939CB3,                                      0x53177411,0x59B95A4B,0xF183EE37,0x9F2268A5,0x9B286AA9,0x7EE3CDC3,0xBCB5CF84,0x099AB05A,                                      0x79AD814E,0x89AA90A3,0x4785A19A,0x9301CA79,0xC2315726,0x307E16EB,0xBA08BC6C,0x393034C9,                                      0x696B24FF,0xA128ADA0,0xE3852B15,0x0F7AF55A,0x96898D95,0xAEF6BF28,0x5C80C969,0x58FE6DC1};
#line 380 "SRC\\APDU_7816.c"
    
    const unsigned int std_RSA1024_pdata[32] = {0x00F6D766,0x9237C2E4,0xA2A6D2DD,0x7B12E9BD,0xA66B8E01,0x802F914A,0xF426EEB0,0x8A4FF458,                                      0xA11AA749,0xF8D7627B,0x746FC131,0x1D52BD89,0x69B01952,0xBDECFD1D,0x314EE197,0x93F7AD16,                                      0xAF1B1F71,0xCE6A6C15,0x7DCF2A55,0x905D6D02,0x6686313C,0x6D8FF887,0xE940B321,0xF2E0E693,                                      0xBC610887,0x1CD728D9,0x472ED6F1,0xDC1D414F,0x25569D67,0x9900C8B0,0xA6662CF8,0xAEF1E7FA};




    RSA_Param = &RSA_ParamVar;
    
    RSA_Param->pE = Demo_RSA_e;
    RSA_Param->pN = Demo_RSA_n;
    RSA_Param->pP = Demo_RSA_p;
    RSA_Param->pQ = Demo_RSA_q;
    RSA_Param->pDp = Demo_RSA_dp;
    RSA_Param->pDq = Demo_RSA_dq;
    RSA_Param->pQInv = Demo_RSA_qInv;
    RSA_Param->pD = Demo_RSA_d;
    RSA_Param->pPreKey = Demo_RSA_preKey;
    RSA_Param->pDataIn = Demo_RSA_iData;
    RSA_Param->pDataOut = Demo_RSA_oData;                                      
         
     
    
    memcpy(Demo_RSA_e,std_RSA_e,sizeof(std_RSA_e));
    memcpy(Demo_RSA_p,std_RSA2048_p,sizeof(std_RSA2048_p));
    memcpy(Demo_RSA_q, std_RSA2048_q, sizeof(std_RSA2048_q));     
   
    
    RSA_Param->operMode = 0x00;
    RSA_Param->len = 64;
    ret = HED_RSA2048_Complete(RSA_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F00;
        return;
    } 
    
    if (memcmp(Demo_RSA_n, std_RSA2048_n, sizeof(std_RSA2048_n)) != 0)
    {
        SW1SW2 = 0x6F01;
        return;
    }
    
    if (memcmp(Demo_RSA_d, std_RSA2048_d, sizeof(std_RSA2048_d)) != 0)
    {
        SW1SW2 = 0x6F02;
        return;
    }     
    
    
    memcpy(Demo_RSA_iData, std_RSA2048_pdata, sizeof(std_RSA2048_pdata));
    
    
    RSA_Param->len = 64;
    ret = HED_RSA2048_PriOpt(RSA_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F03;
        return;
    }

    if (memcmp(Demo_RSA_oData, std_RSA2048_cdata, sizeof(std_RSA2048_cdata)) != 0)
    {
        SW1SW2 = 0x6F04;
        return;
    }  
    
    
    memcpy(Demo_RSA_iData, std_RSA2048_cdata, sizeof(std_RSA2048_cdata));
    
    
    RSA_Param->len = 64;
    ret = HED_RSA2048_PubOpt(RSA_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F05;
        return;
    }
    
    if (memcmp(Demo_RSA_oData, std_RSA2048_pdata, sizeof(std_RSA2048_pdata)) != 0)
    {
        SW1SW2 = 0x6F06;
        return;
    }
        
     
    
    memcpy(Demo_RSA_e, std_RSA_e, sizeof(std_RSA_e));
    
    
    RSA_Param->operMode = 0x00;
    RSA_Param->len = 32;
    HED_RSA2048_GenKey(RSA_Param); 
    
    
    memcpy(Demo_RSA_iData, std_RSA1024_pdata, sizeof(std_RSA1024_pdata));    
    
    RSA_Param->len = 32;
    ret = HED_RSA2048_PubOpt(RSA_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F07;
        return;
    }
    
    
    
    memcpy(Demo_RSA_iData, Demo_RSA_oData, sizeof(std_RSA1024_pdata));
    RSA_Param->len = 32;
    ret = HED_RSA2048_PriOpt(RSA_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F08;
        return;
    }

    if (memcmp(Demo_RSA_oData, std_RSA1024_pdata, sizeof(std_RSA1024_pdata)) != 0)
    {
        SW1SW2 = 0x6F09;
        return;
    }
        
    SW1SW2 = 0x9000;
}







 
void cmd_SM2_ALG(void)
{
    unsigned char ret;
    
     
__align(4) unsigned char  Demo_SM2_iData[512];       
__align(4) unsigned char  Demo_SM2_oData[256];
    unsigned int Demo_SM2_RNGData[8];
    unsigned int Demo_SM2_priKey[8];
    unsigned int Demo_SM2_pubKey[16];
    
    SM2_Parameters * SM2_Param;
    SM2_Parameters  SM2_ParamVar;
    
    SM2KeyExch_Parameters * SM2KeyExch_Param;
    SM2KeyExch_Parameters SM2KeyExch_ParamVar;

    

 
    const unsigned char std_SM2_Prikey_d[32] = {0x9E,0x1F,0x3B,0x25,0x12,0x38,0x45,0x09,0x76,0x7D,0x7A,0x5A,0x5D,0x03,0x70,0x1F,0x26,0xA6,0x42,0x8B,0x66,0xBB,0x64,0x43,0x4D,0xC8,0x07,0x4D,0x2D,0x12,0x39,0xB3};
    const unsigned char std_SM2_Pubkey[64] = {0xA8,0x8B,0xCD,0xF9,0x81,0x22,0x60,0x8F,0x18,0xB0,0x0E,0xB0,0x3A,0x41,0x0C,0xA1,0xCD,0x6D,0x7E,0x41,0x24,0x83,0x2F,0x4B,0xC6,0x63,0x86,0x1C,0x45,0xFE,0x5D,0x31,                                0x90,0xBE,0xE3,0x75,0x9C,0x25,0xA2,0x99,0xEF,0x39,0x7C,0x87,0xF6,0x9A,0x42,0x1C,0xE0,0xD9,0x32,0x5F,0x36,0xFC,0x0F,0x4F,0xA0,0x02,0x7B,0x30,0x12,0xF8,0xAB,0xA0};

    const unsigned char std_SM2_pData[32] = {0x96,0x04,0xFC,0xBB,0x3C,0x6E,0xE8,0xB9,0x38,0xD7,0xD4,0xC2,0xF8,0x46,0xBC,0xB1,0x7C,0x0A,0xC0,0xF3,0x0A,0xA1,0x79,0x8E,0x23,0xD8,0x8D,0x62,0xB5,0x34,0x81,0xAF};
    const unsigned char std_SM2_cData[128] = {0x4E,0xB7,0x39,0x93,0x6B,0x12,0x5D,0x38,0xED,0xC9,0x6B,0xEC,0x94,0x03,0x3E,0x70,0x78,0x74,0x84,0xD4,0x55,0x9A,0xF8,0xB7,0x22,0x80,0x13,0xE4,0x99,0x69,0x1F,0x83,                                  0x9C,0x75,0xD0,0x04,0x35,0x05,0xBA,0x10,0x0E,0xD5,0x18,0x32,0x8C,0x67,0xAC,0x13,0x74,0x0C,0x8D,0x44,0xA1,0x42,0xA6,0x81,0x4A,0x22,0x4F,0x1A,0x20,0x92,0x4B,0x25,                                  0xCB,0xFA,0xE9,0x58,0x88,0x7F,0x99,0xB3,0xA9,0x82,0xB3,0x46,0x92,0xBB,0x62,0xAB,0x4D,0x91,0x64,0xFA,0xE8,0x13,0xC4,0xA1,0xA2,0x9F,0x88,0x7E,0x1A,0x42,0x2C,0xD9,                                  0x5C,0xE9,0x46,0xBE,0xF4,0x5B,0x0A,0x62,0x6C,0xEE,0xEB,0x46,0xF0,0x10,0x79,0xA2,0x8A,0x67,0xDC,0xAF,0x3F,0xE6,0x0F,0x4B,0x7D,0x94,0x5F,0x36,0x82,0x69,0x48,0x99};



    
    const unsigned char std_SM2_signingData[32] = {0xAF,0x81,0x34,0xB5,0x62,0x8D,0xD8,0x23,0x8E,0x79,0xA1,0x0A,0xF3,0xC0,0x0A,0x7C,0xB1,0xBC,0x46,0xF8,0xC2,0xD4,0xD7,0x38,0xB9,0xE8,0x6E,0x3C,0xBB,0xFC,0x04,0x96};
    const unsigned char std_SM2_signingResult[64] = {0xB7,0xB2,0x7C,0x1B,0x46,0xD6,0x20,0x0F,0x03,0xEF,0x84,0xD6,0x23,0x69,0x13,0xAA,0x5D,0x77,0x65,0x9A,0x04,0x54,0x6C,0xC5,0xBF,0x71,0x6C,0x15,0x46,0xB9,0xF3,0x2A,                                         0x08,0x1B,0x5E,0x29,0x29,0x27,0xA8,0xFF,0x53,0x8C,0xC1,0x1B,0xED,0xAD,0x0C,0xE0,0x3D,0xA3,0x0C,0x55,0xBA,0x20,0xF8,0xD3,0x36,0xB6,0xD4,0x74,0xDB,0xC8,0x49,0x05}; 

    const unsigned char std_SM2_GetZ_AID[4] = {0x03,0x36,0x36,0x93};
    const unsigned char std_SM2_GetZ_Result[32] = {0xF8,0x2A,0xFE,0xF5,0xBC,0x77,0x00,0xE1,0xE6,0x58,0xFD,0xE9,0x0A,0x59,0xF1,0x31,0xA8,0x1B,0x68,0x19,0x24,0x8D,0x63,0x7E,0x8B,0x79,0xED,0x91,0x8C,0xCC,0x7E,0x6F};  
    
    const unsigned char std_SM2_AID[33] = {0x20,0x19,0xAD,0x86,0xDF,0x1B,0xD6,0x7F,0x11,0x66,0x7B,0x90,0x42,0x59,0xCD,0x8D,0xFB,0x81,0xEB,0xA6,0xFC,0x05,0xC5,0x70,0x39,0x4D,0x32,0x35,0x14,0xF3,0x4F,0x7B,0xDC};
    const unsigned int std_SM2_APrikey_d[8] = {0x5F16CC28,0x2485FF80,0x8D84203A,0xFCDC5C44,0x1B5F8436,0x335A7DE6,0xFC737F5E,0x33FD299D};   
    const unsigned int std_SM2_APubkey[16] = {0x90F219EA,0x8B32DC5B,0x2CE29B4F,0x646AB492,0xAC4F5B3D,0x010C260B,0x777B7A3B,0x2ED8FFA7,                                      0x3B21C0B9,0x9734587E,0xFC86057E,0xA449EE21,0xB310BF0A,0x2AB9E48A,0x0D23075D,0xD49DD902}; 

    const unsigned int std_SM2_ATempPrikey_d[8] = {0x1E817CE5,0x8B83B134,0xB2BFE0E8,0x410EA39E,0x7ECF6073,0x4E531AB1,0xFA5F81CE,0xB587F5D8};   
    const unsigned int std_SM2_ATempPubkey[16] = {0x5B692DAF,0xD36B8A74,0xE3C7326C,0xCC0B1E2A,0xB0D60025,0x1A5BF0FB,0x383A5A70,0x0A7BC9C4,                                        0xFAF81A57,0x69625B16,0xAC952219,0xF21690CD,0x5AA51EE4,0xC7CE7869,0xF3B8E360,0xA1A3C2D6}; 

        
    const unsigned char std_SM2_BID[33] = {0x20,0x19,0x46,0xCA,0xF6,0x05,0xAA,0x83,0x85,0x18,0x69,0xDD,0xBB,0x71,0xCB,0xFD,0x05,0xFC,0x27,0xFF,0x2C,0xDB,0xBF,0x07,0x47,0x16,0xE3,0x8C,0x00,0x85,0x45,0xE3,0x09};
    const unsigned int std_SM2_BPrikey_d[8] = {0x70CAB6F4,0x1BD39EB8,0xFE2A995E,0x32AB4978,0xAA401F8B,0x9E0A95F6,0xF22CFA6C,0x45E8EE08};   
    const unsigned int std_SM2_BPubkey[16] = {0x8D18BB94,0xE3378628,0xD413E1F4,0xCFE3D885,0xBA1AB50E,0xEB13EAD3,0x2A57DC27,0x740DFF23,                                    0x85380BBD,0x36791323,0xF2982E60,0xE97375E6,0x3261B99C,0x6EBE40D2,0x7CD0273F,0x2C5F933C}; 

    const unsigned int std_SM2_BTempPrikey_d[8] = {0xC2B466AB,0x4B5A6442,0x670BCEB0,0x7D6F76D3,0x8713BE86,0x3ABF1275,0x27063E0E,0x461C0DBC};   
    const unsigned int std_SM2_BTempPubkey[16] = {0xB264667C,0x18CECC5E,0xDC9AA242,0x2C9AE2D7,0x57A101ED,0x07029ADE,0x7973CEFF,0x102E00F5,                                            0x08FC95BE,0x35592981,0xF19046D6,0x0C401847,0xDD45C5FD,0x7F8A99DF,0x7D79C382,0x354ED8D4}; 

    
    const unsigned char std_SM2_ExchgResult[32] = {0xC9,0x7A,0x20,0xDA,0x61,0x18,0xBD,0x0D,0x27,0xDD,0x56,0xEB,0x03,0x90,0xE8,0xFE,0xB7,0xA4,0xA9,0x4D,0x9F,0x5A,0x2D,0x04,0x19,0x92,0xED,0x58,0x32,0x69,0xA0,0x08};
    
     
    SM2_Param = &SM2_ParamVar;
    SM2_Param->iDataPtr = Demo_SM2_iData;
    SM2_Param->oDataPtr = Demo_SM2_oData;
    SM2_Param->rndPtr = Demo_SM2_RNGData;
    SM2_Param->priKeyPtr = Demo_SM2_priKey; 
    SM2_Param->pubKeyPtr = Demo_SM2_pubKey; 
    SM2_Param->iEccSel = 1;     

     
    
    memcpy(Demo_SM2_iData,std_SM2_pData,sizeof(std_SM2_pData));
    memcpy(Demo_SM2_priKey,std_SM2_Prikey_d,sizeof(std_SM2_Prikey_d));
    memcpy(Demo_SM2_pubKey,std_SM2_Pubkey,sizeof(std_SM2_Pubkey));
    
    ret = HED_SM2GenKey(SM2_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F00;
        return;
    }   
    
    
    ret = HED_SM2Encrypt(SM2_Param, sizeof(std_SM2_pData)); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F01;
        return;
    }
    
    
    memcpy(Demo_SM2_iData, Demo_SM2_oData, sizeof(std_SM2_pData)+96);
    ret = HED_SM2Decrypt(SM2_Param, sizeof(std_SM2_pData)+96); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F02;
        return;
    } 
    
    
    if (memcmp(Demo_SM2_oData, std_SM2_pData, sizeof(std_SM2_pData)) != 0)
    {
        SW1SW2 = 0x6F03;
        return;
    }  
    
     
    
    memcpy(Demo_SM2_iData, std_SM2_signingData, sizeof(std_SM2_signingData));    
    
    memcpy(Demo_SM2_priKey, std_SM2_Prikey_d, sizeof(std_SM2_Prikey_d));    
    
    memcpy(Demo_SM2_pubKey, std_SM2_Pubkey, sizeof(std_SM2_Pubkey));
    
    
    ret = HED_SM2Sign(SM2_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F04;
        return;
    } 
    
    
    ret = HED_SM2Verify(SM2_Param); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F05;
        return;
    } 
    
    
    memcpy(Demo_SM2_oData, std_SM2_signingResult, sizeof(std_SM2_signingResult));
    
    ret = HED_SM2Verify(SM2_Param); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F06;
        return;
    } 
    
    
    memcpy(Demo_SM2_iData, std_SM2_GetZ_AID, sizeof(std_SM2_GetZ_AID));
    ret = HED_SM2GetZ (std_SM2_GetZ_AID, Demo_SM2_pubKey,(unsigned int *)Demo_SM2_oData, 1);
    if (ret != 0)
    {
        SW1SW2 = 0x6F07;
        return;
    }
    
    if (memcmp(Demo_SM2_oData, std_SM2_GetZ_Result, sizeof(std_SM2_GetZ_Result)) != 0)
    {
        SW1SW2 = 0x6F08;
        return;
    }
    
    
    
    memcpy(Demo_SM2_iData, std_SM2_cData,64);
    memcpy(Demo_SM2_iData+32*2,std_SM2_cData+32*2,32);
    memcpy(Demo_SM2_iData+32*2+sizeof(std_SM2_pData),std_SM2_cData+32*2+sizeof(std_SM2_pData),sizeof(std_SM2_pData));
    
    ret = HED_SM2Decrypt(SM2_Param, sizeof(std_SM2_pData)+96);
    if (ret != 0)
    {
        SW1SW2 = 0x6F09;
        return;
    } 
    
    
    if (memcmp(Demo_SM2_oData, std_SM2_pData, sizeof(std_SM2_pData)) != 0)
    {
        SW1SW2 = 0x6F0A;
        return;
    }
    
     


    
    SM2KeyExch_Param = &SM2KeyExch_ParamVar;
    SM2KeyExch_Param->AID = std_SM2_AID;
    SM2KeyExch_Param->BID = std_SM2_BID;
    SM2KeyExch_Param->PublicKey = std_SM2_APubkey;
    SM2KeyExch_Param->PrivateKey = std_SM2_APrikey_d;
    SM2KeyExch_Param->BPublicKey = std_SM2_BPubkey;
    SM2KeyExch_Param->TempPrivateKey = std_SM2_ATempPrikey_d;
    SM2KeyExch_Param->TempPubKeyX = std_SM2_ATempPubkey;
    SM2KeyExch_Param->BTempPubKey = std_SM2_BTempPubkey;
    SM2KeyExch_Param->oLen = 32;
    SM2KeyExch_Param->DataType = 1;
    SM2KeyExch_Param->iEccSel = 1;
    
    ret = HED_SM2KeyExchange(SM2KeyExch_Param,Demo_SM2_oData);
    if (ret != 0)
    {
        SW1SW2 = 0x6F0B;
        return;
    } 
    
    if (memcmp(Demo_SM2_oData, std_SM2_ExchgResult, sizeof(std_SM2_ExchgResult)) != 0)
    {
        SW1SW2 = 0x6F0C;
        return;
    }    
    
    
    SM2KeyExch_Param = &SM2KeyExch_ParamVar;
    SM2KeyExch_Param->AID = std_SM2_BID;
    SM2KeyExch_Param->BID = std_SM2_AID;
    SM2KeyExch_Param->PublicKey = std_SM2_BPubkey;
    SM2KeyExch_Param->PrivateKey = std_SM2_BPrikey_d;
    SM2KeyExch_Param->BPublicKey = std_SM2_APubkey;
    SM2KeyExch_Param->TempPrivateKey = std_SM2_BTempPrikey_d;
    SM2KeyExch_Param->TempPubKeyX = std_SM2_BTempPubkey;
    SM2KeyExch_Param->BTempPubKey = std_SM2_ATempPubkey;
    SM2KeyExch_Param->oLen = 32;
    SM2KeyExch_Param->DataType = 0;
    SM2KeyExch_Param->iEccSel = 1;
    
    ret = HED_SM2KeyExchange(SM2KeyExch_Param,Demo_SM2_oData); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F0D;
        return;
    } 
    
    if (memcmp(Demo_SM2_oData, std_SM2_ExchgResult, sizeof(std_SM2_ExchgResult)) != 0)
    {
        SW1SW2 = 0x6F0E;
        return;
    }
        
    SW1SW2 = 0x9000;
}







 
void cmd_HASH_ALG(void)
{
    unsigned int  out_hash160_v[7];
    unsigned int  out_hash256_v[10];
    unsigned int  out_SM3_v[9];
    unsigned int len;
    unsigned int * inPtr;
    unsigned char ret;
    
    

     
__align(4)    unsigned char  std_SHA1_inputLess64[58] = {0x0A,0x0F,0xEA,0xAA,0x53,0x66,0x5D,0x4C,0x8C,0xB3,0x85,0x66,0xDF,0x4E,0xE6,0x1F,0x27,0x3B,0xB6,0x34,0x83,0x42,0x41,0x58,0x08,0x17,0x3C,0x55,0x95,0x4B,0xFE,0x8E,                                         0xC5,0xCB,0xBA,0xF6,0x76,0xB8,0x02,0xAB,0xD8,0x94,0x45,0x88,0x4C,0x69,0x7F,0x80,0x81,0x52,0x1C,0x0B,0x4A,0x88,0x30,0x0E,0x25,0x46};

__align(4)    unsigned char  std_SHA1_outputLess64[20] = {0x34,0x8C,0x74,0xD1,0xEE,0xB3,0x33,0x49,0x9B,0x8F,0xE2,0xC2,0xD0,0x5D,0xBF,0xD0,0x9B,0xA3,0x6D,0x2A};
    
__align(4)    unsigned char  std_SHA_inputMore64[132] = {0xF4,0x4C,0x7D,0x4F,0x8D,0xF0,0xFD,0x73,0xE8,0x15,0x6A,0x23,0x26,0x0B,0x04,0x05,0x3A,0x16,0xF0,0x79,0x4E,0xB1,0x06,0xE5,0x95,0x4E,0x32,0xEE,0x48,0xD8,0x6C,0x2A,                                         0xD8,0xA2,0x38,0xDF,0x6A,0x5D,0x07,0xD6,0x88,0x13,0xBD,0x8A,0xAD,0x63,0x55,0xFD,0x0A,0x2A,0xDA,0x8F,0x74,0xB7,0x89,0x1A,0xC8,0x42,0x24,0x72,0xB9,0x90,0xFC,0x2A,                                         0xE8,0x8B,0x62,0xC4,0xD0,0x0E,0xC1,0x89,0x3C,0xBD,0x24,0xE9,0xCE,0xC1,0x6A,0xD3,0x59,0xC7,0xDB,0x27,0xD0,0x49,0x19,0x65,0xC8,0x10,0x2C,0x87,0xE4,0x18,0xCC,0x1C,                                         0x11,0xED,0x99,0xB6,0xF9,0x99,0xF9,0xEE,0xCC,0xBF,0x7E,0xE7,0xD4,0x3A,0x30,0xFA,0xAA,0xAE,0xF4,0x26,0x38,0xD4,0x7D,0xAA,0x55,0xB1,0x8E,0xC5,0x70,0x22,0x34,0xB8,                                         0x0D,0x18,0x68,0x67};




__align(4)    unsigned char  std_SHA1_input64[64] = {0x0A,0x0F,0xEA,0xAA,0x53,0x66,0x5D,0x4C,0x8C,0xB3,0x85,0x66,0xDF,0x4E,0xE6,0x1F,0x27,0x3B,0xB6,0x34,0x83,0x42,0x41,0x58,0x08,0x17,0x3C,0x55,0x95,0x4B,0xFE,0x8E,                                         0xC5,0xCB,0xBA,0xF6,0x76,0xB8,0x02,0xAB,0xD8,0x94,0x45,0x88,0x4C,0x69,0x7F,0x80,0x81,0x52,0x1C,0x0B,0x4A,0x88,0x30,0x0E,0x25,0x46,0x00,0x00,0x00,0x00,0x00,0x00};

__align(4)    unsigned char  std_SHA1_outputMore64[20] = {0xFB,0x74,0xDD,0xEB,0xDB,0x40,0x34,0x5C,0x10,0xC0,0x09,0x8B,0x80,0x3D,0x25,0x35,0xF1,0xB9,0x43,0xD6};    
__align(4)    unsigned char  std_SHA256_outputMore64[32] = {0x39,0x21,0xE9,0x5E,0xCA,0xE2,0x33,0xB3,0x2C,0xB8,0x48,0xFC,0x45,0xF3,0x89,0xA7,0x84,0xF1,0x78,0x7B,0xF2,0x41,0x2E,0x9D,0x49,0x25,0xDB,0x23,0x4A,0x4A,0xDE,0xA1};
    
__align(4)    unsigned char   std_SM3_inputMore64[97] = {0x56,0xBB,0xAD,0x9F,0x88,0xD3,0xAC,0x07,0x58,0xC4,0xED,0x64,0xD2,0xEF,0x4A,0xA9,0x77,0x3A,0xC6,0xB8,0x74,0xFA,0xEA,0xF6,0x23,0x22,0x5F,0x0E,0xC6,0xAB,0xCE,0x03,                                         0x81,0x45,0xF6,0x7A,0x98,0x3E,0x0E,0x48,0xE8,0xB2,0x5B,0x39,0xAA,0xF2,0x14,0x22,0x65,0x38,0x74,0x28,0x32,0x8B,0x1F,0x51,0x36,0xEF,0xB8,0x4A,0x5B,0xCF,0xC2,0x79,                                         0x50,0xAE,0xB6,0x44,0xC3,0x0B,0x64,0xA2,0xDB,0x94,0x8D,0xE2,0xFA,0x8D,0xC0,0xBA,0xB3,0x81,0x73,0x92,0x08,0x2A,0x64,0x11,0xE7,0x9C,0x31,0xE6,0xE6,0xB7,0x34,0xDA,                                         0x3C};



__align(4)    unsigned char  std_SM3_outputMore64[32] ={0x7C,0xF6,0x13,0x49,0x75,0xB9,0xD6,0x77,0x47,0x2B,0x98,0x4C,0xBE,0x4A,0xD2,0x60,0xFC,0x8A,0x37,0xAD,0x3E,0x96,0x4E,0xA6,0xE2,0x02,0xC5,0xB9,0xE2,0x97,0x26,0x44};

     
    
    HED_SHA1_Init(out_hash160_v);
    HED_SHA1_Block(out_hash160_v,(unsigned int *)std_SHA1_inputLess64,sizeof(std_SHA1_inputLess64));
    
    
    ret = memcmp(out_hash160_v, std_SHA1_outputLess64, 20);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F01;
        return;
    }
    
         
    len = sizeof(std_SHA_inputMore64);    
    HED_SHA1_Init(out_hash160_v);                  
    inPtr = (unsigned int *)std_SHA_inputMore64;
    for(;len >= 64;)
    {
        HED_SHA1_Block(out_hash160_v,inPtr,64);         
        len -=64;
        inPtr += 16;
    }
    HED_SHA1_Block(out_hash160_v,inPtr,len);       
    
    ret = memcmp(out_hash160_v, std_SHA1_outputMore64, 20);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F02;
        return;
    }

     
    inPtr = (unsigned int *)std_SHA1_input64;
    HED_SHA1_Init(out_hash160_v);
    HED_SHA1_Block(out_hash160_v,inPtr,64);         
    HED_SHA1_Block(out_hash160_v,inPtr+16,0);      
    
         
    len = sizeof(std_SHA_inputMore64);    
    HED_SHA256_Init(out_hash256_v);                  
    inPtr = (unsigned int *)std_SHA_inputMore64;
    for(;len >= 64;)
    {
        HED_SHA256_Block(out_hash256_v,inPtr,64);         
        len -=64;
        inPtr += 16;
    }
    HED_SHA256_Block(out_hash256_v,inPtr,len);       
    
    ret = memcmp(out_hash256_v, std_SHA256_outputMore64, 32);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F03;
        return;
    }

     
    inPtr = (unsigned int *)std_SHA1_input64;
    HED_SHA256_Init(out_hash256_v);
    HED_SHA256_Block(out_hash256_v,inPtr,64);         
    HED_SHA256_Block(out_hash256_v,inPtr+16,0);      
    
     
    len = sizeof(std_SM3_inputMore64);    
    HED_SM3Initial(out_SM3_v);                  
    inPtr = (unsigned int *)std_SM3_inputMore64;
    for(;len >= 64;)
    {
        HED_SM3Block(out_SM3_v,inPtr,64);         
        len -=64;
        inPtr += 16;
    }
    HED_SM3Block(out_SM3_v,inPtr,len);       
    ret = memcmp(out_SM3_v, std_SM3_outputMore64, 32);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F04;
        return;
    }
    
    SW1SW2 = 0x9000;
}







 
void cmd_GET_INFO(void)
{
    unsigned char p3,ret;
    
         
    p3 = SCIAPDUBuf[4];
    SendINS(SCIAPDUBuf[1]);
    
     
    switch (SCIAPDUBuf[2])
    {
        case 0x01:
            ret = HED_RNG1Check();
            if(ret == 1)
            {
                SW1SW2 = 0x6F00;
                return;    
            }
            ret = HED_PokerCheck();
            if(ret == 1)
            {
                SW1SW2 = 0x6F01;
                return;    
            }            
            HED_GetRandom_Enhanced(SCIAPDUBuf,8);
            break;
            
        case 0x02:
            HED_GetRandom(SCIAPDUBuf,8);
            break;
        
        case 0x03:
            HED_GetFactoryCode(SCIAPDUBuf);
            break;        
            
        case 0x04:
            HED_GetChipId(SCIAPDUBuf);
            break;
            
        default:
            SW1SW2 = 0x6F00;
            return;    
    }
        
    SCILeLength = (p3 == 0 ? 256 : p3);
    SW1SW2 = 0x9000;    
}







 
void cmd_NVM_ErWr(void)
{
    unsigned int NVMAddr,ret;
    unsigned int  i;
    unsigned int  DataToNVM[128];
    unsigned char * ptr;    
    
    SendINS(SCIAPDUBuf[1]);
    while(G_SCIRecieveIndex != (5+SCIAPDUBuf[4]));
    
    if(SCIAPDUBuf[4] < 0x04)
    {
        SW1SW2 = 0x6F01;
        return;
    }    
    
    memcpy(DataToNVM,SCIAPDUBuf+5+4,SCIAPDUBuf[4]-4);
    
    NVMAddr = ((unsigned int)SCIAPDUBuf[5])<<24 | ((unsigned int)SCIAPDUBuf[6])<<16 | ((unsigned int)SCIAPDUBuf[7])<<8 | SCIAPDUBuf[8];
    NVMAddr &= ~0x1FF;
     
    if((NVMAddr < 0x19000) || (NVMAddr >= 0x64000))
    {
        SW1SW2 = 0x6F01;
        return;
    }   
    
    ptr = (unsigned char *)DataToNVM;
    for(i=SCIAPDUBuf[4]-4;i<0x200;i++)
    {
        *(ptr+i) = 0xFF;
    }
    
      
      
    
    do
    {
        ret = HED_FlashPageInit_St(NVMAddr);
        ret |= HED_FlashErWrPage_St(NVMAddr,DataToNVM);
    }while(ret == ~0);
    
    ret = memcmp((unsigned char *)DataToNVM, (unsigned char *)NVMAddr, 0x200);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F02;
        return;
    }    
    
    ret = HED_HEFlash_Init();
    if(ret == ~0)
    {
        HED_HEFlashMapReset();
    }
    HED_HEFlashEWPage(0x0011C000,DataToNVM);     
    ret = memcmp((unsigned char *)DataToNVM, (unsigned char *)0x0011C000, 0x200);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F03;
        return;
    }
        
    SW1SW2 = 0x9000;
}







 
void cmd_back2Loader(void)
{
    unsigned int  DataToNVM[128];
    
    memcpy((unsigned char*)DataToNVM,(unsigned char*)0x1FFF8000,0x200);
    DataToNVM[0] = 0xB639A527;
    
    HED_FlashErWrPage_St(0x1FFF8000,DataToNVM);
    SW1SW2 = 0x9000;
}







 
void cmd_M1_Opt(void)
{
	unsigned char result;
	unsigned int block0Data[4]={0x00010203, 0x04050607, 0x08090A0B, 0x0C0D0E0F};
	unsigned int pwData[6]={0x0B545707, 0X45FE3AE7, 0x01020304, 0X05060708, 0x090a0B0C, 0X0D0E1F23};
	unsigned int pwData2[6]={0x0B545707, 0X45FE3AE7, 0x0, 0x0, 0x0, 0x0};
	
	G_cM1_PwAlgType = 0;

	result = HED_M1_InitBlock(block0Data);
    result |= HED_M1_ResetSector(1);
	if(result != 0)
    {
        SW1SW2 = 0x6F01;
        return;
    }   
    
	result = HED_M1_PwWriteBlock (pwData, 2);
	if(result != 0)
    {
        SW1SW2 = 0x6F02;
        return;
    }
	
	result = HED_M1_PwReadBlock (pwData2, 2);
	if(result != 0)
    {
        SW1SW2 = 0x6F03;
        return;
    }
		
	if(memcmp(pwData2, pwData, 24) !=0)
	{
        SW1SW2 = 0x6F03;
        return;
	}
    SW1SW2 = 0x9000;
}







 
void cmd_TerminalCapa(void)
{
    SendINS(SCIAPDUBuf[1]);
    while(G_SCIRecieveIndex != 5+SCIAPDUBuf[4]);

    if ((*((volatile unsigned long *)(0x50007000 + 0x180))) & (1ul<<2))
    {		
        (*((volatile unsigned long *)(0x50007000 + 0x194))) |= (1ul<<30);
        (*((volatile unsigned long *)(0x50007000 + 0x204))) |= (1ul<<20);		
    }
    SW1SW2 = 0x9000;
}







 
void cmd_getResponse(void)
{
	unsigned int i;

	SCIAPDUBuf[0] = 0x61;
	SCIAPDUBuf[1] = 0x12;
	SCIAPDUBuf[2] = 0x12;
	SCIAPDUBuf[3] = 0x4F;
	SCIAPDUBuf[4] = 0x10;	
	for(i=0;i<16;i++)
	{
		SCIAPDUBuf[5+i] = i;
	}
    
	SCILeLength = 0x15;
    SendINS(0xC0);
    SW1SW2 = 0x9000;
}







 
void cmd_selectFile(void)
{
    SendINS(SCIAPDUBuf[1]);
    while(G_SCIRecieveIndex != 5+SCIAPDUBuf[4]);	    
	if(SCIAPDUBuf[4] == 0x02)
    {
        SW1SW2 = 0x6115; 
    }
    else
    {
        SW1SW2 = 0x9000; 
    }
}

static const COMMANDLIST CMD_INSList[]=
{ 
	{0xF0, cmd_Symmetry_ALG},
 	{0xF2, cmd_CRC_Calculate},
  	{0xF4, cmd_RSA_ALG},
  	{0xF6, cmd_SM2_ALG},
  	{0xF8, cmd_HASH_ALG}, 
  	{0xD6, cmd_GET_INFO},
  	{0xD2, cmd_NVM_ErWr},
    {0xD8, cmd_M1_Opt},
    {0xD0, cmd_back2Loader},
    {0xC0, cmd_getResponse},
    {0xA4, cmd_selectFile},
    {0xAA, cmd_TerminalCapa},
};







 
void SCIAPDU_Dispatch(void)
{
    unsigned char i;
    
	SW1SW2 = 0x6D00;
    SCILeLength = 0x00;    
    
    for(i=0;i<(sizeof(CMD_INSList)/sizeof(COMMANDLIST));i++)
    {
    	if(CMD_INSList[i].ins == SCIAPDUBuf[1])
    	{
    		CMD_INSList[i].func();
    		break;
    	}                           			
    }
    
    SCI_WaitRx(0x00);
    SCI_StopTx60();
	SCI_StartTx_INT(0);
}

