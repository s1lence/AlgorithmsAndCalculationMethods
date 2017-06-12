/**********************************************************
*file:"SetOfChebyshevPolynomials.h"
*synopsis:functions declarations for generating polynomials
*author:Neshta R.
*written:12/12/2016
*last modified:01/01/2017
**********************************************************/


#ifndef _SETOFCHEBYSHEVPOLYNOMIALS_H
#define _SETOFCHEBYSHEVPOLYNOMIALS_H


double GetFiFunction(double const X, int const N);

double F(double const X);

double P(double const X, int const DegreeOfPolynomial, double *Coefficients);

double GetPolynomT(double const t, int const N);


#endif
