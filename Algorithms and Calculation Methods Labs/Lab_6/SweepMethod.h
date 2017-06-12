/************************************************************************
*file:"SweepMethod.h"
*synopsis:functions declarations for solving system of tridiagonal matrix
*author:Neshta R.
*written:01/01/2017
*last modified:03/01/2017
************************************************************************/


#ifndef _SWEEPMETHOD_H
#define _SWEEPMETHOD_H


void GetCoefficients(double **ACoefficients, double **BCoefficients, double **CCoefficients, double **DCoefficients, const double *Arguments);

double Function(const double X);


#endif
