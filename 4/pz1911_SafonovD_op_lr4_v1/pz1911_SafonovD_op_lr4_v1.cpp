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
			system("cls");
			for (int i1 = 0; i1 < M; i1++) {
				for (int j1 = 0; j1 < M; j1++) {
					std::cout << std::setw(M) << Matrix_in[i1][j1] << "   ";
				}
				std::cout << std::endl;
			}
		}
	}
#pragma endregion

#pragma region SubMatrix1
	int N;
	N = M / 2;
	double** SubMatrix1 = new double* [N];
	for (int i = 0; i < N; i++) {
		SubMatrix1[i] = new double[N];
		for (int j = 0; j < N; j++) {
			SubMatrix1[i][j] = Matrix_in[i][j];
		}
	}
#pragma endregion

#pragma region SubMatrix2
	double** SubMatrix2 = new double* [N];
	for (int i = 0; i < N; i++) {
		SubMatrix2[i] = new double[N];
		for (int j = 0; j < N; j++) {
			SubMatrix2[i][j] = Matrix_in[i][j + N];
		}
	}
#pragma endregion

#pragma region SubMatrix3
	double** SubMatrix3 = new double* [N];
	for (int i = 0; i < N; i++) {
		SubMatrix3[i] = new double[N];
		for (int j = 0; j < N; j++) {
			SubMatrix3[i][j] = Matrix_in[i + N][j + N];
		}
	}
#pragma endregion

#pragma region SubMatrix4
	double** SubMatrix4 = new double* [N];
	for (int i = 0; i < N; i++) {
		SubMatrix4[i] = new double[N];
		for (int j = 0; j < N; j++) {
			SubMatrix4[i][j] = Matrix_in[i + N][j];
		}
	}

	
#pragma endregion
	
#pragma region Matrix_out
	double** Matrix_out = new double* [M];
	for (int i = 0; i < M; i++) {
		Matrix_out[i] = new double[M];
		for (int j = 0; j < M; j++) {
			if (j < N) {
				if (i < N) {
					Matrix_out[i][j] = SubMatrix4[i][j];
				}
				else {
					Matrix_out[i][j] = SubMatrix3[i - N][j];
				}
			}
			else {
				if (i < N) {
					Matrix_out[i][j] = SubMatrix1[i][j - N];
				}
				else {
					Matrix_out[i][j] = SubMatrix2[i - N][j - N];
				}
			}
		}
	}
#pragma endregion
	
#pragma region deleting SubMatrixes
	for (int i = 0; i < N; i++)
		delete[]SubMatrix1[i];
	for (int i = 0; i < N; i++)
		delete[]SubMatrix2[i];
	for (int i = 0; i < N; i++)
		delete[]SubMatrix3[i];
	for (int i = 0; i < N; i++)
		delete[]SubMatrix4[i];
#pragma endregion

#pragma region print Matrix_out
	system("cls");
	std::cout << "given matrix:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << std::setw(M) << Matrix_in[i][j] << "   ";
		}
		std::cout << std::endl;
	}

	std::cout << "rotated matrix:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << std::setw(M) << Matrix_out[i][j] << "   ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < M; i++)
		delete[]Matrix_in[i];

	for (int i = 0; i < M; i++)
		delete[]Matrix_out[i];
#pragma endregion

	system("pause");
	return 0;
}
