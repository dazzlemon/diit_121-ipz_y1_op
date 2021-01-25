//Application demonstartes ways of argument passing
//function prototypes are in funcs.h file
//function definitions are in funcs.cpp file

#include "funcs.h"
#include <iostream>

int main()
{
	//
	char ms1[] = "MS1";
	myStruct MS1{ 1, 'a', true, ms1 };//, new char[3]};

	MS1.print();
	MS1.Int = func_int_char_bool::int_value(MS1.Int, MS1.Char, MS1.Bool);
	MS1.print();
	std::cout << std::endl;

	MS1.print();
	char char_example1 = func_int_char_bool::char_reference(MS1.Int, MS1.Char, MS1.Bool);//self name is a reference too
	std::cout << "char example = " << char_example1 << std::endl;
	MS1.print();
	std::cout << std::endl;

	MS1.print();
	func_int_char_bool::void_pointer(&(MS1.Int), &(MS1.Char), &(MS1.Bool));
	MS1.print();
	std::cout << std::endl;

	MS1.print();
	int* example_intp = func_int_char_bool::intp_value(MS1.Int, MS1.Char, MS1.Bool);
	std::cout << "pointer to integer example = " << example_intp << std::endl;
	MS1.print();
	std::cout << std::endl;

	MS1.print();
	char* example_charp = func_int_char_bool::charp_reference(MS1.Int, MS1.Char, MS1.Bool);//self name is a reference too
	std::cout << "pointer to character example = " << static_cast<void*>(example_charp) << std::endl;//to print char* it has to be casted to other type*
	MS1.print();
	std::cout << std::endl;


	
	int Iarray[5]{3, 5, 2, 1, 4};
	func_srv::print_int_ar(Iarray, (sizeof(Iarray) / sizeof(*Iarray)));
	func_num_ar::void_reference(Iarray);
	func_srv::print_int_ar(Iarray, (sizeof(Iarray) / sizeof(*Iarray)));
	std::cout << std::endl;

	func_srv::print_int_ar(Iarray, (sizeof(Iarray) / sizeof(*Iarray)));
	func_num_ar::void_pointer(Iarray, (sizeof(Iarray) / sizeof(*Iarray)));
	func_srv::print_int_ar(Iarray, (sizeof(Iarray) / sizeof(*Iarray)));
	std::cout << std::endl;

	MS1.print();
	myStruct MS2 = func_struct::MS_value(MS1);
	char ms2[] = "MS2";
	MS2.id = ms2;
	//std::cout << std::endl;
	MS2.print();
	//std::cout << std::endl;
	MS1.print();
	std::cout << std::endl;

	MS1.print();
	MS2 = *(func_struct::MSp_reference(MS1));
	MS2.id = ms2;
	MS2.print();
	std::cout << std::endl;

	MS1.print();
	MS2 = func_struct::MSr_pointer(&MS1);
	MS2.id = ms2;
	MS2.print();
	std::cout << std::endl;

	char char_array[]{'e', 'a', 'd', 'b', 'c'};
	func_srv::print_char_ar(char_array, (sizeof(char_array) / sizeof(*char_array)));
	func_char_ar::void_reference(char_array);
	func_srv::print_char_ar(char_array, (sizeof(char_array) / sizeof(*char_array)));
	std::cout << std::endl;

	char char_array2[]{'e', 'a', 'd', 'b', 'c'};
	func_srv::print_char_ar(char_array2, (sizeof(char_array2) / sizeof(*char_array2)));
	func_char_ar::void_pointer(char_array2, (sizeof(char_array2) / sizeof(*char_array2)));
	func_srv::print_char_ar(char_array2, (sizeof(char_array2) / sizeof(*char_array2)));

	system("pause");
	return 0;
}
