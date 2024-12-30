#include "Button.h"

void Button_init(button_t *btn, volatile uint8_t* ddr, volatile uint8_t* pin, uint8_t pinNum)
{
	//초기화 함수
	btn->DDR = ddr;
	btn->PIN = pin;
	btn->pinNum = pinNum;
	btn->prevState = 1;
	Gpio_initPin(btn->DDR, INPUT, btn->pinNum);	// 사용하고자 하는 버튼을 입력으로 변경
}

uint8_t ButtonGetState(button_t *btn)	//버튼에 대한 정보를 전달해야 함. 주소값으로 전달 필요
{
	uint8_t curState = Gpio_readPin(btn->PIN, btn->pinNum);
	
	if((curState == 0) && (btn->prevState == 1))
	{
		_delay_ms(10);
		btn->prevState = PUSHED;
		return ACT_PUSHED;
	}
	
	else if((curState != 0) && (btn->prevState == 0))
	{
		_delay_ms(10);
		btn->prevState = RELEASED;
		return ACT_RELEASED;
	}
	return ACT_NONE;
}