//Programm calculating Volume of custom shape(Cylinder+Half Sphere)
//Input=Rc,Rs,h(int)
//output=volume,surface area(int)

#include <iostream>
#include <Windows.h>
#ifndef M_PI
#define M_PI 3.14 //setting pi value to 3.14
#endif 
using namespace std;

//Body
int main()
{
	//Rc - Cylinder radius; Rs - sphere radius; S0 - unsigned value of =pi*(Rc*Rc-Rs*Rs); v,s - ans; h- cyl height
	
	cout << "Programm calculating Volume of custom shape(Cylinder+Half Sphere) " << endl;

	double Rc, Rs, h;
	cout << "input cylinder radius ";
	cin >> Rc;
	cout << "input sphere radius ";
	cin >> Rs;
	cout << "input h ";
	cin >> h;

	double S0;
	S0 = M_PI * (Rc + Rs) * (Rc - Rs);
	if (S0 < 0) {
		S0 = -S0;// making sure that S0>0
	}

	double v, s;
	v = M_PI * (Rc * Rc * h + 2 * Rs * Rs * Rs / 3);
	s = S0 + M_PI * (Rc * (Rc + 2 * h) + 2 * Rs * Rs);
	

	cout << "Custom shape's volume with Rcyl=" << Rc << "; Rsph=" << Rs << " and h=" << h << " equal " << v << endl;
	cout << "and surface " "equal " << s << endl;
	
	system("pause");
	return 0;
}
