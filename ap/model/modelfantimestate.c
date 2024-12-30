#include "modelfantimestate.h"

uint8_t fan_TimeModeState;
uint16_t fan_TimeData;
uint32_t fan_MiliTimeData;

void model_SetFanTimeStateData(uint8_t data)
{
	fan_TimeModeState = data;
}

uint8_t model_GetFanTimeStateData()
{
	return fan_TimeModeState;
}

void model_SetFanTimeData(uint16_t data)
{
	fan_TimeData = data;
}

uint16_t model_GetFanTimeData()
{
	return fan_TimeData;
}

void model_SetFanMiliTimeData(uint32_t miliData)
{
	fan_MiliTimeData = miliData;
}

uint32_t model_GetFanMiliTimeData()
{
	return fan_MiliTimeData;
}