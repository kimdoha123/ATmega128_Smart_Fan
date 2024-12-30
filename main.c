#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "driver/lcd/lcd.h"
#include "driver/fan/fan.h"
#include "driver/fnd/fnd.h"
#include "driver/buzzer/buzzer.h"
#include "periph/timer/timer.h"

#include "ap/listener/listener.h"
#include "ap/presenter/presenter.h"
#include "ap/service/fansystem.h"

#include "ap/model/modelfanmodestate.h"
#include "ap/model/modelfantimestate.h"
#include "ap/model/modeltimedata.h"

FILE OUTPUT_F = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);

ISR(TIMER0_OVF_vect)
{
	FND_ISR_process();
	TCNT0 = 130;
}

ISR(TIMER2_COMP_vect)
{
	militimecount();
	fanTimerCountDown();
}

ISR(USART0_RX_vect)
{
	UART0_ISR_Process();
}

int main(void)
{
	
	presenter_init();
	UART0_init();
	stdout = &OUTPUT_F;
		
	Timer0_init();
	Timer2_init();
	Timer3_init();
	
	
	DDRE |= (1<<3);
	DDRB |= (1<<5);
	
	model_SetFanTimeStateData(TIME0);
	model_SetFanModeStateData(OFF);
	model_SetPrevFanModeStateData(OFF);
	model_SetFanMiliTimeData(0);
	model_SetFanTimeData(0);
	
	Buzzer2_init();
	Buzzer2_powerOffSound();
	militimecountset();
	listener_init();
	
	sei();
	
    while (1) 
    {
		listener_FanModeChange();
		presenter_FanSpeedData();
		presenter_FanDispData();
		listener_FanUARTChange();
		listener_FanTimeUARTChange();
	}
}

