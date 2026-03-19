#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "Library/Bit_Math.h"
#include "Library/STD_TYPE_H_.h"
#include "MCAL/DIO/DIO_Rgister.h"
#include "MCAL/DIO/Interface.h"
#include "MCAL/HAL/LED/LED_Interface.h"
#include "MCAL/HAL/Switch/Switch_Interface.h"
#include "MCAL/HAL/Motor/Motor_Interface.h"
#include "MCAL/HAL/_7_Segment/_7_Segment_Interface.h"
#include "MCAL/HAL/IRSENSOR/IRSENSOR_Interface.h"

int main(void)
{
	MCUCSR |= (1 << JTD);
	MCUCSR |= (1 << JTD);   // disable JTAG

	// IR Sensors
	IRSENSOR_Config IR_ENTER = {DIO_u8PORTC, DIO_u8PIN0};
	IRSENSOR_voidInit(&IR_ENTER);

	IRSENSOR_Config IR_EXIT = {DIO_u8PORTC, DIO_u8PIN1};
	IRSENSOR_voidInit(&IR_EXIT);

	// Motor
	Motor_Config MOTOR = {DIO_u8PORTC, DIO_u8PIN2, DIO_u8PIN3};
	Motor_voidInit(&MOTOR);
	Motor_voidSTOP(&MOTOR);   // ensure motor is off at startup

	// 7-Segment
	SSD_Config Segment = {DIO_u8PORTD, COMMON_CATHODE};
	SSD_voidInit(&Segment);
	unsigned COUNT = 0;

	// LED
	Led_config LED = {DIO_u8PORTA, DIO_u8PIN0, SOURCE_CONNECTION};
	LED_voidInit(&LED);

	u8 prev_enter = 0;
	u8 prev_exit = 0;

	while (1)
	{
		u8 ENTER_STATE = IRSENSOR_u8Read(&IR_ENTER);
		u8 EXIT_STATE  = IRSENSOR_u8Read(&IR_EXIT);

		// Detect new entry
		if (ENTER_STATE == 1 && prev_enter == 0 && COUNT < 4)
		{
			COUNT++;
			SSD_u8SetNumber(&Segment, COUNT);

			Motor_voidSTOP(&MOTOR);
			_delay_ms(5);
			Motor_voidMOVE(&MOTOR, CLOCK_WISE);
			_delay_ms(50);
			Motor_voidSTOP(&MOTOR);
		}

		// Detect new exit
		if (EXIT_STATE == 1 && prev_exit == 0 && COUNT > 0)
		{
			COUNT--;
			SSD_u8SetNumber(&Segment, COUNT);

			Motor_voidSTOP(&MOTOR);
			_delay_ms(5);
			Motor_voidMOVE(&MOTOR, COUNTER_CLOCK_WISE);
			_delay_ms(50);
			Motor_voidSTOP(&MOTOR);
		}

		prev_enter = ENTER_STATE;
		prev_exit  = EXIT_STATE;

		if (COUNT == 4)
		LED_voidLedON(&LED);
		else
		LED_voidLedOFF(&LED);
	}
}