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
#include <fstream>
#include <vector>
#include "SE_DB.h"
#include "inp_val7.h"

int main() {
	bool exit;
	do {
		char databaseFileName[256];//database.bin
		std::fstream SEdatabase;
		do {
			std::fill_n(databaseFileName, 256, 0);//0 = '\0'
			std::cout << "input address of file(or only name if it is in the same folder as programm) starting with disk:\\ and ending with *.txt: " << std::endl;
			std::cin.getline(databaseFileName, 255);
			SEdatabase.open(databaseFileName, /*std::ios::trunc | */std::ios::in | std::ios::out | std::ios::binary);//old file
			if (!SEdatabase.is_open())
				std::cout << "Can't open that file!" << std::endl;
		} while (!SEdatabase.is_open());
		//SE_DBfill(SEdatabase);//
		int choice;
		do {
			std::cout << "1. Add software engineer." << std::endl;
			std::cout << "2. Output list of software engineers." << std::endl;//E
			std::cout << "3. Output software engineers with chosen work expirience." << std::endl;//D
			std::cout << "4. Output software engineers with biggest work expirience." << std::endl;//C
			std::cout << "5. Output chosen software engineer." << std::endl;//B
			std::cout << "6. Output list of software engineers sorted by work expirience." << std::endl;//A
			std::cout << "7. Exit." << std::endl;

			choice = cinum("Choose what you want to do:", "Wrong input, try again", 1, 1, 1, 7);
			switch (choice) {
			case 1: {
				system("cls");
				SE_ SEtmp;
				std::cout << "Adding new software engineer..." << std::endl;
				std::cout << "input name(can't be longer than 23 characters):" << std::endl;
				std::cin.get();//deleting enter from stream after menu_choice
				val_char_lenght(SEtmp.Name, 24);
				std::cout << "input company:" << std::endl;
				val_char_lenght(SEtmp.Company, 24);
				SEtmp.WE = cinum("input work expirience(in days):", "Wrong input, try again", 1, 1, 0);
				cin.get();
				std::cout << "input operating system:" << std::endl;
				val_char_lenght(SEtmp.software.OS, 12);
				std::cout << "input programming language:" << std::endl;
				val_char_lenght(SEtmp.software.CodeLang, 8);
				std::cout << "input database:" << std::endl;
				val_char_lenght(SEtmp.software.DB, 8);
				addSE(SEdatabase, SEtmp);//tmp
				break;
			}
			case 2: {
				std::system("cls");
				printSElist(SEdatabase);
				break;
			}
			case 3: {
				std::system("cls");
				int chosenWE;//tmp
				chosenWE = cinum("input what work expirience you are searching for:", "Wrong input, try again", 1, 1, 0);
				std::vector<int> indexes;
				searchByWE(indexes, SEdatabase, chosenWE);
				printByIndexes(indexes, SEdatabase);
				break;
			}
			case 4: {
				std::system("cls");
				std::vector<int> indexes;
				highestWE(indexes, SEdatabase);
				printByIndexes(indexes, SEdatabase);
				break;
			}
			case 5: {
				std::system("cls");
				char chosenName[24];
				std::cin.get();
				std::cout << "input what name you are searching for:" << std::endl;
				val_char_lenght(chosenName, 24);
				std::vector<int> indexes;
				searchByName(indexes, SEdatabase, chosenName);
				printByIndexes(indexes, SEdatabase);
				break;
			}
			case 6: {
				std::system("cls");
				sortByWE(SEdatabase);
				printSElist(SEdatabase);
				break;
			}
			case 7: {
				break;
			}
			default: {
				std::cout << "Wrong input, try again" << std::endl;
				break;
			}
			}
		} while (choice != 7);

		char chExit;
		std::cout << "Do you want to exit the programm?(Y/N): ";
		std::cin >> chExit;
		while ((chExit != 'Y' && chExit != 'y' && chExit != 'N' && chExit != 'n') || (std::cin.peek() != '\n')) {//until correct input
			while (std::cin.get() != '\n');//clear istream
			std::cout << "wrong input, try again." << std::endl;
			std::cout << "Do you want to exit the programm?(Y/N): ";
			std::cin >> chExit;
		}
		if (chExit == 'Y' || chExit == 'y')
			exit = true;
		else
			exit = false;
		std::cin.get();//enter
	} while (!exit);

	std::system("pause");
	return 0;
}