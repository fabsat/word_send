/************************************************
 * interrupt.h
 * Yu Yoshida
 * ==============================================
 * データ受信時の割り込み定義ヘッダファイル
 * ==============================================
 * ・ver1.00 初版 2015/01/15 Yu Yoshida
 * ==============================================
 * PIC16F88
 * XC8 (v1.33/Win)
 * ==============================================
 * Created by fabsat Project (Tokai University)
 ************************************************/

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__
 
/* INTCON_Registers */
#define GIE_BIT  1					//Global Interrupt Enable			//全体割り込み許可
#define PEIE_BIT 1					//Peripheral Interrupt Enable		//周辺割り込み許可
#define RBIE_BIT 1					//RB Port Change Interrupt Enable	//RBポート状態変化割り込み許可

/* Register_setting */
#define ANSEL_DATA       0x00		//デジタルI/Oに設定(16f88only?) 
#define INTCON_DATA 	 0xc8
#define OPTION_REG_DATA	 0x00
 
/* プロトタイプ宣言 */
void inti_pin_register(void);
void interrupt rx_isr(void);

#endif  // __INTERRUPT_H__