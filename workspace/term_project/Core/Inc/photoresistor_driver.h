/*
 * photoresistor_driver.h
 *
 *  Created on: Jun 2, 2024
 *      Author: cadre
 */

#ifndef INC_PHOTORESISTOR_DRIVER_H_
#define INC_PHOTORESISTOR_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

// Photoresistor_Driver object data structure
struct{
	ADC_HandleTypeDef* adc_handle;
	DMA_HandleTypeDef* dma_handle;
	uint32_t* adc_results;
} typedef Photoresistor_DriverTypeDef;

void start_get_adc_values(Photoresistor_DriverTypeDef* photo);
uint32_t* get_adc_values(Photoresistor_DriverTypeDef* photo);

#endif /* INC_PHOTORESISTOR_DRIVER_H_ */
