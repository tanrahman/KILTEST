/******************** (C) COPYRIGHT 2014 HED *************************************
* File Name          : CIU98M25_SFR_C.h
* Author             : lursh
* Date First Issued  : 2014-12-1
* Description        : This file describes the register map of CIU98M25
// ------------------------------------------------------------
// Modification History:
// Version    Date       Author    Modification Description
// V0.0      2014-12-1   lursh     initial version
*********************************************************************************/

#ifndef __IO_CIU98M25_H
#define __IO_CIU98M25_H

/********************************************************************************
                      AMBA IP AHB Peripherals Addresse
********************************************************************************/
/********************************************************************************
                             CRC Regsiter
********************************************************************************/
#define CRCCSR               (*((volatile unsigned long *)(0x50005000 + 0x00 )))
#define CRCDATA              (*((volatile unsigned long *)(0x50005000 + 0x04 )))
#define CRCIV                (*((volatile unsigned long *)(0x50005000 + 0x08 )))

/********************************************************************************
                             SystemController Regsiter
********************************************************************************/
// EMMU
#define SYSEMMUCON           (*((volatile unsigned long *)(0x50007000 + 0x1C )))
#define SYSCMSBCS            (*((volatile unsigned long *)(0x50007000 + 0x20 )))
#define SYSNVMDEADDR         (*((volatile unsigned long *)(0x50007000 + 0x28 )))
#define SYSSWITCHTAG1        (*((volatile unsigned long *)(0x50007000 + 0x30 )))
#define SYSSWITCHTAG2        (*((volatile unsigned long *)(0x50007000 + 0x34 )))
#define SYSSWITCHTAG3        (*((volatile unsigned long *)(0x50007000 + 0x38 )))

// NVM
#define SYSNVMSTATUS         (*((volatile unsigned long *)(0x50007000 + 0x80 )))
#define SYSNVMMODE           (*((volatile unsigned long *)(0x50007000 + 0x84 )))
#define SYSNVMCON            (*((volatile unsigned long *)(0x50007000 + 0x88 )))
#define SYSVERIERRADDR       (*((volatile unsigned long *)(0x50007000 + 0x8C )))
#define SYSNVMABTADDR        (*((volatile unsigned long *)(0x50007000 + 0x90 )))
#define SYSNVMSDPK1          (*((volatile unsigned long *)(0x50007000 + 0xA0 )))
#define SYSNVMSDPK2          (*((volatile unsigned long *)(0x50007000 + 0xA4 )))
#define SYSNVMSDPK3          (*((volatile unsigned long *)(0x50007000 + 0xA8 )))
#define SYSECCSTADDR         (*((volatile unsigned long *)(0x50007000 + 0xEC )))

// RSTMU
#define SYSINFST             (*((volatile unsigned long *)(0x50007000 + 0x180)))
#define SYSRSTFLAG           (*((volatile unsigned long *)(0x50007000 + 0x184)))
#define SYSRSTCFG            (*((volatile unsigned long *)(0x50007000 + 0x188)))
#define SYSINTCLR            (*((volatile unsigned long *)(0x50007000 + 0x190)))
#define SYSPUDCON            (*((volatile unsigned long *)(0x50007000 + 0x194)))
#define SYSVDFLAG            (*((volatile unsigned long *)(0x50007000 + 0x198)))
#define SYSINFCON            (*((volatile unsigned long *)(0x50007000 + 0x19C)))

// CKMU
#define SYSCLKEN             (*((volatile unsigned long *)(0x50007000 + 0x200)))
#define SYSCLKCLR            (*((volatile unsigned long *)(0x50007000 + 0x204)))
#define SYSCLKCFG            (*((volatile unsigned long *)(0x50007000 + 0x208)))

// POWMU
#define SYSPCON1             (*((volatile unsigned long *)(0x50007000 + 0x280)))
#define SYSPCON3             (*((volatile unsigned long *)(0x50007000 + 0x288)))
#define SYSWKPCALIB          (*((volatile unsigned long *)(0x50007000 + 0x28C)))
#define SYSWKPCON            (*((volatile unsigned long *)(0x50007000 + 0x290)))
#define SYSVR12PB            (*((volatile unsigned long *)(0x50007000 + 0x294)))
#define SYSNVMVR12PB         (*((volatile unsigned long *)(0x50007000 + 0x298)))
#define SYSVR18PB            (*((volatile unsigned long *)(0x50007000 + 0x29C)))

