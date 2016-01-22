/************************************************
 * uart_serial.c
 * Yu Yoshida
 * =============================================
 * uart通信(シリアル)定義ソースファイル
 * =============================================
 * ・ver1.00 初版 2015/01/15 Yu Yoshida
 * uartでPCとシリアル通信をする
 * =============================================
 * PIC16F88
 * XC8 (v1.35/Win)
 * =============================================
 * Created by fabsat Project (Tokai University)
 ************************************************/

#include <xc.h>
#include "uart_serial.h"
#include "pic_clock.h"


/*=====================================================
 * @breif
 *     uart通信初期設定関数
 * @param
 *     なし
 * @return
 *     なし
 * @note
 *     型番によってRXピンを確認する必要がある
 *===================================================*/
void uart_init()
{
    SPBRG = SPBRG_DATA;
    TXSTA = (TX9_RX9_DATA | BRGH_DATA | 0x20);
    RCSTA = (TX9_RX9_DATA | 0x90);
}

void putch(unsigned char byte)
{
    while(!TXIF){
    }
    TXREG = byte;
}
 
unsigned char getch()
{
    while(!RCIF){
    }
 
    return RCREG;
}
 
unsigned char getche()
{
    unsigned char c;
 
    c = getch();
    putch(c);
 
    return c;
}