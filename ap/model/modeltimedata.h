
#ifndef MODELTIMEDATA_H_
#define MODELTIMEDATA_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void model_SetTimeClockData(uint32_t data);
uint32_t model_GetTimeClockData();


	
#endif /* MODELTIMEDATA_H_ */