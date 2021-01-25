

#include <iostream>
#include <Windows.h>

using namespace std;

//Body
int main()
{
	double a, b, c, d;//initialising variables

	cout << "Programm checks if rectangle with sides of a,b can be placed in rectangle with sides of c,d" << endl << "so that their sides parallel/perpendicular" << endl;
	
	cout << "input a ";//input
	cin >> a;
	cout << "input b ";
	cin >> b;
	cout << "input c ";
	cin >> c;
	cout << "input d ";
	cin >> d;

	if (a > 0 && b > 0 && c > 0 && d > 0) {//checks if all numbers >0
			if ((a<c && b<d) || (a<d && b<c)) {//checks if first rectangle has both sides bigger than second
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
	}
	else {
		cout << "one or more numbers <0; false" << endl;
	}

	system("pause");
	return 0;
}

