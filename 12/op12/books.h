#ifndef __BOOKS_H__
#define __BOOKS_H__
//header implementing book structure needed for testing of binary search tree class

#include "binarySearchTree.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

struct bookData {
	std::string author;
	std::string name;
};

std::string bookToStr(bookData& data, int& year) {
	return data.name + " by " + data.author + " in " + std::to_string(year);
}

//print string of books (bookName by bookAuthor in releaseYear/n)
void printBooksPostOrder(binarySearchTree<int, bookData>& bookshelf) {
	int enumerator = 1;
	bookshelf.forEach(postOrder, [&](bookData& data, int year) {
		std::cout << enumerator << ". " << bookToStr(data, year) << std::endl;
		enumerator++;
		});
}

//writes books: (name\0author\0year\0\n)//ofstream trunc
void writeBooksPostOrderTxt(binarySearchTree<int, bookData>& bookshelf, std::ofstream& file) {
	bookshelf.forEach(postOrder, [&](bookData& data, int year) {
		file << data.name << '\0' << data.author << '\0' << year << '\0' << '\n';
		});
}

//writes string to binary file formatted like: length of string, string
void putString(std::string& str,std::ofstream& file) {
	int size = str.size();
	file.write(reinterpret_cast<char*>(&size), sizeof(size));
	file.write(str.c_str(), size);
}

//writes books: (sizeof bookName, bookName, sizeof author, author, year)//ofstream trunc bin
void writeBooksPostOrderBin(binarySearchTree<int, bookData>& bookshelf, std::ofstream& file) {
	bookshelf.forEach(postOrder, [&](bookData& data, int year) {
		putString(data.name, file);
		putString(data.author, file);
		file.write(reinterpret_cast<char*>(&year), sizeof(year));
		});
}

void readTxtUntilNULL(std::string& buffer, std::ifstream& file) {
	buffer = "";
	char currentChar;
	file >> std::noskipws >> currentChar;//by default whitespaces(ws) considered as invalid char's
	while (currentChar != EOF && currentChar != '\0') {
		buffer += currentChar;
		file >> currentChar;//serves as file peek too
	}
}

//reads books formattedlike that: name\0author\0year\0\n //ifstream
void readBooksTxt(binarySearchTree<int, bookData>& bookshelf, std::ifstream& file) {
	bookData book;
	int year;
	std::string yearStr;
	while (file.peek() != EOF && !file.eof()) {
		readTxtUntilNULL(book.name, file);
		readTxtUntilNULL(book.author, file);
		readTxtUntilNULL(yearStr, file);
		year = std::stoi(yearStr);//unsecure(exceptions)
		file.get();//read one more char \n or EOF
		bookshelf.addNode(book, year);
	}
}

//reads string from binary file formatted like: length of string, string
std::string getString(std::ifstream& file) {
	int size;
	file.read(reinterpret_cast<char*>(&size), sizeof(size));
	char* buffer = new char[size];
	file.read(buffer, size);
	std::string ret = "";
	ret.append(buffer, size);
	delete[]buffer;
	return ret;
}

//reads books formattedlike that: sizeof bookName, bookName, sizeof author, author, year //ifstream bin
void readBooksBin(binarySearchTree<int, bookData>& bookshelf, std::ifstream& file) {
	bookData book;
	int year;
	while (file.peek() != EOF && !file.eof()) {
		book.name = getString(file);
		book.author = getString(file);
		file.read(reinterpret_cast<char*>(&year), sizeof(year));
		bookshelf.addNode(book, year);
	}
}
#endif