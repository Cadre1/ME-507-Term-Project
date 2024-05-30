/*
 * motor_driver.h
 *
 *  Created on: Apr 23, 2024
 *      Author: cadre
 */

#ifndef INC_MOTOR_DRIVER_H_
#define INC_MOTOR_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

struct{
	TIM_HandleTypeDef* tim_handle;
	uint32_t tim_channel1;
	uint32_t tim_channel2;
	uint32_t tim_channel3;
	uint32_t tim_channel4;
	uint32_t pulse;
} typedef Motor_DriverTypeDef;

void enable_mot(Motor_DriverTypeDef* mot, uint32_t motor_num);
void disable_mot(Motor_DriverTypeDef* mot, uint32_t motor_num);
void set_PWM_percent(Motor_DriverTypeDef* mot, uint32_t motor_num, int32_t duty_cycle);
void set_PWM(Motor_DriverTypeDef* mot, uint32_t motor_num, int32_t duty_count);

#endif /* INC_MOTOR_DRIVER_H_ */
