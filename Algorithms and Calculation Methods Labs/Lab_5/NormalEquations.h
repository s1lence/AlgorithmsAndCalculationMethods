/*******************************************************************************************************
*file:"NormalEquations.h"
*synopsis:functions declarations for solving normal equations & calculating least squares approximations
*author:Neshta R.
*written:12/12/2016
*last modified:01/01/2017
*******************************************************************************************************/


#ifndef _NORMALEQUATIONS_H
#define _NORMALEQUATIONS_H


void LeastSquaresApproximation(double* LeastSquaresDeviation);

double* GetNormalEquationsRoots(int const MaximumDegreeOfPolynomial);


#endif