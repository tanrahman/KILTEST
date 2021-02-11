/*****************************************************
 Copyright(C),CEC Huada Electronic Design Co.,Ltd.
 
 File name: 	APDU_7816.c
 Author:    	
 Version:		
 Date:  		
 Description: 
 History:	
				
******************************************************/
#include "../inc/Declare.h"

#define DemoNVM_START_ADDR           0x19000// just take 100k for an example
#define DemoNVM_END_ADDR             0x64000// just take 400k for an example 

#define Card_Status_ADDR         0x1FFF8000
#define HEFlash_Addr             0x0011C000//base on the condition that MAX user FLASH is 0x11BFFF

#define ECB_ENCRYPT             0x00
#define ECB_DECRYPT             0x40
#define CBC_ENCRYPT             0x20
#define CBC_DECRYPT             0x60
#define MAC_EXTPARA             0x84

#define ECB_ENCRYPT_ExtKey      0x04
#define ECB_DECRYPT_ExtKey      0x44

#define APDU_CLA    SCIAPDUBuf[0]
#define APDU_INS    SCIAPDUBuf[1]
#define APDU_P1     SCIAPDUBuf[2]
#define APDU_P2     SCIAPDUBuf[3]
#define APDU_P3     SCIAPDUBuf[4]

extern unsigned int SCILeLength;
extern unsigned short SW1SW2;

unsigned int G_output[100];

