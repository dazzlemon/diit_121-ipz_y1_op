//cinum - numerical only (R)
//char msg_invite - your message for inviting user to input their number
//char msg_error - if error input occures
//int m_ - check if input is multiple of this number
//bool intFlag - =1(only integer input); =0(any input)
//double left - leftmost point in diapasone for input
//double right - rightmost point in diapasone for input

class input_validation {
public:
	static int cinum(char* msg_invite, char* msg_error, int m_ = 1, bool intFlag = 0, float left = -2147483648.0, float right = 2147483647.0);

	static void val_char_lenght(char array[], int ary_size);
};
