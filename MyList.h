//
// Created by super on 18.05.2022.
//

#ifndef UNTITLED_MYLIST_H
#define UNTITLED_MYLIST_H
#include <iostream>

class MyList {
private:
    struct Node {
        int data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;

public:
    MyList() = default;


    void display();
    void addFirst(int num);

    void addLast(int num);

    //Inserts element BEFORE elem at given index
    void insertAt(int num, size_t index);

    void deleteFirst();

    void deleteLast();

    void deleteAt(size_t index);


    bool contains(int num);

    void deleteValue(int num);
    void clear();
private:
    Node* getNodeAt(size_t index);

    Node* getNode(int num);

    void deleteNode(Node* node);

};


#endif //UNTITLED_MYLIST_H
