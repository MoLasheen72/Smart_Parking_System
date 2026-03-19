#ifndef _7_SEGMENT_INTERFACE_H_
#define _7_SEGMENT_INTERFACE_H_
#include "../../DIO/Interface.h"

#define COMMON_CATHODE 1
#define COMMON_ANODE 2

typedef struct
{
	u8 DataPort;
	u8 CommonType;
} SSD_Config;

void SSD_voidInit(SSD_Config * target_SSD);
u8 SSD_u8SetNumber(SSD_Config *target_SSD, u8 target_number);
void SSD_viodDisableCommon(SSD_Config * target_SSD);

#endif /* 7_SEGMENT_INTERFACE_H_ */