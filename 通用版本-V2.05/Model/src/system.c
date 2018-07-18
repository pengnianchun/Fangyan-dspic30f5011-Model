#include "system.h"

#define OUT1 gPout.BITS.O1
#define OUT2 gPout.BITS.O2
#define OUT3 gPout.BITS.O3
#define OUT4 gPout.BITS.O4
#define OUT5 gPout.BITS.O5
#define OUT6 gPout.BITS.O6
#define OUT7 gPout.BITS.O7
#define OUT8 gPout.BITS.O8
#define OUT9 gPout.BITS.O9
#define OUT10 gPout.BITS.O10
#define OUT11 gPout.BITS.O11
#define OUT12 gPout.BITS.O12
#define OUT13 gPout.BITS.O13
#define OUT14 gPout.BITS.O14
#define OUT15 gPout.BITS.O15
#define OD gPout.BITS.OD


//总里程计数
//总里程数低位EEROM
unsigned int _EEDATA(2) EE_TOTAL_MILES_LOW_1[16] = {
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 0) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 1) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 2) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 3) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 4) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 5) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 6) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 7) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 8) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 9) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 10) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 11) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 12) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 13) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 14) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 15) ? (1) : (0))),
};
unsigned int _EEDATA(2) EE_TOTAL_MILES_LOW_2[16] = {
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 0) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 1) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 2) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 3) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 4) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 5) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 6) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 7) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 8) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 9) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 10) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 11) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 12) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 13) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 14) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 15) ? (1) : (0))),
};
unsigned int _EEDATA(2) EE_TOTAL_MILES_LOW_3[16] = {
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 0) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 1) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 2) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 3) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 4) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 5) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 6) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 7) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 8) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 9) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 10) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 11) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 12) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 13) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 14) ? (1) : (0))),
    ((TOTAL_MILES / 16) + (((TOTAL_MILES % 16) > 15) ? (1) : (0))),
};

//总里程数高位EEROM
unsigned int _EEDATA(2) EE_TOTAL_MILES_HIGH_1 = (TOTAL_MILES >> 16);   //_EEDATA(2)指定记忆位置的边界值以2byte为单位
unsigned int _EEDATA(2) EE_TOTAL_MILES_HIGH_2 = (TOTAL_MILES >> 16);
unsigned int _EEDATA(2) EE_TOTAL_MILES_HIGH_3 = (TOTAL_MILES >> 16);

//百米脉冲数EEROM备份
unsigned int _EEDATA(2) EE_HM_PLUSE_1 = HM_PLUSE;
unsigned int _EEDATA(2) EE_HM_PLUSE_2 = HM_PLUSE;
unsigned int _EEDATA(2) EE_HM_PLUSE_3 = HM_PLUSE;

////模块地址EEROM备份 0x01 为前部模块 0x02 为后模块 0x03 为顶部模块
unsigned int _EEDATA(2) EE_ADDRESS_1 = MT_ADDR; //地址 0X01 前模块
unsigned int _EEDATA(2) EE_ADDRESS_2 = MT_ADDR;
unsigned int _EEDATA(2) EE_ADDRESS_3 = MT_ADDR;


unsigned int __attribute__((address(0x7FFFFE))) _EEDATA(2) EE_BT_ADDRESS = MT_ADDR; //BootLoader 地址


//模块地址 0x01 为前部模块 0x02 为顶部模块  0x03 为后部模块
unsigned int g_address = MT_ADDR; //全局定义 
unsigned int e_address = MT_ADDR; //EEPROM存储地址
unsigned int hw_address = MT_ADDR; //硬线地址

//总里程定义
unsigned long e_total_miles = TOTAL_MILES;
//总运行时间
unsigned long e_total_time = 0;
//仪表通过CAN发送开关  ON 与雨刮控制
MUIC_KEY gYBKey;

unsigned int ADR1 = 0; //第一路传感器电阻值
unsigned int ADR2 = 0; //第二路传感器电阻值�

unsigned int ADV1 = 0; //第一路传感器电压值
unsigned int ADV2 = 0; //第二路传感器电压值���������ֵ

