//specs
#include <iostream>
#include <iomanip>
#include "funcs.h"

int func_int_char_bool::int_value(int Int, char Char, bool Bool) {
	std::cout << "  arguments are passed by value" << std::endl;
	int temp = Int;
	temp *= 2;

	std::cout << "  returned int: " << temp << std::endl;
	return temp;
}

char func_int_char_bool::char_reference(int& Int, char& Char, bool& Bool) {
	std::cout << "  arguments are passed by reference" << std::endl;
	char temp = Char;
	temp += 4;

	Char += 2;
	
	std::cout << "  returned char: " << temp << std::endl;
	return temp;
}

void func_int_char_bool::void_pointer(int* pInt, char* pChar, bool* pBool) {
	std::cout << "  arguments are passed by pointer" << std::endl;
	bool temp = *pBool;
	temp = !temp;
	bool* ptemp = pBool;

	*pBool = !(*pBool);
}
//E

int* func_int_char_bool::intp_value(int Int, char Char, bool Bool) {
	std::cout << "  arguments are passed by value" << std::endl;

	std::cout << "  returned pointer to int: " << &Int << std::endl;
	return &Int;
}

char* func_int_char_bool::charp_reference(int& Int, char& Char, bool& Bool) {
	std::cout << "  arguments are passed by reference" << std::endl;

	std::cout << "  returned pointer to char: " << static_cast<void*>(&Char) << std::endl;//to print char* it has to be casted to other type*
	return &Char;
}
//D

void func_num_ar::void_reference(int int_array[]) {
	std::cout << "  array is passed by reference" << std::endl;
	int size = (sizeof(int_array) / sizeof(*int_array));
	double average{};
	for (int i = 0; i < size; i++) {
		average += int_array[i];
	}
	average /= size;
	std::cout << "  average = " << average << std::endl;
}

void func_num_ar::void_pointer(int* int_array0, int size) {
	std::cout << "  array is passed by pointer" << std::endl;

	func_srv::int_ar_bubble_sort(int_array0, size);
}
//C

myStruct func_struct::MS_value(myStruct myStruct1) {
	std::cout << "  structure is passed by value" << std::endl;

	//myStruct temp = myStruct1;
	myStruct1.Int *= -1;
	
	if (myStruct1.Char < 'a') {
		myStruct1.Char += 32;//to lowercase
	}
	else {
		myStruct1.Char -= 32;//to upper
	}

	myStruct1.Bool = !myStruct1.Bool;
	char MS[] = "MS_ret";
	myStruct1.id = MS;
	std::cout << "  returned structure:" << std::endl;
	myStruct1.print();
	return myStruct1;
}

myStruct* func_struct::MSp_reference(myStruct& myStruct1) {
	std::cout << "  structure is passed by reference" << std::endl;

	myStruct1.Int++;
	myStruct1.Char--;
	myStruct1.Bool = !(myStruct1.Bool);

	std::cout << "  returned pointer to structure: " << &myStruct1 << std::endl;
	return &myStruct1;
}

myStruct& func_struct::MSr_pointer(myStruct* myStruct1) {
	std::cout << "  structure is passed by pointer" << std::endl;

	(*myStruct1).Int++;
	(*myStruct1).Char--;
	(*myStruct1).Bool = !((*myStruct1).Bool);

	std::cout << "  adress returned reference to structure: " << &*myStruct1 << std::endl;
	return *myStruct1;
}
//B

void func_char_ar::void_reference(char char_array[]) {
	std::cout << "  array is passed by reference" << std::endl;
	func_srv::ch_ar_bubble_sort(&char_array[0], ((sizeof(char_array) / sizeof(*char_array)) + 1));
}

void func_char_ar::void_pointer(char* char_array0, int size) {
	std::cout << "  array is passed by pointer" << std::endl;
	func_srv::ch_ar_bubble_sort(char_array0, size);
}
//A

void myStruct::print() {
	std::cout << id << ".Int = " << Int << std::endl;
	std::cout << id << std::boolalpha << ".Bool = " << Bool << std::endl;//boolalpha to print True/False and not 1/0
	std::cout << id << ".Char = " << Char << std::endl;
}

void func_srv::int_ar_bubble_sort(int* pArray0, int size) {
	bool sorted = false;
	for (int i = 0; !sorted && (i < (size - 1)); i++) {
		bool sorted = true;
		for (int j = 0; j < (size - i - 1); j++) {
			if (pArray0[j] > pArray0[j + 1]) {

				int temp = pArray0[j];
				pArray0[j] = pArray0[j + 1];
				pArray0[j + 1] = temp;

				sorted = false;
			}
		}
	}
}

void func_srv::print_char_ar(char* pArray0, int size) {
	std::cout << "Array: ";
	for (int i = 0; i < size; i++) {
		std::cout << pArray0[i] << ' ';
	}
	std::cout << std::endl;
}

void func_srv::ch_ar_bubble_sort(char* pArray0, int size) {
	bool sorted = false;
	for (int i = 0; !sorted && (i < size - 1); i++) {
		bool sorted = true;
		for (int j = 0; j < (size - i - 1); j++) {
			if (pArray0[j] > pArray0[j + 1]) {

				char temp = pArray0[j];
				pArray0[j] = pArray0[j + 1];
				pArray0[j + 1] = temp;

				sorted = false;
			}
		}
	}
}

void func_srv::print_int_ar(int* pArray0, int size) {
	std::cout << "integer array = ";
	for (int i = 0; i < (size - 1); i++) {
		std::cout << pArray0[i] << ", ";
	}
	std::cout << pArray0[size - 1] << ';' << std::endl;
}