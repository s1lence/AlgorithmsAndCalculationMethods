/***
*file:"Newton.h"
*synopsis:declarations functions for calculation value of integral by Newton-Raphson method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#ifndef _NEWTON_H
#define _NEWTON_H


double get_m1_const(double const a, double const b);

double get_x0(double const a, double const b);

double NewtonRaphson(double const eps, double const a, double const b, double *Accuracy,int *iterations);



#endif