/************************************************* 
  Function:      cmd_Symmetry_ALG
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_Symmetry_ALG(void)
{
    INT8U ret;
    
    DES_Parameters * Demo_DES_Param;
    DES_Parameters  Demo_DES_ParamVar;
    DES3_Parameters  Demo_3DES_Param;
    SM4_Parameters  Demo_SM4_Param;
    SM1_Parameters  Demo_SM1_Param;
    AES_Parameters  Demo_AES_Param;
	SSF33_Parameters Demo_SSF33_Param;
	

    /************************************************* 
        DES/3DES/SSF33 standard data
    *************************************************/
    INT32U  std_DES_Key[4] = {0x53D6A7A9,0x0D38BC86,\
                                0x13B88389,0x963E20CB};
    INT32U  std_DES_IV[2] = {0x3DCD8D1E,0x76F1233B};
    INT32U  std_DES_InData[8] = {0xF0E5AC7F,0x803571B0,0xA7408E0C,0x378C05AE,\
                                   0xE58732C7,0xCC28A34E,0x0B52EE7A,0x8214C162};
    
    INT32U  std_DES_ECB_EncData[8] = {0x1D1A9D5A,0x7BE7C2F0,0xDD3BFC0A,0x74DBA3C3,0x5DAFFB8C,0x87286F17,0xE36194F3,0x307DFAA3};
    INT32U  std_2Key3DES_CBC_EncData[8] = {0x8E507B1D,0x81EF13C6,0x56BCF427,0x8A35434D,0xA5DB5C40,0x04B9FE12,0x5A81FED3,0x82AC8DF7};                                              
    
    INT32U  std_SM4_Key[4]= {0x53D6A7A9,0x0D38BC86,0x13B88389,0x963E20CB};    
    INT32U  std_SM4_InData[8]= {0xF0E5AC7F,0x803571B0,0xA7408E0C,0x378C05AE,0xE58732C7,0xCC28A34E,0x0B52EE7A,0x8214C162};    
    INT32U  std_SM4_ECB_EncData[8] = {0xA106CCAB,0x5FA73D12,0xD20150EB,0x3E0C3F72,0x82C19A1B,0xE04097BC,0xC1BC9F09,0x3A349EAD};        
    
    INT32U  std_SM1_Key[8] = {0x891E5349,0x9FDBE309,0x4E0E4B89,0xB40A8608,0x0,0x0,0x0,0x0};                                  
    INT32U  std_SM1_IV[4] = {0x65062726,0xBD109208,0x8ABC16A8,0xF93323E9};                           
    INT32U  std_SM1_InData[8] = {0xE8C03160,0x3EB4347F,0x7EACE55D,0x34B11E9E,0xC93C62E4,0x8A124F86,0xF8644891,0x51265DFF};
    INT32U  std_SM1_ExtMode_MACData[4] = {0x84FA74A2,0x8A5529D3,0x0C745B64,0x7CE480C8};
    
    INT32U  std_AES_Key[4] = {0xABF41AEC,0x3AD45119,0x9D86AC50,0x84346C60};                                  
    INT32U  std_AES_IV[4] = {0x9C945B04,0xCDA87AAD,0x8BBA1956,0x8F9DECFF};                           
    INT32U  std_AES_InData[8] = {0x73EECE91,0x460F6140,0x646E3486,0xC221E412,0x9F77527F,0x43687B5E,0xF8419782,0x488F6F8C};    
    INT32U  std_AES_CBC_EncData[8] = {0x0165E254,0xDFF63D63,0x1829AF44,0x000C7F9F,0x61825ABA,0x8AD476A1,0x77B6EDA0,0x8C85E4C0};    
    
	INT32U  std_SSF33_Key[4] = {0xC95310CC,0xC2B556C3,0x9C3AFB5C,0x72E94B62}; 
	INT32U  std_SSF33_InData[4] = {0x052C238A,0xCF5F00B1,0x405DEE28,0x08A766AC};
	INT32U  std_SSF33_ECB_EncData[4] = {0xCD803447,0x0EEB5773,0xDD681675,0x7B4F2ECF};
	
	
    /*1. run DES ECB_ENC */
    //1-1.config DES struct para
    Demo_DES_Param = &Demo_DES_ParamVar;
    Demo_DES_Param->iDataPtr = std_DES_InData;
    Demo_DES_Param->oDataPtr = G_output;
    Demo_DES_Param->DataLen = sizeof(std_DES_InData);
    //Demo_DES_Param->IVPtr = std_DES_IV;
    Demo_DES_Param->iKeyPtr = std_DES_Key;
    Demo_DES_Param->Type = ECB_ENCRYPT;
    
    //1-2.run DES 
    ret = HED_DESBlock(Demo_DES_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F01;
        return;
    }
    
    //1-3.check DES data
    ret = memcmp(Demo_DES_Param->oDataPtr, std_DES_ECB_EncData, sizeof(std_DES_ECB_EncData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F02;
        return;
    } 
    
    /*2. run 3DES 2KEY CBC ENC /DEC */
    //2-1.config 3DES struct para
    Demo_3DES_Param.iDataPtr = std_DES_InData;
    Demo_3DES_Param.oDataPtr = G_output;
    Demo_3DES_Param.DataLen = sizeof(std_DES_InData);
    Demo_3DES_Param.IVPtr = std_DES_IV;
    Demo_3DES_Param.iKeyPtr = std_DES_Key;
    Demo_3DES_Param.Type = CBC_ENCRYPT;
    
    //2-2.run 3DES 
    ret = HED_DES3Block(&Demo_3DES_Param);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F03;
        return;
    }
    
    //2-3.check 3DES data
    ret = memcmp(Demo_3DES_Param.oDataPtr, std_2Key3DES_CBC_EncData, sizeof(std_2Key3DES_CBC_EncData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F04;
        return;
    } 
    
    //2-4.check 3DES data Dec
    Demo_3DES_Param.iDataPtr = std_2Key3DES_CBC_EncData;
    Demo_3DES_Param.oDataPtr = G_output;
    Demo_3DES_Param.DataLen = sizeof(std_2Key3DES_CBC_EncData);
    Demo_3DES_Param.IVPtr = std_DES_IV;
    Demo_3DES_Param.iKeyPtr = std_DES_Key;
    Demo_3DES_Param.Type = CBC_DECRYPT;
    
    HED_DES3Block(&Demo_3DES_Param);
    ret = memcmp(Demo_3DES_Param.oDataPtr, std_DES_InData, sizeof(std_DES_InData));
    if (ret !=0 )
    {
        SW1SW2 = 0x6F05;
        return;
    }    
    
    /*3. run SM4 ECB, other SM4 operations is same as DES */
    Demo_SM4_Param.iDataPtr = std_SM4_InData;
    Demo_SM4_Param.oDataPtr = G_output;
    Demo_SM4_Param.DataLen = sizeof(std_SM4_InData);
    Demo_SM4_Param.iKeyPtr = std_SM4_Key;
    Demo_SM4_Param.Type = ECB_ENCRYPT;
    
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
    
    /*4. run SM1 ECB, other SM1 operations is similar */
    Demo_SM1_Param.iDataPtr = std_SM1_InData;
    Demo_SM1_Param.oDataPtr = G_output;
    Demo_SM1_Param.DataLen = sizeof(std_SM1_InData);
    Demo_SM1_Param.iKeyPtr = std_SM1_Key;
    Demo_SM1_Param.IVPtr = std_SM1_IV;
    Demo_SM1_Param.Type = MAC_EXTPARA;
    
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
    
    /*5. run AES ECB, other AES operations is similar */
    Demo_AES_Param.iDataPtr = std_AES_InData;
    Demo_AES_Param.oDataPtr = G_output;
    Demo_AES_Param.DataLen = sizeof(std_AES_InData);
    Demo_AES_Param.iKeyPtr = std_AES_Key;
    Demo_AES_Param.IVPtr = std_AES_IV;
    Demo_AES_Param.Type = CBC_ENCRYPT;
    
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

    /*6. run SSF33 ECB, other SSF33 operations is same as DES */
    Demo_SSF33_Param.iDataPtr = std_SSF33_InData;
    Demo_SSF33_Param.oDataPtr = G_output;
    Demo_SSF33_Param.DataLen = sizeof(std_SSF33_InData);
    Demo_SSF33_Param.iKeyPtr = std_SSF33_Key;
    Demo_SSF33_Param.Type = ECB_ENCRYPT;
    
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
       
    //return
    SW1SW2 = 0x9000;       
}
/************************************************* 
  Function:      cmd_CRC_Calculate
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_CRC_Calculate(void)
{
    INT16U ret;
    INT8U crcXInput[261];

    /************************************************* 
        CRC16 standard data
    *************************************************/
    const INT8U crcFInput[261] = {0xBA,0x37,0xB1,0x5A,0xCF,0xF7,0x7C,0x7D,0x0C,0xFD,0xA4,0x06,0xC2,0xA6,0x6D,0xD8,0x35,0x02,0x8D,0x5C,0x28,0x4A,0x57,0x1B,0xA7,0xA0,0x25,0x9D,0x16,0x08,0x06,0x83,\
                              0x79,0xA5,0xA7,0xE3,0x04,0x37,0x85,0xE2,0xE4,0xD3,0x52,0x96,0x4E,0xE3,0xA6,0x1D,0xC8,0x60,0xE9,0xF7,0xB6,0x4C,0x7F,0xAB,0x26,0x74,0x34,0x98,0xDF,0x66,0xE9,0x1A,\
                              0xA6,0xB0,0x7F,0xE0,0xD1,0x59,0x02,0x8B,0x10,0xA3,0x18,0x8A,0x7A,0x01,0xAA,0x33,0xD5,0x54,0xD3,0x24,0x29,0x6D,0x08,0xDB,0x86,0xBE,0x87,0x92,0x13,0x61,0x04,0x5E,\
                              0x59,0x4D,0x90,0x8A,0xD0,0xD6,0xCC,0x30,0xA9,0x64,0x4D,0x18,0xDC,0x76,0x51,0xD3,0x74,0xD9,0xA2,0x19,0x19,0x23,0xC9,0x62,0xDD,0x75,0x75,0xC2,0x4A,0x70,0x2D,0x09,\
                              0xAA,0x76,0x33,0x19,0x97,0x24,0xBA,0x88,0xC5,0x0E,0x4A,0x79,0x0E,0xBC,0x72,0xB5,0xBD,0xE4,0xAF,0x10,0x1E,0xE8,0x9A,0xF9,0x44,0x91,0x57,0x61,0x1C,0x0B,0x3C,0xD1,\
                              0xB1,0x22,0xC0,0xC5,0xC0,0xBD,0xA5,0x4C,0x7E,0x9A,0x67,0xE4,0xA6,0x4B,0xE6,0x91,0xC8,0x6F,0x51,0x3F,0xD0,0x33,0x54,0x58,0xD4,0x0A,0x85,0xA8,0x21,0xAA,0x0A,0x6F,\
                              0x86,0x49,0x8E,0xC5,0xE1,0x18,0x64,0x34,0xEA,0xFF,0xFB,0x93,0x3E,0x99,0x84,0x1F,0xAE,0x71,0xE1,0xDF,0xC7,0x7C,0xCF,0x37,0xA3,0xD9,0x56,0xCC,0xF1,0xC6,0x6F,0x9A,\
                              0x42,0xE4,0xF5,0x52,0x94,0xAE,0xD0,0xF8,0x23,0x35,0x5F,0xBC,0x6D,0x20,0x25,0x17,0x85,0xE2,0xB6,0x27,0x9B,0x3C,0xE2,0x4E,0xCB,0xF5,0x22,0x08,0x24,0xD6,0x42,0x0C,\
                              0xFB,0xEA,0x4E,0xA5,0x70}; 
    const INT8U crcFInput2[13] = {0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x11,0x22,0x33,0x44};                                
    
    #define std_CRCOutput_6363          0x8AA0
    #define std_CRCOutput_FFFF          0x2152
    #define std_CRCOutput_JAVA_TCK      0x3A2F
    
    SYSCLKEN |= BIT0;//enable CRC IP's CLK
    memcpy(crcXInput, crcFInput, sizeof(crcXInput));
        
    ret = HED_CRC16(0x6363, sizeof(crcXInput), crcXInput,2);
    if (ret != std_CRCOutput_6363)
    {
        SW1SW2 = 0x6F01;
        return;
    }
        
    ret = HED_CRC16(0xFFFF, sizeof(crcFInput), (INT8U *)crcFInput,2);
    if ((INT16U)(~ret) != std_CRCOutput_FFFF)
    {
        SW1SW2 = 0x6F02;
        return;
    }
    
    ret = HED_CRC16(0xFFFF, sizeof(crcFInput2), (INT8U *)crcFInput2,1);//fit to JC API's requirement,can pass TCK verify
    if ((INT16U)(~ret) != std_CRCOutput_JAVA_TCK)
    {
        SW1SW2 = 0x6F03;
        return;
    }
    
    SW1SW2 = 0x9000;
}
/************************************************* 
  Function:      cmd_RSA_ALG
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_RSA_ALG(void)
{
    INT8U ret;
    
    /* user should built all RSA buffers according to RSA_Parameters*/
    INT32U  Demo_RSA_e[1];
    INT32U  Demo_RSA_n[64];
    INT32U  Demo_RSA_p[32];
    INT32U  Demo_RSA_q[32];
    INT32U  Demo_RSA_dp[32];
    INT32U  Demo_RSA_dq[32];
    INT32U  Demo_RSA_qInv[32];
    INT32U  Demo_RSA_d[64];
    INT32U  Demo_RSA_preKey[134];
    INT32U  Demo_RSA_iData[64];
    INT32U  Demo_RSA_oData[64];    
    
    RSA_Info * RSA_Param;
    RSA_Info  RSA_ParamVar;


    /************************************************* 
        RSA standard data(bigEndian)
    *************************************************/
     const INT32U std_RSA_e[1] = {0x00010001};
     const INT32U std_RSA2048_p[32] = {0xAB9C27FF,0x7745BA4E,0xB2F3499E,0xB86B6F98,0x66E62F7E,0x3867198F,0x3CAB7B48,0x6CD1358B,\
                                  0x94C9352B,0xC1E19FFF,0x09B30FEF,0x5AADA132,0xD9FB9F40,0x9047DC7E,0x594168D1,0xAF9843AB,\
                                  0x8AED0357,0x4A220A7A,0x1F7F24F4,0xFDD95C3A,0xA2811AF7,0x36935D39,0x7A49A408,0x574C865E,\
                                  0x305EF0EF,0x6ABDAC25,0x4534CB92,0xDBF3A52E,0xA3283921,0x17F0C925,0xFF199A31,0xB6B13E31};        
         

    const INT32U std_RSA2048_q[32] = {0xC3AF3333,0x0BF5E51B,0xDD5629E7,0x904FD609,0xB465C676,0x49CFADA1,0x467B3C53,0x97E4F5D3,\
                                  0x12770D85,0xE3D26C38,0x8FCE0B06,0xB72A0856,0xD4E03E1D,0x7CDCE5F8,0xBE9D9EF9,0x37A08D7E,\
                                  0xD6B2A91D,0x6AC24A37,0x75148F1E,0xE17C16D7,0x58ECF7EC,0xEC314434,0xDADD6918,0x15EA58F7,\
                                  0x486EFCD2,0xB4086CBE,0x5AC73B16,0x7C5004BB,0xD6FD635A,0x5A1D069D,0x221A3DFC,0x0B992529};

    const INT32U std_RSA2048_d[64] = {0x7C72B121,0xA45321BB,0xDEA75557,0x41854F44,0x4D12AC87,0x66AC701B,0x0FC0A4AF,0x4A515F7F,\
                                  0x330A4F2F,0x720AFD8B,0x469564B1,0x7A1949C3,0xC5389DFD,0xE550A2B8,0x9C9BCC1C,0x7648F659,\
                                  0xDDC194C3,0x96FF7AC6,0xCE633687,0x478184A0,0xBD5ED586,0xFE11FA9E,0x8538E88D,0x3541A8B1,\
                                  0x7A7DCC82,0x8541DC1D,0xEB2B031A,0x02C5961C,0x39D1D2D1,0x24FF0054,0xCE114F2B,0xD5CA3EB8,\
                                  0x597B256A,0x1811BB6C,0x91ABB345,0x3E204285,0xF9F0CD1F,0x1D1BEA48,0xD488F902,0x1EF2C5DC,\
                                  0xC563BB73,0xE57163E8,0x56C59731,0xBE0E8100,0x6A9D9DD7,0x5764E34A,0xBD2EBE74,0x4A85799D,\
                                  0xEF2BBD2C,0xEE5BA2FB,0xD5278831,0x7ECF0D63,0x4710EA32,0xB61AC97A,0xBBA15B58,0x7CCFCE52,\
                                  0x80C45C75,0x97A7FDB4,0x306A7319,0x737C32F3,0xFAC8B41E,0x4D21D77A,0x79D5D429,0x0049E881};
    
    const INT32U std_RSA2048_n[64] = {0x832D6489,0x43950DFB,0x9459E42B,0x31F7943A,0xB2FEFF71,0xC806FA64,0xE692E2E4,0xCCE6CBEB,\
                                  0xD5CB659A,0xB561C85D,0xDC6B8B35,0x88A19545,0xD9027CDF,0xFBF9B138,0xFC7F6DB7,0xBB9B813E,\
                                  0xABEA847A,0x779F9811,0xCAC0F430,0x6DDB1577,0x1246829E,0xB97A1477,0x30AD83D5,0xFA1749B1,\
                                  0xA8A67895,0x73EB4537,0x8534C83D,0xFBA4620D,0x1E26E982,0xB4D87312,0x95614FD6,0x51BD39D8,\
                                  0x66C5FB03,0xFDF39C7A,0x48C6DF18,0x850A9375,0x16B9B913,0x217ACA84,0xF9E36874,0xEC64CBD6,\
                                  0xFE71810C,0xF34F37C8,0x4AD7452D,0xAB0A396B,0x9FD6B301,0xDE1B73F7,0x19F3D69D,0x483E5F3B,\
                                  0xFFB5D9F8,0xF5C4A723,0x75D57185,0x117947AE,0xAD1AF2CF,0x953BF175,0x88D06678,0x3F5D33B1,\
                                  0x51C00DD3,0x116506D1,0x8EE8786E,0xF2227676,0x1D298184,0x6E4548A9,0xBE379434,0x26A90AD9};

    const INT32U std_RSA2048_pdata[64] = {0x008CDF2F,0xD5CE12ED,0xDB4078CD,0x442D7BA2,0x6525BF95,0x98AD0275,0x3C36474D,0xFE4C333C,\
                                      0x5710B781,0x56E8EFD6,0xA0754AFF,0xB5C6ECA2,0x75CB5059,0xE20C3206,0x279AAC66,0xD9469FEA,\
                                      0x7E1254C2,0x4CE5633A,0x3283D449,0x1DBB8567,0x74E2CBA0,0xE4815CE7,0x634B6DAC,0x6F5217B0,\
                                      0x977AFF19,0x3D2D36C1,0x9A505ED4,0x02760F9A,0x6A547891,0x27754ABF,0xF82FD146,0x47D66439,\
                                      0xAC2F00AE,0xB3283015,0xDFC630C8,0xEF5E51E2,0x5F089F55,0x3251C237,0xEF30225D,0xEA3B4E2B,\
                                      0xC41B9FAA,0x353E18DB,0x09CB914C,0x69DB15E8,0x5CE68813,0x8D7B8DF7,0x4F35A618,0xDEEA9D2F,\
                                      0xE8252435,0x4CD7B8BE,0x2149CB88,0xFA552154,0x68D67BF4,0xC15D73A6,0x2025A7A0,0xAD4A19EC,\
                                      0x1F35D676,0x7E5BD664,0x2E2724A5,0x29343ECD,0x8CC0BF20,0x555E3BEC,0x6BEA6B1C,0xDEC28A0B};
  
    const INT32U std_RSA2048_cdata[64] = {0x72339510,0xB2C145BD,0xE348FFB9,0x855A43E4,0x53F2F12A,0xFCF638E2,0xBC13646F,0x3CABDA96,\
                                      0x5D04D100,0x1F579A39,0x0370A84F,0xFEC7ECCB,0x5289AF9C,0x78EB1C16,0x1006C1DD,0x3DB851B9,\
                                      0x9534B555,0x6EE0D93D,0x9C9E63B5,0xAC3FA3C2,0x23EAC0ED,0x79F28D17,0xAF3B8C70,0x1DB25DAA,\
                                      0x06AD55BC,0x03B61B64,0x5F46F7E6,0xEBF27467,0x7A7272D7,0xEB3F3605,0x2DE17B0C,0x17B4F0F3,\
                                      0xDF98977B,0x80C266A6,0x7098BC09,0x40AA1049,0x42EEF868,0x98533498,0xC8C18B8B,0x40939CB3,\
                                      0x53177411,0x59B95A4B,0xF183EE37,0x9F2268A5,0x9B286AA9,0x7EE3CDC3,0xBCB5CF84,0x099AB05A,\
                                      0x79AD814E,0x89AA90A3,0x4785A19A,0x9301CA79,0xC2315726,0x307E16EB,0xBA08BC6C,0x393034C9,\
                                      0x696B24FF,0xA128ADA0,0xE3852B15,0x0F7AF55A,0x96898D95,0xAEF6BF28,0x5C80C969,0x58FE6DC1};
    
    const INT32U std_RSA1024_pdata[32] = {0x00F6D766,0x9237C2E4,0xA2A6D2DD,0x7B12E9BD,0xA66B8E01,0x802F914A,0xF426EEB0,0x8A4FF458,\
                                      0xA11AA749,0xF8D7627B,0x746FC131,0x1D52BD89,0x69B01952,0xBDECFD1D,0x314EE197,0x93F7AD16,\
                                      0xAF1B1F71,0xCE6A6C15,0x7DCF2A55,0x905D6D02,0x6686313C,0x6D8FF887,0xE940B321,0xF2E0E693,\
                                      0xBC610887,0x1CD728D9,0x472ED6F1,0xDC1D414F,0x25569D67,0x9900C8B0,0xA6662CF8,0xAEF1E7FA};

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
    /*************************************************/    
    /*1. Known p q e run 2048 RSA */
    //1-1. load p,q,e. 
    memcpy(Demo_RSA_e,std_RSA_e,sizeof(std_RSA_e));
    memcpy(Demo_RSA_p,std_RSA2048_p,sizeof(std_RSA2048_p));
    memcpy(Demo_RSA_q, std_RSA2048_q, sizeof(std_RSA2048_q));     
   
    //1-2.  run HED_RSA_Complete  
    RSA_Param->operMode = 0x00;
    RSA_Param->len = 64;
    ret = HED_RSA2048_Complete(RSA_Param);//generate 2048 bits key
    if (ret != 0)
    {
        SW1SW2 = 0x6F00;
        return;
    } 
    //1-3.  check output n\d is correct with std data
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
    
    //1-4.  run HED_RSA_PriOpt(CRT), and check oData with std_cData
    memcpy(Demo_RSA_iData, std_RSA2048_pdata, sizeof(std_RSA2048_pdata));
    
    // Input e/n/preKey have generated by HED_RSA_Complete
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
    
    //1-5.  run HED_RSA_PubOpt , and check oData with std_pData
    memcpy(Demo_RSA_iData, std_RSA2048_cdata, sizeof(std_RSA2048_cdata));
    
    // Input such as e/n/d/dp etc. have generated by HED_RSA_Complete  
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
        
    /*2. only Known e,run 1024 RSA */
    //2-1. load e.  RSA1024 buffer length is half of RSA2048, such as Demo_RSA_n[32]
    memcpy(Demo_RSA_e, std_RSA_e, sizeof(std_RSA_e));
    
    //2-2. run HED_RSA2048_GenKey, genearte key and other para
    RSA_Param->operMode = 0x00;
    RSA_Param->len = 32;
    HED_RSA2048_GenKey(RSA_Param); 
    
    //2-3. run HED_RSA2048_PubOpt
    memcpy(Demo_RSA_iData, std_RSA1024_pdata, sizeof(std_RSA1024_pdata));    
    // Input e/n/preKey have generated by HED_RSA_GenKey. you may load it by youself with your data 
    RSA_Param->len = 32;
    ret = HED_RSA2048_PubOpt(RSA_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F07;
        return;
    }
    
    //2-4. run HED_RSA2048_PriOpt (CRT),  and check oData with std_pData
    // Input such as e/n/d/dp etc. have generated by HED_RSA2048_GenKey
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
/************************************************* 
  Function:      cmd_SM2_ALG
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_SM2_ALG(void)
{
    INT8U ret;
    
    /* user should built all SM2 buffers according with SM2_Parameters*/
