#include "BSP.h"

DBCM_KEY gKey;

#define MC33978_WK_DR       _TRISD10  //输入
#define MC33978_INT_DR      _TRISD9   //输入
#define MC33978_ADMUX_DR    _TRISB0  //模拟端口

#define MC33978_WK          _LATD10
#define MC33978_INT         _LATD9

#define MC33978_CS_DR       _TRISG3   //输出
#define MC33978_MOSI_DR     _TRISF3   //输出
#define MC33978_MISO_DR     _TRISF2   //输入
#define MC33978_MCLK_DR     _TRISF6   //输出

#define MC33978_CS_LAT          _LATG3
#define MC33978_MOSI_LAT        _LATF3
#define MC33978_MISO_LAT        _LATF2
#define MC33978_MCLK_LAT        _LATF6

#define MC33978_CS_PORT          _RG3
#define MC33978_MOSI_PORT        _RF3
#define MC33978_MISO_PORT        _RF2
#define MC33978_MCLK_PORT        _RF6

typedef union {
    struct {
        unsigned SG0 : 1;
        unsigned SG1 : 1;
        unsigned SG2 : 1;
        unsigned SG3 : 1;
        unsigned SG4 : 1;
        unsigned SG5 : 1;
        unsigned SG6 : 1;
        unsigned SG7 : 1;

        unsigned SG8 : 1;
        unsigned SG9 : 1;
        unsigned SG10 : 1;
        unsigned SG11 : 1;
        unsigned SG12 : 1;
        unsigned SG13 : 1;
        unsigned SP0 : 1;
        unsigned SP1 : 1;

        unsigned SP2 : 1;
        unsigned SP3 : 1;
        unsigned SP4 : 1;
        unsigned SP5 : 1;
        unsigned SP6 : 1;
        unsigned SP7 : 1;
        unsigned INTflag : 1;
        unsigned FAULT_STATUS : 1;
    } BITS;
    unsigned char BYTES[3];
} SW_STATUS;



static unsigned char mc33978_rtn[4];
static unsigned long check;

unsigned char spi_write(unsigned char dat) {
    unsigned char i;
    unsigned char dump;
    dump = 0;
    for (i = 0; i < 8; i++) {
        MC33978_MCLK_LAT = 0;
        if (dat & 0x80) {
            MC33978_MOSI_LAT = 1;
        } else {
            MC33978_MOSI_LAT = 0;
        }
        dat = dat << 1;
        dump = dump << 1;
        MC33978_MCLK_LAT = 1;
        dump |= MC33978_MISO_PORT;
    }
    MC33978_MCLK_LAT = 0;
    return (dump);

}

void mc33978_write(unsigned char cmd, unsigned char config1, unsigned char config2, unsigned char config3) {
    MC33978_CS_LAT = 0;
    mc33978_rtn[0] = spi_write(cmd);
    mc33978_rtn[1] = spi_write(config1);
    mc33978_rtn[2] = spi_write(config2);
    mc33978_rtn[3] = spi_write(config3);
    MC33978_CS_LAT = 1;
}

void mc33978_spi_check(void) {
    //SPI CHECK
    mc33978_write(0x0, 0, 0, 0);
    mc33978_write(0x0, 0, 0, 0);

    check = ((unsigned long) mc33978_rtn[1] << 16)+((unsigned int) mc33978_rtn[2] << 8) + mc33978_rtn[3];

}

