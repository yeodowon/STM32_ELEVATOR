#include "main.h"

#define IDLE		0
#define FORWARD		1
#define BACKWARD	2

#define EXT_inactive	0
#define EXT_active 		1

#define INT_inactive	0
#define INT_active		1
#define INT_cancle		2

#define STEPS_PER_REV	4096
#define FLOOR1		1
#define FLOOR2		3
#define FLOOR3		5
#define FLOOR4		7

#define DOOR_CLOSE	0
#define DOOR_OPEN	1

#define VIP_OFF		0
#define VIP_ON		1

void set_rpm(int rpm);
void stepmotor_drive(int direction);

void elevator_activation();

void elevator_mode_select();


void elevator_motor_inactive();


void elevator_motor_active();
void elevator_motor_up();
void elevator_motor_down();


void elevator_motor_cancle();

void elevator_motor_cancle_up();
void elevator_motor_cancle_up_to_floor2();
void elevator_motor_cancle_up_to_floor3();
void elevator_motor_cancle_up_to_floor4();

void elevator_motor_cancle_down();
void elevator_motor_cancle_down_to_floor1();
void elevator_motor_cancle_down_to_floor2();
void elevator_motor_cancle_down_to_floor3();