__align(4) INT8U  Demo_SM2_iData[512];       //idata & odata size may be 1~65535
__align(4) INT8U  Demo_SM2_oData[256];
    INT32U Demo_SM2_RNGData[8];
    INT32U Demo_SM2_priKey[8];
    INT32U Demo_SM2_pubKey[16];
    
    SM2_Parameters * SM2_Param;
    SM2_Parameters  SM2_ParamVar;
    
    SM2KeyExch_Parameters * SM2KeyExch_Param;
    SM2KeyExch_Parameters SM2KeyExch_ParamVar;

    /************************************************* 
        SM2 standard data(bigEndian)
    *************************************************/
    const INT8U std_SM2_Prikey_d[32] = {0x9E,0x1F,0x3B,0x25,0x12,0x38,0x45,0x09,0x76,0x7D,0x7A,0x5A,0x5D,0x03,0x70,0x1F,0x26,0xA6,0x42,0x8B,0x66,0xBB,0x64,0x43,0x4D,0xC8,0x07,0x4D,0x2D,0x12,0x39,0xB3};
    const INT8U std_SM2_Pubkey[64] = {0xA8,0x8B,0xCD,0xF9,0x81,0x22,0x60,0x8F,0x18,0xB0,0x0E,0xB0,0x3A,0x41,0x0C,0xA1,0xCD,0x6D,0x7E,0x41,0x24,0x83,0x2F,0x4B,0xC6,0x63,0x86,0x1C,0x45,0xFE,0x5D,0x31,\
                                0x90,0xBE,0xE3,0x75,0x9C,0x25,0xA2,0x99,0xEF,0x39,0x7C,0x87,0xF6,0x9A,0x42,0x1C,0xE0,0xD9,0x32,0x5F,0x36,0xFC,0x0F,0x4F,0xA0,0x02,0x7B,0x30,0x12,0xF8,0xAB,0xA0};
    const INT8U std_SM2_pData[32] = {0x96,0x04,0xFC,0xBB,0x3C,0x6E,0xE8,0xB9,0x38,0xD7,0xD4,0xC2,0xF8,0x46,0xBC,0xB1,0x7C,0x0A,0xC0,0xF3,0x0A,0xA1,0x79,0x8E,0x23,0xD8,0x8D,0x62,0xB5,0x34,0x81,0xAF};
    const INT8U std_SM2_cData[128] = {0x4E,0xB7,0x39,0x93,0x6B,0x12,0x5D,0x38,0xED,0xC9,0x6B,0xEC,0x94,0x03,0x3E,0x70,0x78,0x74,0x84,0xD4,0x55,0x9A,0xF8,0xB7,0x22,0x80,0x13,0xE4,0x99,0x69,0x1F,0x83,\
                                  0x9C,0x75,0xD0,0x04,0x35,0x05,0xBA,0x10,0x0E,0xD5,0x18,0x32,0x8C,0x67,0xAC,0x13,0x74,0x0C,0x8D,0x44,0xA1,0x42,0xA6,0x81,0x4A,0x22,0x4F,0x1A,0x20,0x92,0x4B,0x25,\
                                  0xCB,0xFA,0xE9,0x58,0x88,0x7F,0x99,0xB3,0xA9,0x82,0xB3,0x46,0x92,0xBB,0x62,0xAB,0x4D,0x91,0x64,0xFA,0xE8,0x13,0xC4,0xA1,0xA2,0x9F,0x88,0x7E,0x1A,0x42,0x2C,0xD9,\
                                  0x5C,0xE9,0x46,0xBE,0xF4,0x5B,0x0A,0x62,0x6C,0xEE,0xEB,0x46,0xF0,0x10,0x79,0xA2,0x8A,0x67,0xDC,0xAF,0x3F,0xE6,0x0F,0x4B,0x7D,0x94,0x5F,0x36,0x82,0x69,0x48,0x99};
    
    const INT8U std_SM2_signingData[32] = {0xAF,0x81,0x34,0xB5,0x62,0x8D,0xD8,0x23,0x8E,0x79,0xA1,0x0A,0xF3,0xC0,0x0A,0x7C,0xB1,0xBC,0x46,0xF8,0xC2,0xD4,0xD7,0x38,0xB9,0xE8,0x6E,0x3C,0xBB,0xFC,0x04,0x96};
    const INT8U std_SM2_signingResult[64] = {0xB7,0xB2,0x7C,0x1B,0x46,0xD6,0x20,0x0F,0x03,0xEF,0x84,0xD6,0x23,0x69,0x13,0xAA,0x5D,0x77,0x65,0x9A,0x04,0x54,0x6C,0xC5,0xBF,0x71,0x6C,0x15,0x46,0xB9,0xF3,0x2A,\
                                         0x08,0x1B,0x5E,0x29,0x29,0x27,0xA8,0xFF,0x53,0x8C,0xC1,0x1B,0xED,0xAD,0x0C,0xE0,0x3D,0xA3,0x0C,0x55,0xBA,0x20,0xF8,0xD3,0x36,0xB6,0xD4,0x74,0xDB,0xC8,0x49,0x05}; 
    const INT8U std_SM2_GetZ_AID[4] = {0x03,0x36,0x36,0x93};//LV,length + value 
    const INT8U std_SM2_GetZ_Result[32] = {0xF8,0x2A,0xFE,0xF5,0xBC,0x77,0x00,0xE1,0xE6,0x58,0xFD,0xE9,0x0A,0x59,0xF1,0x31,0xA8,0x1B,0x68,0x19,0x24,0x8D,0x63,0x7E,0x8B,0x79,0xED,0x91,0x8C,0xCC,0x7E,0x6F};  
    
    const INT8U std_SM2_AID[33] = {0x20,0x19,0xAD,0x86,0xDF,0x1B,0xD6,0x7F,0x11,0x66,0x7B,0x90,0x42,0x59,0xCD,0x8D,0xFB,0x81,0xEB,0xA6,0xFC,0x05,0xC5,0x70,0x39,0x4D,0x32,0x35,0x14,0xF3,0x4F,0x7B,0xDC};//LV,length + value 
    const INT32U std_SM2_APrikey_d[8] = {0x5F16CC28,0x2485FF80,0x8D84203A,0xFCDC5C44,0x1B5F8436,0x335A7DE6,0xFC737F5E,0x33FD299D};   
    const INT32U std_SM2_APubkey[16] = {0x90F219EA,0x8B32DC5B,0x2CE29B4F,0x646AB492,0xAC4F5B3D,0x010C260B,0x777B7A3B,0x2ED8FFA7,\
                                      0x3B21C0B9,0x9734587E,0xFC86057E,0xA449EE21,0xB310BF0A,0x2AB9E48A,0x0D23075D,0xD49DD902}; 
    const INT32U std_SM2_ATempPrikey_d[8] = {0x1E817CE5,0x8B83B134,0xB2BFE0E8,0x410EA39E,0x7ECF6073,0x4E531AB1,0xFA5F81CE,0xB587F5D8};   
    const INT32U std_SM2_ATempPubkey[16] = {0x5B692DAF,0xD36B8A74,0xE3C7326C,0xCC0B1E2A,0xB0D60025,0x1A5BF0FB,0x383A5A70,0x0A7BC9C4,\
                                        0xFAF81A57,0x69625B16,0xAC952219,0xF21690CD,0x5AA51EE4,0xC7CE7869,0xF3B8E360,0xA1A3C2D6}; 
        
    const INT8U std_SM2_BID[33] = {0x20,0x19,0x46,0xCA,0xF6,0x05,0xAA,0x83,0x85,0x18,0x69,0xDD,0xBB,0x71,0xCB,0xFD,0x05,0xFC,0x27,0xFF,0x2C,0xDB,0xBF,0x07,0x47,0x16,0xE3,0x8C,0x00,0x85,0x45,0xE3,0x09};//LV,length + value 
    const INT32U std_SM2_BPrikey_d[8] = {0x70CAB6F4,0x1BD39EB8,0xFE2A995E,0x32AB4978,0xAA401F8B,0x9E0A95F6,0xF22CFA6C,0x45E8EE08};   
    const INT32U std_SM2_BPubkey[16] = {0x8D18BB94,0xE3378628,0xD413E1F4,0xCFE3D885,0xBA1AB50E,0xEB13EAD3,0x2A57DC27,0x740DFF23,\
                                    0x85380BBD,0x36791323,0xF2982E60,0xE97375E6,0x3261B99C,0x6EBE40D2,0x7CD0273F,0x2C5F933C}; 
    const INT32U std_SM2_BTempPrikey_d[8] = {0xC2B466AB,0x4B5A6442,0x670BCEB0,0x7D6F76D3,0x8713BE86,0x3ABF1275,0x27063E0E,0x461C0DBC};   
    const INT32U std_SM2_BTempPubkey[16] = {0xB264667C,0x18CECC5E,0xDC9AA242,0x2C9AE2D7,0x57A101ED,0x07029ADE,0x7973CEFF,0x102E00F5,\
                                            0x08FC95BE,0x35592981,0xF19046D6,0x0C401847,0xDD45C5FD,0x7F8A99DF,0x7D79C382,0x354ED8D4}; 
    
    const INT8U std_SM2_ExchgResult[32] = {0xC9,0x7A,0x20,0xDA,0x61,0x18,0xBD,0x0D,0x27,0xDD,0x56,0xEB,0x03,0x90,0xE8,0xFE,0xB7,0xA4,0xA9,0x4D,0x9F,0x5A,0x2D,0x04,0x19,0x92,0xED,0x58,0x32,0x69,0xA0,0x08};
    
    /*************************************************/
    SM2_Param = &SM2_ParamVar;
    SM2_Param->iDataPtr = Demo_SM2_iData;
    SM2_Param->oDataPtr = Demo_SM2_oData;
    SM2_Param->rndPtr = Demo_SM2_RNGData;
    SM2_Param->priKeyPtr = Demo_SM2_priKey; 
    SM2_Param->pubKeyPtr = Demo_SM2_pubKey; 
    SM2_Param->iEccSel = 1;     //only support Fp-256            

    /*1. generate new key ,run SM2 ENC/DEC */
    //1-1.load iData. big endian 
    memcpy(Demo_SM2_iData,std_SM2_pData,sizeof(std_SM2_pData));
    memcpy(Demo_SM2_priKey,std_SM2_Prikey_d,sizeof(std_SM2_Prikey_d));
    memcpy(Demo_SM2_pubKey,std_SM2_Pubkey,sizeof(std_SM2_Pubkey));
    
    ret = HED_SM2GenKey(SM2_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F00;
        return;
    }   
    
    // iKey have got by HED_SM2GenKey
    ret = HED_SM2Encrypt(SM2_Param, sizeof(std_SM2_pData)); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F01;
        return;
    }
    
    // set HED_SM2Encrypt oData to HED_SM2Decrypt iData
    memcpy(Demo_SM2_iData, Demo_SM2_oData, sizeof(std_SM2_pData)+96);
    ret = HED_SM2Decrypt(SM2_Param, sizeof(std_SM2_pData)+96); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F02;
        return;
    } 
    
    // check HED_SM2Decrypt oData with std_SM2_pData
    if (memcmp(Demo_SM2_oData, std_SM2_pData, sizeof(std_SM2_pData)) != 0)
    {
        SW1SW2 = 0x6F03;
        return;
    }  
    
    /*2. key Known ,run SM2 signing/verify and GetZ /SM2Decrypt */
    // 2-1.load iData. big endian  
    memcpy(Demo_SM2_iData, std_SM2_signingData, sizeof(std_SM2_signingData));    
    // load ikey D 
    memcpy(Demo_SM2_priKey, std_SM2_Prikey_d, sizeof(std_SM2_Prikey_d));    
    // load ikey x,y 
    memcpy(Demo_SM2_pubKey, std_SM2_Pubkey, sizeof(std_SM2_Pubkey));
    
    //2-2. run HED_SM2Sign
    ret = HED_SM2Sign(SM2_Param);
    if (ret != 0)
    {
        SW1SW2 = 0x6F04;
        return;
    } 
    
    // run HED_SM2Verify .
    ret = HED_SM2Verify(SM2_Param); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F05;
        return;
    } 
    
    //2-3.  load std data to verify HED_SM2Verify. idata have loaded.
    memcpy(Demo_SM2_oData, std_SM2_signingResult, sizeof(std_SM2_signingResult));
    //signingResult =R + S
    ret = HED_SM2Verify(SM2_Param); 
    if (ret != 0)
    {
        SW1SW2 = 0x6F06;
        return;
    } 
    
    //2-4. run GetZ, other para have loaded above.
    memcpy(Demo_SM2_iData, std_SM2_GetZ_AID, sizeof(std_SM2_GetZ_AID));
    ret = HED_SM2GetZ (std_SM2_GetZ_AID, Demo_SM2_pubKey,(INT32U *)Demo_SM2_oData, 1);
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
    
    //2-5. run SM2Decrypt, get pData.
    //load cData
    memcpy(Demo_SM2_iData, std_SM2_cData,64);//c1_x,c1_y
    memcpy(Demo_SM2_iData+32*2,std_SM2_cData+32*2,32);//c3
    memcpy(Demo_SM2_iData+32*2+sizeof(std_SM2_pData),std_SM2_cData+32*2+sizeof(std_SM2_pData),sizeof(std_SM2_pData));//c2
    
    ret = HED_SM2Decrypt(SM2_Param, sizeof(std_SM2_pData)+96);
    if (ret != 0)
    {
        SW1SW2 = 0x6F09;
        return;
    } 
    
    // check HED_SM2Decrypt oData with std_SM2_pData
    if (memcmp(Demo_SM2_oData, std_SM2_pData, sizeof(std_SM2_pData)) != 0)
    {
        SW1SW2 = 0x6F0A;
        return;
    }
    
    /*3. all key Known,run HED_SM2KeyExchange */
    #define SENDER      1
    #define RECEIVER    0
    //3-1. A is organiger(sender)
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
    SM2KeyExch_Param->DataType = SENDER;//(sender)
    SM2KeyExch_Param->iEccSel = 1;//Fp-256
    
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
    
    //3-2. B is organiger(receiver)    
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
    SM2KeyExch_Param->DataType = RECEIVER;//(receiver)
    SM2KeyExch_Param->iEccSel = 1;//Fp-256    
    
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
/************************************************* 
  Function:      cmd_HASH_ALG
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_HASH_ALG(void)
{
    INT32U  out_hash160_v[7];
    INT32U  out_hash256_v[10];
    INT32U  out_SM3_v[9];
    INT32U len;
    INT32U * inPtr;
    INT8U ret;
    
    /************************************************* 
        SHA1\SHA256\SM3 standard data
    *************************************************/    
