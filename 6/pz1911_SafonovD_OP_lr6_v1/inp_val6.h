//cinum - numerical only (R)
//char msg_invite - your message for inviting user to input their number
//char msg_error - if error input occures
//int m_ - check if input is multiple of this number
//bool intFlag - =1(only integer input); =0(any input)
//double left - leftmost point in diapasone for input
//double right - rightmost point in diapasone for input

#include <iostream>
#include <windows.h>
#undef max
#include <cmath>
#include <climits>

using namespace std;

int cinum(char* msg_invite, char* msg_error, int m_ = 1, bool intFlag = 0, float left = -2147483648.0, float right = 2147483647.0)
{

	bool i = 0;
	float aaa;
	cout << msg_invite << endl;

	do 
	{
		cin >> aaa;
		int iaaa;
		iaaa = (int)aaa;

		if (cin.fail() || (aaa < left) || (aaa > right) || ((intFlag == 1) && (ceil(aaa) != floor(aaa))) || ((m_ != 1) && ((iaaa % m_) != 0))) {
			cout << msg_error << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			i = 1;
		}
	} while (!i);

	return (int)aaa;
}

void val_char_lenght(char array[], int ary_size) {//input to char array with lenght validation
	bool correct = false;
	do
	{
		std::cin.getline(array, 24);
		if ((array[ary_size - 1] != '\0') || cin.fail()) {
			std::cout << "wrong input, try again" << std::endl;
			cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			correct = true;
		}
	} while (!correct);
}