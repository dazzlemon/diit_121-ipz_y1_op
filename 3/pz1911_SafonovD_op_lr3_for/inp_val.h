//cinat - input natural number only (N)
//cinat0 - (N+0)
//cint - integers only (Z)
//cinum - numerical only (R)

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int cinat(string a, string b)
{
	double aaa;
	cout << a << endl;
	cin >> aaa;

	for (bool i = 0; i != 1;)
	{
		if (cin.fail() || (floor(aaa) != ceil(aaa)) || (aaa < 1)) {//floor biggest int x thats smaller ot equal than a; ceil smallest int x thats bigger or equal than a; if floor == ceil, than a - int
			cout << b << endl;
			cin.clear();
			cin.ignore();
			cin >> aaa;
		}
		else {
			i = 1;
		}
	}

	return (int)aaa;
}

int cinat0(string a, string b)
{
	double aaa;
	cout << a << endl;
	cin >> aaa;

	for (bool i = 0; i != 1;)
	{
		if (cin.fail() || (floor(aaa) != ceil(aaa)) || (aaa < 0)) {//floor biggest int x thats smaller ot equal than a; ceil smallest int x thats bigger or equal than a; if floor == ceil, than a - int
			cout << b << endl;
			cin.clear();
			cin.ignore();
			cin >> aaa;
		}
		else {
			i = 1;
		}
	}

	return (int)aaa;
}

int cint(string a, string b)
{
	double aaa;
	cout << a << endl;
	cin >> aaa;

	for (bool i = 0; i != 1;)
	{
		if (cin.fail() || (floor(aaa) != ceil(aaa))) {//floor biggest int x thats smaller ot equal than a; ceil smallest int x thats bigger or equal than a; if floor == ceil, than a - int
			cout << b << endl;
			cin.clear();
			cin.ignore();
			cin >> aaa;
		}
		else {
			i = 1;
		}
	}

	return (int)aaa;
}

double cinum(string a, string b)
{
	double aaa;
	cout << a << endl;
	cin >> aaa;

	for (bool i = 0; i != 1;)
	{
		if (cin.fail()) {
			cout << b << endl;
			cin.clear();
			cin.ignore();
			cin >> aaa;
		}
		else {
			i = 1;
		}
	}

	return aaa;
}