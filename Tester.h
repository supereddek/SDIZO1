//
// Created by super on 25.05.2022.
//

#ifndef UNTITLED_TESTER_H
#define UNTITLED_TESTER_H
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Tester {
    fstream myFile;

public:
    Tester() {
        srand(time(0));
    }

    void generateNumbers(int amount,int min, int max) {
        myFile.open("numbers.txt", ios::out);
        if(myFile.is_open()) {
            //myFile << amount << endl;
            for(int i = 0; i < amount; i++)
            myFile << rand() << endl;
        }
        myFile.close();
    }
};


#endif //UNTITLED_TESTER_H
