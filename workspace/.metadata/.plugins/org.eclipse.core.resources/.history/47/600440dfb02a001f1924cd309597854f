/*
 * photoresistor_driver.c
 *
 *  Created on: Jun 2, 2024
 *      Author: cadre
 */

#include "photoresistor_driver.h"

void ADC_Select_CH1(Photoresistor_DriverTypeDef* photo){
     ADC_ChannelConfTypeDef sConfig = {0};
     sConfig.Channel = ADC_CHANNEL_4;
     sConfig.Rank = 1;
     sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
     if (HAL_ADC_ConfigChannel((photo->adc_handle), &sConfig) != HAL_OK){
    	 Error_Handler();
     }
}

void ADC_Select_CH2 (Photoresistor_DriverTypeDef* photo){
     ADC_ChannelConfTypeDef sConfig = {0};
     sConfig.Channel = ADC_CHANNEL_5;
     sConfig.Rank = 1;
     sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
     if (HAL_ADC_ConfigChannel((photo->adc_handle), &sConfig) != HAL_OK){
    	 Error_Handler();
     }
}

void ADC_Select_CH3 (Photoresistor_DriverTypeDef* photo){
     ADC_ChannelConfTypeDef sConfig = {0};
     sConfig.Channel = ADC_CHANNEL_6;
     sConfig.Rank = 1;
     sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
     if (HAL_ADC_ConfigChannel((photo->adc_handle), &sConfig) != HAL_OK){
    	 Error_Handler();
     }
}

void ADC_Select_CH4 (Photoresistor_DriverTypeDef* photo){
     ADC_ChannelConfTypeDef sConfig = {0};
     sConfig.Channel = ADC_CHANNEL_7;
     sConfig.Rank = 1;
     sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
     if (HAL_ADC_ConfigChannel((photo->adc_handle), &sConfig) != HAL_OK){
    	 Error_Handler();
     }
}

uint32_t get_photo_value(Photoresistor_DriverTypeDef* photo, uint8_t num)
{
	if (num == 1){
		 ADC_Select_CH1(photo);
	}
	if (num == 2){
		 ADC_Select_CH2(photo);
	}
	if (num == 3){
		 ADC_Select_CH3(photo);
	}
	if (num == 4){
		 ADC_Select_CH4(photo);
	}
	  HAL_ADC_Start(photo->adc_handle);
	  HAL_ADC_PollForConversion(photo->adc_handle, 1000);
	  uint32_t photo_result = HAL_ADC_GetValue(photo->adc_handle);
	  photo->photo_results[(num-1)] = photo_result;
	  HAL_ADC_Stop(photo->adc_handle);
	  return photo_result;
}

uint32_t get_photo_diff(Photoresistor_DriverTypeDef* photo, uint8_t num1, uint8_t num2)
{
	uint32_t photo_result1 = get_photo_value(photo,num1);
	uint32_t photo_result2 = get_photo_value(photo,num2);
	return (photo_result1-photo_result2);
}
