#include "BSP.h"

/*****************Masks for bit opern***************/
#define CAN_ABAT                        0x1000
#define CAN_TXBO                        0x2000
#define CAN_RXEP                        0x0800
#define CAN_TXEP                        0x1000
#define CAN_RXFUL                       0x0080
#define CAN_TXREQ                       0x0008

/* defines for CiCTRL (to be used for CANiSetOperationMode functions) */
/* these defines are such that, when used will clear ABAT bit */

#define CAN_CAPTURE_EN                  0xAF00
#define CAN_CAPTURE_DIS                 0x2F00

#define CAN_IDLE_STOP                   0xAF00
#define CAN_IDLE_CON                    0x8F00

#define CAN_MASTERCLOCK_1               0xAF00
#define CAN_MASTERCLOCK_0               0xA700

#define CAN_REQ_OPERMODE_NOR            0xA800
#define CAN_REQ_OPERMODE_DIS            0xA900
#define CAN_REQ_OPERMODE_LOOPBK         0xAA00
#define CAN_REQ_OPERMODE_LISTENONLY     0xAB00
#define CAN_REQ_OPERMODE_CONFIG         0xAC00
#define CAN_REQ_OPERMODE_LISTENALL      0xAF00

/* defines for CiCTRL (to be used for CANiSetOperationModeNoWait functions) */
/* these defines are such that, when used will set ABAT bit */

#define CAN_CAPTURE_EN_NO_WAIT          0xBF00
#define CAN_CAPTURE_DIS_NO_WAIT         0x3F00

#define CAN_IDLE_STOP_NO_WAIT           0xBF00
#define CAN_IDLE_CON_NO_WAIT            0x9F00

#define CAN_MASTERCLOCK_1_NO_WAIT       0xBF00
#define CAN_MASTERCLOCK_0_NO_WAIT       0xB700

#define CAN_REQ_OPERMODE_NOR_NO_WAIT    0xB800
#define CAN_REQ_OPERMODE_DIS_NO_WAIT    0xB900
#define CAN_REQ_OPERMODE_LOOPBK_NO_WAIT 0xBA00
#define CAN_REQ_OPERMODE_LISTENONLY_NO_WAIT 0xBB00
#define CAN_REQ_OPERMODE_CONFIG_NO_WAIT 0xBC00
#define CAN_REQ_OPERMODE_LISTENALL_NO_WAIT 0xBF00

/*configuration of CiRXMnSID */

#define CAN_MASK_SID(x)                 ( ((x & 0x07C0) << 2) | ((x & 0x003F) << 2) | 0x0001 )

#define CAN_MATCH_FILTER_TYPE           0x1FFD
#define CAN_IGNORE_FILTER_TYPE          0x1FFC

/*configuration of CiRXMnEIDH and CiRXMnEIDL */

#define CAN_MASK_EID(x)                 ( (((unsigned long)x & 0x3C000) << 10) | (((unsigned long)x & 0x03FC0) << 10) | (((unsigned long)x & 0x0003F) << 10) )

/* configuration of CiRXFnSID */

#define CAN_FILTER_SID(x)               ( ((x & 0x07C0) << 2) | ((x & 0x003F) << 2) | 0x0001 )

#define CAN_RX_EID_EN                   0x1FFD
#define CAN_RX_EID_DIS                  0x1FFC

/* configuration of CiRXFnEIDH and C1RXFnEIDL */

#define CAN_FILTER_EID(x)               ( (((unsigned long)x & 0x3C000) << 10) | (((unsigned long)x & 0x03FC0) << 10) | (((unsigned long)x & 0x0003F) << 10) )

/* configuration of CiTXxSID */

#define CAN_TX_SID(x)                   ( ((x & 0x07C0) << 5) | ((x & 0x003F) << 2) | 0x0003 )

#define CAN_SUB_REM_TX_REQ              0xF8FF
#define CAN_SUB_NOR_TX_REQ              0xF8FD

#define CAN_TX_EID_EN                   0xF8FF
#define CAN_TX_EID_DIS                  0xF8FE

/* configuration of CiTXxEID and CiTXxDLC */

