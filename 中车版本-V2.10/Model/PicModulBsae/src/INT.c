#include "BSP.h"

unsigned int freq = 0;
unsigned int single_miles = 0;
unsigned int e_hm_pulse=0;


static unsigned int fin_count = 0;
void TIMER1_Init(void) {
    /*��ʱ��1����*/
    TMR1 = 0;
    T1CON = 0x0010; //1��8��Ƶ 1 MHz
    PR1 = 9999; // 10ms
    _T1IF = 0;
    _T1IE = 1;
    _TON=1;
}


void INT1_Init(void) {
    _INT1IF = 0;
    _INT1IE = 1;
    _INT1EP = 1;
}



void TIMER3_Init(void) {
    T3CON = 0x0020; //1��64��Ƶ  125 kHz
    TMR3 = 0;
    PR3 = 24999;
    _T3IP = 5;
    _T3IF = 0;
    _T3IE = 1;
    T3CONbits.TON=1;
}


void __attribute__((__interrupt__, auto_psv)) _T3Interrupt(void) {
    static unsigned int stemp[5] = {0, 0, 0, 0, 0};
    static unsigned int i = 0;
    if (i >= 5) i = 0;
    stemp[i++] = fin_count;
    fin_count = 0;
    freq = stemp[0] + stemp[1] + stemp[2] + stemp[3] + stemp[4];
    _T3IF = 0;
}

void __attribute__((__interrupt__, auto_psv)) _INT1Interrupt(void) {
    static unsigned int count = 0;
    fin_count++;
    //记录里程数,精度0.1Km 
    if (count >= e_hm_pulse) { //460
        count = 0;
        if (single_miles >= 50000) single_miles = 0;
        else single_miles++;
    } else count++;

    _INT1IF = 0;
}
