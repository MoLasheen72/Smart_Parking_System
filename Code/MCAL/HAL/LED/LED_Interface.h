#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "../../DIO/Interface.h"

#define SOURCE_CONNECTION 1
#define SINK_CONNECTION 2

typedef struct 
{
	u8 PORT;
	u8 PIN;
	u8 Connection_type;
} Led_config;

void LED_voidInit(Led_config * target_LED);
void LED_voidLedON(Led_config * target_LED);
void LED_voidLedOFF(Led_config * target_LED);

#endif /* LED_INTERFACE_H_ */