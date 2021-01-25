//need a fix for not uniformula right angle triangle
#include <iostream>
#include <Windows.h>

using namespace std;

//Body
int main()
{
	double Xa, Ya, Xd, Yd, Xe, Ye;

	#pragma region i_o
	cout << "Programm finds coordinates of rectangle vertexes" << endl << "so that triangle of given vertex coordinates is inscribed in rectangle" << endl << "and difference of their areas is as small as possible" << endl;
	cout << "at the moment program can only compute ttrisngles so that AD is vertical or horizontal, check your inputs pls" << endl;
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
	#pragma endregion

	double Xb, Yb, Xc, Yc;

	if (((Xa == Xe) && (Xe == Xd)) || ((Ya == Ye) && (Ye == Yd)) || (((Xe - Xa) / (Xd - Xe)) == ((Ye - Ya) / (Yd - Ye))) || (((Xd - Xe) / (Xe - Xa)) == ((Yd - Ye) / (Ye - Ya)))) {
		cout << "all 3 lines are in the same line, wrong input" << endl;//checking if all three dots are in the same line
		system("pause");
		return 0;
	}
	else {
		if (Ya == Yd) {//checking if A and D are in the same horizontal
			if (((Xe >= Xd) && (Xe <= Xa)) || ((Xe <= Xd) && (Xe >= Xa))) {//checking if Xe is between Xa and Xd regardless of which Xa or Xd is bigger 
				Xb = Xa;
				Yb = Ye;
				Xc = Xd;
				Yc = Ye;
			}
			else {
				if (((Xa >= Xe) && (Xa <= Xd)) || ((Xa <= Xe) && (Xa >= Xd))) {//checking if Xa inbetween Xd and Xe
					Xb = Xe;
					Yb = Ye;
					Xc = Xd;
					Yc = Ye;
					Xa = Xe;
				}
				else {
					Xb = Xa;
					Yb = Ye;
					Yc = Ye;
					Xc = Xe;
					Xd = Xe;
				}
			}
		}
		else {
			if (Xa == Xd) {//checking if A and D are in the same vertical
				if (((Ye >= Yd) && (Ye <= Ya)) || ((Ye <= Yd) && (Ye >= Ya))) {//checking if Ye is between Ya and Yd regardless of which Ya or Yd is bigger 
					Yb = Ya;
					Xb = Xe;
					Yc = Yd;
					Xc = Xe;
				}
				else {
					if (((Ya >= Ye) && (Ya <= Yd)) || ((Ya <= Ye) && (Ya >= Yd))) {//checking if Ya inbetween Yd and Ye
						Yb = Ye;
						Xb = Xe;
						Yc = Yd;
						Xc = Xe;
						Ya = Ye;
					}
					else {
						Yb = Ya;
						Xb = Xe;
						Xc = Xe;
						Yc = Ye;
						Yd = Ye;
					}
				}
			}
			else {
				//add uniformula
				cout << "uniformula isn't added yet" << endl;
				system("pause");
				return 0;
			}
		}
	}

	#pragma region rez_out
	//out
	cout << "A(" << Xa << ";" << Ya << ")" << endl;
	cout << "B(" << Xb << ";" << Yb << ")" << endl;
	cout << "C(" << Xc << ";" << Yc << ")" << endl;
	cout << "D(" << Xd << ";" << Yd << ")" << endl;
	#pragma endregion

	system("pause");
	return 0;
}