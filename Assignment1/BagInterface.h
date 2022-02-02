//
// Created by Kaih White on 10/10/2021.
//

#ifndef ASSIGNMENT1_BAGINTERFACE_H
#define ASSIGNMENT1_BAGINTERFACE_H

// Abstract (Interface) class for the Bags. Has pure virtual functions to be overridden by later child class definitions
template <class T>
class BagInterface{
public:

    virtual void insert(T item) = 0; // insert an item into bag

    virtual void remove(T item) = 0; // removes an item from bag

    virtual void clear() = 0; // clears the bag -- removes all items from the bag

    virtual void print() = 0; // prints content of bag

    virtual int size() = 0; // returns the number of all items in the bag

    virtual bool checkFull() = 0; // checks if bag is full

    virtual bool checkEmpty() = 0; // checks if bag is empty

    virtual bool inBag(T item) = 0; // checks if an item is in the bag

    virtual int itemCount(T item) = 0; // returns the amount of copies of a certain item in the bag

};

#endif //ASSIGNMENT1_BAGINTERFACE_H
