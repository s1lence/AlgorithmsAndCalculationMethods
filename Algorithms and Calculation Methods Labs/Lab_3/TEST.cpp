/***
*file:"TEST.cpp"
*synopsis:testing functions for solving system of linear equations using both methods
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#include <cstdio>


#include "CompletePivoting.h"
#include "DirectIteration.h"

#include "Common.h"



int  main(){

	double *RootsFromPivoting = new double[LINES]();

	double RootsFromIteration[] = { 0, 0, 0, 0 };

	double MatrixForPivoting[] = MATRIX;

	double MatrixForIteration[] = TRANSFORMED;


	Pivoting(MatrixForPivoting, RootsFromPivoting, LINES, COLUMNS);


	printf("Complete pivoting roots:\n");

	for (int i = 0; i < LINES; ++i){

		printf("%f \n", RootsFromPivoting[i]);

	}


	printf("Direct iteration roots:\n");

	if (Iteration(MatrixForIteration, RootsFromIteration, 0.001))

	for (int i = 0; i < LINES; ++i){

		printf("%f \n", RootsFromIteration[i]);

	}

	delete[] RootsFromPivoting;

	return 0;
}
