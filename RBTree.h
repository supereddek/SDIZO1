//
// Created by super on 25.05.2022.
//

#ifndef UNTITLED_RBTREE_H
#define UNTITLED_RBTREE_H


#include <cstdio>
#include <iostream>

class RBTree {

    struct Node{
        int data;
        Node* parent = nullptr;
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;
        bool isRed = true;

        Node(int num, Node* parent) {
            this -> data = num;
            this -> parent = parent;
        }
        Node(bool isRed) {
            this -> isRed = isRed;
        }

        ~Node(){
            this -> data = 0;
            this -> leftChild = nullptr;
            this -> rightChild = nullptr;
        }


    };
    Node* root = nullptr;
    Node* nullNode = new Node(false);



public:
    RBTree() = default;

    void clear() {
        clear(root);
        root = nullptr;
    }

    void add(int num) {
        //create new node and assign to a parent
        Node* newNode = new Node(num, findParent(num));

        //if there's no parent, new node is root
        //if there's a parent it determines on which site should be attached
        if(!newNode -> parent)  {
            root = newNode;
            root -> isRed = false;
            return; //no fix is needed
        } else if(newNode -> parent -> data < newNode -> data) {
            newNode -> parent -> rightChild = newNode;
        } else {
            newNode -> parent -> leftChild = newNode;
        }

        //fix may be needed if there's a grandparent
        if(newNode -> parent -> parent) {
            fixInsert(newNode);
        }
    }

    void remove(int num) {
        Node* node = findRBT(num);
        if(node) deleteNode(node);
    }

