// vector.c

#include <math.h>
#include "vector.h"

float get_mag(VectorTypeDef* vect)
{
    float mag = sqrt(pow(vect->x,2)+pow(vect->y,2)+pow(vect->z,2));
    return mag;
}
