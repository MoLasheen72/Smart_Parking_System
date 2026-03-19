#include "../../Library/Bit_Math.h"		//MUST BE FIRST
#include "../../Library/STD_TYPE_H_.h"

#include "Interface.h"
#include "DIO_Rgister.h"

u8 DIO_u8SetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;
	if(copy_u8Pin <= DIO_u8PIN7)
	{
		if(copy_u8Direction == DIO_u8INPUT)
		{	
			switch(copy_u8Port)
			{
				case DIO_u8PORTA:
				CLR_BIT(DDRA, copy_u8Pin); break;
				
				case DIO_u8PORTB:
				CLR_BIT(DDRB, copy_u8Pin); break;
				
				case DIO_u8PORTC:
				CLR_BIT(DDRC, copy_u8Pin); break;
				
				case DIO_u8PORTD:
				CLR_BIT(DDRD, copy_u8Pin); break;
				
				default:
				Local_u8ErrorState = 1; break;
			}
		}
	else if(copy_u8Direction == DIO_u8OUTPUT)
	{
		switch(copy_u8Port)
		{
			case DIO_u8PORTA:
			SET_BIT(DDRA, copy_u8Pin); break;
			
			case DIO_u8PORTB:
			SET_BIT(DDRB, copy_u8Pin); break;
			
			case DIO_u8PORTC:
			SET_BIT(DDRC, copy_u8Pin); break;
			
			case DIO_u8PORTD:
			SET_BIT(DDRD, copy_u8Pin); break;
			
			default:
			Local_u8ErrorState = 1; break;
		}
	}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState ;
}

u8 DIO_u8SetPortDirection(u8 copy_u8Port, u8 copy_u8Direction)
{
	u8 Local_u8ErrorState = 0;
	switch(copy_u8Port)
	{
		case DIO_u8PORTA: DDRA = copy_u8Direction; break;
		case DIO_u8PORTB: DDRB = copy_u8Direction; break;
		case DIO_u8PORTC: DDRC = copy_u8Direction; break;
		case DIO_u8PORTD: DDRD = copy_u8Direction; break;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 copy_u8Value)
{
	u8 Local_u8ErrorState = 0;
	switch(copy_u8Port)
	{
		case DIO_u8PORTA:	PORTA = copy_u8Value; break;
		case DIO_u8PORTB:	PORTB = copy_u8Value; break;
		case DIO_u8PORTC:	PORTC = copy_u8Value; break;
		case DIO_u8PORTD:	PORTD = copy_u8Value; break;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	u8 Local_u8ErrorState = 0;
	if(copy_u8Pin <= DIO_u8PIN7)
	{
		if(copy_u8Value == DIO_u8PIN_LOW)
		{
			
			switch(copy_u8Port)
			{
				case DIO_u8PORTA:
				CLR_BIT(PORTA, copy_u8Pin); break;
				
				case DIO_u8PORTB:
				CLR_BIT(PORTB, copy_u8Pin); break;
				
				case DIO_u8PORTC:
				CLR_BIT(PORTC, copy_u8Pin); break;
				
				case DIO_u8PORTD:
				CLR_BIT(PORTD, copy_u8Pin); break;
				
				default:
				Local_u8ErrorState = 1; break;
			}
		}
		else if(copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch(copy_u8Port)
			{
				case DIO_u8PORTA:
				SET_BIT(PORTA, copy_u8Pin); break;
				
				case DIO_u8PORTB:
				SET_BIT(PORTB, copy_u8Pin); break;
				
				case DIO_u8PORTC:
				SET_BIT(PORTC, copy_u8Pin); break;
				
				case DIO_u8PORTD:
				SET_BIT(PORTD, copy_u8Pin); break;
				
				default:
				Local_u8ErrorState = 1; break;
			}
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8TogglePin(u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 Local_u8ErrorState = 0;
	if(copy_u8Pin <= DIO_u8PIN7)
	{			
			switch(copy_u8Port)
			{
				case DIO_u8PORTA:
				TOG_BIT(PORTA, copy_u8Pin); break;
				
				case DIO_u8PORTB:
				TOG_BIT(PORTB, copy_u8Pin); break;
				
				case DIO_u8PORTC:
				TOG_BIT(PORTC, copy_u8Pin); break;
				
				case DIO_u8PORTD:
				TOG_BIT(PORTD, copy_u8Pin); break;
				
				default:
				Local_u8ErrorState = 1; break;				
			}		
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState ;
}

u8 DIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8* copy_u8Value)
{
	u8 Local_u8ErrorState = 0;
	if(copy_u8Value != NULL && copy_u8Pin <= DIO_u8PIN7)	
	{
		switch(copy_u8Port)
		{
			case DIO_u8PORTA:	*copy_u8Value = GET_BIT(PINA, copy_u8Pin); break;
			case DIO_u8PORTB:	*copy_u8Value = GET_BIT(PINB, copy_u8Pin); break;
			case DIO_u8PORTC:	*copy_u8Value = GET_BIT(PINC, copy_u8Pin); break;
			case DIO_u8PORTD:	*copy_u8Value = GET_BIT(PIND, copy_u8Pin); break;
			
			default:
			Local_u8ErrorState = 1; break;
		}
	}	
	else
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
}
