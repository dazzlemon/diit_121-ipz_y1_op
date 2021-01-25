#include "SE_list_manip.h"
#include <iostream>
#include <iomanip>

void SE_list_manip::print_heading() {
	std::cout << std::left;
	std::cout << std::setw(24) << "Name" << " | ";
	std::cout << std::setw(24) << "Company" << " | ";
	std::cout << std::setw(20) << "Work Expirience" << " | ";
	std::cout << std::setw(12) << "OS" << " | ";
	std::cout << std::setw(8) << "CodeLang" << " | ";
	std::cout << std::setw(8) << "DataBase" << " ] ";
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::right;
	std::cout << std::setw(26) << "|";
	std::cout << std::setw(27) << "|";
	std::cout << std::setw(23) << "|";
	std::cout << std::setw(15) << "|";
	std::cout << std::setw(11) << "|";
	std::cout << std::setw(11) << "]";
	std::cout << std::endl;
	std::cout << std::setfill(' ') << std::left;
}

void SE_list_manip::print_ending() {
	std::cout << std::setfill('-') << std::right;
	std::cout << std::setw(113) << "]" << std::endl;
	std::cout << std::setfill(' ') << std::left;
}

void SE_list_manip::print_SE(struct SE_ SE[], int i) {
	std::cout << std::setw(24) << SE[i].Name << " | ";
	std::cout << std::setw(24) << SE[i].Company << " | ";
	std::cout << std::setw(20) << SE[i].WE << " | ";
	std::cout << std::setw(12) << SE[i].software.OS << " | ";
	std::cout << std::setw(8) << SE[i].software.CodeLang << " | ";
	std::cout << std::setw(8) << SE[i].software.DB << " ] ";
	std::cout << std::endl;
}

void SE_list_manip::SE_list_sort(struct SE_ SE[], int SE_amount) {//bubble sort
	bool sorted = false;
	for (int i = 0; !sorted && (i < (SE_amount - 2)); i++) {
		bool sorted = true;
		for (int j = 0; j < (SE_amount - i - 1); j++) {
			if (SE[j].WE > SE[j + 1].WE) {
				SE_ temp;
				temp = SE[j];
				SE[j] = SE[j + 1];
				SE[j + 1] = temp;

				sorted = false;
			}
		}
	}
}