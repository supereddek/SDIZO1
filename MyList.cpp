//
// Created by super on 18.05.2022.
//

#include "MyList.h"


void MyList::addFirst(int num) {
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

void MyList::addLast(int num) {
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

void MyList::insertAt(int num, size_t index) {
    Node *nextElem = getNodeAt(index);
    if(!nextElem) {
        std::cout << "Indeks poza zasiegiem!" << std::endl;
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

void MyList::deleteFirst() {
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

void MyList::deleteLast() {
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

void MyList::deleteValue(int num) {
    Node* temp = getNode(num);
    if(temp) deleteNode(temp);
}

void MyList::deleteAt(size_t index) {
    if(!head) return;
    Node* temp = getNodeAt(index);
    if(temp)
        deleteNode(temp);
}

void MyList::clear() {
    while (head) {
        deleteLast();
    }
}

void MyList::display() {
    Node* temp = head;
    if(!head) {
        std::cout << "Lista jest pusta.\n";
    }

    while(temp) {
        std::cout << temp->data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl << std::endl;
}

void MyList::deleteNode(Node *node) {
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

MyList::Node* MyList::getNode(int num) {
    Node* temp = head;
    while (temp) {
        if(temp -> data == num) return temp;
        temp = temp -> next;
    }
    std::cout <<"Nie ma elementu na tym indeksie!\n";
    return nullptr;
}

MyList::Node* MyList::getNodeAt(size_t index) {
    Node* temp = head;
    for(int i = 0; i < index; i ++) {
        temp = temp -> next;
        if(temp == nullptr) {
            std::cout << "Nie ma elementu o tym indeksie.\n";
            return nullptr;
        }
    }
    return temp;
}

bool MyList::contains(int num) {
    Node* temp = head;
    while (temp) {
        if(temp -> data == num) return true;
        temp = temp -> next;
    }
    return false;
}