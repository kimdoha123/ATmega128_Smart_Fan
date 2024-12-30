#include "fnd.h"

uint8_t fndNumFont[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x80};
uint16_t numData = 0;
uint8_t fndColonFlag = 0;

void FND_init()
{
	FND_DIGIT_DDR |= ((1<<FND_DIGIT_4) | (1<<FND_DIGIT_3) | (1<<FND_DIGIT_2) | (1<<FND_DIGIT_1)); 
	FND_DATA_DDR = 0xff;
}

void FND_colonOn()
{
	fndColonFlag = 1;
}

void FND_colonOff()
{
	fndColonFlag = 0;
}

void FND_dispNum(uint16_t fndNum)
{
	static uint8_t fndDigitState = 0;
	
	fndDigitState = (fndDigitState+1) % 5;
	
	switch (fndDigitState)
	{
		case 0:
		PORTE = ((1<<7) | (1<<6) | (1<<5) | (1<<4));
		PORTF = fndNumFont[fndNum/1000%10];
		PORTE &= ~(1<<4);
		// _delay_ms(1);
		break;
		case 1:
		PORTE = ((1<<7) | (1<<6) | (1<<5) | (1<<4));
		PORTF = fndNumFont[fndNum/100%10];
		PORTE &= ~(1<<5);
		// _delay_ms(1);
		break;
		case 2:
		PORTE = ((1<<7) | (1<<6) | (1<<5) | (1<<4));
		PORTF = fndNumFont[fndNum/10%10];
		PORTE &= ~(1<<6);
		// _delay_ms(1);
		break;
		case 3:
		PORTE = ((1<<7) | (1<<6) | (1<<5) | (1<<4));
		PORTF = fndNumFont[fndNum%10];
		PORTE &= ~(1<<7);
		// _delay_ms(1);
		break;
		case 4:
		PORTE = ((1<<7) | (1<<6) | (1<<5) | (1<<4));
		if(fndColonFlag)
		{
			PORTF = fndNumFont[10];
		}
		else
		{
			PORTF = 0x00;
		}
		PORTE &= ~(1<<5);
		break;
		//flag
	}
}

void FND_setFndData(uint16_t data)
{
	numData = data;
}

void FND_ISR_process()
{
	FND_dispNum(numData);
}