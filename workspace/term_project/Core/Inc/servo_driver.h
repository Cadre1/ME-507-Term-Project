/**
 * @file servo_driver.h
 * @brief Sets up the servo driver structure
 *
 *  Created on: May 30, 2024
 *  @author Evan Anthony
 */

#ifndef INC_SERVO_DRIVER_H_
#define INC_SERVO_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

/**
 *  @brief 		A structure to contain the variables of the servo driver typedefs
 *	@param 		*pwmHandle: The PWM output timer handle
 *	@param 		tim_ch: The PWM output timer channel
 *	@param		current_CCR: The current pulse value
 *	@param		timer_ARR: The timer auto reload value
 */
struct {
	TIM_HandleTypeDef* pwmHandle;
	uint32_t timer_ch;
	uint32_t current_CCR;
	uint32_t timer_ARR;
} typedef Servo_DriverTypeDef;

/**
 *  @brief 		Enables the servo motor timer channel for PWM output
 *	@param 		*servo: The structure for the servo driver
 */
void enable_servo(Servo_DriverTypeDef* servo);

/**
 *  @brief 		Disables the servo motor timer channel for PWM output
 *	@param 		*servo: The structure for the servo driver
 */
void disable_servo(Servo_DriverTypeDef* servo);

/**
 *  @brief 		Returns the positon of the servo
 *	@param 		*servo: The structure for the servo driver
 *	@return		The servo position (degrees)
 */
float servo_get_position(Servo_DriverTypeDef* servo);

/**
 *  @brief 		Sets the servo position
 *	@param 		*servo: The structure for the servo driver
 *	@param		angle: The desired servo angle (degrees)
 */
void servo_set_position(Servo_DriverTypeDef* servo, float angle);

/**
 *  @brief 		Sets the servo position relative to the last position
 *	@param 		*servo: The structure for the servo driver
 *	@param		PW: The change in pulse width
 */
void servo_change_relative_PW(Servo_DriverTypeDef* servo, float PW);


#endif /* INC_SERVO_DRIVER_H_ */
