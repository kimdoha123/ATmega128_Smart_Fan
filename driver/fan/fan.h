
#ifndef FAN_H_
#define FAN_H_

#define	F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BUZZER_ICR ICR3
#define BUZZER_OCR OCR3A

//void fan_init();
void fan_On();
void fan_Off();
void fan_makeHertz(uint16_t hertz);

#endif /* FAN_H_ */