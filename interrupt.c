/************************************************
 * interrupt.c
 * Yu Yoshida
 * =============================================
 * データ受信時割り込みソースファイル
 * =============================================
 * ・ver1.00 初版 2015/01/15 Yu Yoshida
 * 割り込み用1bit + 復調した文字データ8bitをPICに読み込む
 * =============================================
 * PIC16F88
 * XC8 (v1.35/Win)
************************************************/

#include <xc.h>
#include <stdio.h>
#include <pic16f88.h>
#include "uart_serial.h"
#include "pic_clock.h"
#include "interrupt.h"

/*=====================================================
 * @breif
 *     割り込み設定関数
 * @param
 *     なし
 * @return
 *     なし
 * @note
 *     型番によってレジスタの有無がある。
 *     RA2:文字データを出力ピン
 *     RB1:復調されたデータ入力ピン
 *     RB2:シリアル通信受信ピン
 *     RB7:状態変化割り込み入力ピン
 *===================================================*/

void inti_pin_register(void)
{
    TRISA = 0b00000010;             // PORTAの入出力設定、RA1入力、RA2出力
    TRISB = 0b10000110;             // PORTBの入出力設定、RB1は復調ICからのデータ入力RB2はシアリルの受信なので入力,RB7は状態変化割り込み入力
    PORTA = 0x00;                   // PORTAを初期化
    PORTB = 0x00;                   // PORTBを初期化

    ANSEL      = ANSEL_DATA;        //デジタルI/Oとして設定
    INTCON     = INTCON_DATA;       //割り込み許可設定、PORTBの変化での割り込みレジスタ設定
    OPTION_REG = OPTION_REG_DATA;

}

/*=====================================================
 * @breif
 *     受信時の割り込み関数
 * @param
 *     なし
 * @return
 *     なし
 * @note
 *     picの立ち上がりをトリガーにしている関数。データシート参照。
 *===================================================*/

void interrupt rx_isr(void)
{
    char moji_rx_bit[9] = {};               //受信データを格納するための配列
    char moji_rx;                           //配列で得られたデータを合成するための変数

    /*状態変化(立ち上がり)フラグの状態を判断*/
    if (INTCONbits.RBIF == 1){
        for (int i = 0; i < 9; i++){
            moji_rx_bit[i] = PORTBbits.RB1; //今回はRB1の状態を配列に格納
            __delay_ms(100);
        }

        /*得られたデータを合成する*/
        for (int i = 0; i < 8; i++){
            moji_rx |= moji_rx_bit[8 - i];
            moji_rx = moji_rx << 1; 
        }
        moji_rx = moji_rx >> 1;             //ビットシフトが１回分for文で多く回しているので戻す
        putch(moji_rx);                     //PCに送信

        /*-----内田さんアドバイス--------------------
        for (int i = 0; i<8; i++){
            bit_rx = PORTBbits.RB1;
            __delay_ms(100);
            moji1 = moji1 + bit_rx;
            moji1 = moji1 << 1;
        }
        //moji1 = moji1 >> 1;
        putch(moji1);
        -----ビットスワップが必要だが、値はずれていなかった*/

        INTCONbits.RBIF = 0;                //flag reset            
    }
}