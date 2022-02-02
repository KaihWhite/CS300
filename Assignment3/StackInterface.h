//
// Created by Kaih White on 10/26/2021.
//

#ifndef ASSIGNMENT3_STACKINTERFACE_H
#define ASSIGNMENT3_STACKINTERFACE_H

template<class T>
class StackInterface{
public:
    virtual bool isEmpty() const = 0; // checks to see if stack is empty
    virtual bool push(const T& nItem) = 0; // adds new item onto top of stack
    virtual bool pop() = 0; // removes item from top of stack
    virtual T peek() const = 0; // observe what the item at the top of the stack is

    virtual T max() const = 0; // retrieve the max item in the stack
    virtual T mean() const = 0; // retrieve the average of all the items in the stack if they are integers
};

#endif //ASSIGNMENT3_STACKINTERFACE_H
