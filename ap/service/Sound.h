

#ifndef SERVICE_SPEED_H_
#define SERVICE_SPEED_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../model/modelfanmodestate.h"
#include "../model/modelfantimestate.h"
#include "../presenter/presenter.h"
void presenter_FanSpeedData();
void Presenter_timerOffSound();
void Presenter_PowerOnSound();
void Presenter_speedButtonSound();




#endif /* SERVICE_SPEED_H_ */