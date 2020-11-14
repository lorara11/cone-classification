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


double dotproduct(double * u, double * v)
{
	/* Returns the dot product of two input vectors */

    double result = 0;
    int i;

    for (i=0; i<LEN; i++) {
        result += u[i]*v[i];
    }

    return result;
}


double norm(double * u)
{
	/* Returns the norm of the input vector */

    return sqrt(dotproduct(u,u));
}


double det(double * u, double * v, double * w)
{
	/* Returns the determinant of the matrix formed by column vectors u,v,w in this order. */

    return u[0]*v[1]*w[2] + u[1]*v[2]*w[0] + u[2]*v[0]*w[1]
		   - w[0]*v[1]*u[2] - w[1]*v[2]*u[0] - w[2]*v[0]*u[1];
}


unsigned int orthogonal(double * u, double * v)
{
	/* Returns 1 if input vectos u, v are orthogonal, and 0 if they aren't. */

    if (fabs(dotproduct(u,v)) < EPSILON) {
        return 1;
    } else {
        return 0;
    }
}


double angle(double * p, double * u, double * v)
{
	/* Returns the signed angle (-pi < angle <= pi) between input vectors u, v;
	 * p is a vector orthogonal to u and v, used to determine the sign of the angle. */

    double cos = dotproduct(u,v) / (norm(u) * norm(v));

    /* I make sure that cos is in the interval [-1,1], preventing errors
    * due to rounding when cos is close to the endpoints of the interval. */
    if (cos < -1.0){
        cos = -1.0;
    } else if (cos > 1.0){
        cos = 1.0;
    }

    double alpha = acos(cos);

    /* I set the sign of the angle to equal the sign of the determinant of the
     * matrix formed by the column vectors p,u,v in this order
     * If the angle is pi (thus the determinant is zero), I set the angle to be
     * positive. This way, we'll always have -pi < angle <= pi */
    if ((det(p,u,v) > 0 || fabs(det(p,u,v)) < EPSILON) && (alpha < 0)){
        alpha = fabs(alpha);
    } else if ((det(p,u,v) < 0) && (alpha > 0)){
        alpha = -alpha;
    }

    return alpha;
}


void crossproduct(double * prod, double * u, double * v)
{
	/* Computes the cross product of two input vectors u, v;
	 * stores the result in the input array prod. */

    prod[0] = u[1]*v[2] - u[2]*v[1];
    prod[1] = u[2]*v[0] - u[0]*v[2];
    prod[2] = u[0]*v[1] - u[1]*v[0];
}


void projection(double * vector_proj, double * u, double * v)
{
	/* Computes the orthogonal projection of vector v onto vector u.
	 * Stores the result in the input array vector_proj. */

    int i;
    double scalar = dotproduct(u,v) / dotproduct(u,u);

    for (i=0; i<LEN; i++) {
        vector_proj[i] = v[i] - scalar * u[i];
    }
}


#endif // HEADERS_VECTOR_OPERATIONS
