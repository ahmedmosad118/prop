/*
 * ADC_prog.c
 *
 *  Created on: Mar 16, 2018
 *      Author: Ahmed
 */

#include "Bit_modification.h"
#include "Datatype.h"
#include <avr/io.h>
#include <avr/delay.h>


void ADC_initioalized(void){
	// vcc
	Set_bits(ADMUX,REFS0);
	Clear_bits(ADMUX,REFS1);
		Set_bits(ADMUX,ADLAR);



		Set_bits(ADCSRA,ADEN); //enable

		// prescaller 128
		Set_bits(ADCSRA,2);
		Set_bits(ADCSRA,1);
		Set_bits(ADCSRA,0);

		Clear_bits(ADCSRA,ADATE);//disable auto
		Clear_bits(ADCSRA,ADIE);

}

u16 ADC_read(u8 channle){
	if(channle == 0){
		Clear_bits(ADMUX,0);
			Clear_bits(ADMUX,1);
			Clear_bits(ADMUX,2);
			Clear_bits(ADMUX,3);
			Clear_bits(ADMUX,4);
			_delay_ms(100);
			Set_bits(ADCSRA,ADSC);//start conversion
				while (Get_bit_number(ADCSRA,ADSC));
				u16 read1= (((u16)ADCH) <<2);
				read1= read1*4.88;
			    return read1 ;

	}

	else if(channle == 1){
		Set_bits(ADMUX,0);
			Clear_bits(ADMUX,1);
			Clear_bits(ADMUX,2);
			Clear_bits(ADMUX,3);
			Clear_bits(ADMUX,4);
			Set_bits(ADCSRA,ADSC);//start conversion
				while (Get_bit_number(ADCSRA,ADSC));
				u16 read= (((u16)ADCH) <<2);
				read= read*4.88;
			    return read ;

	}

}
