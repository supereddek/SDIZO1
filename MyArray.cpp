//
// Created by super on 10.05.2022.
//

#include "MyArray.h"
#include <iostream>
#include <cstdio>

MyArray::MyArray() {
    data = nullptr;
    arrSize = 0;
}

MyArray::~MyArray()  {
    free(data);
    data = nullptr;
    arrSize = 0;
}

void MyArray::reduce(bool isFirst)  {
    if (arrSize == 0) return;
    size_t newSize = arrSize - 1;
    int* newArray = new int[newSize];

    std::copy(data + isFirst, data + newSize + isFirst, newArray);
    arrSize = newSize;
    delete[]data;
    data = newArray;
}

void MyArray::enlarge(bool isFirst) {
    size_t newSize = arrSize +1;
    int* newArray = new int[newSize];

    std::copy(data, data + arrSize, newArray + isFirst);
    arrSize = newSize;
    delete[] data;
    data = newArray;
}

void MyArray::moveLeft(int index) {
    size_t newSize = arrSize - 1;
    int* newArray = new int[newSize];

    std::copy(data,data + index, newArray);
    std::copy(data + index + 1, data + arrSize, newArray + index);

    arrSize = newSize;
    delete[]data;
    data = newArray;
}

void MyArray::moveRight(int index) {
    size_t newSize = arrSize + 1;
    int* newArray = new int[newSize];

    std::copy(data,data + index, newArray);
    std::copy(data + index, data + arrSize, newArray + index + 1);

    arrSize = newSize;
    delete[]data;
    data = newArray;
}

void MyArray::addFirst(int num) {
    enlarge(true);
    data[0] = num;
}

void MyArray::addLast(int num) {
    enlarge();
    data[arrSize-1] = num;
};

void MyArray::insertAt(int num, int index) {
    if (index > arrSize || index < 0) {
        std::cout << "Index out of range!" << std::endl;
        return;
    }
    moveRight(index);
    data[index] = num;
}

void MyArray::deleteFirst() {
    reduce(true);
}

void MyArray::deleteLast() {
    reduce();
}

void MyArray::deleteValue(int num) {
    for (int i = 0; i < arrSize; i ++) {
        if(num == data[i]) {
            moveLeft(i);
            std::cout << "Usunieto wartosc " << num << " z indeksu " << i << std::endl;
            return;
        }
    }
    std::cout << "Nie ma takiej wartosci!" << std::endl;
}

void MyArray::deleteAt(int index) {
    if (index >= arrSize) {
        std::cout << "Index out of range!" << std::endl;
        return;
    }
    moveLeft(index);
}

bool MyArray::contains(int num) {
    for(int i = 0; i < arrSize; i++) {
        if(data[i] == num) {
            std::cout << "Znaleziono na indeksie nr " << i << std::endl;
            return true;
        }
    }
    std::cout << "Nie znaleziono.\n";
    return false;
}

void MyArray::print() {
    std::cout << "[ ";
    for(int i = 0; i < arrSize; i++) {
        std::cout << data[i] << ", ";
    }
    std::cout<< "]" << std::endl;
}

void MyArray::clear(){
    std::fill(data, data + arrSize, 0);
    arrSize = 0;
    delete[] data;
    data = nullptr;
}

size_t MyArray::getSize() {
    return arrSize;
}

void MyArray::swap(size_t firstIndex, size_t secondIndex) {
    int temp = data[firstIndex];
    data[firstIndex] = data[secondIndex];
    data[secondIndex] = temp;
}


int MyArray::operator[](const size_t index) {
    if (index >= arrSize)
        throw std::out_of_range("Array index out of range");
    return data[index];
}

int MyArray::operator[](const size_t index) const {
    if (index >= arrSize)
        throw std::out_of_range("Array index out of range");
    return data[index];
}
