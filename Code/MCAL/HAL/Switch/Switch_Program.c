#include "../../../Library/Bit_Math.h"
#include "../../../Library/STD_TYPE_H_.h"
#include "../../../MCAL/DIO/DIO_Rgister.h"

#include "Switch_Interface.h"

void SWITCH_voidInit(SWITCH_config * target_SWITCH)
{
	DIO_u8SetPinDirection(target_SWITCH->PORT, target_SWITCH->PIN, DIO_u8INPUT);
	
	if (target_SWITCH->PULL_type == PULL_UP_CONNECTION)
	{
		DIO_u8SetPinValue(target_SWITCH->PORT, target_SWITCH->PIN, DIO_u8PIN_HIGH);
	}
}

u8 SWITCH_u8GetState(SWITCH_config * target_SWITCH)
{
	u8 Local_u8SwitchState = NOT_PRESSED;
	
	u8 Switch_Reading = 0;
	DIO_u8GetPinValue(target_SWITCH->PORT, target_SWITCH->PIN, &Switch_Reading);
	if (Switch_Reading == 0 && target_SWITCH->PULL_type == PULL_UP_CONNECTION)
	{
		Local_u8SwitchState = PRESSED;
	}
	else if (Switch_Reading == 1 && target_SWITCH->PULL_type == PULL_DOWN_CONNECTION)
	{
		Local_u8SwitchState = PRESSED;
	}
	return Local_u8SwitchState;
}
