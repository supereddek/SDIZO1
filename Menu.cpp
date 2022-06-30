//
// Created by super on 30.06.2022.
//
#include "Menu.h"

int Menu::getBasicInput() {
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

void Menu::listMenu() {
    MyList test;
    input = getBasicInput();
    while (input != 0) {
        switch (input) {
            case 1:
                myFile.open("numbers.txt", ios::in);
                myFile >> amount;
                for (int i = 0; i < amount; i ++) {
                    myFile >> num;
                    test.addLast(num);
                }
                cout << "Utworzono strukture.\n";
                test.display();
                break;
            case 2:
                cout << "Podaj rozmiar struktury" << endl;
                int size;
                cin >> size;
                for (int i = 0; i < size; i ++) {
                    test.addLast(rand());
                }
                cout << "Utworzono strukture.\n";
                test.display();
                break;
            case 3:
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                test.addFirst(num);
                test.display();
                break;
            case 4:
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                test.addLast(num);
                test.display();
                break;
            case 5:
                int index;
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                cout << "Na ktore miejsce chcesz dodac liczbe?\n";
                cin >> index;
                test.insertAt(num, index);
                test.display();
                break;
            case 6:
                test.deleteFirst();
                test.display();
                break;
            case 7:
                test.deleteLast();
                test.display();
                break;
            case 8:
                cout << "Podaj indeks, z ktorego zostanie usuniety element.\n";
                cin >> index;
                if(index < 0) {
                    cout << "Niewlasciwa wartosc!\n";
                } else {
                    test.deleteAt(index);
                }
                test.display();
                break;
            case 9:
                cout << "Jaka liczbe chcesz usunac?\n";
                cin >> num;
                test.deleteValue(num);
                test.display();
                break;
            case 10:
                cout << "Jaka liczbe chcesz wyszukac?\n";
                cin >> num;
                cout << (test.contains(num) ? "Znaleziono\n" : "Nie znaleziono\n");
                test.display();
                break;
            case 11:
                test.display();
                break;
            default:
                cout << "Niewlasciwa wartosc!\n";
                break;
        }
        input = getBasicInput();
    }
}

void Menu::arrayMenu() {
    MyArray test;
    input = getBasicInput();
    while (input != 0) {
        switch (input) {
            case 1:
                myFile.open("numbers.txt", ios::in);
                myFile >> amount;
                for (int i = 0; i < amount; i ++) {
                    myFile >> num;
                    test.addLast(num);
                }
                cout << "Struktura utworzona.\n";
                test.print();
                break;

            case 2:
                cout << "Podaj rozmiar struktury" << endl;
                int size;
                cin >> size;
                for (int i = 0; i < size; i ++) {
                    test.addLast(rand());
                }
                cout << "Utworzono strukture.\n";
                test.print();
                break;

            case 3:
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                test.addFirst(num);
                test.print();
                break;

            case 4:
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                test.addLast(num);
                test.print();
                break;

            case 5:
                int index;
                cout << "Jaka liczbe chcesz dodac?\n";
                cin >> num;
                cout << "Na ktory indeks chcesz dodac liczbe?\n";
                cin >> index;
                test.insertAt(num, index);
                test.print();
                break;

            case 6:
                test.deleteFirst();
                test.print();
                break;

            case 7:
                test.deleteLast();
                test.print();
                break;
            case 8:
                cout << "Z ktorego miejsca chcesz usunac liczbe?\n";
                cin >> index;
                test.deleteAt(index);
                test.print();
                break;
            case 9:
                cout << "Jaka liczbe chcesz usunac?\n";
                cin >> num;
                test.deleteValue(num);
                test.print();
                break;
            case 10:
                cout << "Jaka liczbe chcesz wyszukac?\n";
                cin >> num;
                test.contains(num);
                break;
            case 11:
                test.print();
            default:
                cout << "Wprowadzono niewlasciwa wartosc!\n";
        }
        input = getBasicInput();
    }
}

int Menu::getTreeInput() {
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

void Menu::treeMenu() {
    AVLTree test;
    input = getTreeInput();
    while (input != 0) {
        switch (input) {
            case 1:
                myFile.open("numbers.txt", ios::in);
                myFile >> amount;
                for (int i = 0; i < amount; i ++) {
                    myFile >> num;
                    test.add(num);
                }
                test.printTree();
                break;

            case 2:
                cout << "Podaj rozmiar struktury" << endl;
                int size;
                cin >> size;
                for (int i = 0; i < size; i ++) {
                    test.add(rand());
                }
                cout << "Utworzono strukture.\n";
                test.printTree();
                break;

            case 3:
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                test.add(num);
                test.printTree();
                break;
            case 4:
                cout << "Jaka liczbe chcesz usuanc?\n";
                cin >> num;
                test.remove(num);
                test.printTree();
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

void Menu::treeMenu1() {
    RBTree test;
    input = getTreeInput();
    while (input != 0) {
        switch (input) {
            case 1:
                myFile.open("numbers.txt", ios::in);
                myFile >> amount;
                for (int i = 0; i < amount; i ++) {
                    myFile >> num;
                    test.add(num);
                }
                test.printTree();
                break;

            case 2:
                cout << "Podaj rozmiar struktury" << endl;
                int size;
                cin >> size;
                for (int i = 0; i < size; i ++) {
                    test.add(rand());
                }
                cout << "Utworzono strukture.\n";
                test.printTree();
                break;

            case 3:
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                test.add(num);
                test.printTree();
                break;
            case 4:
                cout << "Jaka liczbe chcesz usuanc?\n";
                cin >> num;
                test.remove(num);
                test.printTree();
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

void Menu::heapMenu()  {
    BinaryHeap test;
    input = getHeapInput();
    while (input != 0) {
        switch (input) {
            case 1:
                myFile.open("numbers.txt", ios::in);
                myFile >> amount;
                for (int i = 0; i < amount; i ++) {
                    myFile >> num;
                    test.add(num);
                }
                test.printTree();
                break;

            case 2:
                cout << "Podaj rozmiar struktury" << endl;
                int size;
                cin >> size;
                for (int i = 0; i < size; i ++) {
                    test.add(rand());
                }
                cout << "Utworzono strukture.\n";
                test.printTree();
                break;

            case 3:
                cout << "Jaka liczbe chesz dodac?\n";
                cin >> num;
                test.add(num);
                test.printTree();
                break;
            case 4:
                cout << "Jaka liczbe chcesz usuanc?\n";
                cin >> num;
                test.deleteValue(num);
                test.printTree();
                break;
            case 5:
                test.deleteAt();
                test.printTree();
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

int Menu::getHeapInput() {
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