//
// Created by super on 22.05.2022.
//

#include "BinaryHeap.h"

void BinaryHeap::add(int num) {
    data.addLast(num);
    fixUpward(data.getSize() - 1);
}

void BinaryHeap::deleteAt(size_t index) {
    if (index >= data.getSize()) {
        std::cout << "Niewlasciwa operacja\n";
        return;
    }
    data.swap(index, data.getSize() - 1);
    data.deleteLast();
    fixDownward(index);
}

void BinaryHeap::deleteValue(int num) {
    size_t index = getIndexOf(num);
    if(index != -1) {
        data.swap(index, data.getSize() - 1);
        data.deleteLast();
        fixDownward(index);
    }

}



void BinaryHeap::printTree() {
    if(data.getSize() == 0) {
        std::cout << "Struktura jest pusta.\n\n";
        return;
    }
    printTree(0, "", true);
    std::cout << std::endl;
}

void BinaryHeap::printTree(size_t firstIndex, std::string indent, bool last) {
    // print the tree structure on the screen
    if (firstIndex < data.getSize()) {
        std::cout<<indent;
        if (last) {
            std::cout<<"R----";
            indent += "     ";
        } else {
            std::cout<<"L----";
            indent += "|    ";
        }

        std::cout<<"("<<data[firstIndex] << ")" <<std::endl;
        printTree(getLeftChildOf(firstIndex), indent, false);
        printTree(getRightChildOf(firstIndex), indent, true);
    }
}

bool BinaryHeap::contains(int num) {
    data.contains(num);
}

size_t BinaryHeap::getRightChildOf(size_t parentIndex) {
    return parentIndex * 2 + 2;
}

size_t BinaryHeap::getLeftChildOf(size_t parentIndex) {
    return parentIndex * 2 + 1;
}

size_t BinaryHeap::getIndexOf(int num) {
    for(size_t i = 0; i < data.getSize(); i ++) {
        if(data[i] == num) return i;
    }
    return -1;
}

size_t BinaryHeap::getParentOf(size_t childIndex) {
    return (childIndex-1) / 2;
}

void BinaryHeap::clear() {
    data.clear();
}

void BinaryHeap::fixDownward(size_t pos) {
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

void BinaryHeap::fixUpward(size_t pos) {
    while (pos != 0) {
        if (data[pos] > data[getParentOf(pos)]) {
            data.swap(pos, getParentOf(pos));
        }
        pos = getParentOf(pos);
    }
}

