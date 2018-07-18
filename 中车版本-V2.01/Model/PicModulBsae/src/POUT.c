#include "BSP.h"

#define PO1_DR   _TRISD0
#define PO2_DR   _TRISG14
#define PO3_DR   _TRISD1
#define PO4_DR   _TRISG12
#define PO5_DR   _TRISD2
#define PO6_DR   _TRISG13
#define PO7_DR   _TRISD3
#define PO8_DR   _TRISG15
#define PO9_DR   _TRISD4
#define PO10_DR  _TRISG7
#define PO11_DR  _TRISD5
#define PO12_DR  _TRISG8
#define PO13_DR  _TRISD6
#define PO14_DR  _TRISG9
#define PO15_DR  _TRISD7

#define PO1  _LATD0
#define PO2  _LATG14
#define PO3  _LATD1
#define PO4  _LATG12
#define PO5  _LATD2
#define PO6  _LATG13
#define PO7  _LATD3
#define PO8  _LATG15
#define PO9  _LATD4
#define PO10 _LATG7
#define PO11 _LATD5
#define PO12 _LATG8
#define PO13 _LATD6
#define PO14 _LATG9
#define PO15 _LATD7

#define POD_DR  _TRISC1
#define POD     _LATC1

POUT gPout, pout;

#define OPENLOAD_VALUE     100
#define PROTECT_THRESHOLD  1000
#define PROTECT_MAX_CNT    50

