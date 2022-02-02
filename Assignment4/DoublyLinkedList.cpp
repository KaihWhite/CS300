//
// Created by Kaih White on 11/13/2021.
//

#include "DoublyLinkedList.h"
#include "NoSuchElementException.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : first(nullptr), last(nullptr), iterator(nullptr), length(0) {} //constructor

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& o) : length(o.length) {
    first = new Node<T>;
    first->data = o.first->data;
    first->prev = nullptr;
    Node<T>* past = first;
    Node<T>* n = o.first->next;

    while(n->next != nullptr){
        Node<T>* temp = new Node<T>;
        temp->data = n->data;
        temp->prev = past;
        past->next = temp;
        past = temp;
        n = n->next;
    }

    past->next = last;
    last = new Node<T>;
    last->data = o.last->data;
    last->next = nullptr;
    last->prev = n;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::operator=(const DoublyLinkedList <T> &o) {
    clear();
    return DoublyLinkedList<T>(o);
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() {
    if(first != nullptr){
        return false;
    }
    return true;
}

template <class T>
int DoublyLinkedList<T>::getLength() {
    return length;
}

template <class T>
void DoublyLinkedList<T>::insertFirst(const T &item) {
    length+=1;
    Node<T>* inp = new Node<T>;
    inp->data = item;
    inp->next = first;
    inp->prev = nullptr;
    if(first != nullptr){
        first->prev = inp;
    }
    else{
        last = inp;
    }
    first = inp;
}

template <class T>
void DoublyLinkedList<T>::insertLast(const T &item) {
    length+=1;
    Node<T>* inp = new Node<T>;
    inp->data = item;
    inp->prev = last;
    inp->next = nullptr;
    if(last != nullptr){
        last->next = inp;
    }
    else{
        first = inp;
    }
    last = inp;
}

template <class T>
void DoublyLinkedList<T>::deleteFirst() {
    length-=1;
    Node<T>* toDelete = first;
    if(first->next != nullptr) {
        Node<T> *temp = first->next;
        temp->prev = nullptr;
        delete toDelete;
        first = temp;
        return;
    }
    delete toDelete;
}

template <class T>
void DoublyLinkedList<T>::deleteLast() {
    length-=1;
    Node<T>* toDelete = last;
    if(last->prev != nullptr){
        Node<T>* temp = last->prev;
        temp->next = nullptr;
        delete toDelete;
        last = temp;
        return;
    }
    delete toDelete;
}

template <class T>
void DoublyLinkedList<T>::clear() {
    Node<T>* nf = first;
    Node<T>* nl = last;

    while(nl != nullptr){
        if(nf->next != nullptr){
            nf = nf->next;
            deleteFirst();
        }
        nl = nl->prev;
        deleteLast();
    }

    first = nullptr;
    last = nullptr;
    length = 0;
}

template <class T>
void DoublyLinkedList<T>::setIteratorFirst() {
    iterator = first;
}

template <class T>
void DoublyLinkedList<T>::setIteratorLast() {
    iterator = last;
}

template <class T>
bool DoublyLinkedList<T>::hasNext() {
    if(iterator->prev == nullptr){
        return false;
    }
    return true;
}

template <class T>
bool DoublyLinkedList<T>::hasPrev() {
    if(iterator->next == nullptr){
        return false;
    }
    return true;
}

template <class T>
void DoublyLinkedList<T>::next() {
    if(!isIteratorNULL()) {
        iterator = iterator->next;
    }
    else{
        throw NoSuchElementException("There is no next element.");
    }
}

template <class T>
void DoublyLinkedList<T>::prev() {
    if(!isIteratorNULL()) {
        iterator = iterator->prev;
    }
    else{
        throw NoSuchElementException("There is no previous element.");
    }
}

template <class T>
bool DoublyLinkedList<T>::isIteratorNULL() {
    if(iterator != nullptr){
        return false;
    }
    return true;
}

template <class T>
T DoublyLinkedList<T>::getData() {
    return iterator->data;
}

template <class U>
ostream& operator<<(ostream& out, const DoublyLinkedList<U> &o){
    Node<U>* n = o.first;
    while(n != nullptr){
        out << n->data;
        n = n->next;
    }
    return out;
}

template <class U>
istream& operator>>(istream& in, DoublyLinkedList<U> &o){
    U item;
    in >> item;
    for(auto c : item){
        o.insertLast(c);
    }
    return in;
}