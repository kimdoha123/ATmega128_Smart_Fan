#include "Sound.h"

void Speed_run()
{
	uint8_t speedState = model_GetFanModeStateData();
	uint8_t timerState = model_GetFanTimeStateData();
	static uint8_t preSpeedState;
	static uint8_t preOnOffState;
	
	switch(speedState)
	{
		case OFF :
		presenter_FanSpeedData(0);
		if(timerState)
		{
			Presenter_timerOffSound();
		}
		else if(preOnOffState != speedState)
		{
			Presenter_timerOffSound();
		}
		preOnOffState = speedState;
		preSpeedState = speedState;
		model_SetFanTimeStateData(TIMER_OFF);
		break;
		
		case WEAK :
		presenter_FanSpeedData(100);
		if(preOnOffState != speedState)
		{
			Presenter_PowerOnSound();
		}
		else if(preSpeedState != speedState)
		{
			Presenter_speedButtonSound();
		}
		preSpeedState = speedState;
		preOnOffState = speedState;
		break;
		
		case MIDDLE :
		presenter_FanSpeedData(500);
		if(preSpeedState != speedState)
		{
			Presenter_speedButtonSound();
		}
		
		preSpeedState = speedState;
		break;
		
		case STRONG :
		presenter_FanSpeedData(1000);
		if(preSpeedState != speedState)
		{
			Presenter_speedButtonSound();
		}
		break;
		
		//case FAN_AUTO :
		//{
		//static uint32_t prevtime = 0;
		//
		//switch(speedAutoState)
		//{
		//case
		//}
		//}
		//break;
		
	}
}