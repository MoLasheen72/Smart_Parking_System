#include "../../../Library/Bit_Math.h"		//MUST BE FIRST
#include "../../../Library/STD_TYPE_H_.h"
#include "../../../MCAL/DIO/DIO_Rgister.h"

#include "Motor_Interface.h"

void Motor_voidInit(Motor_Config * target_Motor)
{
	DIO_u8SetPinDirection(target_Motor->PORT, target_Motor->PINX, DIO_u8OUTPUT);
	DIO_u8SetPinDirection(target_Motor->PORT, target_Motor->PINY, DIO_u8OUTPUT);
}

void Motor_voidMOVE(Motor_Config * target_Motor, u8 MotorRotation)
{
	if (MotorRotation == CLOCK_WISE)
	{
		DIO_u8SetPinValue(target_Motor->PORT, target_Motor->PINX, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(target_Motor->PORT, target_Motor->PINY, DIO_u8PIN_HIGH);
	}
	
	else if (MotorRotation == COUNTER_CLOCK_WISE)
	{
		DIO_u8SetPinValue(target_Motor->PORT, target_Motor->PINX, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(target_Motor->PORT, target_Motor->PINY, DIO_u8PIN_LOW);
	}
}

void Motor_voidSTOP(Motor_Config * target_Motor)
{
		DIO_u8SetPinValue(target_Motor->PORT, target_Motor->PINX, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(target_Motor->PORT, target_Motor->PINY, DIO_u8PIN_LOW);
}

