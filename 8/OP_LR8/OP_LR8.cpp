#include <cstdio>
#include <iostream>
#include "txtProcessing.h"
#include <vector>
#include <algorithm>

int main() {
	std::cout << "This application is the text redactor that opens *.txt files." << std::endl;
	std::cout << "Makes a copy of that file formatted so that one line contains one full sentence." << std::endl;
	std::cout << "It can scroll one sentence at the time, add new sentences and delete them." << std::endl;
	system("pause");
	system("cls");

	errno_t err;
	FILE* txtOLD, * txtNEW;
	char fileInName[256];//D:\1uno1\diit\year1\year1_semester2\WIP\OP_Lr8_almost\OP_LR8\test.txt
	bool exit;
	do {
		do {
			std::fill_n(fileInName, 256, 0);//0 = '\0'
			std::cout << "input address of file(or only name if it is in the same folder as programm) starting with disk:\\ and ending with *.txt: " << std::endl;
			std::cin.getline(fileInName, 255);
			err = fopen_s(&txtOLD, fileInName, "r+");//old file
			if (err)
				std::cout << "Can't open that file!" << std::endl;
		} while (err);

		char fileOutName[256];
		err = tmpnam_s(fileOutName, 255);
		if (!err) {
			err = fopen_s(&txtNEW, fileOutName, "w+");//resulting file
			if (!err) {
				copySentenceLines(txtOLD, txtNEW);
				std::vector<fpos_t> pointers{ 0 };
				int index = 0;
				int choice;
				do {
					system("cls");
					coutSentence(txtNEW, pointers, index);

					std::cout << std::endl;
					std::cout << "1. Insert new sentence before current." << std::endl;
					std::cout << "2. Insert new sentence after current." << std::endl;
					if (index < pointers.size() - 1)//if not last sentence in file
						std::cout << "3. Scroll to next sentence." << std::endl;
					if (index > 0)//if not 1st sentence in file
						std::cout << "4. Scroll to previous sentence." << std::endl;
					std::cout << "5. Delete this sentence" << std::endl;
					std::cout << "6. End work with file." << std::endl;

					std::cin >> choice;
					switch (choice) {
					case 1: {
						char sentence[256];
						std::fill_n(fileInName, 256, '\0');
						std::cin.get();//get enter
						std::cout << "Input new sentence: " << std::endl;
						std::cin.getline(sentence, 255);
						int i;
						for (i = 0; i < 256 && sentence[i] != '\0'; i++) {}
						insertSentence(txtNEW, sentence, pointers, index, i + 2);
						break;
					}
					case 2: {
						char sentence[256];
						std::fill_n(fileInName, 256, '\0');
						std::cin.get();//get enter
						std::cout << "Input new sentence: " << std::endl;
						std::cin.getline(sentence, 255);
						int i;
						for (i = 0; i < 256 && sentence[i] != '\0'; i++) {}
						if (index == pointers.size() - 2) {
							index++;
							coutSentence(txtNEW, pointers, index);
							insertSentence(txtNEW, sentence, pointers, index, i + 2);
							index--;
						}
						else
							insertSentence(txtNEW, sentence, pointers, index + 1, i + 2);
						break;
					}
					case 3: {
						if (index < pointers.size() - 1)
							index++;
						else {
							std::cout << "wrong input";
							system("pause");
						}
						break;
					}
					case 4: {
						if (index > 0)
							index--;
						else {
							std::cout << "wrong input";
							system("pause");
						}
						break;
					}
					case 5: {
						fclose(txtNEW);
						err = deleteSentence(fileOutName, pointers, index);
						if (!err)
							err = fopen_s(&txtNEW, fileOutName, "r+");
					}
					case 6:
						break;
					default: {
						std::cout << "wrong input";
						system("pause");
						break;
					}
					}
				} while (choice != 6 && !err);
			}
		}
		if (err)
			std::cout << "Error occured." << std::endl;
		else
			std::cout << "outputFile: " << fileOutName << std::endl;

		_fcloseall();
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

	system("pause");
	return 0;
}