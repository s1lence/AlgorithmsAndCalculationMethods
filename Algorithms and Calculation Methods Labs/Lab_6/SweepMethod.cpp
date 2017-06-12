/***********************************************************************
*file:"SweepMethod.h"
*synopsis:functions realisation for solving system of tridiagonal matrix
*author:Neshta R.
*written:01/01/2017
*last modified:03/01/2017
***********************************************************************/


#include "Common.h"


void GetCoefficients(double **ACoefficients, double **BCoefficients, double **CCoefficients, double **DCoefficients, const double *Arguments){

	double A, B, C, F, hCurrent, hNext, tmp, *Alphas, *Betas;

	*ACoefficients = new double[NUMBER_OF_INTERVALS];
	*BCoefficients = new double[NUMBER_OF_INTERVALS];
	*CCoefficients = new double[NUMBER_OF_INTERVALS];
	*DCoefficients = new double[NUMBER_OF_INTERVALS];


	Alphas = new double[NUMBER_OF_INTERVALS - 1];
	Betas = new double[NUMBER_OF_INTERVALS - 1];

	Alphas[0] = Betas[0] = (*CCoefficients)[0] = 0;


	for (int i = 0; i < NUMBER_OF_INTERVALS; ++i)
		(*ACoefficients)[i] = Function(Arguments[i]);


	for (int i = 1; i < NUMBER_OF_INTERVALS - 1; ++i){

		hCurrent = Arguments[i] - Arguments[i - 1];
		hNext = Arguments[i + 1] - Arguments[i];


		A = hCurrent;
		C = (hCurrent + hNext) * 2;

		B = hNext;
		F = 6 * (((*ACoefficients)[i + 1] - (*ACoefficients)[i]) / hNext - ((*ACoefficients)[i] - (*ACoefficients)[i - 1]) / hCurrent);


		tmp = A*Alphas[i - 1] + C;

		Alphas[i] = -B / tmp;

		Betas[i] = (F - A*Betas[i - 1]) / tmp;


	}


	(*CCoefficients)[NUMBER_OF_INTERVALS - 1] = (F - A*Betas[NUMBER_OF_INTERVALS - 2]) / (A*Alphas[NUMBER_OF_INTERVALS - 2] + C);


	for (int i = NUMBER_OF_INTERVALS - 2; i > 0; --i)

		(*CCoefficients)[i] = Alphas[i] * (*CCoefficients)[i + 1] + Betas[i];


	delete[] Alphas;
	delete[] Betas;


	for (int i = NUMBER_OF_INTERVALS - 1; i > 0; --i){

		hCurrent = Arguments[i] - Arguments[i - 1];

		(*DCoefficients)[i] = ((*CCoefficients)[i] - (*CCoefficients)[i - 1]) / hCurrent;

		(*BCoefficients)[i] = hCurrent*0.5*(*CCoefficients)[i] - hCurrent*hCurrent*(*DCoefficients)[i] / 6 + ((*ACoefficients)[i] - (*ACoefficients)[i - 1]) / hCurrent;

	}


	(*ACoefficients)[0] = Function(Arguments[0]);

	(*BCoefficients)[0] = (*CCoefficients)[0] = (*DCoefficients)[0] = 0;

	(*BCoefficients)[NUMBER_OF_INTERVALS - 1] = (*CCoefficients)[NUMBER_OF_INTERVALS - 1] = (*DCoefficients)[NUMBER_OF_INTERVALS - 1] = 0;


}

double Function(const double X){

	return 0.5*X*X*X*sin(X * 3);

}
