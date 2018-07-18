#include "BSP.h"

const unsigned char Title[] = "DBCM";
const unsigned char Company[] = "HFMZKJ";
const unsigned char CreateDate[] = __DATE__;
const unsigned char CreateTime[] = __TIME__;
const unsigned char Author_name[] = "Pingsheng Mao";
const unsigned char software_version[] = "V1.0.0";
const unsigned char author_email_msg[] = "mpszm@126.com";

extern unsigned int ReadEEROM(unsigned long address);
extern void EraseEEROM(unsigned long address);
extern void WriteEEROM(unsigned long address, unsigned int dat);

unsigned int EEROM_ReadLowMiles(unsigned long address) {
    unsigned int dump = 0;
    unsigned char i;

    for (i = 0; i < 16; i++) {
        dump += ReadEEROM(address + 2 * i);
    }

    return dump;
}

void EEROM_WriteLowMiles(unsigned long address, unsigned int value) {
    unsigned int mod = 0;
    unsigned int div = 0;
    unsigned int dump = 0;

    unsigned char i = 0;

    div = value / 16;
    mod = value % 16;

    for (i = 0; i < 16; i++) {
        dump = ReadEEROM(address + 2 * i);
        if (i < mod) {
            if (dump != div + 1) {
                EraseEEROM(address + i * 2);
                WriteEEROM(address + i * 2, (div + 1));
            }
        } else {
            if (dump != div) {
                EraseEEROM(address + i * 2);
                WriteEEROM(address + i * 2, div);
            }
        }
    }
}

unsigned int EEROM_ReadWord(unsigned long dst) {
    return (ReadEEROM(dst));
}

void EEROM_WriteWord(unsigned long dst, unsigned int val) {
    unsigned int dump;

    dump = ReadEEROM(dst);

    if (dump != val) {
        EraseEEROM(dst);
        WriteEEROM(dst, val);
    }
}



