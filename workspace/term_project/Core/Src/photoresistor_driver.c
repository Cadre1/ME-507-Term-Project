/*
 * photoresistor_driver.c
 *
 *  Created on: Jun 2, 2024
 *      Author: cadre
 */

#include "photoresistor_driver.h"

void start_get_adc_values(Photoresistor_DriverTypeDef* photo)
{
	HAL_ADC_Start_DMA(photo->adc_handle, (uint32_t*)(photo->adc_results),4); // EDIT: make sure the buffer works as an address input
}

uint32_t* get_adc_values(Photoresistor_DriverTypeDef* photo)
{
	return photo->adc_results;
}
