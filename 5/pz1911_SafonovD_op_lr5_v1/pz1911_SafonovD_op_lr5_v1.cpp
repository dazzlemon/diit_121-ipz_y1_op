//Application behaves like a simple database it stores 3 default Software Engineer type structure with fields:
// Name, Company, Work Experience, skills structure type name software that contains next fields:
//Operating System, Programming Language, DataBase
//it has 6 main functions:
//1 - Adding new software enginner(program can store only 10 at time)
//2 - printing list of all software engineers
//3 - printing list of software engineers with chosen work expirience
//4 - printing list of software engineers with biggest work expirience
//5 - printing list of software engineers with chosen name
//6 - printing list of all softare engineers sorted  by work expirience
#include <iostream>
#include <iomanip>
#include "inp_val6.h"
#include <Windows.h>
#include <string>
#include <limits>
#include "SE_list_manip.h"
#undef max

int main()
{
	const int size = 10;
	SE_ SE[size]{ //declared in SE_list_manip.h
		{"George Washington", "SpaceX", 521, {"Kali linux", "C++", "SQL"}}, 
		{"Joseph Joestar", "Atari", 176, {"Arch Linux", "Java", "MongoDB"} },
		{"John Watson", "IBM", 938, {"Windows 10", "Ruby", "Oracle"} }
	};
	int SE_amount = 3;

	int menu_choice;
	do
	{
#pragma region output menu
		std::cout << "1. Add software engineer." << std::endl;
		std::cout << "2. Output list of software engineers." << std::endl;//E
		std::cout << "3. Output software engineers with chosen work expirience." << std::endl;//D
		std::cout << "4. Output software engineers with biggest work expirience." << std::endl;//C
		std::cout << "5. Output chosen software engineer." << std::endl;//B
		std::cout << "6. Output list of software engineers sorted by work expirience." << std::endl;//A
		std::cout << "7. Exit." << std::endl;
#pragma endregion
		char msg_invite[] = "Choose what you want to do:";
		char msg_error[] = "Wrong input, try again";
		menu_choice = cinum(msg_invite, msg_error, 1, 1, 1, 7);
		
		switch (menu_choice)
		{
		case 1:
		{
			system("cls");
			std::cout << "Adding new software engineer..." << std::endl;
			std::cout << "input name(can't be longer than 23 characters):" << std::endl;
			std::cin.get();//deleting enter from stream after menu_choice
			val_char_lenght(SE[SE_amount].Name, 24);
			std::cout << "input company:" << std::endl;
			val_char_lenght(SE[SE_amount].Company, 24);
			char msg_invite2[] = "input work expirience(in days):";
			SE[SE_amount].WE = cinum(msg_invite2, msg_error, 1, 1, 0);
			cin.get();
			std::cout << "input operating system:" << std::endl;
			val_char_lenght(SE[SE_amount].software.OS, 12);
			std::cout << "input programming language:" << std::endl;
			val_char_lenght(SE[SE_amount].software.CodeLang, 8);
			std::cout << "input database:" << std::endl;
			val_char_lenght(SE[SE_amount].software.DB, 8);

			SE_amount++;
			break;
		}
		case 2:
		{
			std::system("cls");
			print_heading();
			for (int i = 0; i < SE_amount; i++) {
				print_SE(SE, i);
			}
			print_ending();
			break;
		}
		case 3:
		{
			std::system("cls");
			int chosen_WE;
			char msg_invite1[] = "input what work expirience you are searching for:";
			chosen_WE = cinum(msg_invite1, msg_error, 1, 1, 0);
			print_heading();
			for (int i = 0; i < SE_amount; i++) {
				if (SE[i].WE == chosen_WE) {//checking if current Work Expirience == chosen_WE
					print_SE(SE, i);
				}
			}
			print_ending();
			break;
		}
		case 4:
		{
			SE_list_sort(SE, SE_amount);
			std::system("cls");
			print_heading();
			bool next = true;
			for (int i = SE_amount - 1;next && i >= 0; i--) {//reading from big to small
				next = false;
				if (SE[i].WE == SE[SE_amount - 1].WE) {
					print_SE(SE, i);
					next = true;// if current != biggest than it's smaller, that means all next elements are smaller, so we can stop on the current one
				}
			}
			print_ending();
			break;
		}
		case 5:
		{
			std::system("cls");
			char chosen_Name[24];
			std::cin.get();
			std::cout << "input what name you are searching for:" << std::endl;
			val_char_lenght(chosen_Name, 24);
			print_heading();
			for (int i = 0; i < SE_amount; i++) {
				bool chosen = true;
				for (int j = 0;chosen && (SE[i].Name[j] != '\0') && (chosen_Name[j] != '\0'); j++) {
					if (SE[i].Name[j] != chosen_Name[j]) {//cheking name one char by the tame if chars are different going to another name
						chosen = false;
					}
				}
				
				if (chosen) {
					print_SE(SE, i);
				}
			}
			print_ending();
			break;
		}
		case 6:
		{
			SE_list_sort(SE, SE_amount);
			std::system("cls");
			print_heading();
			for (int i = 0; i < SE_amount; i++) {
				print_SE(SE, i);
			}
			print_ending();
			break;
		}
		case 7:
		{
			break;
		}
		default:
		{
			std::cout << "Wrong input, try again" << std::endl;
		}
		}
	} while (menu_choice != 7);

	std::system("pause");
	return 0;
}
