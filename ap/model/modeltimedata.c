#include "modeltimedata.h"

uint32_t TimeClockData;

void model_SetTimeClockData(uint32_t data)
{
	TimeClockData = data;
}

uint32_t model_GetTimeClockData()
{
	return TimeClockData;
}