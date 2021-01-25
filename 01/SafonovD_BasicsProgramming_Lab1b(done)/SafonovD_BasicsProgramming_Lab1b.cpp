//programm making M=badc from N=abcd
#include <iostream>
#include <Windows.h> 
using namespace std;

int main()
{
	long int N, M, a, b, c, d;

	cout << "programm making M=badc from N=abcd" << endl << "input N ";
	cin >> N;

	while (N != 0)//loop to split number into digits
	{
		d = N % 10;
		c = ((N - d) / 10) % 10;
		b = ((N - (10 * c + d)) / 100) % 10;
		a = ((N - (100 * b + 10 * c + d)) / 1000) % 10;

		M = 1000 * b + 100 * a + 10 * d + c;
		cout << "M from given N is equal " << M << endl;
		system("pause");
		return 0;
	}
}