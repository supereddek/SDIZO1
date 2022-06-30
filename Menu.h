//
// Created by super on 09.06.2022.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include <iostream>
#include <fstream>
#include "MyArray.h"
#include "MyList.h"
#include "AVLTree.h"
#include "RBTree.h"
#include "BinaryHeap.h"

using namespace std;
class Menu {
    fstream myFile;
    string fileName;
    int input;
    int num;
    int amount;

public:
    void arrayMenu();
    int getBasicInput();
    void listMenu();
    void treeMenu();
    void treeMenu1();
    void heapMenu();
    int getHeapInput();
    int getTreeInput();
};

#endif //UNTITLED_MENU_H