#define CAN_TX_EID(x)                   ( (((unsigned long)x & 0x3C000) << 14) | (((unsigned long)x & 0x03FC0) << 10) | (((unsigned long)x & 0x0003F) << 10) | 0x000003F8 )

#define CAN_REM_TX_REQ                  0xF0FFFFF8
#define CAN_NOR_TX_REQ                  0xF0FFFDF8

#define CAN_DATALEN_0                   0xF0FFFF80
#define CAN_DATALEN_1                   0xF0FFFF88
#define CAN_DATALEN_2                   0xF0FFFF90
#define CAN_DATALEN_3                   0xF0FFFF98
#define CAN_DATALEN_4                   0xF0FFFFA0
#define CAN_DATALEN_5                   0xF0FFFFA8
#define CAN_DATALEN_6                   0xF0FFFFB0
#define CAN_DATALEN_7                   0xF0FFFFB8
#define CAN_DATALEN_8                   0xF0FFFFC0

/* CiCFG1 */
#define CAN_SYNC_JUMP_WIDTH1            0x003F
#define CAN_SYNC_JUMP_WIDTH2            0x007F
#define CAN_SYNC_JUMP_WIDTH3            0x00BF
#define CAN_SYNC_JUMP_WIDTH4            0x00FF

#define CAN_BAUD_PRE_SCALE(x)           (((x-1) & 0x3f) | 0xC0)

/* CiCFG2 */
#define CAN_WAKEUP_BY_FILTER_EN         0x47FF
#define CAN_WAKEUP_BY_FILTER_DIS        0x07FF

#define CAN_PHASE_SEG2_TQ(x)            ((((x-1) & 0x7) << 8) | 0x40FF)

#define CAN_PHASE_SEG1_TQ(x)            ((((x-1) & 0x7) << 3) | 0x47C7)

#define CAN_PROPAGATIONTIME_SEG_TQ(x)   (((x-1) & 0x7) | 0x47F8)

#define CAN_SEG2_FREE_PROG              0x47FF
#define CAN_SEG2_TIME_LIMIT_SET         0x477F

#define CAN_SAMPLE3TIMES                0x47FF
#define CAN_SAMPLE1TIME                 0x47BF

/* CiRXnCON */
#define CAN_BUF0_DBLBUFFER_EN           0x0084
#define CAN_BUF0_DBLBUFFER_DIS          0x0080
#define CAN_RXFUL_CLEAR                 0x0004

/* CiTXnCON */
#define CAN_TX_REQ                      0x000B
#define CAN_TX_STOP_REQ                 0x0003

#define CAN_TX_PRIORITY_HIGH            0x000B
#define CAN_TX_PRIORITY_HIGH_INTER      0x000A
#define CAN_TX_PRIORITY_LOW_INTER       0x0009
#define CAN_TX_PRIORITY_LOW             0x0008

/* CiINTE */
#define CAN_INDI_INVMESS_EN             0x00FF
#define CAN_INDI_WAK_EN                 0x00FF
#define CAN_INDI_ERR_EN                 0x00FF
#define CAN_INDI_TXB2_EN                0x00FF
#define CAN_INDI_TXB1_EN                0x00FF
#define CAN_INDI_TXB0_EN                0x00FF
#define CAN_INDI_RXB1_EN                0x00FF
#define CAN_INDI_RXB0_EN                0x00FF

#define CAN_INDI_INVMESS_DIS            0x007F
#define CAN_INDI_WAK_DIS                0x00BF
#define CAN_INDI_ERR_DIS                0x00DF
#define CAN_INDI_TXB2_DIS               0x00EF
#define CAN_INDI_TXB1_DIS               0x00F7
#define CAN_INDI_TXB0_DIS               0x00FB
#define CAN_INDI_RXB1_DIS               0x00FD
#define CAN_INDI_RXB0_DIS               0x00FE



