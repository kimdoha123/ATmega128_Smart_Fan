#include "listener.h"

button_t btnOnOff, btnFanSpeed, btnAuto, btntimer;
uint8_t fanState, prevState, fanTimeState;

void listener_init()
{
	//button 초기화, btn1 onoff, btn2 풍량조절, btn3 자동모드 변경, btn4 타이머 설정
	Button_init(&btnOnOff, &BUTTON_DDR, &BUTTON_PIN, 0);
	Button_init(&btnFanSpeed, &BUTTON_DDR, &BUTTON_PIN, 1);
	Button_init(&btnAuto, &BUTTON_DDR, &BUTTON_PIN, 2);
	Button_init(&btntimer, &BUTTON_DDR, &BUTTON_PIN, 3);
}

void listener_FanModeChange()
{
	fanState = model_GetFanModeStateData();
	
	switch (fanState)
	{
		case OFF:
		//fan_Off();
		if(ButtonGetState(&btnFanSpeed) == ACT_RELEASED || ButtonGetState(&btnOnOff) == ACT_RELEASED)
		{
			Presenter_PowerOnSound();
			fanState = WEAK;
			model_SetFanModeStateData(fanState);
		}
		break;
		
		case WEAK:
		listener_FanTimeChange();
		if (ButtonGetState(&btnFanSpeed) == ACT_RELEASED)
		{
			Presenter_speedButtonSound();
			fanState = MIDDLE;
			model_SetFanModeStateData(fanState);
		}
		else if (ButtonGetState(&btnOnOff) == ACT_RELEASED)
		{
			Buzzer2_powerOffSound();
			fanState = OFF;
			model_SetFanModeStateData(fanState);
		}
		else if (ButtonGetState(&btnAuto) == ACT_RELEASED)
		{
			Buzzer2_timerButtonSound();
			prevState = fanState;
			model_SetPrevFanModeStateData(prevState);
			fanState = AUTO;
			model_SetFanModeStateData(fanState);
		}
		break;
		
		case MIDDLE:
		listener_FanTimeChange();
		if (ButtonGetState(&btnFanSpeed) == ACT_RELEASED)
		{
			Presenter_speedButtonSound();
			fanState = STRONG;
			model_SetFanModeStateData(fanState);
		}
		else if (ButtonGetState(&btnOnOff) == ACT_RELEASED)
		{
			Buzzer2_powerOffSound();
			fanState = OFF;
			model_SetFanModeStateData(fanState);
		}
		else if (ButtonGetState(&btnAuto) == ACT_RELEASED)
		{
			Buzzer2_timerButtonSound();
			prevState = fanState;
			model_SetPrevFanModeStateData(prevState);
			fanState = AUTO;
			model_SetFanModeStateData(fanState);
		}
		break;
		
		case STRONG:
		listener_FanTimeChange();
		if (ButtonGetState(&btnFanSpeed) == ACT_RELEASED)
		{
			Presenter_speedButtonSound();
			fanState = WEAK;
			model_SetFanModeStateData(fanState);
		}
		else if (ButtonGetState(&btnOnOff) == ACT_RELEASED)
		{
			Buzzer2_powerOffSound();
			fanState = OFF;
			model_SetFanModeStateData(fanState);
		}
		else if (ButtonGetState(&btnAuto) == ACT_RELEASED)
		{
			Buzzer2_timerButtonSound();
			prevState = fanState;
			model_SetPrevFanModeStateData(prevState);
			fanState = AUTO;
			model_SetFanModeStateData(fanState);
		}
		break;
		
		case AUTO:
		listener_FanTimeChange();
		if (ButtonGetState(&btnFanSpeed) == ACT_RELEASED)
		{
			fan_Off();
			Buzzer2_timerButtonSound();
			fanState = model_GetPrevFanModeStateData();
			model_SetFanModeStateData(fanState);
		}
		else if (ButtonGetState(&btnOnOff) == ACT_RELEASED)
		{
			fan_Off();
			Buzzer2_powerOffSound();
			fanState = OFF;
			model_SetFanModeStateData(fanState);
		}
		break;
	}
}

