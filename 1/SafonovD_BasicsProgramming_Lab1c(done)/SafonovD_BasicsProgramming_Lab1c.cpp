//programm calculating  -64a^3 + 240a^(2)*b - 300ab^2 + 125b^3

#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	float a, b;

	cout << "programm calculating - 64a ^ 3 + 240a ^ (2) * b - 300ab ^ 2 + 125b ^ 3 from given a and b  variables" << endl;
	cout << "input a ";
	cin >> a;
	cout << "input b ";
	cin >> b;

	float r;
	r = (5 * b - 4 * a) * (5 * b - 4 * a) * (5 * b - 4 * a);

	cout << r << endl;
	system("pause");
	return 0;
}
