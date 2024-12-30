

#include "Buzzer.h"

void Buzzer2_makeHerz(uint16_t herz)
{      
	if (herz<100) herz=100;
	else if (herz>4000) herz=4000;

	BUZZER2_ICR = (250000/herz) -1; 
	        
	BUZZER2_OCR = BUZZER2_ICR / 2;                     
}

void Buzzer2_soundOn()
{
	BUZZER2_TCCRA |= (1<<BUZZER2_COM1) | (0<<BUZZER2_COM0); 
}

void Buzzer2_soundOff()
{
	BUZZER2_TCCRA &= ~((1<<BUZZER2_COM1) | (1<<BUZZER2_COM0));      
}

void Buzzer2_init()
{
	Gpio_initPin(&BUZZER2_DDR, 3, OUTPUT);
	
	BUZZER2_TCCRB |= (1<<BUZZER2_WGM3) | (1<<BUZZER2_WGM2);   
	BUZZER2_TCCRA |= (1<<BUZZER2_WGM1) | (0<<BUZZER2_WGM0);  
	BUZZER2_TCCRB |= (0<<BUZZER2_CS2) | (1<<BUZZER2_CS1) | (1<<BUZZER2_CS0);         
	
}

void Buzzer2_powerOnSound()
{
	Buzzer2_soundOn();
	TCNT1 =0;              
	Buzzer2_makeHerz(1319);
	_delay_ms(150);
	TCNT1 =0;
	Buzzer2_makeHerz(659);
	_delay_ms(100);
	TCNT1 =0;
	Buzzer2_makeHerz(988);
	_delay_ms(90);
	TCNT1 =0;
	Buzzer2_makeHerz(440);
	_delay_ms(200);
	TCNT1 =0;
	Buzzer2_makeHerz(1319);
	_delay_ms(100);
	TCNT1 =0;
	Buzzer2_makeHerz(988);
	_delay_ms(200);
	Buzzer2_soundOff();
}

void Buzzer2_powerOffSound()
{
	Buzzer2_soundOn();
	TCNT1 = 0;
	Buzzer2_makeHerz(880);
	_delay_ms(110);
	TCNT1 = 0;
	Buzzer2_makeHerz(659);
	_delay_ms(110);
	TCNT1 = 0;
	Buzzer2_makeHerz(440);
	_delay_ms(110);
	TCNT1 = 0;
	Buzzer2_makeHerz(494);
	_delay_ms(110);
	Buzzer2_soundOff();
}

void Buzzer2_speedButtonSound()
{
	Buzzer2_soundOn();
	TCNT1 =0;               
	Buzzer2_makeHerz(523);
	_delay_ms(20);
	TCNT1 =0;
	Buzzer2_makeHerz(1046);
	_delay_ms(50);
	Buzzer2_soundOff();
}

void Buzzer2_timerButtonSound()
{
	Buzzer2_soundOn();
	TCNT1 =0;
	Buzzer2_makeHerz(1046);
	_delay_ms(50);
	TCNT1 =0;               
	Buzzer2_makeHerz(1318);
	_delay_ms(50);
	TCNT1 =0;
	Buzzer2_makeHerz(1567);
	_delay_ms(50);
	Buzzer2_soundOff();
}

void Buzzer2_TimerSound()
{
	for(int i=0; i<2; i++)
	{
		Buzzer2_soundOn();
		TCNT1 =0;               
		Buzzer2_makeHerz(523);
		_delay_ms(20);
		TCNT1 =0;
		Buzzer2_makeHerz(784);
		_delay_ms(20);
		TCNT1 =0;               
		Buzzer2_makeHerz(1046);
		_delay_ms(50);
		Buzzer2_soundOff();
	}
}

void Buzzer2_TimerDownSound()
{
	Buzzer2_soundOn();
	TCNT1 =0;
	Buzzer2_makeHerz(1567);
	_delay_ms(50);
	TCNT1 =0;
	Buzzer2_makeHerz(1318);
	_delay_ms(50);
	TCNT1 =0;
	Buzzer2_makeHerz(1046);
	_delay_ms(50);
	Buzzer2_soundOff();
}