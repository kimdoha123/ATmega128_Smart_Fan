
#ifndef BUZZER_H_
#define BUZZER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../periph/GPIO/Gpio.h"

#define BUZZER2_ICR			ICR1
#define BUZZER2_OCR			OCR1A
#define BUZZER2_TCCRA		TCCR1A
#define BUZZER2_TCCRB		TCCR1B
#define BUZZER2_COM0		COM1A0
#define BUZZER2_COM1		COM1A1
#define BUZZER2_DDR			DDRB
#define BUZZER2_WGM0		WGM10
#define BUZZER2_WGM1		WGM11
#define BUZZER2_WGM2		WGM12
#define BUZZER2_WGM3		WGM13
#define BUZZER2_CS0			CS10
#define BUZZER2_CS1			CS11
#define BUZZER2_CS2			CS12
#define BUZZER2_PIN			PINB

void Buzzer2_makeHerz(uint16_t herz);
void Buzzer2_soundOn();
void Buzzer2_soundOff();
void Buzzer2_init();
void Buzzer2_powerOnSound();
void Buzzer2_powerOffSound();
void Buzzer2_speedButtonSound();
void Buzzer2_timerButtonSound();
void Buzzer2_TimerSound();
void Buzzer2_powerOffSound();
void Buzzer2_timerButtonSound();
void Buzzer2_TimerDownSound();
void Buzzer2_TimerSound();


#endif /* BUZZER_H_ */