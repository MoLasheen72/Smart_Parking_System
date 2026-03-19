#include "../../../Library/Bit_Math.h"		//MUST BE FIRST
#include "../../../Library/STD_TYPE_H_.h"
#include "../../../MCAL/DIO/DIO_Rgister.h"

#include "LED_Interface.h"

void LED_voidInit(Led_config * target_LED)
{
	DIO_u8SetPinDirection(target_LED->PORT, target_LED->PIN, DIO_u8OUTPUT);
}

void LED_voidLedON(Led_config * target_LED)
{
	if(target_LED->Connection_type == SOURCE_CONNECTION)
	{
		DIO_u8SetPinValue(target_LED->PORT, target_LED->PIN, DIO_u8PIN_HIGH);
	}
	else if(target_LED->Connection_type == SINK_CONNECTION)
	{
		DIO_u8SetPinValue(target_LED->PORT, target_LED->PIN, DIO_u8PIN_LOW);
	}
}

void LED_voidLedOFF(Led_config * target_LED)
{
	if(target_LED->Connection_type == SINK_CONNECTION)
	{
		DIO_u8SetPinValue(target_LED->PORT, target_LED->PIN, DIO_u8PIN_HIGH);
	}
	else if(target_LED->Connection_type == SOURCE_CONNECTION)
	{
		DIO_u8SetPinValue(target_LED->PORT, target_LED->PIN, DIO_u8PIN_LOW);
	}
}