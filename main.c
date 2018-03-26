/*

 * main.c
 *
 *  Created on: Mar 16, 2018
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <avr/delay.h>
#include "Datatype.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "ADC_init.h"
#include <avr/interrupt.h>

#include "string.h"
#include "Bit_modification.h"
u8 A[11]="Temp: \0";
u8 B[11]="Light: \0";
u8 C[11]="3-Back \0";

 int main(){
	    ADC_initioalized();
		Lcd_vInitialization();

		Set_bits(SREG,SREG_I); // enable global interrupt
		Set_bits(GICR,INT0); // enable int0 interrupt
		Set_bits(GICR,INT1); // enable int1 interrupt
		Set_bits(GICR,INT2); // enable int2 interrupt

		Set_bits(MCUCR,ISC00); // select rising edge mode of int0
		Set_bits(MCUCR,ISC01); // select rising edge mode of int0
		Set_bits(MCUCR,ISC10); // select rising edge mode of int1
		Set_bits(MCUCR,ISC11); // select rising edge mode of int1
		Set_bits(MCUCSR,ISC2); // select rising edge mode of int2
	 // pull up resistor and costomize the work !
	    Set_bits(SREG,7);// global enable
	 	DDRD=0x00;      //ddrd intrupt input

	 	 Set_bits(PORTB,2);
	 	 Set_bits(PORTD,2);
	 	 Set_bits(PORTD,3);
	 	DIO_vSerPinDirection(DIO_PORTB , DIO_PIN7 , DIO_OUTPUT);

	 	LCD_vWriteDataSting(6,A);
		 LCD_vPosition(17); // First digit in Second Line
		 LCD_vWriteDataSting(6,B);
		 _delay_ms(10000);
		 while(1){
		 if(ADC_read(1) > 1500){
			  DIO_vSetPinValue(DIO_PORTB , DIO_PIN7 , DIO_HIGH);
		 }
		 else{
			 DIO_vSetPinValue(DIO_PORTB , DIO_PIN7 , DIO_LOW);
		 }

	 }

 }
 ISR(INT0_vect)
 {
	 LCD_vWriteCommand(0b00000001);
	 LCD_vWriteDataSting(6,B);
	 _delay_ms(100);

	 u16 read2;
	 read2=5000/ADC_read(1);
	 u16 result2[16];
	 itoa(read2,result2, 10);
	 LCD_vWriteDataSting(5,result2);
	 LCD_vPosition(17);

		 LCD_vWriteDataSting(6,C);
	 Clear_bits(GICR,INT0);
	    Clear_bits(GICR,INT1);

 }
 ISR(INT1_vect)
 {
	 LCD_vWriteCommand(0b00000001);
	 LCD_vWriteDataSting(6,A);
 	 u16 read= 19;
 	 u16 result[16];
 	 itoa(read,result, 10);
 	 LCD_vWriteDataSting(2,result);
	 LCD_vPosition(17);
		 LCD_vWriteDataSting(6,C);
	 Clear_bits(GICR,INT0);
	    Clear_bits(GICR,INT1);

 }
 ISR(INT2_vect)
 {
	 LCD_vWriteCommand(0b00000001);

	 LCD_vWriteDataSting(6,A);
		 LCD_vPosition(17);
	 LCD_vWriteDataSting(6,B);
	    Set_bits(GICR,INT0);//enable dio
	    Set_bits(GICR,INT1);//enable dio

 }