void CAN1_OperationModeStop(void){//静止模式
     //C1CTRL = CAN_IDLE_CON & CAN_CAPTURE_DIS & CAN_MASTERCLOCK_0 & CAN_REQ_OPERMODE_DIS;
     C1CTRLbits.REQOP=0x01;
     while(C1CTRLbits.OPMODE != 1);
}
void CAN1_OperationModeNormal(void){
   // C1CTRL = CAN_IDLE_CON & CAN_CAPTURE_DIS & CAN_MASTERCLOCK_0 & CAN_REQ_OPERMODE_NOR;
    C1CTRLbits.REQOP=0x00;
    while (C1CTRLbits.OPMODE != 0);
}

void CAN1_Init(void) {
  
    C1CTRL = CAN_IDLE_CON & CAN_CAPTURE_DIS & CAN_MASTERCLOCK_0 & CAN_REQ_OPERMODE_CONFIG ;
    while (C1CTRLbits.OPMODE != 4);

    //配置波特率
    C1CFG1 = CAN_SYNC_JUMP_WIDTH1 & CAN_BAUD_PRE_SCALE(4);
    C1CFG2 = CAN_WAKEUP_BY_FILTER_EN  & CAN_PHASE_SEG2_TQ(7) &
            CAN_PHASE_SEG1_TQ(6) & CAN_PROPAGATIONTIME_SEG_TQ(2) &
            CAN_SEG2_FREE_PROG & CAN_SAMPLE1TIME;

    C1RXF0SID = CAN_FILTER_EID(0) & CAN_RX_EID_EN; //接收滤波器
    *((unsigned long *) &C1RXF0EIDH) = CAN_FILTER_EID(0);
    C1RXM0SID = CAN_MASK_EID(0) & CAN_MATCH_FILTER_TYPE; //屏蔽滤波器
    *((unsigned long *) &C1RXM0EIDH) = CAN_MASK_EID(0);

    //接收模式
    C1RX0CON = CAN_RXFUL_CLEAR & CAN_BUF0_DBLBUFFER_DIS;

    //中断使能
    C1INTE = 0x0041; //使能RX0B接收和唤醒中断
    _C1IE = 1;

    C1CTRL = CAN_IDLE_CON & CAN_CAPTURE_DIS & CAN_MASTERCLOCK_0 & CAN_REQ_OPERMODE_NOR;
    while (C1CTRLbits.OPMODE != 0);


}

void CAN2_Init(void) {
    C2CTRL = CAN_IDLE_CON & CAN_MASTERCLOCK_0 & CAN_REQ_OPERMODE_CONFIG
            & CAN_CAPTURE_DIS;
    while (C2CTRLbits.OPMODE != 4);

    //配置波特率
    C2CFG1 = CAN_SYNC_JUMP_WIDTH1 & CAN_BAUD_PRE_SCALE(4);
    C2CFG2 = CAN_WAKEUP_BY_FILTER_DIS & CAN_PHASE_SEG2_TQ(7) &
            CAN_PHASE_SEG1_TQ(6) & CAN_PROPAGATIONTIME_SEG_TQ(2) &
            CAN_SEG2_FREE_PROG & CAN_SAMPLE1TIME;

    C2RXF0SID = CAN_FILTER_EID(0) & CAN_RX_EID_EN; //接收滤波器
    *((unsigned long *) &C2RXF0EIDH) = CAN_FILTER_EID(0);
    C2RXM0SID = CAN_MASK_EID(0) & CAN_MATCH_FILTER_TYPE; //屏蔽滤波器
    *((unsigned long *) &C2RXM0EIDH) = CAN_MASK_EID(0);
    //接收模式
    C2RX0CON = CAN_RXFUL_CLEAR & CAN_BUF0_DBLBUFFER_DIS;

    //中断使能
    C2INTE = 0x0001; //使能RX0B接收和唤醒中断
    _C2IE = 1;

    C2CTRL = CAN_IDLE_CON & CAN_CAPTURE_DIS & CAN_MASTERCLOCK_0 & CAN_REQ_OPERMODE_NOR;
    while (C2CTRLbits.OPMODE != 0);

}

