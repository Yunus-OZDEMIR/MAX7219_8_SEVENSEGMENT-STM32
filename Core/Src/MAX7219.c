/*
 * MAX7219.c
 *
 *  Created on: 13 Oca 2023
 *      Author: YUNUS ÖZDEMİR
 */

#include "stm32f4xx_hal.h"
#include "MAX7219.h"
#include "main.h"
#define CS_SET		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET)
#define CS_RESET	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, SET)

extern SPI_HandleTypeDef hspi2;

void Max7219_Send_Data(uint8_t Address, uint8_t Data){
	CS_SET;
	HAL_SPI_Transmit(&hspi2, &Address, 1, HAL_MAX_DELAY);
	HAL_SPI_Transmit(&hspi2, &Data, 1, HAL_MAX_DELAY);
	CS_RESET;
}

void CleanDigits(uint8_t DigitDecode){
	if (DigitDecode == Decode_7){
		for (int i=1 ;i<=8; i++){
			Max7219_Send_Data(i, 0);
		}
	}
	else if (DigitDecode == Decode_4){
		for (int i=1 ;i<=4; i++){
			Max7219_Send_Data(i, 0);
		}
	}
	else if (DigitDecode == Decode_1){
		for (int i=1 ;i<=1; i++){
			Max7219_Send_Data(i, 0);
		}
	}
}

void Max7219_Init(uint8_t Decode_Num,uint8_t Scan_Limit,uint8_t Intens){

	CS_SET; //INITIAL CHIP SELECT
	CleanDigits(Decode_Num);
	Max7219_Send_Data(ShutDown, NormOp);
	Max7219_Send_Data(ScanLimit, Scan_Limit);
	Max7219_Send_Data(Intensity, Intens);
	Max7219_Send_Data(DecodeMode, Decode_Num);
}



void PrintDigit(uint8_t Digit, uint8_t Print, uint8_t Dot){

	if (Dot == DotEn){
	Print |= 0x80;
	Max7219_Send_Data(Digit, Print);
	}
	else if (Dot == DotDis){
	Max7219_Send_Data(Digit, Print);
	}

}

void PrintNumber(int Number, uint8_t Dot){
	int temp1;
	int temp2 = 1;
	int i = 10;
	int j = 2;


	temp1 = Number % 10;
	PrintDigit(Digit_0,temp1,Dot);

	while (temp2 >0){
		temp2 = Number / (1*i);
		temp2 = temp2 % 10;
		if (temp2 >0){
		PrintDigit(j,temp2,Dot);
		}
		j++;
		i = i*10;
	}

}





