/**
 * @file intertask_vars.h
 * @brief Sets up the intertask variable structure
 *
 *  Created on: Jun 9, 2024
 *  @author Christopher Ng
 */

#ifndef INC_INTERTASK_VARS_H_
#define INC_INTERTASK_VARS_H_

#include <stdio.h>
#include <stdint.h>

/**
 *  @brief 		A structure to contain the intertask variables used by the tasks
 *	@param 		rc_trigger_flag: A flag set by task 1 to read the radio controller receiver value
 *	@param		*rad_edge_flag: A flag set by the radio receiver HAL_TIM_IC_CaptureCallback
 *	@param 		*htim_cb: The timer object from the HAL_TIM_IC_CaptureCallback
 */
struct{
	uint8_t rc_trigger_flag;
	uint8_t* rad_edge_flag;
	TIM_HandleTypeDef* htim_cb;
} typedef INTERTASK_VARS;


#endif /* INC_INTERTASK_VARS_H_ */
