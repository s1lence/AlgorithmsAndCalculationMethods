/***
*file:"TEST.cpp"
*synopsis:testing all functions for numerical integration
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/


#include <cstdio>


#include "Common.h"

#include "CompositeTrapeziumRule.h"
#include "RefinedCalculation.h"

#define NUMBER_OF_CALCULATIONS 5
#define STEP 3
#define N STEP*NUMBER_OF_CALCULATIONS


double GetCorrectIntergal(){

	return ANTIDERIVATIVE(B) - (ANTIDERIVATIVE(A));

}

void Second(double const D, double const Answer, double* Arr, int i){

	double Step, Delta;
	Delta = fabs(Answer - Refined_Calculation(D, &Step));

	Arr[i] = D;

	Arr[i + 1] = Step;

	Arr[i + 2] = Delta;

}

void First(double* Arr){

	int n;
	double Step, CorrectValue, E = 0.01, Delta;

	printf("|     Error   |     Step    |  Accurate value  |  Calculation error  |\n");

	CorrectValue = GetCorrectIntergal();

	for (int i = 0; i < N; i += 3){

		n = static_cast<int>((B - A) / sqrt(E));

		Delta = fabs(CorrectValue - Trapezium(n, &Step));

		printf("|% .*E |% .*E |% .*E |% .*E |\n", 4, E, 4, Step, 9, CorrectValue, 12, Delta);

		Second(Delta, CorrectValue, Arr, i);

		E *= 0.01;

	}

}

int main(){

	double Arr[N * 3];
	First(Arr);

	printf("\n| Trapezium method error  |     Step    |  Calculation error  |\n");

	for (int i = 0; i < N; i += 3)

		printf("|% .*E |% .*E |% .*E |\n", 16, Arr[i], 4, Arr[i + 1], 12, Arr[i + 2]);


	return 0;

}
