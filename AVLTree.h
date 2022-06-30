//
// Created by super on 23.05.2022.
//

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H

#include <cstdio>
#include <iostream>

class AVLTree {
    struct Node {
        int data;
        size_t height = 1;
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;

        Node(int data);
        ~Node();
    };
    Node* root = nullptr;



public:
    AVLTree() = default;
    void add(int num);
    void remove(int num);
    void printTree();
    bool contains(int num);
    void clear();



private:
    int height(Node *node);
    //higher node means closer to the root
    //lower node becomes higher node
    Node* rightRotate(Node* higherNode);
    //higher node means closer to the root
    //lower node becomes higher node
    Node* leftRotate(Node* higherNode);
    Node* insertNode(Node *root, int num);
    // Delete a node
    Node *deleteNode(Node *root, int num);
    void printTree(Node* root, std::string indent, bool last);
    int getBalanceFactor(Node* node);
    // Node with minimum value
    Node* findSuccessor(Node *node);
    Node* rebalance(Node* node);
    void clear(Node* root);


};


#endif //UNTITLED_AVLTREE_H
