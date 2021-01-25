//application manipulates matrix NxM
//input: 
//N - amount of rows
//M - amount of columns
//outputs:
//1. pseudo random generated matrix NxM
//2. amount of elements with two same numbers in fraction
//3. sum of additive elements with 5 or less tenth in fraction
//4. sum of additive elements with 5 or less tenth in fraction for every row(array)
//5. array from p.4 sorted ascending and matrix with rows sorted by respective elements of array(p.4)
//6. matrix with deleted even rows

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "inp_val6.h"
#include <cmath>
#include "structs_.h"

int main()
{
	std::srand(time(NULL));

	int N, M;
	std::cout << "input size of matrix:" << std::endl;
	char msg_invN[] = "N: ";
	char msg_invM[] = "M: ";
	char msg_error[] = "wrong input, try again";
	N = cinum(msg_invN, msg_error, 1, 1, 1);
	M = cinum(msg_invM, msg_error, 1, 1, 1);

	Matrix matrix1;//v1
	//Matrix_v2 matrix1;//v2

	matrix1.n = N;
	matrix1.m = M;

	matrix1.gen();
	std::cout << "Matrix " << matrix1.n << "x" << matrix1.m << " after generation: " << std::endl;
	matrix1.print();
	std::cout << std::endl;

	std::cout << "amount of elements with two same numbers in fraction: " << std::endl;
	std::cout << matrix1.repdigit_amount() << std::endl << std::endl;//E

	matrix1.frac_find();//D+C
	std::cout << "sum of additive elements with 5 or less tenth in fraction:" << std::endl;
	std::cout << matrix1.frac_0_6_sum << std::endl << std::endl;

	std::cout << "sum of additive elements with 5 or less tenth in fraction for every row:" << std::endl;
	for (int i = 0; i < matrix1.n; i++) {
		std::cout << "row" << (i + 1) << ": " << matrix1.frac_0_6[i] << ' ' << std::endl;
	}
	std::cout << std::endl;

	matrix1.sort_rows();//B

	std::cout << "sum of additive elements with 5 or less tenth in fraction for every row(sorted):" << std::endl;
	for (int i = 0; i < matrix1.n; i++) {
		std::cout << "row" << (i + 1) << ": " << matrix1.frac_0_6[i] << ' ' << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Matrix " << matrix1.n << "x" << matrix1.m << " with rows sorted ascending up to down" << std::endl;
	std::cout << "by sum of additive elements with 5 or less tenth in fraction, respectively: " << std::endl;
	matrix1.print();
	std::cout << std::endl;

	std::cout << "Matrix " << matrix1.n << "x" << matrix1.m << " with deleted even rows: " << std::endl;
	matrix1.del_even_rows();
	std::cout << "New size of matrix: " << matrix1.n << "x" << matrix1.m << std::endl;
	matrix1.print();
	std::cout << std::endl;

	std::system("pause");
	return(0);
}
