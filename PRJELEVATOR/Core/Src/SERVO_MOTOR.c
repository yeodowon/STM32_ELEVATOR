#include "main.h"	// for GPIO, HAL

extern TIM_HandleTypeDef htim2;	// PWM Control을 위해 TIMER2에 관련된 구조체를 가져온다.


extern volatile int real_distance;		// 거리 측정 값을 저장하는 변수

// 84000000Hz / 1680 ==> 50000Hz = 50KHz
// T = 1/f = 1/50000 = 20us
// 2ms = 20us * 100 ==> 100번 count ==> arm 180도 회전
// 1.5ms = 20us * 75 ==> 75번 count ==> arm 90도 회전
// 1ms = 20us * 50 ==> 50번 count ==> arm 0도 회전

