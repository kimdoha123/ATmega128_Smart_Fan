#include "presenter.h"
uint8_t secondname;
uint32_t milisec;
uint8_t FanTimeData, autostate;
uint32_t min=0, sec=0;
char *Speed[5] = {"OFF ", "SPD1", "SPD2", "SPD3", "AUTO"};

void presenter_init()
{
	LCD_init();
	FND_init();
	secondname = 0;
	milisec = 0;
}

void presenter_FanSpeedData()
{
	uint8_t fanModeState = model_GetFanModeStateData();
	
	switch (fanModeState)
	{
		case OFF:
		fan_Off();
		break;
		
		case WEAK:
		fan_On();
		fan_makeHertz(300);
		break;
		
		case MIDDLE:
		//fan_On();
		fan_makeHertz(600);
		break;
		
		case STRONG:
		//fan_On();
		fan_makeHertz(1200);
		break;
		
		case AUTO:
		if(autostate == 0)
		{
			fan_On();
			fan_makeHertz(300);
			if(secondname == 1)
			{
				autostate++;
				secondname = 0;
				return;
			}
		}
		else if(autostate == 1)
		{
			fan_Off();
			if(secondname == 1)
			{
				autostate++;
				secondname = 0;
				return;
			}
		}
		else if(autostate == 2)
		{
			fan_On();
			fan_makeHertz(1200);
			if(secondname == 1)
			{
				autostate++;
				secondname = 0;
				return;
			}
		}
		else if(autostate == 3)
		{
			fan_Off();
			if(milisec == 1000)
			{
				autostate++;
				milisec = 0;
				return;
			}
		}
		break;
	}
}

void presenter_FanDispData()
{
	uint8_t fanModeState = model_GetFanModeStateData();
	char Fan_buff[30];
	
	uint32_t FanMiliTimeData = model_GetFanMiliTimeData();
	sec = (FanMiliTimeData+1)/1000%60;
	min = (FanMiliTimeData+1)/1000/60;
	
	uint16_t data = min*100+sec;
	char buff[80];
	
	FND_setFndData(data);
	if((FanMiliTimeData%1000) < 500)
	{
		FND_colonOn();
	}
	else
	{
		FND_colonOff();
	}
	
	
	switch (fanModeState)
	{
		case OFF:
		sprintf(Fan_buff, "%s ", Speed[0]);
		break;
		
		case WEAK:
		sprintf(Fan_buff, "%s ", Speed[1]);
		break;
		
		case MIDDLE:
		sprintf(Fan_buff, "%s ", Speed[2]);
		break;
		
		case STRONG:
		sprintf(Fan_buff, "%s ", Speed[3]);
		break;
		
		case AUTO:
		sprintf(Fan_buff, "%s ", Speed[4]);
		break;
	}
	sprintf(buff, "Intel 5th Fan");
	LCD_writeStringXY(0,2,buff);
	sprintf(buff, "%02d:%02d", (int)min, (int)sec);
	LCD_writeStringXY(1, 3, strcat(Fan_buff, buff));
}

void Presenter_speedButtonSound()
{
	Buzzer2_speedButtonSound();
}
void Presenter_timerButtonSound()
{
	Buzzer2_timerButtonSound();
}
void Presenter_PowerOnSound()
{
	Buzzer2_powerOnSound();
}
void Presenter_PowerOffSound()
{
	Buzzer2_powerOffSound();
}
void Presenter_timerOffSound()
{
	Buzzer2_TimerSound();
}
void Presenter_ISR_Process()
{
	FND_ISR_process();
}