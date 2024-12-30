#include "fansystem.h"

uint32_t milisec;
uint8_t secondname;

void militimecountset()
{
	milisec = 0;
	secondname = 0;
}

void militimecount()
{
	milisec = (milisec + 1) % 1000;

	
	if(milisec) return;
	
	secondname = (secondname+1) % 3;
	if(secondname) return;
}

void fanTimerCountDown()
{
	uint32_t fanTimeData = model_GetFanTimeData();
	uint8_t fanModeStateData = model_GetFanModeStateData();
	static uint8_t count = 0;
	static uint32_t miliTime = 0;
	
	if (fanModeStateData == OFF)
	{
		model_SetFanTimeData(0);
		model_SetFanMiliTimeData(0);
		model_SetFanTimeStateData(TIME0);
		count = 0;
		return;
	}
	
	if (fanTimeData == 0)
	{
		model_SetFanMiliTimeData(0);
		count = 0;
		return;
	}
	
	if(count==0 && fanTimeData == 180)
	{
		miliTime = 0;
		miliTime = fanTimeData * 1000;
		count++;
	}
	if(count==1 && fanTimeData == 300)
	{
		miliTime = 0;
		miliTime = fanTimeData * 1000;
		count++;
	}
	else if(count==2 && fanTimeData == 420)
	{
		miliTime = 0;
		miliTime = fanTimeData * 1000;
		count=0;
	}
	
	model_SetFanMiliTimeData(miliTime);
	
	//presenter_FanDispTimerData(miliTime);
	miliTime = (miliTime-1);
	//model_SetFanMiliTimeData(miliTime);
	if (miliTime == 0)
	{
		model_SetFanModeStateData(OFF);
		count = 0;
		model_SetFanTimeData(0);
		model_SetFanTimeStateData(TIME0);
	}
}


/*
void service_AutoData()
{
	
}
*/