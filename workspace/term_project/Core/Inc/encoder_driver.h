/**
 * @file encoder.h
 * @brief Sets up the encoder driver structure
 *
 *  Created on: Jun 3, 2024
 *  @author Christopher Ng
 */

#ifndef INC_ENCODER_DRIVER_H_
#define INC_ENCODER_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

/**
 *  @brief 		A structure to contain the variables of the encoder driver typedefs
 *	@param 		*tim_handle: The encoder timer handle
 *	@param 		tim_channel1: The designated timer channel 1
 *	@param 		tim_channel2: The designated timer channel 2
 *	@param 		curr_count: The current encoder count/position value
 *	@param 		prev_count: The previous encoder count/position value
 *	@param 		tot_count: The absolute encoder count/position
 *	@param 		pos: The position of the quad encoder
 *	@param 		AR: The autoreload/max timer count
 */
struct{
	TIM_HandleTypeDef* tim_handle;
	uint32_t tim_channel1;
	uint32_t tim_channel2;
	uint32_t curr_count;
	uint32_t prev_count;
	int32_t tot_count;
	int32_t pos;
	int32_t AR;
} typedef Encoder_DriverTypeDef;

/**
 *  @brief 		Enables the encoder timer channels for PWM inputs
 *	@param 		*enc: The structure for the encoder
 */
void enable_enc(Encoder_DriverTypeDef* enc);

/**
 *  @brief 		Disables the encoder timer channels for PWM outputs
 *	@param 		*enc: The structure for the encoder
 */
void disable_enc(Encoder_DriverTypeDef* enc);

/**
 *  @brief 		Sets the zero for positions
 *	@param 		*enc: The structure for the encoder
 */
void set_zero(Encoder_DriverTypeDef* enc);

/**
 *  @brief 		Reads the current count of the encoder timer channel
 *	@param 		*enc: The structure for the encoder
 *	@return		The current count position
 */
int32_t read_count(Encoder_DriverTypeDef* enc);

/**
 *  @brief 		Reads the current position of the motor encoder
 *	@param 		*enc: The structure for the encoder
 *	@return		The current position
 */
int32_t read_position(Encoder_DriverTypeDef* enc);

#endif /* INC_ENCODER_DRIVER_H_ */
