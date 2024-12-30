#include "timer.h"

void Timer0_init()	//1ms overflow interrupt, FND display
{
	// 128 1ms interrupt occured
	TCCR0 |= ((1<<CS02) | (0<<CS01) | (1<<CS00));	//128 preScaler
	TIMSK |= (1<<TOIE0);							//TIMSK Timer/Counter0 overflow interrupt enable
	TCNT0 = 130;									//
}

void Timer2_init()
{
	//Timer/Counter 2 사용, 64분주 활용, 1ms period interrupt, CTC mode
	// 1/64 prescaler
	TCCR2 |= ((0<<CS22) | (1<<CS21) | (1<<CS20));
	TIMSK |= (1<<OCIE2);
	//CTC mode
	TCCR2 |= ((1<<WGM21) | (0<<WGM20));
	OCR2 = 250-1;
}

void Timer3_init()
{
	//timer3, Fast PWM MODE, Top ICR3, DUTY CYCLE OCR3A, PresScaler 1/64, non-inverting Mode
	//Frequency : 1kHz, Duty Cycle 50%
	
	TCCR3B |= ((0<<CS32) | (1<<CS31) | (1<<CS30));	//PreScaler 1/64
	TCCR3B |= ((1<<WGM33) | (1<<WGM32));	//Fast PWM 14
	TCCR3A |= ((1<<WGM31) | (0<<WGM30));	//Fast PWM 14
}