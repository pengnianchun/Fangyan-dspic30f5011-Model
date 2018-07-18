/* 
 * File:   system.h
 * Author: mpszm
 *
 * Created on 2016年6月8日, 上午11:43
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#include "bsp.h"
#include "cfg.h"

typedef union {
    struct {
        unsigned k0 : 1;
        unsigned k1 : 1;
        unsigned k2 : 1;
        unsigned k3 : 1;
        unsigned k4 : 1;
        unsigned : 3;
    } BITS;
    unsigned char BYTE;
} MUIC_KEY;
extern MUIC_KEY gYBKey;

#define K_ON            gYBKey.BITS.k0 //钥匙ON
#define RAIN_SLOW	    gYBKey.BITS.k1 //雨刮慢档
#define RAIN_INTERVAL	gYBKey.BITS.k2 //雨刮间歇档
#define RAIN_HIGH	    gYBKey.BITS.k3 //雨刮快档
#define RAIN_SPRAY	    gYBKey.BITS.k4 //雨刮喷水档

//传感器电源控制脚
#define SPWR_EN_DR   _TRISG2
#define SPWR_EN      _LATG2

//电阻 电压传感器切换
#define VS_CTL_DR   _TRISC2
#define VS_CTL      _LATC2

//CAN使能
#define C1_WK_DR  _TRISC13
#define C1_WK     _LATC13

//控制雨刮放电
#define POWPP_DR  _TRISF5
#define POWPP     _LATF5

//防止雨刮高档电流
#define PO16_DR  _TRISG6
#define PO16     _LATG6

#define CAN_TIME  30

extern unsigned int delay_10s;
extern unsigned char F10ms;
extern unsigned char F50ms;
extern unsigned char F100ms;
extern unsigned char F500ms;
extern unsigned char F1000ms;
extern unsigned char FLASH;

extern unsigned char addr_eeror;//地址比较出错

extern unsigned int g_address; //全局定义 
extern unsigned int e_address; //EEPROM存储地址
extern unsigned int hw_address; //硬线地址

extern unsigned int wash_time;
extern unsigned int wipe_int_time ;
extern unsigned int wipe_stop_time;
extern unsigned char DELAY_START;
extern unsigned char DELAY_END;

extern unsigned int wipe_wpp_time; //30毫秒

extern unsigned int system_wake_time;

void system_Init(void);
void get_hw_address(void);
void read_ADR(void);

void rain_wape(void);
void Test(void);

void delay(unsigned int t);

void can_send_message_key(void);
void can_send_message_st(void);
void can_send_message_ADR(void);
void can_send_message_mileage(void);

void can_send_message_Pcur1(void);
void can_send_message_Pcur2(void);
void can_send_message_Pcur3(void);
void can_send_message_Pcur4(void);

void TIM5_Init(void);
#endif	/* SYSTEM_H */

