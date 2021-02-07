/*
 * vector-operations.h
 * Author: Loredana Sandu
 * Description: Basic functions for vector operations in the vector space R^3
 */

#ifndef HEADER_VECTOR_OPERATIONS
#define HEADER_VECTOR_OPERATIONS

#include <math.h>
#include <stdlib.h>

#define EPSILON 0.0000001	// Tolerance of 10^(-8) used when checking equalities.
#define LEN 3      			// Length of vectors.


double dotproduct(double * u, double * v);
double norm(double * u);
double det(double * u, double * v, double * w);
unsigned int orthogonal(double * u, double * v);
double angle(double * p, double * u, double * v);
void crossproduct(double * prod, double * u, double * v);
void projection(double * vector_proj, double * u, double * v);


#endif // HEADERS_VECTOR_OPERATIONS
