/*
 * DIO_Rgister.h
 *
 *  Created on: Mar 9, 2018
 *      Author: Ahmed
 */

#ifndef DIO_RGISTER_H_
#define DIO_RGISTER_H_

#define PORTA (*((u8 *)0x3B)) //  * int * ptr
#define DDRA (*((u8 *)0x3A))
#define PINA (*((u8 *)0x39))

#define PORTB (*((u8 *)0x38))
#define DDRB (*((u8 *)0x37))
#define PINB (*((u8 *)0x36))

#define PORTC (*((u8 *)0x35))
#define DDRC (*((u8 *)0x34))
#define PINC (*((u8 *)0x33))

#define PORTD (*((u8 *)0x32))
#define DDRD (*((u8 *)0x31))
#define PIND (*((u8 *)0x30))

#define MCUCR (*((u8 *)0x55))






#endif /* DIO_RGISTER_H_ */
