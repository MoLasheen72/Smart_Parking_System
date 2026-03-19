#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_
#include "../../DIO/Interface.h"

#define PULL_UP_CONNECTION 1
#define PULL_DOWN_CONNECTION 2

#define PRESSED 1
#define NOT_PRESSED 2

typedef struct
{
	u8 PORT;
	u8 PIN;
	u8 PULL_type;
}SWITCH_config;

void SWITCH_voidInit(SWITCH_config * target_SWITCH);
u8 SWITCH_voidGetState(SWITCH_config * target_SWITCH);

#endif /* SWITCH_INTERFACE_H_ */