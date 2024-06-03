// vector.h

#ifndef INC_VECTOR_H_
#define INC_VECTOR_H_

#include <stdio.h>
#include <stdint.h>

// Vector object data structure
struct{
    float x;
    float y;
    float z;
} typedef VectorTypeDef;

float get_mag(VectorTypeDef* vect);

#endif /* INC_VECTOR_H_ */
