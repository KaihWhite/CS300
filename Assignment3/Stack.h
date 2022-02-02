//
// Created by Kaih White on 10/26/2021.
//

#include "Node.h"
#include "StackInterface.h"

#ifndef ASSIGNMENT3_STACK_H
#define ASSIGNMENT3_STACK_H

template <class T>
class Stack: public StackInterface<T>{
    Node<T>* top;
    T maxItem; // max item in stack
    int sum; // total sum of all items in stack
    int itemCount; // total number of items in stack
public:
    Stack(); // default constructor
    Stack(const Stack<T>& other); // constructor
    ~Stack(); // deconstructor

    bool isEmpty() const; // checks to see if stack is empty
    bool push(const T& nItem); // adds new item onto top of stack
    bool pop(); // removes item from top of stack
    T peek() const; // observe what the item at the top of the stack is

    T max() const; // retrieve the max item in the stack
    T mean() const; // retrieve the average of all the items in the stack if they are integers
    Stack<T> operator+(const Stack<T>& other); // allows two stacks to be added together in an alternating fashion

};

#endif //ASSIGNMENT3_STACK_H
