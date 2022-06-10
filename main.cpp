#include <iostream>
#include "MyArray.h"
#include "MyList.h"
#include "BinaryHeap.h"
#include "AVLTree.h"
#include "RBTree.h"
#include "random"
#include "Tester.h"
#include <fstream>
#include <chrono>
#include "Menu.h"
using namespace std;



int main() {
    srand(time(0));
    int input;
    Menu menu;
    cout << "Jaka strukture chcesz utworzyc? \n"
            "1 - Tablica \n"
            "2 - Lista \n"
            "3 - Kopiec binarny \n"
            "4 - Drzewo czerwono-czarne \n"
            "5 - Drzewo AVL \n";
    cin >> input;

    switch (input) {
        case 1:
            menu.arrayMenu();
            break;
        case 2:
            menu.listMenu();
            break;
        case 3:
            menu.heapMenu();
            break;
        case 4:
            menu.treeMenu1();
            break;
        case 5:
            menu.treeMenu();
            break;
    }
    return 0;
}



