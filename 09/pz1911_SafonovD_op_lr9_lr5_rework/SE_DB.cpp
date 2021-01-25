#include "SE_DB.h"

void addSE(std::fstream& SEdatabase, SE_& SEtmp) {
	SEdatabase.seekp(0, std::ios_base::end);
	SEdatabase.write(reinterpret_cast<char*>(&SEtmp), SE_size);
}

void printSElist(std::fstream& SEdatabase) {
	SEdatabase.seekg(0, std::ios_base::beg);
	SE_ SEtmp;
	printHeading();
	SEdatabase.read(reinterpret_cast<char*>(&SEtmp), SE_size);
	while (!SEdatabase.eof()) {
		printSE(SEtmp);
		SEdatabase.read(reinterpret_cast<char*>(&SEtmp), SE_size);
	} 
	printEnding();
	SEdatabase.clear();//clear eof
}

void searchByWE(std::vector<int>& indexes, std::fstream& SEdatabase, int chosenWE) {
	SEdatabase.seekg(0, std::ios_base::end);
	int length = SEdatabase.tellg() / SE_size;
	int currentWE;
	SEdatabase.seekg(0, std::ios_base::beg);
	for (int i = 0; i < length; i++) {//save indexes with chosen WE
		SEdatabase.seekg(48, std::ios_base::cur);
		SEdatabase.read(reinterpret_cast<char*>(&currentWE), sizeof(int));
		SEdatabase.seekg(28, std::ios_base::cur);//read only WE
		if (currentWE == chosenWE)
			indexes.push_back(i);
	}
}

void highestWE(std::vector<int>& indexes, std::fstream& SEdatabase) {
	SEdatabase.seekg(0, std::ios_base::end);
	int length = SEdatabase.tellg() / SE_size;
	int currentWE, highestWE = 0;
	SEdatabase.seekg(0, std::ios_base::beg);
	for (int i = 0; i < length; i++) {//find highest
		SEdatabase.seekg(48, std::ios_base::cur);
		SEdatabase.read(reinterpret_cast<char*>(&currentWE), sizeof(int));
		SEdatabase.seekg(28, std::ios_base::cur);//read only WE
		if (currentWE > highestWE)
			highestWE = currentWE;
	}
	searchByWE(indexes, SEdatabase, highestWE);
}

void searchByName(std::vector<int>& indexes, std::fstream& SEdatabase, char chosenName[24]) {
	SEdatabase.seekg(0, std::ios_base::end);
	int length = SEdatabase.tellg() / SE_size;
	SEdatabase.seekg(0, std::ios_base::beg);
	char currentName[24];
	for (int i = 0; i < length; i++) {//save indexes with chosen name
		SEdatabase.read(reinterpret_cast<char*>(&currentName), 24);
		SEdatabase.seekg(56, std::ios_base::cur);//read only WE
		if (!strcmp(currentName, chosenName))
			indexes.push_back(i);
	}
}

void printByIndexes(std::vector<int>& indexes, std::fstream& SEdatabase) {
	printHeading();
	SE_ currentSE;
	for (auto index : indexes) {
		SEdatabase.seekg(index * SE_size, std::ios_base::beg);
		SEdatabase.read(reinterpret_cast<char*>(&currentSE), SE_size);
		printSE(currentSE);
	}
	printEnding();
}

void sortByWE(std::fstream& SEdatabase) {//insertionSort
	SEdatabase.seekg(0, std::ios_base::end);
	int length = SEdatabase.tellg() / SE_size;
	SE_ SEtmp[2];
	for (int i = 1; i < length; i++) {
		SEdatabase.seekg((i - 1) * SE_size, std::ios_base::beg);
		SEdatabase.read(reinterpret_cast<char*>(&SEtmp[0]), SE_size);//arrayToSort[i - 1]
		SEdatabase.read(reinterpret_cast<char*>(&SEtmp[1]), SE_size);//arrayToSort[i]
		if (SEtmp[1].WE < SEtmp[0].WE) {//if !inplace
			int j = i - 1;
			for (j; (j >= 0) && (SEtmp[1].WE < SEtmp[0].WE); j--) {//arrayToSort[j + 1] = arrayToSort[j];//find position and shift to right elements between new and old position
				SEdatabase.seekp((j + 1) * SE_size, std::ios_base::beg);
				SEdatabase.write(reinterpret_cast<char*>(&SEtmp[0]), SE_size);
				if (j > 0) {
					SEdatabase.seekg((j - 1) * SE_size, std::ios_base::beg);//read j-th for next iteration
					SEdatabase.read(reinterpret_cast<char*>(&SEtmp[0]), SE_size);
				}
			}
			SEdatabase.seekp((j + 1) * SE_size, std::ios_base::beg);//arrayToSort[j + 1] = temp;
			SEdatabase.write(reinterpret_cast<char*>(&SEtmp[1]), SE_size);
		}
	}
}

void printHeading() {//
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

void printEnding() {//
	std::cout << std::setfill('-') << std::right;
	std::cout << std::setw(113) << "]" << std::endl;
	std::cout << std::setfill(' ') << std::left;
}

void printSE(SE_& SE) {//
	std::cout << std::setw(24) << SE.Name << " | ";
	std::cout << std::setw(24) << SE.Company << " | ";
	std::cout << std::setw(20) << SE.WE << " | ";
	std::cout << std::setw(12) << SE.software.OS << " | ";
	std::cout << std::setw(8) << SE.software.CodeLang << " | ";
	std::cout << std::setw(8) << SE.software.DB << " ] ";
	std::cout << std::endl;
}

void SE_DBfill(std::fstream& tmp) {
	std::uniform_int_distribution<int> valueDist(0, 2);
	std::default_random_engine gen(time(NULL));

	SE_ SEblck[3]{ {"George Washington", "SpaceX", 521, {"Kali linux", "C++", "SQL"}},
		{"Joseph Joestar", "Atari", 176, {"Arch Linux", "Java", "MongoDB"} },
		{"John Watson", "IBM", 938, {"Windows 10", "Ruby", "Oracle"} } };
	for (int i = 0; i < 5; i++)
		tmp.write(reinterpret_cast<char*>(&SEblck[valueDist(gen)]), SE_size);
}