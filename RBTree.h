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
        if(!root){
            std::cout << "Struktura jest pusta\n\n";
            return;
        }
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

    Node* findSibling(Node* node) {
        if(!node -> parent)
            return nullptr;
        if(isOnLeft(node))
            return node -> parent -> rightChild;
        else
            return node -> parent -> leftChild;
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

    // find node that replaces a deleted node in BST
    Node* BSTreplace(Node *x) {
        // when node have 2 children
        if (x->leftChild and x->rightChild)
            return findSuccessor(x);

        // when leaf
        if (!x->leftChild and !x->rightChild)
            return nullptr;

        // when single child
        if (x->leftChild)
            return x->leftChild;
        else
            return x->rightChild;
    }

    void fixDoubleBlack(Node *x) {
        if (x == root)
            // Reached root
            return;

        Node *sibling = findSibling(x), *parent = x->parent;
        if (!sibling) {
            // No sibiling, double black pushed up
            fixDoubleBlack(parent);
        } else {
            if (sibling->isRed) {
                // Sibling red
                parent->isRed = true;
                sibling->isRed = false;
                if (isOnLeft(sibling)) {
                    // left case
                    rightRotate(parent);
                } else {
                    // right case
                    leftRotate(parent);
                }
                fixDoubleBlack(x);
            } else {
                // Sibling black
                if ((sibling -> leftChild and sibling->leftChild -> isRed)
                    or (sibling -> rightChild and sibling -> rightChild -> isRed)) {
                    // at least 1 red children
                    if (sibling->leftChild and sibling->leftChild->isRed) {
                        if (isOnLeft(sibling)) {
                            // left left
                            sibling->leftChild->isRed = sibling->isRed;
                            sibling->isRed = parent->isRed;
                            rightRotate(parent);
                        } else {
                            // right left
                            sibling->leftChild->isRed = parent->isRed;
                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    } else {
                        if (isOnLeft(sibling)) {
                            // left right
                            sibling->rightChild->isRed = parent->isRed;
                            leftRotate(sibling);
                            rightRotate(parent);
                        } else {
                            // right right
                            sibling->rightChild->isRed = sibling->isRed;
                            sibling->isRed = parent->isRed;
                            leftRotate(parent);
                        }
                    }
                    parent->isRed = false;
                } else {
                    // 2 black children
                    sibling->isRed = true;
                    if (!parent->isRed)
                        fixDoubleBlack(parent);
                    else
                        parent->isRed = false;
                }
            }
        }
    }

    // deletes the given node
    void deleteNode(Node *v) {
        Node *u = BSTreplace(v);

        // True when u and v are both black
        bool uvBlack = ((u == nullptr or !u->isRed) and (!v->isRed));
        Node *parent = v->parent;

        if (u == nullptr) {
            // u is nullptr therefore v is leaf
            if (v == root) {
                // v is root, making root nullptr
                root = nullptr;
            } else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (findSibling(v))
                        // sibling is not nullptr, make it red
                        findSibling(v) -> isRed = true;
                }

                // delete v from the tree
                if (isOnLeft(v)) {
                    parent->leftChild = nullptr;
                } else {
                    parent->rightChild = nullptr;
                }
            }
            delete v;
            return;
        }

        if (v->leftChild == nullptr or v->rightChild == nullptr) {
            // v has 1 child
            if (v == root) {
                // v is root, assign the value of u to v, and delete u
                v->data = u->data;
                v->leftChild = v->rightChild = nullptr;
                delete u;
            } else {
                // Detach v from tree and move u up
                if (isOnLeft(v)) {
                    parent->leftChild = u;
                } else {
                    parent->rightChild = u;
                }
                delete v;
                u->parent = parent;
                if (uvBlack) {
                    // u and v both black, fix double black at u
                    fixDoubleBlack(u);
                } else {
                    // u or v red, color u black
                    u-> isRed = false;
                }
            }
            return;
        }

        // v has 2 children, swap values with successor and recurse
        swapValues(u, v);
        deleteNode(u);
    }


    void swapValues(Node *u, Node *v) {
        int temp;
        temp = u->data;
        u->data = v->data;
        v->data = temp;
    }

    // check if node is left child of parent
    bool isOnLeft(Node* node) { return node == node -> parent->leftChild; }
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
