/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "../Services/Platform_Types.h"
#include "../Services/stm32f103c6.h"
#include "../Services/Utils.h"
#include "../MCAL/Inc/GPIO.h"
#include "../MCAL/Inc/EXTI.h"
#include "../MCAL/Inc/USART.h"
#include "../MCAL/Inc/SPI.h"
#include "../MCAL/Inc/I2C.h"
#include "../MCAL/Inc/GPTM.h"
#include "../HAL/Inc/LCD.h"
#include "../HAL/Inc/keypad.h"
#include "../HAL/Inc/EEPROM.h"
#include "../HAL/Inc/SevenSegment.h"
#include "../HAL/Inc/Servo.h"

uint8_t IRQ_Flag = 0;

uint32_t VAL_CONTROL 	= 0;
uint32_t VAL_IPSR 		= 0;

void CallBackFunction(void)
{
	IRQ_Flag = 1;

	//Start
	__asm("nop \n\t"
		  "nop \n\t"
		  "nop \n\t"
		);

	//Lab 6 - Mastering this section
	__asm("mrs %[out],IPSR"
		:[out] "=r" (VAL_IPSR)					//Fisrt:  Output parameters
		 );

	//End
	__asm("nop \n\t"
		  "nop \n\t"
		  "nop \n\t"
		);

}

int main(void)
{
	EXTI_PinConfig_t EXTIConfig;
	EXTIConfig.EXTI_Enable 		= EXTI_IRQ_ENABLE;
	EXTIConfig.EXTI_Pin 		= EXTIPB9;
	EXTIConfig.EXTI_Trigger		= EXTI_TRIGGER_RISING;
	EXTIConfig.IRQ_CallBackPtr 	= CallBackFunction;
	MCAL_EXTI_Init(&EXTIConfig);

	//Start
	__asm("nop \n\t"
		  "nop \n\t"
		  "nop \n\t"
		);


	//Lab 6 - Mastering this section
	__asm("mrs %[out],CONTROL"
		:[out] "=r" (VAL_CONTROL)				//Fisrt:  Output parameters
		 );

	//End
	__asm("nop \n\t"
		  "nop \n\t"
		  "nop \n\t"
		);


	while(1)
	{
		if(IRQ_Flag)
			IRQ_Flag = 0;
	}
}