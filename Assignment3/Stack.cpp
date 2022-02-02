//
// Created by Kaih White on 10/26/2021.
//

#include "Stack.h"
#include <vector>
#include <cassert>

template<class T>
Stack<T>::Stack() : top(nullptr), maxItem(0), sum(0), itemCount(0) {} // default constructor

template<class T>
Stack<T>::Stack(const Stack<T>& other){
    Node<T>* origChainPtr = other.top;
    if (origChainPtr == nullptr) {
        top = nullptr;
    }
    else{
        top =  new Node<T>();
        top -> setItem(origChainPtr -> getItem());

        maxItem = top -> getItem();  // Set max to the first item added

        itemCount++; // add to total number of items in the stack
        if (typeid(maxItem) == typeid(1)) { // checks that the items are integers
            sum += maxItem; // add to sum of items in the stack
        }

        Node<T>* newChainPtr = top; // Point to first node in new chain

        while (origChainPtr != nullptr){
            origChainPtr = origChainPtr -> getNext(); // Advance original-chain pointer
            T nItem = origChainPtr -> getItem(); // Get next item from original chain

            if(nItem > maxItem){
                maxItem = nItem; // If new item is larger can current max
            }

            if (typeid(nItem) == typeid(1)) {
                sum += nItem; // add to sum
            }

            Node<T>* newNodePtr =  new Node<T>(nItem); // Create a new node containing the next item
            newChainPtr -> setNext(newNodePtr); // Link new node to end of new chain
            newChainPtr = newChainPtr -> getNext(); // Advance pointer to new last node

            itemCount++;
        }
        newChainPtr -> setNext(nullptr);
    }
}

template<class T>
Stack<T>::~Stack(){
    while (!isEmpty()) // while stack is not empty
        pop(); // remove top of stack
}

template<class T>
bool Stack<T>::isEmpty() const{
    return top == nullptr;
}

template<class T>
bool Stack<T>::push(const T& nItem) {
    Node<T> *newNodePtr = new Node<T>(nItem, top);
    top = newNodePtr;

    if(maxItem < nItem){ // set new max item if newly added item is larger than current max
        maxItem = nItem;
    }

    if (typeid(nItem) == typeid(1)){ // checks that items are integers
        sum += nItem; // add new item to sum
        itemCount++; // add to item count
    }

    newNodePtr = nullptr;
    return true;
}

template<class T>
bool Stack<T>::pop(){
    bool result = false;
    if (!isEmpty()){ // Stack is not empty; delete top
        Node<T>* nodeToDeletePtr = top;

        if(top -> getItem() == maxItem) { // if max value was also the top of the stack
            maxItem = 0; // set max to 0 to find new max in remaining stack
            Node<T>* n = top -> getNext();
            while(n != nullptr){
                if (n -> getItem() > maxItem){ // find new max item
                    maxItem = n -> getItem();
                }
                n = n -> getNext();
            }
        }

        itemCount--; // one item is being removed
        if (typeid(top -> getItem()) == typeid(1)){
            sum -= top -> getItem(); // remove item value from sum
        }

        top = top -> getNext();

        nodeToDeletePtr -> setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr =  nullptr;
        result =  true;
    }
    return result;
}

template<class T>
T Stack<T>::peek() const{
    assert(!isEmpty()); // Enforce precondition
    return top->getItem(); // Stack is not empty; return top
}

template <class T>
T Stack<T>::max() const{
    return maxItem;
}

template <class T>
T Stack<T>::mean() const {
    return sum / itemCount;
}

template <class T>
Stack<T> Stack<T>::operator+(const Stack<T> &other) {
    Node<T>* o = other.top;
    Node<T>* n = this -> top;
    Stack<T> fin; // new stack to be returned
    Node<T>* newTop = new Node<T>(n -> getItem());
    fin.top = newTop;
    Node<T>* fn = fin.top;
    n = n -> getNext();

    int count = 1; // to keep track of alternation between two stacks
    while(n != nullptr || o != nullptr){
        if(count % 2 == 0 && n != nullptr){
            Node<T>* newNodePtr = new Node<T>(n -> getItem());
            fn -> setNext(newNodePtr);
            n = n -> getNext();
            fn = fn -> getNext();
        }
        else if(o != nullptr){
            Node<T>* newNodePtr = new Node<T>(o -> getItem());
            fn -> setNext(newNodePtr);
            fn = fn -> getNext();
            o = o -> getNext();
        }
        count++; // alternate to different stack
    }
    fn -> setNext(nullptr); // end of new stack

    if(this -> maxItem > other.maxItem){ // find which stack had the biggest item and set the new stack's max to that
        fin.maxItem = this -> maxItem;
    }
    else{
        fin.maxItem = other.maxItem;
    }

    fin.sum = this -> sum + other.sum; // add sums
    fin.itemCount = this -> itemCount + other.itemCount; // add item counts

    return fin;
}