/**
 *  @file vector.h
 *  @brief Sets up the vector structure.
 *
 *  Created on: Jun 5, 2024
 *  @author Christopher Ng
 */

#ifndef INC_VECTOR_H_
#define INC_VECTOR_H_

#include <stdio.h>
#include <stdint.h>

/**
 *  @struct 	Vector
 *	@typedef 	VectorTypeDef
 *  @brief 		A structure to contain the variables of a vector typedefs
 *	@param 		x: The vector's x component
 *	@param 		y: The vector's y component
 *	@param 		z: The vector's z component
 */
struct{
    float x;
    float y;
    float z;
} typedef VectorTypeDef;

/**
 *  @brief 		Returns the magnitude of the vector
 *	@param 		*vect: The vector
 *	@return		The magnitude of the vector
 */
float get_mag(VectorTypeDef* vect);

#endif /* INC_VECTOR_H_ */
