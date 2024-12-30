#include "GPIO.h"


void Gpio_initPort(volatile uint8_t* DDR, uint8_t dir)
{
	//DDR
	//하드 코딩을 불가. 유저가 어떤 포트를 사용할 것인지, input/output 사용을 결정하여 알려줘야 한다.
	if(dir == OUTPUT)
	{
		*DDR = 0xff;
	}
	else
	{
		*DDR = 0x00;
	}
}

void Gpio_initPin(volatile uint8_t* DDR, uint8_t dir, uint8_t pinNum)
{
	//DDR
	//DDRA &= ~(1<<0);  INPUT
	//DDRA |= ~(1<<0);  OUTPUT
	if (dir == OUTPUT)
	{
		*DDR |= (1<<pinNum);
	} 
	else
	{
		*DDR &= ~(1<<pinNum);
	}
}

void Gpio_writePort(volatile uint8_t* PORT, uint8_t data)
{
	//PORT
	//PORTD 0xff;
	//PORTD = data;
	*PORT = data;
}

void Gpio_writePin(volatile uint8_t* PORT, uint8_t pinNum, uint8_t state)
{
	//PORT
	//PORTD |= (1<<0)
	if (state == GPIO_PIN_SET)
	{
		*PORT |= (1<<pinNum);
	} 
	else
	{
		*PORT &= ~(1<<pinNum);
	}
}

uint8_t Gpio_readPort(volatile uint8_t* PIN)
{
	return *PIN;
}

uint8_t Gpio_readPin(volatile uint8_t* PIN, uint8_t pinNum)
{
	//PIN
	//PINA & (1<<0)
	
	return ((*PIN & (1<<pinNum)) != 0);
	//pushed 일 경우 return 0;
	//released 일 경우 return 1;
}