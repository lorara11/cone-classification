/*
 * classification-functions.h
 * Author: Loredana Sandu
 * Description: Functions to classificate cones in the 2D plane and the 3D space.
 */


#ifndef HEADER_CLASSIFICATION_FUNCTIONS
#define HEADER_CLASSIFICATION_FUNCTIONS

#include <stdio.h>
#include <stddef.h>
#include "vector-operations.h"


#define PI 3.14159265358979     
// I've checked that the predefined value of pi is 3.1415926535897931 (17 significant digits), 
// so I define PI with a precision of 15 significant digits.


unsigned int classification2d(unsigned int n, double * v[n], double * u, unsigned int vgen[], unsigned int * len_vgen);

unsigned int projectcone(unsigned int n, double * proj[n], double * u, double * v[n]);
unsigned int classification3d(unsigned int n, double * v[n], unsigned int vgen[], unsigned int * len_vgen);


#endif // HEADER_CLASSIFICATION_FUNCTIONS