    void printTree(){
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

private:
    Node* findParent(int num) {
        Node* newParent = nullptr;
        Node* temp = root;
        while (temp) {
            newParent = temp;
            if(num < temp -> data) temp = temp -> leftChild;
            else temp = temp -> rightChild;
            }
        return newParent;
    }

    Node* findUncle(Node* node) {
        if(node -> parent == node -> parent -> parent -> rightChild)
            return node -> parent -> parent -> leftChild;
        else if(node -> parent == node -> parent -> parent -> leftChild)
            return node -> parent -> parent -> rightChild;
        else return nullNode;
    }

    void printTree(Node* root, std::string indent, bool last) {
        // print the tree structure on the screen
        if (root) {
            std::cout<<indent;
            if (last) {
                std::cout<<"R----";
                indent += "     ";
            } else {
                std::cout<<"L----";
                indent += "|    ";
            }

            std::string sColor = root->isRed?"RED":"BLACK";
            std::cout<<"("<<root->data<<sColor<<")"<<std::endl;
            printTree(root->leftChild, indent, false);
            printTree(root->rightChild, indent, true);
        }
    }

    //todo
    void fixInsert(Node* node) {
        Node* uncle = (findUncle(node) ? findUncle(node) : nullNode);
        while (node -> parent -> isRed){
            if(uncle -> isRed) {
                uncle -> isRed = false;
                node -> parent -> isRed = false;
                node -> parent -> parent -> isRed = true;
                node = node -> parent -> parent;
            } else {
                //uncle is black or null
                //check if parent node is right child
                if(node -> parent == node -> parent -> parent -> rightChild) {
                    if(node == node -> parent -> leftChild ) {
                        node = node ->parent;
                        rightRotate(node );
                    }
                    node -> parent -> isRed = false;
                    node -> parent -> parent -> isRed = true;
                    leftRotate(node -> parent -> parent);
                } else {
                    //parent is leftChildchild
                    if(node == node -> parent -> rightChild ) {
                        node = node -> parent;
                        leftRotate(node);
                    }
                    node -> parent -> isRed = false;
                    node -> parent -> parent -> isRed = true;
                    rightRotate(node -> parent -> parent);
                }
            }

            if(node == root) {
                node -> isRed = false;
                break;
            }
        }
    }

    ///todo
    void rightRotate(Node* higherNode) {
        Node* lowerNode = higherNode->leftChild;
        higherNode->leftChild = lowerNode->rightChild;
        if (lowerNode->rightChild) {
            lowerNode->rightChild->parent = higherNode;
        }
        lowerNode->parent = higherNode->parent;
        if (higherNode->parent == nullptr) {
            this->root = lowerNode;
        } else if (higherNode == higherNode->parent->rightChild) {
            higherNode->parent->rightChild = lowerNode;
        } else {
            higherNode->parent->leftChild = lowerNode;
        }
        lowerNode->rightChild = higherNode;
        higherNode->parent = lowerNode;
    }

    void leftRotate(Node* higherNode) {
        Node* lowerNode = higherNode->rightChild;
        higherNode->rightChild = lowerNode->leftChild;
        if (lowerNode->leftChild) {
            lowerNode->leftChild->parent = higherNode;
        }
        lowerNode->parent = higherNode->parent;
        if (higherNode->parent == nullptr) {
            this->root = lowerNode;
        } else if (higherNode == higherNode->parent->leftChild) {
            higherNode->parent->leftChild = lowerNode;
        } else {
            higherNode->parent->rightChild = lowerNode;
        }
        lowerNode->leftChild = higherNode;
        higherNode->parent = lowerNode;
    }

    Node* getMinimumValue (Node* node ) {
            while( node->leftChild ) node = node->leftChild;
        return node;
    }

    Node* findSuccessor (Node* node)
    {
        Node* successor;
        if(node) {
            if( node->rightChild)
                return getMinimumValue(node->rightChild);
            else {
                successor = node-> parent;
                while(( successor) && (node == successor->rightChild ) )
                {
                    node = successor;
                    successor = successor-> parent;
                }
                return successor;
            }
        }
        return nullptr;
    }

    void deleteNode ( Node * X )
    {
        Node * W = nullptr;
        Node * Y = nullptr;
        Node * Z = nullptr;

        if( ( X->leftChild == nullptr ) || ( X->rightChild == nullptr ) ) Y = X;
        else Y = findSuccessor(X);

        if( Y->leftChild) Z = Y->leftChild;
        else Z = Y->rightChild;

        Z->parent = Y->parent;

        if( !Y->parent) root = Z;
        else if( Y == Y->parent->leftChild) Y->parent->leftChild = Z;
        else Y->parent->rightChild = Z;

        if( Y != X ) X->data = Y->data;

        if( !Y->isRed)   // Naprawa struktury drzewa czerwono-czarnego
            while( ( Z != root ) && Z && ( !(Z -> isRed)) )
                if( Z == Z->parent->leftChild)
                {
                    W = Z->parent->rightChild;

                    if( W-> isRed )
                    {              // Przypadek 1
                        W->isRed = false;
                        Z->parent->isRed = true;
                         leftRotate( Z->parent );
                        W = Z->parent->rightChild;
                    }

                    if( ( !W->leftChild->isRed ) && ( !W->rightChild->isRed ) )
                    {              // Przypadek 2
                        W->isRed = true;
                        Z = Z->parent;
                        continue;
                    }

                    if( !W->rightChild->isRed )
                    {              // Przypadek 3
                        W->leftChild->isRed = false;
                        W->isRed = true;
                        rightRotate( W );
                        W = Z->parent->rightChild;
                    }

                    W->isRed = Z->parent->isRed; // Przypadek 4
                    Z->parent->isRed = false;
                    W->rightChild->isRed = false;
                    leftRotate( Z->parent );
                    Z = root;      // To spowoduje zakończenie pętli
                }
                else
                {                // Przypadki lustrzane
                    W = Z->parent->leftChild;

                    if( W->isRed)
                    {              // Przypadek 1
                        W->isRed = false;
                        Z->parent->isRed;
                        rightRotate( Z->parent );
                        W = Z->parent->leftChild;
                    }

                    if( ( !W->leftChild->isRed) && ( !W->rightChild->isRed) )
                    {              // Przypadek 2
                        W->isRed = true;
                        Z = Z->parent;
                        continue;
                    }

                    if( !W->leftChild->isRed )
                    {              // Przypadek 3
                        W->rightChild->isRed = false;
                        W->isRed = true;
                        leftRotate( W );
                        W = Z->parent->leftChild;
                    }

                    W->isRed = Z->parent->isRed;  // Przypadek 4
                    Z->parent->isRed = false;
                    W->leftChild->isRed = false;
                    rightRotate( Z->parent );
                    Z = root;      // To spowoduje zakończenie pętli
                }

                if(Z) Z->isRed = false;

        delete Y;
    }

    Node* findRBT ( int k )
    {
        Node * p;

        p = root;
        while( ( p) && ( p->data != k ) )
            if( k < p->data ) p = p->leftChild;
            else           p = p->rightChild;
        if(!p) return nullptr;
        return p;
    }

    void clear(Node* root) {
        if(root -> leftChild)
            clear(root -> leftChild);
        if(root -> rightChild)
            clear(root -> rightChild);
        delete root;
    }

};


#endif //UNTITLED_RBTREE_H
