//
// Created by super on 22.05.2022.
//

#ifndef UNTITLED_BINARYHEAP_H
#define UNTITLED_BINARYHEAP_H

#include "MyArray.h"
#include <cstdio>
#include <iostream>



class BinaryHeap {
private:
    MyArray data;

public:
    BinaryHeap() = default;

    void add(int num) {
        data.addLast(num);
        fixUpward(data.getSize() - 1);
    }

    //todo optimize
    void printTree(size_t nextIndex = 0, int pos = 0) {
        if (nextIndex >= data.getSize()) {
            for(int i=0; i<pos; i++) std::cout << "\t";
            std::cout << "*" << std::endl;
            return;
        }
        printTree(getRightChildOf(nextIndex), pos+1);
        for(int i=0; i<pos; i++) std::cout << "\t";
        std::cout << data[nextIndex] <<std::endl;
        printTree(getLeftChildOf(nextIndex),pos+1);

        std::cout << std:: endl << std::endl;
    }

    //delete at index, root is default
    void deleteAt(size_t index = 0) {
        if (index >= data.getSize()) {
            throw std::out_of_range("Deleting element outside of range!");
        }
        data.swap(index, data.getSize() - 1);
        data.deleteLast();
        fixDownward(index);
    }

    bool contains(int num) {
        data.contains(num);
    }

    void deleteVal(int num) {
        if(contains(num)) {
            size_t index = getIndexOf(num);
            data.swap(index, data.getSize() - 1);
            data.deleteLast();
            fixDownward(index);
        }
    }



private:
    size_t getParentOf(size_t childIndex) {
        return (childIndex-1) / 2;
    }

    size_t getLeftChildOf(size_t parentIndex) {
        return parentIndex * 2 + 1;
    }

    size_t getRightChildOf(size_t parentIndex) {
        return parentIndex * 2 + 2;
    }

    void fixUpward(size_t pos) {
        while (pos != 0) {
            if (data[pos] > data[getParentOf(pos)]) {
                data.swap(pos, getParentOf(pos));
            }
            pos = getParentOf(pos);
        }
    }

    void fixDownward(size_t pos) {
        size_t size = data.getSize();
        size_t largest = pos;
        //check if has at least one child
        //check if left child has bigger value
        if(getLeftChildOf(pos) < size && data[getLeftChildOf(pos)] > data[largest])
            largest = getLeftChildOf(pos);

        //check if right child has bigger value
        if(getRightChildOf(pos) < size && data[getRightChildOf(pos)] > data[largest])
            largest = getRightChildOf(pos);

        //check if any child is bigger and swap if needed
        if(largest == pos) return;
        else {
            data.swap(largest, pos);
            fixDownward(largest);
            }
    }

    size_t getIndexOf(int num) {
        for(size_t i = 0; i < data.getSize(); i ++) {
            if(data[i] == num) return i;
        }
    }

};


#endif //UNTITLED_BINARYHEAP_H
