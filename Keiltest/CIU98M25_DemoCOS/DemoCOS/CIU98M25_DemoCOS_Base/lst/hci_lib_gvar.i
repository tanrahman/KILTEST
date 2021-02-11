#line 1 "API\\HCI_lib_GVar.c"












 
#line 1 "API\\../inc/CIU98M25_SFR_C.h"









 






 


 






 

#line 35 "API\\../inc/CIU98M25_SFR_C.h"


#line 46 "API\\../inc/CIU98M25_SFR_C.h"


#line 55 "API\\../inc/CIU98M25_SFR_C.h"







#line 69 "API\\../inc/CIU98M25_SFR_C.h"






#line 89 "API\\../inc/CIU98M25_SFR_C.h"



 







 
#line 109 "API\\../inc/CIU98M25_SFR_C.h"



 
#line 121 "API\\../inc/CIU98M25_SFR_C.h"



 
#line 133 "API\\../inc/CIU98M25_SFR_C.h"



 
#line 158 "API\\../inc/CIU98M25_SFR_C.h"



 
#line 171 "API\\../inc/CIU98M25_SFR_C.h"



 
#line 201 "API\\../inc/CIU98M25_SFR_C.h"



 

#line 233 "API\\../inc/CIU98M25_SFR_C.h"



 
#line 252 "API\\../inc/CIU98M25_SFR_C.h"

#line 15 "API\\HCI_lib_GVar.c"













 
__attribute__((zero_init)) unsigned char G_SYNC_PARA;







 
__attribute__((zero_init)) unsigned char G_CmptblCtrl;









 
unsigned short G_triggerResult;















 
__align(4) unsigned char G_APDUBuf[264];


unsigned short G_APDULen;









 
unsigned char G_APDUGateBuf[261];


unsigned short G_APDUGateLen;













 
unsigned int G_AppOpenSta;


__attribute__((zero_init)) unsigned char G_bSWP_DetectStatus;


unsigned char G_HCIMode;


__attribute__((zero_init)) unsigned char G_bSWP_busy;


__attribute__((zero_init)) unsigned char G_bCLKSwitchValid;


unsigned char G_ReaderTimerOutInteger;







 
unsigned char G_appMode;










 
unsigned short G_RFType;






 
unsigned char G_bFstAPDU;

























 
unsigned char G_SetParaBuf[20];

























 
unsigned char G_GetParaBuf[20]; 





 
unsigned char G_bRFIndicator; 




 
unsigned char G_bAPPSendType;







 
unsigned char G_GetRFType;



const unsigned char pReg_ID_Gate_VerSW[4] = {0x03,0x01,0x00,0x00};
const unsigned char pReg_ID_Gate_VerHard[4] = {0x03,0x00,0x00,0x00};
const unsigned char pReg_ID_Gate_Vendor_Name[4] = {0x03,0x48,0x45,0x44};
const unsigned char pReg_ID_Gate_Model_ID[2] = {0x01,0x00};


 

__attribute__((zero_init)) unsigned char aReg_CardRFTypeA_UID[5]; 
unsigned char aReg_CardRFTypeA_SAK[2] = {0x01,0x28}; 
unsigned char aReg_CardRFTypeA_ATQA[3] = {0x02,0x04,0x01}; 
unsigned char aReg_CardRFTypeA_History[7] = {0x06,0x81,0x17,0x01,0x0D,0x10,0x00};
unsigned char aReg_CardRFTypeA_TB1[2] = {0x01,0x81};
unsigned char aReg_CardRFTypeA_MAXDataRate[4] = {0x03,0x00,0x00,0x00};
unsigned char aReg_CardRFTypeA_CID_SUPPORT[2] = {0x01,0x00};

unsigned char aReg_ReaderRFTypeA_MAXDataRate [2] = {0x01,0x03};

unsigned char aReg_CardRFTypeB_AFI[2] = {0x01,0x00};
unsigned char aReg_CardRFTypeB_ATQB[5] = {0x04,0x00,0x00,0x00,0x84};
unsigned char aReg_CardRFTypeB_MAXDataRate[4] = {0x03,0x00,0x00,0x00}; 



unsigned char aReg_ReaderRFTypeA_UID[11] = {0x0A, 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A};
unsigned char aReg_ReaderRFTypeA_SAK[2] = {0x01,0x00};
unsigned char aReg_ReaderRFTypeA_ATQA[3] = {0x02,0x00,0x00};  
unsigned char aReg_ReaderRFTypeA_History[16] = {0x0F,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
unsigned char aReg_ReaderRFTypeA_TB1[2] = {0x01,0x00};



unsigned char pReg_APDU_App_Gate_ATR[9] = {0x08,0x3B,0x06,0x81,0x17,0x01,0xDD,0xB0,0x16};



 
const unsigned int HCIConfig_ADRESS = 0x11BE00;
