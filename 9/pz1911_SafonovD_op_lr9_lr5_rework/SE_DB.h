#ifndef __SE_DB_H__
#define __SE_DB_H__

#define SE_size sizeof(SE_)//?

#include <iomanip>
#include <iostream>
#include <fstream>
#include <random>//
#include <chrono>//
#include <vector>

struct skills {
	char OS[12];
	char CodeLang[8];
	char DB[8];
};

struct SE_ {//SE - SoftwareEngineer
	char Name[24];
	char Company[24];
	int WE;//WE - WorkExpirience
	skills software;
};

void addSE(std::fstream& SEdatabase, SE_& SEtmp);
void printSElist(std::fstream& SEdatabase);
//saves indexes of SEs with chosen WE
void searchByWE(std::vector<int>& indexes, std::fstream& SEdatabase, int chosenWE);
//saves indexes of SEs with highest WE to indexes
void highestWE(std::vector<int>& indexes, std::fstream& SEdatabase);
//saves indexes of SEs with chosen name to indexes
void searchByName(std::vector<int>& indexes, std::fstream& SEdatabase, char chosenName[24]);
void sortByWE(std::fstream& SEdatabase);
void printByIndexes(std::vector<int>& indexes, std::fstream& SEdatabase);
void printHeading();//
void printEnding();//
void printSE(SE_& SE);
//fills file with some SEs(random)
void SE_DBfill(std::fstream& tmp);
#endif