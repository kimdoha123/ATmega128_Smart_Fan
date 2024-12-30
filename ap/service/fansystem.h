
#ifndef FANSYSTEM_H_
#define FANSYSTEM_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "../model/modelfanmodestate.h"
#include "../model/modelfantimestate.h"
#include "../model/modelautodata.h"
#include "../model/modeltimedata.h"

#include "../service/fansystem.h"

void fanTimerCountDown();
void service_FanAutoDurationData();
void service_FanAutoSpeedData();
void militimecount();
void militimecountset();

#endif /* FANSYSTEM_H_ */