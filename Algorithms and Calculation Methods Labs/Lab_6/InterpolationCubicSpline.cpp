/************************************************
*file:"InterpolationCubicSpline.h"
*synopsis:function realisation for interpolation
*author:Neshta R.
*written:01/01/2017
*last modified:03/01/2017
************************************************/


#include "Common.h"


double* GetSplineInterpolation(const double *InterpolationNodes, const double *Arguments, const int Size){

	double *ACoefficients, *BCoefficients, *CCoefficients, *DCoefficients, Difference, *InterpolationResults;
	int Left, Right;

	GetCoefficients(&ACoefficients, &BCoefficients, &CCoefficients, &DCoefficients, InterpolationNodes);

	InterpolationResults = new double[Size];

	for (int i = 0, NodesIterator = 0, CoefficientsIterator = 0; i < Size; ++i){


		if (Arguments[i] <= InterpolationNodes[0]){

			NodesIterator = 1;
			CoefficientsIterator = 1;

		}
		else if (Arguments[i] >= InterpolationNodes[NUMBER_OF_INTERVALS - 1]){

			NodesIterator = NUMBER_OF_INTERVALS - 1;
			CoefficientsIterator = NUMBER_OF_INTERVALS - 1;

		}

		else{

			Left = 0;
			Right = NUMBER_OF_INTERVALS - 1;

			while (Left + 1 < Right){

				NodesIterator = Left + (Right - Left) / 2;

				if (Arguments[i] <= InterpolationNodes[NodesIterator])
					Right = NodesIterator;

				else
					Left = NodesIterator;

			}


			CoefficientsIterator = Right;
			NodesIterator = Right;


		}


		Difference = Arguments[i] - InterpolationNodes[NodesIterator];


		InterpolationResults[i] = ACoefficients[CoefficientsIterator] +
			BCoefficients[CoefficientsIterator] * Difference +
			0.5*CCoefficients[CoefficientsIterator] * Difference*Difference +
			DCoefficients[CoefficientsIterator] * Difference*Difference*Difference / 6;

	}

	delete[] ACoefficients;
	delete[] BCoefficients;
	delete[] CCoefficients;
	delete[] DCoefficients;


	return InterpolationResults;

}
