//application gets number N from the user, this number represents how many inputs after that he wants to do(if user inputs a 0 loop breaks).
//Output is three biggest numbers from all inputs.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include "inp_val.h"
using namespace std;

int main()
{
	cout << "The application takes at least 3 natural number inputs, at most n(user specified)," << endl;
	cout << "first three can be equal to 0, but if any input after 3rd will be equal to 0, input stops" << endl;
	cout << "Output will be three biggest numbers from the input" << endl;
	cout << endl;
#pragma region input S,M,L,n
	int n;
	string dialogN = "input natural number n";
	string error = "Wrong input, try again";
	n = cinat(dialogN, error);

	int L;
	string dialogL = "input natural number a1";
	L = cinat0(dialogL, error);

	int M;
	string dialogM = "input natural number a2";
	M = cinat0(dialogM, error);

	int S;
	string dialogS = "input natural number a3";
	S = cinat0(dialogS, error);
#pragma endregion

	int ax;

#pragma region sort
	while ((L < S) || (L < M) || (M < S)) {
		if (L < S) {
			ax = L;
			L = S;
			S = ax;//xchg L, S
		}
		else if (L < M) {
			ax = M;
			M = L;
			L = ax;//xchg L, M
		}
		else if (M < S) {
			ax = M;
			M = S;
			S = ax;//xchg M, S
		}
	}
#pragma endregion sorting a1, a2, a3 and putting them to S, M, L; so that L>M>S

	int i = 0;
	do {
#pragma region input a
		double a;
		cout << "input natural number a" << i + 4 << endl;
		cin >> a;

		for (bool i = 0; i != 1;)
		{
			if (cin.fail() || (floor(a) != ceil(a)) || (a < 0)) {//floor biggest int x thats smaller ot equal than a; ceil smallest int x thats bigger or equal than a; if floor == ceil, than a - int
				cout << "Wrong input, try again" << endl;
				cin.clear();
				cin.ignore();
				cin >> a;
			}
			else {
				i = 1;
			}
		}
#pragma endregion
#pragma region swaps
		if (a == 0) {
			break;
		}
		if (a > L) {
			ax = L;
			L = a;
			a = ax;
		}
		if (a > M) {
			ax = M;
			M = a;
			a = ax;
		}
		if (a > S) {
			S = a;
		}
#pragma endregion
		n -= 1;
		i += 1;
	} while (n > 3);

	std::cout << L << ">" << M << ">" << S << endl;
	std::system("pause");
	return 0;
}