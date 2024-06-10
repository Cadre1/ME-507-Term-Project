/*!
 *  @file task1.c
 *  @brief Runs the states associated with task 1 as described in its FSM.
 *
 *  Created on: Jun 5, 2024
 */

#include <task1.h>

void main_task1(TASK1* task, INTERTASK_VARS* intertask_vars)
{
	if(task->state == 0){
		state0_task1(task, intertask_vars);
	}
	else if(task->state == 1){
		state1_task1(task, intertask_vars);
	}
	else if(task->state == 2){
		state2_task1(task, intertask_vars);
	}
}

void state0_task1(TASK1* task, INTERTASK_VARS* intertask_vars)
{
	// Initializing the radio receiver
	enable_rad(task->rad);
	task->state = 1;
}

void state1_task1(TASK1* task, INTERTASK_VARS* intertask_vars)
{
	// Reading the value of the Radio Receiver after each period
	if (*(intertask_vars->rad_edge_flag)){
		read_pulse(task->rad, intertask_vars->htim_cb); // EDIT: This should work bc the address is stored in htim_cb within the interstae_vars struct, not the value. So when the value is changed in the interrupt in main, it should read the value at the register
		*(intertask_vars->rad_edge_flag) = 0;
	}
	// Checking if the value is greater than 50% of its max (1750)
	if (get_pulse_percent(task->rad) > 50){
		intertask_vars->rc_trigger_flag = 1;
		task->state = 2;
	}
}

void state2_task1(TASK1* task, INTERTASK_VARS* intertask_vars)
{
	// Reading the value of the Radio Receiver after each period
	if (*(intertask_vars->rad_edge_flag)){
		read_pulse(task->rad, intertask_vars->htim_cb); // EDIT: This should work bc the address is stored in htim_cb within the interstae_vars struct, not the value. So when the value is changed in the interrupt in main, it should read the value at the register
		*(intertask_vars->rad_edge_flag) = 0;
	}
	// Checking if the value is less than 50% of its max (1750)
	if (get_pulse_percent(task->rad) < 50){
		intertask_vars->rc_trigger_flag = 0;
		task->state = 1;
	}
}

int32_t get_pulse_percent(RadioReciever_DriverTypeDef* rad)
{
	  // Calculates the radio pulse as a percent
	  uint32_t pulse_rad = get_pulse(rad);
	  if (abs(pulse_rad) < 10){
		  pulse_rad = 1509;
	  }
	  int32_t duty_percent = (int32_t)((pulse_rad-1509)*100)/513;
	  if (duty_percent > 100){
		  duty_percent = 100;
	  }
	  else if (duty_percent < -100){
		  duty_percent = -100;
	  }
	  return duty_percent;
}