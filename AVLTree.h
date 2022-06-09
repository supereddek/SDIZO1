//
// Created by super on 23.05.2022.
//

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H
#define SPACE 10
#include <cstdio>
#include <iostream>

class AVLTree {
    struct Node {
        int data;
        size_t height = 1;
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;

        Node(int data){
            this->data = data;
        }

        ~Node(){
            this -> data = 0;
            this -> leftChild = nullptr;
            this -> rightChild = nullptr;
        }

    };
    Node* root = nullptr;



public:
    AVLTree() = default;

    void add(int num) {
        root = insertNode(root, num);
    }

    void remove(int num) {
        root = deleteNode(root, num);
    }


    void printTree() {
        printTree(root, "", true);
        std::cout << std::endl;
    }


    bool contains(int num) {
            Node * temp = root;
            while (temp) {
                if (num == temp -> data) {
                    return temp;
                } else if (num < temp -> data) {
                    temp = temp -> leftChild;
                } else {
                    temp = temp -> rightChild;
                }
            }
            return false;
    }

    void clear() {
        clear(root);
        root = nullptr;
    }



private:
    int height(Node *node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    //higher node means closer to the root
    //lower node becomes higher node
    Node* rightRotate(Node* higherNode) {
        Node* lowerNode = higherNode -> leftChild;
        Node* optional = lowerNode -> rightChild;
        lowerNode-> rightChild = higherNode;
        higherNode -> leftChild = optional;
        higherNode -> height = std::max(height(higherNode->leftChild), height(higherNode->rightChild)) + 1;
        lowerNode -> height = std::max(height(lowerNode->leftChild),height(lowerNode->rightChild)) + 1;
        return lowerNode;
    }

    //higher node means closer to the root
    //lower node becomes higher node
    Node* leftRotate(Node* higherNode) {
        Node* lowerNode = higherNode -> rightChild;
        Node* optional = lowerNode -> leftChild;
        lowerNode -> leftChild = higherNode;
        higherNode -> rightChild = optional;
        higherNode -> height = std::max(height(higherNode->leftChild), height(higherNode->rightChild)) + 1;
        lowerNode -> height = std::max(height(lowerNode->leftChild), height(lowerNode->rightChild)) + 1;
        return lowerNode;
    }

    Node* insertNode(Node *root, int num) {
        // Find the correct postion and insert the root
        if (root == nullptr) {
            return new Node(num);
        }
        if (num <= root->data)
            root->leftChild = insertNode(root->leftChild, num);
        else if (num > root->data)
            root->rightChild = insertNode(root->rightChild, num);
        else
            return root;
        return rebalance(root);
    }

    // Delete a node
    Node *deleteNode(Node *root, int num) {
        // Find the node and delete it
        if (root == nullptr)
            return root;
        if (num < root->data)
            root-> leftChild = deleteNode(root-> leftChild, num);
        else if (num > root->data)
            root->rightChild = deleteNode(root->rightChild, num);

        //value found
        else {
            //one or zero children
            if ((root-> leftChild == nullptr) ||
                (root->rightChild == nullptr)) {
                //if there's no left child, there may be right one
                Node *temp = root-> leftChild ? root-> leftChild : root->rightChild;
                delete root;
                return temp;
            } else {
                //two children
                Node *temp = findSuccessor(root->rightChild);
                root->data = temp->data;
                root->rightChild = deleteNode(root->rightChild,temp->data);
            }
        }
        //rebalance if needed
        return rebalance(root);
    }



    void printTree(Node* root, std::string indent, bool last) {
        if (root) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            } else {
                std::cout << "L----";
                indent += "|  ";
            }
            std::cout << root->data << std::endl;
            printTree(root->leftChild, indent, false);
            printTree(root->rightChild, indent, true);
        }
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->leftChild) -
               height(node->rightChild);
    }

    // Node with minimum value
    Node* findSuccessor(Node *node) {
        Node *current = node;
        while (current->leftChild)
            current = current->leftChild;
        return current;
    }

    Node* rebalance(Node* node) {
        // Update the balance factor of each node and
        // balance the tree
        node->height = 1 + std::max(height(node->leftChild),
                                    height(node->rightChild));
        int balanceFactor = getBalanceFactor(node);
        //left imbalance
        if (balanceFactor > 1) {
            //left left imbalance
            if (node -> data > node->leftChild->data) {
                return rightRotate(node);
                //left right imbalance
            } else if (node -> data < node->leftChild->data) {
                node->leftChild = leftRotate(node->leftChild);
                return rightRotate(node);
            }
        }
        //right imbalance
        if (balanceFactor < -1) {
            //right right imbalance
            if (node -> data < node->rightChild->data) {
                return leftRotate(node);
                //right left imbalance
            } else if (node -> data > node->rightChild->data) {
                node->rightChild = rightRotate(node->rightChild);
                return leftRotate(node);
            }
        }
        return node;
    }

    void clear(Node* root) {
        if(root -> leftChild)
            clear(root -> leftChild);
        if(root -> rightChild)
            clear(root -> rightChild);
        delete root;
    }



};


#endif //UNTITLED_AVLTREE_H
