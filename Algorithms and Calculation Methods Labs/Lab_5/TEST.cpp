/************************************************************************
*file:"TEST.cpp"
*synopsis:enter point of program(testing configuration for our functions)
*author:Neshta R.
*written:12/12/2016
*last modified:01/01/2017
************************************************************************/


#include<cstdio>

#include "Common.h"


int main(){

	double Error = 0;
	LeastSquaresApproximation(&Error);


	printf("Error = %f\n", Error);


	return 0;

}
