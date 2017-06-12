/************************************************************************
*file:"TEST.cpp"
*synopsis:enter point of program(testing configuration for our functions)
*author:Neshta R.
*written:01/01/2017
*last modified:04/01/2017
************************************************************************/


#include <cstdio>

#include "Common.h"


int  main(){


	double *InterpolationNodes, *Arguments, *Results, Step;

	int Number = NUMBER_OF_INTERVALS*2;


	Step = (UPPER_BOUND - LOWER_BOUND) / NUMBER_OF_INTERVALS;




	InterpolationNodes = new double[NUMBER_OF_INTERVALS];

	for (int i = 0; i < NUMBER_OF_INTERVALS; ++i)

		InterpolationNodes[i] = i*Step;




	Step = (UPPER_BOUND - LOWER_BOUND) / Number;

	Arguments = new double[Number];


	for (int i = 0; i < Number; ++i)

		Arguments[i] = i*Step;




	Results = GetSplineInterpolation(InterpolationNodes, Arguments, Number);

	delete[] InterpolationNodes;




	printf("\tX\t\t\tSpline value \n");

	for (int i = 0; i < Number; ++i)

		printf("%16.14f	%16.14f\n", Arguments[i], Results[i]);




	delete[]  Arguments;
	delete[] Results;


	return 0;

}

