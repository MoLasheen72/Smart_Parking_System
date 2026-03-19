#include "../../../Library/Bit_Math.h"		//MUST BE FIRST
#include "../../../Library/STD_TYPE_H_.h"
#include "../../../MCAL/DIO/DIO_Rgister.h"

#include "IRSENSOR_Interface.h"

void IRSENSOR_voidInit(IRSENSOR_Config * Sensor)
{
	DIO_u8SetPinDirection(Sensor->PORT, Sensor->PIN, DIO_u8INPUT);
}

u8 IRSENSOR_u8Read(IRSENSOR_Config * Sensor)
{
	u8 Sensor_Value = 0;
	DIO_u8GetPinValue(Sensor->PORT, Sensor->PIN, &Sensor_Value);
	return Sensor_Value;
}