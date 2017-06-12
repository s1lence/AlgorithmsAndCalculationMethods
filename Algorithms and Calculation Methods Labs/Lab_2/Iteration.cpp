/***
*file:"Iteration.cpp"
*synopsis:definitions functions for calculation value of integral by iteration method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/


#include "Common.h"

double get_lambda(double const a, double const b){

	double A = fabs(DERIVATIVE(a));
	double B = fabs(DERIVATIVE(b));

	return A > B ? 1 / A : 1 / B;

}

double get_q_const(double const a, double const b, int const k, double const lambda){

	double A = fabs(DERIVATIVE(a));
	double B = fabs(DERIVATIVE(b));

	return A > B ? 1 - B / A : 1 - A / B;

}

double Iteration(double const eps, double const a, double const b, double *Accuracy, int *num, int max_iterations){

	double tmp, x0 = a, x1, lambda = get_lambda(a, b);

	int i = 0, k = 1;

	if (DERIVATIVE(x0) < 0)
		k = -1;

	double q = get_q_const(a, b, k, lambda);

	x1 = x0 - lambda*k*FUNCTION(x0);
	tmp = x1;

	while (fabs(x1 - x0) > (1 - q) / q*eps){

		x0 = tmp;
		x1 = x0 - lambda*k*FUNCTION(x0);
		tmp = x1;

		++i;

		if (i == 100)
			break;

	}

	*num = i;
	*Accuracy = fabs((x1 - x0)*q / (1 - q));

	return x1;

}
