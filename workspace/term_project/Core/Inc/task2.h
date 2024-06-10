/*!
 *  @file task2.h
 *  @brief Sets up the task2 structure.
 *
 *  Created on: Jun 9, 2024
 */

#ifndef INC_TASK2_H_
#define INC_TASK2_H_

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
 *  @struct 	TASK2
 *	@typedef 	TASK2
 *  @brief 		A structure to contain the variables of TASK2 typedefs
 *	@param 		state: The task's current state
 *	@param 		*mot: The initialized motor driver structure to operate panning motion
 *	@param 		*servo: The initialized servo driver structure to operate pitching motion
 *	@param 		*rad: The initialized radio receiver driver structure to receive radio outputs
 *	@param		*photo: The initialized photoresistor driver structure to read brightness values
 *	@param 		*enc: The initialized encoder driver structure to read motor position
 *	@param 		*gyro: The initialized IMU gyroscope structure to read the mirror's normal vector angles
 *
 *	@param		*con: A general use controller
 *	@param		init_controller: A flag used to initially set controller values
 *	@param		*euler: Gyroscope Euler angles (yaw, pitch, roll)
 *	@param		within_range: A flag used to check if the controlled output has entered within a tolerance of the desired output
 *	@param 		end_time: An end time to be within the range until
 *	@param		high_light: A record of the brightest spot during state 2
 *	@param		high_angle: A record of the angle associated with the brightest spot during state 2
 *	@param		reflect_angle: A vector of the angles for the normal vector of the mirror to reflect light to the target
 */
struct{
	uint8_t state;
	Motor_DriverTypeDef* mot;
	Servo_DriverTypeDef* servo;
	RadioReciever_DriverTypeDef* rad;
	Photoresistor_DriverTypeDef* photo;
	Encoder_DriverTypeDef* enc;
	bno055_t* gyro;
	ControllerTypeDef* con;
	uint8_t init_controller;
	bno055_euler_t* euler;
	uint8_t within_range;
	uint32_t end_time;
	uint32_t high_light;
	float high_angle;
	VectorTypeDef reflect_angle;
} typedef TASK2;

/*!
 *  @brief 		Runs the designated state for task 2
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void main_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state0_task2: Init Power
 *  @brief 		Initializes the IMU gyroscope I2C communication, photoresistor ADCs, motor PWM output, servo PWM output, and encoder channels
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state0_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state1_task2: Wait For Start
 *  @brief 		Waits until the radio receiver receives a valid output to start through the radio receiver flag
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state1_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state2_task2: Setup 1
 *  @brief 		Sets the servo so that the mirror is vertical and makes one full revolution to find and record the high photoresistor values and angles to start at
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state2_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state3_task2: Setup 2
 *  @brief 		Sets the initial motor position to one of the recorded high values through angle-motor control
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state3_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state4_task2: Pan To Bright Spot
 *  @brief 		Finds the brightest horizontal direction using photoresistor-motor control
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state4_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state5_task2: Pitch To Bright Spot
 *  @brief 		Finds the brightest vertical direction using photoresistor-servo control
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state5_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state6_task2: Collect Angle
 *  @brief 		Collects the bright spot angle using the gyroscope, then calculates the reflection angle that it needs to turn to
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state6_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state7_task2: Go To Reflection Angles
 *  @brief 		Pans to the reflection angle using gyroscope-motor control and sets the servo angle
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state7_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state8_task2: Stop
 *  @brief 		Stops the motor if the radio receiver receives an invalid output through the radio receiver flag
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state8_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			state9_task2: Return
 *  @brief 		Returns to the home position using gyroscope-motor control and servo angle setting if the radio receiver receives a valid output through the radio receiver flag to restart
 *	@param 		*task: The task's current state
 *	@param 		*intertask_vars: The intertask variables used by other tasks
 */
void state9_task2(TASK2* task, INTERTASK_VARS* intertask_vars);

/*!
 * 	@fn			get_reflect_angle
 *  @brief 		Calculates the angles required to reflect a light source at a given angle to a target given its and the heliostats position
 *	@param 		*light_source_angle: A vector containing the Euler angles of the light source
 *	@param 		*target_position: A vector containing the position of the target
 *	@param 		*heliostat_position: A vector containing the position of the heliostat mirror
 *	@return		A vector of the required angles of the normal vector of the mirror to reflect to the target
 */
VectorTypeDef get_reflect_angle(VectorTypeDef* light_source_angle, VectorTypeDef* target_position, VectorTypeDef* heliostat_position);


#endif /* INC_TASK2_H_ */