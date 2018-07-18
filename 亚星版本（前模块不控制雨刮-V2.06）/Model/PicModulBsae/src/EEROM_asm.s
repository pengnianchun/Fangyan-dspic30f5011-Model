.include "xc.inc"

.equ    _EE_ERASE_WORD_CODE,0x4044    ; valid for all devices
.equ    _EE_ERASE_ROW_CODE,0x4045     ; with EEDATA
.equ    _EE_ERASE_ALL_CODE,0x4046

.equ    _EE_WRITE_WORD_CODE,0x4004
.equ    _EE_WRITE_ROW_CODE,0x4005

.equ    _EE_WORD,2
.equ    _EE_ROW,32

.global _ReadEEROM
.global _EraseEEROM
.global _WriteEEROM

.section .text
/* DATA EEPROM Read Routines */

_ReadEEROM:
        push     _TBLPAG
        mov      w1,_TBLPAG     ; TBLPAG = tblpage(src)
        tblrdl   [w0],w0        ;
        pop      _TBLPAG
        return


_EraseEEROM:
        push    TBLPAG
        mov     w1,_TBLPAG      ; TBLPAG = tblpage(dest)
        tblwtl  w0,[w0]         ; set base address of erase block
        mov     #_EE_ERASE_WORD_CODE,w1
        mov     w1,NVMCON       ; set erase code

finish: disi    #5              ; block level 0-6 interrupts
        mov     #0x55, w1       ;
        mov     w1, NVMKEY      ;
        mov     #0xAA, w1       ;
        mov     w1, NVMKEY      ; unlock sequence
        bset    NVMCON, #15     ; begin erase/write
        nop
        nop
        pop     TBLPAG
L1:     btsc    NVMCON, #15
        bra     L1
        return

/* DATA EEPROM Write Routines */
_WriteEEROM:
        push    TBLPAG
        mov     w1,_TBLPAG      ; TBLPAG = tblpage(dest)
        tblwtl  w2,[w0]         ; write data
        mov     #_EE_WRITE_WORD_CODE,w1
        mov     w1,NVMCON       ; set word write mode
        bra     finish


.end
