/*
 * LCD_Config.h
 *
 *  Created on: Mar 16, 2018
 *      Author: Ahmed
 */
#include "DIO_int.h"
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


//DATA PORT
#define LCD_DATA_PORT DIO_PORTC
//CONTROL POR
#define LCD_CONTROL_PORT DIO_PORTB

//CONTROL pins position
#define LCD_RS         DIO_PIN3
#define LCD_RW         DIO_PIN4
#define LCD_ENABLE     DIO_PIN5

//DATA pins position
#define LCD_D0 DIO_PIN0
#define LCD_D1 DIO_PIN1
#define LCD_D2 DIO_PIN2
#define LCD_D3 DIO_PIN3
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7

#endif /* LCD_CONFIG_H_ */
