/************************************************
 * uart_serial.h
 * Yu Yoshida
 * =============================================
 * uart通信(シリアル)定義ヘッダファイル
 * =============================================
 * ・ver1.00 初版 2015/01/15 Yu Yoshida
 * uartでPCとシリアル通信をする
 * =============================================
 * PIC16F88
 * XC8 (v1.33/Win)
 * =============================================
 * Created by fabsat Project (Tokai University)
************************************************/

#ifndef __UART_SERIAL_H__
#define __UART_SERIAL_H__

#include "pic_clock.h"

#define BAUDRATE 9600       // 9.6kbps
#define TX9_RX9_BIT 0       // 0: 8bit, 1: 9bit
#define BRGH_BIT 1          // 0: 低速サンプル指定, 1: 高速サンプル指定
 
#if TX9_RX9_BIT == 1
#define TX9_RX9_DATA 0x40
#else
#define TX9_RX9_DATA 0x00
#endif
 
#if BRGH_BIT == 1
#define BRGH_DATA 0x04
#define SPBRG_DATA ((unsigned char)(((_XTAL_FREQ / 16) / BAUDRATE) - 1))
#else
#define BRGH_DATA 0x00
#define SPBRG_DATA ((unsigned char)(((_XTAL_FREQ / 64) / BAUDRATE) - 1))
#endif
 
// プロトタイプ宣言
void uart_init();
void putch(unsigned char byte);
unsigned char getch();
unsigned char getche();
 
#endif  // __UART_SERIAL_H__