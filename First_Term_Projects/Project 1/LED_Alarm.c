/*
 ******************************************************************************
 * @file           : LED_Alarm.c
 * @author         : Mohamed Ahmed Hassan
 * @date           : Sep 4 2023
 ******************************************************************************
*/

#include "LED_Alarm.h"

// STATE Pointer to Function
void (*LA_StateFuncPtr)();

STATE_FUNC(LA_ALARM_OFF){
	//Alarm Sensor State
	LA_State = LA_ALARM_OFF;
	//Stop Alarm
	LA_StopAlarm();
	//Change State
	if(PC_HighPressureDetected())
		LA_StateFuncPtr = STATE_NAME(LA_ALARM_ON);
	
}
STATE_FUNC(LA_ALARM_ON){
	//Alarm Sensor State
	LA_State = LA_ALARM_ON;
	//Start Alarm
	LA_StartAlarm();
	//Change State
	LA_StateFuncPtr = STATE_NAME(LA_WAITING);

}
STATE_FUNC(LA_WAITING){
	//Alarm Sensor State
	LA_State = LA_WAITING;
	// Wait for data
	Delay(500);
	//Change State
	LA_StateFuncPtr = STATE_NAME(LA_ALARM_OFF);
}