unsigned int PCUR[15];  //�����������

void EEROM_WriteHMPulse(void) {
    EEROM_WriteWord(__builtin_tbladdress(&EE_HM_PLUSE_1), e_hm_pulse);  //__builtin_tbladdress(&EE_HM_PLUSE_1)  取地址，写三次
    EEROM_WriteWord(__builtin_tbladdress(&EE_HM_PLUSE_2), e_hm_pulse);
    EEROM_WriteWord(__builtin_tbladdress(&EE_HM_PLUSE_3), e_hm_pulse);
}

void EEROM_ReadHMPulse(void) {
    unsigned int dump[3] = {0, 0, 0};                                   //定义三个数组，三个备份位置
    dump[0] = EEROM_ReadWord(__builtin_tbladdress(&EE_HM_PLUSE_1));     
    dump[1] = EEROM_ReadWord(__builtin_tbladdress(&EE_HM_PLUSE_2));
    dump[2] = EEROM_ReadWord(__builtin_tbladdress(&EE_HM_PLUSE_3));

    if (dump[0] == dump[1]) e_hm_pulse = dump[0];                     
    else if (dump[1] == dump[2]) e_hm_pulse = dump[1];
    else if (dump[2] == dump[0]) e_hm_pulse = dump[2];
    else e_hm_pulse = HM_PLUSE;  //默认值
}

void EEROM_WriteTotalMiles(void) {
    unsigned int high = 0;
    unsigned int low = 0;

    high = (e_total_miles >> 16);
    EEROM_WriteWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_1), high);
    EEROM_WriteWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_2), high);
    EEROM_WriteWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_3), high);

    low = (unsigned int) e_total_miles;
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_1), low);
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_2), low);
    EEROM_WriteLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_3), low);
}

void EEROM_ReadTotalMiles(void) {
    unsigned int low[3] = {0, 0, 0};             //低位
    unsigned int high[3] = {0, 0, 0};            //高位

    unsigned int dump_l = 0;
    unsigned int dump_h = 0;

    low[0] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_1));
    low[1] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_2));
    low[2] = EEROM_ReadLowMiles(__builtin_tbladdress(&EE_TOTAL_MILES_LOW_3));

    if (low[0] == low[1]) dump_l = low[0];
    else if (low[1] == low[2]) dump_l = low[1];
    else if (low[2] == low[0]) dump_l = low[2];
    else dump_l = low[2];

    high[0] = EEROM_ReadWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_1));
    high[1] = EEROM_ReadWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_2));
    high[2] = EEROM_ReadWord(__builtin_tbladdress(&EE_TOTAL_MILES_HIGH_3));

    if (high[0] == high[1]) dump_h = high[0];
    else if (high[1] == high[2]) dump_h = high[1];
    else if (high[2] == high[0]) dump_h = high[2];               //没有两两相等
    else 
    {
        if (high[0] != 0xFFFF) dump_h = high[0];                 //取非0XFFFF数据
        else if (high[1] != 0xFFFF) dump_h = high[1];
        else if (high[2] != 0xFFFF) dump_h = high[2];
    }
    e_total_miles = ((unsigned long) dump_h << 16) + dump_l;     //统计总里程
}

void EEROM_WriteAddress(void) {
    EEROM_WriteWord(__builtin_tbladdress(&EE_ADDRESS_1), e_address);   
    EEROM_WriteWord(__builtin_tbladdress(&EE_ADDRESS_2), e_address);
    EEROM_WriteWord(__builtin_tbladdress(&EE_ADDRESS_3), e_address);
    EEROM_WriteWord(__builtin_tbladdress(&EE_BT_ADDRESS), e_address);
}

void EEROM_ReadAddress(void) {
    unsigned int dump[3] = {0, 0, 0};
    dump[0] = EEROM_ReadWord(__builtin_tbladdress(&EE_ADDRESS_1));
    dump[1] = EEROM_ReadWord(__builtin_tbladdress(&EE_ADDRESS_2));
    dump[2] = EEROM_ReadWord(__builtin_tbladdress(&EE_ADDRESS_3));

    if (dump[0] == dump[1]) e_address = dump[0];
    else if (dump[1] == dump[2]) e_address = dump[1];
    else if (dump[2] == dump[1]) e_address = dump[2];
    else e_address = 0;
}

