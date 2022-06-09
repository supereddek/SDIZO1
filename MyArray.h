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
    MyArray() {
        data = nullptr;
        arrSize = 0;
    }

    //todo
    ~MyArray() {
        free(data);
        data = nullptr;
        arrSize = 0;
    }

    int operator[](const size_t index) {
        if (index >= arrSize)
            throw std::out_of_range("Array index out of range");
        return data[index];
    }

    int operator[](const size_t index) const {
        if (index >= arrSize)
            throw std::out_of_range("Array index out of range");
        return data[index];
    }

private:
    void enlarge(bool isFirst = false) {
        size_t newSize = arrSize +1;
        int* newArray = new int[newSize];

        std::copy(data, data + arrSize, newArray + isFirst);
        arrSize = newSize;
        delete[] data;
        data = newArray;
    }

    //offset = 1 jesli chcemy usunac 1 element
    void reduce(bool isFirst = false) {
        size_t newSize = arrSize - 1;
        int* newArray = new int[newSize];

        std::copy(data + isFirst, data + newSize + isFirst, newArray);
        arrSize = newSize;
        delete[]data;
        data = newArray;
    }

    //todo
    //offset = 1 dla dodawania i -1 dla usuwania
    void split(int index, int offset) {
        size_t newSize = arrSize + offset;
        int* newArray = new int[newSize];

        std::copy(data,data + index, newArray);
        std::copy(data + index, data + arrSize, newArray + index + offset);

        arrSize = newSize;
        delete[]data;
        data = newArray;
    }

    void moveRight(int index){
        size_t newSize = arrSize + 1;
        int* newArray = new int[newSize];

        std::copy(data,data + index, newArray);
        std::copy(data + index, data + arrSize, newArray + index + 1);

        arrSize = newSize;
        delete[]data;
        data = newArray;
    }

    void moveLeft(int index) {
        size_t newSize = arrSize - 1;
        int* newArray = new int[newSize];

        std::copy(data,data + index, newArray);
        std::copy(data + index + 1, data + arrSize, newArray + index);

        arrSize = newSize;
        delete[]data;
        data = newArray;
    }

public:

    //todo print
    void deleteValue(int num) {
        for (int i = 0; i < arrSize; i ++) {
            if(num == data[i]) {
                moveLeft(i);
                return;
            }
        }
        //std::cout << "Value not found!" << std::endl;
    }

    void addLast(int num) {
        enlarge();
        data[arrSize-1] = num;
    };


    void addFirst(int num) {
        enlarge(true);
        data[0] = num;
    }


    void insertAt(int num, int index) {
        if (index > arrSize) {
            std::cout << "Index out of range!" << std::endl;
            return;
        }
        //split(index, 1);
        moveRight(index);
        data[index] = num;
    }

    void deleteAt(int index){
        if (index >= arrSize) {
            std::cout << "Index out of range!" << std::endl;
            return;
        }
        moveLeft(index);
    };

    void deleteLast() {
        reduce();
    }

    void deleteFirst() {
        reduce(true);
    }

    bool contains(int num) {
        for(int i = 0; i < arrSize; i++) {
            if(data[i] == num) {
                //std::cout << "Found at: " << i << std::endl;
                return true;
            }
        }
        return false;
    };



    void print() {
        std::cout << "[ ";
        for(int i = 0; i < arrSize; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout<< "]" << std::endl;
    }

    void printLast() {
        std::cout << "Last element: " << data[arrSize - 1] << std::endl;
    }

    void clear() {
        std::fill(data, data + arrSize, 0);
        arrSize = 0;
        delete[] data;
        data = nullptr;
    }




    size_t getSize() {
        return arrSize;
    }

    void swap(size_t firstIndex, size_t secondIndex) {
        int temp = data[firstIndex];
        data[firstIndex] = data[secondIndex];
        data[secondIndex] = temp;
    }

};




#endif //UNTITLED_MYARRAY_H
