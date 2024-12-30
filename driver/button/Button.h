#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../Periph/GPIO/GPIO.h"

enum {PUSHED, RELEASED};
enum {ACT_PUSHED, ACT_RELEASED, ACT_NONE};

typedef struct _button
{
	volatile uint8_t* DDR;
	volatile uint8_t* PIN;
	uint8_t pinNum;
	uint8_t prevState;
	//port
	//pin number
	//static prevState
}button_t;

void Button_init(button_t *btn, volatile uint8_t* ddr, volatile uint8_t* pin, uint8_t pinNum);
uint8_t ButtonGetState(button_t *btn);	//버튼에 대한 정보를 전달해야 함. 주소값으로 전달 필요

#endif /* BUTTON_H_ */