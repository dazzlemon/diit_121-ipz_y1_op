#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

int main()
{
	double Xa, Ya, Xd, Yd, Xe, Ye;

	cout << "Programm finds coordinates of rectangle vertexes" << endl << "so that triangle of given vertex coordinates is inscribed in rectangle" << endl << "and difference of their areas is as small as possible" << endl;
	cout << "Triangle Vertexes(AED), Rectangle Vertexes(ABCD)" << endl;

	cout << "input Xa ";
	cin >> Xa;
	cout << "input Ya ";
	cin >> Ya;
	cout << "input Xe ";
	cin >> Xe;
	cout << "input Ye ";
	cin >> Ye;
	cout << "input Xd ";
	cin >> Xd;
	cout << "input Yd ";
	cin >> Yd;//in 

	double v1, v2;

	if ( ((Xa == Xe) && (Xe == Xd)) || ((Ya == Ye) && (Ye == Yd)) ) {
		cout << "all 3 lines are in the same line, wrong input" << endl;
		system("pause");
		return 0;//checking if all three dots are in the same line
	}

	while ((Xa == Xd) || (Ya == Yd)) {//loop to change postions of use in final formula to avoid dividing by 0
		v1 = Xd;
		v2 = Yd;
		Xd = Xa;
		Yd = Ya;
		Xa = Xe;
		Ya = Ye;
		Xe = v1;
		Ye = v2;
	}
	
	double  Xb, Yb, Xc, Yc;
	
	Xb = 0;
	Yb = 0;
	Xc = 0;
	Yc = 0;

	cout << "A(" << Xa << ";" << Ya << ")" << endl;
	cout << "B(" << Xb << ";" << Yb << ")" << endl;
	cout << "C(" << Xc << ";" << Yc << ")" << endl;
	cout << "D(" << Xd << ";" << Yd << ")" << endl;

	system("pause");
	return 0;
}
 