void CAN1_SendMessage(CAN_MESSAGE *message) {
    unsigned long id;
    unsigned char len;
    id = message->id;
    len = message->len;

    if (len > 8)  len = 8;
    if (C1TX0CONbits.TXREQ == 0) {
        C1TX0CON = CAN_TX_STOP_REQ & CAN_TX_PRIORITY_HIGH;
        if (message->type == 1) { //标准帧
            C1TX0SID = (CAN_TX_SID(id)) & CAN_TX_EID_DIS & CAN_SUB_NOR_TX_REQ;
        } else if (message->type == 0) { //扩展帧
            C1TX0SID = (CAN_TX_SID(id >> 18)) & CAN_TX_EID_EN & CAN_SUB_NOR_TX_REQ;
            C1TX0EID = (((CAN_TX_EID(id)) & CAN_NOR_TX_REQ) >> 16);
            C1TX0DLC = (unsigned int) ((CAN_TX_EID(id)) & CAN_NOR_TX_REQ);
        }
        unsigned char i;
        for (i = 0; i < len; i++) {
            *((unsigned char *) &C1TX0B1 + i) = message->data[i];
        }
        C1TX0DLCbits.DLC = len;
        C1TX0CONbits.TXREQ = 1;
    } else if (C1TX1CONbits.TXREQ == 0) {
        C1TX1CON = CAN_TX_STOP_REQ & CAN_TX_PRIORITY_HIGH;
        if (message->type == 1) { //标准帧
            C1TX1SID = (CAN_TX_SID(id)) & CAN_TX_EID_DIS & CAN_SUB_NOR_TX_REQ;
        } else if (message->type == 0) { //扩展帧
            C1TX1SID = (CAN_TX_SID(id >> 18)) & CAN_TX_EID_EN & CAN_SUB_NOR_TX_REQ;
            C1TX1EID = (((CAN_TX_EID(id)) & CAN_NOR_TX_REQ) >> 16);
            C1TX1DLC = (unsigned int) ((CAN_TX_EID(id)) & CAN_NOR_TX_REQ);
        }
        unsigned char i;
        for (i = 0; i < len; i++) {
            *((unsigned char *) &C1TX1B1 + i) = message->data[i];
        }
        C1TX1DLCbits.DLC = len;
        C1TX1CONbits.TXREQ = 1;
    } else if (C1TX2CONbits.TXREQ == 0) {
        C1TX2CON = CAN_TX_STOP_REQ & CAN_TX_PRIORITY_HIGH;
        if (message->type == 1) { //标准帧
            C1TX2SID = (CAN_TX_SID(id)) & CAN_TX_EID_DIS & CAN_SUB_NOR_TX_REQ;
        } else if (message->type == 0) { //扩展帧
            C1TX2SID = (CAN_TX_SID(id >> 18)) & CAN_TX_EID_EN & CAN_SUB_NOR_TX_REQ;
            C1TX2EID = (((CAN_TX_EID(id)) & CAN_NOR_TX_REQ) >> 16);
            C1TX2DLC = (unsigned int) ((CAN_TX_EID(id)) & CAN_NOR_TX_REQ);
        }
        unsigned char i;
        for (i = 0; i < len; i++) {
            *((unsigned char *) &C1TX2B1 + i) = message->data[i];
        }
        C1TX2DLCbits.DLC = len;
        C1TX2CONbits.TXREQ = 1;
    }
}

