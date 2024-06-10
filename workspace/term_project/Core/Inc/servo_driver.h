/*
 * servo_driver.h
 *
 *  Created on: May 30, 2024
 *      Author: evananthony
 */

#ifndef INC_SERVO_DRIVER_H_
#define INC_SERVO_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

struct {
	TIM_HandleTypeDef* pwmHandle;
	uint32_t timer_ch;
	uint32_t current_CCR;
	uint32_t timer_ARR;
} typedef Servo_DriverTypeDef;

// PROTOTYPES:

void enable_servo(Servo_DriverTypeDef* servo);
void disable_servo(Servo_DriverTypeDef* servo);
float servo_get_position(Servo_DriverTypeDef* servo);
void servo_set_position(Servo_DriverTypeDef* servo, float angle);
void servo_change_relative_PW(Servo_DriverTypeDef* servo, float PW);


#endif /* INC_SERVO_DRIVER_H_ */