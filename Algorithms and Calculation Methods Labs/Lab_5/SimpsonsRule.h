/*********************************************************
*file:"SimpsonsRule.h"
*synopsis:functions declarations for calculating integrals
*author:Neshta R.
*written:12/12/2016
*last modified:01/01/2017
*********************************************************/


#ifndef _SIMPSONSRULE_H
#define _SIMPSONSRULE_H


double GetValueOfT(double const X);

double GetFunctionF(double const x, int);

double GetFunctionG(double const t, int);

double CalculatingLeastSquaresApproximation(double const Arg, int const DegreeOfPolynomial, double* Coefficients);

double NormalEquationsMultiplying(double const Arg,	int const DegreeOfPolynomial,	double* Coefficients = NULL);

double NormalEquationsCalculatingLastRow(	double const Arg,	int const DegreeOfPolynomial,	double* Coefficients);

double SimpsonRule(
	int const DegreeOfPolynomial,
	int const n,
	double(*Function)(double, int, double*),
	double* Coefficients = NULL);

double RefinedCalculation(
	int const DegreeOfPolynomial,
	double const eps,
	double(*Function)(double, int, double*),
	double* Coefficients = NULL);

double GetProperIntegral(
	int const DegreeOfPolynomial,
	bool IsCalculatingNormalEquations,
	double* Coefficients = NULL);



#endif
