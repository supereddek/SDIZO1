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
    void clear();
    void printTree();
    void add(int num);
    //delete at index, root is default
    void deleteAt(size_t index = 0);
    bool contains(int num);
    void deleteValue(int num);

private:
    void printTree(size_t firstIndex, std::string indent, bool last);
    size_t getParentOf(size_t childIndex);
    size_t getLeftChildOf(size_t parentIndex);
    size_t getRightChildOf(size_t parentIndex);
    void fixUpward(size_t pos);
    void fixDownward(size_t pos);
    //returns -1 if value not found
    size_t getIndexOf(int num);

};


#endif //UNTITLED_BINARYHEAP_H
