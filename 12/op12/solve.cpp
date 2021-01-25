#include "solve.h"
#include "binarySearchTree.h"
#include "books.h"
#include <string>
#include <vector>
#include <utility>//pair

void bookTest() {
	std::cout << "Test1: adding nodes and printing them:" << std::endl;
	std::vector<std::pair<int, bookData>> bookshelfVec{
		{1988, {"Stephen Hawking", "A Brief History of Time"}},
		{2001, {"Stephen Hawking", "The Universe in a Nutshell"}},
		{1993, {"Stephen Hawking", "Black Holes and Baby Universes"}},
		{1892, {"Arthur Conan Doyle", "The Adventures of Sherlock Holmes"}},
		{2019, {"Daniel Teslenko", "Against all odds. The way to success"}},
		{1922, {"James Joyce", "Ulysses"}},
	};
	binarySearchTree<int, bookData> bookshelfBST;//int year
	for (auto book : bookshelfVec) {
		bookshelfBST.addNode(book.second, book.first);
	}
	printBooksPostOrder(bookshelfBST);
	std::cout << std::endl;

	std::cout << "Test2: deleting a node(2019) and printing again:" << std::endl;
	bookshelfBST.deleteNode(2019);//teslenko
	printBooksPostOrder(bookshelfBST);
	std::cout << std::endl;

	std::cout << "Test3: writing to txt file, deleting whole tree, then trying to print:" << std::endl;
	//write to txt file (ofstream << toString())
	std::ofstream outFile;
	outFile.open("books.txt", std::ios::trunc);
	writeBooksPostOrderTxt(bookshelfBST, outFile);
	outFile.close();
	bookshelfBST.clear();
	printBooksPostOrder(bookshelfBST);

	std::cout << "Test4: reading from txt file, printing:" << std::endl;
	//read from txt file (ifstream >> addNode())
	std::ifstream inFile;
	inFile.open("books.txt");
	readBooksTxt(bookshelfBST, inFile);
	inFile.close();
	printBooksPostOrder(bookshelfBST);
	std::cout << std::endl;

	std::cout << "Test5: writing to bin file, deleting whole tree, then trying to print:" << std::endl;
	//write to bin file (ofstream << toString())
	outFile.open("books.txt", std::ios::binary | std::ios::trunc);
	writeBooksPostOrderBin(bookshelfBST, outFile);
	outFile.close();
	bookshelfBST.clear();
	printBooksPostOrder(bookshelfBST);

	std::cout << "Test6: reading from bin file, printing:" << std::endl;
	//read from bin file (ifstream >> addNode())
	inFile.open("books.txt", std::ios::binary);
	readBooksBin(bookshelfBST, inFile);
	inFile.close();
	printBooksPostOrder(bookshelfBST);
	std::cout << std::endl;

	std::cout << "Test7: level traversal(printing each level):" << std::endl;
	int height = bookshelfBST.height();
	for (int i = 1; i <= height; i++) {
		std::cout << "level " << i << std::endl;
		bookshelfBST.forEachInLevel(i, [](bookData& data, int year) {
			std::cout << bookToStr(data, year) << std::endl;
		});
	}
}