/*
 * encoder.h
 *
 *  Created on: Jun 3, 2024
 *      Author: cadre
 */

#ifndef INC_ENCODER_DRIVER_H_
#define INC_ENCODER_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

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

void enable_enc(Encoder_DriverTypeDef* enc);
void disable_enc(Encoder_DriverTypeDef* enc);
void set_zero(Encoder_DriverTypeDef* enc);
int32_t read_count(Encoder_DriverTypeDef* enc);
int32_t read_position(Encoder_DriverTypeDef* enc);

#endif /* INC_ENCODER_DRIVER_H_ */
