//
// Created by Kaih White on 10/10/2021.
//

#include "BagInterface.h"
#include <vector>

#ifndef ASSIGNMENT1_PLAINBAG_H
#define ASSIGNMENT1_PLAINBAG_H

// PlainBag class. Is a child of the BagInterface class
template <class T>
class PlainBag : public BagInterface<T>{
public:

    PlainBag(); // default constructor

    virtual void insert(T item); // inserts item into bag. To be used by PlainBag, but MagicBag will override

    void print(); // prints content of bag

    int size(); // returns number of all items in the bag

    bool checkFull(); // checks if bag is full

    bool checkEmpty(); // checks if bag is empty

    bool inBag(T item); // checks if an item is in the bag

    int itemCount(T item); // returns the amount of copies of a certain item in the bag

    void clear(); // clears the bag -- removes all items from the bag

    virtual void remove(T item); // removes item from bag. To be used by PlainBag, but MagicBag will override

protected:

    std::vector<T> items; // vector that holds items inserted into the bag. These are visible.

};

#include "PlainBag.cpp"

#endif //ASSIGNMENT1_PLAINBAG_H