// INTC
#define SYSIRQLR             (*((volatile unsigned long *)(0x50007000 + 0x380)))
#define SYSNMICON            (*((volatile unsigned long *)(0x50007000 + 0x384)))

// SEC
#define SECCTR               (*((volatile unsigned long *)(0x50007000 + 0x400)))
#define SECMEINIH            (*((volatile unsigned long *)(0x50007000 + 0x404)))
#define SECMEINIL            (*((volatile unsigned long *)(0x50007000 + 0x408)))
#define SECPKEMEINI          (*((volatile unsigned long *)(0x50007000 + 0x410)))
#define SECPKEADMESS         (*((volatile unsigned long *)(0x50007000 + 0x414))) 
#define SECSWRSTFLG          (*((volatile unsigned long *)(0x50007000 + 0x418)))
#define SECHWRSTFLG          (*((volatile unsigned long *)(0x50007000 + 0x41C)))
#define SECBUSY              (*((volatile unsigned long *)(0x50007000 + 0x420)))
#define SECRBCLR             (*((volatile unsigned long *)(0x50007000 + 0x424)))
#define SECREGPRT            (*((volatile unsigned long *)(0x50007000 + 0x428)))
#define SECSWCES             (*((volatile unsigned long *)(0x50007000 + 0x42C)))
#define SECAUTOCHK           (*((volatile unsigned long *)(0x50007000 + 0x430)))
#define SECRNDSTOP           (*((volatile unsigned long *)(0x50007000 + 0x434)))
#define SECTESTPRST          (*((volatile unsigned long *)(0x50007000 + 0x47C)))

/********************************************************************************
                             WDT Regsiter
********************************************************************************/
#define WDTLOAD              (*((volatile unsigned long *)(0x40000000 + 0x00 )))
#define WDTVALUE             (*((volatile unsigned long *)(0x40000000 + 0x04 )))
#define WDTCONTROL           (*((volatile unsigned long *)(0x40000000 + 0x08 )))
#define WDTIS                (*((volatile unsigned long *)(0x40000000 + 0x0C )))

/********************************************************************************
                             TIMER Regsiter
********************************************************************************/
#define TIMER0LOAD           (*((volatile unsigned long *)(0x40000800 + 0x00 )))
#define TIMER0VALUE          (*((volatile unsigned long *)(0x40000800 + 0x04 )))
#define TIMER0CONTROL        (*((volatile unsigned long *)(0x40000800 + 0x08 )))
#define TIMER0IS             (*((volatile unsigned long *)(0x40000800 + 0x0C )))
#define TIMER1LOAD           (*((volatile unsigned long *)(0x40000800 + 0x20 )))
#define TIMER1VALUE          (*((volatile unsigned long *)(0x40000800 + 0x24 )))
#define TIMER1CONTROL        (*((volatile unsigned long *)(0x40000800 + 0x28 )))
#define TIMER1IS             (*((volatile unsigned long *)(0x40000800 + 0x2C )))

/********************************************************************************
                             SCI Regsiter
********************************************************************************/
#define SCISBUF              (*((volatile unsigned long *)(0x40001000 + 0x00 )))
#define SCISCON              (*((volatile unsigned long *)(0x40001000 + 0x04 )))
#define SCISSR               (*((volatile unsigned long *)(0x40001000 + 0x08 )))
#define SCISCNT              (*((volatile unsigned long *)(0x40001000 + 0x0C )))
#define SCITXFCR             (*((volatile unsigned long *)(0x40001000 + 0x10 )))
#define SCIRXFCR             (*((volatile unsigned long *)(0x40001000 + 0x14 )))
#define SCITA1               (*((volatile unsigned long *)(0x40001000 + 0x18 )))
#define SCIS60CON            (*((volatile unsigned long *)(0x40001000 + 0x1C )))

/********************************************************************************
                             SPI Regsiter
********************************************************************************/
#define SPICON               (*((volatile unsigned long *)(0x40001800 + 0x00 )))
#define SPIDLEN              (*((volatile unsigned long *)(0x40001800 + 0x04 )))
#define SPIST                (*((volatile unsigned long *)(0x40001800 + 0x08 )))
#define SPIDIV               (*((volatile unsigned long *)(0x40001800 + 0x0C )))
#define SPIIE                (*((volatile unsigned long *)(0x40001800 + 0x10 )))
#define SPIIS                (*((volatile unsigned long *)(0x40001800 + 0x14 )))
#define SPISTR               (*((volatile unsigned long *)(0x40001800 + 0x18 )))
#define SPIDATA              (*((volatile unsigned long *)(0x40001800 + 0x40 )))

