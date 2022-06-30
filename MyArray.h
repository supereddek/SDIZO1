//
// Created by super on 10.05.2022.
//

#ifndef UNTITLED_MYARRAY_H
#define UNTITLED_MYARRAY_H

#include <iostream>
#include <cstdio>

class MyArray {
private:
    int* data = nullptr;
    size_t arrSize = 0;

public:
    MyArray();
    ~MyArray();

    int operator[](const size_t index);
    int operator[](const size_t index) const;

private:
    void enlarge(bool isFirst = false);
    void reduce(bool isFirst = false);
    void moveRight(int index);
    void moveLeft(int index);

public:
    void deleteValue(int num);
    void addLast(int num);
    void addFirst(int num);
    void insertAt(int num, int index);
    void deleteAt(int index);
    void deleteLast();
    void deleteFirst();
    bool contains(int num);
    void print();
    void clear();
    size_t getSize();
    void swap(size_t firstIndex, size_t secondIndex);
};




#endif //UNTITLED_MYARRAY_H
