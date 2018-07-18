/* 
 * File:   bsp.h
 * Author: mpszm
 *
 * Created on 2016年6月11日, 下午8:49
 */

#ifndef BSP_H
#define	BSP_H

#include <xc.h>
#define FCY 8000000    //crystal fre
#include <libpic30.h>

typedef union
{ 
    unsigned char BYTES[2];
    unsigned int  WORDS;
    struct 
    { 
        unsigned char O1:1; 
        unsigned char O2:1; 
        unsigned char O3:1; 
        unsigned char O4:1; 
        unsigned char O5:1; 
        unsigned char O6:1; 
        unsigned char O7:1; 
        unsigned char O8:1; 
        unsigned char O9:1; 
        unsigned char O10:1; 
        unsigned char O11:1; 
        unsigned char O12:1; 
        unsigned char O13:1; 
        unsigned char O14:1; 
        unsigned char O15:1; 
        unsigned  OD:1;
    } BITS; 
} POUT; 

//仪表修改保护电流和时间
extern unsigned char pct_cut[15]; //保护电流单位：100mA
extern unsigned char pct_time;//保护时间单位：100ms
extern unsigned char pf[15]; 
extern unsigned int pcur[15];
extern POUT gPout;
void POUT_Init(void);          //power output
void POUT_Write(void);


void ADC_Init(void);
unsigned int ADC_Read(unsigned char chs);

typedef struct {
    unsigned long id;
    unsigned char data[8];
    unsigned char len;
    unsigned char type;
} CAN_MESSAGE;

void CAN1_Init(void);
void CAN1_OperationModeStop(void);      //
void CAN1_OperationModeNormal(void);   //
void CAN1_SendMessage(CAN_MESSAGE *message);
void CAN1_ReceiveMessage(CAN_MESSAGE *message);

void CAN2_Init(void);
void CAN2_SendMessage(CAN_MESSAGE *message);
void CAN2_ReceiveMessage(CAN_MESSAGE *message);

unsigned int EEROM_ReadLowMiles(unsigned long address);
void EEROM_WriteLowMiles(unsigned long address, unsigned int value);
unsigned int EEROM_ReadWord(unsigned long dst);
void EEROM_WriteWord(unsigned long dst,unsigned int val);

extern unsigned int freq  ;
extern unsigned int single_miles ;
extern unsigned int e_hm_pulse;

void INT1_Init(void) ;   //external interrupt
void TIMER3_Init(void) ; //timer3
void TIMER1_Init(void) ; //timer1

typedef union {                     //这是位域结构,1表示成员只占1位空间,注意是1位,不是1字节.1个字节是8位
    struct {
        unsigned kl1 : 1;
        unsigned kl2 : 1;
        unsigned kl3 : 1;
        unsigned kl4 : 1;
        unsigned kl5 : 1;
        unsigned kl6 : 1;
        unsigned kl7 : 1;
        unsigned kl8 : 1;

        unsigned kl9 : 1;
        unsigned kl10 : 1;
        unsigned kl11 : 1;
        unsigned kl12 : 1;
        unsigned kl13 : 1;
        unsigned kl14 : 1;
        unsigned kl15 : 1;
        unsigned     : 1;

        unsigned kh1 :1;
        unsigned add :1;
        unsigned :6;      
    } BITS;
    unsigned char BYTES[3];
} DBCM_KEY;
extern DBCM_KEY gKey;

#define KL1   gKey.BITS.kl1
#define KL2   gKey.BITS.kl2
#define KL3   gKey.BITS.kl3
#define KL4   gKey.BITS.kl4
#define KL5   gKey.BITS.kl5
#define KL6   gKey.BITS.kl6
#define KL7   gKey.BITS.kl7
#define KL8   gKey.BITS.kl8
#define KL9   gKey.BITS.kl9
#define KL10  gKey.BITS.kl10
#define KL11  gKey.BITS.kl11
#define KL12  gKey.BITS.kl12
#define KL13  gKey.BITS.kl13
#define KL14  gKey.BITS.kl14
#define KL15  gKey.BITS.kl15

#define KH1   gKey.BITS.kh1
#define ADD   gKey.BITS.add




void mc33978_Init(void);                   //
void mc33978_AMUX(unsigned char chs);
void mc33978_ReadSwtichStatus(void);
void mc33978_DeviceConfiguration(unsigned char mode);
void mc33978_write(unsigned char cmd, unsigned char config1, unsigned char config2, unsigned char config3);


#endif	/* BSP_H */

