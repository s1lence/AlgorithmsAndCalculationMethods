/***
*file:"Function.h"
*synopsis:declarations functions for calculation value of Cos
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#ifndef _FUNCTION_H
#define _FUNCTION_H
//x is the current angle in radians
int Cos(double Eps, double X, double* Absolute_Error, double *Reminder_Term);

double fact(int num);

double to_2pi(double angle);

#endif