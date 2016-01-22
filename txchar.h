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

#ifndef __TXCHAR_H__
#define	__TXCHAR_H__

#include <xc.h>
#include <stdio.h>
#include <pic16f88.h>

//プロトタイプ宣言
void txchar(char *moji);

#endif	//__TXCHAR_H__