void get_hw_address(void) {
    unsigned char i;
    unsigned char dump[3] = {0, 0, 0};

    for (i = 0; i < 3; i++) {                //硬线读三次
        __delay_ms(10);
        mc33978_ReadSwtichStatus();
        if ((KL13 == 0) && (KL14 == 0)) dump[i] = 1; //前模块
        else if ((KL13 == 0) && (KL14 == 1)) dump[i] = 2; //顶模块
        else if ((KL13 == 1) && (KL14 == 0)) dump[i] = 3; //后模块
        else dump[i] = 0;
    }

    if (dump[0] == dump[1]) hw_address = dump[0];        //取有两个相同的数据中的一个
    else if (dump[1] == dump[2]) hw_address = dump[1];
    else if (dump[2] == dump[0]) hw_address = dump[2];
    else hw_address = 0;
    if (hw_address) {//模块切换成可互换型
        g_address = hw_address;
    } 
    
}


void system_Init(void) {
    ADPCFG = 0xFFFF;        //ADC analog input 1 
    ADC_Init();             //AD initialization
    POUT_Init();            //power output
    SPWR_EN_DR = 0;         //Digital output 0 
    SPWR_EN = 1;            //sensor power supply

    VS_CTL_DR = 0;         
    VS_CTL = 1;             //使能上臂电阻电源

    C1_WK_DR = 0;           
    C1_WK = 0;
    
    POWPP_DR = 0;
    POWPP = 0;
    
    PO16_DR = 0;           //雨刮慢档控制
    PO16 = 1;

    mc33978_Init();         //33978初始化  
    mc33978_DeviceConfiguration(0x81); //KH1和KL15为控火开关
    //mc33978_write(0x07, 0x00, 0x2D, 0x22); //0x2D,SG13,SG11,SG10,SG8=1;0x22 SG5=1; SG1=1 ; 

    EEROM_ReadHMPulse();    //读取百米脉冲数
    EEROM_ReadTotalMiles(); //读总里程数
    EEROM_ReadAddress();    //读模块地址

    get_hw_address();       //获取硬线模块地址

    TIMER1_Init();
    INT1_Init();
    TIMER3_Init();
    CAN1_Init();
    TIM5_Init();
}


void Test(void){
    OUT1=1;
    OUT2=1;
    OUT3=1;
    OUT4=1;
    OUT5=1;
    OUT6=1;
    OUT7=1;
    OUT8=1;
    OUT9=1;
    OUT10=1;
    OUT11=1;
    OUT12=1;
    OUT13=1;
    OUT14=1;
    OUT15=1;
    
    /*
    if(KH1 || KL1 || ADD){
        OUT1=1;
    }else OUT1=0;
    OUT2=KL2;
    OUT3=KL3;
    OUT4=KL4;
    OUT5=KL5;
    OUT6=KL6;
    OUT7=KL7;
    OUT8=KL8;
    OUT9=KL9;
    OUT10=KL10;
    OUT11=KL11;
    OUT12=KL12;
    OUT13=KL13;
    OUT14=KL14;
    OUT15=KL15;
    */
}

void can_send_message_key(void) {
    CAN_MESSAGE msg;
    unsigned int speed = 0;

    msg.id = 0x680 + g_address;
    msg.data[0] = gKey.BYTES[0];
    msg.data[1] = gKey.BYTES[1];
    msg.data[2] = gKey.BYTES[2];

    msg.data[3] = (unsigned char) (freq);       //频率信号低8位
    msg.data[4] = (unsigned char) (freq >> 8);  //频率信号高8位

    speed = (unsigned int) ((3600.0 * freq) / e_hm_pulse);
    msg.data[5] = (unsigned char) (speed);      //车速信号低8位
    msg.data[6] = (unsigned char) (speed >> 8);

    msg.data[7] = addr_eeror;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);
}

