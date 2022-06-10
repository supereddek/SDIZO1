//
// Created by super on 09.06.2022.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include <iostream>
#include <fstream>
#include "MyArray.h"

using namespace std;
class Menu {
    fstream myFile;
    string fileName;
    int input;
    int num;
    int amount;

public:
    void arrayMenu() {
        MyArray test;
        input = getArrayInput();
        while (input != 0) {
            switch (input) {
                case 1:
                    cout << "Pierwsza wczytana liczba musi zawierac rozmiar struktury.\n "
                            "Podaj nazwe pliku (z rozszerzeniem): ";
                    cin >> fileName;
                    myFile.open(fileName, ios::in);
                    myFile >> amount;
                    for (int i = 0; i < amount; i ++) {
                        myFile >> num;
                        test.addLast(num);
                    }
                    break;

                case 2:
                    cout << "Podaj rozmiar struktury" << endl;
                    int size;
                    cin >> size;
                    for (int i = 0; i < size; i ++) {
                        test.addLast(rand());
                    }
                    cout << "Utworzono strukture.\n";
                    break;

                case 3:
                    int index;
                    cout << "Jaka liczbe chesz dodac?\n";
                    cin >> num;
                    cout << "Podaj indeks, na ktorym ma zostac umieszczona liczba (-1 doda na ostanie miejsce)\n";
                    cin >> index;
                    test.add(num, index);
                    break;

                case 4:
                    cout << "Jaka liczbe chcesz usuanc?\n";
                    cin >> num;
                    test.deleteValue(num);
                    break;

                case 5:
                    cout << "Jaka liczbe chcesz wyszukac?\n";
                    cin >> num;
                    test.contains(num);
                    break;

                case 6:
                    test.print();
                    break;
                default:
                    cout << "Wprowadzono niewlasciwa wartosc!\n";
            }
            input = getArrayInput();
        }
    }

    void listMenu() {
        MyList test;
        input = getListInput();
        while (input != 0) {
            switch (input) {
                case 1:
                    cout << "Pierwsza wczytana liczba musi zawierac rozmiar struktury.\n "
                            "Podaj nazwe pliku (z rozszerzeniem): ";
                    cin >> fileName;
                    myFile.open(fileName, ios::in);
                    myFile >> amount;
                    for (int i = 0; i < amount; i ++) {
                        myFile >> num;
                        test.addLast(num);
                    }
                    break;

                case 2:
                    cout << "Podaj rozmiar struktury" << endl;
                    int size;
                    cin >> size;
                    for (int i = 0; i < size; i ++) {
                        test.addLast(rand());
                    }
                    cout << "Utworzono strukture.\n";
                    break;
                case 3:
                    cout << "Jaka liczbe chesz dodac?\n";
                    cin >> num;
                    test.addFirst(num);
                    break;
                case 4:
                    cout << "Jaka liczbe chesz dodac?\n";
                    cin >> num;
                    test.addLast(num);
                    break;
                case 5:
                    int index;
                    cout << "Jaka liczbe chesz dodac?\n";
                    cin >> num;
                    cout << "Na ktore miejsce chcesz dodac liczbe?\n";
                    cin >> index;
                    test.insertAt(num, index);
                    break;
                case 6:
                    test.deleteFirst();
                    break;
                case 7:
                    test.deleteLast();
                    break;
                case 8:
                    cout << "Podaj indeks, z ktorego zostanie usuniety element.\n";
                    cin >> index;
                    if(index < 0) {
                        cout << "Niewlasciwa wartosc!\n";
                    } else {
                        test.deleteAt(index);
                    }
                    break;
                case 9:
                    cout << "Jaka liczbe chcesz usunac?\n";
                    cin >> num;
                    test.deleteValue(num);
                    break;
                case 10:
                    cout << "Jaka liczbe chcesz wyszukac?\n";
                    cin >> num;
                    test.contains(num);
                    break;
                case 11:
                    test.display();
                    break;
                default:
                    cout << "Niewlasciwa wartosc!\n";
                    break;
            }
            input = getListInput();
        }
    }

    void treeMenu() {
        AVLTree test;
        input = getTreeInput();
        while (input != 0) {
            switch (input) {
                case 1:
                    cout << "Pierwsza wczytana liczba musi zawierac rozmiar struktury.\n "
                            "Podaj nazwe pliku (z rozszerzeniem): ";
                    cin >> fileName;
                    myFile.open(fileName, ios::in);
                    myFile >> amount;
                    for (int i = 0; i < amount; i ++) {
                        myFile >> num;
                        test.add(num);
                    }
                    break;

                case 2:
                    cout << "Podaj rozmiar struktury" << endl;
                    int size;
                    cin >> size;
                    for (int i = 0; i < size; i ++) {
                        test.add(rand());
                    }
                    cout << "Utworzono strukture.\n";
                    break;

                case 3:
                    cout << "Jaka liczbe chesz dodac?\n";
                    cin >> num;
                    test.add(num);
                    break;
                case 4:
                    cout << "Jaka liczbe chcesz usuanc?\n";
                    cin >> num;
                    test.remove(num);
                    break;

                case 5:
                    cout << "Jaka liczbe chcesz wyszukac?\n";
                    cin >> num;
                    if(test.contains(num))
                        cout << endl << num << " znajduje sie w drzewie!\n";
                    else
                        cout << endl << num << " nie ma w drzewie.\n";
                    break;
                case 6:
                    test.printTree();
                    break;
                default:
                    cout << "Wprowadzono niewlasciwa wartosc!\n";
            }
            input = getTreeInput();
        }
    }

