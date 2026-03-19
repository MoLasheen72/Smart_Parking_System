#include "../../../Library/Bit_Math.h"
#include "../../../Library/STD_TYPE_H_.h"
#include "../../../MCAL/DIO/Interface.h"

#include "_7_Segment_Interface.h"

static u8 _7_Segment [10] =
{
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111
};

void SSD_voidInit(SSD_Config * target_SSD)
{
	DIO_u8SetPortDirection(target_SSD->DataPort, DIO_u8PORT_OUTPUT);	
}

u8 SSD_u8SetNumber(SSD_Config *target_SSD, u8 target_number)
{
	u8 ErrorState = 0;
	if(target_number >= 0 && target_number <= 9)
	{
		if (target_SSD->CommonType == COMMON_CATHODE)
		{
			DIO_u8SetPortValue(target_SSD->DataPort, _7_Segment[target_number]);
		}
		else if (target_SSD->CommonType == COMMON_ANODE)
		{
			DIO_u8SetPortValue(target_SSD->DataPort, ~(_7_Segment[target_number]));
		}
	}
	else
	{
		ErrorState = 1;
	}
	return ErrorState;
}

void SSD_DisableCommon(SSD_Config * target_SSD)
{
	if (target_SSD->CommonType == COMMON_CATHODE)
	{
		DIO_u8SetPortValue(target_SSD->DataPort, 0x00);
	}
	else if (target_SSD->CommonType == COMMON_ANODE)
	{
		DIO_u8SetPortValue(target_SSD->DataPort, 0xff);
	}
}



