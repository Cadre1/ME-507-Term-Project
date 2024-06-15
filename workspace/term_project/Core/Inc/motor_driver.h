/**
 * @file motor_driver.h
 * @brief Sets up the motor driver structure
 *
 *  Created on: Apr 23, 2024
 *  @author Christopher Ng
 */

#ifndef INC_MOTOR_DRIVER_H_
#define INC_MOTOR_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

/**
 *  @brief 		A structure to contain the variables of the motor driver typedefs
 *	@param 		*tim_handle: The PWM output timer handle
 *	@param 		tim_channel1: The designated timer channel 1 for motor 1
 *	@param 		tim_channel2: The designated timer channel 2 for motor 1
 *	@param 		tim_channel3: The designated timer channel 1 for motor 2
 *	@param 		tim_channel4: The designated timer channel 2 for motor 2
 *	@param 		pulse: The pulse value used for motor outputs
 */
struct{
	TIM_HandleTypeDef* tim_handle;
	uint32_t tim_channel1;
	uint32_t tim_channel2;
	uint32_t tim_channel3;
	uint32_t tim_channel4;
	uint32_t pulse;
} typedef Motor_DriverTypeDef;

/**
 *  @brief 		Enables the desired motor timer channels for PWM outputs
 *	@param 		*mot: The structure for the motor driver
 */
void enable_mot(Motor_DriverTypeDef* mot, uint32_t motor_num);

/**
 *  @brief 		Disables the desired motor timer channels for PWM outputs
 *	@param 		*mot: The structure for the motor driver
 */
void disable_mot(Motor_DriverTypeDef* mot, uint32_t motor_num);

/**
 *  @brief 		Sets the PWM output using a percent input
 *	@param 		*mot: The structure for the motor driver
 *	@param 		motor_num: The motor to set its PWM
 *	@param		duty_cycle: The percentage duty cycle of the PWM output
 */
void set_PWM_percent(Motor_DriverTypeDef* mot, uint32_t motor_num, int32_t duty_cycle);

/**
 *  @brief 		Sets the PWM output using a count input
 *	@param 		*mot: The structure for the motor driver
 *	@param 		motor_num: The motor to set its PWM
 *	@param		duty_cycle: The count duty cycle of the PWM output
 */
void set_PWM(Motor_DriverTypeDef* mot, uint32_t motor_num, int32_t duty_count);

#endif /* INC_MOTOR_DRIVER_H_ */
