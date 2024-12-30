#include "fan.h"

/*
void fan_init()
{
	//timer3, Fast PWM MODE, Top ICR3, DUTY CYCLE OCR3A, PresScaler 1/64, non-inverting Mode
	//Frequency : 1kHz, Duty Cycle 50%
	
	TCCR3B |= ((0<<CS32) | (1<<CS31) | (1<<CS30));	//PreScaler 1/64
	TCCR3B |= ((1<<WGM33) | (1<<WGM32));	//Fast PWM 14
	TCCR3A |= ((1<<WGM31) | (0<<WGM30));	//Fast PWM 14
}
*/

void fan_makeHertz(uint16_t hertz)
{
	if(hertz < 100) hertz = 100;
	else if(hertz > 5000) hertz = 5000;
	BUZZER_ICR = (250000 / hertz) - 1;
	BUZZER_OCR = BUZZER_ICR / 2;
}
/*
void fan_Button_On()
{
	Buzzer_SoundOn();
	
	Buzzer_makeHertz(1046);
	_delay_ms(1000);
	TCNT3 = 0;
	Buzzer_makeHertz(1318);
	_delay_ms(1000);
	TCNT3 = 0;
	Buzzer_makeHertz(1568);
	_delay_ms(1000);
	TCNT3 = 0;
	Buzzer_makeHertz(2093);
	_delay_ms(1000);
	TCNT3 = 0;
	
	//Buzzer_SoundOff();
}
*/

void fan_On()
{
	TCCR3A |= ((1<<COM3A1) | (0<<COM3A0));	//non-inverting Mode
}

void fan_Off()
{
	TCCR3A &= ~((1<<COM3A1) | (1<<COM3A0));	//non-inverting Mode
}