    void treeMenu1() {
        RBTree test;
        input = getTreeInput();
        while (input != 0) {
            switch (input) {
                case 1:
                    cout << "Pierwsza wczytana liczba musi zawierac rozmiar struktury.\n "
                            "Podaj nazwe pliku (z rozszerzeniem): ";
                    cin >> fileName;
                    myFile.open(fileName, ios::in);
                    myFile >> amount;
                    for (int i = 0; i < amount; i ++) {
                        myFile >> num;
                        test.add(num);
                    }
                    break;

                case 2:
                    cout << "Podaj rozmiar struktury" << endl;
                    int size;
                    cin >> size;
                    for (int i = 0; i < size; i ++) {
                        test.add(rand());
                    }
                    cout << "Utworzono strukture.\n";
                    break;

                case 3:
                    cout << "Jaka liczbe chesz dodac?\n";
                    cin >> num;
                    test.add(num);
                    break;
                case 4:
                    cout << "Jaka liczbe chcesz usuanc?\n";
                    cin >> num;
                    test.remove(num);
                    break;

                case 5:
                    cout << "Jaka liczbe chcesz wyszukac?\n";
                    cin >> num;
                    if(test.contains(num))
                        cout << endl << num << " znajduje sie w drzewie!\n";
                    else
                        cout << endl << num << " nie ma w drzewie.\n";
                    break;
                case 6:
                    test.printTree();
                    break;
                default:
                    cout << "Wprowadzono niewlasciwa wartosc!\n";
            }
            input = getTreeInput();
        }
    }

    void heapMenu() {
        BinaryHeap test;
        input = getHeapInput();
        while (input != 0) {
            switch (input) {
                case 1:
                    cout << "Pierwsza wczytana liczba musi zawierac rozmiar struktury.\n "
                            "Podaj nazwe pliku (z rozszerzeniem): ";
                    cin >> fileName;
                    myFile.open(fileName, ios::in);
                    myFile >> amount;
                    for (int i = 0; i < amount; i ++) {
                        myFile >> num;
                        test.add(num);
                    }
                    break;

                case 2:
                    cout << "Podaj rozmiar struktury" << endl;
                    int size;
                    cin >> size;
                    for (int i = 0; i < size; i ++) {
                        test.add(rand());
                    }
                    cout << "Utworzono strukture.\n";
                    break;

                case 3:
                    cout << "Jaka liczbe chesz dodac?\n";
                    cin >> num;
                    test.add(num);
                    break;
                case 4:
                    cout << "Jaka liczbe chcesz usuanc?\n";
                    cin >> num;
                    test.deleteValue(num);
                    break;
                case 5:
                    test.deleteAt();
                    break;
                case 6:
                    cout << "Jaka liczbe chcesz wyszukac?\n";
                    cin >> num;
                    if(test.contains(num))
                        cout << endl << num << " znajduje sie w drzewie!\n";
                    else
                        cout << endl << num << " nie ma w drzewie.\n";
                    break;
                case 7:
                    test.printTree();
                    break;
                default:
                    cout << "Wprowadzono niewlasciwa wartosc!\n";
            }
            input = getHeapInput();
        }
    }

    int getHeapInput() {
        int option;
        cout << "Co chcesz zrobic?\n"
                "1 - Dodaj dane z pliku\n"
                "2 - Utworz losowo\n"
                "3 - Dodaj element\n"
                "4 - Usun liczbe \n"
                "5 - Usun korzen\n"
                "6 - Znajdz element\n"
                "7 - Wyswietl strukture\n"
                "0 - wyjdz\n";
        cin >> option;
        return option;
    }

    int getTreeInput() {
        int option;
        cout << "Co chcesz zrobic?\n"
                "1 - Dodaj dane z pliku\n"
                "2 - Utworz losowo\n"
                "3 - Dodaj element\n"
                "4 - Usun liczbe \n"
                "5 - Znajdz element\n"
                "6 - Wyswietl strukture\n"
                "0 - wyjdz\n";
        cin >> option;
        return option;
    }


    int getListInput() {
        int option;
        cout << "Co chcesz zrobic?\n"
                "1 - Dodaj dane z pliku\n"
                "2 - Utworz losowo\n"
                "3 - Dodaj element na poczatek\n"
                "4 - Dodaj element na koniec\n"
                "5 - Dodaj element na zadany indeks\n"
                "6 - Usun pierwszy element\n"
                "7 - Usun ostatni element\n"
                "8 - Usun element o zadanym indeksie\n"
                "9 - Usun liczbe\n"
                "10 - Znajdz element\n"
                "11 - Wyswietl strukture\n"
                "0 - wyjdz\n";
        cin >> option;
        return option;
    }

    int getArrayInput() {
        int option;
        cout << "Co chcesz zrobic?\n"
                "1 - Dodaj dane z pliku\n"
                "2 - Utworz losowo\n"
                "3 - Dodaj element\n"
                "4 - Usun liczbe \n"
                "5 - Znajdz element\n"
                "6 - Wyswietl strukture\n"
                "0 - wyjdz\n";
        cin >> option;
        return option;
    }
};

#endif //UNTITLED_MENU_H