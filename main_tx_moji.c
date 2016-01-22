/********************************************************
* main_tx_moji.c
* Yu Yoshida
* =======================================================
* 1文字をビットシフトで送信するメインファイル
* =======================================================
* ・ver1.00 初版 2016/01/16 Yu Yoshida
* pc-pic-変調IC-復調IC-pic-pc pc-pic間はuart通信
* 受信して読み込むにはinterrupt.cを受信側に書き込む
* =======================================================
* pic16f88
* AD5700(変調, 復調)
* xc8 (v1.33 / win)
* =======================================================
* Created by fabsat Project (Tokai University)
*********************************************************/

#include <xc.h>
#include <stdio.h>
#include <pic16f88.h>
#include "pic_clock.h"
#include "uart_serial.h"
#include "interrupt.h"
#include "txchar.h"

#pragma config FOSC = HS, WDTE = OFF, PWRTE = ON,  MCLRE = ON, BOREN = ON,  LVP = OFF
#pragma config CPD = OFF, WRT = OFF,  CCPMX = RB3, CP = OFF, IESO = OFF, FCMEN = OFF

/*=====================================================
 * main fanction
 *===================================================*/

void main(void)
{
    /*PIC初期化関数*/
    uart_init();
    inti_pin_register();

    char moji_tx;                      //1文字を格納するchar型変数「moji」を作る
    char buf[9];                       //文字データ(ASCII, ２進数)を格納する配列
    printf("Press a key:\r\n");

    while(1)
    {
        moji_tx = getch();					//ターミナルに文字が入力されるまでこの行で停止
        printf("Echo: %c\r\n", moji_tx);	//mojiに入った文字をターミナルに表示する。%cはchar型の「フォーマット指定子」

        buf[0] = 1;                         //割り込み検知用(立ち上がり)

        /*文字データを配列にビットシフトで格納*/
        for (int i = 1; i < 9; i++){
            buf[i] = ((moji_tx >> (i-1) & 0b00000001));
        }

        /*文字データ送信関数*/
        txchar(buf);
        RA2 = 0;           
    }
}

