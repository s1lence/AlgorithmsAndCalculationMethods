/***
*file:"Function.cpp"
*synopsis:definitions functions for calculation value of Cos
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/


#define _USE_MATH_DEFINES
#include <math.h>

double fact(int num){

	return (num == 0 || num == 1) ? 1 : fact(num - 1)*num;

}

double to_2pi(double angle){

	double tmp = angle / M_PI;
	int n = tmp;
	tmp -= n;

	if (n % 2 != 0)
		return tmp + M_PI;

	return tmp;

}

int Cos(double Eps, double X,double* Absolute_Error,double* Reminder_Term){

	double res = 0, cur = 1; //res - is a searched value of cos, cur is U(i) element
	int i=0;

	X = to_2pi(X);
	while (fabs(cur)>=Eps)	{
		res += cur;
		++i;
		cur = pow(X, 2 * i) / fact(2 * i);
		if (i % 2 != 0)
			cur *= -1;
	}

	*Absolute_Error = fabs(cos(X)-res);
	*Reminder_Term = fabs(cur);

	return i - 1;

}

