/***
*file:"TEST.cpp"
*synopsis:testing functions for calculation value of integral by both method
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/


#include <iostream>

#include "Iteration.h"
#include "Newton.h"

using std::cout;
using std::endl;

#define MAX_ITERATIONS 100

//roots have been isolated previously analytically:
#define A1 -2
#define A2 -1
#define B1 0
#define B2 1

void GetRoots(bool Method){

	double Accuracy = 0, EPS = 0.01, X;
	int n = 0;

	if (Method)
		cout << "\nNewton-Raphson method\n";
	else
		cout << "\nIteration method( maximum iterations:" << MAX_ITERATIONS << ")\n";


	cout << "____________________________________________________________________\n";
	cout << "|       Epsilon      |        Root       |         Accuracy        |\n";
	cout << "____________________________________________________________________\n";

	if (Method){

		cout << "\nFirst root:" << endl;
		cout << "____________________________________________________________________\n";


		for (int i = 0; i < 5; ++i){

			X = NewtonRaphson(EPS, A1, A2, &Accuracy, &n);

			printf("| %18.16f | %17.13f | %23.20f |\n", EPS, X, Accuracy);

			EPS *= 0.001;
			cout << "____________________________________________________________________\n";

		}

		EPS = 0.01;

		cout << "\nSecond root:" << endl;
		cout << "____________________________________________________________________\n";

		for (int i = 0; i < 5; ++i){

			X = NewtonRaphson(EPS, B1, B2, &Accuracy, &n);

			printf("| %18.16f | %17.13f | %23.20f |\n", EPS, X, Accuracy);

			EPS *= 0.001;
			cout << "____________________________________________________________________\n";

		}

	}
	else{

		cout << "\nFirst root:" << endl;
		cout << "____________________________________________________________________\n";


		for (int i = 0; i < 5; ++i){

			X = Iteration(EPS, A1, A2, &Accuracy, &n, MAX_ITERATIONS);

			printf("| %18.16f | %17.13f | %23.20f |\n", EPS, X, Accuracy);

			EPS *= 0.001;
			cout << "____________________________________________________________________\n";

		}

		EPS = 0.01;

		cout << "\nSecond root:" << endl;
		cout << "____________________________________________________________________\n";


		for (int i = 0; i < 5; ++i){

			X = Iteration(EPS, B1, B2, &Accuracy, &n, MAX_ITERATIONS);

			printf("| %18.16f | %17.13f | %23.20f |\n", EPS, X, Accuracy);

			EPS *= 0.001;
			cout << "____________________________________________________________________\n";

		}

	}

}

void First(){

	GetRoots(true);

	GetRoots(false);

}

void Second(){

	double Accuracy = 0, EPS = 0.01;

	int n1 = 0, n2 = 0;

	cout <<"\nSecond task:\n" <<"____________________________________________________________________\n";
	cout << "|       Epsilon      |      Newton-Raphson      |     Iterations   |\n";
	cout << "____________________________________________________________________\n";

	for (int i = 0; i < 5; ++i){

		Iteration(EPS, A1, A2, &Accuracy, &n1, MAX_ITERATIONS);

		NewtonRaphson(EPS, A1, A2, &Accuracy, &n2);

		printf("| %18.16f | %24d | %16d |\n", EPS, n2, n1);

		EPS *= 0.001;
		cout << "____________________________________________________________________\n";

	}

}

int main(){

	First();

	Second();


	return 0;

}
