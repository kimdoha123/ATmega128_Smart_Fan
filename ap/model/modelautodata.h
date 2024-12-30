
#ifndef MODELAUTODATA_H_
#define MODELAUTODATA_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void model_SetAutoSpeedData(uint16_t speed);
uint16_t model_GetAutoSpeedData();
void model_SetAutoDurationData(uint16_t dur);
uint16_t model_GetAutoDurationData();


#endif /* MODELAUTODATA_H_ */