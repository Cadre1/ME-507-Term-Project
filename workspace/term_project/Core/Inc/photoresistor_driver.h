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
	uint32_t adc_channel1;
	uint32_t adc_channel2;
	uint32_t adc_channel3;
	uint32_t adc_channel4;
	uint32_t* photo_results;
} typedef Photoresistor_DriverTypeDef;

void ADC_Select_CH1 (Photoresistor_DriverTypeDef* photo);
void ADC_Select_CH2 (Photoresistor_DriverTypeDef* photo);
void ADC_Select_CH3 (Photoresistor_DriverTypeDef* photo);
void ADC_Select_CH4 (Photoresistor_DriverTypeDef* photo);
uint32_t get_photo_value(Photoresistor_DriverTypeDef* photo, uint8_t num);
uint32_t get_photo_diff(Photoresistor_DriverTypeDef* photo, uint8_t num1, uint8_t num2);

#endif /* INC_PHOTORESISTOR_DRIVER_H_ */
