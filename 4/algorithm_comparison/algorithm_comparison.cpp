//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <chrono>

int main()
{
#pragma region Matrix_in_rand
	int M = 9392;
	double** Matrix_in = new double* [M];
	for (int i = 0; i < M; i++) {
		Matrix_in[i] = new double[M];
		for (int j = 0; j < M; j++) {
			Matrix_in[i][j] = rand();
		}
	}
#pragma endregion

#pragma region test_old
	std::chrono::time_point<std::chrono::system_clock> start_old, end_old;

	start_old = std::chrono::system_clock::now();
#pragma region processing_old
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
#pragma endregion
	end_old = std::chrono::system_clock::now();
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
	unsigned long int elapsed_old_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_old - start_old).count();
	long float elapsed_old_sec = elapsed_old_ms / 1000;
#pragma endregion

#pragma region test_new
	std::chrono::time_point<std::chrono::system_clock> start_new, end_new;

	start_new = std::chrono::system_clock::now();
#pragma region Matrix_processing_new
	for (int i = 0; i < (M / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			double temp(Matrix_in[i][j]);
			Matrix_in[i][j] = Matrix_in[i + M / 2][j];
			Matrix_in[i + M / 2][j] = Matrix_in[i + M / 2][j + M / 2];
			Matrix_in[i + M / 2][j + M / 2] = Matrix_in[i][j + M / 2];
			Matrix_in[i][j + M / 2] = temp;
		}
	}
#pragma endregion
	end_new = std::chrono::system_clock::now();

	unsigned long int elapsed_new_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_new - start_new).count();
	long float elapsed_new_sec = elapsed_new_ms / 1000;
#pragma endregion
	for (int i = 0; i < M; i++)
		delete[]Matrix_in[i];

	for (int i = 0; i < M; i++)
		delete[]Matrix_out[i];
	std::cout << "Matrix size: " << M << "*" << M << std::endl;
	std::cout << "old algorithm in millisec: " << elapsed_old_ms << std::endl;
	std::cout << "new algorithm in millisec: " << elapsed_new_ms << std::endl;
	std::system("pause");
	return 0;
}