void can_send_message_Pcur1(void) {
    CAN_MESSAGE msg;
    msg.id = 0x620 + g_address;
    msg.data[0] = (unsigned char) PCUR[0];
    msg.data[1] = (unsigned char)(PCUR[0] >> 8);
    msg.data[2] = (unsigned char) PCUR[1];
    msg.data[3] = (unsigned char)(PCUR[1] >> 8);
    msg.data[4] = (unsigned char) PCUR[2];
    msg.data[5] = (unsigned char)(PCUR[2] >> 8);
    msg.data[6] = (unsigned char) PCUR[3];
    msg.data[7] = (unsigned char)(PCUR[3] >> 8);

    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);
}

void can_send_message_Pcur2(void) {
    CAN_MESSAGE msg;
    msg.id = 0x630 + g_address;
    msg.data[0] = (unsigned char) PCUR[4];
    msg.data[1] = (unsigned char)(PCUR[4] >> 8);
    msg.data[2] = (unsigned char) PCUR[5];
    msg.data[3] = (unsigned char)(PCUR[5] >> 8);
    msg.data[4] = (unsigned char) PCUR[6];
    msg.data[5] = (unsigned char)(PCUR[6] >> 8);
    msg.data[6] = (unsigned char) PCUR[7];
    msg.data[7] = (unsigned char)(PCUR[7] >> 8);

    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);
}

void can_send_message_Pcur3(void) {
    CAN_MESSAGE msg;
    msg.id = 0x640 + g_address;
    msg.data[0] = (unsigned char) PCUR[8];
    msg.data[1] = (unsigned char)(PCUR[8] >> 8);
    msg.data[2] = (unsigned char) PCUR[9];
    msg.data[3] = (unsigned char)(PCUR[9] >> 8);
    msg.data[4] = (unsigned char) PCUR[10];
    msg.data[5] = (unsigned char)(PCUR[10] >> 8);
    msg.data[6] = (unsigned char) PCUR[11];
    msg.data[7] = (unsigned char)(PCUR[11] >> 8);
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);
}

void can_send_message_Pcur4(void) {
    CAN_MESSAGE msg;
    msg.id = 0x650 + g_address;
    msg.data[0] = (unsigned char) PCUR[12];
    msg.data[1] = (unsigned char)(PCUR[12] >> 8);
    msg.data[2] = (unsigned char) PCUR[13];
    msg.data[3] = (unsigned char)(PCUR[13] >> 8);
    msg.data[4] = (unsigned char) PCUR[14];
    msg.data[5] = (unsigned char)(PCUR[14] >> 8);

    msg.len = 0x06;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);
}

void read_ADR(void) {
    unsigned char i;
    unsigned int Vser = 0;
    unsigned int Rser1 = 0;
    unsigned int Rser2 = 0;
    unsigned int dump;
    
    mc33978_AMUX(0x09); //SG8
    __delay_ms(2);
    Vser = ADC_Read(0x00); //

    mc33978_AMUX(0x0E); //SG13
    __delay_ms(2);
    Rser1 = ADC_Read(0x00); //   

    mc33978_AMUX(0x0C); //SG11
    __delay_ms(2);
    Rser2 = ADC_Read(0x00); //

    if (Vser > Rser1) { //5V参考电压
        ADR1 = (unsigned int) (5000.0 * Rser1 / (Vser - Rser1));
        if (ADR1 > 10000) ADR1 = 10000;               
    } else {
        ADR1 = 10000;
    }
    
    ADV1 = (unsigned int) (5000.0 * Rser1 / 4096);
    if (ADV1 > 5000) ADV1 = 5000;

    if (Vser > Rser2) {
        ADR2 = (unsigned int) (5000.0 * Rser2 / (Vser - Rser2));
        if (ADR2 > 10000) ADR2 = 10000;
    } else {
        ADR2 = 10000;
    }
    
    ADV2 = (unsigned int) (5000.0 * Rser2 / 4096);
    if (ADV2 > 5000) ADV2 = 5000;
      
    dump = gPout.WORDS;
    for (i = 0; i < 15; i++) {
        if (((dump & 0x01) == 0x01) && (pf[i] != 0x02)) {
            PCUR[i] = (unsigned int) (pcur[i] * 12.2); //实际电流放大1000倍
        } else PCUR[i] = 0;
        dump = dump >> 1;
    }

}

