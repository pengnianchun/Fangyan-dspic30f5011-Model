/* 
 * File:   main.c
 * Author: mpszm
 *
 * Created on 2016年6月7日, 下午9:11
 */

#include "system.h"

// FOSC
#pragma config FPR = XT_PLL4            // Primary Oscillator Mode (XT w/PLL 4x)
#pragma config FOS = PRI                // Oscillator Source (Primary Oscillator)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = BORV_20        // Brown Out Voltage (2.0V)
#pragma config BOREN = PBOR_ON          // PBOR Enable (Enabled)
#pragma config MCLRE = MCLR_DIS          // Master Clear Enable (Enabled)

// FBS
#pragma config BWRP = WR_PROTECT_BOOT_OFF// Boot Segment Program Memory Write Protect (Boot Segment Program Memory may be written)
#pragma config BSS = NO_BOOT_CODE       // Boot Segment Program Flash Memory Code Protection (No Boot Segment)
#pragma config EBS = NO_BOOT_EEPROM     // Boot Segment Data EEPROM Protection (No Boot EEPROM)
#pragma config RBS = NO_BOOT_RAM        // Boot Segment Data RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WR_PROT_SEC_OFF   // Secure Segment Program Write Protect (Disabled)
#pragma config SSS = NO_SEC_CODE        // Secure Segment Program Flash Memory Code Protection (No Secure Segment)
#pragma config ESS = NO_SEC_EEPROM      // Secure Segment Data EEPROM Protection (No Segment Data EEPROM)
#pragma config RSS = NO_SEC_RAM         // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = GSS_OFF            // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)
/*
 */


int main(void){ 
    static DBCM_KEY gKeyDump;        //define structor 
    unsigned char task = 0;
    system_Init();
    
    gKeyDump=gKey;                   //缓存开关值   
    
    for(;;){
       ClrWdt();       
       
       //模块上电10秒内通过CAN报文ID判断地址， 如果有同地址模块，则修改全局地址 
        if ((addr_eeror != 0x00) && (delay_10s > 10)) {
            get_hw_address();       //再次读取硬件地址
            g_address = hw_address;
        }

        if (K_ON == 0) { //key OFF
            single_miles = 0; //里程清零
        }
       
        if (g_address == 1) //前模块执行雨刮程序
            rain_wape();
       
        if (F10ms == 1) { //读取开关信号
            F10ms = 0;
            //Test();
            POUT_Write();          
            mc33978_ReadSwtichStatus();
            if ((gKeyDump.BYTES[0] != gKey.BYTES[0]) | (gKeyDump.BYTES[1] != gKey.BYTES[1]) | (gKeyDump.BYTES[2] != gKey.BYTES[2])) {
                can_send_message_key();
            }
            gKeyDump = gKey;
        }

        if (F50ms == 1) { //50ms自动发送开关量信息
            F50ms = 0;
            //POUT_Write();
            can_send_message_key();
        }
       
       if (F100ms == 1) {
            F100ms = 0;
            can_send_message_st();
            if (task == 0) {
                task = 1;
                can_send_message_Pcur1();
            } else if (task == 1) {
                task = 2;
                can_send_message_Pcur2();
            } else if (task == 2) {
                task = 3;
                can_send_message_Pcur3();
            } else if (task == 3) {
                task = 0;
                can_send_message_Pcur4();
            } else task = 0;
        }
       
       if (F500ms) {
            F500ms = 0;
            read_ADR();
            can_send_message_ADR();     //采样电阻������               
        }
       
        if (F1000ms) {
            F1000ms = 0;
            can_send_message_mileage(); //发送里程信息������Ϣ               
        }   
    }
    return 0;
}

