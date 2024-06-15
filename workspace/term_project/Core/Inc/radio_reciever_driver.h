/**
 * @file radio_reciever_driver.h
 * @brief Sets up the radio receiver driver structure
 *
 *  Created on: May 17, 2024
 *  @author Christopher Ng
 */

#ifndef INC_RADIO_RECIEVER_DRIVER_H_
#define INC_RADIO_RECIEVER_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

/**
 *  @brief 		A structure to contain the variables of the radio receiver driver typedefs
 *	@param 		*tim_handle: The PWM output timer handle
 *	@param 		tim_channel1: The designated timer channel 1 for channel signal 1
 *	@param 		tim_channel2: The designated timer channel 2 for channel signal 2
 *	@param 		IC_Rise: The rising edge timer value (us)
 *	@param 		IC_Fall: The falling edge timer value (us)
 *	@param 		IC_Diff: The difference between rising and falling edge timer values (us)
 *	@param		pulse_width: The pulse width accounting for overflow
 *	@param 		tol: The tolerance of IC values before an error output is detected
 *	@param 		pulse_reciever_flag: A flag called for a change in pulse amplitude from HAL_TIM_IC_CaptureCallback
 *	@param 		rise_flag: A flag for the rising edge
 */
struct rad_struct{
	TIM_HandleTypeDef* tim_handle;
	uint32_t tim_channel1;
	uint32_t tim_channel2;
	uint16_t IC_Rise;
	uint16_t IC_Fall;
	uint16_t IC_Diff;
	uint16_t pulse_width;
	uint16_t tol;
	int pulse_recieve_flag;
	int rise_flag;
} typedef RadioReciever_DriverTypeDef;

/**
 *  @brief 		Enables the radio receiver timer channels for PWM inputs
 *	@param 		*rad: The structure for the radio receiver driver
 */
void enable_rad(RadioReciever_DriverTypeDef* rad);

/**
 * 	@fn			disable_rad
 *  @brief 		Disables the radio receiver timer channels for PWM inputs
 *	@param 		*rad: The structure for the radio receiver driver
 */
void disable_rad(RadioReciever_DriverTypeDef* rad);

/**
 *  @brief		Returns the pulse width of the radio receiver
 *	@param 		*rad: The structure for the radio receiver driver
 *	@return		The pulse width of the radio receiver (us)
 */
uint16_t get_pulse(RadioReciever_DriverTypeDef* rad);

/**
 *  @brief		Reads the pulse width of the radio receiver
 *	@param 		*rad: The structure for the radio receiver driver
 *	@param 		*htim: The timer that had a pulse read from (used for two channel applications)
 */
void read_pulse(RadioReciever_DriverTypeDef* rad, TIM_HandleTypeDef* htim);

#endif /* INC_RADIO_RECIEVER_DRIVER_H_ */