void can_send_message_ADR(void) {
    CAN_MESSAGE msg;
    msg.id = 0x670 + g_address;

    msg.data[0] = (unsigned char) (ADR1); //ADR1信号
    msg.data[1] = (unsigned char) (ADR1 >> 8);

    msg.data[2] = (unsigned char) (ADR2); //ADR2信号
    msg.data[3] = (unsigned char) (ADR2 >> 8);
    //msg.data[4] = e_address;
    msg.data[4] = (unsigned char) (ADV1); //ADV1信号
    msg.data[5] = (unsigned char) (ADV1 >> 8);

    msg.data[6] = (unsigned char) (ADV2); //ADV2信号
    msg.data[7] = (unsigned char) (ADV2 >> 8);

    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

}

void can_send_message_st(void) {
    CAN_MESSAGE msg;
    msg.id = 0x560 + g_address;
    msg.data[0] = gPout.BYTES[0]; //(unsigned char) (128 * FPO8 + 64 * FPO7 + 32 * FPO6 + 16 * FPO5 + 8 * FPO4 + 4 * FPO3 + 2 * FPO2 + FPO1);
    msg.data[1] = gPout.BYTES[1]; //(unsigned char) (128 * OD + 64 * FPO15 + 32 * FPO14 + 16 * FPO13 + 8 * FPO12 + 4 * FPO11 + 2 * FPO10 + FPO9);
    msg.data[2] = (pf[0]&0x03) +((pf[1] << 2) & 0x0c)+(pf[2] << 4 & 0x30)+(pf[3] << 6 & 0xc0);
    msg.data[3] = (pf[4]&0x03) +((pf[5] << 2) & 0x0c)+(pf[6] << 4 & 0x30)+(pf[7] << 6 & 0xc0);
    msg.data[4] = (pf[8]&0x03) +((pf[9] << 2) & 0x0c)+(pf[10] << 4 & 0x30)+(pf[11] << 6 & 0xc0);
    msg.data[5] = (pf[12]&0x03) +((pf[13] << 2) & 0x0c)+(pf[14] << 4 & 0x30);
    msg.data[6] = VERESION;

    msg.len = 0x07;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);

    // can1_send_message(0x560 + g, data, 8);
}

void can_send_message_mileage(void) {
    CAN_MESSAGE msg;
    msg.data[0] = (unsigned char) (e_total_miles); //低八位
    msg.data[1] = (unsigned char) (e_total_miles >> 8); //二级八位
    msg.data[2] = (unsigned char) (e_total_miles >> 16); //三级八位
    msg.data[3] = (unsigned char) (e_total_miles >> 24); //高八位
    msg.data[4] = (unsigned char) (single_miles); //车速信号
    msg.data[5] = (unsigned char) (single_miles >> 8);
    msg.data[6] = (unsigned char) (e_hm_pulse); //百米脉冲数
    msg.data[7] = (unsigned char) (e_hm_pulse >> 8);
    msg.id = 0x450 + g_address;
    msg.len = 0x08;
    msg.type = 0x01;
    CAN1_SendMessage(&msg);
    //can1_send_message(0x450 + g_address, data, 8);
}

void delay(unsigned int t){
  unsigned int i;
  for(i=0;i<t;i++);
}

unsigned int delay_10s = 1000;      //上电10s
unsigned char F10ms = 0;
unsigned char F50ms = 0;
unsigned char F100ms = 0;
unsigned char F500ms = 0;
unsigned char F1000ms = 0;
unsigned int  ICcan_count = 0;

