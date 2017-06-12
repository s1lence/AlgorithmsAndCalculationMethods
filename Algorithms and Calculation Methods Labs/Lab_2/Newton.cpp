/***
*file:"Newton.cpp"
*synopsis:definitions functions for calculation value of integral by Newton-Raphson method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/


#include <iostream>

#include "Common.h"


double get_m1_const(double const a, double const b){

	double tmp_a = abs(DERIVATIVE(a));
	double tmp_b = abs(DERIVATIVE(b));

	return tmp_a < tmp_b ? tmp_a : tmp_b;

}

double get_x0(double const a, double const b){

	if (FUNCTION(a)*SECOND_DERIVATIVE(a)>0)
		return a;

	return b;

}

double NewtonRaphson(double const eps, double const a, double const b, double *Accuracy, int *iterations){
	
	double m1 = get_m1_const(a, b);
	double x0 = get_x0(a, b);

	int i;
	if (0 == m1 || 0 >= SECOND_DERIVATIVE(x0)){

		std::cerr << "You have done wrong roots isolating." << std::endl;
		return 0;

	}

	for (i = 0;	eps < (abs(FUNCTION(x0)) / m1);	++i){

		x0 = x0 - FUNCTION(x0) / DERIVATIVE(x0);

	}

	*iterations = i;
	*Accuracy = abs(FUNCTION(x0) / m1);

	return x0;

}