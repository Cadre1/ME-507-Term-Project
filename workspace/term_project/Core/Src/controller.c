/*
 * controller.c
 *
 *  Created on: May 30, 2024
 *      Author: cadre
 */

#include "controller.h"

void enable_controller(ControllerTypeDef* con, float kp, float kd, float ki)
{
	con->kp = kp;
	con->kd = kd;
	con->ki = ki;
	con->des_val = 0;
}

void disable_controller(ControllerTypeDef* con)
{
	con->kp = 0;
	con->kd = 0;
	con->ki = 0;
	con->des_val = 0;
}

void set_gains(ControllerTypeDef* con, float kp, float kd, float ki)
{
	con->kp = kp;
	con->kd = kd;
	con->ki = ki;
}

void set_target(ControllerTypeDef* con, float des_val)
{
	con->des_val = des_val;
}

float get_output(ControllerTypeDef* con, float curr_val)
{
	float prop_err, der_err;
	uint32_t diff_time;
	uint32_t curr_time = HAL_GetTick();
	if (con->first_time){
		prop_err = (con->des_val)-curr_val;
		der_err = 0;
		con->int_err = 0;
		con->first_time = 0;
	}
	else{
		diff_time = curr_time-(con->prev_time);
		prop_err = (con->des_val)-curr_val;
		der_err = (prop_err-(con->prev_err))/diff_time;
		con->int_err += prop_err*diff_time;
	}
	float p_output = (con->kp)*prop_err;
	float d_output = (con->kd)*der_err;
	float i_output = (con->ki)*(con->int_err);
	float output = p_output+d_output+i_output;

	con->prev_err = prop_err;
	con->prev_time = curr_time;
	return output;
}