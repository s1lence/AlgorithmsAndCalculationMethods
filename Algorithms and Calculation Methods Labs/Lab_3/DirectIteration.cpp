/***
*file:"DirectIteration.cpp"
*synopsis:definitions functions for solving system of linear equations using Direct Iteration method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#include "Common.h"


bool Transform(double* arr){

	for (int j = 0; j < LINES; ++j){

		for (int i = 0; i < COLUMNS; ++i){

			if (i == j){

				if (arr[j*COLUMNS + i] == 0)
					return false;

				continue;

			}


			arr[j*COLUMNS + i] /= -arr[j*COLUMNS + j];

		}


		arr[j*COLUMNS + j] = 0;

	}


	return true;

}

bool Iteration(double* arr, double* roots, double const eps){

	double new_roots[LINES];
	double mNorm = 0, tmp = 0, q = 0;

	int k = 0;

	if (!Transform(arr))
		return false;

	for (int j = 0; j < LINES; ++j){

		for (int i = 0; i < COLUMNS - 1; ++i){

			if (i == j)
				continue;


			tmp += fabs(arr[j*COLUMNS + i]);

			roots[j] += (arr[j*COLUMNS + i] + 1)* arr[i*COLUMNS + COLUMNS - 1];

		}

		if (q < tmp)
			q = tmp;

		tmp = 0;

	}


	k = 1;

	while (1){

		for (int j = 0; j < LINES; ++j){

			new_roots[j] = 0;

			for (int i = 0; i < COLUMNS - 1; ++i){

				if (i == j)
					continue;

				new_roots[j] += arr[j*COLUMNS + i] * roots[i];

			}

			new_roots[j] += arr[j*COLUMNS + COLUMNS - 1];

		}


		for (int i = 0; i < LINES; ++i){

			tmp = fabs(new_roots[i] - roots[i]);

			if (tmp > mNorm)
				mNorm = tmp;

			roots[i] = new_roots[i];

		}


		if (mNorm <= eps*(1 - q) / q){

			for (int i = 0; i < LINES; ++i)
				roots[i] *= -1;


			return true;
		}

		++k;

		mNorm = 0;

	}

}
