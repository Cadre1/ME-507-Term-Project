/*
 * controller.h
 *
 *  Created on: May 30, 2024
 *      Author: cadre
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include <stdio.h>
#include <stdint.h>

// Vector object data structure
struct{
	float des_val;
	float kp;
	float kd;
	float ki;
	float int_err;
	float prev_err;
	uint32_t prev_time;
	uint8_t first_time;
} typedef ControllerTypeDef;

void enable_controller(ControllerTypeDef* con, float kp, float kd, float ki);
void disable_controller(ControllerTypeDef* con);
void set_gains(ControllerTypeDef* con, float kp, float kd, float ki);
void set_target(ControllerTypeDef* con, float des_val);
float get_output(ControllerTypeDef* con, float curr_val);

#endif /* INC_CONTROLLER_H_ */