__align(4)    INT8U  std_SHA1_inputLess64[58] = {0x0A,0x0F,0xEA,0xAA,0x53,0x66,0x5D,0x4C,0x8C,0xB3,0x85,0x66,0xDF,0x4E,0xE6,0x1F,0x27,0x3B,0xB6,0x34,0x83,0x42,0x41,0x58,0x08,0x17,0x3C,0x55,0x95,0x4B,0xFE,0x8E,\
                                         0xC5,0xCB,0xBA,0xF6,0x76,0xB8,0x02,0xAB,0xD8,0x94,0x45,0x88,0x4C,0x69,0x7F,0x80,0x81,0x52,0x1C,0x0B,0x4A,0x88,0x30,0x0E,0x25,0x46};
__align(4)    INT8U  std_SHA1_outputLess64[20] = {0x34,0x8C,0x74,0xD1,0xEE,0xB3,0x33,0x49,0x9B,0x8F,0xE2,0xC2,0xD0,0x5D,0xBF,0xD0,0x9B,0xA3,0x6D,0x2A};
    
__align(4)    INT8U  std_SHA_inputMore64[132] = {0xF4,0x4C,0x7D,0x4F,0x8D,0xF0,0xFD,0x73,0xE8,0x15,0x6A,0x23,0x26,0x0B,0x04,0x05,0x3A,0x16,0xF0,0x79,0x4E,0xB1,0x06,0xE5,0x95,0x4E,0x32,0xEE,0x48,0xD8,0x6C,0x2A,\
                                         0xD8,0xA2,0x38,0xDF,0x6A,0x5D,0x07,0xD6,0x88,0x13,0xBD,0x8A,0xAD,0x63,0x55,0xFD,0x0A,0x2A,0xDA,0x8F,0x74,0xB7,0x89,0x1A,0xC8,0x42,0x24,0x72,0xB9,0x90,0xFC,0x2A,\
                                         0xE8,0x8B,0x62,0xC4,0xD0,0x0E,0xC1,0x89,0x3C,0xBD,0x24,0xE9,0xCE,0xC1,0x6A,0xD3,0x59,0xC7,0xDB,0x27,0xD0,0x49,0x19,0x65,0xC8,0x10,0x2C,0x87,0xE4,0x18,0xCC,0x1C,\
                                         0x11,0xED,0x99,0xB6,0xF9,0x99,0xF9,0xEE,0xCC,0xBF,0x7E,0xE7,0xD4,0x3A,0x30,0xFA,0xAA,0xAE,0xF4,0x26,0x38,0xD4,0x7D,0xAA,0x55,0xB1,0x8E,0xC5,0x70,0x22,0x34,0xB8,\
                                         0x0D,0x18,0x68,0x67};
