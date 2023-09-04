/*
 ******************************************************************************
 * @file           : Pressure_Sensor.c
 * @author         : Mohamed Ahmed Hassan
 * @date           : Sep 4 2023
 ******************************************************************************
*/

#include "Pressure_Sensor.h"

static uint32_t PS_pVal = 0;

// STATE Pointer to Function
void (*PS_StateFuncPtr)();

STATE_FUNC(PS_INIT){
	//Init
	//------
	//Pressure Sensor State
	PS_State = PS_INIT;
	//Change State
	PS_StateFuncPtr = STATE_NAME(PS_READING);
}
STATE_FUNC(PS_READING){
	//Pressure Sensor State
	PS_State = PS_READING;
	//get pressure value
	PS_pVal = getPressureVal();
	//Change State
	PS_StateFuncPtr = STATE_NAME(PS_WAITING);

}
STATE_FUNC(PS_WAITING){
	//Pressure Sensor State
	PS_State = PS_WAITING;
	// Wait for data
	Delay(1000);
	//Change State
	PS_StateFuncPtr = STATE_NAME(PS_READING);
}

uint32_t PS_SetPressureValue(void){
	return PS_pVal;
}