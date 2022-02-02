//
// Created by Kaih White on 10/26/2021.
//

#ifndef ASSIGNMENT3_NODE_H
#define ASSIGNMENT3_NODE_H

template <class T>
class Node{
    T item;
    Node* next;
public:
    Node(); // default constructor
    explicit Node(const T& nItem); // constructor
    Node(const T& nItem, Node<T>* nNext); // constructor
    void setItem(const T& nItem); // set current node's item
    void setNext(Node<T>* nNext); // set next pointer
    T getItem() const;
    Node<T>* getNext() const;
};


#endif //ASSIGNMENT3_NODE_H
