/***
*file:"CompletePivoting.cpp"
*synopsis:definitions functions for solving system of linear equations
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/


#include <cmath>

bool IsAllPivots(bool *Arr, int const COLUMNS){

	for (int i = 0; i < COLUMNS; ++i){

		if (!Arr[i])
			return false;

	}

	return true;

}

void GetAvailableValues(int *v1, int *v2, bool* arr1, bool* arr2, int const LINES, int const COLUMNS){
	
	for (int i = 0; i < LINES; ++i)
		if (!arr1[i]){

			*v1 = i;
			break;

		}

	for (int i = 0; i < COLUMNS - 1; ++i)
		if (!arr2[i]){

			*v2 = i;
			break;

		}

}

void Pivoting(double* Arr, double* Roots, int const LINES, int const COLUMNS){

	bool *isPivotLines, *isPivotColumns;

	int *Order, p = 0, q = 0, k = 0;
	double m = 0;

	Order = new int[LINES * 2]();

	isPivotLines = new bool[LINES]();
	isPivotColumns = new bool[COLUMNS]();

	while (!IsAllPivots(isPivotLines, COLUMNS)){

		for (int j = 0; j < LINES; ++j){

			if (isPivotLines[j])
				continue;

			for (int i = 0; i < COLUMNS - 1; ++i){

				if (!isPivotColumns[i] && fabs(Arr[j*COLUMNS + i]) > fabs(Arr[p*COLUMNS + q])){

					p = j;
					q = i;

				}

			}

		}


		isPivotLines[p] = true;

		for (int j = 0; j < LINES; ++j){

			if (isPivotLines[j])
				continue;

			for (int i = 0; i < COLUMNS; ++i){

				if (isPivotColumns[i])
					continue;

				if (m == 0)
					m = Arr[j*COLUMNS + q] / Arr[p*COLUMNS + q];

				Arr[j*COLUMNS + i] -= m* Arr[p*COLUMNS + i];

			}

			m = 0;

		}

		isPivotColumns[q] = true;

		Order[k++] = p;
		Order[k++] = q;

		GetAvailableValues(&p, &q, isPivotLines, isPivotColumns, LINES, COLUMNS);

	}


	delete[] isPivotColumns;
	delete[] isPivotLines;


	k = (COLUMNS - 1) * 2 - 1;

	while (k > 0){

		q = Order[k--];
		p = Order[k--];

		Roots[q] = Arr[p*COLUMNS + LINES];

		for (int i = 0; i < LINES; ++i){

			if (i == q)
				continue;

			Roots[q] -= Arr[p*COLUMNS + i] * Roots[i];

		}

		Roots[q] /= Arr[p*COLUMNS + q];

	}

	delete[] Order;

}