void mc33978_Init(void) {
    MC33978_WK_DR = 1; //输入
    MC33978_INT_DR = 1; //输入

    MC33978_CS_DR = 0; //输出
    MC33978_MOSI_DR = 0; //输出
    MC33978_MISO_DR = 1; //输入
    MC33978_MCLK_DR = 0; //输出

    MC33978_CS_LAT = 1;
    MC33978_MOSI_LAT = 0;
    MC33978_MCLK_LAT = 0;
    __delay_us(100);


    mc33978_spi_check();

    //RESET
    mc33978_write(0x49, 0, 0, 0);
    __delay_us(100);
    //SPI CHECK

    //DeviceConfiguration
    mc33978_write(0x03, 0, 0x00, 0x01); //SP0-BAT SP1-7=GND

    //Tri-State SP Register
    mc33978_write(0x05, 0, 0, 0x00); //
    //Tri-State SG Register
    mc33978_write(0x07, 0x00, 0x2D, 0x20); //0x2D,SG13,SG11,SG10,SG8=1;0x20 SG5=1;  ; 

    //Wetting Current Level SP Register
    mc33978_write(0x09, 0, 0, 0); //SP0-7 2mA

    //Wetting Current Level SG Register 0
    mc33978_write(0x0B, 0, 0, 0); //SG0-7 2mA

    //Wetting Current Level SG Register 1
    mc33978_write(0x0D, 0, 0, 0); //SG8-13 2mA

    //Continuous Wetting Current SP Register
    mc33978_write(0x17, 0, 0, 0x00); //SP0-7 脉冲

    //Continuous Wetting Current SG Register
    mc33978_write(0x19, 0, 0x00, 0x00); //SG0-13 脉冲 

    //Interrupt Enable SP Register
    mc33978_write(0x1B, 0, 0, 0x00);

    //Interrupt Enable SG Register
    mc33978_write(0x1D, 0, 0x00, 0x00);

    //Low Power Mode Configuration Register 
    mc33978_write(0x1F, 0, 0, 0); //poll 3ms

    //Wake-up Enable SP Register 
    mc33978_write(0x21, 0, 0, 0x00);

    //Wake-up Enable SG Register 
    mc33978_write(0x23, 0, 0x00, 0x00);

    // Polling Current Configuration SP Register
    mc33978_write(0x2D, 0, 0x00, 0x00);
    //Polling Current Configuration SG Register  
    mc33978_write(0x2F, 0, 0x00, 0x00);

}

//void mc33978_DeviceConfiguration(unsigned char mode=0x01);

void mc33978_DeviceConfiguration(unsigned char mode) {
    //DeviceConfiguration
    mc33978_write(0x03, 0, 0x00, mode); //SP0-BAT SP1-7=GND
}

void mc33978_AMUX(unsigned char chs) {
    //AMUX Control Register
    chs = chs & 0x3f;
    mc33978_write(0x3B, 0x00, 0x00, chs);
}

void mc33978_ReadSwtichStatus(void) {
    SW_STATUS gSW;
    mc33978_write(0x3E, 0, 0, 0);
    mc33978_write(0x3E, 0, 0, 0);

    if (mc33978_rtn[0] == 0x3E) {
        gSW.BYTES[0] = mc33978_rtn[3];
        gSW.BYTES[1] = mc33978_rtn[2];
        gSW.BYTES[2] = mc33978_rtn[1];
        
        gKey.BITS.kl1 = gSW.BITS.SG0;
        gKey.BITS.kl2 = gSW.BITS.SG1;
        gKey.BITS.kl3 = gSW.BITS.SG2;
        gKey.BITS.kl4 = gSW.BITS.SG3;
        gKey.BITS.kl5 = gSW.BITS.SG4;
        gKey.BITS.kl6 = gSW.BITS.SG7;
        gKey.BITS.kl7 = gSW.BITS.SG12;
        gKey.BITS.kl8 = gSW.BITS.SG6;

        gKey.BITS.kl9 = gSW.BITS.SP1;
        gKey.BITS.kl10 = gSW.BITS.SP2;
        gKey.BITS.kl11 = gSW.BITS.SP3;
        gKey.BITS.kl12 = gSW.BITS.SP4;
        gKey.BITS.kl13 = gSW.BITS.SP5;
        gKey.BITS.kl14 = gSW.BITS.SP6;
        gKey.BITS.kl15 = gSW.BITS.SP7;

        gKey.BITS.kh1 = gSW.BITS.SP0;
        gKey.BITS.add = gSW.BITS.SG9;
    }
}











