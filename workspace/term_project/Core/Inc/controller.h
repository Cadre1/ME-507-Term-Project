/**
 * @file controller.h
 * @brief Sets up the general use PID controller structure
 *
 *  Created on: May 30, 2024
 *  @author Christopher Ng
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include <stdio.h>
#include <stdint.h>

/**
 *  @brief 		A structure to contain the variables of controller typedefs
 *	@param 		des_val: The desired target value
 *	@param 		kp: Proportional gain
 *	@param 		kd: Derivative gain
 *	@param 		ki: Integral gain
 *	@param 		int_err: The accumulated integral error
 *	@param 		prev_err: The previous error
 *	@param		first_time: A flag used for the first time when returning an output value to ignore derivative and integral values at t=0
 */
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

/**
 *  @brief 		Resets the setup variables for a different closed-loop control system
 *	@param 		*con: The structure for the controller
 */
void reset_controller(ControllerTypeDef* con);

/**
 *  @brief 		Sets the controller gain after reseting the controller
 *	@param 		*con: The structure for the controller
 *	@param		kp: The desired proportional gain
 *	@param		kd: The desired derivative gain
 *	@param		ki: The desired integral gain
 */
void set_gains(ControllerTypeDef* con, float kp, float kd, float ki);

/**
 *  @brief 		Sets the controller target after reseting the controller
 *	@param 		*con: The structure for the controller
 *	@param		des_val: The target value
 */
void set_target(ControllerTypeDef* con, float des_val);

/**
 *  @brief 		Resets the setup variables for a different closed-loop control system
 *	@param 		*con: The structure for the controller
 *	@param		des_val: The current input value
 *	@return 	An output for the controller
 */
float get_output(ControllerTypeDef* con, float curr_val);

#endif /* INC_CONTROLLER_H_ */
