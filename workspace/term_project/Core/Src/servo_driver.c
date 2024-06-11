/*
 * servo_driver.c
 *
 *  Created on: May 30, 2024
 *      Author: evananthony
 */

#include "servo_driver.h"

void enable_servo(Servo_DriverTypeDef* servo){
	// Enables servo motor PWM output channel
	HAL_TIM_PWM_Start(servo->pwmHandle, servo->timer_ch);

}

void disable_servo(Servo_DriverTypeDef* servo){
	// Disables servo motor PWM output channel
	HAL_TIM_PWM_Stop(servo->pwmHandle, servo->timer_ch);

}

float servo_get_position(Servo_DriverTypeDef* servo){
	// Gets the current position of the servo relative to the initial position
	float position;
	float PW = (((float)(servo->current_CCR)*20)/(float)(servo->timer_ARR + 1));
	position = (90*PW) - 135;
	return position;
}

void servo_set_position(Servo_DriverTypeDef* servo, float angle){
	// Sets the current position of the servo to an angle from -90 to 90 degrees

	if (angle > 90){
		angle = 90;
	}
	else if (angle < -90){
		angle = -90;
	}

	float PW = (angle + 135) / 90;
	float CCR = (PW * (servo->timer_ARR + 1)) / 20;
	servo->current_CCR = (uint32_t)CCR;
	__HAL_TIM_SET_COMPARE(servo->pwmHandle, servo->timer_ch, CCR);
}

void servo_change_relative_PW(Servo_DriverTypeDef* servo, float PW){
	// Changes the pulse width of the PWM output relative to the latest pulse width output
	float current_PW = (float)((servo->current_CCR)/(servo->timer_ARR + 1)*20);
	float next_PW = current_PW + PW;
	float CCR = (next_PW * (servo->timer_ARR + 1)) / 20;
	servo->current_CCR = (uint32_t)CCR;
	__HAL_TIM_SET_COMPARE(servo->pwmHandle, servo->timer_ch, CCR);

}

