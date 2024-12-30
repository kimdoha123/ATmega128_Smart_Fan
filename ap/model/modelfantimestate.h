
#ifndef MODELFANTIMESTATE_H_
#define MODELFANTIMESTATE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void model_SetFanTimeStateData(uint8_t data);
uint8_t model_GetFanTimeStateData();
void model_SetFanTimeData(uint16_t data);
uint16_t model_GetFanTimeData();
void model_SetFanMiliTimeData(uint32_t data);
uint32_t model_GetFanMiliTimeData();

enum {TIME0, TIME1, TIME2, TIME3};
enum {TIMER_OFF, TIMER_UP};
#endif /* MODELFANTIMESTATE_H_ */