void __attribute__((__interrupt__, auto_psv)) _T1Interrupt(void) {              //10ms中断一次

    static unsigned int count0 = 0;
    static unsigned int count1 = 0;
    static unsigned int count2 = 0;
    static unsigned int count3 = 0;

    if (delay_10s > 0) delay_10s--; //10秒钟使能地址选择
    if (system_wake_time > 0) system_wake_time--;

    F10ms = 1;

    if (count0 >= 5) {       //产生50ms时基
        count0 = 0;
        F50ms = 1;
    } else count0++;

    if (count1 >= 10) {      //产生100ms时基
        count1 = 0;
        F100ms = 1;
        if (ICcan_count >= CAN_TIME)ICcan_count = CAN_TIME;
        else ICcan_count++;
    } else count1++;

    if (count2 >= 50) {      //产生500ms时基
        count2 = 0;
        F500ms = 1;
    } else count2++;

    if (count3 >= 100) {     //产生1000ms时基
        count3 = 0;
        F1000ms = 1;
    } else count3++;

    /////雨刮程序增加 20120811（毛平生）
    
    if (wipe_int_time > 0) wipe_int_time--; //雨刮间歇时间
    if (wash_time > 0) wash_time--; //雨刮洗涤时间
    if (wipe_stop_time > 0)wipe_stop_time--;
    
    
    _T1IF = 0;              //清标志
}


unsigned int wash_time = 300; //3秒
unsigned int wipe_int_time = 0;
unsigned int wipe_stop_time = 2000; //20秒
unsigned char DELAY_START = 0;
unsigned char DELAY_END = 0;

//雨刮程序

void rain_wape(void) {
    static unsigned char RAIN_RST = 0;   
    //RAIN_SLOW	       雨刮慢档
    //RAIN_INTERVAL	   雨刮间歇档
    //RAIN_HIGH	       雨刮快档
    //RAIN_SPRAY	   雨刮喷水档

    if (K_ON && RAIN_SLOW && !RAIN_HIGH && !RAIN_INTERVAL) {//慢档
        if (DELAY_START == 0) {
            DELAY_START = 1;
            wipe_wpp_time = 200;
        }
        POWPP = 0;
        if (wipe_wpp_time == 0) {
            PO16 = 1;
            OUT2 = 1; //雨刮慢档电机
            OUT1 = 0;
            wash_time = 0;
            DELAY_START = 0;
            DELAY_END = 0;
        }
    }
    if (K_ON && RAIN_HIGH && !RAIN_INTERVAL) {//快档 快档慢档同时有效时，快档有效
        if (DELAY_START == 0) {
            DELAY_START = 1;
            wipe_wpp_time = 200;
        }
        POWPP = 0;
        if (wipe_wpp_time == 0) {
            OUT2 = 0;
            PO16 = 0;
            OUT1 = 1; //雨刮快档电机
            wash_time = 0;
            DELAY_START = 0;
            DELAY_END = 0;
        }
    }
    if (K_ON && RAIN_SPRAY) {
        OUT3 = 1; //喷水电机
        if (DELAY_START == 0) {
            DELAY_START = 1;
            wipe_wpp_time = 200;
        }
        POWPP = 0;
        if (wipe_wpp_time == 0) {
            PO16 = 1;
            OUT2 = 1; //雨刮慢档电机
            OUT1 = 0;
            wash_time = 300;
            DELAY_START = 0;
            DELAY_END = 0;
        }
    } else {
        if (wash_time <= 0) OUT3 = 0;
    }
    if (K_ON && !RAIN_SLOW && !RAIN_HIGH && RAIN_INTERVAL) {//间歇档
        if (wipe_int_time == 0) {
            if (DELAY_START == 0) {
                DELAY_START = 1;
                wipe_wpp_time = 200;
            }
            POWPP = 0;
            if (wipe_wpp_time == 0) {
                PO16 = 1;
                OUT2 = 1;
                OUT1 = 0;
                wash_time = 0;
                DELAY_START = 0;
                DELAY_END = 0;
            }
        }
    }
    //雨刮无操作，需要停止工作
    if (!K_ON || (!RAIN_SLOW && !RAIN_HIGH && !RAIN_INTERVAL && !RAIN_SPRAY && (wash_time == 0))) {
        /*if (!ADD && wipe_stop_time > 0) {//雨刮半途掉电，上电可自动归位
            OUT1 = 0;
            OUT2 = 1;
            OUT3 = 0;
            PO16 = 1;
            wipe_int_time = 0;
        }*/
        if (!ADD && OUT1 && wipe_stop_time > 0) {
            OUT1 = 0;
            OUT2 = 1;
            OUT3 = 0;
            PO16 = 1;
            wipe_int_time = 0;
        }
        if (wipe_stop_time == 0) { //雨刮操作开关断开 20内强制关闭雨刮 保护雨刮电机
            OUT1 = 0;
            OUT2 = 0;
            OUT3 = 0;
            PO16 = 1;
            wipe_int_time = 0;
        }
    } else {
        wipe_stop_time = 2000;
    }

    if (ADD == 1 && RAIN_RST == 0) {//雨刮复位开关 ADD==1
        if (K_ON) {
            if (!RAIN_SLOW && !RAIN_HIGH && !RAIN_INTERVAL && !RAIN_SPRAY && (wash_time == 0)) {
                OUT1 = 0;
                OUT2 = 0;   
                PO16 = 1;
            }
            if (RAIN_INTERVAL) {//间歇
                OUT2 = 0;
                PO16 = 1;
                wipe_int_time = 300;
            }
        } else {
            OUT1 = 0;
            OUT2 = 0;
            OUT3 = 0;
            PO16 = 1;
            wipe_int_time = 0;
        }
    }
    
    if (ADD) {
        if ((OUT1 == 0) && (OUT2 == 0)) {
            if (DELAY_END == 0) {
                DELAY_END = 1;
                wipe_wpp_time = 15;//打开放电延时时间为30-10=20ms,实际测量发现输出关短有10ms延时
            }
            if (wipe_wpp_time == 0) {
                POWPP = 1;
                DELAY_END = 0;
                DELAY_START = 0;
            }
        }
    }
    
    RAIN_RST = ADD;
}

