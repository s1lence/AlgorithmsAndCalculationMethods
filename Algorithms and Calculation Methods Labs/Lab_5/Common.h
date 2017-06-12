/*****************************************************************
*file:"Common.h"
*synopsis:declarations for calculating least squares approximation
*author: Neshta R.
*written:12/12/2016
*last modified:01/01/2017
*****************************************************************/


#ifndef _COMMON_H
#define _COMMON_H


#include <cmath>
#include <cstdlib>

#include "NormalEquations.h"
#include "SetOfChebyshevPolynomials.h"
#include "SimpsonsRule.h"


#define ACCURACY 0.01

#define A 0.0

#define B 5.7

#define FUNCTION(X) 0.5*X*X*X*sin(X*3)



#endif
