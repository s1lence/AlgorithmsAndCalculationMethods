/***
*file:"CompositeTrapeziumRule.cpp"
*synopsis:definitions functions for numerical integration using composite trapezium rule
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#include "Common.h"


double Function(double const X){

	return FUNCTION(X);

}

double Trapezium(int const n, double *h){

	double x, I = 0;
	int i = 0;

	*h = (B - A) / n;

	x = A;

	while (i <= n){

		if (i == 0 || i == n)
			I += 0.5*Function(x);

		else
			I += Function(x);

		x += *h;

		++i;

	}


	return I*(*h);

}
