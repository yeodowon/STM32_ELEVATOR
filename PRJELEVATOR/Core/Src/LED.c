#include "LED.h"
#include "BUTTON.H"
#include "STEPMOTOR.h"

extern uint8_t prev_button1_state;		// 1층 버튼 상태
extern uint8_t prev_button2_state;		// 2층 버튼 상태
extern uint8_t prev_button3_state;		// 3층 버튼 상태
extern uint8_t prev_button4_state;		// 4층 버튼 상태

extern volatile int floor_count;
extern int motor_state;
extern volatile int elevator_led_counter;	// 엘레베이터 LED가 깜빡거리는 시간 변수

void elevator_led_inactive()
{
	switch(floor_count)
	{
		case STEPS_PER_REV * FLOOR1:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_RESET);
		break;

		case STEPS_PER_REV * FLOOR2:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_RESET);
		break;

		case STEPS_PER_REV * FLOOR3:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
		break;

		case STEPS_PER_REV * FLOOR4:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);
		break;
	}
}

void elevator_led_active()
{
	switch(motor_state)
		{
			case FORWARD:
				elevator_led_up();
			break;

			case BACKWARD:
				elevator_led_down();
			break;
		}
}

// 엘레베이터가 상승하는 중에 LED Display와 관련된 함수
void elevator_led_up()
{
	elevator_led_up_to_floor2();
	elevator_led_up_to_floor3();
	elevator_led_up_to_floor4();
}

void elevator_led_up_to_floor2()
{
	static char led_state = 0;
	// 1층에서 2층으로 올라가는 중
	if((floor_count > STEPS_PER_REV * FLOOR1) && (floor_count < STEPS_PER_REV * FLOOR2))
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
		if(elevator_led_counter >= 250)
		{
			elevator_led_counter = 0;
			led_state = !led_state;
			if(led_state)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
		}
	}
	// 2층에 도착했을 때
	else if(floor_count == STEPS_PER_REV * FLOOR2)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(FLOOR2_LED_GPIO_Port, FLOOR2_LED_Pin, GPIO_PIN_RESET);
	}
}

void elevator_led_up_to_floor3()
{
	static char led_state = 0;
	// 2층에서 3층으로 올라가는 중
	if((floor_count > STEPS_PER_REV * FLOOR2) && (floor_count < STEPS_PER_REV * FLOOR3))
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_SET);
		if(elevator_led_counter >= 250)
		{
			elevator_led_counter = 0;
			led_state = !led_state;
			if(led_state)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
		}
	}
	// 3층에 도착했을 때
	else if(floor_count == STEPS_PER_REV * FLOOR3)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(FLOOR3_LED_GPIO_Port, FLOOR3_LED_Pin, GPIO_PIN_RESET);
	}
}

void elevator_led_up_to_floor4()
{
	static char led_state = 0;
	// 3층에서 4층으로 올라가는 중
	if((floor_count > STEPS_PER_REV * FLOOR3) && (floor_count < STEPS_PER_REV * FLOOR4))
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2, GPIO_PIN_SET);
		if(elevator_led_counter >= 250)
		{
			elevator_led_counter = 0;
			led_state = !led_state;
			if(led_state)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
		}
	}
	// 4층에 도착했을 때
	else if(floor_count == STEPS_PER_REV * FLOOR4)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(FLOOR4_LED_GPIO_Port, FLOOR4_LED_Pin, GPIO_PIN_RESET);
	}
}

// 엘레베이터가 하강하는 중에 LED Display와 관련된 함수
void elevator_led_down()
{
	elevator_led_down_to_floor1();
	elevator_led_down_to_floor2();
	elevator_led_down_to_floor3();
}

void elevator_led_down_to_floor1()
{
	static char led_state = 0;
	// 2층에서 1층으로 내려가는 중
	if((floor_count > STEPS_PER_REV * FLOOR1) && (floor_count < STEPS_PER_REV * FLOOR2))
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
		if(elevator_led_counter >= 250)
		{
			elevator_led_counter = 0;
			led_state = !led_state;
			if(led_state)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
		}
	}
	// 1층에 도착했을 때
	else if(floor_count == STEPS_PER_REV * FLOOR1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FLOOR1_LED_GPIO_Port, FLOOR1_LED_Pin, GPIO_PIN_RESET);
	}
}

void elevator_led_down_to_floor2()
{
	static char led_state = 0;
	// 3층에서 2층으로 내려가는 중
	if((floor_count > STEPS_PER_REV * FLOOR2) && (floor_count < STEPS_PER_REV * FLOOR3))
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_SET);
		if(elevator_led_counter >= 250)
		{
			elevator_led_counter = 0;
			led_state = !led_state;
			if(led_state)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
		}
	}
	// 2층에 도착했을 때
	else if(floor_count == STEPS_PER_REV * FLOOR2)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FLOOR2_LED_GPIO_Port, FLOOR2_LED_Pin, GPIO_PIN_RESET);
	}
}

void elevator_led_down_to_floor3()
{
	static char led_state = 0;
	// 4층에서 3층으로 내려가는 중
	if((floor_count > STEPS_PER_REV * FLOOR3) && (floor_count < STEPS_PER_REV * FLOOR4))
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2, GPIO_PIN_SET);
		if(elevator_led_counter >= 250)
		{
			elevator_led_counter = 0;
			led_state = !led_state;
			if(led_state)
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
		}
	}
	// 3층에 도착했을 때
	else if(floor_count == STEPS_PER_REV * FLOOR3)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FLOOR3_LED_GPIO_Port, FLOOR3_LED_Pin, GPIO_PIN_RESET);
	}
}

void led_all_on()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_SET);
}

void led_all_off()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7, GPIO_PIN_RESET);
}
