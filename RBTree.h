//
// Created by super on 25.05.2022.
//
#ifndef UNTITLED_RBTREE_H
#define UNTITLED_RBTREE_H


#include <cstdio>
#include <iostream>

class RBTree {

    struct Node{
        int data = 0;
        Node* parent = nullptr;
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;
        bool isRed = true;

        Node(int num, Node* parent);
        Node(bool isRed);
        ~Node();

    };
    Node* root = nullptr;
    Node* nullNode = new Node(false);

public:
    RBTree() = default;
    void clear();
    void add(int num);
    void remove(int num);
    void printTree();
    bool contains(int num);

private:
    Node* findParent(int num);
    Node* findUncle(Node* node);
    Node* findSibling(Node* node);
    void printTree(Node* root, std::string indent, bool last);
    void fixInsert(Node* node);
    void rightRotate(Node* higherNode);
    void leftRotate(Node* higherNode);
    Node* getMinimumValue (Node* node);
    Node* findSuccessor (Node* node);
    // find node that replaces a deleted node in BST
    Node* BSTreplace(Node *x);
    void fixDoubleBlack(Node *x);
    // deletes the given node
    void deleteNode(Node *v);
    void swapValues(Node *u, Node *v);
    // check if node is left child of parent
    bool isOnLeft(Node* node);
    Node* findRBT (int num);
    void clear(Node* root);

};


#endif //UNTITLED_RBTREE_H
