/***
*file:"TEST.cpp"
*synopsis:testing functions for calculation value of Cos
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#include <iostream>
//#include <fstream>
#include "Function.h"
#define UPPER -31.3
#define LOWER -4.9
using namespace std;

int First(){

	double X = (LOWER + UPPER) / 2.0;
	double Eps = 0.01, Error, Rem_Term;

	cout << "First task:"<<endl<<"______________________________________________________________________________________" << endl;
	cout << "|      Epsilon     |   N   |        Absolute Error      |        Reminder Term       |" << endl;
	cout << "______________________________________________________________________________________" << endl;
	
	int l, n;

	for (int i = 0; i < 5; ++i){

		l = Cos(Eps, X, &Error, &Rem_Term);

		printf("| %1.14f | %5d | %1.24f | %27.23f|\n",Eps,l,Error,Rem_Term);
		cout << "______________________________________________________________________________________" << endl;
		Eps *= 0.001;

		if (i == 2)
			n = l;

	}

	cout << endl;

	return n;

}

void Second(int N){

	double AbsoluteError, ReminderTerm;
	double X, H;

	cout << "Second task:\n____________________________________________________________________________" << endl;
	cout << "|      X(i)   |        Absolute Error      |          Reminder Term        |" << endl;
	cout << "____________________________________________________________________________" << endl;


	H = (UPPER - LOWER) / 10;

	for (int i = 0; i <= 10; ++i){

		X = LOWER + H*i;
		Cos(0.00000001, X, &AbsoluteError, &ReminderTerm);

		printf("| %10.4f  | %26.12f | %30.25f|\n", X, AbsoluteError, ReminderTerm);
		cout << "____________________________________________________________________________" << endl;

	}

}

int main(){

	Second(First());



	return 0;

}