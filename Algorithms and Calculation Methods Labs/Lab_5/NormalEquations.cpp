/******************************************************************************************************
*file:"NormalEquations.cpp"
*synopsis:functions realisations for solving normal equations & calculating least squares approximation
*author:Neshta R.
*written:12/12/2016
*last modified:01/01/2017
******************************************************************************************************/


#include<cstdio>

#include "Common.h"

void LeastSquaresApproximation(double *LeastSquaresDeviation){

	int DegreeOfPolynomial = 10;
	double *Coefficients = NULL;

	*LeastSquaresDeviation = 1;
	while (*LeastSquaresDeviation >= 0.01){

		if (Coefficients){

			delete[] Coefficients;
			Coefficients = NULL;

		}


		Coefficients = GetNormalEquationsRoots(DegreeOfPolynomial);

		*LeastSquaresDeviation = sqrt(GetProperIntegral(DegreeOfPolynomial, false, Coefficients) / (B - A));

		++DegreeOfPolynomial;

	}


	printf("Degree of polynomial is %d\n", --DegreeOfPolynomial);
	printf("\tX\t\t\tP(x) \n");

	for (double i = A; i <= B; i += 0.05){

		printf("%16.14f	%16.14f\n", i, P(GetValueOfT(i), DegreeOfPolynomial, Coefficients));

	}

}


double* GetNormalEquationsRoots(int const MaximumDegreeOfPolynomial){

	double *Roots = new(double[MaximumDegreeOfPolynomial + 1]);

	for (int i = 0; i <= MaximumDegreeOfPolynomial; ++i){

		Roots[i] = GetProperIntegral(i, false) / GetProperIntegral(i, true);

	}

	return Roots;

}

