/***
*file:"CompletePivoting.h"
*synopsis:declarations functions for solving system of linear equations using Complete Pivoting method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#ifndef _COMPLETEPIVOTING_H
#define _COMPLETEPIVOTING_H


bool IsAllPivots(bool *Arr, int const COLUMNS);

void GetAvailableValues(int *v1, int *v2, bool* arr1, bool* arr2, int const LINES, int const COLUMNS);

void Pivoting(double* Arr, double* Roots, int const LINES, int const COLUMNS);



#endif