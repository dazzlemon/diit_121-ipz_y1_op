//each class represents set of function with same arguments(name of class), but these functions vary way of passing argument to them and return type(both in the name of function)


struct myStruct {//for passing to func
	int Int;
	char Char;
	bool Bool;
	char* id;
	void print();
	//add char array
	//add int array
};

class func_int_char_bool {
public: 
	static int int_value(int Int, char Char, bool Bool);//arguments passed by value, returns int, defined in funcs_r.cpp
	static char char_reference(int& rInt, char& rChar, bool& rBool);//arguments passed by reference, returns char, defined in funcs_r.cpp
	static void void_pointer(int* pInt, char* pChar, bool* pBool);//arguments passed by pointer, returns nothing, defined in funcs_r.cpp
	//E

	static int* intp_value(int Int, char Char, bool Bool);//arguments passed by value, returns int*, defined in funcs_r.cpp
	static char* charp_reference(int& rInt, char& rChar, bool& rBool);//arguments passed by reference, returns char*, defined in funcs_r.cpp
	//D
};

class func_num_ar {
public:
	//array passed by value, defined in funcs_r.cpp
	//todo: explain in report why array cant be passed by value!
	static void void_reference(int int_array[]);//array passed by reference, defined in funcs_r.cpp
	static void void_pointer(int* int_array0, int size);//array passed by pointer of first element, defined in funcs_r.cpp
	//C
};

class func_struct {
public:
	static myStruct MS_value(myStruct myStruct1);//struct passed by value
	static myStruct* MSp_reference(myStruct& myStruct1);//struct passed by reference, returns pointer
	static myStruct& MSr_pointer(myStruct* myStruct);//struct passed by pointer, returns refernce
	//B
};

class func_char_ar {
public:
	//array passed by value, defined in funcs_r.cpp
	//todo: explain in report why array cant be passed by value!
	static void void_reference(char char_array[]);//array passed by reference, defined in funcs_r.cpp
	static void void_pointer(char* char_array0, int size);//array passed by point, defined in funcs_r.cpp
	//A
};


class func_srv {
public:
	static void int_ar_bubble_sort(int* pArray0, int size);//to sort arrays 
	static void print_char_ar(char* pArray0, int size);
	static void ch_ar_bubble_sort(char* pArray0, int size);
	static void print_int_ar(int* pArray0, int size);
};
