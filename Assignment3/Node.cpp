//
// Created by Kaih White on 10/26/2021.
//

#include "Node.h"


template<class T>
Node<T>::Node() : next(nullptr){} // default constructor. Next set to nullptr

template<class T>
Node<T>::Node(const T& nItem) : item(nItem), next(nullptr){} // constructor

template<class T>
Node<T>::Node(const T& nItem, Node<T>* nNext) : item(nItem), next(nNext){} // constructor

template<class T>
void Node<T>::setItem(const T& nItem){
    item = nItem;
}

template<class T>
void Node<T>::setNext(Node<T>* nNext){
    next = nNext;
}

template<class T>
T Node<T>::getItem() const{
    return item;
}

template<class T>
Node<T>* Node<T>::getNext() const{
    return next;
}