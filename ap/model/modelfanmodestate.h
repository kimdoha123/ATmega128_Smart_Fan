
#ifndef MODELFANMODESTATE_H_
#define MODELFANMODESTATE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void model_SetFanModeStateData(uint8_t data);
uint8_t model_GetFanModeStateData();
void model_SetPrevFanModeStateData(uint8_t data);
uint8_t model_GetPrevFanModeStateData();

enum {OFF, WEAK, MIDDLE, STRONG, AUTO};

#endif /* MODELFANMODESTATE_H_ */