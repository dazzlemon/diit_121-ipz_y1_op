//cinum - numerical only (R)
//char msg_invite - your message for inviting user to input their number
//char msg_error - if error input occures
//int m_ - check if input is multiple of this number
//bool intFlag - =1(only integer input); =0(any input)
//double left - leftmost point in diapasone for input
//double right - rightmost point in diapasone for input

#include <iostream>
#include <windows.h>
#include <cmath>
#include <climits>
#include "inp_val6.h"
#undef max

int input_validation::cinum(char* msg_invite, char* msg_error, int m_, bool intFlag, float left, float right)
{
	bool i = 0;
	float aaa;
	std::cout << msg_invite << std::endl;

	do
	{
		std::cin >> aaa;
		int iaaa;
		iaaa = (int)aaa;

		if (std::cin.fail() || (aaa < left) || (aaa > right) || ((intFlag == 1) && (ceil(aaa) != floor(aaa))) || ((m_ != 1) && ((iaaa % m_) != 0))) {
			std::cout << msg_error << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			i = 1;
		}
	} while (!i);

	return (int)aaa;
}

void input_validation::val_char_lenght(char array[], int ary_size) {//input to char array with lenght validation
	bool correct = false;
	do
	{
		std::cin.getline(array, 24);
		if ((strlen(array) > 23) || std::cin.fail()) {
			std::cout << "wrong input, try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			correct = true;
		}
	} while (!correct);
}