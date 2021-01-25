#include "binarySearchTree.h"
#include <vector>
#include<iostream>
#include "solve.h"

void test() {//test with int
    binarySearchTree<int, int> bst;

    /*while (true) {//testing destructor
        binarySearchTree<int, int> bst1;
        std::vector<int> test{ 8, 10, 14, 2, 6, 1, 13, 7, 4, 15, 5, 3 };//{23, 18, 27, 23, 16, 47, 46, 11, 18, 14};
        for (auto i : test)
            bst1.addNode(i, i);
    }*/

    std::vector<int> test{ 8, 10, 14, 2, 6, 1, 13, 7, 4, 15, 5, 3 };//{23, 18, 27, 23, 16, 47, 46, 11, 18, 14};
    for (auto i : test)
        bst.addNode(i, i);
    bst.forEach(preOrder, [](int& data, int key) {
        std::cout << key << " ";
        });
    std::cout << std::endl;

    bst.forEach(inOrder, [](int& data, int key) {
        std::cout << key << " ";
        });
    std::cout << std::endl;

    bst.forEach(postOrder, [](int& data, int key) {
        std::cout << key << " ";
        });
    std::cout << std::endl;

    std::cout << std::endl;
    int height = bst.height();
    for (int i = 0; i <= height; i++) {
        bst.forEachInLevel(i, [](int& data, int key) {
            std::cout << key << " ";
            });
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << *(bst.search(13)) << std::endl;

    bst.deleteNode(8);
    std::cout << std::endl;
    height = bst.height();
    for (int i = 0; i <= height; i++) {
        bst.forEachInLevel(i, [](int& data, int key) {
            std::cout << key << " ";
            });
        std::cout << std::endl;
    }
    std::cout << std::endl;

    bst.forEach(preOrder, [](int& data, int key) {
        std::cout << key << " ";
        });
    std::cout << std::endl;

    bst.forEach(inOrder, [](int& data, int key) {
        std::cout << key << " ";
        });
    std::cout << std::endl;

    bst.forEach(postOrder, [](int& data, int key) {
        std::cout << key << " ";
        });
    std::cout << std::endl;

    //std::cout << *(bst.search(2)) << std::endl;
}

int main() {
    bookTest();
    //test();
    return 0;
}
