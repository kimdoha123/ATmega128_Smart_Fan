
#ifndef PRESENTER_H_
#define PRESENTER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "../model/modelfanmodestate.h"
#include "../model/modelfantimestate.h"
#include "../model/modelautodata.h"
#include "../../driver/fan/fan.h"
#include "../../driver/lcd/lcd.h"
#include "../../driver/fnd/fnd.h"
#include "../../driver/buzzer/buzzer.h"
#include "../service/fansystem.h"

void presenter_init();
void presenter_FanSpeedData();
//void presenter_FanTimerData();
void presenter_FanDispTimerData();
void presenter_FanDispData();

#endif /* PRESENTER_H_ */