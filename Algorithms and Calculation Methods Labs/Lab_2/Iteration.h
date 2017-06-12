/***
*file:"Iteration.h"
*synopsis:declarations functions for calculation value of integral by iteration method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#ifndef _ITERATION_H
#define _ITERATION_H



double get_lambda(double const a, double const b);

double get_q_const(double const a, double const b);

double Iteration(double const eps, double const a, double const b, double *Accuracy, int *num, int max_iterations);



#endif