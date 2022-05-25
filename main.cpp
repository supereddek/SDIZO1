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


int main() {
    srand(time(0));
    fstream myFile;
    Tester tester;
    tester.generateNumbers(40000,INT_MIN, INT_MIN + 1000);
    myFile.open("numbers.txt", ios::in);
    AVLTree list;
    int amount;
    int num;
    myFile >> amount;
    for(int i = 0; i < amount; i ++) {
        myFile >> num;
        list.add(num);
    }

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 100; i ++) {
        list.add(rand());
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << duration.count();

    return 0;
}

