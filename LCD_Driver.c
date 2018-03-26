/*

 * LCD_Driver.c
 *
 *  Created on: Mar 2, 2018
 *      Author: Ahmed
 */
#include "LCD_Config.h"
#include "Datatype.h"
#include "LCD_int.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "DIO_int.h"
#include "Bit_modification.h"

void LCD_vDataPort(void)
{

	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D0,DIO_OUTPUT);
	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D1,DIO_OUTPUT);
	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D2,DIO_OUTPUT);
	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D3,DIO_OUTPUT);
	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D4,DIO_OUTPUT);
	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D5,DIO_OUTPUT);
	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D6,DIO_OUTPUT);
	DIO_vSerPinDirection(LCD_DATA_PORT,LCD_D7,DIO_OUTPUT);


}
void LCD_vControlPort(void)
{

	DIO_vSerPinDirection(LCD_CONTROL_PORT,LCD_RS, DIO_HIGH);
	DIO_vSerPinDirection(LCD_CONTROL_PORT,LCD_RW, DIO_HIGH);
	DIO_vSerPinDirection(LCD_CONTROL_PORT,LCD_ENABLE, DIO_HIGH);

}


void LCD_vPosition(u8 position)
{
	if (position > 16)
		LCD_vWriteCommand((175 +position));
	else
		LCD_vWriteCommand((127+position));
	_delay_ms(10);
}



void LCD_vWriteData(u8 Data){

	// RS -> 1
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS , DIO_HIGH);
    //RW -> 0
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW , DIO_LOW);
    // Write  data
    PORTC = Data;
    //E -> 1
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_ENABLE , DIO_HIGH);

    // Delay 3 ms to understand data

    _delay_ms(10);

    //E -> 0

    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_ENABLE , DIO_LOW);


}

void LCD_vWriteCommand(u8 Command){

	// RS -> 0
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS , DIO_LOW);
    //RW -> 0
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW , DIO_LOW);
    // Write  data

    PORTC = Command;

    //E -> 1
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_ENABLE , DIO_HIGH);

    // Delay 3 ms to understand data

    _delay_ms(10);

    //E -> 0

    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_ENABLE , DIO_LOW);


}
void Lcd_vInitialization(void){
	//delay for initialized
	 LCD_vDataPort();
	 LCD_vControlPort();
	_delay_ms(100);
	// RS -> 0
	    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS , DIO_LOW);
	    //RW -> 0
	    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW , DIO_LOW);

	 LCD_vWriteCommand(0b00111100);
	 _delay_ms(2);
	 LCD_vWriteCommand(0b00001111);
	 _delay_ms(2);
	 LCD_vWriteCommand(0b00000001);
	 _delay_ms(2);



}
void LCD_vWriteDataSting(u8 Data,u8 * ptr){
	u8 counter;

	// RS -> 1
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RS , DIO_HIGH);
    //RW -> 0
    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_RW , DIO_LOW);
    // Write  data
	for(counter = 0 ; counter < Data ; counter ++){
		if(ptr[counter] == '\0'){break;}
		PORTC = ptr[counter];
	    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_ENABLE , DIO_HIGH);

	    // Delay 3 ms to understand data

	    _delay_ms(10);

	    //E -> 1

	    DIO_vSetPinValue(LCD_CONTROL_PORT , LCD_ENABLE , DIO_LOW);


	}


}
