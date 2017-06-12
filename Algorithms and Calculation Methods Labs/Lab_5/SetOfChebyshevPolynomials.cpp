/**********************************************************
*file:"SetOfChebyshevPolynomials.cpp"
*synopsis:functions realisations for generating polynomials
*author:Neshta R.
*written:12/12/2016
*last modified:01/01/2017
**********************************************************/

#include "Common.h"

double GetFiFunction(const double Argument, const int DegreeOf){

	if (DegreeOf == 0)
		return 1;

	if (DegreeOf == 1)
		return Argument;


	double Fi_Old = 1, Fi_Current = Argument, Fi_New = 0;


	for (int i = 1; i <= DegreeOf - 1; ++i) {

		Fi_New = ((2 * i + 1) / (double)(i + 1)) * Argument * Fi_Current - (i / (double)(i + 1)) * Fi_Old;
		
		Fi_Old = Fi_Current;

		Fi_Current = Fi_New;

	}


	return Fi_New;

}

double F(double const X){

	return FUNCTION(X);

}

double P(double const X,int const DegreeOfPolynomial,double *Coefficients){

	double P = 0;

	for (int i = 0; i <= DegreeOfPolynomial; ++i)

		P += GetFiFunction(X, i)*Coefficients[i];


	return P;

}

double GetPolynomT(double const t, int const N){

	return GetFiFunction(t, N);

}
