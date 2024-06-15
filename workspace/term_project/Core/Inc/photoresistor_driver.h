/**
 * @file photoresistor_driver.h
 * @brief Sets up the photoresistor driver structure
 *
 *  Created on: Jun 2, 2024
 *  @author Christopher Ng
 */

#ifndef INC_PHOTORESISTOR_DRIVER_H_
#define INC_PHOTORESISTOR_DRIVER_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

/**
 *  @brief 		A structure to contain the variables of the photoresistor driver typedefs
 *	@param 		*adc_handle: The ADC handle
 *	@param 		adc_channel1: The ADC channel 1 for photoresistor 1
 *	@param 		adc_channel2: The ADC channel 2 for photoresistor 2
 *	@param 		adc_channel3: The ADC channel 3 for photoresistor 3
 *	@param 		adc_channel4: The ADC channel 4 for photoresistor 4
 *	@param 		*photo_results: A list of the four photoresistor values
 */
struct{
	ADC_HandleTypeDef* adc_handle;
	uint32_t adc_channel1;
	uint32_t adc_channel2;
	uint32_t adc_channel3;
	uint32_t adc_channel4;
	uint32_t* photo_results;
} typedef Photoresistor_DriverTypeDef;

/**
 *  @brief 		Changes the ADC settings to read photoresistor 1
 *	@param 		*photo: The structure for the photoresistor driver
 */
void ADC_Select_CH1 (Photoresistor_DriverTypeDef* photo);

/**
 *  @brief 		Changes the ADC settings to read photoresistor 2
 *	@param 		*photo: The structure for the photoresistor driver
 */
void ADC_Select_CH2 (Photoresistor_DriverTypeDef* photo);

/**
 *  @brief 		Changes the ADC settings to read photoresistor 3
 *	@param 		*photo: The structure for the photoresistor driver
 */
void ADC_Select_CH3 (Photoresistor_DriverTypeDef* photo);

/**
 *  @brief 		Changes the ADC settings to read photoresistor 4
 *	@param 		*photo: The structure for the photoresistor driver
 */
void ADC_Select_CH4 (Photoresistor_DriverTypeDef* photo);

/**
 *  @brief 		Returns one of the photoresistor values (ranging from 0 to 4095 for 0 to 3v3)
 *	@param 		*photo: The structure for the photoresistor driver
 *	@param 		num: The photoresistor number to read
 *	@return		The input photoresistor value
 */
uint32_t get_photo_value(Photoresistor_DriverTypeDef* photo, uint8_t num);

/**
 *  @brief 		Returns the difference between two of the photoresistor values
 *	@param 		*photo: The structure for the photoresistor driver
 *	@param 		num1: The 1st photoresistor number to read
 *	@param 		num2: The 2nd photoresistor number to read and compare to the first
 *	@return		The difference between two photoresistor values
 */
uint32_t get_photo_diff(Photoresistor_DriverTypeDef* photo, uint8_t num1, uint8_t num2);

#endif /* INC_PHOTORESISTOR_DRIVER_H_ */
