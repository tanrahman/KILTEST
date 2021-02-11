#line 1 "API\\CIU98M25_API_NVM_STABILITY.c"










 
#line 1 ".\\INC\\CIU98M25_SFR_C.H"









 






 


 






 

#line 35 ".\\INC\\CIU98M25_SFR_C.H"


#line 46 ".\\INC\\CIU98M25_SFR_C.H"


#line 55 ".\\INC\\CIU98M25_SFR_C.H"







#line 69 ".\\INC\\CIU98M25_SFR_C.H"






#line 89 ".\\INC\\CIU98M25_SFR_C.H"



 







 
#line 109 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 121 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 133 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 158 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 171 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 201 ".\\INC\\CIU98M25_SFR_C.H"



 

#line 233 ".\\INC\\CIU98M25_SFR_C.H"



 
#line 252 ".\\INC\\CIU98M25_SFR_C.H"

#line 13 "API\\CIU98M25_API_NVM_STABILITY.c"



#line 24 "API\\CIU98M25_API_NVM_STABILITY.c"

#line 31 "API\\CIU98M25_API_NVM_STABILITY.c"

typedef enum
{
    SYSNVMSTATUS_EPP = 0,
    SYSNVMSTATUS_EINT = 1,
    SYSNVMSTATUS_ABORTFLAG = 8,   
    SYSNVMSTATUS_VERIERR = 9,
    SYSNVMSTATUS_VERICRCERR = 10,
    SYSNVMSTATUS_ECCERR1 = 24,
    SYSNVMSTATUS_ALLONE = 27,
    SYSNVMSTATUS_SDPERR = 31,
}SYSNVMSTATUS_BITS;

#line 50 "API\\CIU98M25_API_NVM_STABILITY.c"




extern void setWrMode(unsigned int wrMode);










  
void FLSHOprtInPage(unsigned int DestAddr,unsigned int * SrcAddr,unsigned int OprtMode)
{
    unsigned int i;
    
    do
    {
        ((*((volatile unsigned long *)(0x50007000 + 0x80 ))) &= ~(1 << (SYSNVMSTATUS_ABORTFLAG)));
        __disable_irq();
        (*((volatile unsigned long *)(0x50007000 + 0xA0 ))) = (*((volatile unsigned long *)(0x50007000 + 0x30 )));
        (*((volatile unsigned long *)(0x50007000 + 0xA4 ))) = (*((volatile unsigned long *)(0x50007000 + 0x34 )));
        (*((volatile unsigned long *)(0x50007000 + 0xA8 ))) = (*((volatile unsigned long *)(0x50007000 + 0x38 )));

        if(OprtMode == 0x02)
        {
            ;
        }
        else if((OprtMode == 0x09) || (OprtMode == 0x0A))
        {
            *((unsigned int*)DestAddr) = ~0;
        }
        else
        {
            if(SrcAddr == 0)
            {
                for(i=0;i<(0x200>>2);i++)
                {
                    *((unsigned int*)DestAddr + i) = ~0;
                }    
            }
            else
            {
                for(i=0;i<(0x200>>2);i++)
                {
                    *((unsigned int*)DestAddr + i) = *(SrcAddr + i);
                } 
            }
        }

        
        setWrMode(0x57AF6C00 | OprtMode);
        while(((*((volatile unsigned long *)(0x50007000 + 0x80 ))) & (1 << (SYSNVMSTATUS_EPP))));
        __enable_irq();
    }while(((*((volatile unsigned long *)(0x50007000 + 0x80 ))) & (1 << (SYSNVMSTATUS_ABORTFLAG))));
}








      
unsigned int HED_FlashPageInit_St (unsigned int DestAddr)
{
    DestAddr &= ~0x1FF;

    FLSHOprtInPage(DestAddr,(unsigned int *)0,0x05);
    
    if(((*((volatile unsigned long *)(0x50007000 + 0x80 ))) & (1 << (SYSNVMSTATUS_VERIERR))))
    {
        ((*((volatile unsigned long *)(0x50007000 + 0x80 ))) &= ~(1 << (SYSNVMSTATUS_VERIERR)));
        return ~0;
    }
        
    return 0x00;
}  








      
unsigned int HED_FlashErWrPage_St(unsigned int DestAddr,unsigned int * SrcAddr)
{
    DestAddr &= ~0x1FF;

    FLSHOprtInPage(DestAddr,SrcAddr,0x05);
    
    if(((*((volatile unsigned long *)(0x50007000 + 0x80 ))) & (1 << (SYSNVMSTATUS_VERIERR))))
    {
        ((*((volatile unsigned long *)(0x50007000 + 0x80 ))) &= ~(1 << (SYSNVMSTATUS_VERIERR)));
        return ~0;
    }
        
    return 0x00;
}  








      
void HED_FlashPageBufClr(void)
{    
    FLSHOprtInPage(0,(unsigned int *)0,0x02); 
}

