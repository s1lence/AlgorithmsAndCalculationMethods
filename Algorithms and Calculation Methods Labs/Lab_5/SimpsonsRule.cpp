/*********************************************************
*file:"SimpsonsRule.cpp"
*synopsis:functions realisations for calculating integrals
*author:Neshta R.
*written:12/12/2016
*last modified:01/01/2017
*********************************************************/

#include "Common.h"

#define UPPER 1.0
#define LOWER -1.0

double GetValueOfT(double const X){

	return (X * 2 - (B + A)) / (B - A);

}

double GetProperIntegral(
	int const DegreeOfPolynomial,
	bool IsCalculatingNormalEquations,
	double* Coefficients)
{

	if (IsCalculatingNormalEquations)
		return RefinedCalculation(DegreeOfPolynomial, 1e-7, NormalEquationsMultiplying);


	if (Coefficients)
		return RefinedCalculation(DegreeOfPolynomial, 0.001, CalculatingLeastSquaresApproximation, Coefficients);
	
	
	return RefinedCalculation(DegreeOfPolynomial, 1e-7, NormalEquationsCalculatingLastRow);

}

double RefinedCalculation(int const DegreeOfPolynomial,
	double const eps,
	double(*Function)(double, int, double*),
	double* Coefficients)
{

	int n;
	double In, I2n;

	n = static_cast<int>((UPPER - LOWER) / sqrt(eps));
	In = SimpsonRule(DegreeOfPolynomial, n, Function, Coefficients);

	n *= 2;
	I2n = SimpsonRule(DegreeOfPolynomial, n, Function, Coefficients);


	while (fabs(In - I2n) > 3 * eps){

		In = I2n;

		n *= 2;

		I2n = SimpsonRule(DegreeOfPolynomial, n, Function, Coefficients);

	}


	return I2n;

}

double NormalEquationsMultiplying(double const Arg, int const DegreeOfPolynomial, double* Coefficients){
	
	return GetPolynomT(Arg, DegreeOfPolynomial)*GetPolynomT(Arg, DegreeOfPolynomial);

}

double NormalEquationsCalculatingLastRow(double const Arg, int const DegreeOfPolynomial, double* Coefficients){
	
	return GetFunctionG(Arg, DegreeOfPolynomial)*GetPolynomT(Arg, DegreeOfPolynomial);

}

double CalculatingLeastSquaresApproximation(double const Arg, int const DegreeOfPolynomial, double* Coefficients){
	
	double G, Px;
	G = GetFunctionG(Arg, DegreeOfPolynomial);

	Px = P(Arg, DegreeOfPolynomial, Coefficients);

	return (G - Px)*(G - Px);

}

double SimpsonRule(const int DegreeOfPolynomial,
	const int n,
	double(*Function)(double, int, double*),
	double* Coefficients)
{
	
	double Integral = 0, arg = LOWER, h;
	int j = 0;

	h = (UPPER - LOWER) / n;
	for (int i = 0; i <= n; ++i){

		if (i == 0 || i == n)
			Integral += Function(arg, DegreeOfPolynomial, Coefficients);

		else if (i % 2 == 0)
			Integral += 2 * Function(arg, DegreeOfPolynomial, Coefficients);

		else
			Integral += 4 * Function(arg, DegreeOfPolynomial, Coefficients);


		arg += h;

	}


	Integral *= h / 3;

	return Integral;

}

double GetFunctionG(double const t, int useless){

	return FUNCTION((0.5*(B + A) + 0.5*t*(B - A)));

}
