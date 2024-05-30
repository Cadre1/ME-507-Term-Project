/*
 * radio_driver.c
 *
 *  Created on: May 17, 2024
 *      Author: cadre
 */

#include <radio_reciever_driver.h>

void enable_rad(RadioReciever_DriverTypeDef* rad)
{
	// Enabling the rising/falling edge interrupt
	HAL_TIM_IC_Start_IT(rad->tim_handle,rad->tim_channel1);
	HAL_TIM_IC_Start_IT(rad->tim_handle,rad->tim_channel2);
}

void disable_rad(RadioReciever_DriverTypeDef* rad)
{
	// Disabling the rising/falling edge interrupt
	HAL_TIM_IC_Stop_IT(rad->tim_handle,rad->tim_channel1);
	HAL_TIM_IC_Stop_IT(rad->tim_handle,rad->tim_channel2);
}

uint16_t get_pulse(RadioReciever_DriverTypeDef* rad)
{
	if (rad->pulse_recieve_flag){
		// Calculate pulse width (in us) w/ overflow
		if (rad->IC_Fall < rad->IC_Rise){
			rad->IC_Diff = (0xffff - rad->IC_Rise) + rad->IC_Fall;
		}
		else{
			rad->IC_Diff = rad->IC_Fall - rad->IC_Rise;
		}
		// Manage invalid values
		if (rad->IC_Diff < (2000*(1+rad->tol)) || rad->IC_Diff > (1000*(1-rad->tol))){
			rad->pulse_width = rad->IC_Diff;
		}
		rad->pulse_recieve_flag = 0;
	}
	return rad->pulse_width;
}

void read_pulse(RadioReciever_DriverTypeDef* rad, TIM_HandleTypeDef* htim)
{
	if (htim->Instance == rad->tim_handle->Instance && !(rad->pulse_recieve_flag)){
		if (rad->rise_flag){
			rad->IC_Rise = 0;
			rad->IC_Fall = HAL_TIM_ReadCapturedValue(htim, rad->tim_channel2);
			rad->pulse_recieve_flag = 1;
			rad->rise_flag = 0;
		}
		else{
			rad->rise_flag = 1;
		}
	}
}
