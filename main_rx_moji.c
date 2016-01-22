/********************************************************
* main_rx_moji.c
* Yu Yoshida
* =======================================================
* 1文字をビットシフトで受信するメインファイル
* =======================================================
* ・ver1.00 初版 2016/01/16 Yu Yoshida
* pc-pic-変調IC-復調IC-pic-pc pc-pic間はuart通信
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

    while(1){

    	/*RBportの状態変化するまで無限ループ*/

    }
}