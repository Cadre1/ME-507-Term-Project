/*
 * intertask_vars.h
 *
 *  Created on: Jun 9, 2024
 *      Author: cadre
 */

#ifndef INC_INTERTASK_VARS_H_
#define INC_INTERTASK_VARS_H_

#include <stdio.h>
#include <stdint.h>

// Insterstate Variable object data structure
struct{
	uint8_t rc_trigger_flag;
	uint8_t* rad_edge_flag;
	TIM_HandleTypeDef* htim_cb;
} typedef INTERTASK_VARS;


#endif /* INC_INTERTASK_VARS_H_ */