__align(4)    INT8U  std_SHA1_input64[64] = {0x0A,0x0F,0xEA,0xAA,0x53,0x66,0x5D,0x4C,0x8C,0xB3,0x85,0x66,0xDF,0x4E,0xE6,0x1F,0x27,0x3B,0xB6,0x34,0x83,0x42,0x41,0x58,0x08,0x17,0x3C,0x55,0x95,0x4B,0xFE,0x8E,\
                                         0xC5,0xCB,0xBA,0xF6,0x76,0xB8,0x02,0xAB,0xD8,0x94,0x45,0x88,0x4C,0x69,0x7F,0x80,0x81,0x52,0x1C,0x0B,0x4A,0x88,0x30,0x0E,0x25,0x46,0x00,0x00,0x00,0x00,0x00,0x00};
__align(4)    INT8U  std_SHA1_outputMore64[20] = {0xFB,0x74,0xDD,0xEB,0xDB,0x40,0x34,0x5C,0x10,0xC0,0x09,0x8B,0x80,0x3D,0x25,0x35,0xF1,0xB9,0x43,0xD6};    
__align(4)    INT8U  std_SHA256_outputMore64[32] = {0x39,0x21,0xE9,0x5E,0xCA,0xE2,0x33,0xB3,0x2C,0xB8,0x48,0xFC,0x45,0xF3,0x89,0xA7,0x84,0xF1,0x78,0x7B,0xF2,0x41,0x2E,0x9D,0x49,0x25,0xDB,0x23,0x4A,0x4A,0xDE,0xA1};
    