/********************************************************************************
                             RNG Regsiter
********************************************************************************/
#define RNG1XCFG             (*((volatile unsigned long *)(0x40002800 + 0x24 )))
#define RNG1XCEN             (*((volatile unsigned long *)(0x40002800 + 0x28 )))
#define RNG1XCSTR            (*((volatile unsigned long *)(0x40002800 + 0x2C )))
#define RNG1STR              (*((volatile unsigned long *)(0x40002800 + 0x30 )))
#define RNG1OUT              (*((volatile unsigned long *)(0x40002800 + 0x34 )))
#define RTCNT0               (*((volatile unsigned long *)(0x40002800 + 0x38 )))
#define RTCNT1               (*((volatile unsigned long *)(0x40002800 + 0x3C )))
#define RTCNT2               (*((volatile unsigned long *)(0x40002800 + 0x40 )))
#define RTCNT3               (*((volatile unsigned long *)(0x40002800 + 0x44 )))
#define RTCNT4               (*((volatile unsigned long *)(0x40002800 + 0x48 )))
#define RTCNT5               (*((volatile unsigned long *)(0x40002800 + 0x4C )))
#define RTCNT6               (*((volatile unsigned long *)(0x40002800 + 0x50 )))
#define RTCNT7               (*((volatile unsigned long *)(0x40002800 + 0x54 )))
#define RTCNT8               (*((volatile unsigned long *)(0x40002800 + 0x58 )))
#define RTCNT9               (*((volatile unsigned long *)(0x40002800 + 0x5C )))
#define RTCNT10              (*((volatile unsigned long *)(0x40002800 + 0x60 )))
#define RTCNT11              (*((volatile unsigned long *)(0x40002800 + 0x64 )))
#define RTCNT12              (*((volatile unsigned long *)(0x40002800 + 0x68 )))
#define RTCNT13              (*((volatile unsigned long *)(0x40002800 + 0x6C )))
#define RTCNT14              (*((volatile unsigned long *)(0x40002800 + 0x70 )))
#define RTCNT15              (*((volatile unsigned long *)(0x40002800 + 0x74 )))

/********************************************************************************
                             GPIO Regsiter
********************************************************************************/
#define GPIODATA             (*((volatile unsigned long *)(0x40003000 + 0x00 )))
#define GPIODIR              (*((volatile unsigned long *)(0x40003000 + 0x04 )))
#define GPIOIS               (*((volatile unsigned long *)(0x40003000 + 0x08 )))
#define GPIOIBE              (*((volatile unsigned long *)(0x40003000 + 0x0c )))
#define GPIOIEV              (*((volatile unsigned long *)(0x40003000 + 0x10 )))
#define GPIOIE               (*((volatile unsigned long *)(0x40003000 + 0x14 )))
#define GPIORIS              (*((volatile unsigned long *)(0x40003000 + 0x18 )))
#define GPIOMIS              (*((volatile unsigned long *)(0x40003000 + 0x1c )))
#define GPIOIC               (*((volatile unsigned long *)(0x40003000 + 0x20 )))

/********************************************************************************
                             SWP Regsiter
********************************************************************************/
#define SWPIT                (*((volatile unsigned long *)(0x40003800 + 0x00 )))
#define SWPITMK              (*((volatile unsigned long *)(0x40003800 + 0x04 )))
#define SWPITEN              (*((volatile unsigned long *)(0x40003800 + 0x08 )))
#define SWPITENCLR           (*((volatile unsigned long *)(0x40003800 + 0x0C )))
#define SWPCON               (*((volatile unsigned long *)(0x40003800 + 0x10 )))
#define SWPCLT               (*((volatile unsigned long *)(0x40003800 + 0x14 )))
#define SWPTFS               (*((volatile unsigned long *)(0x40003800 + 0x18 )))
#define SWPRFS               (*((volatile unsigned long *)(0x40003800 + 0x1C )))
#define SWPBFC               (*((volatile unsigned long *)(0x40003800 + 0x20 )))
#define SWPBFS               (*((volatile unsigned long *)(0x40003800 + 0x24 )))
#define SWPMTP               (*((volatile unsigned long *)(0x40003800 + 0x30 )))
#define SWPMTC               (*((volatile unsigned long *)(0x40003800 + 0x34 )))
#define SWPMOD               (*((volatile unsigned long *)(0x40003800 + 0x80 )))
#define SWPPARA1             (*((volatile unsigned long *)(0x40003800 + 0x100 )))
#define SWPPARA2             (*((volatile unsigned long *)(0x40003800 + 0x104 )))
#define SWPPARA5             (*((volatile unsigned long *)(0x40003800 + 0x108 )))
#define SWPSID               (*((volatile unsigned long *)(0x40003800 + 0x10C )))
#define SWPSSR               (*((volatile unsigned long *)(0x40003800 + 0x180 )))
#define SWPSTATE             (*((volatile unsigned long *)(0x40003800 + 0x184 )))
#define SWPM1KL              (*((volatile unsigned long *)(0x40003800 + 0x1C0 )))
#define SWPM1KM              (*((volatile unsigned long *)(0x40003800 + 0x1C4 )))
#define SWPM1KH              (*((volatile unsigned long *)(0x40003800 + 0x1C8 )))
#define SWPM1RNG             (*((volatile unsigned long *)(0x40003800 + 0x1CC )))
#define SWPUID               (*((volatile unsigned long *)(0x40003800 + 0x1D0 )))
#define SWPDBUF              (*((volatile unsigned long *)(0x40003800 + 0x300 )))
#define SWPSDBUF             ((volatile unsigned long *)(0x40003800 + 0x304 ))

