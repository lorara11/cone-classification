/*
 * math-pi-value.c
 * Author: Loredana Sandu
 * Description: Tests the functions found in vector-operations.h
 */

#include <stdio.h>
#include "../headers/vector-operations.h"

int main()
{
	double * u = malloc(LEN * sizeof(double));
	if (u == NULL){
		printf("\nError: couldn't allocate memory for first vector.");
	}
	double * v = malloc(LEN * sizeof(double));
	if (v == NULL){
		printf("\nError: couldn't allocate memory for second vector.");
	}

	printf("\nEnter values for the first vector u:\n");
	for (int i=0; i<LEN; i++){
		printf("u[%d]? ", i+1);
		scanf("%lf", &u[i]);
	}
	printf("\nVector entered:\n");
	for (int i=0; i<LEN; i++){
		printf("u[%d] = %.2lf\n", i+1, u[i]);
	}

	printf("\nEnter values for the second vector v:\n");
	for (int i=0; i<LEN; i++){
		printf("v[%d]? ", i+1);
		scanf("%lf", &v[i]);
	}
	printf("\nVector entered:\n");
	for (int i=0; i<LEN; i++){
		printf("v[%d] = %.2f\n", i+1, v[i]);
	}

	printf("\nThe dot product u · v is %.2f", dotproduct(u,v));
	printf("\nThe norm of u is %.2f", norm(u));
	printf("\nThe norm of v is %.2f", norm(v));
	
	if (orthogonal(u,v) == 1){
		printf("\nu and v are orthogonal.");
	} else {
		printf("\nu and v aren't orthogonal");
	}

	double * crossprod = malloc(LEN * sizeof(double));
	if (crossprod == NULL){
		printf("\nError: couldn't allocate memory for the cross product.");
	}

	crossproduct(crossprod, u, v);
	printf("\nThe cross product u x v is (%.2f, %.2f, %.2f)", crossprod[0], crossprod[1], crossprod[2]);

	printf("\nThe determinant of the matrix formed by the cross product vector, u and v is %.2f", det(crossprod, u, v));
	printf("\nThe angle between u and v is %.2f", angle(crossprod, u, v));
	
	double * proj = malloc(LEN * sizeof(double));
	if (proj == NULL){
		printf("\nError: couldn't allocate memory for the projection.");
	}

	projection(proj, u, v);
	printf("\nThe orthogonal projection of v onto u is (%.2f, %.2f, %.2f)\n", proj[0], proj[1], proj[2]);

	return 0;
}