__align(4)    INT8U   std_SM3_inputMore64[97] = {0x56,0xBB,0xAD,0x9F,0x88,0xD3,0xAC,0x07,0x58,0xC4,0xED,0x64,0xD2,0xEF,0x4A,0xA9,0x77,0x3A,0xC6,0xB8,0x74,0xFA,0xEA,0xF6,0x23,0x22,0x5F,0x0E,0xC6,0xAB,0xCE,0x03,\
                                         0x81,0x45,0xF6,0x7A,0x98,0x3E,0x0E,0x48,0xE8,0xB2,0x5B,0x39,0xAA,0xF2,0x14,0x22,0x65,0x38,0x74,0x28,0x32,0x8B,0x1F,0x51,0x36,0xEF,0xB8,0x4A,0x5B,0xCF,0xC2,0x79,\
                                         0x50,0xAE,0xB6,0x44,0xC3,0x0B,0x64,0xA2,0xDB,0x94,0x8D,0xE2,0xFA,0x8D,0xC0,0xBA,0xB3,0x81,0x73,0x92,0x08,0x2A,0x64,0x11,0xE7,0x9C,0x31,0xE6,0xE6,0xB7,0x34,0xDA,\
                                         0x3C};
__align(4)    INT8U  std_SM3_outputMore64[32] ={0x7C,0xF6,0x13,0x49,0x75,0xB9,0xD6,0x77,0x47,0x2B,0x98,0x4C,0xBE,0x4A,0xD2,0x60,0xFC,0x8A,0x37,0xAD,0x3E,0x96,0x4E,0xA6,0xE2,0x02,0xC5,0xB9,0xE2,0x97,0x26,0x44};

    /*1. SHA1 , data length less than 64Bytes */
    //1-1.run these sha1 fun
    HED_SHA1_Init(out_hash160_v);
    HED_SHA1_Block(out_hash160_v,(INT32U *)std_SHA1_inputLess64,sizeof(std_SHA1_inputLess64));
    
    //1-2.check sha1 output data
    ret = memcmp(out_hash160_v, std_SHA1_outputLess64, 20);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F01;
        return;
    }
    
    /*2. SHA1 , data length more than 64Bytes */    
    len = sizeof(std_SHA_inputMore64);    
    HED_SHA1_Init(out_hash160_v);                  //init
    inPtr = (INT32U *)std_SHA_inputMore64;
    for(;len >= 64;)
    {
        HED_SHA1_Block(out_hash160_v,inPtr,64);         //ProcBlock
        len -=64;
        inPtr += 16;
    }
    HED_SHA1_Block(out_hash160_v,inPtr,len);       //FinalBlock
    
    ret = memcmp(out_hash160_v, std_SHA1_outputMore64, 20);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F02;
        return;
    }

    /*3. SHA1 , data length equal to 64Bytes */
    inPtr = (INT32U *)std_SHA1_input64;
    HED_SHA1_Init(out_hash160_v);
    HED_SHA1_Block(out_hash160_v,inPtr,64);         //ProcBlock
    HED_SHA1_Block(out_hash160_v,inPtr+16,0);      //FinalBlock
    
    /*4. SHA256 , data length more than 64Bytes */    
    len = sizeof(std_SHA_inputMore64);    
    HED_SHA256_Init(out_hash256_v);                  //init
    inPtr = (INT32U *)std_SHA_inputMore64;
    for(;len >= 64;)
    {
        HED_SHA256_Block(out_hash256_v,inPtr,64);         //ProcBlock
        len -=64;
        inPtr += 16;
    }
    HED_SHA256_Block(out_hash256_v,inPtr,len);       //FinalBlock
    
    ret = memcmp(out_hash256_v, std_SHA256_outputMore64, 32);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F03;
        return;
    }

    /*5. SHA256 , data length equal to 64Bytes */
    inPtr = (INT32U *)std_SHA1_input64;
    HED_SHA256_Init(out_hash256_v);
    HED_SHA256_Block(out_hash256_v,inPtr,64);         //ProcBlock
    HED_SHA256_Block(out_hash256_v,inPtr+16,0);      //FinalBlock
    
    /*6. SM3 , data length more than 64B */
    len = sizeof(std_SM3_inputMore64);    
    HED_SM3Initial(out_SM3_v);                  //init
    inPtr = (INT32U *)std_SM3_inputMore64;
    for(;len >= 64;)
    {
        HED_SM3Block(out_SM3_v,inPtr,64);         //ProcBlock
        len -=64;
        inPtr += 16;
    }
    HED_SM3Block(out_SM3_v,inPtr,len);       //FinalBlock
    ret = memcmp(out_SM3_v, std_SM3_outputMore64, 32);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F04;
        return;
    }
    
    SW1SW2 = 0x9000;
}
/************************************************* 
  Function:      cmd_GET_INFO
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_GET_INFO(void)
{
    INT8U p3,ret;
    
    /*no check P3 ,user can add it */    
    p3 = APDU_P3;
    SendINS(APDU_INS);//send INS
    
    /* according to P1, do*/
    switch (APDU_P1)
    {
        case 0x01:
            ret = HED_RNG1Check();//RNG1 self-check if neccessary
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
/************************************************* 
  Function:      cmd_NVM_ErWr
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_NVM_ErWr(void)
{
    INT32U NVMAddr,ret;
    INT32U  i;
    INT32U  DataToNVM[128];
    INT8U * ptr;    
    
    SendINS(APDU_INS);//send INS       
    while(G_SCIRecieveIndex != (5+APDU_P3));
    
    if(APDU_P3 < 0x04)
    {
        SW1SW2 = 0x6F01;
        return;
    }    
    
    memcpy(DataToNVM,SCIAPDUBuf+5+4,APDU_P3-4);
    
    NVMAddr = ((INT32U)SCIAPDUBuf[5])<<24 | ((INT32U)SCIAPDUBuf[6])<<16 | ((INT32U)SCIAPDUBuf[7])<<8 | SCIAPDUBuf[8];//NVM OPERATION ADDRESS
    NVMAddr &= ~0x1FF;//page aligned
    /*NVM address valid or not*/
    if((NVMAddr < DemoNVM_START_ADDR) || (NVMAddr >= DemoNVM_END_ADDR))
    {
        SW1SW2 = 0x6F01;
        return;
    }   
    
    ptr = (INT8U *)DataToNVM;
    for(i=APDU_P3-4;i<0x200;i++)
    {
        *(ptr+i) = 0xFF;//padding data
    }
    
     /*NVM API's para DataLen means word number */
     /*CHIP's NVM ADDR start at 0x0,but Demo only cover 200k-400k*/
    
    do
    {
        ret = HED_FlashPageInit_St(NVMAddr);
        ret |= HED_FlashErWrPage_St(NVMAddr,DataToNVM);
    }while(ret == ~0);
    
    ret = memcmp((INT8U *)DataToNVM, (INT8U *)NVMAddr, 0x200);
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
    HED_HEFlashEWPage(HEFlash_Addr,DataToNVM);     
    ret = memcmp((INT8U *)DataToNVM, (INT8U *)HEFlash_Addr, 0x200);
    if (ret !=0 )
    {
        SW1SW2 = 0x6F03;
        return;
    }
        
    SW1SW2 = 0x9000;
}
/************************************************* 
  Function:      cmd_back2Loader
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_back2Loader(void)
{
    INT32U  DataToNVM[128];
    
    memcpy((INT8U*)DataToNVM,(INT8U*)Card_Status_ADDR,0x200);
    DataToNVM[0] = 0xB639A527;
    
    HED_FlashErWrPage_St(Card_Status_ADDR,DataToNVM);
    SW1SW2 = 0x9000;
}
/************************************************* 
  Function:      cmd_M1_Opt
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void cmd_M1_Opt(void)
{
	INT8U result;
	INT32U block0Data[4]={0x00010203, 0x04050607, 0x08090A0B, 0x0C0D0E0F};
	INT32U pwData[6]={0x0B545707, 0X45FE3AE7, 0x01020304, 0X05060708, 0x090a0B0C, 0X0D0E1F23};
	INT32U pwData2[6]={0x0B545707, 0X45FE3AE7, 0x0, 0x0, 0x0, 0x0};
	
	G_cM1_PwAlgType = 0;//M1 Standard PassWord Algorithm type

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
/****************************************************************************
  Function:      cmd_TerminalCapa
  Description:   be careful before running this APDU on Develepment Tool ,because this APDU lead to high currency on Pad C6
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void cmd_TerminalCapa(void)
{
    SendINS(APDU_INS);
    while(G_SCIRecieveIndex != 5+APDU_P3);

    if (SYSINFST & BIT2)//swp interface not detected
    {		
        SYSPUDCON |= BIT30;
        SYSCLKCLR |= BIT20;		
    }
    SW1SW2 = 0x9000;
}
/****************************************************************************
  Function:      cmd_getResponse
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void cmd_getResponse(void)
{
	INT32U i;

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
    SendINS(0xC0);//case 2 APDU
    SW1SW2 = 0x9000;
}
/****************************************************************************
  Function:      cmd_selectFile
  Description:    
  Input:           
  Output:         
  Return:        
  Others:                            
****************************************************************************/
void cmd_selectFile(void)
{
    SendINS(APDU_INS);
    while(G_SCIRecieveIndex != 5+APDU_P3);	    
	if(SCIAPDUBuf[4] == 0x02)
    {
        SW1SW2 = 0x6115; 
    }
    else
    {
        SW1SW2 = 0x9000; 
    }
}
//command list
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
/************************************************* 
  Function:      SCIAPDU_Dispatch
  Description:    
  Input:           
  Output:         
  Return:        
  Others:      
*************************************************/
void SCIAPDU_Dispatch(void)
{
    INT8U i;
    
	SW1SW2 = 0x6D00;
    SCILeLength = 0x00;    
    
    for(i=0;i<(sizeof(CMD_INSList)/sizeof(COMMANDLIST));i++)
    {
    	if(CMD_INSList[i].ins == APDU_INS)
    	{
    		CMD_INSList[i].func();
    		break;
    	}                           			
    }
    
    SCI_WaitRx(0x00);//prepare to Rx next APDU
    SCI_StopTx60();
	SCI_StartTx_INT(0);//Tx Le data or SW1SW2 in int mode    
}