/********************************************************************************
                             PPB Regsiter
********************************************************************************/

#define ACTLR                 (*((volatile unsigned long *)( 0xE000E008	)))
#define NVIC_ISER             (*((volatile unsigned long *)( 0xE000E100	)))
#define NVIC_ICER             (*((volatile unsigned long *)( 0xE000E180	)))
#define NVIC_ISPR             (*((volatile unsigned long *)( 0xE000E200	)))
#define NVIC_ICPR             (*((volatile unsigned long *)( 0xE000E280	)))
#define NVIC_IPR0             (*((volatile unsigned long *)( 0xE000E400	)))
#define NVIC_IPR1             (*((volatile unsigned long *)( 0xE000E404	)))
#define NVIC_IPR2             (*((volatile unsigned long *)( 0xE000E408	)))
#define NVIC_IPR3             (*((volatile unsigned long *)( 0xE000E40C	)))
#define NVIC_IPR4             (*((volatile unsigned long *)( 0xE000E410	)))
#define NVIC_IPR5             (*((volatile unsigned long *)( 0xE000E414	)))
#define NVIC_IPR6             (*((volatile unsigned long *)( 0xE000E418	)))
#define NVIC_IPR7             (*((volatile unsigned long *)( 0xE000E41C	)))
#define CPUID                 (*((volatile unsigned long *)( 0xE000ED00	)))
#define ICSR                  (*((volatile unsigned long *)( 0xE000ED04	)))
#define VTOR                  (*((volatile unsigned long *)( 0xE000ED08	)))
#define AIRCR                 (*((volatile unsigned long *)( 0xE000ED0C	)))
#define SCR                   (*((volatile unsigned long *)( 0xE000ED10	)))
#define CCR                   (*((volatile unsigned long *)( 0xE000ED14	)))
#define SHPR2                 (*((volatile unsigned long *)( 0xE000ED1C	)))
#define SHPR3                 (*((volatile unsigned long *)( 0xE000ED20	)))
#define MPU_TYPE              (*((volatile unsigned long *)( 0xE000ED90	)))
#define MPU_CTRL              (*((volatile unsigned long *)( 0xE000ED94	)))
#define MPU_RNR               (*((volatile unsigned long *)( 0xE000ED98	)))
#define MPU_RBAR              (*((volatile unsigned long *)( 0xE000ED9C	)))
#define MPU_RASR              (*((volatile unsigned long *)( 0xE000EDA0	)))
#define SFCR                  (*((volatile unsigned long *)( 0xE000EF90	)))

/********************************************************************************
                             Interrupt Source
********************************************************************************/
#define     IRQ_TMR0                0
#define     IRQ_TMR1                1
#define     IRQ_WDT                 2
#define     IRQ_NVMCTR              3
#define     IRQ_NVMDE               4
#define     IRQ_SECRST              5
#define     IRQ_RNG1                7
#define     IRQ_7816RST             8
#define     IRQ_7816TX              9
#define     IRQ_7816RX              10
#define     IRQ_7816FIFO            11
#define     IRQ_IFDET               12
#define     IRQ_SWP                 13
#define     IRQ_SPI                 14
#define     IRQ_GPIOINT0            15

#endif  /* End of __IO_CIU98M25_H */