unsigned char pf[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static unsigned char pcnt[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int pcur[15];
const unsigned char ad_ch[] = {5, 9, 4, 10, 3, 11, 2, 12, 1, 13, 6, 14, 7, 15, 8};

extern unsigned int ADC_Read(unsigned char chs);

void POUT_Init(void) {
    PO1_DR = 0; //
    PO2_DR = 0; //
    PO3_DR = 0; //
    PO4_DR = 0; //
    PO5_DR = 0; //
    PO6_DR = 0; //
    PO7_DR = 0; //
    PO8_DR = 0; //
    PO9_DR = 0; //
    PO10_DR = 0; //
    PO11_DR = 0; //
    PO12_DR = 0; //
    PO13_DR = 0; //
    PO14_DR = 0; //
    PO15_DR = 0; // 

    PO1 = 0; //
    PO2 = 0; //
    PO3 = 0; //
    PO4 = 0; //
    PO5 = 0; //
    PO6 = 0; //
    PO7 = 0; //
    PO8 = 0; //
    PO9 = 0; //
    PO10 = 0; //
    PO11 = 0; //
    PO12 = 0; //
    PO13 = 0; //
    PO14 = 0; //
    PO15 = 0; //

    POD_DR = 0;
    POD = 0;

}

static void POUT_Protect(void) {
    unsigned char i;
    unsigned int dump;
    dump = gPout.WORDS;
    for (i = 0; i < 16; i++) {
        if ((dump & 0x01) == 1) {//一个AD值大约等于12mA
            if (pf[i] != 0x02) {
                pcur[i] = ADC_Read(ad_ch[i]);
                if (pcnt[i] >= (PROTECT_MAX_CNT)) {
                    pout.WORDS = (pout.WORDS & ~(0x01 << i));//关闭输出                      
                    pf[i] = 0x02; //故障保护
                } else {
                    pout.WORDS = (pout.WORDS | (0x01 << i));//打开输出
                    if (pcur[i] < OPENLOAD_VALUE) pf[i] = 0x01; //开路
                    else pf[i] = 0x00; //正常
                }
                if (pcur[i] > (PROTECT_THRESHOLD)) {
                    pcnt[i]++;
                } else {
                    if (pcnt[i] > 0) pcnt[i]--;
                }
            }
        } else {
            pout.WORDS = (pout.WORDS & ~(0x01 << i));
            pcnt[i] = 0;
            pf[i] = 0;
        }
        dump = dump >> 1;
    }
}

void POUT_Write(void) {
    POUT_Protect();
    PO1 = pout.BITS.O1;
    PO2 = pout.BITS.O2;
    PO3 = pout.BITS.O3;
    PO4 = pout.BITS.O4;
    PO5 = pout.BITS.O5;
    PO6 = pout.BITS.O6;
    PO7 = pout.BITS.O7;
    PO8 = pout.BITS.O8;
    PO9 = pout.BITS.O9;
    PO10 = pout.BITS.O10;
    PO11 = pout.BITS.O11;
    PO12 = pout.BITS.O12;
    PO13 = pout.BITS.O13;
    PO14 = pout.BITS.O14;
    PO15 = pout.BITS.O15;     
#if 0   
    if (gPout.BITS.O1 == 1) {//一个AD值大约等于12mA
        if (pf[0] != 0x02) {
            pcur[0] = ADC_Read(ad_ch[0]);
            if (pcnt[0] >= (PROTECT_MAX_CNT)) {
                PO1 = 0; //关闭输出 
                pf[0] = 0x02; //故障保护
            } else {
                PO1 = 1; //打开输出
                if (pcur[0] < OPENLOAD_VALUE) pf[0] = 0x01; //开路
                else pf[0] = 0x00; //正常
            }
            if (pcur[0] > (PROTECT_THRESHOLD)) {
                pcnt[0]++;
            } else {
                if (pcnt[0] > 0) pcnt[0]--;
            }
        }
    } else {
        PO1 = 0;
        pcnt[0] = 0;
        pf[0] = 0;
    }

    if (gPout.BITS.O2 == 1) {
        if (pf[1] != 0x02) {
            pcur[1] = ADC_Read(ad_ch[1]);
            if (pcnt[1] >= PROTECT_MAX_CNT) {
                PO2 = 0; //关闭输出 
                pf[1] = 0x02; //故障保护
            } else {
                PO2 = 1; //打开输出
                if (pcur[1] < OPENLOAD_VALUE) pf[1] = 0x01;
                else pf[1] = 0x00;
            }
            if (pcur[1] > PROTECT_THRESHOLD) {
                pcnt[1]++;
            } else {
                if (pcnt[1] > 0) pcnt[1]--;
            }
        }
    } else {
        PO2 = 0;
        pcnt[1] = 0;
        pf[1] = 0;
    }

    if (gPout.BITS.O3 == 1) {
        if (pf[2] != 0x02) {
            pcur[2] = ADC_Read(ad_ch[2]);
            if (pcnt[2] >= PROTECT_MAX_CNT) {
                PO3 = 0; //关闭输出 
                pf[2] = 0x02; //故障保护
            } else {
                PO3 = 1; //打开输出
                if (pcur[2] < OPENLOAD_VALUE) pf[2] = 0x01;
                else pf[2] = 0x00;
            }
            if (pcur[2] > PROTECT_THRESHOLD) {
                pcnt[2]++;
            } else {
                if (pcnt[2] > 0) pcnt[2]--;
            }
        }
    } else {
        PO3 = 0;
        pcnt[2] = 0;
        pf[2] = 0;
    }


    if (gPout.BITS.O4 == 1) {
        if (pf[3] != 0x02) {
            pcur[3] = ADC_Read(ad_ch[3]);
            if (pcnt[3] >= PROTECT_MAX_CNT) {
                PO4 = 0; //关闭输出 
                pf[3] = 0x02; //故障保护
            } else {
                PO4 = 1; //打开输出
                if (pcur[3] < OPENLOAD_VALUE) pf[3] = 0x01;
                else pf[3] = 0x00;
            }
            if (pcur[3] > PROTECT_THRESHOLD) {
                pcnt[3]++;
            } else {
                if (pcnt[3] > 0) pcnt[3]--;
            }
        }
    } else {
        PO4 = 0;
        pcnt[3] = 0;
        pf[3] = 0;
    }

    if (gPout.BITS.O5 == 1) {
        if (pf[4] != 0x02) {
            pcur[4] = ADC_Read(ad_ch[4]);
            if (pcnt[4] >= PROTECT_MAX_CNT) {
                PO5 = 0; //关闭输出 
                pf[4] = 0x02; //故障保护
            } else {
                PO5 = 1; //打开输出
                if (pcur[4] < OPENLOAD_VALUE) pf[4] = 0x01;
                else pf[4] = 0x00;
            }
            if (pcur[4] > PROTECT_THRESHOLD) {
                pcnt[4]++;
            } else {
                if (pcnt[4] > 0) pcnt[4]--;
            }
        }
    } else {
        PO5 = 0;
        pcnt[4] = 0;
        pf[4] = 0;
    }


    if (gPout.BITS.O6 == 1) {
        if (pf[5] != 0x02) {
            pcur[5] = ADC_Read(ad_ch[5]);
            if (pcnt[5] >= PROTECT_MAX_CNT) {
                PO6 = 0; //关闭输出 
                pf[5] = 0x02; //故障保护
            } else {
                PO6 = 1; //打开输出
                if (pcur[5] < OPENLOAD_VALUE) pf[5] = 0x01;
                else pf[5] = 0x00;
            }
            if (pcur[5] > PROTECT_THRESHOLD) {
                pcnt[5]++;
            } else {
                if (pcnt[5] > 0) pcnt[5]--;
            }
        }
    } else {
        PO6 = 0;
        pcnt[5] = 0;
        pf[5] = 0;
    }



    if (gPout.BITS.O7 == 1) {
        if (pf[6] != 0x02) {
            pcur[6] = ADC_Read(ad_ch[6]);
            if (pcnt[6] >= PROTECT_MAX_CNT) {
                PO7 = 0; //关闭输出 
                pf[6] = 0x02; //故障保护
            } else {
                PO7 = 1; //打开输出
                if (pcur[6] < OPENLOAD_VALUE) pf[6] = 0x01;
                else pf[6] = 0x00;
            }
            if (pcur[6] > PROTECT_THRESHOLD) {
                pcnt[6]++;
            } else {
                if (pcnt[6] > 0) pcnt[6]--;
            }
        }
    } else {
        PO7 = 0;
        pcnt[6] = 0;
        pf[6] = 0;
    }


    if (gPout.BITS.O8 == 1) {
        if (pf[7] != 0x02) {
            pcur[7] = ADC_Read(ad_ch[7]);
            if (pcnt[7] >= PROTECT_MAX_CNT) {
                PO8 = 0; //关闭输出 
                pf[7] = 0x02; //故障保护
            } else {
                PO8 = 1; //打开输出
                if (pcur[7] < OPENLOAD_VALUE) pf[7] = 0x01;
                else pf[7] = 0x00;
            }
            if (pcur[7] > PROTECT_THRESHOLD) {
                pcnt[7]++;
            } else {
                if (pcnt[7] > 0) pcnt[7]--;
            }
        }
    } else {
        PO8 = 0;
        pcnt[7] = 0;
        pf[7] = 0;
    }


    if (gPout.BITS.O9 == 1) {
        if (pf[8] != 0x02) {
            pcur[8] = ADC_Read(ad_ch[8]);
            if (pcnt[8] >= PROTECT_MAX_CNT) {
                PO9 = 0; //关闭输出 
                pf[8] = 0x02; //故障保护
            } else {
                PO9 = 1; //打开输出
                if (pcur[8] < OPENLOAD_VALUE) pf[8] = 0x01;
                else pf[8] = 0x00;
            }
            if (pcur[8] > PROTECT_THRESHOLD) {
                pcnt[8]++;
            } else {
                if (pcnt[8] > 0) pcnt[8]--;
            }
        }
    } else {
        PO9 = 0;
        pcnt[8] = 0;
        pf[8] = 0;
    }


    if (gPout.BITS.O10 == 1) {
        if (pf[9] != 0x02) {
            pcur[9] = ADC_Read(ad_ch[9]);
            if (pcnt[9] >= PROTECT_MAX_CNT) {
                PO10 = 0; //关闭输出 
                pf[9] = 0x02; //故障保护
            } else {
                PO10 = 1; //打开输出
                if (pcur[9] < OPENLOAD_VALUE) pf[9] = 0x01;
                else pf[9] = 0x00;
            }
            if (pcur[9] > PROTECT_THRESHOLD) {
                pcnt[9]++;
            } else {
                if (pcnt[9] > 0) pcnt[9]--;
            }
        }
    } else {
        PO10 = 0;
        pcnt[9] = 0;
        pf[9] = 0;
    }


    if (gPout.BITS.O11 == 1) {
        if (pf[10] != 0x02) {
            pcur[10] = ADC_Read(ad_ch[10]);
            if (pcnt[10] >= PROTECT_MAX_CNT) {
                PO11 = 0; //关闭输出 
                pf[10] = 0x02; //故障保护
            } else {
                PO11 = 1; //打开输出
                if (pcur[10] < OPENLOAD_VALUE) pf[10] = 0x01;
                else pf[10] = 0x00;
            }
            if (pcur[10] > PROTECT_THRESHOLD) {
                pcnt[10]++;
            } else {
                if (pcnt[10] > 0) pcnt[10]--;
            }
        }
    } else {
        PO11 = 0;
        pcnt[10] = 0;
        pf[10] = 0;
    }

    if (gPout.BITS.O12 == 1) {
        if (pf[11] != 0x02) {
            pcur[11] = ADC_Read(ad_ch[11]);
            if (pcnt[11] >= PROTECT_MAX_CNT) {
                PO12 = 0; //关闭输出 
                pf[11] = 0x02; //故障保护
            } else {
                PO12 = 1; //打开输出
                if (pcur[11] < OPENLOAD_VALUE) pf[11] = 0x01;
                else pf[11] = 0x00;
            }
            if (pcur[11] > PROTECT_THRESHOLD) {
                pcnt[11]++;
            } else {
                if (pcnt[11] > 0) pcnt[11]--;
            }
        }
    } else {
        PO12 = 0;
        pcnt[11] = 0;
        pf[11] = 0;
    }

    if (gPout.BITS.O13 == 1) {
        if (pf[12] != 0x02) {
            pcur[12] = ADC_Read(ad_ch[12]);
            if (pcnt[12] >= PROTECT_MAX_CNT) {
                PO13 = 0; //关闭输出 
                pf[12] = 0x02; //故障保护
            } else {
                PO13 = 1; //打开输出
                if (pcur[12] < OPENLOAD_VALUE) pf[12] = 0x01;
                else pf[12] = 0x00;
            }
            if (pcur[12] > PROTECT_THRESHOLD) {
                pcnt[12]++;
            } else {
                if (pcnt[12] > 0) pcnt[12]--;
            }
        }
    } else {
        PO13 = 0;
        pcnt[12] = 0;
        pf[12] = 0;
    }


    if (gPout.BITS.O14 == 1) {
        if (pf[13] != 0x02) {
            pcur[13] = ADC_Read(ad_ch[13]);
            if (pcnt[13] >= PROTECT_MAX_CNT) {
                PO14 = 0; //关闭输出 
                pf[13] = 0x02; //故障保护
            } else {
                PO14 = 1; //打开输出
                if (pcur[13] < OPENLOAD_VALUE) pf[13] = 0x01;
                else pf[13] = 0x00;
            }
            if (pcur[13] > PROTECT_THRESHOLD) {
                pcnt[13]++;
            } else {
                if (pcnt[13] > 0) pcnt[13]--;
            }
        }
    } else {
        PO14 = 0;
        pcnt[13] = 0;
        pf[13] = 0;
    }


    if (gPout.BITS.O15 == 1) {
        if (pf[14] != 0x02) {
            pcur[14] = ADC_Read(ad_ch[14]);
            if (pcnt[14] >= PROTECT_MAX_CNT) {
                PO15 = 0; //关闭输出 
                pf[14] = 0x02; //故障保护
            } else {
                PO15 = 1; //打开输出
                if (pcur[14] < OPENLOAD_VALUE) pf[14] = 0x01;
                else pf[14] = 0x00;
            }
            if (pcur[14] > PROTECT_THRESHOLD) {
                pcnt[14]++;
            } else {
                if (pcnt[14] > 0) pcnt[14]--;
            }
        }
    } else {
        PO15 = 0;
        pcnt[14] = 0;
        pf[14] = 0;
    }
#endif
    POD = gPout.BITS.OD;
}

