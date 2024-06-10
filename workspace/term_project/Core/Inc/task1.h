/*!
 *  @file task1.h
 *  @brief Sets up the task1 structure.
 *
 *  Created on: Jun 5, 2024
 */

#ifndef INC_TASK1_H_
#define INC_TASK1_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "motor_driver.h"
#include "servo_driver.h"
#include "radio_reciever_driver.h"
#include "photoresistor_driver.h"
#include "encoder_driver.h"
#include "bno055.h"
#include "bno_config.h"
#include "controller.h"
#include "intertask_vars.h"
#include "vector.h"

/*!
 *  @struct 	TASK1
 *	@typedef 	TASK1
 *  @brief 		A structure to contain the variables of TASK1 typedefs
 *	@param 		state: The task's current state
 *	@param 		*mot: The initialized motor driver structure to operate panning motion
 *	@param 		*servo: The initialized servo driver structure to operate pitching motion
 *	@param 		*rad: The initialized radio receiver driver structure to receive radio outputs
 *	@param		*photo: The initialized photoresistor driver structure to read brightness values
 *	@param 		*enc: The initialized encoder driver structure to read motor position
 *	@param 		*gyro: The initialized IMU gyroscope structure to read the mirror's normal vector angles
 */
struct{
	uint8_t state;
	Motor_DriverTypeDef* mot;
	Servo_DriverTypeDef* servo;
	RadioReciever_DriverTypeDef* rad;
	Photoresistor_DriverTypeDef* photo;
	Encoder_DriverTypeDef* enc;
	bno055_t* gyro;
} typedef TASK1;

/*!
 *  @brief 		Runs the designated state for task 1
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void main_task1(TASK1* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state0_task1: Init
 *  @brief 		Initializes the radio receiver to read values sent by the radio controller trigger
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state0_task1(TASK1* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state1_task1: Off
 *  @brief 		Checks if the radio controller trigger is more than halfway down and sets the radio trigger flag if it is
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state1_task1(TASK1* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state1_task1: On
 *  @brief 		Checks if the radio controller trigger is less than halfway down and resets the radio trigger flag if it is
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state2_task1(TASK1* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			get_pulse_percent
 *  @brief 		Calculates the percent that the radio controller trigger is pressed down
 *	@param 		*rad: The radio receiver driver
 *	@return 	A trigger down percent
 */
int32_t get_pulse_percent(RadioReciever_DriverTypeDef* rad);

#endif /* INC_TASK1_H_ */