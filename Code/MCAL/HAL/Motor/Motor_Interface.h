#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_
#include "../../DIO/Interface.h"

#define CLOCK_WISE 1
#define COUNTER_CLOCK_WISE 2

typedef struct
{
	u8 PORT;
	u8 PINX;
	u8 PINY;
}Motor_Config;

void Motor_voidInit(Motor_Config * target_Motor);
void Motor_voidMOVE(Motor_Config * target_Motor, u8 MotorRotation);
void Motor_voidSTOP(Motor_Config * target_Motor);

#endif /* MOTOR_INTERFACE_H_ */