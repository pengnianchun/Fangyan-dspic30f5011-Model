#include "BSP.h"

void ADC_Init(void) {
    ADPCFG = 0x0000; //���ýӿ�Ϊģ��ӿ�
    ADCON1 = 0x00e0; //SSRC=111 �Զ�ת��
    ADCON2 = 0x003c; //SMPI=1111 ÿ16���ж�һ��
    ADCON3 = 0x1f1f; //����ʱ�� 15Tad, 1Tad= �ڲ� Tcy/2?
    ADCSSL = 0x0000; //
}

unsigned int ADC_Read(unsigned char chs) {
    unsigned int value = 0;
    unsigned char i;
    if (chs > 16)  return 0;
    
    ADCON1bits.ADON = 1; //����ADC
    ADCHS = chs;
    IFS0bits.ADIF = 0;
    ADCON1bits.ASAM = 1;
    while (!IFS0bits.ADIF);
    ADCON1bits.ASAM = 0;
    for (i = 0; i < 16; i++){
        value = value + *(&ADCBUF0 + i);
    }
    value = value >> 4;
    ADCON1bits.ADON = 0; //�ر�ADC
    return (value);
}
