#include "modelfanmodestate.h"

uint8_t fan_ModeState, fan_PrevModeState;

void model_SetFanModeStateData(uint8_t data)
{
	fan_ModeState = data;
}

uint8_t model_GetFanModeStateData()
{
	return fan_ModeState;
}

void model_SetPrevFanModeStateData(uint8_t data)
{
	fan_PrevModeState = data;
}

uint8_t model_GetPrevFanModeStateData()
{
	return fan_PrevModeState;
}