void listener_FanTimeChange()
{
	fanTimeState = model_GetFanTimeStateData();
	
	switch (fanTimeState)
	{
	case TIME0:
	model_SetFanTimeData(0);
	if(ButtonGetState(&btntimer) == ACT_RELEASED)
	{
		Buzzer2_TimerSound();
		fanTimeState = TIME1;
		model_SetFanTimeStateData(fanTimeState);
	}
	else if(ButtonGetState(&btnOnOff) == ACT_RELEASED)
	{
		Buzzer2_powerOffSound();
		fanState = OFF;
		model_SetFanModeStateData(fanState);
	}
	break;
	
	case TIME1:
	model_SetFanTimeData(180);
	if(ButtonGetState(&btntimer) == ACT_RELEASED)
	{
		Buzzer2_TimerSound();
		fanTimeState = TIME2;
		model_SetFanTimeStateData(fanTimeState);
	}
	else if(ButtonGetState(&btnOnOff) == ACT_RELEASED)
	{
		Buzzer2_powerOffSound();
		fanState = OFF;
		model_SetFanModeStateData(fanState);
	}
	break;
	
	case TIME2:
	model_SetFanTimeData(300);
	if(ButtonGetState(&btntimer) == ACT_RELEASED)
	{
		Buzzer2_TimerSound();
		fanTimeState = TIME3;
		model_SetFanTimeStateData(fanTimeState);
	}
	else if(ButtonGetState(&btnOnOff) == ACT_RELEASED)
	{
		Buzzer2_powerOffSound();
		fanState = OFF;
		model_SetFanModeStateData(fanState);
	}
	break;
	
	case TIME3:
	model_SetFanTimeData(420);
	if(ButtonGetState(&btntimer) == ACT_RELEASED)
	{
		Buzzer2_TimerDownSound();
		fanTimeState = TIME0;
		model_SetFanTimeStateData(fanTimeState);
	}
	else if(ButtonGetState(&btnOnOff) == ACT_RELEASED)
	{
		Buzzer2_powerOffSound();
		fanState = OFF;
		model_SetFanModeStateData(fanState);
	}
	break;
	}
}

void listener_FanUARTChange()
{
	fanState = model_GetFanModeStateData();
	
	switch (fanState)
	{
		case OFF:
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!(strcmp((char *)rxString,"SPEED_CHANGE\n")) || !(strcmp((char *)rxString,"ON_OFF\n")))
			{
				fanState = WEAK;
				model_SetFanModeStateData(fanState);
				printf("WEAK\n");
			}
		}
		case WEAK:
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"SPEED_CHANGE\n"))
			{
				fanState = MIDDLE;
				model_SetFanModeStateData(fanState);
				printf("MIDDLE\n");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
			else if(!strcmp((char *)rxString,"AUTO\n"))
			{
				prevState = fanState;
				model_SetPrevFanModeStateData(prevState);
				fanState = AUTO;
				model_SetFanModeStateData(fanState);
				printf("AUTO\n");
			}
		}
		break;
		
		case MIDDLE:
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"SPEED_CHANGE\n"))
			{
				fanState = STRONG;
				model_SetFanModeStateData(fanState);
				printf("STRONG\n");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
			else if(!strcmp((char *)rxString,"AUTO\n"))
			{
				prevState = fanState;
				model_SetPrevFanModeStateData(prevState);
				fanState = AUTO;
				model_SetFanModeStateData(fanState);
				printf("AUTO\n");
			}
		}
		break;
		
		case STRONG:
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"SPEED_CHANGE\n"))
			{
				fanState = WEAK;
				model_SetFanModeStateData(fanState);
				printf("WEAK\n");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
			else if(!strcmp((char *)rxString,"AUTO\n"))
			{
				prevState = fanState;
				model_SetPrevFanModeStateData(prevState);
				fanState = AUTO;
				model_SetFanModeStateData(fanState);
				printf("AUTO\n");
			}
		}
		break;
		
		case AUTO:
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"SPEED_CHANGE\n"))
			{
				fanState = model_GetPrevFanModeStateData();
				model_SetFanModeStateData(fanState);
				printf("PREV\n");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
		}
		break;
	}
}

void listener_FanTimeUARTChange()
{
	fanTimeState = model_GetFanTimeStateData();
	
	switch (fanTimeState)
	{
		case TIME0:
		model_SetFanTimeData(0);
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"TIMER_CHANGE\n"))
			{
				fanTimeState = TIME1;
				model_SetFanTimeStateData(fanTimeState);
				printf("TIMER1");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
		}
		break;
		
		case TIME1:
		model_SetFanTimeData(180);
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"TIMER_CHANGE\n"))
			{
				fanTimeState = TIME2;
				model_SetFanTimeStateData(fanTimeState);
				printf("TIMER2");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
		}
		break;
		
		case TIME2:
		model_SetFanTimeData(300);
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"TIMER_CHANGE\n"))
			{
				fanTimeState = TIME3;
				model_SetFanTimeStateData(fanTimeState);
				printf("TIMER3");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
		}
		break;
		
		case TIME3:
		model_SetFanTimeData(420);
		if(UART0_getRxFlag())
		{
			UART0_clearRxFlag();
			uint8_t* rxString = UART0_readRxBuff();
			
			if(!strcmp((char *)rxString,"TIMER_CHANGE\n"))
			{
				fanTimeState = TIME0;
				model_SetFanTimeStateData(fanTimeState);
				printf("TIMER_OFF");
			}
			else if(!strcmp((char *)rxString,"ON_OFF\n"))
			{
				fanState = OFF;
				model_SetFanModeStateData(fanState);
				printf("FAN_OFF\n");
			}
		}
		break;
	}
}