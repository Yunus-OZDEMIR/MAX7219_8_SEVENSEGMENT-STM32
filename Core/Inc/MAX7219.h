/*
 * MAX7219.h
 *
 *  Created on: Jan 12, 2023
 *      Author: yunus
 */

#ifndef INC_MAX7219_H_
#define INC_MAX7219_H_

// REGISTER ADDRESS MAP //
#define NO_OP			0x00
#define Digit_0			0x01
#define Digit_1			0x02
#define Digit_2			0x03
#define Digit_3			0x04
#define Digit_4			0x05
#define Digit_5			0x06
#define Digit_6			0x07
#define Digit_7			0x08
#define DecodeMode		0x09
#define Intensity		0x0A
#define ScanLimit		0x0B
#define ShutDown		0x0C
#define NormOp			0x01
#define DisplayTest		0x0F

//DECODE MODE//
#define NoDecode		0x00
#define Decode_1		0x01
#define Decode_4		0x0F
#define Decode_7		0xFF

//CODE B FONT//
#define D_0				0x00
#define D_1				0x01
#define D_2				0x02
#define D_3				0x03
#define D_4				0x04
#define D_5				0x05
#define D_6				0x06
#define D_7				0x07
#define D_8				0x08
#define D_9				0x09
#define dash			0x0A
#define E_letter		0x0B
#define H_letter		0x0C
#define L_letter		0x0D
#define P_letter		0x0E
#define blank			0x0F

//INTENSITY (BRIGHTNESS) OF REGISTER CONFIG
#define Intensity_0			0x00 // MIN
#define Intensity_1			0x01
#define Intensity_2			0x02
#define Intensity_3			0x03
#define Intensity_4			0x04
#define Intensity_5			0x05
#define Intensity_6			0x06
#define Intensity_7			0x07
#define Intensity_8			0x08
#define Intensity_9			0x09
#define Intensity_10		0x0A
#define Intensity_11		0x0B
#define Intensity_12		0x0C
#define Intensity_13		0x0D
#define Intensity_14		0x0E
#define Intensity_15		0x0F // MAX

// SCAN LIMIT FORMAT

#define ScanOne			0x00
#define ScanTwo			0x01
#define ScanThree		0x02
#define ScanFour		0x03
#define ScanFive		0x04
#define ScanSix			0x05
#define ScanSeven		0x06
#define ScanEight		0x07

#define DotEn			0x01
#define DotDis		    0x00

void Max7219_Send_Data(uint8_t Address, uint8_t Data);
void CleanDigits(uint8_t DigitDecode);
void Max7219_Init(uint8_t Decode_Num,uint8_t Scan_Limit,uint8_t Intens);
void PrintDigit(uint8_t Digit, uint8_t Print, uint8_t Dot);
void PrintNumber(int Number);



#endif /* INC_MAX7219_H_ */
