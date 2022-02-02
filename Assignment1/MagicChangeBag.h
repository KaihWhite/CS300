//
// Created by Kaih White on 10/10/2021.
//

#include "PlainBag.h"

#ifndef ASSIGNMENT1_MAGICCHANGEBAG_H
#define ASSIGNMENT1_MAGICCHANGEBAG_H

// Magic Change Bag class. Is a child of the PlainBag class.
template <class T>
class MagicChangeBag : public PlainBag<T>{
public:

    MagicChangeBag(); // default constructor

    void insert(T item); // inserts item into MagicBag. Items are hidden until a removal

    void remove(T item); // removes item from bag and reveals the rest of the items

protected:

    std::vector<T> hidden; // vector that holds the inserted items before they are revealed by a removal

};

#include "MagicChangeBag.cpp"

#endif //ASSIGNMENT1_MAGICCHANGEBAG_H
