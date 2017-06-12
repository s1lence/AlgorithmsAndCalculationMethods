/***
*file:"RefinedCalculation.cpp"
*synopsis:definitions functions for numerical integration using refined calculation method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/


#include "CompositeTrapeziumRule.h"

#include "Common.h"

double Refined_Calculation(double const eps, double *h){

	int n;
	double In, I2n;

	n = static_cast<int>((B - A) / sqrt(eps));
	In = Trapezium(n, h);

	n *= 2;
	I2n = Trapezium(n, h);


	while (fabs(In - I2n) > 3 * eps){

		In = I2n;

		n *= 2;

		I2n = Trapezium(n, h);

	}


	return I2n;

}

