#include "modelautodata.h"

uint16_t Auto_Speed, Auto_Duration;

void model_SetAutoSpeedData(uint16_t speed)
{
	Auto_Speed = speed;
}

uint16_t model_GetAutoSpeedData()
{
	return Auto_Speed;
}

void model_SetAutoDurationData(uint16_t dur)
{
	Auto_Duration = dur;
}

uint16_t model_GetAutoDurationData()
{
	return Auto_Duration;
}