unsigned char addr_eeror = 0; //地址错误
unsigned int system_wake_time = 6000; //60秒休眠
void __attribute__((__interrupt__, auto_psv)) _C1Interrupt(void) {             //CAN总线接受中断
    unsigned char i = 0;
    static unsigned int can_time = 0;

    CAN_MESSAGE message;
    unsigned long yb_total_miles = 0;
    unsigned int yb_hm_pulse = 0;

    if (C1INTFbits.ERRIF) { //接收错误
        C1INTFbits.ERRIF = 0; // 添加错误处理代码
        CAN1_Init();          //重启CAN
        C1RX0CONbits.RXFUL = 0;
    }
    if (C1INTFbits.IVRIF) {
        C1INTFbits.IVRIF = 0; //数据无效
        C1RX0CONbits.RXFUL = 0;
    }
    if(C1INTFbits.WAKIF){
        
//       C1INTFbits.WAKIF=0;
//       
//       CAN1_OperationModeNormal(); //进入工作模式      
//       C1_WK_DR = 0;
//       C1_WK = 0;
//       SPWR_EN_DR = 0;
//       SPWR_EN = 1; //开启传感器电压
//
//       VS_CTL_DR = 0;
//       VS_CTL = 1; //使能上臂电阻电源
       
    }
    
    
    if (C1RX0CONbits.RXFUL) { //数据有效
        CAN1_ReceiveMessage(&message);
        switch (message.id) {
            case 0x681:
                if (g_address == 0x01) 
                {
                    if (can_time >= 3) {
                        addr_eeror = 0x01; //地址错误
                        can_time = 0;
                    } else can_time++;
                }
                break;

            case 0x682:
                if (g_address == 0x02) {
                    if (can_time >= 3) {
                        addr_eeror = 0x01; //地址错误
                        can_time = 0;
                    } else can_time++;
                }
                break;

            case 0x683:
                if (g_address == 0x03) {
                    if (can_time >= 3) {
                        addr_eeror = 0x01; //地址错误
                        can_time = 0;
                    } else can_time++;
                }
                break;

            case 0x6A4:
                ICcan_count = 0;
                system_wake_time = 6000; //休眠计时器清除
                if (g_address == 0x01) {   
                    gPout.BITS.O4 = (message.data[0] >> 3)&0x01;
                    gPout.BITS.O5 = (message.data[0] >> 4)&0x01;
                    gPout.BITS.O6 = (message.data[0] >> 5)&0x01;
                    gPout.BITS.O7 = (message.data[0] >> 6)&0x01;
                    gPout.BITS.O8 = (message.data[0] >> 7)&0x01;
                    //gPout.BYTES[0] = message.data[0];
                    gPout.BYTES[1] = message.data[1];
                } else if (g_address == 0x02) {
                    gPout.BYTES[0] = message.data[2];
                    gPout.BYTES[1] = message.data[3];
                } else if (g_address == 0x03) {
                    gPout.BYTES[0] = message.data[4];
                    gPout.BYTES[1] = message.data[5];
                }
                gYBKey.BYTE = message.data[6];

                break;

            case 0x454: //仪表设定里程与速比，模块记录

                yb_total_miles = (((unsigned long) message.data[3]) << 24)+
                        (((unsigned long) message.data[2]) << 16)+
                        (((unsigned long) message.data[1]) << 8) + message.data[0];
                if (yb_total_miles != e_total_miles) { //判断存储，更新总里程
                    e_total_miles = yb_total_miles;
                    EEROM_WriteTotalMiles();
                }

                yb_hm_pulse = ((unsigned int) (message.data[7]) << 8) + message.data[6];
                if (yb_hm_pulse != e_hm_pulse) {//更新脉冲数
                    e_hm_pulse = yb_hm_pulse;
                    EEROM_WriteHMPulse();
                }
                break;
               
            default:
                if (message.id == g_address) {
                    system_wake_time = 0; //休眠计时器清除
                    if (message.data[0] == 0xC1) {
                        __asm__ volatile ("reset");
                    }
                }
                if (message.id == 0x610) {
                    system_wake_time = 0; //休眠计时器清除
                    if (message.data[0] == 0x55) {
                        if (message.data[1] == g_address) {
                            gPout.BYTES[0] = message.data[2];
                            gPout.BYTES[1] = message.data[3];
                        }
                    } else if (message.data[0] == 0x56) {
                        if (message.data[1] == g_address) {
                            e_hm_pulse = message.data[2]+((unsigned int) message.data[3] << 8);
                            EEROM_WriteTotalMiles();
                        }
                    } else if (message.data[0] == 0x58) { //上电后更新
                        if (message.data[1] == g_address) {
                            e_address = message.data[2];
                            EEROM_WriteAddress();
                        }
                    } else if (message.data[0] == 0x59) {
                        if (message.data[1] == g_address) {
                            e_total_miles = (unsigned char) message.data[2]
                                    +((unsigned int) message.data[3] << 8)
                                    +((unsigned long) message.data[4] << 16)
                                    +((unsigned long) message.data[5] << 24);
                            EEROM_WriteTotalMiles();
                        }
                    }
                }
                if (message.id == 0x500 + g_address) {
                    for (i = 0; i < 8; i++) {
                        pct_cut[i] = message.data[i];
                    }
                }
                if (message.id == 0x510 + g_address) {
                    for (i = 0; i < 7; i++) {
                        pct_cut[i + 8] = message.data[i];
                        pct_time = message.data[7];
                    }
                }
                break;
        }
    }
    C1INTF = 0; /* the individual flag register cleared */
    C1RX0CONbits.RXFUL = 0;
    _C1IF = 0;
}

void TIM5_Init(void){   
    T5CON = 0; //1：1 分频   8MHz
    TMR5 = 0;
    PR5 = 7999;  //1ms中断一次
    _T5IF = 0;
    _T5IE = 1;
    T5CONbits.TON=1;
}

unsigned int wipe_wpp_time = 200; //200毫秒

void __attribute__((__interrupt__, auto_psv)) _T5Interrupt(void) { //1ms  

    if (wipe_wpp_time > 0)wipe_wpp_time--;//电机上电延迟时间    
    
    _T5IF = 0;
}