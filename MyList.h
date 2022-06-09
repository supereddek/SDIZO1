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


    void display() {
        Node* temp = head;
        while(temp) {
            std::cout << temp->data << " ";
            temp = temp -> next;
        }
        std::cout << std::endl;
    }

    void addFirst(int num) {
        Node* newElem = new Node();
        newElem -> data = num;

        newElem -> next = head;
        newElem -> prev = nullptr;

        //Check if empty. Head is null when list is empty so tail is also null.
        if(head != nullptr) {
            head->prev = newElem;
        } else {
            tail = newElem;
        }
        head = newElem;
    }

    void addLast(int num) {
        Node* newElem = new Node();
        newElem -> data = num;

        newElem -> prev = tail;
        newElem -> next = nullptr;

        //Check if empty. Head is null when list is empty so tail is also null.
        if(tail != nullptr) {
            tail -> next = newElem;
        } else {
            head = newElem;
        }
        tail = newElem;
    }

    void add(int num, size_t index) {
        Node *nextElem = getNodeAt(index);
        if(!nextElem) {
            std::cout << "Index out of range!" << std::endl;
            return;
        }

        Node *newElem = new Node();

        newElem->data = num;
        newElem->next = nextElem;
        newElem->prev = nextElem->prev;

        if (nextElem->prev) {
            nextElem->prev->next = newElem;
        } else {
            head = newElem;
        }
        nextElem->prev = newElem;
    }

    void deleteFirst() {
        //if list is empty do nothing
        if(!head) return;

        //check if there's only one element
        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = head;
            head->next->prev = nullptr;
            head = head->next;
            delete temp;
        }
    }

    void deleteLast() {
        if(!head) return;

        //check if there's only one element
        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = tail;
            tail -> prev -> next = nullptr;
            tail = tail -> prev;
            delete temp;
        }

    }

    void deleteAt(size_t index) {
        deleteNode(getNodeAt(index));
    }

    void clear() {
        while (head) {
            deleteLast();
        }
    }

    bool contains(int num) {
        Node* temp = head;
        while (temp) {
            if(temp -> data == num) return true;
            temp = temp -> next;
        }
        return false;
    }

    void deleteValue(int num) {
        Node* temp = getNode(num);
        if(temp) deleteNode(temp);
    }

private:
    Node* getNodeAt(size_t index) {
        Node* temp = head;
        for(int i = 0; i < index; i ++) {
            temp = temp -> next;
            if(temp == nullptr) {
                return nullptr;
            }
        }
        return temp;
    }

    Node* getNode(int num) {
        Node* temp = head;
        while (temp) {
            if(temp -> data == num) return temp;
            temp = temp -> next;
        }
        return nullptr;
    }

    void deleteNode(Node* node) {
        //check if it's last node
        if(node -> next) {
            node -> next -> prev = node -> prev;
        } else{
            tail = node -> prev;
        }

        //check if it's first node
        if(node -> prev) {
            node -> prev -> next = node -> next;
        } else{
            head = node -> next;
        }
        delete node;
    }


};


#endif //UNTITLED_MYLIST_H
