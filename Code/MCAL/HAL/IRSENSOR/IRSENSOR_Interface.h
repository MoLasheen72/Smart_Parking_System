#ifndef IRSENSOR_INTERFACE_H_
#define IRSENSOR_INTERFACE_H_
#include "../../DIO/Interface.h"

typedef struct
{
	u8 PORT;
	u8 PIN;
} IRSENSOR_Config;

void IRSENSOR_voidInit(IRSENSOR_Config * Sensor);
u8 IRSENSOR_u8Read(IRSENSOR_Config * Sensor);

#endif /* IRSENSOR_INTERFACE_H_ */