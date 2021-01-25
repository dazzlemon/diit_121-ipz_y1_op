#include <iostream>
#include <Windows.h>

using namespace std;

//Body
int main()
{
	double Xa, Ya, Xd, Yd, Xe, Ye;

	#pragma region i_o
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
	#pragma endregion

	double Xb, Yb, Xc, Yc;

	#pragma region 3in_same_line/a_d_in1
	if ( ((Xa == Xe) && (Xe == Xd)) || ((Ya == Ye) && (Ye == Yd)) || (((Xe - Xa) / (Xd - Xe)) == ((Ye - Ya) / (Yd - Ye))) || (((Xd - Xe) / (Xe - Xa)) == ((Yd - Ye) / (Ye - Ya))) ) {
		cout << "all 3 lines are in the same line, wrong input" << endl;
		goto end_main;//checking if all three dots are in the same line
	}

	if (Ya == Yd) {
		goto ad_horizon;//checking if A and D are in the same horizontal
	}
	
	if (Xa == Xd) {
		goto ad_vert;//checking if A and D are in the same vertical
	}
	#pragma endregion

	#pragma region hor_steps
	#pragma region ad_horizon
	ad_horizon:
	if (((Xe > Xd) && (Xe < Xa)) || ((Xe < Xd) && (Xe > Xa))) {
		goto r1;//checking if Xe is between Xa and Xd regardless of which Xa or Xd is bigger 
	}
	else {
		if (Xa > Xd) {//checking if A is further to the right than D
			goto Xa_d;
		}
	}	goto Xd_a;
	#pragma endregion 

	#pragma region Xa_d
	Xa_d://Xa>Xd, Ya==Yd, Xe isn't inbetween Xa and Xd
	if (Xe > Xa) {//check for Xe>Xa>Xd
		goto XAinbetw_ED;
	}
	else {
		goto XDinbetw_EA;
	}
	#pragma endregion
	
	#pragma region Xd_a
	Xd_a://Xd>Xa, Ya==Yd, Xe isn't inbetween Xa and Xd
	if (Xe > Xd) {//check for Xe>Xd>Xa
		goto XDinbetw_EA;
	}
	else {
			goto XAinbetw_ED;
	}
	#pragma endregion
	#pragma endregion

	#pragma region results set
	r1://result calculation for Xe between Xa and Xd
	Xb = Xa;
	Yb = Ye;
	Xc = Xd;
	Yc = Ye;
	goto end_main;

	XDinbetw_EA://Xa>Xd>Xe || Xa<Xd<Xe
	Yb = Ye;
	Xb = Xa;
	Yc = Ye;
	Xc = Xe;
	Xd = Xe;
	goto rez_out;
	
	XAinbetw_ED://Xe>Xa>Xd || Xe<Xa<Xd
	Yb = Ye;
	Xb = Xe;
	Yc = Ye;
	Xc = Xd;
	Xa = Xe;
	goto rez_out;

	YDinbetw_EA://Ya>Yd>Ye || Ya<Yd<Ye
	Yb = Ye;
	Xb = Xe;
	Xc = Xe;
	Yc = Yd;
	Ya = Ye;
	goto rez_out;

	YAinbetw_ED://Ye>Ya>Yd || Ye<Ya<Yd
	Yb = Ya;
	Xb = Xe;
	Xc = Xe;
	Yc = Ye;
	Yd = Ye;
	goto rez_out;

	uniformula:
	#pragma endregion add uniformula

	#pragma region vert_steps
	ad_vert:
	if (((Ye > Yd) && (Ye < Ya)) || ((Ye < Yd) && (Ye > Ya))) {
		goto r1;//checking if Ye is between Ya and Yd regardless of which Ya or Yd is bigger 
	}
	else {
		if (Ya > Yd) {//checking if A is higher than D
			goto Ya_d;
		}
	}	goto Yd_a;

	#pragma region Ya_d
	Ya_d://Ya>Yd, Xa==Xd, Ye isn't inbetween Ya and Yd
	if (Ye > Ya) {//check for Ye>Ya>Yd
		goto YAinbetw_ED;
	}
	else {
		goto YDinbetw_EA;
	}
	#pragma endregion

	#pragma region Yd_a
	Yd_a://Yd>Ya, Xa==Xd, Ye isn't inbetween Ya and Yd
	if (Ye > Yd) {//check for Ye>Yd>Ya
		goto YDinbetw_EA;
	}
	else {
		goto YAinbetw_ED;
	}
	#pragma endregion

	#pragma endregion

	#pragma region rez_out
	rez_out://out
	cout << "A(" << Xa << ";" << Ya << ")" << endl;
	cout << "B(" << Xb << ";" << Yb << ")" << endl;
	cout << "C(" << Xc << ";" << Yc << ")" << endl;
	cout << "D(" << Xd << ";" << Yd << ")" << endl;
	#pragma endregion

	end_main:
	system("pause");
	return 0;
}
