//application to rotate 90 degrees clockwise quarter submatrix of given qudratic matrix 2Nx2N
//in:
//number M(matrix order)
//Elements of Matrix MxM
//out:
//new matrix MxM with rotated 90 degrees clockwise quarter submatrixes

#include <iostream>
#include "inp_val5.h"
#include <iomanip>
#include <stdlib.h>

int main()
{
	std::cout << "Application takes input matrix MxM(M = 2N), and rotates its quarter submatrixes 90 degrees clockwise" << endl;
#pragma region M
	int M;
	char msg_inviteM[8] = "input M";
	char msg_error[23] = "wrong input, try again";
	M = cinum(msg_inviteM, msg_error, 2, 1, 2);
#pragma endregion 

#pragma region Matrix_in_0
	double** Matrix_in = new double* [M];
	for (int i = 0; i < M; i++) {
		Matrix_in[i] = new double[M];
		for (int j = 0; j < M; j++) {
			Matrix_in[i][j] = 0;
		}
	}
#pragma endregion

#pragma region Matrix_in
	char msg_inviteij[21] = "input matrix element";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			Matrix_in[i][j] = cinum(msg_inviteij, msg_error, 1, 0, -214783648);
			std::system("cls");
			for (int i1 = 0; i1 < M; i1++) {
				for (int j1 = 0; j1 < M; j1++) {
					std::cout << std::setw(M) << Matrix_in[i1][j1] << "   ";
				}
				std::cout << std::endl;
			}
		}
	}
#pragma endregion

#pragma region Matrix_processing
	for (int i = 0; i < (M / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			double temp (Matrix_in[i][j]);
			Matrix_in[i][j] = Matrix_in[i + M / 2][j];
			Matrix_in[i + M / 2][j] = Matrix_in[i + M / 2][j + M / 2];
			Matrix_in[i + M / 2][j + M / 2] = Matrix_in[i][j + M / 2];
			Matrix_in[i][j + M / 2] = temp;
		}
	}
#pragma endregion

#pragma region print Matrix_in
	//std::system("cls");
	std::cout << "rotated matrix:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << std::setw(M) << Matrix_in[i][j] << "   ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < M; i++)
		delete[]Matrix_in[i];
#pragma endregion

	std::system("pause");
	return 0;
}