void CAN2_SendMessage(CAN_MESSAGE *message) {
    unsigned long id;
    unsigned char len;
    id = message->id;
    len = message->len;
    if (len > 8) len = 8;

    if (C2TX0CONbits.TXREQ == 0) {
        C2TX0CON = CAN_TX_STOP_REQ & CAN_TX_PRIORITY_HIGH;
        if (message->type == 1) { //标准帧
            C2TX0SID = (CAN_TX_SID(id)) & CAN_TX_EID_DIS & CAN_SUB_NOR_TX_REQ;
        } else if (message->type == 0) { //扩展帧
            C2TX0SID = (CAN_TX_SID(id >> 18)) & CAN_TX_EID_EN & CAN_SUB_NOR_TX_REQ;
            C2TX0EID = (((CAN_TX_EID(id)) & CAN_NOR_TX_REQ) >> 16);
            C2TX0DLC = (unsigned int) ((CAN_TX_EID(id)) & CAN_NOR_TX_REQ);
        }
        unsigned char i;
        for (i = 0; i < len; i++) {
            *((unsigned char *) &C2TX0B1 + i) = message->data[i];
        }
        C2TX0DLCbits.DLC = len;
        C2TX0CONbits.TXREQ = 1;
    } else if (C2TX1CONbits.TXREQ == 0) {
        C2TX1CON = CAN_TX_STOP_REQ & CAN_TX_PRIORITY_HIGH;
        if (message->type == 1) { //标准帧
            C2TX1SID = (CAN_TX_SID(id)) & CAN_TX_EID_DIS & CAN_SUB_NOR_TX_REQ;
        } else if (message->type == 0) { //扩展帧
            C2TX1SID = (CAN_TX_SID(id >> 18)) & CAN_TX_EID_EN & CAN_SUB_NOR_TX_REQ;
            C2TX1EID = (((CAN_TX_EID(id)) & CAN_NOR_TX_REQ) >> 16);
            C2TX1DLC = (unsigned int) ((CAN_TX_EID(id)) & CAN_NOR_TX_REQ);
        }
        unsigned char i;
        for (i = 0; i < len; i++) {
            *((unsigned char *) &C2TX1B1 + i) = message->data[i];
        }
        C2TX1DLCbits.DLC = len;
        C2TX1CONbits.TXREQ = 1;
    } else if (C2TX2CONbits.TXREQ == 0) {
        C2TX2CON = CAN_TX_STOP_REQ & CAN_TX_PRIORITY_HIGH;
        if (message->type == 1) { //标准帧
            C2TX2SID = (CAN_TX_SID(id)) & CAN_TX_EID_DIS & CAN_SUB_NOR_TX_REQ;
        } else if (message->type == 0) { //扩展帧
            C2TX2SID = (CAN_TX_SID(id >> 18)) & CAN_TX_EID_EN & CAN_SUB_NOR_TX_REQ;
            C2TX2EID = (((CAN_TX_EID(id)) & CAN_NOR_TX_REQ) >> 16);
            C2TX2DLC = (unsigned int) ((CAN_TX_EID(id)) & CAN_NOR_TX_REQ);
        }
        unsigned char i;
        for (i = 0; i < len; i++) {
            *((unsigned char *) &C2TX2B1 + i) = message->data[i];
        }
        C2TX2DLCbits.DLC = len;
        C2TX2CONbits.TXREQ = 1;
    }
}

void CAN1_ReceiveMessage(CAN_MESSAGE *message) {
    unsigned long id;
    unsigned char len;

    id = 0;
    if (C1RX0SIDbits.RXIDE) {
        id += C1RX0SIDbits.SID; //取EID 28--18
        id <<= 12;
        id += C1RX0EID; //取EID17--6
        id <<= 6;
        id += C1RX0DLCbits.EID5_0; //取EID5--0
        message->type = 0;
    } else { //接收的数据是标准帧
        id += C1RX0SIDbits.SID; //取SID 10--0
        message->type = 1;
    }

    message->id = id;

    len = C1RX0DLCbits.DLC;
    if (len > 8) len = 8;
    message->len = len;
    unsigned char i;
    for (i = 0; i < len; i++) {
        message->data[i] = *((unsigned char *) &C1RX0B1 + i);
    }
}

void CAN2_ReceiveMessage(CAN_MESSAGE *message) {
    unsigned long id;
    unsigned char len;

    id = 0;
    if (C2RX0SIDbits.RXIDE) {
        id += C2RX0SIDbits.SID; //取EID 28--18
        id <<= 12;
        id += C2RX0EID; //取EID17--6
        id <<= 6;
        id += C2RX0DLCbits.EID5_0; //取EID5--0
        message->type = 0;
    } else { //接收的数据是标准帧
        id += C2RX0SIDbits.SID; //取SID 10--0
        message->type = 1;
    }

    message->id = id;

    len = C2RX0DLCbits.DLC;
    if (len > 8) len = 8;
    message->len = len;
    unsigned char i;
    for (i = 0; i < len; i++) {
        message->data[i] = *((unsigned char *) &C2RX0B1 + i);
    }
}



