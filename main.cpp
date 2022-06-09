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
    MyArray list;
    int num;
    size_t pos;
    int amounts[7] = {1000, 5000, 10000, 15000, 20000, 25000, 50000};

    fstream results;
    results.open("results_array.txt", ios::app);

    for (int i = 0; i < 7; i ++) {
        int result[100] = {};
        int sum = 0;
        results << "Operation for " << amounts[i] << endl;
        cout << "Making test for " << amounts[i] << endl;
        for (int k = 0; k < 100; k++) {
            //generating new numbers
            tester.generateNumbers(amounts[i], INT_MIN, INT_MAX);
            myFile.open("numbers.txt", ios::in);

            //filling the list
            for (int j = 0; j < amounts[i]; j++) {
                myFile >> num;
                list.addFirst(num);
            }
            myFile.close();
            num = rand();
            pos = rand() % amounts[i];
            auto start = std::chrono::high_resolution_clock::now();
            list.deleteLast();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            //results << duration.count() << endl;
            result[k] = duration.count();
            sum += result[k];
            list.clear();
        }
        results << sum / 100 << endl;
    }


    results.close();




    return 0;
}



