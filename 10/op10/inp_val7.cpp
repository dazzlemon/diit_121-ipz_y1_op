#include "inp_val7.h"
#include <iostream>
#include <windows.h>
#include <cmath>
#include <climits>
#undef max

using namespace std;
double cinum(const char* msg_invite, const char* msg_error, int multipleOf = 1, bool intFlag = false, double left = -2147483648.0, double right = 2147483647.0) {
	bool goodInput = false;
	double doubleInput;
	cout << msg_invite << endl;
	do {
		cin >> doubleInput;
		int integerInput;
		integerInput = static_cast<int>(doubleInput);

		if (cin.fail() || (doubleInput <= left) || (doubleInput >= right) || ((intFlag == true) && (ceil(doubleInput) != floor(doubleInput))) || ((multipleOf != 1) && ((integerInput % multipleOf) != 0))) {
			cout << msg_error << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			goodInput = true;
	} while (!goodInput);
	return doubleInput;
}

void val_char_lenght(char array[], int ary_size) {//input to char array with lenght validation
	bool correct = false;
	do {
		std::cin.getline(array, ary_size);
		if ((strlen(array) > ary_size - 1) || cin.fail()) {
			std::cout << "wrong input, try again" << std::endl;
			cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			correct = true;
	} while (!correct);
}