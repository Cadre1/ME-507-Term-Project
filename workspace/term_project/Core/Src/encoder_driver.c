/*
 * encoder.c
 *
 *  Created on: Jun 3, 2024
 *      Author: cadre
 */

#include <encoder_driver.h>

void enable_enc(Encoder_DriverTypeDef* enc)
{
	HAL_TIM_Encoder_Start(enc->tim_handle, TIM_CHANNEL_ALL);
}

void disable_enc(Encoder_DriverTypeDef* enc)
{
	HAL_TIM_Encoder_Stop(enc->tim_handle, TIM_CHANNEL_ALL);
}

void set_zero(Encoder_DriverTypeDef* enc)
{
	enc->tot_count = 0;
	enc->pos = 0;
}

int32_t read_count(Encoder_DriverTypeDef* enc)
{
	enc->curr_count = __HAL_TIM_GET_COUNTER(enc->tim_handle);
	int32_t dcount = (enc->curr_count)-(enc->prev_count);
	if(dcount <= -((enc->AR)+1)/2){
		enc->tot_count += ((enc->AR)+1)+dcount;
		enc->pos += (((enc->AR)+1)+dcount)/4;
	}
	else if(dcount >= ((enc->AR)+1)/2){
		enc->tot_count += dcount-((enc->AR)+1);
		enc->pos += (dcount-((enc->AR)+1))/4;
	}
	else{
		enc->tot_count += dcount;
		enc->pos += dcount/4;
	}
	enc->prev_count = enc->curr_count;
	return enc->tot_count;
}

int32_t read_position(Encoder_DriverTypeDef* enc)
{
	return enc->pos;
}
