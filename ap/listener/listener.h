

#ifndef LISTENER_H_
#define LISTENER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../../driver/button/Button.h"
#include "../../driver/fan/fan.h"
#include "../../periph/UART0/UART0.h"
#include "../model/modelfanmodestate.h"
#include "../model/modelfantimestate.h"

#define BUTTON_DDR	DDRA
#define BUTTON_PORT	PORTA
#define BUTTON_PIN	PINA

void listener_init();
void listener_FanModeChange();
void listener_FanTimeChange();
void listener_FanUARTChange();
void listener_FanTimeUARTChange();

#endif /* LISTENER_H_ */